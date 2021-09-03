FILES=$(wildcard src/*.cs)
BINS=$(patsubst src/%.cs,build/%.exe,$(FILES))

all: $(BINS)

build/%.exe: src/%.cs
	mcs $^ -out:$@

clean:
	find build -name '*.exe' -exec rm {} \;

