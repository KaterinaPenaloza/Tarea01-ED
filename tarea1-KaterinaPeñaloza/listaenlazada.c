#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//CONSTRUCTOR
struct Nodo{
   int dato;
   struct Nodo *next;
};

//OPERACIONES
void imprimir(struct Nodo *nodo){
  while(nodo != NULL){
    printf(" %d ", nodo->dato);
    nodo = nodo->next;
  }
}

//Tamaño
int size(struct Nodo *head){
  int count = 0;
  struct Nodo *actual = head;
  while(actual != NULL){
    count++;
    actual = actual->next;
  }
  return count;
}
//Esta vacia?
bool vacia(struct Nodo** head){
  if(*head == NULL){
    printf("Verdadero");
  }
  else{
    printf("Falso");
  }
}

//Vaciar la lista
void anular(struct Nodo** head){
  //Apuntar al principio
  struct Nodo* actual = *head;
  struct Nodo* next;
  while(actual != NULL){
    next = actual->next;
    free(actual);
    actual = next;
  }   
  //Volver head a nulo
  *head = NULL;
}

//Encontrar el nodo final
int fin(struct Nodo *nodo){
    while(nodo != NULL){
      if(nodo->next == NULL){
        printf(" %d ", nodo->dato);
      }
    nodo = nodo->next;
  }
}

//SIGUIENTE
int siguiente(struct Nodo** head, int posicion){
  //Si la lista está vacia
  if(*head == NULL){
    return -1;
  }
  //Guardar head en un nodo temporal
  struct Nodo* temp = *head;
  //Encontrar el nodo de la posición
  for(int i = 0; temp != NULL && i < posicion; i++){
    //Aqui esta el siguiente jeje
    temp = temp->next;
    temp = temp->next;
  }
  //Si la posicion es mayor al que tiene la lista
  if(temp == NULL || temp->next== NULL){
    printf("Error al encontrar el elemento");
    return -1;
  }
  return temp->dato;
}


//PREVIO
int previo(struct Nodo** head, int posicion){
  //Si la lista está vacia
  if(*head == NULL){
    return -1;
  }
  //Guardar head en un nodo temporal
  struct Nodo* temp = *head;
  //Encontrar el nodo previo
  for(int i = 0; temp != NULL && i < posicion - 1; i++){
    temp = temp->next;
  }
  if(temp == NULL || temp->next== NULL){
    printf("Error al encontrar el elemento");
    return -1;
  }
  return temp->dato;
}

//Localizar la posicion de un elemento
int localizar(struct Nodo *nodo, int e){
  int pos = 0;
  while(nodo != NULL){
    if(nodo->dato == e){
      return pos;
    }
    nodo = nodo->next;
    pos++;
  }
}

//Recuperar un elemento dado su posicion
int recuperar(struct Nodo** head, int posicion){
  //Si la lista está vacia
  if(*head == NULL){
    return -1;
  }
  //Guardar head en un nodo temporal
  struct Nodo* temp = *head;
  //Encontrar el nodo de la posición
  for(int i = 0; temp != NULL && i < posicion; i++){
    //Aqui esta el siguiente jeje
    temp = temp->next;
  }
  //Si la posicion es mayor al que tiene la lista
  if(temp == NULL || temp->next== NULL){
    printf("Error al encontrar el elemento");
    return -1;
  }
  return temp->dato;
}

//Solo puedo insertar al final de la lista :(
void insertar(struct Nodo** head, int nuevo_dato){
  struct Nodo* nuevo_nodo = (struct Nodo*) malloc(sizeof(struct Nodo));
  struct Nodo *tail = *head;
  nuevo_nodo->dato = nuevo_dato;
  //Apuntar el nodo final a nulo
  nuevo_nodo->next = NULL;
  //Si la lista esta vacia
  if(*head == NULL){
    *head = nuevo_nodo;
    return;
  } 
  while(tail->next != NULL){
    tail = tail->next;
  }
  tail->next = nuevo_nodo;
  return;   
}

void suprimir(struct Nodo** head, int posicion){
  //Si la lista está vacia
  if(*head == NULL){
    return;
  }
  //Guardar head en un nodo temporal
  struct Nodo* temp = *head;
  //Si la posicion es 0, cambiar head (swap)
  if(posicion == 0){
    *head = temp->next;
    free(temp);
    return;
  }
  //Encontrar el nodo previo
  for(int i = 0; temp != NULL && i < posicion - 1; i++){
    temp = temp->next;
  }
  //Si la posicion es mayor al que tiene la lista
  if(temp == NULL || temp->next== NULL){
    return;
  }
  //Guardar el nodo siguiente al siguiente en ser borrado
  struct Nodo* next = temp->next->next;
  //Eliminar el nodo
  free(temp->next);
  //Eliminar el puntero
  temp->next = next;
}

//MENU
int main(void) {
  int e, p, op;
  struct Nodo* head = NULL;
  do{
    printf( "\nMENU");
    printf( "\n1. Mostrar tamaño de la lista");
    printf( "\n2. Anular()");
    printf( "\n3. Vacia()");
    printf( "\n4. Fin()");
    printf( "\n5. Siguiente()");
    printf( "\n6. Previo()");
    printf( "\n7. Imprimir()");
    printf( "\n8. Insertar()");
    printf( "\n9. Localizar()");
    printf( "\n10. Recuperar()");
    printf( "\n11. Suprimir()");
    printf( "\n0. Salir");
    printf( "\nIntroduzca opción (0-11): ");
    scanf("%d", &op);
    switch(op){
      case 1:
        printf("\nEl tamaño de la lista es: %d", size(head));
        break;
      case 2:
        anular(&head);
        break;
      case 3:
        vacia(&head);
        break;
      case 4:
        fin(head);
        break;
      case 5:
        printf("\nIngrese la posición: ");
        scanf("%d", &p);
        printf("\nEl elemento siguiente a la posición %d de la lista es: %d", p, siguiente(&head,p));
        break;
      case 6:
        printf("\nIngrese la posición: ");
        scanf("%d", &p);
        printf("\nEl elemento previo a la posición %d de la lista es: %d", p, previo(&head, p));
        break;
      case 7:
        imprimir(head);
        break;
      case 8:
        printf("\nIngrese el elemento: ");
        scanf("%d", &e);
        insertar(&head, e);
        break;
      case 9:
        printf("\nIngrese el elemento: ");
        scanf("%d", &e);
        if(localizar(head, e) != -1){
          printf("\nLa posición del elemento es: %d", localizar(head, e));
        }
        else{
          printf("\nNo se pudo encontrar la posicion");
        }
        break;
      case 10:
        printf("\nIngrese la posición: ");
        scanf("%d", &p);
        printf("\nEl elemento en la posición dada es: %d", recuperar(&head, p));
        break;
      case 11:
        printf("\nIngrese la posición a eliminar: ");
        scanf("%d", &p);
        suprimir(&head,p);
        break;
    } 
  } while(op != 0);
}