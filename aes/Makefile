#
# Makefile for Rijndael (AES) code.
#
# $Id: Makefile,v 1.2 2003/04/15 00:26:33 elm Exp elm $
# NOTE: has GNU make specific stuff

SRCS = protectfile rijndael.c
INCS = rijndael.h
PROGS = protectfile
OTHERS = testfile Makefile
DIR = $(notdir $(PWD))
TAR = tar
TARFILE = aes.tgz

COBJS = rijndael.o
CFLAGS = -O3

all: $(PROGS)

protectfile: protectfile.o $(COBJS) $(INCS)
	$(CC) $(CFLAGS) -o $@ protectfile.o $(COBJS)

rijndael.o: rijndael.h

tarball:
	cd .. ; $(TAR) cvf - $(addprefix $(DIR)/, $(SRCS) $(INCS) $(OTHERS)) | gzip - > $(TARFILE)


clean:
	$(RM) *~ *.o

spotless: clean
	$(RM) $(PROGS)
