import { readFileSync } from 'fs';
import { fileURLToPath } from 'url';
import { dirname, join } from 'path';

const __filename = fileURLToPath(import.meta.url);
const __dirname = dirname(__filename);

const input = readFileSync(join(__dirname, './input'), { encoding: 'utf-8' }).trim();

const type = {
  sum: 0,
  multi: 1,
  min: 2,
  max: 3,
  literal: 4,
  gt: 5,
  lt: 6,
  eq: 7,
};

const getBit = (buf, length) => {
  let res = 0;
  while (length-- && buf.length) {
    res = res * 2 + buf.shift();
  }
  return res;
};

const calculate = (values, typeID) => {
  if (typeID === type.sum) {
    return values.reduce((prev, curr) => prev + curr, 0);
  } else if (typeID === type.multi) {
    return values.reduce((prev, curr) => prev * curr, 1);
  } else if (typeID === type.min) {
    return Math.min(...values);
  } else if (typeID === type.max) {
    return Math.max(...values);
  } else if (typeID === type.gt) {
    return values[0] > values[1] ? 1 : 0;
  } else if (typeID === type.lt) {
    return values[0] < values[1] ? 1 : 0;
  } else if (typeID === type.eq) {
    return values[0] === values[1] ? 1 : 0;
  }
  return 0;
};

const parsePacket = (o, callback) => {
  let packet = {
    version: getBit(o.buf, 3),
    typeID: getBit(o.buf, 3),
    val: 0,
  };
  if (o.buf.length < 5) return false;

  const parseLiteralValue = (o) => {
    let lastGroup = getBit(o.buf, 1);
    let val = getBit(o.buf, 4);

    while (lastGroup !== 0) {
      lastGroup = getBit(o.buf, 1);
      val = val * 16 + getBit(o.buf, 4);
    }
    return val;
  };

  const parseSubPacket = (o) => {
    let sub = [];
    let lengthID = getBit(o.buf, 1);

    if (lengthID === 0) {
      let length = getBit(o.buf, 15);
      let ocpy = { buf: o.buf.slice(0, length) };
      o.buf = o.buf.slice(length);

      while (parsePacket(ocpy, (v) => sub.push(v)));
    } else {
      let subNumbers = getBit(o.buf, 11);
      for (let i = 0; i < subNumbers; i++) {
        parsePacket(o, (v) => sub.push(v));
      }
    }
    return sub;
  };

  if (packet.typeID === type.literal) {
    packet.val = parseLiteralValue(o);
  } else {
    let sub = parseSubPacket(o);
    packet.val = calculate(sub, packet.typeID);
  }
  callback(packet.val);
  return true;
};

let buffer = [];
for (let c of input) {
  let hex = parseInt(c, 16);
  for (let i = 3; i >= 0; --i) {
    let bit = (hex & (1 << i)) >> i;
    buffer.push(bit);
  }
}

parsePacket({ buf: buffer }, (v) => console.log('result :', v));
