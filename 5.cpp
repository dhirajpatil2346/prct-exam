#include <bits/stdc++.h>
using namespace std;
typedef struct node
{

  char k[20];
  char m[20];
  class node *left;
  class node *right;
} node;

class dict
{
public:
  node *root;
  void create();
  void disp(node *);
  void insert(node *root, node *temp);
  int search(node *, char[]);
  int update(node *, char[]);
  
};

void dict ::create()
{
  node *temp;
  int ch;

  do
  {
    temp = new node;
    cout << "\nEnter Keyword:";
    cin >> temp->k;
    cout << "\nEnter Meaning:";
    cin >> temp->m;

    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
    {
      root = temp;
    }
    else
    {
      insert(root, temp);
    }
    cout << "\nDo u want to add more (y=1/n=0):";
    cin >> ch;
  } while (ch == 1);
}

void dict ::insert(node *root, node *temp)
{
  if (strcmp(temp->k, root->k) < 0)
  {
    if (root->left == NULL)
      root->left = temp;
    else
      insert(root->left, temp);
  }
  else
  {
    if (root->right == NULL)
      root->right = temp;
    else
      insert(root->right, temp);
  }
}

void dict::disp(node *root)
{
  if (root != NULL)
  {
    disp(root->left);
    cout << "\n Key Word :" << root->k;
    cout << "\t Meaning :" << root->m;
    disp(root->right);
  }
}

int dict ::search(node *root, char k[20])
{
  int c = 0;
  while (root != NULL)
  {
    c++;
    if (strcmp(k, root->k) == 0)
    {
      cout << "\nNo of Comparisons:" << c;
      return 1;
    }
    if (strcmp(k, root->k) < 0)
      root = root->left;
    if (strcmp(k, root->k) > 0)
      root = root->right;
  }

  return -1;
}
int dict ::update(node *root, char k[20])
{
  while (root != NULL)
  {
    if (strcmp(k, root->k) == 0)
    {
      cout << "\nEnter New Meaning ofKeyword " << root->k;
      cin >> root->m;
      return 1;
    }
    if (strcmp(k, root->k) < 0)
      root = root->left;
    if (strcmp(k, root->k) > 0)
      root = root->right;
  }
  return -1;
}

int main()
{
  int ch;
  dict d;
  d.root = NULL;

  do
  {
    cout << "\nMenu\n1.Create\n2.Disp\n3.Search\n4.Update\nEnter Ur CH:";
    cin >> ch;

    switch (ch)
    {
    case 1:
      d.create();
      break;
    case 2:
      if (d.root == NULL)
      {
        cout << "\nNo any Keyword";
      }
      else
      {
        d.disp(d.root);
      }
      break;
    case 3:
      if (d.root == NULL)
      {
        cout << "\nDictionary is Empty. First add keywords then try again ";
      }
      else
      {

        cout << "\nEnter Keyword which u want to search:";
        char k[20];
        cin >> k;

        if (d.search(d.root, k) == 1)
          cout << "\nKeyword Found";
        else
          cout << "\nKeyword Not Found";
      }
      break;
    case 4:
      if (d.root == NULL)
      {
        cout << "\nDictionary is Empty. First add keywords then try again ";
      }
      else
      {
        cout << "\nEnter Keyword which meaning  want to update:";
        char k[20];
        cin >> k;
        if (d.update(d.root, k) == 1)
          cout << "\nMeaning Updated";
        else
          cout << "\nMeaning Not Found";
      }
      break;
    }
  }while (ch <= 4);
    return 0;
  }
