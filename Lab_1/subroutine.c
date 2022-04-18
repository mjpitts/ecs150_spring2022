#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*print out 1-10 over 10 seconds*/
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    //set end of delay
    clock_t end = clock() + milli_seconds;
    
    // wait until end of delay 
    while (clock() < end);
}
  
/*delay driver*/
int main(int argc, char *argv[] ) {
    for(int i = 1; i < atoi(argv[1]); i++){
        delay(1);
        printf("\n %d", i);
    }
    
    return 0;
}