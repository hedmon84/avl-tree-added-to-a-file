


#include "AvlTree.h"
#include "Archivo.h"

#include <iostream>

using namespace std;


int main() {


	Node *root = NULL;


	int op;
	int dat;
	int data;
	int dato3;

	do
	{
		cout << "\n\n*---AVL---* \n\n";
		cout << "\n1. Generar  AVL \n"<<endl;
		cout << "\n2. Borrar Dato Arbol AVL\n"<<endl;
		cout << "\n3. Mostrar Archivo \n"<<endl;
		cout << "\n4. Cargar Archivo\n"<<endl;
		cout << "\n5. imprimir arbol\n"<<endl;
	

		cin >> op;


		switch (op)
		{
		case 1:
			
			cout << "Ingrese cuantos enteros desea ingresar : ";
			cin >> dat;

			for (int i = 0; i < dat; i++)
			{
				cout << "ingrese dato : ";
				cin >> data;
				root = insert(root, data);
				agragardatos(data, root);
			}
			guardar(root);
			break;

		case 2:
			
			cout << "Valor a Eliminar : ";
			cin >> dato3;
			deleteNode(root, dato3);
			Eliminarenelarchivo(dato3);
			break;

		case 3:consultarinventario();

			break;

		case 4:

			root = arbolarchivoamemoria();
			cout << "ESTA Aqui Cargado!" << endl;

			break;
		case 5:
			cout << "\n1 PreOrden :\n";
			preorder(root);
			cout << "\n2 PosOrden :\n";
			posorden(root);
			cout << "\n3 InOrden :\n";
			inorden(root);


			
			
		
			
			
			
			break;
		}



	} while (op != 6);




};