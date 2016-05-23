.PHONY : all clean
CC = g++ --std=c++11 
all :\
	output/factorymethod\
	output/builder\
	output/singleton\
	output/prototype\
	output/adapter

output/factorymethod : factorymethod.cc
	$(CC) $^ -o $@

output/builder : builder.cc
	$(CC) $^ -o $@

output/singleton : singleton.cc
	$(CC) $^ -o $@

output/prototype: prototype.cc
	$(CC) $^ -o $@
output/adapter: adapter.cc
	$(CC) $^ -o $@

clean: 
	rm -rf output/*
