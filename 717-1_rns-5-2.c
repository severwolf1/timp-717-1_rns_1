#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int value;
    struct node *left;
    struct node *right;
    struct  node *prev;

};

struct tree{
    int i;
    struct node *parent;
};

void init(struct tree *t) {
    t->parent = NULL;
}

int insert(struct tree *t, int value){
    struct node *temp;
    struct node* tree_new = (struct node *) malloc(sizeof(struct node));
    tree_new->value=value;
    tree_new->left =NULL;
    tree_new->right = NULL;
    if(t->parent ==NULL){
        tree_new->prev =NULL;
        t->parent = tree_new;
        t->i=1;
        return 0;
    }else {
        temp  = t->parent;
        while (3) {
            if (temp->value == value) return 1;
            if (temp->right == NULL  && temp->left == NULL) {
                if (temp->value > value) {
                    temp->left = tree_new;
                    temp->left->prev = temp;
                    t->i++;
                    return 0;
                } if(temp->value < value){
                    temp->right = tree_new;
                    temp->right->prev = temp;
                    t->i++;
                    return 0;
                }
            } else {
                if(temp->right ==NULL && temp->value < value){
                    temp->right = tree_new;
                    temp->right->prev = temp;
                    t->i++;
                    return 0;
                }if(temp->left ==NULL && temp->value > value){
                    temp->left = tree_new;
                    temp->left->prev = temp;
                    t->i++;
                    return 0;
                }
            } if (temp->value > value) {
                temp = temp->left;
                continue;
            } if (temp->value < value) {
                temp = temp->right;
                continue;
            }
        }
    }
    return 0;
}

void print(struct node *root) {
    int *a,*h;
    int b=0;
    struct node *p;
    struct node *n;
    a = (int *) malloc(4* sizeof(int));
    h = (int *) malloc(3* sizeof(int));
    if(root) {
        a[b] = root->value;
        p = root->left;
        n = root->left;
        while(n){
            if(p){
                a[b] =p->value;
                p = p->left;
                b++;
            }else{
                p = n->right;
                n=p;
            }
        }
        p=root->right;
        n = root->right;
        b=0;
        while (n){
            if(p){
                h[b] =p->value;
                p = p->left;
                b++;
            }else{
                p = n->right;
                n =p;
            }

        }
        printf("%d",root->value);
        for(int j =0;j<3;j++){
            printf(" %d",a[j]);
        } 
	for(int j=0;j<3;j++){
            printf(" %d",h[j]);
        }
    }
}

int main(){
    int number;
    struct  tree root;
    init(&root);
    for(int i=0;i<7;i++){
        scanf("%d",&number);
        insert(&root,number);
    }
    print(root.parent);
    printf("\n");

    return 0;

}
