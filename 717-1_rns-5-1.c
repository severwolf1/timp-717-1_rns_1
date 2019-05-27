#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
    struct  node *prev;

};

struct tree {
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

bool print_layer(struct node *root, int n,int j) {
    if(!root) return false;
    if(n==0)
    {
        if(j == 0 )
            printf("%d",root->value);
        else{
            printf(" %d",root->value);
        }
        return root->left || root->right;
    }
    else
    {
        bool l = print_layer(root->left, n-1,1);
        bool r = print_layer(root->right, n-1,1);
        return l || r;
    }
}

void print_layers(struct node *root) {
    int n = 0;
    while(print_layer(root, n,0)) ++n;
}

int main(){
    int number;
    struct  tree root;
    init(&root);
    for(int i=0;i<7;i++){
        scanf("%d",&number);
        insert(&root,number);
    }
    print_layers(root.parent);
    printf("\n");
    return 0;

}
