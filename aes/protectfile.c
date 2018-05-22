/*
 * This code encrypts input data using the Rijndael (AES) cipher.  The
 * key length is hard-coded to 128 key bits; this number may be changed
 * by redefining a constant near the start of the file.
 *
 * This program uses CTR mode encryption.
 *
 * Usage: encrypt <key1> <key2> <file name>
 *
 * Author: Ethan L. Miller (elm@cs.ucsc.edu)
 * Based on code from Philip J. Erdelsky (pje@acm.org)
 *
 */

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "rijndael.h"
static char rcsid[] = "$Id: encrypt.c,v 1.2 2003/04/15 01:05:36 elm Exp elm $";

#define KEYBITS 128

/***********************************************************************
 *s
 * hexvalue
 *
 * This routine takes a single character as input, and returns the
 * hexadecimal equivalent.  If the character passed isn't a hex value,
 * the program exits.
 *
 ***********************************************************************
 */
int hexvalue (char c)
{
  if (c >= '0' && c <= '9') {
    return (c - '0');
  } else if (c >= 'a' && c <= 'f') {
    return (10 + c - 'a');
  } else if (c >= 'A' && c <= 'F') {
    return (10 + c - 'A');
  } else {
    fprintf (stderr, "ERROR: key digit %c isn't a hex digit!\n", c);
    exit (-1);
  }
}



int main (int argc, char **argv){
  unsigned long rk[RKLENGTH(KEYBITS)];  /* round key */
  unsigned char key[KEYLENGTH(KEYBITS)];/* cipher key */
  char  buf[100];
  int i, nbytes, nwritten , ctr;
  int totalbytes;
  int k0, k1;
  char *ck0 , *ck1;
  int 
  int fileId = 0x1234;      /* fake (in this example) */
  int nrounds;        /* # of Rijndael rounds */
  char *password;     /* supplied (ASCII) password */
  int fd;
  char *filename;
  unsigned char filedata[16];
  unsigned char ciphertext[16];
  unsigned char ctrvalue[16];
  char *inputkey; 
  int z,keysize,counter ; 
 if (argc < 4)
  {
    fprintf (stderr, "Usage: %s <-e -d > <key> <file>\n", argv[0]);
    return 1;
  }
  if(argc==4){

   // printf("%s /n" , argv[2]);
   /*get key from the input*/
	inputkey=argv[2];
    keysize=strlen(inputkey); /*get input keys size to divied them*/
    printf("%d\n", keysize);
    /*vaildate the input key is hexa decimal then divide it into k0 and k1*/
    for (z=0 ;inputkey[z];z++){
	 hexvalue(inputkey[z]);
   // printf("%c", inputkey[z]);
  } 
  strncpy(ck0,inputkey,(strlen(inputkey)/2))
  strncpy(ck1,inputkey+(strlen(inputkey)/2)+1,(strlen(inputkey)/2))
  int y ;
  for (y=0 ;k2[y];y++)
  printf("%c \n",k2[y]);
    return 0;
  }

  /*Convert key from hexa to integer*/

  }

}

