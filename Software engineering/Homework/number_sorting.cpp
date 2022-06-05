/*
    Task: Number Sorting
    Task description: http://olimps.lio.lv/uzdevumi.php?show=471
    Special requirements: Use a binary tree
*/

#include <iostream>
#include <fstream>

using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int newVal)
    {
        value = newVal;
        left = right = NULL;
    }
};

class Stack
{
    struct StackNode
    {
        Node *node;
        StackNode *next;

        StackNode(Node *newNode)
        {
            node = newNode;
            next = NULL;
        }
    };

    StackNode *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(Node *node)
    {
        StackNode *stackNode = new StackNode(node);
        stackNode->next = top;
        top = stackNode;
    }

    void pop(Node *&node)
    {
        if (top)
        {
            node = top->node;
            StackNode *oldTop = top;
            top = top->next;
            delete oldTop;
        }
    }
};

class BinaryTree
{
    Node *root;

public:
    BinaryTree()
    {
        root = NULL;
    }

    void insert(int value)
    {
        if (!root)
        {
            root = new Node(value);
            return;
        }

        Node *currNode = root;

        while (true)
        {
            if (currNode->value > value)
            {
                if (!currNode->left)
                {
                    currNode->left = new Node(value);
                    return;
                }

                currNode = currNode->left;
            }
            else
            {
                if (!currNode->right)
                {
                    currNode->right = new Node(value);
                    return;
                }

                currNode = currNode->right;
            }
        }
    }

    void inOrderPrint(ofstream &writeFile)
    {
        Stack *stack = new Stack();
        Node *currNode = root;

        while (true)
        {
            if (currNode)
            {
                stack->push(currNode);
                currNode = currNode->left;
            }
            else
            {
                stack->pop(currNode);

                if (!currNode)
                {
                    break;
                }

                writeFile << currNode->value << endl;
                currNode = currNode->right;
            }
        }
    }
};

int main()
{
    ifstream readFile("kartosan.dat");
    ofstream writeFile("kartosan.rez");

    int valueAmount;
    readFile >> valueAmount;

    BinaryTree tree = BinaryTree();
    int currentValue;

    while (readFile >> currentValue && valueAmount != 0)
    {
        tree.insert(currentValue);
        valueAmount--;
    }

    readFile.close();

    tree.inOrderPrint(writeFile);
    writeFile.close();
}