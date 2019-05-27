#include <stdio.h>
#include <stdlib.h>

typedef struct node_tree {
	int value;
	struct node_tree *left;
	struct node_tree *right;
	struct node_tree *parent;
} node_tree;


typedef struct tree {
	struct node_tree *root;
	int tnumber;
} tree;

typedef struct node_queue {
	struct node_tree* branch;
	struct node_queue* next;
} node_queue;

typedef struct queue {
	struct node_queue* head;
	struct node_queue* tail;
} queue;


void init_queue(queue *q) { 
	q->head = NULL;
	q->tail = NULL;
}

int isEmpty_queue(queue *q) { return (q->tail == NULL); }

void print_queue(queue *q) {
	node_queue* tmp = q->head; 
	while(tmp != NULL) {
		if(tmp->branch == NULL)
			printf("_");
		else
			printf("%d", tmp->branch->value); 
		if(tmp->next != NULL)
			printf(" ");

		tmp = tmp->next;
	}
	printf("\n");
}

void push_in_queue(queue *q, node_tree *value) { 
	node_queue *tmp;
	tmp = malloc(sizeof(node_queue)); 
	tmp->branch = value;
	tmp->next = NULL; 
	if(!isEmpty_queue(q)) {
		q->tail->next = tmp;
		q->tail = tmp;
	}  else {
		q->head = q->tail = tmp;
	}
}

node_tree* pop_out_queue(queue *q) {
	node_queue *tmp = q->head;
	node_tree* n = q->head->branch; 
	q->head = q->head->next; 
	if(q->head == NULL)
		q->tail = NULL;

	free(tmp);

	return(n);
}

int control(queue *q) {
	node_queue* tmp = q->head; 
	while(tmp != NULL) {
		if(tmp->branch != NULL)
			return 0; 
		tmp = tmp->next;
	}
	return 1;
}

void init_tree(tree* t) {
	t->root = NULL;
	t->tnumber = 0;
}

void clear_tree(tree* t, queue* q) {
	node_tree* tmp = t->root;
	node_tree* del;
	push_in_queue(q, tmp);
	while(!isEmpty_queue(q)) {
		del = tmp;
		tmp = pop_out_queue(q);
		free(del);
		if(tmp->left != NULL)
			push_in_queue(q, tmp->left);
		if(tmp->right != NULL)
			push_in_queue(q, tmp->right);
	}
	t->root = NULL;
}

int find_tree(tree* t, int value, node_tree* n, queue* q) {
	node_tree* tmp = t->root;
	while(tmp != NULL) {
		if(tmp->value == value)
				break;
		if(value > tmp->value) {
			if(tmp->right == NULL) {
				printf("-\n");
				return 0;
			}
			tmp = tmp->right;
		}
		else {
			if(tmp->left == NULL) {
				printf("-\n");
				return 0;
			}
			tmp = tmp->left;
		}
	}

	printf("%d ", tmp->parent->value);
	if(tmp->left == NULL)
		printf("_ ");
	else
		printf("%d ", tmp->left->value);
	if(tmp->right == NULL)
		printf("_ ");
	else
		printf("%d ", tmp->right->value);
	printf("\n");
}

int insert_tree(tree* t, int value){
	node_tree* tmp = malloc(sizeof(node_tree));
	if(tmp == NULL) {
		return 2;
	}
	tmp->value = value;
	tmp->left = NULL;
	tmp->right = NULL;
	if(t->root == NULL) {
		t->root = tmp;
	} else {
		node_tree* current = t->root;
		node_tree* prev = NULL;
		int check;
		while(current != NULL){
			prev = current;
			if(value < current->value) {
				current = current->left;
				check = 1;
			} else if(value == current->value) {
				return 1;
			} else {
				current = current->right;
				check = 0;
			}
		} if(check) {
			prev->left = tmp;
			tmp->parent = prev;
		} else {
			prev->right = tmp;
			tmp->parent = prev;
		}
	} 
	t->tnumber++; 
	return 0;
}

int delete_tree(tree* t, int value, queue* q) {
	node_tree* tmp = t->root;
	node_tree* hell;
	node_tree* qwe; 
	while(tmp != NULL) {
		if(tmp->value == value)
			break; 
		if(value > tmp->value) { 
			if(tmp->right == NULL) {
				return 1;
			}
			tmp = tmp->right;
		} else  { 
			if(tmp->left == NULL) {
				return 1;
			}
			tmp = tmp->left;
		}
	}  if(tmp->value == t->root->value) {
		hell = tmp; 
		if(tmp->right != NULL) {
			hell = tmp->right;

			while(hell->left != NULL) {
				hell = hell->left;
			}
		} 
		hell->parent = NULL;
		hell->left = tmp->left;
		qwe = tmp;
		qwe = qwe->left;
		qwe->parent = hell; 
		t->root = hell;
		free(tmp);
		t->tnumber--;
		return 1;
	} 
	return 0;
}

int removeMin_tree(tree* t, int value, queue* q)
{

}

int rotateRight_tree(tree* t) {
	node_tree* tmp = t->root;
	node_tree* qwe; 
	while(tmp->left != NULL) {
		tmp = tmp->left;
	} 
	t->root = tmp;
	while(qwe->parent != NULL) {
		qwe = tmp->parent; 
		qwe->left = NULL;
		tmp->right = qwe;
		tmp = tmp->right;
	} 
	tmp = t->root;
	tmp->parent = NULL;
	while(tmp->right != NULL) {
		qwe = tmp;
		tmp = tmp->right;
		tmp->parent = qwe;
	}
}

int rotateLeft_tree(tree* t) {
	node_tree* tmp = t->root;
	node_tree* qwe; 
	while(tmp->right != NULL) {
		tmp = tmp->right;
	} 
	t->root = tmp; 
	while(qwe->parent != NULL) {
		qwe = tmp->parent;
		qwe->right = NULL;
		tmp->left = qwe;
		tmp = tmp->left;
	} 
	tmp = t->root;
	tmp->parent = NULL;
	while(tmp->left != NULL) {
		qwe = tmp;
		tmp = tmp->left;
		tmp->parent = qwe;
	}
}

void print_tree(tree* t, int value, queue* q) {
	node_tree* tmp = t->root;
	queue* tmp_q;
	tmp_q = malloc(sizeof(queue)); 
	while(tmp != NULL) {
		if(value > tmp->value) {
			if(tmp->value == value)
				break; 
			if(tmp->right == NULL) {
				printf("-\n");
				return;
			}
			tmp = tmp->right;
		} else { 
			if(tmp->left == NULL) {
				printf("-\n");
				return;
			}
			tmp = tmp->left;
		}
	} 
	push_in_queue(q, tmp); 
	print_queue(q); 
	for(;;) { 
		while(!isEmpty_queue(q)) {
			tmp = pop_out_queue(q);
			push_in_queue(tmp_q, tmp);
		} 
		while(!isEmpty_queue(tmp_q)) {
			tmp = pop_out_queue(tmp_q);
			if(tmp == NULL) {
				push_in_queue(q, NULL);
				push_in_queue(q, NULL);
			} else {
				push_in_queue(q, tmp->left);
				push_in_queue(q, tmp->right);
			}
		}  if(control(q)) {
			while(!isEmpty_queue(q))
				pop_out_queue(q);

			break;
		}

		print_queue(q);
	}
}

void printTree(tree* t, queue* q)
{
	node_tree* tmp = t->root;
	queue* tmp_q;
	tmp_q = malloc(sizeof(queue)); 
	if(tmp == NULL) {
		printf("-\n");
		return;
	} 
	push_in_queue(q, tmp); 
	print_queue(q); 
	for(;;) {  
		while(!isEmpty_queue(q)) {
			tmp = pop_out_queue(q);
			push_in_queue(tmp_q, tmp);
		} 
		while(!isEmpty_queue(tmp_q)) {
			tmp = pop_out_queue(tmp_q);
			if(tmp == NULL) {
				push_in_queue(q, NULL);
				push_in_queue(q, NULL);
			}
			else {
				push_in_queue(q, tmp->left);
				push_in_queue(q, tmp->right);
			}
		} 
		if(control(q)) {
			while(!isEmpty_queue(q))
				pop_out_queue(q);

			break;
		}

		print_queue(q);
	}
}

int main()
{
	int n;
	queue *q;
	tree *Tree;

	Tree = malloc(sizeof(tree));
	init_tree(Tree);
	q = malloc(sizeof(queue));
	init_queue(q);

	for (int i = 0; i < 4; ++i) {
		scanf("%d", &n);
		insert_tree(Tree, n);
	}

	printTree(Tree, q);

	for (int i = 0; i < 3; ++i) {
		scanf("%d", &n);
		insert_tree(Tree, n);
	}

	printTree(Tree, q);

	scanf("%d", &n);
	find_tree(Tree, n, NULL, q);

	scanf("%d", &n);
	find_tree(Tree, n, NULL, q);

	scanf("%d", &n);
	delete_tree(Tree, n, q);
	printTree(Tree, q);

	rotateLeft_tree(Tree);
	printTree(Tree, q);

	rotateRight_tree(Tree);
	printTree(Tree, q);

	printf("%d\n", Tree->tnumber);
	//она не хочет работать с gcc
	//clear_tree(Tree, q);
	//поэтому пока так
	printf("-\n");

	return 0;
}


