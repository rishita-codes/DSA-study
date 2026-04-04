#include<iostream>
#include<queue>

using namespace std;

typedef struct node{
    int data;
    struct node *left, *right;
}node;

node* create_node(int data){
    node* p= new node({data, nullptr, nullptr});
    return p;
}

node* insert_node(node* head, int data){
    if(head==nullptr)
        return create_node(data);
    if(data < head->data)
        head->left= insert_node(head->left, data);
    else if(data > head->data)
        head->right= insert_node(head->right, data);
    return head;
}

node* delete_node(node* head, int data){
    if(head==nullptr)
        return head;
    if(data < head->data)
        head->left= delete_node(head->left, data);
    else if(data > head-> data)
        head->right= delete_node(head->right, data);
    else{
        node *t=nullptr;
        if(!head->left && !head->right){
            delete head;
            head= nullptr;
        }
        else if(!head->left && head->right){
            t=head->right;
            delete head;
            head= t;
        }
        else if(!head->right && head->left){
            t=head->left;
            delete head;
            head= t;
        }
        else{
            t=head->right;
            while(t->left)
                t=t->left;
            head->data=t->data;
            head->right= delete_node(head->right, t->data);
        }
    }
    return head;
}

node* search(node* head, int data){
    if(!head)
        return head;
    else if(data < head->data)
        return search(head->left, data);
    else if(data > head->data)
        return search(head->right, data);
    else
        return head;
}

void inorder(node* head){
    if(head){
        inorder(head->left);
        cout<< head->data<< " ";
        inorder(head->right);
    }
}

void preorder(node* head){
    if(head){
        cout<< head->data<< " ";
        preorder(head->left);
        preorder(head->right);
    }
}

void postorder(node* head){
    if(head){
        postorder(head->left);
        postorder(head->right);
        cout<< head->data << " ";
    }
}

void levelorder(node* head){
    if(!head)
        return;
    queue<node*> q;
    node* cur=nullptr;
    q.push(head);
    while(q.size()){
        cur= q.front();
        q.pop();
        cout<< cur->data<< " ";
        if(cur->left)
            q.push(cur->left);
        if(cur->right)
            q.push(cur->right);
    }
    cout<< endl;
}

void free_tree(node* head){
    if(head){
        free_tree(head->left);
        free_tree(head->right);
        delete head;
    }
}

int main(){
    int ch, data;
    node* head=nullptr;
    cout<< "Enter 1-insert 2-delete 3-search 4-inorder 5-preorder 6-postorder 7-levelorder 0-exit\n";
    while(true){
        cin>> ch;
        switch(ch){
            case 1:
                cin>> data;
                head=insert_node(head, data);
                break;
            case 2:
                cin>> data;
                head=delete_node(head, data);
                break;
            case 3:
                cin>> data;
                if(search(head, data))
                    cout<< "present\n";
                else
                    cout<< "not present\n";
                break;
            case 4:
                inorder(head);
                cout<< endl;
                break;
            case 5:
                preorder(head);
                cout<< endl;
                break;
            case 6:
                postorder(head);
                cout<< endl;
                break;
            case 7:
                levelorder(head);
                break;
            case 0:
                free_tree(head);
                exit(0);
            default:
                cout<< "invalid choice";
        }
    }

    return 0;
}
