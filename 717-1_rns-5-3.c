#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct node{
    int value;
    struct node *left;
    struct node *right;
    struct node *prev;
};

struct tree{
    int i;
    struct node *parent;
};

void init(struct tree *t) { t->parent = NULL; }

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
                } if(temp->left ==NULL && temp->value > value){
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

void print(struct node* root,int k) {
    if (root) {
        print(root->left,1);
        print(root->right,1);
        if(k==0) {
            printf("%d", root->value);
        } else {
            printf("%d ", root->value);
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
    print(root.parent,0);
    printf("\n");
    return 0;
}
