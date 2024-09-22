#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Come input ha una stringa
void termina(char *messaggio){
    puts(messaggio);
    exit(1);
}

bool primo(int k){
    if(k % 2 == 0)
        return false;
    for(int i = 3; i*i < k; i += 2){
        if(k % i == 0)
            return false;
    }
    return true;
}

//legge intero n e costruisce array dei primi <=N

int main(int argc, char *argv[]){
    int n,e;

    e = puts("Inserisci la dimensione dell'array");
    e = scanf("%d",&n);
    if(e != 1){
        termina("Lettura fallita");
    }

    if(n < 2){
        puts("L'array che ti interessa è vuoto");
    }

    int *a;
    int size = 10; //dimensione attuale dell'array
    int messi = 0;
    //sizeof(int) = 4 (byte)
    a = malloc(size*sizeof(int));
    if(a == NULL)
        termina("Memoria insufficente");

    for(int i = 2; i <= n; i++){
        if(primo(i)){
            if(messi >= size){
                size *=2;
                a = realloc(a, size*sizeof(int));
                if(a == NULL)
                    termina("Memoria insufficente");
            }
            a[messi] = i;
            messi++;
        }
    }

    size = messi;
    //Guarda che succede senza sizeof(int)
    a = realloc(a, size*sizeof(int));
    if(a == NULL)
        termina("Memoria insufficente");

    for(int i = 0; i < messi; i++){
        printf("%8d",a[i]);
    }
    printf("\n");
    free(a);

    return 0;
}
