#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[] ) {
    if(argc != 3){
        printf("Format should be: ./timeout.exe seconds command");
    }else{
        printf("Perfect");
    }
    
    return 0;
}