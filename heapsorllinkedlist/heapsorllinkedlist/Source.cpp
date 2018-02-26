#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define GETBIT(num,pos) (num >> pos & 1)

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node node;

int nodes;
node *first, *tmp, *current;

void addNode(node *, node *, int);
void swap(int *, int *);
void getRoot(node *, int);
void heapSort(node *);

int main(int argc, char *argv[])
{
	int num;
	int i, j;
	char c = 'y';

	while (1)
	{
		printf("Nhap so muon them: ");
		cin>>num;
		fflush(stdin);

		current = (node *)malloc(sizeof(node));
		//if(current ==  0)
		//return 0;

		current->data = num;
		nodes++;

		for (i = nodes, j = -1; i; i >>= 1, j++);

		if (first == 0)
		{
			first = current;
			first->left = 0;
			first->right = 0;
		}
		else
			addNode(first, first, j - 1);

		printf("ban co muon them nua k? nhap: y de them --- n de ket thuc:");
		cin>>c;
		if (c == 'n')
			break;
	}
	printf("So nodes co trong day la: %d\n", nodes);

	while (nodes)
	{
		printf(" %d -> ", first->data);//prints the largest number in the heap

		for (i = nodes, j = -1; i; i >>= 1, j++);//Updating the height of the tree
		getRoot(first, j - 1);
		nodes--;

		heapSort(first);
	}
}

void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void addNode(node *tmp1, node *parent, int pos)
{
	int dirxn = GETBIT(nodes, pos);     // 0 - go left, 1 - go right

	if (!pos)
	{
		if (dirxn)
			tmp1->right = current;
		else
			tmp1->left = current;

		current->left = 0;
		current->right = 0;

		if (current->data > tmp1->data)
			swap(&current->data, &tmp1->data);
	}

	else
	if (dirxn)
		addNode(tmp1->right, tmp1, pos - 1);
	else
		addNode(tmp1->left, tmp1, pos - 1);

	if (tmp1->data > parent->data)
		swap(&parent->data, &tmp1->data);
}

void getRoot(node *tmp, int pos)
{
	int dirxn;

	if (nodes == 1)
		return;

	while (pos)
	{
		dirxn = GETBIT(nodes, pos);

		if (dirxn)
			tmp = tmp->right;
		else
			tmp = tmp->left;
		pos--;
	}

	dirxn = GETBIT(nodes, pos);

	if (dirxn)
	{
		first->data = tmp->right->data;
		free(tmp->right);
		tmp->right = 0;
	}
	else
	{
		first->data = tmp->left->data;
		free(tmp->left);
		tmp->left = 0;
	}
}

void heapSort(node *tmp)
{
	if (!tmp->right && !tmp->left)
		return;

	if (!tmp->right)
	{
		if (tmp->left->data > tmp->data)
			swap(&tmp->left->data, &tmp->data);
	}
	else
	{
		if (tmp->right->data > tmp->left->data)
		{
			if (tmp->right->data > tmp->data)
			{
				swap(&tmp->right->data, &tmp->data);
				heapSort(tmp->right);
			}
		}
		else
		{
			if (tmp->left->data > tmp->data)
			{
				swap(&tmp->left->data, &tmp->data);
				heapSort(tmp->left);
			}
		}
	}
}