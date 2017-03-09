#include "stdio.h"
#include "stdlib.h"
#include "StringUtils.h"

#define MAXLENGTH 100
char filename[] = "C:\\Users\\devsa\\Desktop\\Study !\\Programs\\Miscellaneous\\Ellipses\\TestSuite.txt";

void readTestSuite(char * inputbuffer, int * maxlength, int * last_n)
{
	FILE *p;
	int index = 0;
	char tempstr[MAXLENGTH], c;

	p = fopen( filename ,"r");

	fscanf( p , "%[^\n]" , inputbuffer );		fseek( p , 2L , SEEK_CUR );

	fscanf( p , "%[^\n]" , tempstr );			fseek( p , 2L , SEEK_CUR );

	*maxlength = atoi( tempstr );

	fscanf( p , "%[^\n]" , tempstr );			

	*last_n = atoi( tempstr );
}

int main()
{
	char inputbuffer[MAXLENGTH];
	char outputbuffer[MAXLENGTH];
	int maxlength, last_n;

	readTestSuite( inputbuffer , &maxlength , &last_n );

	if( ! (squeezeWithEllipses( inputbuffer , outputbuffer , maxlength , last_n )) )

		printf("%s\n", outputbuffer);

	return 0;
}