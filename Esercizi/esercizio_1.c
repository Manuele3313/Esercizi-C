#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void termina(char *messaggio){
    puts(messaggio);
    exit(1);
}

void inserisci(int **a, int *size, int *messi, int insrt){
    if(*messi == *size){
        *size *= 2;
        *a = realloc(*a, *size * sizeof(int));
        if(*a == NULL)
            termina("Memoria insufficente");
    }
    (*a)[*messi] = insrt;
    (*messi)++;
}

void print_arr(int *a, int size){
     for(int i=0; i < size; i++){
        printf("%8d",a[i]);
    }
    printf("\n");
}

int somma_arr(int *a, int size){
    int somma = 0;
    for(int i=0; i < size; i++){
        somma += a[i];
    }
    return somma;
}

int main(int argc, char *argv[]){
    int n, e;
    puts("Inserisci un intero N");
    e = scanf("%d", &n);
    if(e != 1){
        termina("Numero non valido");
    }

    int *a;
    int a_size = 10;
    int a_messi = 0;
    a = malloc(a_size * sizeof(int));
    if(a == NULL)
        termina("Memoria insufficente");

    int *b;
    int b_size = 10;
    int b_messi = 0;
    b = malloc(b_size * sizeof(int));
    if(b == NULL)
        termina("Memoria insufficente");

    for(int i = 0; i <= n; i ++){
        if(i % 3 == 0 && i % 5 != 0){
            inserisci(&a, &a_size, &a_messi, i);
        }
        if(i % 5 == 0 && i % 3 != 0){
            inserisci(&b, &b_size, &b_messi, i);
        }
    }

    a_size = a_messi;
    a = realloc(a, a_size * sizeof(int));

    b_size = b_messi;
    b = realloc(b, b_size * sizeof(int));

    printf("Lunghezza a[] = %d, somma a[] = %d", a_size, somma_arr(a, a_size));
    printf("\n");
    printf("Lunghezza b[] = %d, somma b[] = %d", b_size, somma_arr(b, b_size));
    printf("\n");
    
    free(a);
    free(b);
    return 0;
}