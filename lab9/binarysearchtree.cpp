#include <iostream>
using namespace std;

class bst{
    private:
        struct node{
            int val;
            struct node *left,*right;
        };
    public:
        struct node * root;
        bst(){
            root=NULL;
        }

        node * insert(int,node * root);
        void preorder(node * root);
        void inorder(node * root);
        void postorder(node * root);
        void search(int,node * root);
};

int main(){
    bst b1;
    int loop=0;
    int num;
    while (loop==0){
        int ch;
        cout<<"1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch (ch){
            case 1:
                cout<<"Enter the number:";
                cin>>num;
                b1.root=b1.insert(num,b1.root);
                cout<<"\n";
                break;
            case 2:
                cout<<"\n";
                b1.inorder(b1.root);
                cout<<"\n\n";
                break;
            case 3:
                cout<<"\n";
                b1.preorder(b1.root);
                cout<<"\n\n";
                break;
            case 4:
                cout<<"\n";
                b1.postorder(b1.root);
                cout<<"\n\n";
                break;
            case 5:
                cout<<"Enter the number to be searched:";
                cin>>num;
                b1.search(num,b1.root);
                break;
            case 6:
                loop=1;
                break;
            default:
                cout<<"\nInvalid Entry\n\n";
                break;
        }
    }
}


bst::node* bst::insert(int num,node * root){
    if (root==NULL){
        struct node * newnode=(struct node *) malloc(sizeof(struct node));
        newnode->val=num;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
    if (root->val > num){
        root->left=insert(num,root->left);
    }
    else if (root->val < num){
        root->right=insert(num,root->right);
    }
    return root;
}


void bst::inorder(node * root){
    if (root!=NULL){
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
    else{
        return;
    }
}


void bst::preorder(node * root){
    if (root!=NULL){
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    else{
        return;
    }
}


void bst::postorder(node * root){
    if (root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
    else{
        return;
    }
}


void bst::search(int num,node * root){
    if (root!=NULL){
        search(num,root->left);
        search(num,root->right);
        if (root->val == num){
            cout<<"\nElement Found\n\n";
            return;
        }
    }
    else{
        return;
    }
}