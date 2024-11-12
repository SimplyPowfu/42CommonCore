#include <stdlib.h>
#include <stdio.h>

void *ft_calloc(unsigned int num, unsigned int size)
{
    unsigned int *arr;
    unsigned int  i;

    i = 0;
    arr = (unsigned int *)malloc(num * size);
    if(arr == NULL)
        return NULL;
    while(i < num)
    {
        arr[i] = 0;
        i++;
    }

    return (void *)arr;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    size_t num_elements = 5;

    // Alloca memoria per un array di 5 interi
    arr = (int *)ft_calloc(num_elements, sizeof(int));

    if (arr == NULL) {
        printf("Errore di allocazione memoria\n");
        return 1;
    }

    // Stampa i valori dell'array (dovrebbero essere tutti zero)
    for (size_t i = 0; i < num_elements; i++) {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }

    // Libera la memoria
    free(arr);

    return 0;
}
