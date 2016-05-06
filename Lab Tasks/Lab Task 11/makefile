#Makefile for Lab11

CC	= gcc
LD	= $(CC)
DEPEND	= mkdep

CFLAGS	= -O2 -Wall

CFILES	=\
	NameAge.c\
	Person.c\
	mystrings.c

HFILES	=\
	Person.h\
	mystrings.h\
	boolean.h

OFILES	= $(CFILES:%.c=%.o)

NameAge:	$(OFILES)
	$(LD) -o $@ $(OFILES)

NameAge.o:	NameAge.c Person.h boolean.h mystrings.h

Person.o:	Person.c Person.h boolean.h mystrings.h

mystrings.o:	mystrings.c mystrings.h boolean.h

depend:
	$(DEPEND) $(CFLAGS) $(CFILES)

clean:
	rm -f *.o *.bak
