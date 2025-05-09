#include <stdio.h>

int main (){

    // Simular movimentação de três peças
 
/*
    Torre: Move-se em linha reta horizontalmente ou verticalmente. Seu programa deverá simular o movimento da Torre cinco casas para a direita.
 
    Bispo: Move-se na diagonal. Seu programa deverá simular o movimento do Bispo cinco casas na diagonal para cima e à direita. Para representar a diagonal, você imprimirá a combinação de duas direções a cada casa (ex: "Cima, Direita").
     
    Rainha: Move-se em todas as direções. Seu programa deverá simular o movimento da Rainha oito casas para a esquerda.
*/


//Torre movimenta 5 casas direita

printf("--------------------------------------------------------------------------\n");
printf("Movimentação: Torre - cinco casas para a direita\n");

int torre=0;

while (torre < 5)
    {

    printf("Direita\n");
    
     torre++;
    }

printf("--------------------------------------------------------------------------\n");
printf("Movimentação: Bispo - cinco casas na diagonal para cima e à direita.\n");

// mover 5 casas diagonal (cima direita)
for (int bispo = 0; bispo < 5; bispo++)
{
    printf("Cima Direita\n"); 
}

printf("--------------------------------------------------------------------------\n");
printf("Movimentação: Rainha - oito casas para a esquerda\n");
// Mover 8 para esquerda


int rainha =1;


    do{
        printf("Esquerda\n");
        rainha++;
          
    } while (rainha <= 8);
  


return 0;
}
