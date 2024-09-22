#include <stdio.h>
#include <stdlib.h>

//input: intero e array di stringhe
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

    //Array con dimensione variabile: deve essere abbastanza piccolo da "entrare" nello stack
    //Trovare un modo per definire array di dimensione definita a runtime memorizzadoli in un posto diverso dallo Stack.
    //Max 8MB nello stack
    int a[n];

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
    return 0;
}