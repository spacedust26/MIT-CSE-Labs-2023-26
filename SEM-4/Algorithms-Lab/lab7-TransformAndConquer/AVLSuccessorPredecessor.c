//To find the successor and predecessor of AVL trees for a given key
//Input - keys to construct AVL tree, key 
//Output - predecessor and successor of the key
//Time complexity - O(log n)

#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int data){
  struct node *newnode = (struct node*) malloc(sizeof(struct node));
  newnode->data = data;
  newnode->left = newnode->right = NULL;
  return newnode;
}

//height function
int maximum(int a, int b){
  return a > b ? a : b;
}
int height(struct node *root){
  if(root == NULL) return -1;
  else return maximum(height(root->left), height(root->right)) + 1;
}

//balance factor
int balanceFactor(struct node *root){
  return height(root->left) - height(root->right);
}

//Left rotate function
struct node *leftRotate(struct node *x){
  struct node *y = x->right;
  struct node *t2 = y->left;
  y->left = x;
  x->right = t2;
  return y;
}

//Right rotate function
struct node *rightRotate(struct node *y){
  struct node *x = y->left;
  struct node *t2 = x->right;
  x->right = y;
  y->left = t2;
  return x;
}

//Insert function
struct node *insert(struct node *root, int key){
  if(root == NULL) return createNode(key);
  if(key < root->data) root->left = insert(root->left, key);
  else if(key > root->data) root->right = insert(root->right, key);
  else{
    printf("Duplicate key");
    return root;
  }
  int bfactor = balanceFactor(root);
  //Left rotation
  if(bfactor > 1 && key < root->left->data){
    return rightRotate(root);
  }
  //Right rotation
  if(bfactor < -1 && key > root->right->data){
    return leftRotate(root);
  }
  //Left right rotation
  if(bfactor > 1 && key > root->left->data){
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  //Right left rotation
  if(bfactor < -1 && key < root->right->data){
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}

//inorder function
void inorder(struct node *root){
  if(root == NULL) return;
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}

// //Successor function
// struct node *minvalue(struct node *root){
//   struct node *temp = root;
//   while(temp->left != NULL) temp = temp->left;
//   return temp;
// }

// struct node *successor(struct node *root, int data){
//   struct node *succ = NULL;
//   struct node *current = root;
//   while(current != NULL){
//     if(data < current->data){
//       succ = current;
//       current = current->left;
//     }
//     else if(data > current->data){
//       current = current->right;
//     }
//     else{
//       if(current->right != NULL) succ = minvalue(current->right);
//       break;
//     }
//   }
//   return succ;
// }

// //Predecessor function
// struct node *maxvalue(struct node *root){
//   struct node *temp = root;
//   while(temp->right != NULL) temp = temp->right;
//   return temp;
// }

// struct node *predecessor(struct node *root, int data){
//   struct node *pred = NULL;
//   struct node *current = root;
//   while(current != NULL){
//     if(data < current->data){
//       current = current->left;
//     }
//     else if(data > current->data){
//       pred = current;
//       current = current->right;
//     }
//     else{
//       if(current->left != NULL) pred = maxvalue(current->left);
//       break;
//     }
//   }
//   return pred;
// }

//To find successor and predecessor
void findsuccpred(struct node *root, int key, int *succ, int *pred){
  if(root == NULL) return;
  if(key == root->data){
    if(root->right != NULL){
      struct node *temp = root->right;
      while(temp->left != NULL){
        temp = temp->left;
      }
      *succ = temp->data;
    }
    if(root->left != NULL){
      struct node *temp = root->left;
      while(temp->right != NULL){
        temp = temp->right;
      }
      *pred = temp->data;
    }
  }
  if(key < root->data){
    *succ = root->data;
    findsuccpred(root->left, key, succ, pred);
  }
  else if(key > root->data){
    *pred = root->data;
    findsuccpred(root->right, key, succ, pred);
  }
}

//Main function
int main(){
  struct node *root = NULL;
  int choice = 1, key;
  do{
    printf("Enter key: ");
    scanf("%d",&key);
    root = insert(root,key);
    printf("1->continue 0->stop: ");
    scanf("%d",&choice);
  }while(choice == 1);
  printf("Inorder traversal: ");
  inorder(root);

  printf("\nEnter key value: ");
  scanf("%d",&key);
  // struct node *pred = predecessor(root,key);
  // printf("\nPredecessor: %d",pred->data);
  // struct node *succ = successor(root,key);
  // printf("\nSuccessor: %d",succ->data);
  int pred = -1;
  int succ = -1;
  findsuccpred(root,key,&succ,&pred);
  printf("\nPredecessor: %d\nSuccessor: %d",pred,succ);
}