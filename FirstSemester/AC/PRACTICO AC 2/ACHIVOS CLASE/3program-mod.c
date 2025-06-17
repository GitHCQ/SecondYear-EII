#include <stdio.h>
#include <stdlib.h>
#include "3-4print-pte.h" // Cabecera para usar print_virtual_physical_pte
#include <sys/types.h>
#include <unistd.h>

int compare_ints(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(void) {
    // Arreglo y clave para usar bsearch
    int array[] = {1, 2, 3, 4, 5};
    int key = 3;

    // Uso de bsearch para buscar un elemento en el arreglo
    int *result = bsearch(&key, array, 5, sizeof(int), compare_ints);

    // Mostrar el resultado de la búsqueda
    if (result != NULL) {
        printf("Elemento encontrado: %d\n", *result);
    } else {
        printf("Elemento no encontrado\n");
    }

    // Mostrar la información de la función bsearch
    print_virtual_physical_pte(bsearch, "Información de la función bsearch\n"
                                        "----------------------------------\n");

    printf("\nProcess Identifier (PID): %d\n", getpid());

	printf("\nPress [ENTER] to continue\n");
	getchar(); /* Wait for ENTER */

    return 0;
}
