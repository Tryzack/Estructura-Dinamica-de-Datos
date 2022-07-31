#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{

   int dato;
   struct nodo *derecha;
   struct nodo *izquierda;

}nodo;
nodo *crearNodo(int dato), *insertarNodo(struct nodo *arbol, struct nodo *nuevo), *buscar(nodo *arbol, int dato);
void imprimirPreOrden(nodo *arbol), imprimirEnOrden(nodo *arbol), imprimirPostOrden(nodo *arbol); 

int main(){

    int n, i=1, c, f, j;
    struct nodo *arbol;
    struct nodo *aux;
    struct nodo *respuesta;

    printf("Bienvenido al arbol binario\n");
    printf("Trabajo realizado por: Jose Chacon\n");
    printf("C.I.: 30.310.209\n");
    system("PAUSE");

    printf("\nComo sabemos, un arbol binario debe tener principalmente una raiz que no debe ser modificada\n");
    printf("En el caso de este arbol binario, los valores que seran convertidos en nodos se ordenaran de la siguiente manera:\n mayores a la derecha y menores o iguales a la izquierda\n");

    printf("\nPara comenzar, ingrese la raiz del arbol Binario (enteros): \n");
    scanf("%d", &n);
    arbol = crearNodo(n);

    do{
      
        printf("\nQue operacion deseas realizar?\n");
        printf("[1] - Agregar un nodo\n");
        printf("[2] - Buscar la existencia de un nodo\n");
        printf("[3] - Imprimir arbol PreOrden\n");
        printf("[4] - Imprimir arbol InOrden\n");
        printf("[5] - Imprimir arbol PostOrden\n");
        printf("[6] - Salir\n");
        printf("Opcion: ");
        scanf("%d", &c);
        printf("\n");
      
        switch(c){
            case 1:
                printf("Cuantos nodos deseas agregar?\n");
                scanf("%d", &j);
                for(int k=0; k<j; k++){
                    printf("Ingresa el dato del nodo %d: ",k+1);
                    scanf("%d", &f);
                    aux = crearNodo(f);
                    insertarNodo(arbol, aux);
                }
                system("PAUSE");
            break;

            case 2:
                printf("Ingresa el dato del nodo a buscar: ");
                scanf("%d", &f);
                respuesta = buscar(arbol, f);
                if (respuesta != NULL) {
                    printf("El nodo si existe en el arbol: \n");
                    printf("Arbol InOrden: \n");
                    imprimirEnOrden(arbol);
                } else { 
                    printf("El nodo no existe en el arbol\n");
                    printf("Arbol InOrden: \n");
                    imprimirEnOrden(arbol);
                }
                system("PAUSE");
            break;

            case 3:
                printf("El arbol PreOrden es el siguiente:\n");
                imprimirPreOrden(arbol);
                system("PAUSE");
            break;

            case 4:
            printf("El arbol EnOrden es el siguiente:\n");
                imprimirEnOrden(arbol);
                system("PAUSE");
            break;
            
            case 5:
            printf("El arbol PostOrden es el siguiente:\n");
                imprimirPostOrden(arbol);
                system("PAUSE");
            break;

            case 6:
                printf("Seguro que deseas salir?\n");
                printf(" [1] - NO        [2] - SI\n");
                scanf("%d", &i);
            break;

            default:
            printf("Opcion incorrecta, intente de nuevo\n");
            i=1;
            system("PAUSE");
            break;
        }
    }while(i==1);

    return 0;
}

nodo *crearNodo(int dato) { 

    nodo *aux = malloc(sizeof(nodo));

    aux->dato = dato;
    aux->izquierda = NULL;
    aux->derecha = NULL;

    return aux;

 }

nodo *insertarNodo(struct nodo *arbol, struct nodo *nuevo) { 

    if (arbol==NULL){
        arbol = nuevo;
    } else {
        if (nuevo->dato > arbol->dato){
            arbol->derecha = insertarNodo(arbol->derecha, nuevo);
        } else {
            arbol->izquierda = insertarNodo(arbol->izquierda, nuevo);
        }
    }

    return arbol;
}

nodo *buscar(nodo *arbol, int dato) {
    
    nodo *respuesta = NULL;

    if (arbol!=NULL){
        if (dato==arbol->dato) {
            respuesta = arbol;
        } else {
            if (dato>arbol->dato){
                respuesta = buscar(arbol->derecha, dato);
            } else {
                respuesta = buscar(arbol->izquierda, dato);
            }
        }
    }

    return respuesta;
}

void imprimirPreOrden(nodo *arbol) {

/*  Cuando se imprime preorden se empieza por la raiz y se imprimen desde la raiz el nodo a la izquierda del nodo actual
    Una vez que no hayan nodos a la izquierda para imprimir, se utiliza el nodo a la derecha del nodo actual y se devuelve con la recursividad
    Imprimiendo de esta forma todos los nodos ahora a la derecha hasta que encuentre en algun nodo anterior otro nodo a la izquierda.
*/
    if (arbol != NULL) {  

        printf("%d - ", arbol->dato);
        imprimirPreOrden(arbol->izquierda);
        imprimirPreOrden(arbol->derecha);

    }

}

void imprimirEnOrden(nodo *arbol) {

/*  En este caso ocurre algo distinto al nodo anterior, primero se va todo lo posible a la izquierda antes de imprimir, y luego se imprime de izquierda a derecha
    Siempre que no hayan nodos restantes a la izquierda, esto hace que el nodo raiz termine en el medio (siempre y cuando sea un arbol balanceado)
*/
    //printf("Los datos del arbol en Preorden, son los siguientes: \n");
    if (arbol != NULL) {  
        
        imprimirEnOrden(arbol->izquierda);
        printf("%d - ", arbol->dato);
        imprimirEnOrden(arbol->derecha);

    }

}

void imprimirPostOrden(nodo *arbol) {

/*  Este caso es similar al pre orden, con la diferencia de que en vez de ir imprimiendo los datos cuando se encuentran, primero se llega al limite y luego imprime los datos
    De cada hoja posible antes de llegar a la raiz, a diferencia de el modo en orden, la raiz aparecera al final en lugar de al medio
*/
    if (arbol != NULL) {  

        imprimirPostOrden(arbol->izquierda);
        imprimirPostOrden(arbol->derecha);
        printf("%d - ", arbol->dato);

    }

}
