#include "Producto.h"

using namespace std;

void muestra(const tProducto &producto){
	cout << producto.codigo << " - " << producto.unidades << " x " << producto.precio << " $ = " << totalVenta(producto)<< " $" << endl;
}

float totalVenta(const tProducto &producto) {
	return producto.precio * producto.unidades;
}
