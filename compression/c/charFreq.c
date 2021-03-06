/*
 @ author: Amjad Yousef Majid
*/

#include "huffmanAlgo.h"
 
void charFreq( FILE * hexFile ){
  int count[MAX_ASCII_HEX][TWO_COLS];
   // set the memory locations of the array to 0
    memset(count, 0, sizeof(count));

    int c;
    while( (c=fgetc(hexFile)) != EOF ) {
      if(c !='\n'  && c !='\0') // these symbols are no part of hexdecimal digits
      count[c][0]=c;
      count[c][1]+=1;
    }

    if(DEBUG){ // Debugging
        printf("the length of count[c][1] is %.0f\n",  ( sizeof(count)/sizeof(int) ) / 2.0 );
    }

    int k,l = 0 ;
    for(k=48; k<MAX_ASCII_HEX; k++) {
        if(count[k][1] > 0 && count[k][0] != 58) // the asscii code of 0 is 48 and the asscii code of : is 58
          {
              hDigits[l] =  count[k][0];
              freq[l] = count[k][1];

              if(DEBUG){ // Debugging
                  printf("char %c:%d times\n", hDigits[l], freq[l]);
              }

              l++;
         }
    }
}
