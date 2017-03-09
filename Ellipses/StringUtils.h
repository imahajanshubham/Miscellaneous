#include "string.h"

// Squeezes arbitrary long strings and concatenates ellipses accordingly

int squeezeWithEllipses(char * inputbuffer, char * outputbuffer, int maxlength, int last_n)
{
	int prefix_count, index = 0, suffix_pos;

	if( ( strlen(inputbuffer) < last_n ) || ( last_n > maxlength ) )
		return 1;

	if( maxlength < 0 )
		return 1;

	if( last_n < 0 )
		return 1;

	if( maxlength >= strlen(inputbuffer) )
	{
		strcpy(outputbuffer, inputbuffer);

		return 0;
	}

	prefix_count = maxlength - last_n - 3;
	
	if( prefix_count <= 0 )
	{
		outputbuffer[index++] = outputbuffer[index++] = outputbuffer[index++] = '.';

		suffix_pos = strlen(inputbuffer) - ( maxlength - 3 );

		while( inputbuffer[suffix_pos] != '\0' ) 

			outputbuffer[index++] = inputbuffer[suffix_pos++];
	}

	else
	{
		for( index = 0; index < prefix_count; ++index) 
		
			outputbuffer[index] = inputbuffer[index];
		
		outputbuffer[index++] = outputbuffer[index++] = outputbuffer[index++] = '.';

		suffix_pos = strlen(inputbuffer) - last_n;

		while( inputbuffer[suffix_pos] != '\0' ) 

			outputbuffer[index++] = inputbuffer[suffix_pos++];
	}

	outputbuffer[index] = '\0';

	return 0;
}
