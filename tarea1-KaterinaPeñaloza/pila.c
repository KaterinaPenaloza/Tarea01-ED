#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 50

int Pila[MAXSIZE];     
int tope_index = -1;            
int count = 0;

int size(){
  return count;
}

bool vacia(){
  if(tope_index == -1)
    return true;
  else
    return false;
}
   
bool llena(){
  if(tope_index == MAXSIZE)
    return true;
  else
    return false;
}

int tope(){
  if(!vacia()){
    return Pila[tope_index];
  }
  else{
    printf("\nError al obtener el tope");
    return -1;
  }
}

int pop(){
  int e;
  if(!vacia()){
    e = Pila[tope_index];
    tope_index = tope_index - 1; 
    count++;
    printf("\nElemento eliminado\n");
    return e;
  }
  else{
    printf("\nError al eliminar elemento.\n");
    return -1;
  }
}

int push(int e){
  if(!llena()){
    tope_index = tope_index + 1;   
    Pila[tope_index] = e;
    count++;
    printf("\nElemento insertado\n");
    return e;
  }
  else{
    printf("\nError al insertar elemento\n");
    return -1;
  }
}

bool anular(){
  while(!vacia()){
    pop();
  }
  return vacia();
}

int main(){
  int e, op;
  do{
    printf( "\nMENU");
    printf( "\n1. Mostrar tamaño de la pila");
    printf( "\n2. Meter elemento");
    printf( "\n3. Sacar elemento");
    printf( "\n4. Mostrar tope");
    printf( "\n5. Vaciar la pila");
    printf( "\n6. ¿Está vacía?");
    printf( "\n7. Salir");
    printf( "\nIntroduzca opción (1-7): ");
    scanf("%d", &op);
    switch(op){
      case 1:
        printf("\nEl tamaño de la pila es: %d\n", size());
        break;
      case 2:
        printf("\nIntroduzca el elemento a insertar (entero): ");
        scanf("%d", &e);
        push(e);
        break;
      case 3:
        pop();
        break;
      case 4:
        printf("\nEl tope de la pila es: %d\n", tope());
        break;
      case 5:
        if(anular()){
          printf("\nPila anulada\n");
        }
        else
          printf("Error en vaciar la pila\n");
        break;
      case 6:
        if(vacia()){
          printf("\nVerdadero\n");
        }
        else
          printf("\nFalso\n");
        break;
    } 
  } while(op != 7);
}