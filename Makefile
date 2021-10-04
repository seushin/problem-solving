BINARY := $(shell find . -type f -name a.out -o -name a.exe)

.PHONY: help clean
help:
	@echo "Usage: make clean"

clean:
	rm -f $(BINARY)
