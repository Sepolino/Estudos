#include <stdio.h>
#include <stdlib.h>
#define CHAVE 3 //o número definido da chave da Cifra do Cesar
#define MAX 1000 //tamanho maximo de caracteres do arquivo

void criptografia(const char *nome)
{
	//definição das variaveis entrada e saida, do tipo FILE
    FILE *entrada = fopen(nome, "r");
    FILE *saida = fopen("criptografado.txt", "w");
    
    //falha se não existir o arquivo
    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    
    //criptografia, com uso de fgetc e fputc
    char ch;
    while ((ch = fgetc(entrada)) != EOF) {
        if ((ch >= 'a' && ch <= 'z'))
            fputc(((ch - 'a' + CHAVE) % 26) + 'a', saida);
        else if ((ch >= 'A' && ch <= 'Z'))
            fputc(((ch - 'A' + CHAVE) % 26) + 'A', saida);
        else
            fputc(ch, saida);
    }

    fclose(entrada); //fechando as entradas e saidas
    fclose(saida);
    printf("Arquivo criptografado como 'criptografado.txt'\n");
}

void descriptografia(const char *nome)
{
    FILE *entrada = fopen(nome, "r");
    FILE *saida = fopen("descriptografado.txt", "w");

    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    
    //descriptografia, com uso de fgetc e fputc
    char ch;
    while ((ch = fgetc(entrada)) != EOF) {
        if ((ch >= 'a' && ch <= 'z'))
            fputc(((ch - 'a' - CHAVE + 26) % 26) + 'a', saida);
        else if ((ch >= 'A' && ch <= 'Z'))
            fputc(((ch - 'A' - CHAVE + 26) % 26) + 'A', saida);
        else
            fputc(ch, saida);
    }

    fclose(entrada);  //fechando as entradas e saidas
    fclose(saida);
    printf("Arquivo descriptografado como 'descriptografado.txt'\n");
}

void visualizar(const char *nome)
{
    FILE *arquivo = fopen(nome, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    //visualizando o arquivo
    char ch;
    printf("\n============Conteudo de '%s'============\n", nome);
    while ((ch = fgetc(arquivo)) != EOF) {
        putchar(ch); //comando para colocar os caracteres dentro do arquivo no terminal
    }
    printf("\n==============Fim do arquivo==============\n");

    fclose(arquivo); //fechando o arquivo
}

int main()
{
    int opcao;
    char nomeArquivo[MAX];
    
    //loop menu até inserir o numero 9 
    do{
        system("cls");
        printf("=======================MENU======================\n\n");
        printf("\n1. Criptografar");
        printf("\n2. Descriptografar");
        printf("\n3. Visualizar");
        printf("\n9. Sair\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
            	system("cls");
            	printf("Digite o nome do arquivo (ex: texto.txt): ");
                scanf("%s", nomeArquivo);
                criptografia(nomeArquivo);
                printf("\n\n");
                system("pause");
                break;
            case 2:
            	printf("Digite o nome do arquivo (ex: texto.txt): ");
                scanf("%s", nomeArquivo);
                descriptografia(nomeArquivo);
                printf("\n\n");
                system("pause");
                break;
            case 3:
            	printf("Digite o nome do arquivo (ex: texto.txt): ");
                scanf("%s", nomeArquivo);
                visualizar(nomeArquivo);
                printf("\n\n");
                system("pause");
                break;
            case 9:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                printf("\n\n");
                system("pause");
                break;
        }
    }while (opcao != 9);

    return 0;
}
