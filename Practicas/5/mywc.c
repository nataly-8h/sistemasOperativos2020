#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char c;
    unsigned caracteres = 0;
    unsigned palabras = 0;
    unsigned lineas = 0;
    unsigned flag = 0;
    while(read(STDIN_FILENO, &c, 1) != 0){
        if(c == '\n' && flag == 1){
            lineas ++;
            caracteres ++;
            palabras ++;
            flag = 1;
        }else if(c == '\n' && flag == 0){
            lineas ++;
            caracteres ++;
            //flag = 1;
        }else if (c == ' ') {
            if(flag == 1){
                caracteres ++;
                palabras++;
                flag = 0;
            }else{
                caracteres ++;
            }
            
        }else{
            caracteres ++;
            flag = 1;
        }
    }

    printf("Lineas: %u\n" , lineas);
    printf("Palabras: %u\n" , palabras);
    printf("Caracteres: %u\n", caracteres);
    
}
