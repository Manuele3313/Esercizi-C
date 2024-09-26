#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

//Come input ha una stringa
//Miglioramento tramite la stampa dell'errore
void termina(char *messaggio){
    if(errno != 0)
        perror(messaggio);
    else
        fprintf(stderr,"%s",messaggio);
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

void stampaArray(int *arr, int size, FILE *f){
    for(int i = 0; i < size; i++){
        if(i % 10 == 0)
            fprintf(f, "\n");
        fprintf(f,"%8d",arr[i]);
    }
    fprintf(f,"\n");
}


int lunghezza_stringa(char str[]){
    int l = 0;
    for(int i = 0; *(str+i) != '\0'; i++, l++){
    }
    return l;
}

void merge(int a[], int n1, int b[], int n2, int c[]){
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    int ia = 0, ib = 0;
    for(int i = 0; i < n1+n2; i++){
        if(ia == n1){
            assert(ib < n2);
            c[i] = b[ib++];
            continue;
        }
        if(ib == n2){
            assert(ia < n1);
            c[i] = a[ia++];
            continue;
        }
        if(a[ia] <= b[ib]){
            c[i] = a[ia++];
        } else{
            c[i] = b[ib++];
        }
    }

}

void merge_sort(int a[], int n){
    assert(a != NULL);
    assert(n > 0);
    if(n == 1)
        return;
    
    int n1 = n/2;
    int n2 = n - n1;

    merge_sort(a, n1);
    merge_sort(&a[n1], n2);

    int *b = malloc(sizeof(int) * n);
    if(b == NULL) termina("Allocazione fallita");
    merge(a,n1,&a[n1],n2,b);
    for(int i = 0; i < n; i++){
        a[i] = b[i];
    }
    free(b);
}


//legge intero n e costruisce array dei primi <=N 
//Adesso però, andremo a scrivere l'output in un file

int main(int argc, char *argv[]){

    if(argc != 2){
        //Controlla se è inserito il file in input
        fprintf(stderr, "Uso: %s nomefile\n",argv[0]);
        exit(1);
    }

    FILE *f = fopen(argv[1],"w");
    if(f == NULL)
        perror("Impossibile aprire il file");

    int n,e;

    e = puts("Inserisci la dimensione dell'array");
    e = scanf("%d",&n);
    if(e != 1){
        termina("Lettura fallita");
    }

    if(n <= 2){
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

    stampaArray(a,messi, f);

    printf("Output messo nel file\n");
    free(a);
    if(fclose(f) != 0)
        termina("Errore chiusura file");

    printf("\n\n%d\n\n",lunghezza_stringa("ciasod"));

    int merge[] = {1,16,17,18,10,2,13,14,15,11,12,19,20,3,4,5,6,7,8,9};
    stampaArray(merge,20,stdout);
    merge_sort(merge,20);
    stampaArray(merge,20,stdout);
    return 0;
} 
