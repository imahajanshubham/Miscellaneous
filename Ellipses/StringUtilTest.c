#include "stdio.h"
#include "stdlib.h"
#include "StringUtils.h"

#define MAXLENGTH 100
char filename[] = "C:\\Users\\devsa\\Desktop\\Study !\\Programs\\Miscellaneous\\Ellipses\\TestSuite.txt";

void readInputFromCmd(const char * argv[], int argc, char * inputbuffer, int * maxlength, int * last_n)
{
	int index = 1;

	if( ( strcmp( argv[index] , "-maxlength" ) ) == 0 )
		*maxlength = atoi( argv[index + 1] );

	index += 2;

	if( ( strcmp( argv[index] , "-lastnchars" )) == 0 )
		*last_n = atoi( argv[index + 1] );

	index += 2;

	strcpy( inputbuffer , argv[index] );
}

int main(int argc, char const * argv[])
{
	char inputbuffer[MAXLENGTH];
	char outputbuffer[MAXLENGTH];
	int maxlength, last_n;

	readInputFromCmd( argv , argc , inputbuffer , &maxlength , &last_n );

	if( ! (squeezeWithEllipses( inputbuffer , outputbuffer , maxlength , last_n )) )

		printf("%s\n", outputbuffer);

	return 0;
}