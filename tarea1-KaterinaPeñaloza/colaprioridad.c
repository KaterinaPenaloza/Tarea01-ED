#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Constructor
typedef struct nodo{
  int dato;
  int prioridad;  //menor valor, mayor prioridad
  struct nodo* next;
}Nodo;

struct cola{
  struct nodo *front;
  struct nodo *back;
};

//Crear nuevo nodo
Nodo* crearNodo(int e, int p){
  Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
  nuevo_nodo->dato = e;
  nuevo_nodo->prioridad = p;
  nuevo_nodo->next = NULL;
  return nuevo_nodo;
}

//Tamaño de la cola
int size(struct nodo *head){
  int count = 0;
  struct nodo *actual = head;
  while(actual != NULL){
    count++;
    actual = actual->next;
  }
  return count;
}

//Verificar si la cola está vacia
void vacia(Nodo** head){
  if(*head == NULL){
    printf("Verdadero");
  }
  else{
    printf("Falso");
  }
}

//Vaciar la cola
void anular(struct nodo** head){
  struct nodo* actual = *head;
  struct nodo* next;
  while(actual != NULL){
    next = actual->next;
    free(actual);
    actual = next;
  }   
  //Volver head a nulo
  *head = NULL;
  printf("\nCola anulada con éxito");
}

//Retornar el elemento con mayor prioridad
int elem_max(Nodo** head){
  return (*head)->dato;
}

//Retornar el elemento con menor prioridad
int elem_min(struct nodo* nodo){
  while(nodo!=NULL){
    if(nodo->next == NULL){
      return nodo->dato;
    }
      nodo = nodo->next;
  }
}

//Devuelve la prioridad maxima
int prioridad_max(Nodo** head){
  return (*head)->prioridad;
}

//Devuelve la prioridad minima
int prioridad_min(struct nodo* nodo){
  while(nodo!=NULL){
    if(nodo->next == NULL){
      return nodo->prioridad;
    }
      nodo = nodo->next;
  }
}

//Insertar un elemento a la cola de prioridad
void insertar(Nodo** head, int e, int p){
  Nodo* start = (*head);
  //Crear nodo
  Nodo* temp = crearNodo(e, p); 
  //Si el tope de la lista tiene menor prioridad que el nuevo nodo
  if((*head)->prioridad > p){
    temp->next = *head;
    (*head) = temp;
  }
  else{
   //Encontrar la posicion del nuevo nodo
    while(start->next != NULL && start->next->prioridad < p) {
      start = start->next;
    }
    temp->next = start->next;
    start->next = temp;
  }
}

//Remover elemento
void eliminar_minimo(Nodo** head){
  Nodo* temp = *head;
  (*head) = (*head)->next;
  free(temp);
}

//MENU
int main(void) {
  int e, p, op;
  printf("\nCrear cola: inserte el primer elemento con su prioridad ");
  printf("\nElemento: ");
  scanf("%d", &e);
  printf("\nPrioridad: ");
  scanf("%d", &p);
  struct nodo* head = crearNodo(e, p);
  
  do{
    printf( "\nMENU");
    printf( "\n1. Mostrar Tamaño de la cola");
    printf( "\n2. Vaciar la cola con prioridad");
    printf( "\n3. ¿La cola está vacía?");
    printf( "\n4. Elemento con mínima prioridad");
    printf( "\n5. Elemento con máxima prioridad");
    printf( "\n6. Insertar elemento");
    printf( "\n7. Mostrar la mínima prioridad");
    printf( "\n8. Mostrar la máxima prioridad");
    printf( "\n9. Eliminar mínimo");
    printf( "\n10. Crear cola");
    printf( "\n0. Salir");
    printf( "\nIntroduzca opción (0-10): ");
    scanf("%d", &op);
    switch(op){
      case 1:
        printf("\nEl tamaño de la cola es: %d", size(head));
        break;
      case 2:
        anular(&head);
        break;
      case 3:
        vacia(&head);
        break;
      case 4:
        printf("\nEl elemento con minima prioridad de la cola es: %d", elem_min(head));
        break;
      case 5:
        printf("\nEl elemento con máxima prioridad de la cola es: %d", elem_max(&head));
        break;
      case 6:
        printf("\nIngrese el elemento: ");
        scanf("%d", &e);
        printf("\nIngrese la prioridad: ");
        scanf("%d", &p);
        insertar(&head, e, p);
        break;
      case 7:
        printf("\nLa mínima prioridad es: %d", prioridad_min(head));
        break;
      case 8:
        printf("La máxima prioridad es: %d", prioridad_max(&head));
        break;
      case 9:
        eliminar_minimo(&head);
        break;
      case 10:
        printf("\nCrear cola: inserte el primer elemento con su prioridad ");
        printf("\nElemento: ");
        scanf("%d", &e);
        printf("\nPrioridad: ");
        scanf("%d", &p);
        struct nodo* head = crearNodo(e, p);
        break;
    } 
  } while(op != 0);
}