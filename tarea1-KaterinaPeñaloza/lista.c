#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXSIZE 30

//En este caso ya que se implemento con arrays, si el elemento es 0, entonces significa que esta vacio. Por lo tanto insertar elementos mayores a 0
//Las posiciones a ingrsar son desde el 0 hasta MAXSIZE

//Constructor Lista
int Lista[MAXSIZE];     
int indice = -1;            
int count = 0;

int size(){
  return count;
}

bool vacia(){
  return (count == 0);
}

bool llena(){
  return (count == MAXSIZE);
}

int fin(){
  return Lista[count-1];
}

int siguiente(int p){
  if(p<0 || p>MAXSIZE){
    printf("\nPosición no válida");
    return -1;    
  }
  else{
    for(int indice; indice <= count; indice++){
      if(indice == p){
        return Lista[indice + 1];
      }
    }
  }
}

int previo(int p){
  if(p<0 || p>MAXSIZE){
    printf("\nPosición no válida");
    return -1;    
  }
  else{
    for(int indice; indice <= count; indice++){
      if(indice == p){
        return Lista[indice - 1];
      }
    }  
  }
}

int imprimir(){
  int n = (int)( sizeof(Lista) / sizeof(Lista[0]) );
  printf("\n");
  for(int i=0; i <= n; i++){
    //Si el elemento es un 0, se interpreta como que esta vacio
    if(Lista[i] == 0){
      printf(" ");
    }
    else{
    printf(" %d ", Lista[i]);
    }
  }
  printf("\n");
}

int insertar(int p, int e){
  //La lista debe ser secuencial, osea no dejar espacios entre medio vacios
  if(p!=0 && Lista[p-1]==0){
    printf("\nError al insertar elemento");
    return -1;    
  }
  //Insertar elemento si la pos es mayor a 0, menor a MAXSIZE y la lista no esta llena
  if(p>=0 && p<= MAXSIZE){
    if(!llena()){  
      Lista[p] = e;
      count++;
      printf("\nElemento insertado");
      return e;
    }
    else{
      printf("\nError al insertar elemento");
      return -1;
    }
  }
}

int localizar(int e){
  for(int i=0; i <= count; i++){
    if(Lista[i] == e){
      return i;
    }
  }  
}

int recuperar(int p){
  for(int indice; indice <= count; indice++){
    if(Lista[indice] == Lista[p]){
      return Lista[indice];
    }
  }    
}

void suprimir(int p){
  for(int i = 0; i <= count; i++){
    imprimir();
    if(i == p){
      Lista[i] = 0;
      count--;
      for(int j=i; j <= count; j++){
        Lista[j] = Lista[j+1];      
      }
    }
  }
  printf("\nElemento eliminado");
}

bool anular(){
  int i = 0;
  while(count != 0){
    Lista[i] = 0;
    count--;
    i++;
  }
  return vacia();
}

int main(void) {
    int e, p, op;
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
        printf("\nEl tamaño de la lista es: %d", size());
        break;
      case 2:
        anular();
        printf("\nLista anulada");
        break;
      case 3:
        if(vacia()){
          printf("\nVerdadero");
        }
        else
          printf("\nFalso");
        break;
      case 4:
        printf("\nEl elemento final de la lista es: %d", fin());
        break;
      case 5:
        printf("\nIngrese la posición: ");
        scanf("%d", &p);
        printf("\nEl elemento siguiente a la posición %d de la lista es: %d", p, siguiente(p));
        break;
      case 6:
        printf("\nIngrese la posición: ");
        scanf("%d", &p);
        printf("\nEl elemento previo a la posición %d de la lista es: %d", p, previo(p));
        break;
      case 7:
        imprimir();
        break;
      case 8:
        printf("\nIngrese la posición: ");
        scanf("%d", &p);
        printf("\nIngrese el elemento: ");
        scanf("%d", &e);
        insertar(p, e);
        break;
      case 9:
        printf("\nIngrese el elemento: ");
        scanf("%d", &e);
        if(localizar(e) != -1){
          printf("\nLa posición del elemento es: %d", localizar(e));
        }
        else{
          printf("\nNo se pudo encontrar la posición");
        }
        break;
      case 10:
        printf("\nIngrese la posición: ");
        scanf("%d", &p);
        if(recuperar(e) != -1){
          printf("\nEl elemento en la posición dada es: %d", recuperar(p));
        }
        else{
          printf("\nNo se pudo encontrar el elemento");
        }
        break;
      case 11:
        printf("\nIngrese la posicion del elemento a eliminar: ");
        scanf("%d", &p);
        suprimir(p);
        break;
    } 
  } while(op != 0);
}