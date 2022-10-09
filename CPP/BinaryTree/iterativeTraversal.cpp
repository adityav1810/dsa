
#include <iostream>
#include <queue>
#include <stack>
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

void preOrderprintTree(node *t)
{
    stack<node *> st;

    while (t != NULL || !st.empty())
    {
        if (t != NULL)
        {
            // root
            cout << t->data;
            // left
            st.push(t);
            t = t->left;
        }
        else
        {
            // right
            t = st.top();
            st.pop();
            t = t->right;
        }
    }
}
void postOrderprintTree(node *t)
{
  stack<node*> st;
  long int temp;
  while(t!=NULL || !st.empty()){
    if(t!=NULL){
        st.push(t);
        t = t->left;

    }else{
        temp = (int)st.top();
        st.pop();
        if(temp > 0){
            st.push((node*)temp);
            t = ((node*)temp) ->right;

        }else{
            cout<<((node*)temp)->data;
            t = NULL;

        }

    }
  }

}
void inOrderprintTree(node *t)
{
    stack<node *> st;
    while (t != NULL || !st.empty())
    {

        if (t != NULL)
        {
            st.push(t);

            t = t->left;
           
        }
        else
        {
            t = st.top();
            st.pop();
             cout << t->data;
            t = t->right;
        }
    }
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    // root = create(root);
    lvlOrderprintTree(root);
    preOrderprintTree(root);
    cout << endl;
    postOrderprintTree(root);
    cout << endl;
    inOrderprintTree(root);
    cout << endl;

    return 0;
}