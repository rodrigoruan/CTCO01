#include <stdio.h>
#include <string.h>

typedef struct {
    int number;
    char name[100];
    float balance;
} tClient;

int numberExists(tClient clients[], int number, int qtyClients) {
    for (int i = 0; i < qtyClients; i++) {
        if (clients[i].number == number) {
            return 1;
        }
    }

    return 0;
}

int removeAccountWithSmallestBalance(tClient clients[], int qtyClients) {
    if (qtyClients == 0) return 0;

    float min = clients[0].balance;
    int idx = 0;

    for (int i = 1; i < qtyClients; i++) {
        if (clients[i].balance < min) {
            min = clients[i].balance;
            idx = i;
        }
    }

    return 1;
}

void printUserAccounts(tClient clients[], int qtyClients, char name[]) {
    if (qtyClients == 0) {
        printf("Nenhum usuario encontrado com este nome.\n");
        return;
    }

    for (int i = 0; i < qtyClients; i++) {
        if (strcmp(clients[i].name, name) == 0) {
            printf("Numero: %d; Nome: %s; Saldo: %f\n", clients[i].number, clients[i].name, clients[i].balance);
        }
    }
}

int main() {
    tClient clients[15];

    int option, qtyClients = 0;

    while (1) {
        printf("Menu de opcoes: \n");
        printf("1. Cadastrar conta.\n");
        printf("2. Visualizar todas as contas de determinado cliente.\n");
        printf("3. Excluir a conta com menor saldo.\n");
        printf("4. Sair.\n");
        printf("Digite o numero da opcao: ");
        scanf("%d", &option);

        if (option == 4) break;
        
        if (option == 1) {
            tClient client;

            printf("Digite o numero da conta: ");
            scanf("%d", &client.number);

            if(numberExists(clients, client.number, qtyClients)) {
                printf("Numero de conta ja existe.\nEncerrando operacao...");
                continue;
            }

            printf("Digite o nome do do cliente: ");
            scanf(" %[^\n]", &client.name);

            printf("Digite o saldo do cliente: ");
            scanf("%f", &client.balance);

            clients[qtyClients] = client;
            qtyClients++;
        }

        if (option == 3) {
            int resultCode = removeAccountWithSmallestBalance(clients, qtyClients);
            if (resultCode == 1) {
                qtyClients--;
            }
        }

        if (option == 2) {
            printf("Digite o nome do cliente para verificar suas contas: ");
            char name[100];
            scanf(" %[^\n]", &name);
            printUserAccounts(clients, qtyClients, name);
        }
    }

    return 0;
}