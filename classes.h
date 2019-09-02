
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;
class ClassTree;
class ClassArray;
class ClassList;

class ClassTree {
public:
	void show(Branch *&Tree)
	{

		if (Tree != NULL)
		{
			show(Tree->left);
			printf("%d ", Tree->value);
			show(Tree->right);
		}
	}
	int CalculateTree(Branch *&Tree, int Limit, int result)
	{
		if (Tree != NULL)
		{
			if (Limit < Tree->value)
			{
				result++;
			}
			result = CalculateTree(Tree->left, Limit, result);
			result = CalculateTree(Tree->right, Limit, result);
		}
		return result;
	}
	void add_node(int value, Branch *&MyTree)
	{
		if (NULL == MyTree)
		{
			MyTree = new Branch;
			MyTree->value = value;
			MyTree->left = MyTree->right = NULL;
		}

		if (value < MyTree->value)
		{
			if (MyTree->left != NULL) add_node(value, MyTree->left);
			else
			{
				MyTree->left = new Branch;
				MyTree->left->left = MyTree->left->right = NULL;
				MyTree->left->value = value;
			}
		}

		if (value > MyTree->value)
		{
			if (MyTree->right != NULL) add_node(value, MyTree->right);
			else
			{
				MyTree->right = new Branch;
				MyTree->right->left = MyTree->right->right = NULL;
				MyTree->right->value = value;
			}
		}
	}
};
class ClassArray {
public:

	int* InputArray(int sizeOfArray)
	{
		int *array = (int*)malloc(sizeOfArray * sizeof(int));
		char inputString[256];
		for (int i = 0; i < sizeOfArray; i++)
		{
			cin >> inputString;
			for (int j = 0; j < strlen(inputString); j++)
			{
				if ('0' > inputString[j] || inputString[j] > '9')
				{
					printf("Данные введены некорректно");
					return array;
				}
			}
			array[i] = atoi(inputString);
		}
		return array;
	}
	int CalculateArray(int* array, int limitOfArray, int sizeOfArray)
	{
		int result = 0;
		for (int i = 0; i < sizeOfArray; i++)
		{
			if (array[i] > limitOfArray)
			{
				result++;
			}
		}
		return result;
	}
};
class ClassList {
public:
	struct Node
	{
		int value;
		struct Node *next;
		struct Node *prev;
	};

	struct List
	{
		struct Node* first;
		struct Node* last;
	};


	struct List* create()
	{
		struct List* list = (struct List*)malloc(sizeof(struct List));
		list->first = NULL;
		list->last = NULL;
		return list;
	}

	int insert(struct List* list)
	{
		struct Node* node = (struct Node*)malloc(sizeof(struct Node));
		char inputString[256];
		if (list->first == NULL && list->last == NULL)
		{
			cin >> inputString;
			for (int j = 0; j < strlen(inputString); j++)
			{
				if ('0' > inputString[j] || inputString[j] > '9')
				{
					printf("Данные введены некорректно");
					return 1;
				}
			}
			node->value = atoi(inputString);
			node->next = NULL;
			node->prev = NULL;
			list->first = node;
			list->last = node;
		}
		else {

			cin >> inputString;
			for (int j = 0; j < strlen(inputString); j++)
			{
				if ('0' > inputString[j] || inputString[j] > '9')
				{
					printf("Данные введены некорректно");
					return 1;
				}
			}
			node->value = atoi(inputString);
			node->prev = list->last;
			node->next = NULL;
			list->last = node;
		}
		return 0;
	}
	int ScrollList(int limit, struct List* list)
	{

		if (list == NULL || list->first == NULL)
		{
			return 0;
		}

		Node* curentNode = list->last;
		int result = 0;
		printf("коллекция");
		do {
			printf("%d ", curentNode->value);
			curentNode = curentNode->prev;
		} while (curentNode != list->last && curentNode != NULL);
	}

	int CalculatelList(int limit, struct List* list)
	{
		int result = 0;
		if (list == NULL || list->first == NULL)
		{
			return 0;
		}

		Node* curentNode = list->last;
		printf("коллекция");
		do {
			result++;
			curentNode = curentNode->prev;
		} while (curentNode != list->last && curentNode != NULL);
		return result;
	}
};
