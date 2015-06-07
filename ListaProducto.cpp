#include "ListaProducto.h"

using namespace std;

void insertaProd(tListaProd &listaProducto, const tProducto &producto){
	if (listaProducto.cont < MAX_PRODUCTOS){
		listaProducto.arrayProductos[listaProducto.cont] = producto;
		listaProducto.cont++;
	}
}

void muestra(const tListaProd &listaProducto){
	for (int i = 0; i < listaProducto.cont; i++){
		muestra(listaProducto.arrayProductos[i]);
	}
}

float totalVentas(const tListaProd &listaProducto){
	float resultado = 0;

	for (int i = 0; i < listaProducto.cont; i++){
		resultado += totalVenta(listaProducto.arrayProductos[i]);
	}

	return resultado;
}

void destruye(tListaProd &listaProducto){
	delete[] listaProducto.arrayProductos;
	listaProducto.arrayProductos = nullptr;
	listaProducto.cont = 0;
}

