#ifndef Producto_h
#define Producto_h

#include <iostream>

typedef struct{
	int codigo;
	float precio;
	int unidades;
}tProducto;

void muestra(const tProducto &producto);
float totalVenta(const tProducto &producto);

#endif // !Producto_h
