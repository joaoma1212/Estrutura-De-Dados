# Estrutura-De-Dados

/******************************************************************************

1 - Crie uma apricaçao para armazenar idades de no maximo 50 alunos de uma 
faculdade esse apricaçao devera conter as seguintes apricaçoes A) Carreguar / 
B) Exibir / C) Linpar / D) Maior idade / E) Qtde de idades carregadas / 
F) Idade media

*******************************************************************************/

#include <stdio.h>

int main()
{
    int vidades [50] = {0};
    int i = 0;
    int opc = 0;
    int maior = 0;
    int contador = 0;
    float soma = 0;
    float media = 0;
    
    do {
        printf("\nCONTROLE DE IDADES\n");
        printf("\n1). Carregar \n");
        printf("\n2). Exibir\n");
        printf("\n3). Limpar\n");
        printf("\n4). Maior idade\n");
        printf("\n5). Qtde de idades carregadas\n");
        printf("\n6). Idade media\n");
        printf("\n9). Sair\n");
        printf("\nDigite a opcao: ");
        scanf("%i", &opc);
        
        if (opc == 1) {
            
            for (i = 0; i < 8; i++) {
                printf("Informe as idade: ");
                scanf("%i", &vidades[i]);
            }
            
        } else if (opc == 2) {
            
            for (i = 0; i < 8; i++) {
                
            //printf("%i\n", vidades[i]);
            printf("[%i] = %i\n", i, vidades[i]);
            }
            
        } else if (opc == 3) {
            
            for (i = 0; i < 8; i++) {
                vidades[i] = 0;
            }
            
        } else if (opc == 4) {
            
           maior = vidades[i];
            for (i = 0; i < 8; i++) {
             if(vidades[i] > maior) {
                 maior = vidades[i];
             }
            }
            
            printf("A maior idade e: %i", maior);
            
        } else if (opc == 5) {
           
            contador = 0;
           for (i = 0; i < 8; i++) {
               if (vidades[i] != 0) {
                   contador ++;
               }
           }
           
           printf("Existe(m) %i idade(s). \n", contador); 
            
        } else if (opc == 6) {
            contador = 0;
            soma = 0;
            
            for (i = 0; i < 8; i++) {
                if (vidades[i] != 0) {
                    contador = contador ++;
                    soma = soma + vidades[i];
                }
            }
            
            media = (soma / contador);
            
            printf("A media das idades e: %f \n", media);
        }
        
    } while (opc != 9);
    
    return 0;
}
