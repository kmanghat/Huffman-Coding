SOURCE = testMain.cpp encoder.cpp huffmanTree.cpp testHuffmanTree.cpp testEncoder.cpp testDecoder.cpp decoder.cpp
SOURCE2 = encoder.cpp huffmanTree.cpp main.cpp decoder.cpp

OBJS = $(SOURCE:.cpp=.o)
OBJS2 = $(SOURCE2:.cpp=.o)

#GNU C/C++ Compiler
GCC = g++

# GNU C/C++ Linker
LINK = g++

# Archive
AR = ar rs

# Compiler flags
INC =
CFLAGS = -fPIC -Wall -std=c++11 $(INC)
CXXFLAGS = $(CFLAGS)

# Fill in special libraries needed here
LIBS =

.PHONY: clean

# Targets include all, clean, debug, tar

all : tests huffman

huffman:$(OBJS2)
	$(LINK) -o $@ $^ $(LIBS)

tests: $(OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	rm -rf *.o tests huffman

debug: CXXFLAGS = -DDEBUG -g -std=c++11
debug: tests huffman

tar: 

help:


-include $(SOURCE:.cpp=.d)




