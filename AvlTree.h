#pragma once
#include<iostream>
using namespace std;
struct Node
{
	int data;
	int height;
	Node *left;
	Node *right;
};


int max(int a, int b);
int heights(Node *temp);
int getbalance(Node *temp);
Node * minValueNode(Node* node);
Node *leftrot(Node *x);
Node *rightrot(Node *y);
Node *insert(Node* node, int key);
void preorder(Node* temp);
void posorden(Node *);
void inorden(Node *);

Node* deleteNode(Node* raiz, int valor);