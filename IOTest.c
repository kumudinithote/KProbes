/**
 * Test Application
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define INPUT_FILE_NAME "InputFile.txt"
#define OUTPUT_FILE_NAME1 "OutputFile.txt"

#define BUFFER_SIZE 1024

size_t nRead;
char buf[BUFFER_SIZE];

int main()
{


  fprintf(stdout, "Process will wait for 15 sec.\n");
  sleep(15);

	FILE *filp1 = NULL, *filp2 = NULL;

	for(int i = 0; i  < 1500; i++)
	{
		filp1 = fopen(INPUT_FILE_NAME, "r");
		filp2 = fopen(OUTPUT_FILE_NAME1, "w");


		while((nRead = fread(buf, 1, sizeof(buf), filp1)) > 0) {
			fwrite(buf, 1, nRead, filp2);
		}

		char buffer[100];
		strcpy(buffer, "Writting to output file is done! \n");
		fwrite(buffer, 1, strlen(buffer), filp2);

		fclose(filp1);
		fclose(filp2);

	}

	fprintf(stdout, "DO dmesg\n");
	return 0;
}
