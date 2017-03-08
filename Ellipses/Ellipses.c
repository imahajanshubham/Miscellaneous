#include "stdio.h"
#include "String.h"

#define MAXLENGTH 	100
#define ERROR 		0
#define SUCCESS		1

char buffer[MAXLENGTH], outputbuffer[MAXLENGTH];
int maxlength, last_n;

void readTestSuite()
{
	FILE *p;
	int index = 0;

	p = fopen("C:\\Users\\devsa\\Desktop\\TestSuite.txt","r");

	while((buffer[index++] = fgetc(p)) != EOF);

	buffer[--index] = '\0';

	maxlength = 12;
	last_n = 3;
}

int squeezeWithEllipses()
{
	int prefix_count, index = 0, suffix_pos;

	if( ( strlen(buffer) < last_n ) || ( last_n > maxlength ) )
		return ERROR;

	if( maxlength < 0 )
		return ERROR;

	if( last_n < 0 )
		return ERROR;

	if( maxlength >= strlen(buffer) )
	{
		strcpy(outputbuffer, buffer);

		return SUCCESS;
	}

	prefix_count = maxlength - last_n - 3;
	
	if( prefix_count <= 0 )
	{
		outputbuffer[index++] = outputbuffer[index++] = outputbuffer[index++] = '.';

		suffix_pos = strlen(buffer) - ( maxlength - 3 );

		while( buffer[suffix_pos] != '\0' ) 

			outputbuffer[index++] = buffer[suffix_pos++];
	}

	else
	{
		for( index = 0; index < prefix_count; ++index) 
		
			outputbuffer[index] = buffer[index];
		
		outputbuffer[index++] = outputbuffer[index++] = outputbuffer[index++] = '.';

		suffix_pos = strlen(buffer) - last_n;

		while( buffer[suffix_pos] != '\0' ) 

			outputbuffer[index++] = buffer[suffix_pos++];
	}

	outputbuffer[index] = '\0';

	return SUCCESS;
}

int main()
{
	readTestSuite();

	if( squeezeWithEllipses() )

		printf("%s\n", outputbuffer);

	return 0;
}