#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char c;
    char buffer[250];
    unsigned i = 0;
    unsigned total = 0;
    while(read(STDIN_FILENO, &c, 1) != 0){
        if(c != ' '){
            buffer[i] = c;
            i++;
        }else{
            buffer[i] = '\0';
            total += atoi(buffer);
            i = 0;
        }
        //write(STDOUT_FILENO, &c, 1);
    }
    buffer[i] = '0';
    total += atoi(buffer);
    printf("%u\n", total);
    return 0;
}
