#include <stdio.h>

// Definição das estruturas
typedef struct
{
    char nome[50];
    char funcional[10];
    char titulacao[20];
} Professor;

typedef struct
{
    char nome[50];
    int codigo;
    int carga_horaria;
    Professor professor_responsavel;
} Disciplina;

typedef struct
{
    char nome[50];
    char matricula[10];
    int idade;
} Estudante;

// Protótipos das funções
void bubbleSort(Estudante estudantes[], int n);
int le_valida_idade();

int main()
{
    // Criação dos professores
    Professor professores[3];
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("Digite o nome do Professor %d: ", i + 1);
        scanf("%s", professores[i].nome);
        printf("Digite o funcional do Professor %d: ", i + 1);
        scanf("%s", professores[i].funcional);
        printf("Digite a titulação do Professor %d: ", i + 1);
        scanf("%s", professores[i].titulacao);
        printf("\n");
    }

    // Criação das disciplinas
    Disciplina disciplinas[2];
    for (i = 0; i < 2; i++)
    {
        printf("Digite o nome da Disciplina %d: ", i + 1);
        scanf("%s", disciplinas[i].nome);
        printf("Digite o codigo da Disciplina %d: ", i + 1);
        scanf("%d", &disciplinas[i].codigo);
        printf("Digite a carga horária da Disciplina %d: ", i + 1);
        scanf("%d", &disciplinas[i].carga_horaria);
        printf("Digite o número correspondente ao Professor responsavel pela Disciplina %d:\n", i + 1);
        for (int j = 0; j < 3; j++)
        {
            printf("%d. %s\n", j + 1, professores[j].nome);
        }
        int opcao;
        scanf("%d", &opcao);
        disciplinas[i].professor_responsavel = professores[opcao - 1];
        printf("\n");
    }

    // Criação dos estudantes
    Estudante estudantes[15];
    int numEstudantes;

    printf("Digite o numero de estudantes a serem cadastrados (máximo de 15): ");
    scanf("%d", &numEstudantes);

    if (numEstudantes > 15)
    {
        printf("Numero de estudantes excedeu o limite. Serão cadastrados apenas 15 estudantes.\n");
        numEstudantes = 15;
    }

    for (i = 0; i < numEstudantes; i++)
    {
        printf("Digite o nome do Estudante %d: ", i + 1);
        scanf("%s", estudantes[i].nome);
        printf("Digite a matricula do Estudante %d: ", i + 1);
        scanf("%s", estudantes[i].matricula);
        printf("Digite a idade do Estudante %d: ", i + 1);
        scanf("%d", &estudantes[i].idade);
        printf("\n");
    }

    // Ordenação dos estudantes por idade
    bubbleSort(estudantes, numEstudantes);

    // Relatório dos alunos matriculados na primeira disciplina ordenados por idade
    printf("Relatorio dos alunos matriculados na primeira disciplina ordenados por idade:\n");
    printf("Codigo da Disciplina\tNome do Professor\tNome do Estudante\tIdade do Estudante\n");
    for (i = 0; i < numEstudantes; i++)
    {
        printf("%d\t\t\t%s\t\t\t%s\t\t\t%d\n", disciplinas[0].codigo, disciplinas[0].professor_responsavel.nome, estudantes[i].nome, estudantes[i].idade);
    }

    // Relatório dos alunos matriculados na segunda disciplina ordenados por idade em ordem decrescente
    printf("\nRelatorio dos alunos matriculados na segunda disciplina ordenados por idade em ordem decrescente:\n");
    printf("Codigo da Disciplina\tNome do Professor\tNome do Estudante\tIdade do Estudante\n");
    for (i = numEstudantes - 1; i >= 0; i--)
    {
        printf("%d\t\t\t%s\t\t\t%s\t\t\t%d\n", disciplinas[1].codigo, disciplinas[1].professor_responsavel.nome, estudantes[i].nome, estudantes[i].idade);
    }

    return 0;
}

void bubbleSort(Estudante estudantes[], int n)
{
    int i, j;
    Estudante temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (estudantes[j].idade > estudantes[j + 1].idade)
            {
                temp = estudantes[j];
                estudantes[j] = estudantes[j + 1];
                estudantes[j + 1] = temp;
            }
        }
    }
}
