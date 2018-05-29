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
 * This function takes a single character as input, and returns the
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
   filename = argv[3];
   /*Getting file info*/
   struct stat fileInfo;
   stat (filename, &fileInfo);
   uid_t fileOwner = fileInfo.st_uid;

   /*get key from the input*/
	inputkey=argv[2];
    keysize=strlen(inputkey); /*get input keys size to divied them*/
    printf("%d\n", keysize);
    /*vaildate the input key is hexa decimal then divide it into k0 and k1*/
    for (z=0 ;inputkey[z];z++){
	 hexvalue(inputkey[z]);
   // printf("%c", inputkey[z]);
  } 



/*
Checking if the user option was encryption. It validates first if the file was encrypted or not. If not, it does. 
*/
  if (!strcmp(argv[1], "-e")) {
			if (fileInfo.st_mode & S_ISVTX) {
				fprintf (stderr, "Error: %s is already encrypted.\n", filename);
				return 1;
			} else {
				fileId = fileInfo.st_ino;
				if (chmod(filename, S_ISVTX)) {
					perror("protectfile");
					exit (-1);
				}
			}
		} 

/*
Checking if the user option was decryption. It validates first if the file was encrypted or not. If not, it does. 
*/

    else if (!strcmp(argv[1], "-d")) {
			if (!(fileInfo.st_mode & S_ISVTX)) {
				fprintf (stderr, "Error: %s is already decrpyted.\n", filename);
				return 1;
			} else {
				fileId = fileInfo.st_ino;
				if (chmod(filename, S_IFREG)) {
					perror("protectfile");
					exit (-1);
				}
			}
		}
  }

  else{
    printf(stderr, "Usage for first time users: %s <-e/-d option> <key>\n", argv[0]);
		return 1;
  }

}

