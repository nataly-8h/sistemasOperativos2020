#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void signalHandler(int signum){
    printf("haha no me matas \n");
}

int main(){
    signal(17, signalHandler);
    while(1){
        sleep(2);
        printf("trabajando \n");
    }
    return 0;
}