
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

void postorderTraverse(node *t)
{
    if (t == NULL)
    {
        return;
    }

    postorderTraverse(t->left);
    postorderTraverse(t->right);
    cout << t->data;
}

int countNodes(node *t)
{
    int x, y;

    if (t == NULL)
    {
        return 0;
    }
    else
    {
        x = countNodes(t->left);
        y = countNodes(t->left);
        if (t->left && t->right)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
}

int heightTree(node *t)
{
    int x = 0, y = 0;
    if (t == 0)
    {
        return 0;
    }
    x = heightTree(t->left);
    y = heightTree(t->right);
    if (x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    // root = create(root);

    postorderTraverse(root);
    cout << endl;
    cout << countNodes(root);
    cout << endl;
    cout << heightTree(root);

    return 0;
}