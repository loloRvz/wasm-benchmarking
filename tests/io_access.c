#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "time.h"
#include "errno.h"

#define WARMUP 50

void n_io(int n){
	for(int i=0; i<n; i++){
		FILE *f = fopen("./data/io_file.txt", "w");
		if (f == NULL)
		{
			printf("Error opening file!\n");
			exit(1);
		}
		fprintf(f,"%d\n",n);
		fclose(f);
	}
}


int main(int argc, char *argv[]){
	//First argument: ceiling, second argument:increment
	
	//Variables
	char *p;
	errno = 0;
	int n = strtol(argv[1], &p, 10);
	int m = strtol(argv[2], &p, 10);

	//Check input
	if(argc != 3){printf("Incorrect input!\n");return 0;}
	if(errno != 0 || *p != '\0'){
		printf("Incorrect input!\n");return 0;
	}
	
	//Warmup
	for(int i=0; i<WARMUP; i++){
		n_io(WARMUP);
	}
	
	//Run test
	float start_time,end_time,time_elapsed;
	for(int i=1; i<n; i+=m){
		start_time = (float)clock()/CLOCKS_PER_SEC*1000;
		n_io(i);
		end_time = (float)clock()/CLOCKS_PER_SEC*1000;
		
		time_elapsed = end_time - start_time;
	
		printf("%4d \t %.3f\n", i, time_elapsed);
	}
	
	return 0;
}
