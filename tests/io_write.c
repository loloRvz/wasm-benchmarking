#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "time.h"
#include "errno.h"

#define WARMUP 50

void io_write(int n){
	FILE *f = fopen("./data/io_file.txt", "w");
	if (f == NULL)
		{
			printf("Error opening file!\n");
			exit(1);
		}
		
	for(int i=0; i<n; i++){
		fprintf(f,"%d\n",n);
	}
	
	fclose(f);
}


int main(int argc, char *argv[]){
	//Parameters
	int ceil = 10000;
	int step = 100;
	
	//Warmup
	for(int i=0; i<WARMUP; i++){
		io_write(WARMUP);
	}
	
	//Run test
	float start_time,end_time,time_elapsed;
	for(int i=1; i<ceil; i+=step){
		start_time = (float)clock()/CLOCKS_PER_SEC*1000;
		io_write(i);
		end_time = (float)clock()/CLOCKS_PER_SEC*1000;
		
		time_elapsed = end_time - start_time;
	
		printf("%4d \t %.3f\n", i, time_elapsed);
	}
	
	return 0;
}
