#include <iostream>
#include <fstream>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode (int d) 
    {
        this->data = d;
        left = right = NULL;
    }
};

struct Data
{
    int x;
    int y;
    int z;
};

struct Node 
{
    Data val;
    Node* next;
};

TreeNode* findNode(TreeNode* root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == data) 
    {
        return root;
    }

    TreeNode* left = findNode(root->left, data);

    if (left != NULL)
    {
        return left;
    }

    TreeNode* right = findNode(root->right, data);

    return right;
}

void printNodesOnLevel(fstream& fout, TreeNode* root, int level)
{
    if (root == NULL || level < 0)
    {
        return;
    }

    if (level == 0)
    {
        fout << " " << root->data;
        return;
    }

    printNodesOnLevel(fout, root->left, level - 1);
    printNodesOnLevel(fout, root->right, level - 1);
}

int findTreeDepth(TreeNode* n)
{
    if (n == NULL) 
    {
        return 0;
    }
    else
    {
        int lDepth = findTreeDepth(n->left);
        int rDepth = findTreeDepth(n->right);

        if (lDepth > rDepth) 
        {
            return (lDepth + 1);
        }
        else 
        {
            return (rDepth + 1);
        }
    }
}

void deleteTree(TreeNode* node)
{
    if (node == NULL) 
    {
        return;
    }

    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fstream fin("team.in", ios::in);

    int currVal;

    Node* head = NULL;
    Node* currNode = NULL;
    Node* n;

    while (fin.peek() != EOF)
    {
        n = new Node();
        n->next = NULL;

        fin >> currVal;
        n->val.x = currVal;

        fin >> currVal;
        n->val.y = currVal;

        fin >> currVal;
        n->val.z = currVal;

        if (head == NULL)
        {
            head = currNode = n;
        }
        else
        {
            currNode->next = n;
            currNode = n;
        }
    }

    fin.close();

    TreeNode* root = NULL;
    TreeNode* curr;

    if (head != NULL)
    {
        currNode = head;

        while (currNode != NULL)
        {
            n = head;
            bool found = false;

            while (n != NULL)
            {
                if (n != currNode)
                {
                    if (currNode->val.x == n->val.z || currNode->val.x == n->val.y)
                    {
                        found = true;
                        break;
                    }
                }

                n = n->next;
            }

            if (!found)
            {
                Data temp = currNode->val;
                currNode->val = head->val;
                head->val = temp;
                break;
            }

            currNode = currNode->next;
        }

        currNode = head;
        Node* inputNode = head->next;

        while (currNode != NULL)
        {
            Node* femaleNode = NULL;
            Node* maleNode = NULL;

            if (currNode->val.y == 0) { femaleNode = currNode; }
            if (currNode->val.z == 0) { maleNode = currNode; }

            n = currNode->next;

            while (femaleNode == NULL || maleNode == NULL)
            {
                if (femaleNode == NULL)
                {
                    if (n->val.x == currNode->val.y)
                    {
                        femaleNode = n;
                    }
                }

                if (maleNode == NULL)
                {
                    if (n->val.x == currNode->val.z)
                    {
                        maleNode = n;
                    }
                }

                n = n->next;
            }

            if (currNode->val.x == 0)
            {
                break;
            }

            Data temp;
            int changePos = 0;

            currVal = currNode->val.x;
            curr = findNode(root, currVal);

            if (curr == NULL)
            {
                root = new TreeNode(currVal);
                curr = root;
            }    

            if (femaleNode != currNode)
            {
                if (inputNode == maleNode)
                {
                    temp = inputNode->next->val;
                    inputNode->next->val = maleNode->val;
                    maleNode->val = temp;

                    curr->right = new TreeNode(currNode->val.z);

                    changePos++;

                    maleNode = currNode;
                }

                temp = inputNode->val;
                inputNode->val = femaleNode->val;
                femaleNode->val = temp;

                curr->left = new TreeNode(currNode->val.y);

                changePos++;
            }

            if (maleNode != currNode)
            {
                if (femaleNode == currNode)
                {
                    temp = inputNode->val;
                    inputNode->val = maleNode->val;
                    maleNode->val = temp;
                }
                else 
                {
                    temp = inputNode->next->val;
                    inputNode->next->val = maleNode->val;
                    maleNode->val = temp;
                }

                curr->right = new TreeNode(currNode->val.z);

                changePos++;
            }

            for (int x = 0; x < changePos; x++)
            {
                inputNode = inputNode->next;
            }

            currNode = currNode->next;
        }
    }

    while (head != NULL)
    {
        n = head;
        head = head->next;
        delete n;
    }

    fstream fout("team.out", ios::out);

    for (int x = findTreeDepth(root) - 1; x != -1; x--)
    {
        fout << x << ":";
        printNodesOnLevel(fout, root, x);
        fout << '\n';
    }

    fout.close();

    deleteTree(root);
}