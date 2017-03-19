#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "utils.h"

#define MAXLENGTH 100

void readInputFromCmd(int argc, const char * argv[], char * inputbuffer, int * maxlength, int * last_n)
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

	readInputFromCmd( argc , argv , inputbuffer , &maxlength , &last_n );

	if( ! (squeezeWithEllipses( inputbuffer , outputbuffer , maxlength , last_n )) )

		printf("%s\n", outputbuffer);

	else
		printf("Error!");

	return 0;
}