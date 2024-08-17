#include <stdio.h>

typedef struct tPerson {
    int code, age;
    char sex;
    float height;
    char eyeColor;
} tPerson;

int readData(tPerson people[]) {
    FILE *fp = freopen("dados.txt", "r", stdin);
    if(fp == NULL) {
        perror("Error opening file.");
        return -1;
    }

    for (int i = 0; i < 50; i++) {
        scanf("%d", &people[i].code);
        scanf(" %c", &people[i].sex);
        scanf("%f", &people[i].height);
        scanf("%d", &people[i].age);
        scanf(" %c", &people[i].eyeColor);

        if (feof(stdin)) {
            printf("Couldn't read 50 people.");
            return -1;
        }
    }

    fclose(fp);
    return 0;
}

void generateInformation(tPerson people[]) {
    int medianAge = 0, totalA = 0, totalPeople = 0;
    int maximumAge = people[0].age;
    int femalesMiddleAgedOrGreenEyes = 0;
    int totalMen = 0;

    for (int i = 0; i < 50; i++) {
        if (people[i].eyeColor == 'C' && people[i].height > 1.60) {
            medianAge += people[i].age;
            totalA++;
        }

        if (people[i].age > maximumAge) {
            maximumAge = people[i].age;
        }

        if (people[i].sex == 'F' && ((people[i].age >= 20 && people[i].age <= 45) || (people[i].eyeColor == 'V' && people[i].height < 1.70))) {
                femalesMiddleAgedOrGreenEyes++;
        }

        if (people[i].sex == 'M') {
            totalMen++;
        }

        totalPeople++;
    }

    printf("Media de idade das pessoas com olhos castanhos e altura superior a 1,60m: %.2f\n", (float)medianAge / (float)totalA);
    printf("Maior idade entre os habitantes: %d\n", maximumAge);
    printf("Quantidade de individuos do sexo feminino com idade entre 20 e 45 anos (inclusive) ou que tenham olhos verdes e altura inferior a 1,70m: %d\n", femalesMiddleAgedOrGreenEyes);
    printf("Percentual de homens: %.2f\n", ((float)totalMen / (float)totalPeople) * 100.00);
}

void printPeople(tPerson people[]) {
    for (int i = 0; i < 50; i++) {
        printf("%d ", people[i].code);
        printf("%c ", people[i].sex);
        printf("%f ", people[i].height);
        printf("%d ", people[i].age);
        printf("%c ", people[i].eyeColor);
        printf("\n");
    }
}

int main() {
    tPerson people[50];

    int resultCode = readData(people);
    if (resultCode != 0) {
        return -1;
    }

    printPeople(people);
    generateInformation(people);

    return 0;
}