SOURCE = testMain.cpp encoder.cpp huffmanTree.cpp testHuffmanTree.cpp testEncoder.cpp
OBJS = $(SOURCE:.cpp=.o)

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

all : huffman

huffman: $(OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	rm -rf *.o huffman

debug: CXXFLAGS = -DDEBUG -g -std=c++11
debug: huffman

tar: 

help:


-include $(SOURCE:.cpp=.d)




