#pragma once

#include "AvlTree.h"
#include <fstream>

#include  <iostream>

using namespace std;
struct  Archiv
{
	int left;
	int right;
	unsigned int data;
};



void  agragardatos(int dato, Node * arbol);
void guardar(Node * root);
int leftrot(int dato, Node * arbol);
int rigthrot(int dato, Node * arbol);
int getposRegistro(int codigo);
void Eliminarenelarchivo(int dato);
void consultarinventario();
Node * arbolarchivoamemoria();