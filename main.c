#include <stdio.h>
#include "funcoes.h"


char ask();

int main(void) {

  no * pipa = NULL;

  int count = 0;

  char qual,cab;

  int resp = 1;

   printf("ORGANIZAÇÃO DE CAFIFAS.\n's' ou 'n' para responder:\n");

  do{
    
    printf("\n=================CAFIFA %d=================\n",count + 1);

    do{
      printf("\nnova? ");
      qual = ask();
    }while(qual == 'd'); 

    if(qual == 'n'){//se n for nova, pergunta se tem cabresto
      do{
        printf("\ncabresto? ");
        cab = ask();
      }while(cab == 'd');
    }
    else{//se n, ja coloca direto q precisa ser feito o cabresto por ser nova
      cab = 'n';
    }

    count ++;

    endInsert(&pipa,cab,qual,count);
    printf("\n[ID: %d, CABRESTO: %c, NOVA: %c] foi inserido com sucesso!\n",count,cab,qual);

    printf("\n==========================================\n");

    printf("\n#################  MENU  #################\n");
    do{
      
      printf("\nDeseja inserir mais uma pipa?\n1 - Para sim\n0 - Para não\n ");
      scanf("%d",&resp);

      if(resp != 1 && resp != 0 && resp > 'a' && resp < 'z')
        printf("Resposta invalida. Tente novamente!\n");
      
    }while(resp != 1 && resp != 0 && resp > 'a' && resp < 'z');
    
    printf("\n##########################################\n");
    
  }while(resp == 1);

  endInsert(&pipa,cab,qual,count);
  
  printf("\nFoi(ram) inserido(s) %d cafifa(s)\n",count);

  
  printf("\n---------------  NORMAL  ---------------\n");
  
  print(pipa);

  printf("\n-----------------------------------------\n");
  printf("\n---------------  REVERSO  ---------------\n");

  printf("CAFIFAS REVERSO:[\n");
  reversePrint(pipa, count);
  printf("]\n");
  
  return 0;
}

char ask (){
  
  char res;
    
  scanf(" %c",&res);

  if(res != 's' && res != 'n'){
    printf("\ncaracter invalido. Por favor, responda novamente:\n ");
    res = 'd';
  }
    
  return res;
}