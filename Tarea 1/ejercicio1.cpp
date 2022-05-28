/*Investigar la asignación dinámica de arreglos

Uso de el operador new y del
operador delete

Realizar un ejercicio práctico con arreglos dinámicos en donde se demuestre
el uno de estos operadores.

En este caso reutilice el codigo de programacion 2 de metodos de ordenamiento (Metodo Burbuja) encontrado en el siguiente link
https://github.com/Tryzack/Programacion_II_Jose_Chacon/blob/main/Ejercicios/Metodo%20Burbuja.cpp
*/

#include <stdio.h>
#include <stdlib.h>

int x, *numeros, n, aux;
void pregunta(), respuesta();

int main(){

    pregunta(); //Funcion pregunta para obtener la cantidad de numeros y cuales son

    for(int i=0; i<x; i++){ //Codigo de metodo de burbuja

        for(int j=0; j<x; j++){

            if(numeros[j]>numeros[j+1]){

                aux=numeros[j];
                numeros[j]=numeros[j+1];
                numeros[j+1]=aux;

            }
        }
    }

    respuesta(); //Proporcionar los nuevos numeros ya reordenados

    delete [] numeros; //Eliminar el puntero para evitar fugas de informacion mediante "DELETE"
    return 0;
}

void pregunta(){
    printf("===============================================================================================================\n");
    printf("Bienvenido a la ordenadora dinamica de numeros\n");
    printf("Por favor indique la cantidad de numeros que va a colocar, posteriormente se le preguntara cuanto vale cada uno\n");
    printf("===============================================================================================================\n\n");
    scanf("%d", &x);

    numeros = new int[x]; //Asignar valor dinamico al arreglo mediante "NEW"

    for(int i=0; i<x; i++){

        printf("Ingrese el numero [%d]\n", i+1);
        scanf("%d",&numeros[i]);

    }
    x--;

}

void respuesta(){

    for(int i=0; i<x+1; i++){

        printf("El nuevo valor del arreglo en la posicion [%d] es de %d\n", i+1, numeros[i]);

    }
}
