#include <stdio.h>
#include <string.h>
#include <math.h>

void ingresoMateriales(int *cant_aceite, int *cant_filtros, int *cant_llantas, int *cant_frenos);

int main() {
    // Programa principal

    // Declaración de variables de precios de servicios

    int precio_ayf, precio_llantas, precio_liq, precio_comp;
    int i, b;

    /*for(i = 1; i <= 6; i++) {
        printf("Día %d - Ingreso de precios");
        printf("Ingrese el precio del servicio de cambio de aceite y filtro: ");
        scanf("%.2f", &precio_ayf);
        printf("Ingrese el precio del servicio de reemplazo de llantas: ");
        scanf("%.2f", &precio_llantas);
        printf("Ingrese el precio del servicio de revisión y llenado de líquidos: ");
        scanf("%.2f", &precio_liq);
        printf("Ingrese el precio del servicio de mantenimiento completo: ");
        scanf("%.2f", &precio_comp);

        b = 1;

        while(b == 1) {

        }
    }*/

}

void ingresoMateriales(int *cant_aceite, int *cant_filtros, int *cant_llantas, int *cant_frenos) {
    // Procedimiento que facilita el ingreso de cantidad de materiales de cada tipo en diferentes presentaciones
    
    int j, s, op, cant, lectura, mult;
    char material[8];

    for(j = 1; j <= 4; j++) {
        cant = 0;

        switch(j){
            case 1:
                strcpy(material, "aceite");
            break;
            case 2:
                strcpy(material, "filtros");
            break;
            case 3:
                strcpy(material, "llantas");
            break;
            case 4:
                strcpy(material, "frenos");
            break;
        }

        s = 1;
        while(s == 1) {
            printf("Ingreso de la cantidad de %s \n", material);
            printf("Elegir una opción: \n");
            printf("1 - Cantidad unitaria (litros o unidades sueltas de filtros/llantas) \n");
            printf("2 - Cantidad en bidones o paquetes (a especificar) \n");
            printf("3 - Finalizar \n");
            scanf("%d", &op);

            switch(op) {
                case 1:
                    printf("Ingrese la cantidad en unidades: ");
                    scanf("%d", &lectura);
                    cant = cant + lectura;
                break;
                case 2:
                    printf("Ingrese la cantidad de unidades por cada bidón/paquete: ");
                    scanf("%d", &mult);
                    printf("Ingrese la cantidad de bidones/paquetes: ");
                    scanf("%d", &lectura);
                    cant = cant + (lectura * mult);
                break;
                case 3:
                    printf("Ha finalizado el ingreso de la cantidad de %s. \n", material);
                    s = 0;
                break;
            }
        }

        switch(j){
            case 1:
                *cant_aceite = cant;
            break;
            case 2:
                *cant_filtros = cant;
            break;
            case 3:
                *cant_llantas = cant;
            break;
            case 4:
                *cant_frenos = cant;
            break;
        }


    }

    printf("Cantidad de litros de aceite: %dl \n", *cant_aceite);
    printf("Cantidad de filtros en unidades: %d filtros \n", *cant_filtros);
    printf("Cantidad de llantas en unidades: %d llantas \n", *cant_llantas);
    printf("Cantidad de líquido de frenos en litros: %dl \n", *cant_frenos);
}