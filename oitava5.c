/*Em uma pesquisa envolvendo 20 entrevistados, uma editora solicitou os seguintes dados:
sexo, idade e quantidade de livros que leu em 2020. Faça um programa que leia os dados
digitados pelo usuário e ao final, calcule e imprima:
a) A quantidade total de livros lidos pelos entrevistados menores de 10 anos;
b) A quantidade de mulheres que leram 5 livros ou mais;
c) O percentual de pessoas que não leram livros.
 acrescente no algoritmo um menu que permita ao
usuário escolher um dos seguintes tipos de relatórios:
a) Por ordem inversa de registro;
b) Por idade em ordem crescente;
c) Por idade em ordem decrescente;
d) Por sexo e por ordem de sexo; esses eu fiz separados nao entendi muito bem a questão */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  int entrevistados = 3;
  struct entrevistado
  {
    char sexo;
    int idade;
    int livros_lidos;
  };
  struct entrevistado d[entrevistados];

  int total_livros_lidos_menores_de_10_anos = 0;
  int contador_m = 0;
  int nao_leram = 0;
  int opcao;
  float porcentagem = 0;
  float percentual = 0;
  int aux_idade = 0;
  char aux_sexo = ' ';
  int aux_livros_lidos = 0;
  char sexo_relatorio;
  char continuar = 's';
  for (int i = 0; i < entrevistados; i++)
  {
    printf("insira seu sexo (f=feminino ou m=masculino): ");
    scanf("%c", &d[i].sexo);
    fflush(stdin);
    while (d[i].sexo != 'f' && d[i].sexo != 'm')
    {
      printf("insira seu sexo (f=feminino ou m=masculino): ");
      scanf("%c", &d[i].sexo);
      fflush(stdin);
    }
    printf("insira sua idade: ");
    scanf("%d", &d[i].idade);
    fflush(stdin);
    printf("insira a quantidade de livros lidos em 2020: ");
    scanf("%d", &d[i].livros_lidos);
    fflush(stdin);
  }
  for (int i = 0; i < entrevistados; i++)
  {
    if (d[i].idade < 10)
    {
      total_livros_lidos_menores_de_10_anos = total_livros_lidos_menores_de_10_anos + d[i].livros_lidos;
    }
  }
  for (int i = 0; i < entrevistados; i++)
  {
    if (d[i].sexo == 'f' && d[i].livros_lidos >= 5)
    {
      contador_m++;
    }
  }
  for (int i = 0; i < entrevistados; i++)
  {
    if (d[i].livros_lidos == 0)
    {
      nao_leram++;
    }
  }
  porcentagem = 100 / entrevistados; // entrevistados
  percentual = porcentagem * nao_leram;
  // deixar essas opcoes em loop ate o usuario dizer que nao quer mais
  printf("voce quer imprimir um relatorio? (s=sim ou n=nao): ", &continuar);
  scanf(" %c", &continuar);
  while (continuar != 'n')
  {
    printf("Opções de impressão de relatório:\n");
    printf("1-Por ordem inversa de registro.\n");                                                // deu
    printf("2-Por idade em ordem crescente.\n");                                                 // deu
    printf("3-Por idade em ordem decrescente.\n");                                               // deu
    printf("4-Por sexo imprime um relatório com individuos do sexo escolhido.\n");               // deu
    printf("5-Por ordem de sexo (imprime em ordem de feminino primeiro e masculino depois).\n"); // deu
    printf("insira a opcao desejada: ");
    scanf("%d", &opcao);
    fflush(stdin);
    switch (opcao)
    {
    case 1:
    {
      printf("Entrevistados\n");
      for (int i = 2; i >= 0; i--)
      {
        printf("%c, %d anos de idade e %d livros lidos\n", d[i].sexo, d[i].idade, d[i].livros_lidos);
      }
      printf("\n");
      printf("voce quer continuar? (s=sim ou n=nao): ", &continuar);
      scanf(" %c", &continuar);
      break;
    }
    case 2:
    {
      for (int i = 0; i < entrevistados; i++)
      {
        for (int j = 0; j < entrevistados; j++)
        {
          if (d[i].idade < d[j].idade)
          {
            aux_idade = d[i].idade;
            d[i].idade = d[j].idade;
            d[j].idade = aux_idade;
            aux_sexo = d[i].sexo;
            d[i].sexo = d[j].sexo;
            d[j].sexo = aux_sexo;
            aux_livros_lidos = d[i].livros_lidos;
            d[i].livros_lidos = d[j].livros_lidos;
            d[j].livros_lidos = aux_livros_lidos;
          }
        }
      }
      printf("Entrevistados\n");
      for (int i = 0; i < entrevistados; i++)
      {

        printf("%c, %d anos de idade e %d livros lidos\n", d[i].sexo, d[i].idade, d[i].livros_lidos);
      }
      printf("\n");
      printf("voce quer continuar? (s=sim ou n=nao): ", &continuar);
      scanf(" %c", &continuar);
      break;
    }
    case 3:
    {
      for (int i = 0; i < entrevistados; i++)
      {
        for (int j = 0; j < entrevistados; j++)
        {
          if (d[i].idade > d[j].idade)
          {
            aux_idade = d[i].idade;
            d[i].idade = d[j].idade;
            d[j].idade = aux_idade;
            aux_sexo = d[i].sexo;
            d[i].sexo = d[j].sexo;
            d[j].sexo = aux_sexo;
            aux_livros_lidos = d[i].livros_lidos;
            d[i].livros_lidos = d[j].livros_lidos;
            d[j].livros_lidos = aux_livros_lidos;
          }
        }
      }
      printf("Entrevistados\n");
      for (int i = 0; i < entrevistados; i++)
      {

        printf("%c, %d anos de idade e %d livros lidos\n", d[i].sexo, d[i].idade, d[i].livros_lidos);
      }
      printf("\n");
      printf("voce quer continuar? (s=sim ou n=nao): ", &continuar);
      scanf(" %c", &continuar);
      break;
    }
    case 4:
    {
      printf("Qual sexo você quer o relatório? (f=feminino ou m=masculino): ");
      scanf("%c", &sexo_relatorio);
      fflush(stdin);
      while (sexo_relatorio != 'f' && sexo_relatorio != 'm')
      {
        printf("Qual sexo você quer o relatório? (f=feminino ou m=masculino): ");
        scanf("%c", &sexo_relatorio);
        fflush(stdin);
      }
      printf("Entrevistados do sexo %c\n", sexo_relatorio);
      for (int i = 0; i < entrevistados; i++)
      {
        if (d[i].sexo == sexo_relatorio)
        {
          printf("%c, %d anos de idade e %d livros lidos\n", d[i].sexo, d[i].idade, d[i].livros_lidos);
        }
      }
      printf("\n");
      printf("voce quer continuar? (s=sim ou n=nao): ", &continuar);
      scanf(" %c", &continuar);
      break;
    }
    case 5:
    {
      printf("Entrevistados\n");
      for (int i = 0; i < entrevistados; i++)
      {
        if (d[i].sexo == 'f')
        {
          printf("%c, %d anos de idade e %d livros lidos\n", d[i].sexo, d[i].idade, d[i].livros_lidos);
        }
      }
      for (int i = 0; i < entrevistados; i++)
      {
        if (d[i].sexo == 'm')
        {
          printf("%c, %d anos de idade e %d livros lidos\n", d[i].sexo, d[i].idade, d[i].livros_lidos);
        }
      }
      printf("\n");
      printf("voce quer continuar? (s=sim ou n=nao): ", &continuar);
      scanf(" %c", &continuar);
      break;
    }
    default:
    {
      printf("opcao invalida\n");
    }
    }
  }
  printf("Total livros lidos por menores de 10 anos: %d\n", total_livros_lidos_menores_de_10_anos);
  printf("Total mulheres que leram 5 livros ou mais: %d\n", contador_m);
  printf("Porcentagem de pessoas que não leram nada: %2.f %%", percentual);
  return 0;
}
