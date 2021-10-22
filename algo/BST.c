#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

int heightBST(struct node *root){
    if(!root){
        return 0;
    }
    int leftHeight = heightBST(root -> left);
    int rightHeight = heightBST(root -> right);
    return (leftHeight>rightHeight?leftHeight:rightHeight) + 1;
}
void printLevel(struct node *root , int level){

    if(!root){
        return;
    }
    if(level == 1){
        printf("%d ",root -> data);
    }
    else{
        printLevel(root -> left , level - 1);
        printLevel(root -> right , level - 1);
    }
}

void levelOrder(struct node *root){
    for(int i = 0;i < heightBST(root);i++){
        printLevel(root , i);
    }
    printf("\n");
}

void inOrder(struct node *root){
    
    if(!root){
        return;
    }
    inOrder(root -> left);
    printf("%d ",root->data);
    inOrder(root -> right);
}

struct node *createBST(struct node *root, int data){

    if(!root){
        struct node *new = malloc(sizeof(struct node));
        new -> data = data;
        new -> left = NULL;
        new -> right = NULL;
        return new;
    }
    if(data<=root->data){
        root -> left = createBST(root -> left , data);
    }
    else{
        root -> right = createBST(root -> right , data);
    }
    return root;
}
void searchBST(struct node *root,int data){
    if(!root){
        return;
    }
    if(root -> data == data){
        printf("\n%p\n",root);
        return;
    }
    else{
        if(data > root -> data){
            searchBST(root -> right , data);
        }
        else{
            searchBST(root -> left , data);
        }
    }
}



void findSP(struct node *root , struct node *pre , struct node *suc,int key){
    if(!root){
        return;
    }
    if(root -> data == key){
        if(root -> left){
            struct node *temp = root -> left;
            while(temp -> right){
                temp = temp -> right;
            }
            printf("Predecessor of %d is  %d\n",key,temp -> data);
        }
        if(root -> right){
            struct node *temp = root -> right;
            while(temp -> left){
                temp = temp -> left;
            }
            printf("Sucessor of %d is %d\n",key,temp -> data);
        }
        return;
    }
    if(root -> data > key){
        suc = root;
        findSP(root -> left , pre , suc , key);
    }
    else{
        pre = root;
        findSP(root -> right , pre , suc , key);
    }
}

struct node *inorderSuc(struct node *root){
    while(root && root -> left){
        root = root -> left;
    }
    return root;
}
struct node* deleteBST(struct node* root, int key)
{
    
    if (!root)
        return root;
 
    if (key < root -> data)
        root->left = deleteBST(root->left, key);
 
    else if (key > root -> data)
        root->right = deleteBST(root->right, key);
 
    else {
 
        if (root->left==NULL && root->right==NULL)
            return NULL;
       

        else if (root -> left == NULL) {
            struct node* temp = root -> right;
            free(root);
            return temp;
        }
        else if (root -> right == NULL) {
            struct node* temp = root -> left;
            free(root);
            return temp;
        }

        struct node* temp = inorderSuc(root->right);
 
        root -> data = temp -> data;

        root->right = deleteBST(root->right, temp -> data);
    }
    return root;
}
int main(){

    struct node *root = NULL;
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        int data;
        scanf("%d",&data);
        root = createBST(root , data);
    }
    printf("Inorder traversal is \n");

    inOrder(root);

    int find;
    scanf("%d",&find);
    printf("\nMemory Address of %d if found is ",find);
    searchBST(root , find);
    printf("Height is %d\n",heightBST(root));
    int sp;
    scanf("%d",&sp);
    findSP(root , NULL , NULL , sp);
    int delete[2];
    scanf("%d%d",delete,delete + 1);
    printf("%d Deleted\n",delete[0]);
    deleteBST(root , delete[0]);
    levelOrder(root);
    printf("%d Deleted\n",delete[1]);
    deleteBST(root , delete[1]);
    levelOrder(root);
}

/*10
11 66 6 9 40 28 5 88 125 90
40
11
40 88*/