#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]){
    struct stat *fileStat1, *fileStat2;
    fileStat1 = malloc(sizeof(struct stat));
    fileStat2 = malloc(sizeof(struct stat));
    if(lstat(argv[1], fileStat1) < 0 || lstat(argv[2], fileStat2) < 0){
        perror("Error");
        return errno;
    }
    int isLnk1 = S_ISLNK(fileStat1->st_mode), isLnk2 = S_ISLNK(fileStat2->st_mode);
    if(!isLnk1 && !isLnk2){
        if(fileStat1->st_ino == fileStat2->st_ino){
            printf("These files are linked.\n");
        }
        else{
            printf("The files are not linked.\n");
        }
        return 0;
    }
    char* symb, *norm;
    if(isLnk1){
        symb = argv[1];
        norm = argv[2];

    }
    else{
        norm = argv[1];
        symb = argv[2];
    }
    if(stat(argv[1], fileStat1) < 0 || stat(argv[2], fileStat2) < 0){
        perror("Error");
        return errno;
    }
    if(fileStat1->st_ino == fileStat2->st_ino){
        printf("%s is a symbolic link to %s.\n", symb, norm);
    }
    else{
        printf("The files are not linked.\n");
    }
    return 0;
}