#ifndef ListaCliente_h
#define ListaCliente_h

#include "ListaProducto.h"
#include <string>
#include <fstream>
#include <iomanip>

const int MAX_CLIENTES = 100;
const std::string TXT = "datos.txt";

typedef struct {
	std::string nif;
	tListaProd ventas;
}tCliente;

typedef struct {
	tCliente *arrayClientes[MAX_CLIENTES];
	int cont;
}tListaClientes;

bool encuentra(const tListaClientes &listaClientes, std::string nif, const int &ini, const int &fin, int &mitad);
float totalVentas(const tListaClientes &listaClientes);
void insertaCliente(tListaClientes &listaClientes, const std::string &nif, const tProducto &producto, const int pos);
bool carga(tListaClientes &listaClientes);
void muestra(const tListaClientes &listaCliente);
void destruye(tListaClientes &listaClientes);

#endif // !ListaCliente_h
