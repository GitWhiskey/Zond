#include "stdio.h"
#include "time.h"

int main(int argc, char * argv[]) {
srand(time(0));
int i;
int poneCount =0;
int moneCount =0;
int zeroCount =0;
for(i = 0; i < 10000; i ++) {
int posMove = (rand()%3) - 1;
if(posMove == -1) 
moneCount++;
if(posMove == 0)
zeroCount++;
if(posMove == 1)
poneCount++; 
}

printf("-1: %d\n", moneCount);
printf("0: %d\n", zeroCount);
printf("1: %d\n", poneCount);

return 0;
}
