#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
void funcchild(){
        char name[50];
            for(int i=1; i<5; i++){
            printf("USER#%d YOUR NAME: ", i);
            fgets(name, sizeof(name), stdin); // read string
            printf("USER#%d :", i);
            puts(name); // display string
        }
}
void funcparent(){
    printf("JOB IS DONE!\n");
}
int main(void){
    pid_t pid = fork();
        if(pid==0){
            funcchild();
            exit(EXIT_SUCCESS);
        }
        else if(pid > 0){
            wait(NULL);
            funcparent();
        }
        else{
            printf("!!SOMETHING WENT WRONG. TRY AGAIN!!");
        }
        return EXIT_SUCCESS;
}
