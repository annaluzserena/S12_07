#include <stdio.h>
#include <string.h>
#include <math.h>

void ingresoMateriales(int j, int k, int *cant_aceite, int *cant_filtros, int *cant_llantas, int *cant_frenos);
void pedido(int j, float precio, int *stock1, int *stock2, int *contador, float *total_servicio, float *total_pedido);

int main() {
    // Programa principal

    // Declaración de variables globales del programa

    float precio_ayf, precio_llantas, precio_liq, precio_comp;
    float total_pedido, total_ayf, total_llantas, total_liq, total_comp;
    int stock_aceite = 0, stock_filtros = 0, stock_llantas = 0, stock_frenos = 0;
    int cont_ayf, cont_llantas, cont_liq, cont_comp;
    int i, b, op;
    char s[4];

    // Repetir incondicional para los 6 días de la semana (lun-sáb)
    for(i = 1; i <= 6; i++) {
        // Invocación al procedimiento para el ingreso de stock de materiales inicial
        printf("Ingreso de stock de materiales inicial del día %d: \n", i);
        ingresoMateriales(1, 4, &stock_aceite, &stock_filtros, &stock_llantas, &stock_frenos);

        // Ingreso del precio de cada servicio en variables de tipo real con 2 decimales
        printf("Día %d - Ingreso de precios (decimal con punto 0.00)");
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
            printf("Ingrese un servicio utilizado en el pedido: \n");
            printf("1 - Cambio de aceite y filtro \n");
            printf("2 - Reemplazo de llantas \n");
            printf("3 - Revisión y llenado de líquidos \n");
            printf("4 - Servicio de mantenimiento completo \n");
            printf("5 - Finalizar pedido \n");
            scanf("%d", &op);

            switch(op) {
                case 1:
                    pedido(1, precio_ayf, &stock_aceite, &stock_filtros, &cont_ayf, &total_ayf, &total_pedido);
                break;
                case 2:
                    pedido(2, precio_llantas, &stock_llantas, 0, &cont_llantas, &total_llantas, &total_pedido);
                break;
                case 3:
                    pedido(3, precio_liq, &stock_frenos, 0, &cont_liq, &total_liq, &total_pedido);
                break;
                case 4:
                    for(k = 1; k <= 3; k++) {
                        if(k == 1) {
                            pedido(1, precio_ayf, &stock_aceite, &stock_filtros, &cont_ayf, &total_ayf, &total_pedido);
                        } else if(k == 2) {
                            pedido(2, precio_llantas, &stock_llantas, 0, &cont_llantas, &total_llantas, &total_pedido);
                        } else if(k == 3) {
                            pedido(3, precio_liq, &stock_frenos, 0, &cont_liq, &total_liq, &total_pedido);
                        }
                    }
                    b = 0;
                break;
                case 5:
                    b = 0;
                    printf("Pedido finalizado - Detalles: \n");
                    printf("Servicios: \n");
                break;
                default:
                    printf("Opción inválida.\n");
                break;
            }
        }
    }

}

void ingresoMateriales(int j, int k, int *cant_aceite, int *cant_filtros, int *cant_llantas, int *cant_frenos) {
    // Procedimiento que facilita el ingreso de cantidad de materiales de cada tipo en diferentes presentaciones
    
    int s, op, cant, lectura, mult;
    char material[8];

    for(j; j <= k; j++) {
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
                default:
                    printf("Opción inválida.\n");
                break;
            }
        }

        switch(j){
            case 1:
                *cant_aceite += cant;
            break;
            case 2:
                *cant_filtros += cant;
            break;
            case 3:
                *cant_llantas += cant;
            break;
            case 4:
                *cant_frenos += cant;
            break;
        }


    }

    printf("Cantidad de litros de aceite: %dl \n", *cant_aceite);
    printf("Cantidad de filtros en unidades: %d filtros \n", *cant_filtros);
    printf("Cantidad de llantas en unidades: %d llantas \n", *cant_llantas);
    printf("Cantidad de líquido de frenos en litros: %dl \n", *cant_frenos);
}

void pedido(int j, float precio, int *stock1, int *stock2, int *contador, float *total_servicio, float *total_pedido) {
    // Procedimiento para el manejo de cada pedido (de uno o más servicios)


}