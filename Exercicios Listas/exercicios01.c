/*Suponha que em um laboratório, cada paciente quando chega escolhe uma senha para atendimento. Essa senha pode ser para realizar exames de sangue ou exames de imagem. Quando um paciente é chamado pelo atendente ele deve informar o número da senha, seu nome, o plano de saúde(Unimed/Ipê) e o tipo de exame a fazer(sangue/imagem). Ao término do dia, cada atendente gera a listagem dos pacientes que ele atendeu. Apresente:

A listagem dos pacientes atendidos
A quantidade de pacientes atendidos que possuem Unimed.
A quantidade de pacientes atendidos para realizar exames de Sangue.

OBS: Apresente os dados com a seguinte construção (endereço do nó, valores do nó, valor do próximo).
*/

// O exercio nao possui algumas validacoes de input do usuario pq o intuito do probelema e verificar a solucao para lista encadeada.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct No
{
    int senha, planoDeSaude, tipoExame;

    char nome[30];

    struct No *proximo;
} No;

typedef struct Lista
{
    No *Inicio;
    No *Fim;
} Lista;

int menu()
{
    int opcao;

    printf("\n1 - Registrar Paciente: ");
    printf("\n2 - Listar os pacientes atendidos");
    printf("\n3 - A quantidade de pacientes que possuem unimed.");
    printf("\n4 - A quantidade de pacientes atendidos para realizar exames de Sangue..");
    printf("\n5- Sair ");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);

    while (opcao < 1 && opcao > 5)
    {
        printf("\nEscolha uma opcao valida: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

bool inserePacientenoFim(Lista *listaEncadeada, int senha, char *nome, int planoDeSaude, int tipoExame)
{

    No *novoNo = malloc(sizeof(No));

    if (novoNo)
    {

        novoNo->senha = senha;
        strcpy(novoNo->nome, nome);
        novoNo->planoDeSaude = planoDeSaude;
        novoNo->tipoExame = tipoExame;
        novoNo->proximo = NULL;

        if (listaEncadeada->Inicio == NULL)
        {
            listaEncadeada->Inicio = novoNo;
            listaEncadeada->Fim = novoNo;
        }
        else
        {
            listaEncadeada->Fim->proximo = novoNo;
            listaEncadeada->Fim = novoNo;
        }

        return true;
    }
    else
    {
        printf("\nNao foi possivel acadastrar o novo paciente!");
        return false;
    }
}
void imprimelista(Lista listaEncadeada)
{
    No *auxiliar = listaEncadeada.Inicio;

    printf("Senha\tNome\t\t|1/unimed 2/ipe|\t\t|1/sangue 2/imagem|\tendereco\tproximo");
    while (auxiliar)
    {
        printf("\n%d\t%s\t\t\t\t%d\t\t\t\t%d\t%p\t%p", auxiliar->senha, auxiliar->nome, auxiliar->planoDeSaude, auxiliar->tipoExame, auxiliar, auxiliar->proximo);
        auxiliar = auxiliar->proximo;
    }
}

int main()
{
    int loop = 0, senha, planoDeSaude, tipoExame;
    int contadorUnimed = 0, contadorSangue = 0;
    bool verifica;
    char nome[30];
    Lista listaEncadeada;
    listaEncadeada.Inicio = NULL;
    listaEncadeada.Fim = NULL;

    while (loop != 5)
    {
        switch (menu())
        {
        case 1:
            printf("\nInforme sua senha:");
            scanf("%d", &senha);
            printf("\nInforme o nome do paciente: ");
            scanf("\n");
            gets(nome);
            printf("\nInforme seu plano de saude \n1 - Unimed\n2 - Ipe: ");
            scanf("%d", &planoDeSaude);
            printf("\nInforme o tipo de exame \n1 - Sangue\n2 - Imagem: ");
            scanf("%d", &tipoExame);
            verifica = inserePacientenoFim(&listaEncadeada, senha, nome, planoDeSaude, tipoExame);

            if (verifica)
            {
                if (planoDeSaude == 1)
                {
                    contadorUnimed++;
                }

                if (tipoExame == 1)
                {
                    contadorSangue++;
                }
            }

            break;
        case 2:

            imprimelista(listaEncadeada);

            break;
        case 3:

            printf("\nForam atendidos %d pacientes que possuem unimed", contadorUnimed);

            break;
        case 4:
            printf("\nForam atendidos %d pacientes com exame de sangue", contadorSangue);
            break;
        case 5:
            loop = 5;
            break;
        }
    }
}
