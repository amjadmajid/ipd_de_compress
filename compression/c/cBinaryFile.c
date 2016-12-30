/*
 @ author: Amjad Yousef Majid
*/
#include "huffmanAlgo.h"
 
void cBinaryFile( FILE * hex , FILE * chex)
{
  int c, i;
  while( ( c=fgetc(hex) ) != EOF ) {
      if( (c >= 48 && c <= 57) ||
          (c >= 65 && c <= 70) ||
          (c >=97 && c <=102 )
        ) // these symbols are no part of hexdecimal digits
          {
            for (i=0 ; i < 16 ; i++){
              if( c == hexCode[i]){
                  //printf("---%c\n", c);
                  fprintf(chex, "%s", binCode[i]);
                }
            }
        }
    }
}
