/*
 @ author: Amjad Yousef Majid
*/

#include "huffmanAlgo.h"

void comprsdHex(FILE * cbf , FILE * cf){
  // int c, i, cnt=0;
  // char tmp[MAX_CODE_LEN] ={'x'}; // initialize the array to none hex symbol
 char c[5];
  while(( c[0] = fgetc(cbf)) != EOF )
  {
    if( ( c[1] = fgetc(cbf) ) != EOF){
    }else{
      c[1] = c[2] = c[3] =0;
    }
    if( (c[2] = fgetc(cbf) ) != EOF){
    }else{
       c[2] = c[3] =0;
    }
    if( ( c[3] = fgetc(cbf) ) != EOF){
    }else{
      c[3] =0;
    }
    c[4] = '\0';
    if( !strcmp(c,"0000") ){
      fprintf(cf, "%c", '0');
    }else if( !strcmp(c,"0001") ){
      fprintf(cf, "%c", '1');
    }else if( !strcmp(c ,"0010") ){
      fprintf(cf, "%c", '2');
    }else if( !strcmp(c ,"0011") ){
      fprintf(cf, "%c", '3');
    }else if( !strcmp(c ,"0100") ){
      fprintf(cf, "%c", '4');
    }else if( !strcmp(c ,"0101") ){
      fprintf(cf, "%c", '5');
    }else if( !strcmp(c ,"0110") ){
      fprintf(cf, "%c", '6');
    }else if( !strcmp(c ,"0111") ){
      fprintf(cf, "%c", '7');
    }else if( !strcmp(c ,"1000") ){
      fprintf(cf, "%c", '8');
    }else if( !strcmp(c ,"1001") ){
      fprintf(cf, "%c", '9');
    }else if( !strcmp(c ,"1010") ){
      fprintf(cf, "%c", 'A');
    }else if( !strcmp(c ,"1011") ){
      fprintf(cf, "%c", 'B');
    }else if( !strcmp(c ,"1100") ){
      fprintf(cf, "%c", 'C');
    }else if( !strcmp(c ,"1101") ){
      fprintf(cf, "%c", 'D');
    }else if( !strcmp(c ,"1110") ){
      fprintf(cf, "%c", 'E');
    }else if( !strcmp(c ,"1111") ){
      fprintf(cf, "%c", 'F');
    }else{

    }
  }
}
