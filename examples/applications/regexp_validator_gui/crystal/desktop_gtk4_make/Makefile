
all: build

build:
	shards install
	./bin/gi-crystal
	crystal build regexp_validator_gui.cr
	
clean:
	rm -rf bin lib regexp_validator_gui

run:
	./regexp_validator_gui
