#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Rutatransmilenio {
    char ruta[10];
    char paradas[15][50];
    char festivo;
};

void consultarParadas(struct Rutatransmilenio rutas[], int numRutas, char* ruta) {
    int i, j;
    for (i = 0; i < numRutas; i++) {
        if (strcasecmp(rutas[i].ruta, ruta) == 0) {
            printf("Paradas de la ruta %s:\n", ruta);
            for (j = 0; j < 15; j++) {
                if (strlen(rutas[i].paradas[j]) == 0)
                    break;
                printf("%s\n", rutas[i].paradas[j]);
            }
            return;
        }
    }
    printf("No se encontraron paradas para la ruta %s\n", ruta);
}

void consultarRutasFestivas(struct Rutatransmilenio rutas[], int numRutas) {
    printf("Rutas que funcionan en festivos:\n");
    int i;
    for (i = 0; i < numRutas; i++) {
        if (rutas[i].festivo == 'S') {
            printf("%s\n", rutas[i].ruta);
        }
    }
}

int main() {
    struct Rutatransmilenio rutas[] = {
        {"K16", {"Modelica", "Avenida Rojas", "El Tiempo-Camara de Comercio", "Salitre El Greco", "CAN", "Quinta Paredes", "Corferias", "Av el dorado", "Av chile", "NQS calle 75", "Pepe sierra", "Alcala", "Toberin", "Calle 187", "Terminal"}, 'N'},
        {"G43", {"Modelia", "Normandia", "Avenida Rojas", "El Tiempo-Camara de Comercio", "Salitre El Greco", "CAN", "", "", "", "", "", "", "", "", ""}, 'S'}
    };

    int numRutas = sizeof(rutas) / sizeof(rutas[0]);

    int opcion;
    char ruta[10];
    do {
        printf("\nMenu:\n");
        printf("1. Consultar paradas de una ruta de Transmilenio\n");
        printf("2. Consultar rutas que funcionan en festivos\n");
        printf("3. Salir\n");
        printf("Escoja una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese el numero de ruta de Transmilenio: ");
                scanf("%s", ruta);
                for(int i = 0; ruta[i]; i++){
                    ruta[i] = tolower(ruta[i]);
                }
                consultarParadas(rutas, numRutas, ruta);
                break;
            case 2:
                consultarRutasFestivas(rutas, numRutas);
                break;
            case 3:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
        }
    } while(opcion != 3);

    return 0;
}

