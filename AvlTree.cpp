
#include "AvlTree.h"


Node *root = NULL;

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int heights(Node *temp)
{
	if (temp == NULL)
		return 0;
	return temp->height;
}
int getbalance(Node *temp)
{
	if (temp == NULL)
		return 0;
	return heights(temp->left) - heights(temp->right);
}
Node *leftrot(Node *x)
{
	Node *y = x->right;
	Node *z = y->left;

	y->left = x;
	x->right = z;

	x->height = max(heights(x->left), heights(x->right)) + 1;
	y->height = max(heights(y->left), heights(y->right)) + 1;

	return y;
}
Node *rightrot(Node *y)
{
	Node *x = y->left;
	Node *z = x->right;

	x->right = y;
	y->left = z;

	x->height = max(heights(x->left), heights(x->right)) + 1;
	y->height = max(heights(y->left), heights(y->right)) + 1;

	return x;
}
Node *insert(Node* node, int key)
{
	Node *temp = new Node;
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	temp->height = 0;
	if (node == NULL)
		node = temp;

	if (node->data > key)
		node->left = insert(node->left, key);
	else if (node->data < key)
		node->right = insert(node->right, key);
	else
		return node;

	node->height = max(heights(node->left), heights(node->right)) + 1;

	
	int balance = getbalance(node);

	if (balance > 1 && node->left->data > key)
		return rightrot(node);
	if (balance < -1 && node->right->data < key)
		return leftrot(node);
	if (balance > 1 && node->left->data < key)
	{
		node->left = leftrot(node->left);
		return rightrot(node);
	}
	if (balance<-1 && node->right->data>key)
	{
		node->right = rightrot(node->right);
		return leftrot(node);
	}
	
	return node;
}
void preorder(Node* temp)
{
	if (temp == NULL)
		return;

	cout << temp->data << "    ";
	preorder(temp->left);
	preorder(temp->right);


}


void posorden(Node *node)
{
	if (node == NULL)
		return;

	posorden(node->left);

	posorden(node->right);

	cout << node->data << " ";
}

void inorden(Node *node){
	if (node == NULL)
		return;

	inorden(node->left);


	cout << node->data << " ";

	inorden(node->right);
}






Node * minValueNode(Node* node)
{
	Node* current = node;


	while (current->left != NULL)
		current = current->left;

	return current;
}

Node * deleteNode(Node * raiz, int valor)
{
	if (raiz == NULL)
		return raiz;


	if (valor < raiz->data)
		raiz->left = deleteNode(raiz->left, valor);


	else if (valor > raiz->data)
		raiz->right = deleteNode(raiz->right, valor);


	else
	{

		if ((raiz->left == NULL) || (raiz->right == NULL))
		{
			Node *temp = raiz->left ? raiz->left : raiz->right;


			if (temp == NULL)
			{
				temp = raiz;
				raiz = NULL;
			}
			else
				*raiz = *temp;

			free(temp);
		}
		else
		{

			Node* temp = minValueNode(raiz->right);


			raiz->data = temp->data;


			raiz->right = deleteNode(raiz->right, temp->data);
		}
	}


	if (raiz == NULL)
		return raiz;


	raiz->height = max(heights(raiz->left), heights(raiz->right));



	int balance = heights(raiz);

	if (balance < -1 && valor < raiz->left->data) {

		return rightrot(raiz);
	}

	if (balance > 1 && valor > raiz->right->data) {

		return leftrot(raiz);
	}

	if (balance < -1 && valor > raiz->left->data)
	{
		raiz->left = leftrot(raiz->left);
		return rightrot(raiz);
	}

	if (balance > 1 && valor < raiz->right->data)
	{
		raiz->right = rightrot(raiz->right);
		return leftrot(raiz);
	}

	return raiz;
}
