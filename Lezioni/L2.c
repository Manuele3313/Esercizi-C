#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int n; 


    puts("Inserisci un intero");
    int e = scanf("%d",&n); 
    if(e != 1){
        puts("Lettura fallita");
        exit(1);
    };
    if(n <= 0){
        puts("Dimensione non valida");
        exit(1);
    }

    ///A è al momento un "potenziale array"
    int *a;
    //le variabili intere sono, al momento 4Byte
    a = malloc(n*sizeof(int));
    //WHAT?!
    printf('%d',sizeof(int));
    if(a == NULL){
        puts("Memoria insufficente");
        exit(1);
    }
    for(int i=0; i<n; i++){
        printf("inserisci l'elemento di posto %d\n",(i+1));
        int e = scanf("%d", &a[i]);
        if(e != 1){
            puts("Lettura fallita");
            exit(1);
        };
    }
    
    int somma = 0;
    for(int i=0; i<n; i++){
        somma += a[i];
    };                                                                                                                                                                                                                                      

    printf("La somma dell'array di %d elementi è %d\n",n,somma);
    
    //restituisci la memoria
    free(a);

    return 0;
}
