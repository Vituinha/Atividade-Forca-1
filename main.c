#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void copyright(){
    system("cls");
    printf("=============================================================\n\n");
    printf("JOGO DA FORCA\n");
    printf("Desenvolvido por: \n\tAntonio Gabriel Cardoso de Rezende Orlandini 18122\n\t");
    printf("\tXXXXX - NNNNNNNNNNNNNNNNNNN\n");
    printf("=============================================================\n\n");
}

int main()
{
    setbuf(stdout, 0);
    int h = 0, a = 0, b = 0, n = 0, cont = 0;
    char nome[34] = "", aux, letra;
do{
     system("cls");
     printf("Voce entrou no jogo da forca %s\n",nome);
     printf("Configuracoes(2)\n");
     printf("Jogar(1)\n");
     printf("Sair(0)\n");
     scanf("%d",&a);
    fflush(stdin);
      if(a == 1)
      {
        b = 0;
        copyright();
        int x;
        NoSecreto * lstSecreta = inicializaListaSecreta();
        NoSecreto * sorteada;
        char  aux1[31];
        NoSecreto * usadas = inicializaListaSecreta();
        lstSecreta = carregaListaArquivo(lstSecreta,"palavras.dat");
        imprimeListaSecreta(lstSecreta);

      do{
        cont = 0;
        system("cls");
        sorteada= sorteiaPalavra(lstSecreta);
        if(sorteada!=NULL)
            {
                strcpy(aux1,sorteada->palavra);
            n = conta(sorteada->palavra);
            for(int i = 0; i<n; i++)
            {
                    sorteada->palavra[i] = '*';
            }
            for(int x = 0; x<n*3; x++)
            {
                h = 0;
                if(strcmp(aux1,sorteada->palavra) == 0)
                {
                    printf("\nAcertou!!!\n");
                    h = 1;
                    break;
                }
                else
                {
                cont++;
                }
            copyright();
            printf("%s ", sorteada->palavra);
            printf("%s\n", sorteada->assunto);
            printf("Faca sua tentativa: ");
            scanf("%c",&letra);
            system("cls");
            fflush(stdin);
            for(int i = 0; i<n; i++)
                {
                if(aux1[i] == letra)
                {
                    sorteada->palavra[i] = aux1[i];
                }
            }
            }
            if(h == 1)
            {
            system("cls");
            printf("\nVoce ganhou fazendo %d tentaivas\n aperte enter para jogar novamente.",cont);
            }
            else
            {
                system("cls");
                printf("\nAcabaram suas tentativas!\n");
                printf("Numero de tentativas: %d aperte enter para tentar de novo.\n",cont);
            }
            lstSecreta = retiraUmElemento(lstSecreta,sorteada->palavra);
            aux = lstSecreta;
      }
            else
            {
                printf("Acabaram as palavras.\n\n");
                b = 1;
            }
      }
        while(getchar()!='f' && b == 0);
      }

    else if(a == 0)
    {
        return (0);
    }

    else if(a == 2)
    {
         CLEAR_SCREEN;
         printf("Digite seu primeiro nome: ");
         gets(nome);
    }
}while(a != 0);
    return 0;
}
