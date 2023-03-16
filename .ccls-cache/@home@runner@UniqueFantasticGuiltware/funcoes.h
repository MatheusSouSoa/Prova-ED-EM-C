#include <stdlib.h>
#include <stdio.h>

typedef struct no{
  int id;
  char qualidade;
  char cabresto;
  struct no * prox;
}no;

void endInsert ( no ** lista, char cab, char qual, int cont){
  no * novo = (no*) malloc (sizeof(no));
  no * aux = *lista;
  
  if(novo){
    novo -> qualidade = qual;
    novo -> cabresto = cab;
    novo -> id = cont;
    novo -> prox = NULL;
    if(!*lista){
      *lista = novo;
    }
    else{
      while(aux -> prox){
        aux = aux -> prox;
      }
      if(!aux -> prox){
      aux -> prox = novo;
      novo -> id = cont;
      }
    }
  }
}

void print(no *lista){
  no * aux = lista;
  printf("CAFIFAS:[\n");
  while(aux -> prox){
    printf("\t[ID: %d, CABRESTO: %c, NOVA: %c]",aux -> id, aux->cabresto,aux->qualidade);
    aux = aux -> prox;
    if(aux -> prox){
      printf(",\n ");
    }
  }
  printf("\n]\n");
}

void reversePrint (no * lista, int count){

  if(lista != NULL && count != 0 ){
    reversePrint(lista -> prox, count - 1);
    printf("\t[ID: %d, CABRESTO: %c, NOVA: %c]\n",lista -> id, lista -> cabresto,lista -> qualidade);
  }
}
