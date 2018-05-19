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
#include <strings.h>
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



/*********************************************************************
*
* keyhexchk
*
* This routine takes in a char array and checks each of the characters 
* to see if they are all valid hexadecimal characters.
*
***********************************************************************
*/
void
keyhexchk (char key[]) {
  size_t i;
  int counter =0;
  for (i = 0; key[i]; i++) {
    hexvalue(key[i]);
    counter++;
    printf("%d",counter);
  }


int main(int argc, char **argv){


printf("%d\n", keyhexchk(['6','8','2','6','e','d','3','a','9','2','4','6','e','3','1','a']);


}