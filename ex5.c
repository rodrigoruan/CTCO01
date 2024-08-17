#include <stdio.h>
#include <stdlib.h>

void discountToProducts(int **p, int qtyProducts, int minQty, int percentageDiscount) {
    for (int i = 0; i < qtyProducts; i++) {
        if (p[i][2] >= minQty) {
            p[i][1] = p[i][1] * (100-percentageDiscount)/100;
        }
    }
}

int fillVector(int **p, int qtyProducts) {
    FILE *fp = freopen("produtos.dat", "r", stdin);
    if (fp == NULL) {
        perror("Error opening the file");
        return -1;
    }

    for (int i = 0; i < qtyProducts; i++) {
        if (feof(fp)) {
            printf("It wasn't possible to read %d products.\n", qtyProducts);
            return -1;
        }

        scanf("%d %d %d", &p[i][0], &p[i][1], &p[i][2]);
        printf("%d %d %d\n", p[i][0], p[i][1], p[i][2]);
    }

    fclose(fp);

    return 0;
}

void printProducts(int **p, int qtyProducts) {
    for (int i = 0; i < qtyProducts; i++) {
        printf("%d %d %d\n", p[i][0], p[i][1], p[i][2]);
    }
}

int main() {
    int n, discount;

    printf("Digite a quantidade de produtos: ");
    scanf("%d", &n);
    printf("Digite a porcentagem de desconto: ");
    scanf("%d", &discount);

    int **p = malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++) {
        p[i] = malloc(sizeof(int) * 3);
    }

    if (fillVector(p, n) != 0) {
        return -1;
    }

    discountToProducts(p, n, 50, discount);
    printf("\n");
    printProducts(p, n);

    return 0;
}