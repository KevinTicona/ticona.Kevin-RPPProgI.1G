#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM_N 4

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
} eNotebook;

void calcularIVA(float precio, float* resultado);

void printNotebook(eNotebook listNote);
int printNotebooks(eNotebook* listNote, int len);
int sortNotebooks(eNotebook* listNote, int len);

int reemplazarCaracter(char* cadena, char caracterA, char caracterB);

int main()
{
    /*
    1. Crear una función llamada calcularIVA que reciba como parámetro el
    precio bruto de un producto y devuelva el valor del impuesto (el IVA es 21%).
    Realizar la llamada desde main. *
    */
    float precio = 1000;
    float resultadoConIva;
    calcularIVA(precio, &resultadoConIva);

    printf("El precio es: %.2f\n", precio);
    printf("El valor del impuesto IVA es: %.2f\n", resultadoConIva);
    printf("\n\n");

    /*2. Crear una función que se llame reemplazarCaracter que reciba una cadena
    de caracteres como primer parámetro, como segundo parámetro el carácter a
    reemplazar y como tercero el nuevo carácter y devuelva la cantidad de veces
    que se reemplazo el carácter. int reemplazarCaracter(char [], char, char);
    */

    char frase[]="Hola como estas";
    printf("%s\n", frase);
    printf("La frase tiene %d cantidad de o\n", reemplazarCaracter(frase, 'o', 'a'));
    printf("\n\n");

    /*
    3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función
     que permita ordenar un array de dicha estructura por marca. Ante igualdad de marca
      deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main.
    */

    eNotebook listNotebooks[TAM_N] =
    {
        {100, "FX", "AMD", 10000.75},
        {101, "I7", "Intel", 25000.75},
        {102, "Ryzen 3", "AMD", 30000.89},
        {103, "Athlon", "AMD", 15000}
    };
    printNotebooks(listNotebooks,TAM_N);
    sortNotebooks(listNotebooks, TAM_N);
    printNotebooks(listNotebooks, TAM_N);



    return 0;

}

void calcularIVA(float precio, float* resultado)
{
    *resultado = (precio * 21) / 100;
}

int reemplazarCaracter(char* cadena, char caracterA, char caracterB )
{
    int lenCadena = strlen(cadena);
    int contarCaracter = 0;
    for(int i = 0; i < lenCadena; i++)
    {
        if(cadena[i] == caracterA)
        {
            strcpy(cadena[i],caracterB);
            contarCaracter++;
        }
    }
    return contarCaracter;
}


int sortNotebooks(eNotebook* listNote, int len)
{
    int error = -1;
    eNotebook auxNotebook;

    if(listNote!= NULL && len > 0)
    {
        for(int i = 0; i < len-1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(strcmp(listNote[i].marca, listNote[j].marca) > 0)
                {
                    auxNotebook = listNote[i];
                    listNote[i] = listNote[j];
                    listNote[j] = auxNotebook;
                }
                else if(strcmp(listNote[i].marca, listNote[j].marca) == 0 && listNote[i].precio < listNote[j].precio)
                {
                    auxNotebook = listNote[i];
                    listNote[i] = listNote[j];
                    listNote[j] = auxNotebook;
                }
            }
        }
        error = 0;

    }

    return error;
}


int printNotebooks(eNotebook* listNote, int len)
{
    if(listNote != NULL && len > 0 && len <= 10)
    {
        printf("  ID            PROCESADOR           MARCA              PRECIO\n");
        printf("--------------------------------------------------------------\n");
        for(int i = 0; i < len; i++)
        {
                printNotebook(listNote[i]);
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}

void printNotebook(eNotebook listNote)
{
    printf("%6d %15s            %8s              $%4.2f\n",
           listNote.id,
           listNote.procesador,
           listNote.marca,
           listNote.precio
          );
}
