#include "ListaCliente.h"

using namespace std;

bool encuentra(const tListaClientes &listaClientes, string nif, const int &ini, const int &fin, int &pos){
	bool encontrado = false;
	int mitad;

	if (ini <= fin){
		mitad = (ini + fin) / 2;
		if (listaClientes.arrayClientes[mitad]->nif == nif){
			encontrado = true;
			pos = mitad;
		}
		else if (listaClientes.arrayClientes[mitad]->nif < nif){
			encontrado = encuentra(listaClientes, nif, mitad + 1, fin, pos);
		}
		else{
			encontrado = encuentra(listaClientes, nif, ini, mitad - 1, pos);
		}
	}
	else {
		pos = ini;
	}

	return encontrado;
}

float totalVentas(const tListaClientes &listaClientes){
	float resultado = 0;

	for (int i = 0; i < listaClientes.cont; i++){
		resultado += totalVentas(listaClientes.arrayClientes[i]->ventas);
	}

	return resultado;
}

void insertaCliente(tListaClientes &listaClientes,  const string &nif, const tProducto &producto, const int pos){
	
	if (listaClientes.cont < MAX_CLIENTES){

		for (int i = listaClientes.cont; i > pos; i--){
			listaClientes.arrayClientes[i] = listaClientes.arrayClientes[i - 1];
		}

		listaClientes.arrayClientes[pos] = new tCliente;
		listaClientes.arrayClientes[pos]->ventas.arrayProductos = new tProducto[MAX_PRODUCTOS];
		listaClientes.arrayClientes[pos]->ventas.cont = 0;

		listaClientes.arrayClientes[pos]->nif = nif;
		insertaProd(listaClientes.arrayClientes[pos]->ventas, producto);
		listaClientes.cont++;

	}
}

bool carga(tListaClientes &listaClientes){
	bool carga = false;
	string nif;
	ifstream archivo;

	archivo.open(TXT);

	if (!archivo.is_open()){
		cout << "error al abrir archivo\n";
	}
	else {
		carga = true;
		listaClientes.cont = 0;

		archivo >> nif;

		tProducto productoAux;
		int pos;

		while (nif != "XXX" && listaClientes.cont < MAX_CLIENTES){
			archivo >> productoAux.codigo;
			archivo >> productoAux.precio;
			archivo >> productoAux.unidades;

			if (encuentra(listaClientes, nif, 0, listaClientes.cont - 1, pos)){
				insertaProd(listaClientes.arrayClientes[pos]->ventas, productoAux);
			}
			else{
				insertaCliente(listaClientes, nif, productoAux, pos);
			}

			archivo >> nif;
		}

		archivo.close();
	}
	return carga;
}

void muestra(const tListaClientes &listaCliente){
	for (int i = 0; i < listaCliente.cont; i++){
		cout << setfill('-') << setw(20) << "-\n";
		cout << "Cliente: " << listaCliente.arrayClientes[i]->nif << endl;
		muestra(listaCliente.arrayClientes[i]->ventas);
	}
	cout << "Total ventas = " << totalVentas(listaCliente) << endl;
}

void destruye(tListaClientes &listaClientes){
	for (int i = 0; i < listaClientes.cont; i++){
		destruye(listaClientes.arrayClientes[i]->ventas);
		delete listaClientes.arrayClientes[i];
		listaClientes.arrayClientes[i] = nullptr;
	}

	listaClientes.cont = 0;
}