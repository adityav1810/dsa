
#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    int data;
    cout << "Enter data :";
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "enter data for left node of : " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter data for right node of : " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

node* create(node *root)
{
    node *t = NULL;
    node *p = NULL;
    int x;

    queue<node*> q;
    cout << "Enter data : ";
    cin >> x;
    t = new node(x);
    cout<<t->data;
    q.push(t);

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        cout << "enter data for left node of " << p->data;
        cin >> x;
        if (x != -1)
        {
            t = new node(x);
            p->left = t;
            q.push(t);
        }

        cout << "enter data for right node of " << p->data;
        cin >> x;
        if (x != -1)
        {
            t = new node(x);
            p->right = t;
            q.push(t);
        }
    }
    return root;
}

void lvlOrderprintTree(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // level traversal complete

            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void preOrderprintTree(node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data;

    preOrderprintTree(root->left);
    preOrderprintTree(root->right);
    
}
void postOrderprintTree(node *root){
    if(root == NULL){
        return;
    }
    
    postOrderprintTree(root->left);
    postOrderprintTree(root->right);
    cout<<root->data;
}
void inOrderprintTree(node *root){
    if(root == NULL){
        return;
    }
    
    inOrderprintTree(root->left);
    cout<<root->data;
    inOrderprintTree(root->right);
    
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    // root = create(root);
    lvlOrderprintTree(root);
    preOrderprintTree(root);
    cout<<endl;
    postOrderprintTree(root);
    cout<<endl;
    inOrderprintTree(root);
    cout<<endl;

    return 0;
}