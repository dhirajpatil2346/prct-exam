#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    long long value;
    node *next;
} * HashTable[10];

class hashing
{
public:
    hashing()
    {
        for (int i = 0; i < 10; i++)
        {
            HashTable[i] = NULL;
        }
    }
    int Hashfunction(int val)
    {
        return (val % 10);
    }

    node *create(int x)
    {
        node *temp = new node;
        temp->next = NULL;
        temp->value = x;
        return temp;
    }

    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            node *temp = new node;
            temp = HashTable[i];
            cout << "a[" << i << "] : ";
            while (temp != NULL)
            {
                cout << "-->" << temp->value;
                temp = temp->next;
            }
            cout << "\n";
        }
    }
    int searchElement(int value)
    {
        bool flag = false;
        int hash_val = Hashfunction(value);
        node *entry = HashTable[hash_val];
        cout << "Element found at : ";
        while (entry != NULL)
        {
            if (entry->value = value)
            {
                cout << hash_val << " : " << entry->value << endl;
                flag = true;
            }
            entry = entry->next;
        }

        if (!flag)
            return -1;

        return 0;
    }

    void deleteElement(int value)
    {
        int hash_val = Hashfunction(value);
        node *entry = HashTable[hash_val];
        if (entry == NULL)
        {
            cout << "NO ELEMENT FOUND !!!";
            return;
        }
        if (entry->value == value)
        {
            HashTable[hash_val] = entry->next;
            return;
        }
        while ((entry->next)->value != value)
        {
            entry = entry->next;
        }
        (entry->next) = (entry->next)->next;
    }

    void insertElement(int value)
    {
        int hash_val = Hashfunction(value);
        node *temp = new node;
        node *head = new node;
        head = create(value);
        temp = HashTable[hash_val];
        if (temp == NULL)
        {
            HashTable[hash_val] = head;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = head;
        }
    }
};

int main()
{
    int ch, data, search, del;
    hashing h;
    do
    {
        cout << "\nTelephone : \n1.Insert \n2.Display \n3.Search \n4.Delete \n5.Exit \n";
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\n Enter phonr no to be inserted : ";
            cin >> data;
            h.insertElement(data);
            break;

        case 2:
            h.display();
            break;

        case 3:
            cout << "\nEnter the no to be search : ";
            cin >> search;
            if (h.searchElement(search) == -1)
            {
                cout << "No Element found at key ";
                continue;
            }
            break;

        case 4:
            cout << "\nEnter the phone to be deleted : ";
            cin >> del;
            h.deleteElement(del);
            cout << "Phone Number deleted ??";
            break;
        }
    } while (ch != 5);
}