#include "Archivo.h"

void agragardatos(int dato, Node * arbol)
{
	fstream archivoAVL("ArbolAVL.dat", ios::out | ios::app | ios::binary);

	if (!archivoAVL)
	{
		cout << " Error al intentar abrir archivo ArbolAVL.dat";
	}

	Archiv nuevo;

	
	nuevo.left = -1;
	nuevo.data = dato; 
	nuevo.right = -1;

	archivoAVL.write(reinterpret_cast <const char *>(&nuevo), sizeof(Archiv));

	archivoAVL.close();


}


int rigthrot(int dato, Node * arbol)
{
	if (arbol == NULL)
		return -1;

	if (dato == arbol->data)
	{
	
		return (arbol->right == nullptr) ? -1 : arbol->right->data;
	}
	else if (dato > arbol->data)
	{
		return rigthrot(dato, arbol->right);
	}
	else
	{
		return rigthrot(dato, arbol->left);
	}

	return -1;
}

int leftrot(int dato, Node * arbol)
{
	if (arbol == NULL)
		return -1;

	if (dato == arbol->data)
	{
		return (arbol->left == nullptr) ? -1 : arbol->left->data;
		
	}
	else if (dato < arbol->data)
	{
		return leftrot(dato, arbol->left);
	}
	else
	{
		return leftrot(dato, arbol->left);
	}

	return -1;
}
void guardar(Node * root)
{
	fstream archivoModef("ArbolAVL.dat", ios::in | ios::out | ios::binary);
	ifstream archivoIn("ArbolAVL.dat", ios::in | ios::binary);

	if (!archivoModef)
	{
		cout << " Error al intentar abrir archivo ArbolAVL.dat";
		return;
	}


	Archiv actual;

	archivoIn.read(reinterpret_cast <char *>(&actual), sizeof(Archiv));
	int pos = getposRegistro(actual.data);
	archivoIn.seekg(1 * sizeof(Archiv), ios::beg);


	Archiv nuevo;

	archivoModef.seekp(pos * sizeof(Archiv), ios::beg);



	while (!archivoIn.eof()) {


		nuevo.left = getposRegistro(leftrot(actual.data, root));
		nuevo.data = actual.data;
		nuevo.right = getposRegistro(rigthrot(actual.data, root));;



		archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(Archiv));
		archivoModef.write(reinterpret_cast <const char *>(&nuevo), sizeof(Archiv));


	}




	archivoModef.close();



}



int getposRegistro(int codigo) {

	ifstream archivoPos("ArbolAVL.dat", ios::in | ios::binary);

	if (!archivoPos)
	{
		cout << " Error al intentar abrir archivo ArbolAVL.dat";
		return -1;
	}

	archivoPos.seekg(0, ios::beg);
	Archiv nuevo;

	archivoPos.read(reinterpret_cast <char *>(&nuevo), sizeof(Archiv));  
	int posicion = 0;

	while (!archivoPos.eof())
	{

		if (nuevo.data == codigo)
		{


			archivoPos.close();
			return posicion;
		}
		posicion++;
		archivoPos.read(reinterpret_cast <char *>(&nuevo), sizeof(Archiv)); 

	}

	archivoPos.close();
	return -1;



}

void Eliminarenelarchivo(int dato)
{

	fstream archivoModef("ArbolAVL.dat", ios::in | ios::out | ios::binary);
	ifstream archivoIn("ArbolAVL.dat", ios::in | ios::binary);

	if (!archivoModef)
	{
		cout << " Error al intentar abrir archivo ArbolAVL.dat";
		return;
	}


	Archiv actual;

	archivoIn.read(reinterpret_cast <char *>(&actual), sizeof(Archiv));
	int pos = getposRegistro(actual.data);
	archivoIn.seekg(1 * sizeof(Archiv), ios::beg);


	Archiv nuevo;

	archivoModef.seekp(pos * sizeof(Archiv), ios::beg);



	while (!archivoIn.eof()) {


		if (actual.left == getposRegistro(dato))
		{
			nuevo.left = -1;
			nuevo.data = actual.data;
			nuevo.right = actual.right;
		}
		else if (actual.right == getposRegistro(dato))
		{
			nuevo.left = actual.left;
			nuevo.right = -1;
			nuevo.data = actual.data;
		}


		else if (actual.data == dato)
		{
			nuevo.left = -1;
			nuevo.right = -1;
			nuevo.data = -1;
		}

		else
		{

			nuevo.left = actual.left;
			nuevo.data = actual.data;
			nuevo.right = actual.right;
		}




		archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(Archiv));
		archivoModef.write(reinterpret_cast <const char *>(&nuevo), sizeof(Archiv));


	}




	archivoModef.close();



}



void consultarinventario()
{

	ifstream archivoIn("ArbolAVL.dat", ios::in | ios::binary);

	if (!archivoIn)
	{
		cout << " Error al intentar abrir archivo ArbolAVL.dat";
		return;
	}


	archivoIn.seekg(0, ios::beg);


	cout << "\n\n* * * A r c h i v o  B i n a r i o * * *\n\n";

	Archiv actual;

	archivoIn.read(reinterpret_cast <char *>(&actual), sizeof(Archiv));

	while (!archivoIn.eof())
	{

		cout << "|izq: " << actual.left << "\nvalor: " << actual.data
			<< "\nderecha|: " << actual.right;

		cout << endl << endl;

		archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(Archiv));




	}

	archivoIn.close();

}


Node * arbolarchivoamemoria()
{

	ifstream archivoIn("ArbolAVL.dat", ios::in | ios::binary);

	if (!archivoIn)
	{
		cout << " Error al intentar abrir archivo ArbolAVL.dat";
		return NULL;
	}


	archivoIn.seekg(0, ios::beg);




	Archiv actual;
	Node *root = NULL;


	archivoIn.read(reinterpret_cast <char *>(&actual), sizeof(Archiv));

	while (!archivoIn.eof()) 
	{

		if (actual.data == -1)
		{

		}
		else
		{
			root = insert(root, actual.data);
		}




		archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(Archiv));




	}

	archivoIn.close();
	return root;
}



