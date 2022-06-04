// hacer un problema libre con respecto a lo visto en clase el dia 4/6/22 (arrays dinamicos)
/*
Problema: el usuario engresara una cantidad de estudiantes y cada uno tendra su respectiva nota
al final se debera de informar cuales estudiantes pasaron y cuales no e indicar el promedio de la seccion
y al final indicar el alumno con mayor calificacion (en caso de que dos o mas alumnos tengan buena calificacion)
*/


#include <stdio.h>
#include <stdlib.h>

int alumnos;
float *nota, notamayor,promedio;
void entrada1(), entrada2(), salida();

int main(){

    entrada1();

    entrada2();

    salida();

    free(nota);

    return 0;
}

void entrada1(){

    printf("Los alumnos con un puntaje mayor a 9.5 pasaran la materia\n");
    printf("Ingrese la cantidad de alumnos a evaluar\n");
    scanf("%d", &alumnos);
    nota=(float *)malloc(alumnos*sizeof(float));

}

void entrada2(){
    for(int c=0; c<alumnos; c++){
        
        printf("Ingrese la nota del alumno [%d]: ", c+1);
        scanf("%f", &nota[c]);
        promedio+=nota[c];
        if(nota[c]>notamayor){
            notamayor=nota[c];
        }
    }
    promedio/=alumnos;
}

void salida(){

    printf("\n");
    for(int c=0; c<alumnos; c++){
        if(nota[c]<9.5){
            printf("El alumno [%d] reprobo la materia\n", c+1);
        }else if(nota[c]<17){
            printf("El alumno [%d] aprobo la materia\n", c+1);
        }else{
            printf("El alumno [%d] aprobo la materia con notas excelentes\n", c+1);
        }
    }
    printf("El promedio de la seccion fue de %.2f\n", promedio);

    printf("La nota mayor fue de %.2f\n", notamayor);
    
    
}
