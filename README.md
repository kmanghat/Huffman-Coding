Huffman tree encoder and decoder
--------------------------------

Description:
------------
Program uses huffman trees to compress text files under 1000kb and decode them as well.
Program Displays statistics of compressor or decompressor after completing process.
Unit tests are used to minimize bugs and astyle is used to align code.

Usage:
------
Encoder
./huffman -e originalFile.txt encodedFile.txt

Decoder
./huffman -d encodedFile.txt DecodedFile.txt

Sample Files Provided and statistics

simpleOriginal.txt ---> simpleEncoded.txt
106 bytes               66 bytes


50kbOriginal.txt   ---> 50kbEncoded.txt
50,324 bytes            30,977 bytes


1000kbOriginal.txt ---> 1000kbOriginal.txt
1MB                     500kb

All decompressed sizes are without histogram in the begining of file. 
Size of Histogram is 258 bytes.



