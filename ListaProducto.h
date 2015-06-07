#ifndef ListaProducto_h
#define ListaProducto_h

#include "Producto.h"

typedef struct{
	tProducto *arrayProductos;
	int cont;
}tListaProd;

const int MAX_PRODUCTOS = 200;

void insertaProd(tListaProd &listaProducto, const tProducto &producto);
void muestra(const tListaProd &listaProducto);
float totalVentas(const tListaProd &listaProducto);
void destruye(tListaProd &listaProducto);

#endif // !ListaProducto_h
