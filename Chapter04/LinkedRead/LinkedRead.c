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
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	while (1)
	{
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;
	}

	printf("입력 받은 데이터의 전체출력!\n");
	if (head == NULL)
		printf("저장된 정수가 존재하지 않습니다.");
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

		printf("%d을 삭제합니다.\n", delNode->data);
		free(delNode);
		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을 삭제합니다.\n", delNode->data);
			free(delNode);
		}
	}

	return 0;
}