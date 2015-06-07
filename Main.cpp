#include "ListaCliente.h"
using namespace std;

int main(){
	tListaClientes listaClientes;

	carga(listaClientes);
	muestra(listaClientes);
	destruye(listaClientes);

	system("pause");

	return 0;
}