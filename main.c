#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[80], curso[30];
    int matricula;
} Aluno;

void titulo(void);
void loading(int tempo);
void removerAluno(Aluno alunos[], int *total_alunos);

int max_alunos = 100;

int main()
{
    Aluno alunos[max_alunos];
    int r, total_alunos = 0;
    do
    {
        titulo();
        printf("\nO que quer fazer? [Escreva o numero]\n--> ");
        scanf(" %d", &r);

        // execução dos comandos
        switch (r)
        {
        case 1:
            system("cls");
            printf("\nIniciando cadastro do aluno %d\n", total_alunos + 1);
            loading(2000);
            system("cls");
            printf("Qual o nome do aluno?\n--> ");
            while (getchar() != '\n')
                ; // limpar o buffer da memoria

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
            printf("\n%-30s %-25s %-10s\n","NOME:", "CURSO:", "MATRICULA:");
            printf("-----------------------------------------------------------------\n");
            for (int i = 0; i < total_alunos; i++)
            {
                printf(" %-30.30s %-25.25s %-10d\n\n", alunos[i].nome, alunos[i].curso ,alunos[i].matricula);
            }
            system("pause");
            break;

        case 3:
            {
            int matricula, encontrado = 0;

            system("cls");
            printf("Informe o numero da matricula do aluno\n--> ");
            scanf(" %d", &matricula);

            for (int i = 0; i < total_alunos; i++)
            {
                if (alunos[i].matricula == matricula)
                {
                    encontrado = 1;

                    printf("\nAluno encontrado: %s --- %s\n", alunos[i].nome, alunos[i].curso);

                    while (getchar() != '\n');
                    printf("\nInsira novo nome\n--> ");
                    
                    fgets(alunos[i].nome, 80, stdin);
                    alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

                    printf("\nInsira novo curso\n--> ");
                    fgets(alunos[i].curso, 30, stdin);
                    alunos[i].curso[strcspn(alunos[i].curso, "\n")] = '\0';

                    printf("\nCadastro atualizado.\n");
                    break;
                }
            }

            if (encontrado == 0)
            {
                printf("\nAluno não encontrado.\n");
            }

            system("pause");

            break;
        }
        case 4:
            system("cls");
            removerAluno(alunos, &total_alunos);
            break;

        default:
            break;
        }

    } while (r != 0);

}

void titulo()
{
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

void loading(int tempo)
{
    printf(".");
    Sleep(tempo / 3);
    printf(".");
    Sleep(tempo / 3);
    printf(".");
    Sleep(tempo / 3);
}

void removerAluno(Aluno alunos[], int *total_alunos)
{
    int matricula;
    int encontrado = 0;

    printf("Digite a matricula do aluno que deseja remover:\n--> ");
    scanf("%d", &matricula);

    for (int i = 0; i < *total_alunos; i++)
    {
        if (alunos[i].matricula == matricula)
        {
            encontrado = 1;
            char temp[100];
            strcpy(temp, alunos[i].nome);

            for (int j = i; j < *total_alunos - 1; j++)
            {
                alunos[j] = alunos[j + 1];
            }

            (*total_alunos)--;

            printf("\nAluno %s removido com sucesso!\n", temp);
            break;
        }
    }

    if (encontrado == 0)
    {
        printf("\nAluno nao encontrado!\n");
    }

    system("pause");
}