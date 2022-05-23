#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *root;
    string word, meaning;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;
    TreeNode(string w1, string w2)
    {
        word = w1;
        meaning = w2;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int getHeight(struct TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    return root->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBf(struct TreeNode *root)
{
    return (getHeight(root->left) - getHeight(root->right));
}

struct TreeNode *rightRotate(struct TreeNode *x)
{
    struct TreeNode *y = x->left;
    struct TreeNode *T = y->right;

    y->right = x;
    x->left = T;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

struct TreeNode *leftRotate(struct TreeNode *x)
{
    struct TreeNode *y = x->right;
    struct TreeNode *T = y->left;

    y->left = x;
    x->right = T;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

struct TreeNode *insert(struct TreeNode *root, string w1, string w2)
{
    if (!root)
    {
        root = new TreeNode(w1, w2);
        return root;
    }

    if (w1 < root->word)
    {
        root->left = insert(root->left, w1, w2);
    }
    else if (w1 > root->word)
    {
        root->right = insert(root->right, w1, w2);
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBf(root);

    // left left
    if (bf > 1 && w1 < root->left->word)
    {
        return rightRotate(root);
    }

    // right right
    if (bf < -1 && w1 > root->right->word)
    {
        return leftRotate(root);
    }
    // left right
    if (bf > 1 && w1 > root->left->word)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // right left
    if (bf < -1 && w1 < root->right->word)
    {
        root->right = leftRotate(root->right);
        return rightRotate(root);
    }
    return root;
}

struct TreeNode *ipreceder(struct TreeNode *root)
{
    root = root->left;
    while (root->right)
    {
        root = root->right;
    }
    return root;
}

struct TreeNode *deletion(struct TreeNode *root, string w1)
{
    struct TreeNode *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->word == w1 && root->left == NULL && root->right == NULL)
    {
        return NULL;
    }
    else if (w1 < root->word)
    {
        root->left = deletion(root->left, w1);
    }
    else if (w1 > root->word)
    {
        root->right = deletion(root->right, w1);
    }
    else
    {
        ipre = ipreceder(root);
        root->word = ipre->word, root->meaning = ipre->meaning;
        root->left = deletion(root->left, ipre->word);
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBf(root);

    // left left
    if (bf > 1 && w1 < root->left->word)
    {
        return rightRotate(root);
    }

    // right right
    if (bf < -1 && w1 > root->right->word)
    {
        return leftRotate(root);
    }
    // left right
    if (bf > 1 && w1 > root->left->word)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // right left
    if (bf < -1 && w1 < root->right->word)
    {
        root->right = leftRotate(root->right);
        return rightRotate(root);
    }
    return root;
}

void ascendingInorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        ascendingInorder(root->left);
        cout << root->word << " " << root->meaning << " "<< endl;
        ascendingInorder(root->right);
    }
}

int main()
{
    int ch;
    string key, meaning, dele;
    // TreeNode b;
    TreeNode *root = NULL;
    do
    {
        cout << "\t\t****\tMenu\t****\t\t" << endl
             << "1. Insert" << endl
             << "2. Display Dictionary in ascending order " << endl
             << "3. To delete" << endl
             << "4. To exit" << endl;

        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the key : ";
            cin >> key;
            cout << "Enter the meaning : ";
            cin >> meaning;
            root = insert(root, key, meaning);
            cout << endl;
            break;

        case 2:
            ascendingInorder(root);
            cout << endl;
            break;

        case 3:
            cout << "Enter the word to delete : ";
            cin >> dele;
            root = deletion(root, dele);
        }
    } while (ch < 4);

    return 0;
}