import { readFileSync } from 'fs';
import { fileURLToPath } from 'url';
import { dirname, join } from 'path';

const __filename = fileURLToPath(import.meta.url);
const __dirname = dirname(__filename);

const inputFile = readFileSync(join(__dirname, './input'));
let input = inputFile.toString().trim().split('');

const type = {
  literal: ['1', '0', '0'],
};

const hex = {
  0: ['0', '0', '0', '0'],
  1: ['0', '0', '0', '1'],
  2: ['0', '0', '1', '0'],
  3: ['0', '0', '1', '1'],
  4: ['0', '1', '0', '0'],
  5: ['0', '1', '0', '1'],
  6: ['0', '1', '1', '0'],
  7: ['0', '1', '1', '1'],
  8: ['1', '0', '0', '0'],
  9: ['1', '0', '0', '1'],
  A: ['1', '0', '1', '0'],
  B: ['1', '0', '1', '1'],
  C: ['1', '1', '0', '0'],
  D: ['1', '1', '0', '1'],
  E: ['1', '1', '1', '0'],
  F: ['1', '1', '1', '1'],
};

let buffer = [];
const getBit = (length) => {
  let res = [];

  while (buffer.length < length) {
    const key = input.shift();

    if (!key) return [];
    buffer.push(...hex[key]);
  }
  res = buffer.slice(0, length);
  buffer = buffer.slice(length);
  return res;
};

const btoi = (bitBuf) => {
  let res = 0;

  for (let i = 0; i < bitBuf.length; ++i) {
    res = res << 1;
    res += parseInt(bitBuf[i]);
  }
  return res;
};

const parse = () => {
  let packet = {
    version: getBit(3),
    typeID: getBit(3),
    size: 6,
  };
  versionSum += btoi(packet.version);

  const parseLiteralValue = () => {
    let lastGroup = getBit(1).toString();
    let val = getBit(4);

    packet.size += 5;
    while (lastGroup !== '0') {
      lastGroup = getBit(1).toString();
      val = [...val, ...getBit(4)];
      packet.size += 5;
    }
    return val;
  };

  const parseSubPacket = () => {
    let subPacket = [];

    packet.lengthID = getBit(1).toString();
    packet.size += 1;

    let length = packet.lengthID === '0' ? btoi(getBit(15)) : btoi(getBit(11));
    packet.size += packet.lengthID === '0' ? 15 : 11;

    while (length > 0) {
      let tmpPacket = parse();
      subPacket.push(tmpPacket);
      packet.size += tmpPacket.size;
      length -= packet.lengthID === '0' ? tmpPacket.size : 1;
    }
    return subPacket;
  };

  if (packet.typeID.toString() === type.literal.toString()) {
    packet.val = parseLiteralValue();
  } else {
    packet.val = parseSubPacket();
  }
  return packet;
};

let versionSum = 0;

while (input.length > 1) {
  console.log(parse());
  buffer = [];
}

console.log('result :', versionSum);
