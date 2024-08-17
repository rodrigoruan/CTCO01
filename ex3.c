#include <stdio.h>

void preencher(float num[]){
    FILE *arq = freopen("dados (1).txt", "r", stdin);
    if (arq == NULL){
        printf("Erro em abrir o arquivo\n");
        return;
    }
    
    for (int i = 0; i < 20; i++) {
        scanf("%f,", &num[i]);
    }

    fclose(arq);
}

void imprimir(float num[]){
    for (int i=0; i<20; i++){
        printf("%f\n", num[i]);
    }
}

int main (void){
    float num[20];
    preencher(num);
    imprimir(num);
    return 0;
}