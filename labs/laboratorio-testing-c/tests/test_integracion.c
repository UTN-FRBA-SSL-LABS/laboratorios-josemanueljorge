#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_compra_con_descuento()
{
    Carrito c;
    carrito_init(&c);
    Producto pan = {"Pan", 200, 3};
    carrito_agregar(&c, pan);
    Producto leche = {"Leche", 350, 2};
    carrito_agregar(&c, leche);
    ASSERT_IGUAL(1300, carrito_total(&c));
    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), 10));

}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar()
{
    Carrito c;
   carrito_init(&c);
    Producto manzana = {"Manzana", 100, 1};

    for (int i = 0; i < MAX_ITEMS; i++) {
        carrito_agregar(&c, manzana);
    }

    ASSERT_IGUAL(MAX_ITEMS, c.cantidad); 

    int resultado = carrito_agregar(&c, manzana); // Intentamos agregar el 5to producto
    ASSERT_IGUAL(0, resultado);
    ASSERT_IGUAL(MAX_ITEMS, c.cantidad);
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento(); 
    test_agregar_hasta_llenar(); 
    RESUMEN();
    return EXIT_CODE();
}
