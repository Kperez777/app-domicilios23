#include <stdio.h>

#define MAX_PRODUCTOS 6
#define DOMICILIO 3000
#define IVA 0.19

typedef struct {
    int id;
    char nombre[30];
    float precio;
} Producto;

Producto catalogo[MAX_PRODUCTOS] = {
    {1, "Hamburguesa", 12000},
    {2, "Pizza", 18000},
    {3, "Perro caliente", 8000},
    {4, "Papas fritas", 5000},
    {5, "Gaseosa", 4000},
    {6, "Helado", 6000}
};

int carrito[MAX_PRODUCTOS] = {0};

// ===== UTILIDADES =====
void limpiarPantalla() {
    printf("\n\n");
}

// ===== MENU =====
void verMenu() {
    printf("\n🍔 ===== MENU ===== 🍔\n");
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        printf("%d. %-15s $%.0f\n", catalogo[i].id, catalogo[i].nombre, catalogo[i].precio);
    }
}

// ===== AGREGAR =====
void agregarProducto() {
    int id, cantidad;

    verMenu();
    printf("\nIngrese ID del producto: ");
    scanf("%d", &id);

    if (id < 1 || id > MAX_PRODUCTOS) {
        printf("❌ Producto no existe\n");
        return;
    }

    printf("Cantidad: ");
    scanf("%d", &cantidad);

    if (cantidad <= 0) {
        printf("❌ Cantidad invalida\n");
        return;
    }

    carrito[id - 1] += cantidad;
    printf("✅ Agregado correctamente\n");
}

// ===== ELIMINAR =====
void eliminarProducto() {
    int id;

    printf("\nIngrese ID a eliminar: ");
    scanf("%d", &id);

    if (id < 1 || id > MAX_PRODUCTOS) {
        printf("❌ Producto invalido\n");
        return;
    }

    if (carrito[id - 1] == 0) {
        printf("⚠️ Ese producto no esta en el carrito\n");
    } else {
        carrito[id - 1] = 0;
        printf("🗑️ Producto eliminado\n");
    }
}

// ===== VER CARRITO =====
void verCarrito() {
    float subtotal = 0;

    printf("\n🛒 ===== CARRITO ===== 🛒\n");

    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        if (carrito[i] > 0) {
            float sub = carrito[i] * catalogo[i].precio;
            printf("%s x%d -> $%.0f\n", catalogo[i].nombre, carrito[i], sub);
            subtotal += sub;
        }
    }

    if (subtotal == 0) {
        printf("Carrito vacio\n");
        return;
    }

    float iva = subtotal * IVA;
    float total = subtotal + iva + DOMICILIO;

    printf("\nSubtotal: $%.0f", subtotal);
    printf("\nIVA (19%%): $%.0f", iva);
    printf("\nDomicilio: $%d", DOMICILIO);
    printf("\nTOTAL: $%.0f\n", total);
}

// ===== CONFIRMAR =====
void confirmarPedido() {
    float subtotal = 0;

    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        subtotal += carrito[i] * catalogo[i].precio;
    }

    if (subtotal == 0) {
        printf("❌ No hay productos\n");
        return;
    }

    float iva = subtotal * IVA;
    float total = subtotal + iva + DOMICILIO;

    printf("\n🧾 ===== FACTURA ===== 🧾\n");

    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        if (carrito[i] > 0) {
            printf("%s x%d\n", catalogo[i].nombre, carrito[i]);
        }
    }

    printf("\nSubtotal: $%.0f", subtotal);
    printf("\nIVA: $%.0f", iva);
    printf("\nDomicilio: $%d", DOMICILIO);
    printf("\nTOTAL PAGADO: $%.0f\n", total);

    printf("\n🎉 Pedido confirmado!\n");

    // Vaciar carrito
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        carrito[i] = 0;
    }
}

// ===== VACIAR =====
void vaciarCarrito() {
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        carrito[i] = 0;
    }
    printf("🧹 Carrito vaciado\n");
}

// ===== MAIN =====
int main() {
    int opcion;

    do {
        printf("\n===== APP DOMICILIOS PRO =====\n");
        printf("1. Ver menu\n");
        printf("2. Agregar producto\n");
        printf("3. Ver carrito\n");
        printf("4. Eliminar producto\n");
        printf("5. Confirmar pedido\n");
        printf("6. Vaciar carrito\n");
        printf("7. Salir\n");
        printf("Opcion: ");

        scanf("%d", &opcion);

        switch (opcion) {
            case 1: verMenu(); break;
            case 2: agregarProducto(); break;
            case 3: verCarrito(); break;
            case 4: eliminarProducto(); break;
            case 5: confirmarPedido(); break;
            case 6: vaciarCarrito(); break;
            case 7: printf("👋 Hasta luego\n"); break;
            default: printf("❌ Opcion invalida\n");
        }

    } while (opcion != 7);

    return 0;
}