#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <unistd.h>


int make_step(int pos, int width, float prob);

int main (int argc, char * argv[]) {

	int h = 80;
	int w = 40;
	float p = 0.01;

	int i;
	if(argc > 1) {
		for(i = 1; i < argc; i += 2) {
			if(strcmp(argv[i], "-w") == 0)
				w = atoi(argv[i+1]);
			else if(strcmp(argv[i], "-h") == 0)
				h = atoi(argv[i+1]);
			else if(strcmp(argv[i], "-p") == 0)
				p = atof(argv[i+1]);
		}
	}	

	srand(time(0));
	
	for(i = 0; i < h; i++) {
		int posMove = (rand()%3) - 1;
		int result;
		int currpos = ((int) w/2) + posMove;
		result = make_step(currpos, w, p);
		usleep(100000);

		if(result == 0) {
			printf("You died at step %d!\n", i);
			break;
		}
	}
	if(i == h)
		printf("You win!\n");
	
	return 0;
}

int make_step(int pos, int width, float prob) {
	
	int i;
	int result;	
	char * mystr;
	mystr = (char *) malloc(width + 1);
	
	for(i = 0; i < width; i++) {
		float asteroidProb = (float)rand()/RAND_MAX;
		if(asteroidProb < prob)
			mystr[i] = '*';
		else
			mystr[i] = ' ';
	}
	mystr[width] = '0';

	if(mystr[pos+1] == '*' || mystr[pos-1] == '*') {
		mystr[pos] = '0';
		result = 1;
		
	} 
	else if(mystr[pos] == ' ') {
		mystr[pos] = '+';
		result = 1;
	}
	else {
		mystr[pos] = '@';
		result = 0;
	}

	printf("%s\n", mystr);
	free(mystr);
	return result;
}
