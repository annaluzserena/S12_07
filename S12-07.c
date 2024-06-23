#include <stdio.h>
#include <string.h>

// Prototipos de funciones
void ingresoMateriales(int j, int k, int *cant_aceite, int *cant_filtros, int *cant_llantas, int *cant_frenos);
void servicio(int j, int *b, float precio, int *stock1, int *stock2, int *tmp1, int *tmp2, float *total_servicio, float *total_pedido);
int generarReporteDiario(int dia, float total_dia, int cont_sayf, int cont_sllantas, int cont_sliq, int cont_scomp, int stock_aceite, int stock_filtros, int stock_llantas, int stock_frenos, int tmp_aceite, int tmp_filtros, int tmp_llantas, int tmp_frenos);
int generarReporteSemanal(float total_semana, float total_ayf, float total_llantas, float total_liq, float total_comp, int stock_inicial_aceite, int stock_inicial_filtros, int stock_inicial_frenos, int stock_inicial_llantas, int cont_semana_ayf, int cont_semana_liq, int cont_semana_llantas, int cont_semana_comp, int stock_aceite, int stock_filtros, int stock_frenos, int stock_llantas);

int main() {
    // Variables globales del programa
    float total_pedido = 0, total_ayf = 0, total_llantas = 0, total_liq = 0, total_comp = 0, total_dia = 0, total_semana = 0;
    int stock_aceite = 0, stock_filtros = 0, stock_llantas = 0, stock_frenos = 0;
    int stock_inicial_aceite = 0, stock_inicial_filtros = 0, stock_inicial_llantas = 0, stock_inicial_frenos = 0;
    int i, b, n, op, l;
    float precio_ayf, precio_llantas, precio_liq, precio_comp;
    int cont_sayf = 0, cont_sllantas = 0, cont_sliq = 0, cont_scomp = 0;  // Contadores específicos de servicios
    int cont_semana_ayf = 0, cont_semana_llantas = 0, cont_semana_liq = 0, cont_semana_comp = 0;
    int tmp_aceite = 0, tmp_filtros = 0, tmp_llantas = 0, tmp_frenos = 0; // Contadores de materiales usados en el día

    // Solicitar precios de servicios al usuario
    printf("Ingrese el precio del servicio de aceite y filtros: ");
    scanf("%f", &precio_ayf);
    printf("Ingrese el precio del servicio de llantas: ");
    scanf("%f", &precio_llantas);
    printf("Ingrese el precio del servicio de cambio de líquido: ");
    scanf("%f", &precio_liq);
    printf("Ingrese el precio del servicio de mantenimiento completo: ");
    scanf("%f", &precio_comp);

    // Repetir incondicional para los 6 días de la semana (lun-sáb)
    for (i = 1; i <= 6; i++) {
        // Inicialización de contadores específicos por día
        cont_sayf = 0;
        cont_sllantas = 0;
        cont_sliq = 0;
        cont_scomp = 0;

        // Invocación al procedimiento para el ingreso de stock de materiales inicial
        printf("\nIngreso de stock de materiales inicial del día %d:\n", i);
        ingresoMateriales(1, 4, &stock_aceite, &stock_filtros, &stock_llantas, &stock_frenos);
        if(i == 1) {
            stock_inicial_aceite = stock_aceite;
            stock_inicial_filtros = stock_filtros;
            stock_inicial_frenos = stock_frenos;
            stock_inicial_llantas = stock_llantas;
        }
        b = 1;
        while (b == 1) {
            n = 1;
            while (n == 1) {
                printf("\nIngrese un servicio utilizado en el pedido:\n");
                printf("1 - Cambio de aceite y filtro\n");
                printf("2 - Reemplazo de llantas\n");
                printf("3 - Revisión y llenado de líquidos\n");
                printf("4 - Servicio de mantenimiento completo\n");
                printf("5 - Finalizar pedido\n");
                scanf("%d", &op);

                printf("Detalles del pedido: \n");

                switch (op) {
                    case 1:
                        servicio(1, &l, precio_ayf, &stock_aceite, &stock_filtros, &tmp_aceite, &tmp_filtros, &total_ayf, &total_pedido);
                        if(l == 1) {
                            printf("Servicio de cambio de aceite y filtros. \n");
                            printf("Precio: $%.2f \n", precio_ayf);
                            cont_sayf++;
                            total_ayf += precio_ayf;
                            total_pedido += precio_ayf;
                        }
                        break;
                    case 2:
                        servicio(3, &l, precio_llantas, &stock_llantas, 0, &tmp_llantas, 0, &total_llantas, &total_pedido);
                        if(l == 1) {
                            printf("Servicio de reemplazo de llantas. \n");
                            printf("Precio: $%.2f \n", precio_llantas);
                            cont_sllantas++;
                            total_llantas += precio_llantas;
                            total_pedido += precio_llantas;
                        }
                        break;
                    case 3:
                        servicio(4, &l, precio_liq, &stock_frenos, 0, &tmp_frenos, 0, &total_liq, &total_pedido);
                        if(l == 1) {
                            printf("Servicio de revisión y llenado de líquidos. \n");
                            printf("Precio: $%.2f \n", precio_liq);
                            cont_sliq++;
                            total_liq += precio_liq;
                            total_pedido += precio_liq;
                        }
                        break;
                    case 4:
                        servicio(1, &l, precio_ayf, &stock_aceite, &stock_filtros, &tmp_aceite, &tmp_filtros, &total_comp, &total_pedido);
                        servicio(3, &l, precio_llantas, &stock_llantas, 0, &tmp_llantas, 0, &total_comp, &total_pedido);
                        servicio(4, &l, precio_liq, &stock_frenos, 0, &tmp_frenos, 0, &total_comp, &total_pedido);
                        if(l == 1) {
                            printf("Servicio de mantenimiento completo. \n");
                            printf("Precio: $%.2f \n", precio_comp);
                            cont_scomp++;
                            total_comp += precio_comp;
                            total_pedido += precio_comp;
                        }
                        break;
                    case 5:
                        n = 0;
                        break;
                    default:
                        printf("Opción inválida.\n");
                        break;
                }
            }

            printf("Monto total del pedido: %.2f \n", total_pedido);

            total_dia += total_pedido;

            printf("\n¿Desea ingresar otro pedido?\n");
            printf("1 - Sí\n");
            printf("2 - No\n");
            scanf("%d", &b);

            total_pedido = 0;
        }
        // Generar reporte diario al finalizar el día
        generarReporteDiario(i, total_dia, cont_sayf, cont_sllantas, cont_sliq, cont_scomp, stock_aceite, stock_filtros, stock_llantas, stock_frenos, tmp_aceite, tmp_filtros, tmp_llantas, tmp_frenos);

        cont_semana_ayf += cont_sayf;
        cont_semana_llantas += cont_sllantas;
        cont_semana_liq += cont_sliq;
        cont_semana_comp += cont_scomp;
        // Reiniciar contadores diarios para el siguiente día
        cont_sayf = 0;
        cont_sllantas = 0;
        cont_sliq = 0;
        cont_scomp = 0;
        // Acumular el total día en el total semana
        total_semana += total_dia;
        total_dia = 0;
    }

    // Generar reporte semanal al finalizar la semana
    generarReporteSemanal(total_semana, total_ayf, total_llantas, total_liq, total_comp, stock_inicial_aceite, stock_inicial_filtros, stock_inicial_frenos, stock_inicial_llantas, cont_semana_ayf, cont_semana_liq, cont_semana_llantas, cont_semana_comp, stock_aceite, stock_filtros, stock_frenos, stock_llantas);

    return 0;
}

void ingresoMateriales(int j, int k, int *cant_aceite, int *cant_filtros, int *cant_llantas, int *cant_frenos) {
    // Procedimiento que facilita el ingreso de cantidad de materiales de cada tipo en diferentes presentaciones
    int op, cant, lectura, mult;

    for (j; j <= k; j++) {
        cant = 0;
        switch (j) {
            case 1:
                printf("Ingreso de la cantidad de aceite\n");
                break;
            case 2:
                printf("Ingreso de la cantidad de filtros\n");
                break;
            case 3:
                printf("Ingreso de la cantidad de llantas\n");
                break;
            case 4:
                printf("Ingreso de la cantidad de líquido de frenos\n");
                break;
        }
        op = 1;
        while (op != 3) {
            printf("Elija una opción:\n");
            printf("1 - Cantidad unitaria (litros o unidades sueltas de filtros/llantas)\n");
            printf("2 - Cantidad en bidones o paquetes (a especificar)\n");
            printf("3 - Finalizar\n");
            scanf("%d", &op);
            switch (op) {
                case 1:
                    printf("Ingrese la cantidad en unidades: ");
                    scanf("%d", &lectura);
                    cant += lectura;
                    break;
                case 2:
                    printf("Ingrese la cantidad de unidades por cada bidón/paquete: ");
                    scanf("%d", &mult);
                    printf("Ingrese la cantidad de bidones/paquetes: ");
                    scanf("%d", &lectura);
                    cant += (lectura * mult);
                    break;
                case 3:
                    printf("Ha finalizado el ingreso de la cantidad.\n");
                    break;
                default:
                    printf("Opción inválida.\n");
                    break;
            }
        }
        switch (j) {
            case 1:
                *cant_aceite += cant;
                printf("Cantidad de litros de aceite: %d \n", *cant_aceite);
                break;
            case 2:
                *cant_filtros += cant;
                printf("Cantidad de filtros en unidades: %d filtros\n", *cant_filtros);
                break;
            case 3:
                *cant_llantas += cant;
                printf("Cantidad de llantas en unidades: %d llantas\n", *cant_llantas);
                break;
            case 4:
                *cant_frenos += cant;
                printf("Cantidad de líquido de frenos en litros: %d l\n", *cant_frenos);
                break;
        }
    }
}

void servicio(int j, int *b, float precio, int *stock1, int *stock2, int *tmp1, int *tmp2, float *total_servicio, float *total_pedido) {
    // Procedimiento para el manejo de cada servicio de un pedido
    int cont1 = 0, cont2 = 0;
    int k;

    *b = 1;

    switch (j) {
        case 1:
            k = 2;
            ingresoMateriales(j, k, &cont1, &cont2, 0, 0);
            if(*stock1 >= cont1) {
                *stock1 -= cont1;
                *tmp1 += cont1;
            } else {
                printf("No hay stock suficiente. Pedido cancelado. \n");
                *b = 0;
            }
            if(*stock2 >= cont2) {
                *stock2 -= cont2;
                *tmp2 += cont2;
            } else {
                printf("No hay stock suficiente. Pedido cancelado. \n");
                *b = 0;
            }
            break;
        case 3:
            k = 3;
            ingresoMateriales(j, k, 0, 0, &cont1, 0);
            if(*stock1 >= cont1) {
                *stock1 -= cont1;
                *tmp1 += cont1;
            } else {
                printf("No hay stock suficiente. Pedido cancelado. \n");
                *b = 0;
            }
            break;
        case 4:
            k = 4;
            ingresoMateriales(j, k, 0, 0, 0, &cont1);
            if(*stock1 >= cont1) {
                *stock1 -= cont1;
                *tmp1 += cont1;
            } else {
                printf("No hay stock suficiente. Pedido cancelado. \n");
                *b = 0;
            }
            break;
    }

}

int generarReporteDiario(int dia, float total_dia, int cont_sayf, int cont_sllantas, int cont_sliq, int cont_scomp, int stock_aceite, int stock_filtros, int stock_llantas, int stock_frenos, int tmp_aceite, int tmp_filtros, int tmp_llantas, int tmp_frenos) {
    char max_material[50];

    // Encontrar el material más utilizado del día
    if((tmp_aceite > tmp_filtros) && (tmp_aceite > tmp_llantas) && (tmp_aceite > tmp_frenos)) {
        strcpy(max_material, "Aceite");
    } else if((tmp_filtros > tmp_aceite) && (tmp_filtros > tmp_llantas) && (tmp_filtros > tmp_frenos)) {
        strcpy(max_material, "Filtros");
    } else if((tmp_llantas > tmp_aceite) && (tmp_llantas > tmp_filtros) && (tmp_llantas > tmp_frenos)) {
        strcpy(max_material, "Llantas");
    } else {
        strcpy(max_material, "Líquido de frenos");
    }
    
    // Función para generar el reporte diario
    printf("\n--- Reporte del día %d ---\n", dia);
    printf("Cantidad de servicios realizados:\n");
    printf("Cambio de aceite y filtro: %d\n", cont_sayf);
    printf("Reemplazo de llantas: %d\n", cont_sllantas);
    printf("Revisión y llenado de líquidos: %d\n", cont_sliq);
    printf("Servicio de mantenimiento completo: %d\n", cont_scomp);
    printf("\nStock restante de materiales:\n");
    printf("Aceite: %d litros\n", stock_aceite);
    printf("Filtros: %d unidades\n", stock_filtros);
    printf("Llantas: %d unidades\n", stock_llantas);
    printf("Líquido de frenos: %d litros\n", stock_frenos);
    printf("Material más utilizado del día: %s \n", max_material);
    printf("\nMonto total recaudado del día: %.2f\n", total_dia);
}

int generarReporteSemanal(float total_semana, float total_ayf, float total_llantas, float total_liq, float total_comp, int stock_inicial_aceite, int stock_inicial_filtros, int stock_inicial_frenos, int stock_inicial_llantas, int cont_semana_ayf, int cont_semana_liq, int cont_semana_llantas, int cont_semana_comp, int stock_aceite, int stock_filtros, int stock_frenos, int stock_llantas) {
    char servicio_mas_recaudo[50];
    float porcentaje_ayf, porcentaje_llantas, porcentaje_liq, porcentaje_comp, porcentaje_stock_aceite, porcentaje_stock_filtros, porcentaje_stock_llantas, porcentaje_stock_frenos;
    
    // Determinar el servicio que más recaudó en la semana
    if (total_ayf >= total_llantas && total_ayf >= total_liq && total_ayf >= total_comp) {
        strcpy(servicio_mas_recaudo, "Cambio de aceite y filtro");
    } else if (total_llantas >= total_ayf && total_llantas >= total_liq && total_llantas >= total_comp) {
        strcpy(servicio_mas_recaudo, "Reemplazo de llantas");
    } else if (total_liq >= total_ayf && total_liq >= total_llantas && total_liq >= total_comp) {
        strcpy(servicio_mas_recaudo, "Revisión y llenado de líquidos");
    } else {
        strcpy(servicio_mas_recaudo, "Servicio de mantenimiento completo");
    }

    // Calcular porcentajes de recaudación por servicio
    porcentaje_ayf = (total_ayf / total_semana) * 100;
    porcentaje_llantas = (total_llantas / total_semana) * 100;
    porcentaje_liq = (total_liq / total_semana) * 100;
    porcentaje_comp = (total_comp / total_semana) * 100;

    // Calcular porcentajes de stock utilizado
    porcentaje_stock_aceite = (stock_inicial_aceite / stock_aceite) * 100;
    porcentaje_stock_filtros = (stock_inicial_filtros / stock_filtros) * 100;
    porcentaje_stock_llantas = (stock_inicial_llantas / stock_llantas) * 100;
    porcentaje_stock_frenos = (stock_inicial_frenos / stock_frenos) * 100;

    // Imprimir el reporte semanal
    printf("\n--- Reporte Semanal al final de la semana ---\n");
    printf("Servicio que más recaudó: %s\n", servicio_mas_recaudo);
    printf("\nCantidad de servicios por tipo:\n");
    printf("Cambio de aceite y filtro: %d\n", cont_semana_ayf);
    printf("Reemplazo de llantas: %d\n", cont_semana_llantas);
    printf("Revisión y llenado de líquidos: %d\n", cont_semana_liq);
    printf("Servicio de mantenimiento completo: %d\n", cont_semana_comp);
    printf("\nPorcentaje de recaudación por servicio:\n");
    printf("Cambio de aceite y filtro: %.2f%%\n", porcentaje_ayf);
    printf("Reemplazo de llantas: %.2f%%\n", porcentaje_llantas);
    printf("Revisión y llenado de líquidos: %.2f%%\n", porcentaje_liq);
    printf("Servicio de mantenimiento completo: %.2f%%\n", porcentaje_comp);
    printf("\nPorcentaje de stock utilizado:\n");
    printf("Aceite: %.2f%%\n", porcentaje_stock_aceite);
    printf("Filtros: %.2f%%\n", porcentaje_stock_filtros);
    printf("Llantas: %.2f%%\n", porcentaje_stock_llantas);
    printf("Líquido de frenos: %.2f%%\n", porcentaje_stock_frenos);
    printf("\nTotal recaudado en la semana: %.2f\n", total_semana);
}