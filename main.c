#include <stdio.h>
#include <stdlib.h>

typedef struct dataNode {
  int indice;
  int valor;
} DataNode;

typedef struct Node {
  DataNode data;
  struct node* next;
} Node;

typedef struct list {
  int size;
  Node* head;
} List;


List* createList(){
  List* list = (List *) malloc(sizeof(List));
  list -> size = 0;
  list -> head = NULL;
  
  return list;
}

Node* atPos(List* lista, int index){
  if( index >= 0 && index < lista -> size ){
    Node* node = lista -> head;
    
    for(int i=0; i< index; i++){
      node = node -> next;
    }
    return node;
  }
  printf("Indice inválido!\n");
  return NULL;
}

int isEmpty(List* lista){
  return (lista -> size);
}

void pop_first(List* lista){
    if (isEmpty(lista) != 0){
      Node* pointer = lista -> head;
      lista -> head = pointer -> next;

      free(pointer);
      lista -> size--;
    }

}

void add(List* lista, DataNode data) {
  Node* node = (Node*) (malloc(sizeof(Node)));
  node -> data = data;
  node -> next = lista -> head;
  lista -> head = node;
  lista -> size++;
}

int get(List* lista, int index){
    Node* node = atPos(lista,index);
    if(node != NULL){
      printf("Índice : %d | Valor : %d\n\n",node -> data.indice, node -> data.valor );
    }
    return node -> data.indice;
}

void pop(List* lista,int index){
    if (index == 0) pop_first(lista);
    else {
      Node* node1 = atPos(lista,index);
      if( node1 != NULL ){
        Node* node2 = atPos(lista,index-1);
        node2 -> next = node1 -> next;

        free(node1);
        lista -> size--;
      }
  }
}


void pop_value(List* lista,int valor){
  Node* point = lista -> head;
  int count = 0;

  while(point != NULL){
    if(point -> data.valor == valor){
      printf("Valor removido!\n");
      break;
    }else{
      point = point -> next;
      count++;
    }
  }
  pop(lista,count);
  lista -> size--;
}


void set(List* lista,int index, int valor){
  Node* node = atPos(lista,index);
  if(node != NULL){
    node -> data.valor = valor;
  }else {
    printf("Índice inválido!\n");
  }
  printf("Valor atualizado!\n");
}

int size(List* lista){
  printf("%d",isEmpty(lista));
  return isEmpty(lista);
}

void clear(List* lista){
  while(isEmpty(lista) != 0){
    Node* pointer = lista -> head;
    lista -> head = pointer -> next;

    free(pointer);
    lista -> size--;
  }
  printf("Lista vazia!");
}

void print(List* lista){
    Node* point = lista -> head;
    
    if (isEmpty(lista) == 0) printf("Lista vazia!\n");
    
    while(point != NULL){
      printf("Indice : %d | Valor : %d\n",point -> data.indice, point -> data.valor);
      point = point -> next;
    }
    printf("\n");
}



int main(){
  List* lista = createList(); 
  DataNode data;
  int menu = -1;
  int index=0;
  int valor=0;

  do {
    printf("Menu\n1) Adicionar valor\n2) Verificar um index\n3) Remover por valor\n4) Remover por index\n5) Modificar um index\n6) Limpar a lista\n7) Tamanho da lista\n8) Printar a lista\nOpcao --> ");
    scanf("%d",&menu);

    switch (menu)
    {
    case 1:
      printf("Digite um valor : ");
      scanf("%d",&valor);
      data.indice = size(lista);
      data.valor = valor;
      add(lista,data);
      break;
    case 2:
      printf("Digite um index : ");
      scanf("%d",&index);
      get(lista,index);
      break;
    case 3:
      printf("Digite um valor para ser removido : ");
      scanf("%d",&valor);
      pop_value(lista,valor);
      break;
    case 4:
      printf("Digite um index para ser removido : ");
      scanf("%d",&index);
      pop(lista,index);
      break;
    case 5:
      printf("Digite um index : ");
      scanf("%d",&index);
      printf("Digite um valor : ");
      scanf("%d",&valor);
      set(lista,index,valor);
      break;
    case 6:
      clear(lista);
      break;
    case 7:
      printf("%d\n",size(lista));
      break;
    case 8:
      print(lista);
      break;
    case 0:
      break;

    default:
      printf("Opcao invalida!");
    }

  }while(menu != 0);
}