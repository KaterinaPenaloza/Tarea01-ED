#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 50

//Creacion de la cola
int Cola[MAX];
int front = 0;
int back = -1;
int count = 0;

int size(){
  return count;
}  

bool vacia(){
  return size() == 0;
}

bool llena(){
  return count == MAX;
}

int frente(){
  if(!vacia()){
    return Cola[front];
  }
  else{
    printf("\nError al encontrar el frente");
    return -1;
  }
}

bool encolar(int e){
  //Si no está llena, encolar
  if(!llena()){
    if(back == MAX-1){
      back = -1;
    }       
    Cola[++back] = e;
    count++;
    printf("\nElemento encolado\n");
    return true;
  }
  else
    printf("\nError al encolar (cola llena)\n");
    return false;
}

int desencolar(){
  //Si la cola está llena
  if(front == MAX) {
    front = 0;
  }
  //Si la cola no está vacia, se puede desencolar
  if(!vacia()){
    int e = Cola[front++];
    count--;
    printf("\nElemento desencolado\n");
    return e;
  }
  else{
    printf("\nError al desencolar\n");
  }
}

bool anular(){
  while(!vacia()){
    desencolar();
  }
  return vacia();
}

int main(){  
  int n, op;
  do{
    printf( "\nMENU");
    printf( "\n1. Mostrar tamaño de la cola");
    printf( "\n2. Encolar elemento");
    printf( "\n3. Desencolar elemento");
    printf( "\n4. Mostrar frente");
    printf( "\n5. Vaciar la cola");
    printf( "\n6. ¿Está vacia?");
    printf( "\n7. Salir");
    printf( "\nIntroduzca opcion (1-7): ");
    scanf("%d", &op);
    switch(op){
      case 1:
        printf("\nEl tamaño de la cola es: %d\n", size());
        break;
      case 2:
        printf("\nIntroduzca el elemento a encolar (entero): ");
        scanf("%d", &n);
        encolar(n);
        break;
      case 3:
        desencolar();
        break;
      case 4:
        printf("\nEl frente de la cola es: %d", frente());
        break;
      case 5:
        if(anular()){
          printf("\nCola anulada");
        }
        else
          printf("\nError en vaciar la cola");
        break;
      case 6:
        if(vacia()){
          printf("\nVerdadero");
        }
        else
          printf("\nFalso");
        break;
    } 
  } while(op != 7);
}