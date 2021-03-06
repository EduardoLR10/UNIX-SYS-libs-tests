/*---------------------------------------------------------------------------
  Integrantes: 
    - Giordano Suffert Monteiro - 170011160; 
    - Eduardo Lemos Rocha - 170009157; 
    - Otho Teixeira Komatsu - 170020142;
    - Pedro Lucas Pinto Andrade - 160038316.

  Versão do SO: Ubuntu 16.04
  Versões do gcc testadas: 5.4.0, 7.4.0 e 10.2.0
---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int i, pid, n_filhos;

  // Recebimentos dos parâmetros necessários
  if (argc < 2) // Se não foi passado o parâmetro para o número de processos a serem gerados encerra a execução
  {
    printf("Passe o número de filhos que o processo deve gerar como argumento (<= 10)\n");
    exit(1);
  }
  else // Trata o primeiro parâmetro passado pelo usuário como um número inteiro
  {
    n_filhos = atoi(argv[1]);
  }

  // Caso o número de processos a serem criados seja maior que dez reduzimos seu valor para o máximo de 10
  if(n_filhos > 10) n_filhos = 10;

  printf("Sou o processo pai com pid = %d\n", getpid());

  // Loop para a criação de n processos
  for (i = 0; i < n_filhos; i++)
  {
    if ((pid = fork()) == -1) // Cria o processo filho e verifica se houve erro
    {
      printf("Error na criacao do fork!");
      exit(1);
    }
    if(pid == 0) // Proibe que os processos filhos tenham seus proprios filhos
    {
      printf("Sou o processo filho com pid = %d\n", getpid());
      break;
    }
  }
  
  if (sleep(30) > 0) // Deixa o processo dormindo e verifica se houve chamada foi interrompida por um manipulador de sinal
  {
      printf("Sleep interrompido.");
      exit(1);
  }

	return 0;

}
