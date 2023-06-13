#include <iostream>
#include <stack>
using namespace std;

class node
{
public:
    char data;
    node *left, *right;
    node()
    {
        left = right = NULL;
    }
};

node *place_node(string st, int &i)
{
    node *ptr = new node();
    ptr->data = st[i];
    if (ptr->data == '+' || ptr->data == '-' || ptr->data == '*' || ptr->data == '/')
    {
        ptr->left = place_node(st, ++i);
        ptr->right = place_node(st, ++i);
    }
    else
    {
        return ptr;
    }

    return ptr;
}

node *construct_ext(string st)
{
    int i = 0;
    node *root = NULL;
    root = place_node(st, i);
    return root;
}

void infix_exp(node *ptr)
{
    if (ptr == NULL)
        return;
    if (ptr->data == '+' || ptr->data == '-' || ptr->data == '*' || ptr->data == '/')
    {
        cout << '(';
    }
    infix_exp(ptr->left);
    cout << ptr->data;
    infix_exp(ptr->right);
    if (ptr->data == '+' || ptr->data == '-' || ptr->data == '*' || ptr->data == '/')
    {
        cout << ')';
    }
}

void postfix_exp(node *ptr)
{
    node *lsubtree, *rsubtree;
    stack<node *> st1, st2;
    st1.push(ptr);
    while (!st1.empty())
    {
        st2.push(st1.top());
        lsubtree = st1.top()->left;
        rsubtree = st1.top()->right;
        st1.pop();
        if (lsubtree != NULL)
            st1.push(lsubtree);
        if (rsubtree != NULL)
            st1.push(rsubtree);
    }
    while (!st2.empty())
    {
        cout << st2.top()->data;
        st2.pop();
    }
}

void del(node* root) {
	if(root == NULL)
        return;
    del(root->left);
    del(root->right);
    cout <<"Deleting node : " << root->data<<endl;
    free(root);
}

int main()
{
    string exp;
    cout<<"Enter prefix expression: ";
    cin>>exp;
    node *root = construct_ext(exp);
    int choice;
    cout << "Expression Menu\n";
    cout << "1. Infix Expression\n";
    cout << "2. Postfix Expression\n";
    cout<<"3. Delete entire tree\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\nInfix expression: ";
        infix_exp(root);
        break;
    case 2:
        cout << "\nPostfix expression: ";
        postfix_exp(root);
        break;
     case 3:
     	cout<<"\nDeleting tree ...\n";
     	del(root);
     	break;
    default:
        cout << "Invalid choice";
        break;
    }
    cout << "\n\n";
    return 0;
}


/*The overall time complexity of the code is O(N), 
where N is the length of the input string or the number of nodes in the expression tree, depending on the operation.

The overall space complexity of the code is O(N) in the worst case, 
where N is the number of nodes in the expression tree.
*/