Huffman tree encoder and decoder
--------------------------------

Description:
------------
Program uses huffman trees to compress text files under 1000kb and decode them as well.
Program Displays statistics of compressor or decompressor after completing process.
Unit tests are used to minimize bugs and astyle is used to align code.

Usage:
------
Compile:      make

Tests:      ./tests

Encoder:    ./huffman -e originalFile.txt encodedFile.txt

Decoder      ./huffman -d encodedFile.txt DecodedFile.txt

Sample Files Provided and statistics
-------------------------------------
simpleOriginal.txt (106 bytes) ---> simpleEncoded.txt (66 bytes)


50kbOriginal.txt (50,324 bytes)  ---> 50kbEncoded.txt ( 30,977 bytes)

1000kbOriginal.txt (1kb) ---> 1000kbOriginal.txt(500 bytes)


All decompressed sizes are without histogram in the begining of file. 

Size of Histogram is 258 bytes.



