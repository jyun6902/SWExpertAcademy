#include <cstdio>
#include <iostream>
#include <cstring>

#define D_NUM 26
using namespace std;

struct node
{
	bool is_end;
	int prefix_count;
	struct node* child[D_NUM];
} *head;

extern void init(void)
{
	head = new node();
	head->is_end = false;
	head->prefix_count = 0;
}

extern void insert(int buffer_size, char *buf)
{
	node *current = head;
	current->prefix_count++;

	for (int i = 0; i < buffer_size; i++)
	{
		int letter = (int)buf[i] - (int)'a';
		if (current->child[letter] == NULL)//없는 경우
			current->child[letter] = new node();

		current->child[letter]->prefix_count++;
		current = current->child[letter];
	}
	current->is_end = true;
}

extern int query(int buffer_size, char *buf)//search
{
	node* current = head;
	for (int i = 0; i < buffer_size; i++)
	{
		int letter = (int)buf[i] - (int)'a';
		if (current->child[letter] == NULL)//없는 경우
			return 0;

		current = current->child[letter];
	}

	return current->prefix_count;
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	//setbuf(stdout, NULL);
	int TestCase;

	for (scanf("%d", &TestCase); TestCase--;)
	{
		int Query_N;
		scanf("%d", &Query_N);

		init();

		static int tc = 0;

		printf("#%d", ++tc);
		for (int i = 1; i <= Query_N; i++)
		{
			int type;
			scanf("%d", &type);

			if (type == 1)
			{
				char buf[15] = { 0, };
				scanf("%s", buf);

				int buffer_size = 0;
				while (buf[buffer_size])
					buffer_size++;

				insert(buffer_size, buf);
			}
			else
			{
				char buf[15] = { 0, };
				scanf("%s", buf);

				int buffer_size = 0;
				while (buf[buffer_size])
					buffer_size++;

				printf(" %d", query(buffer_size, buf));
			}
		}
		printf("\n");
	}
}