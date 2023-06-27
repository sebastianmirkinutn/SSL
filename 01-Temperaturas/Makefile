tablasDeConversion: tablasDeConversion.o
	cc tablasDeConversion.o -o tablasDeConversion

tablasDeConversion.o: tablasDeConversion.c
	cc -c tablasDeConversion.c

conversion: conversion.o
	cc conversion.o -o conversion

conversion.o: conversion.c
	cc -c conversion.c

conversionTests: conversionTests.o
	cc conversionTests.o -o conversionTests

conversionTests.o: conversionTests.cc
	cc -c conversion.c

clean:
	rm -rf conversion tablasDeConversion *.o