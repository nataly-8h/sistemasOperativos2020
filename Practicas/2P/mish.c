/******** mish.c **********/
// gcc -o mish mish.c
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
 
#define MAX_LINE 80
#define MAX_NUM_ARGS 10
size_t string_parser(char *input, char *word_array[]) {
size_t n = 0;
while (*input) {
while (isspace((unsigned char)*input))
++input;
if (*input) {
word_array[n++] = (char *)input;
while (*input && !isspace((unsigned char)*input))
++input;
*(input) = '\0';
++input;
}
}
word_array[n] = NULL;
return n;
}
 
int main(void) {
  char *args[MAX_NUM_ARGS + 1]; /* command line (of 80) has max of 5 arguments */
  char line[MAX_LINE + 1];
  int should_run = 1;
 
  int i;
 
  while (should_run) {
    printf("mish> ");
    fgets(line,MAX_LINE,stdin);
    line[strcspn(line, "\n")] = '\0';
    // Separamos la línea en palabras separadas por espacio
    // y las guardamos en args
    i = string_parser(line,args); // i contiene el número de argumentos
    printf("%d, %s %s\n", i, args[1],line); // Es solo para pruebas borrar cuando esté listo
    
    
    // (1) Crear un proceso hijo
    unsigned pid=fork();
    if(pid==0){    
     execvp(line, &args[1]); 
     fprintf(stderr, "Child process could not do execvp\n"); 
      // (2) El hijo debe ejecutar execvp para ejecutar al comando tecleado
		int comando=execvp(line, &args);
     if(comando==-1){
			printf("Programa no encontrado\n");  // (3) Si el programa no existe debe imprimir programa no encontrado
		}

    }else{      
        int status;
        //waitpid(-1, &status, 0);
        printf("Child exited\n"); 
    } 


    // (4) El proceso padre debe esperar a que el hijo termine, checar funcion waitpid
    // (5) Debe ejecutar comandos como ls , ps
    // (6) Cuando se teclee exit deberá terminar
    
    
    fflush(stdout);
    fflush(stdin);
    line[0] = '\0';
  }
 
  return 0;
}
