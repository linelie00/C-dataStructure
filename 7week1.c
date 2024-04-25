#include <stdio.h>
#include <stdlib.h>

int node_count[100001];
int parent_node[100001];

typedef struct node
{
	int data;
	struct node* next;
}Node;

Node* node[100001];

void Find(int n)
{
	int i;
	Node* cur;

	cur = node[n];

	for (i = 1; i <= node_count[n]; i++)
	{
		cur = cur->next;
		if (parent_node[cur->data] == 0)
		{
			parent_node[cur->data] = n;
			Find(cur->data);
		}
	}

	return;
}

int main()
{
	
	int i, j, N;
	int x, y;
	Node* cur;
	
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		node[i] = (Node*)malloc(sizeof(Node));
		node[i]->next = NULL;
	}

	for (i = 0; i < N - 1; i++)
	{
		scanf("%d %d", &x, &y);

		node_count[x]++;
		cur = node[x];
		for (j = 0; j < node_count[x] - 1; j++)
		{
			cur = cur->next;
		}
		cur->next = (Node*)malloc(sizeof(Node));
		cur->next->data = y;
		cur->next->next = NULL;

		node_count[y]++;
		cur = node[y];
		for (j = 0; j < node_count[y] - 1; j++)
		{
			cur = cur->next;
		}
		cur->next = (Node*)malloc(sizeof(Node));
		cur->next->data = x;
		cur->next->next = NULL;
	}

	Find(1);

	for (i = 2; i <= N; i++)
	{
		printf("%d > %d\n", i, parent_node[i]);
	}


	return 0;
}