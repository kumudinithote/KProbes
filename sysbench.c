
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define ROWS 1024

int main()
{

	fprintf(stdout, "Process will wait for 15 sec do insmod.\n");
	sleep(15);

 int pageSize = 1024;

 int array[ROWS][pageSize];
 int sum = 0;

 for(int i = 0; i < pageSize; i++){
	 for(int j = 0; j < ROWS; j++){
		 for(int k = 0; k < ROWS; k++){
				 sum += array[j][i];
		 }
	 }
 }
 fprintf(stdout, "DO dmesg\n");

 return 0;
}
