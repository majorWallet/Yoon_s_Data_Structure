#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
} Node;

int main()
{
	Node* head = NULL;
	//Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	//Node* prev_node = NULL;
	int readData;

	/*
	while (1)
	{
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		head = newNode;

		if (tail == NULL)
			tail = newNode;
		else
			head->next = prev_node;

		prev_node = newNode;
	}
	*/

	while (1)
	{
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		/*** ����� �߰����� ***/
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
		{
			head = newNode;
			//tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}

	printf("�Է� ���� �������� ��ü���!\n");
	if (head == NULL)
		printf("����� ������ �������� �ʽ��ϴ�.");
	else
	{
		cur = head;
		printf("%d ", cur->data);

		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	
	if (head == NULL)
		return 0;
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d�� �����մϴ�.\n", delNode->data);
		free(delNode);
		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d�� �����մϴ�.\n", delNode->data);
			free(delNode);
		}
	}

	return 0;
}