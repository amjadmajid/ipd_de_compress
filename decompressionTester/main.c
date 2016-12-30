#include <msp430.h> 
#include<stdint.h>
#include "decompression/decompression.h"
/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	// Disable the GPIO power-on default high-impedance mode to activate previously configured port settings.
	PM5CTL0 &= ~LOCKLPM5;		// Lock LPM5.

	// Test data
      *( (uint8_t *)   0x8400)  = 0x0f;
      *( (uint8_t *)   0x8401)  = 0x99;
      *( (uint8_t *)   0x8402)  = 0xE2;
      *( (uint8_t *)   0x8403)  = 0xA9;
      *( (uint8_t *)   0x8404)  = 0xDF;
      *( (uint8_t *)   0x8405)  = 0x0f;
      *( (uint8_t *)   0x8406)  = 0x99;
      *( (uint8_t *)   0x8407)  = 0xe2;
      *( (uint8_t *)   0x8408)  = 0xad;
      *( (uint8_t *)   0x8409)  = 0x7c;

      //:02     1900     00         8613   B4
      *( (uint8_t *)   0x1900)  = 0x0a; // the length of the data
      *( (uint8_t *)   0x1901)  = 0x00;
      //:02195000ffff00    init_flag
	  // *( (uint8_t *)   0x1950)  = 0xff;

	  // The decompressing lookup table in info memory

	  //The format of the transmittered table
	  //length  address  delimiter  data   CRC
      //:02     1880     00         9500   30
	   *( (uint8_t *)   0x1880)  = 0x95;
	   *( (uint8_t *)   0x1881)  = 0x00;
      //:02188200B50153
	   *( (uint8_t *)   0x1882)  = 0xB5;
	   *( (uint8_t *)   0x1883)  = 0x01;
      //:02188400E50286
	   *( (uint8_t *)   0x1884)  = 0xe5;
	   *( (uint8_t *)   0x1885)  = 0x02;
      //:02188600650309
	   *( (uint8_t *)   0x1886)  = 0x65;
	   *( (uint8_t *)   0x1887)  = 0x03;
      //:02188800C40269
	   *( (uint8_t *)   0x1888)  = 0xC4;
	   *( (uint8_t *)   0x1889)  = 0x02;
      //:02188a00D50680
	   *( (uint8_t *)   0x188a)  = 0xD5;
	   *( (uint8_t *)   0x188b)  = 0x06;
      //:02188c00550703
	   *( (uint8_t *)   0x188c)  = 0x55;
	   *( (uint8_t *)   0x188d)  = 0x07;
      //:02188e000201AB
	   *( (uint8_t *)   0x188e)  = 0x02;
	   *( (uint8_t *)   0x188f)  = 0x01;
      //:021890004304F1
	   *( (uint8_t *)   0x1890)  = 0x43;
	   *( (uint8_t *)   0x1891)  = 0x04;
      //:021892003305E4
	   *( (uint8_t *)   0x1892)  = 0x33;
	   *( (uint8_t *)   0x1893)  = 0x05;
	   //:02189400F40cAF
	   *( (uint8_t *)   0x1894)  = 0xf4;
	   *( (uint8_t *)   0x1895)  = 0x0c;
	   //:02189600140dD1
	   *( (uint8_t *)   0x1896)  = 0x14;
	   *( (uint8_t *)   0x1897)  = 0x0d;
      //:02189800851c54
	   *( (uint8_t *)   0x1898)  = 0x85;
	   *( (uint8_t *)   0x1899)  = 0x1c;
      //:02189a00A63a95
	   *( (uint8_t *)   0x189a)  = 0xa6;
	   *( (uint8_t *)   0x189b)  = 0x3a;
      //:02189c00763b68
	   *( (uint8_t *)   0x189c)  = 0x76;
	   *( (uint8_t *)   0x189d)  = 0x3b;
      //:02189e00240fEB
	   *( (uint8_t *)   0x189e)  = 0x24;
	   *( (uint8_t *)   0x189f)  = 0x0f;


      decompression();

  	__no_operation();

  	for(;;)
  	{
  		//do nothing
  	}

  	return 0;

  }

  /*---------------------------------------------------------------
  *shifting algorithm :
  idea:
  1- use a 2 bytes decoding buffer
  2- the buffere is initialized with the first two bytes directly
  3- use a new (one byte) variable to read the data from the memory
  4- drop the decoded bits from the buffer
  5- keep track of the total shifting value
  6- if the total shifting value is greater then 8, insert the byte
  of data from the variable at the end (correct) poisiton in the
  buffer
  7- reduce the total shift value by 8
  8 read a new byte of data into the variable
  ----------------------------------------------------------------*/
