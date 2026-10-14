#include <stdio.h>
#include <windows.h>
#include <locale.h>

void titulo();
void loading(int tempo);

typedef struct{                       //tipo personalizado "Aluno"
    char nome[80], curso[30];
    int matricula;
}Aluno;

int max_alunos = 100;
int main() {
    Aluno alunos[max_alunos];         //vetor de alunos
    int r, total_alunos = 0;
    do{
        titulo();
        printf("\nO que quer fazer? [Escreva o numero]\n--> ");
        scanf(" %d", &r);

        //execução dos comandos
        switch (r){
        case 1:
            system("cls");
            printf("\nIniciando cadastro do aluno %d\n", total_alunos + 1);
            loading(2000);
            system("cls");
            printf("Qual o nome do aluno?\n--> ");
            while (getchar() != '\n'); //limpar o buffer da memoria

            fgets(alunos[total_alunos].nome, 80, stdin);
            alunos[total_alunos].nome[strcspn(alunos[total_alunos].nome, "\n")] = '\0'; // Limpa o \n do nome

            printf("\nQual o curso?\n--> ");
            fgets(alunos[total_alunos].curso, 30, stdin);
            alunos[total_alunos].curso[strcspn(alunos[total_alunos].curso, "\n")] = '\0'; // Limpa o \n do nome

            alunos[total_alunos].matricula = 1000 + total_alunos;
            total_alunos += 1;

            system("cls");
            loading(2000);
            system("cls");
            printf("O aluno %s, foi cadastrado com sucesso!\n", alunos[total_alunos - 1].nome);
            system("pause");
            break;
        
        case 2:
            system("cls");
            printf("exibindo os alunos cadastrados:\n");
            loading(1500);
            system("cls");
            for(int i=0; i<=total_alunos; i++){
                printf(" %s\n", alunos[i].nome);
            }
            system("pause");
            break;

        case 3:
            break;

        case 4:
            break;

        default:
            break;
        }

    } while (r != 0);
    
}

void titulo(){
    system("cls");
    printf("=====================================\n");
    printf("         Cadastro de alunos\n");
    printf("=====================================\n");

    printf("\n1 - Cadastrar um aluno\n");
    printf("2 - Alunos cadastrados\n");
    printf("3 - Editar informacoes\n");
    printf("4 - Remover aluno\n");
    printf("0 - Sair\n");
}

void loading(int tempo){
    printf(".");
    Sleep(tempo / 3);
    printf(".");
    Sleep(tempo / 3);
    printf(".");
    Sleep(tempo / 3);
}