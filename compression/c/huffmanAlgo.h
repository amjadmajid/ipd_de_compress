/*
 @ author: Amjad Yousef Majid
*/

#ifndef HUFFMANALGO_H_
#define HUFFMANALGO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INPUT_FILE "dataFiles/dump.hex"
#define MAX_TREE_HT 100
#define MAX_CODE_LEN 30
#define HEXDIGIT 16
#define MAX_ASCII_HEX 102+1 						// to make the array has the position 102, 1 is added
#define TWO_COLS 2
#define DEBUG 1


extern FILE *hexFile;
extern FILE *codeFile;
extern FILE *cBinFile;
extern FILE *cFile;    								// input / code_output files

extern char hDigits[HEXDIGIT] ; 					// Hex characters
extern int freq[HEXDIGIT] ; 						// the frequencies of the hex characters in a hex file
extern char hexCode[HEXDIGIT]; 						// collect the huffman code from the algorithm
extern char binCode[HEXDIGIT][MAX_CODE_LEN]; 		// collect the huffman code from the algorithm

#endif
