#include <iostream>
using namespace std;
#include <stack>

class exp{
    private:
        struct node{
            char val;
            struct node * left,*right; 
        };
    public:
        struct node * root;
        exp(){
            root=NULL;
        }
        node * exptree(string);
        void preorder(node * root);
        void inorder(node * root);
        void postorder(node * root);
};

int main(){
    exp e1;
    int loop=0;
    string s;
    while (loop==0){
        int ch;
        cout<<"1.Expression Tree\n2.Preorder\n3.Inorder\n4.Postorder\n5.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch (ch){
            case 1:
                cout<<"Enter postfix expression:";
                cin>>s;
                e1.root=e1.exptree(s);
                break;
            case 2:
                cout<<"\n";
                e1.preorder(e1.root);
                cout<<"\n\n";
                break;
            case 3:
                cout<<"\n";
                e1.inorder(e1.root);
                cout<<"\n\n";
                break;
            case 4:
                cout<<"\n";
                e1.postorder(e1.root);
                cout<<"\n\n";
                break;
            case 5:
                loop=1;
                break;
            default:
                cout<<"\nInvalid Entry\n\n";
                break;
        }
    }
}


exp::node * exp::exptree(string s){
    stack <node *> s1;
    int len=s.length();
    for (int i=0;i<len;i++){
        struct node *newnode = (struct node *) malloc(sizeof(struct node));
        newnode->val=s[i];
        newnode->left=NULL;
        newnode->right=NULL;
        if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
            newnode->right=(s1.top());
            s1.pop();
            newnode->left=(s1.top());
            s1.pop();
            s1.push(newnode);
        }
        else{
            newnode->left=NULL;
            newnode->right=NULL;            
            s1.push(newnode);
        }
    }
    cout<<"\nExpression tree constructed\n\n";
    return s1.top();
    
}


void exp::inorder(node * root){
    if (root!=NULL){
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
    else{
        return;
    }
}


void exp::postorder(node * root){
    if (root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
    else{
        return;
    }
}


void exp::preorder(node * root){
    if (root!=NULL){
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    else{
        return;
    }
}