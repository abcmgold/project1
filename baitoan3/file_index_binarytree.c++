#include<bits/stdc++.h>
using namespace std;
ofstream out_file;
//define nodes
class Node {
    public:
        string value;
        Node* next;
};

class NodeCount {
    public:
        int value;
        NodeCount *next;
};

class indexNode {
    public:
        indexNode *left;
        string value;
        int count;
        NodeCount *begin;
        NodeCount *end;
        indexNode *right;
};

// compare 2 string, return true if x < y or false if x > y
bool compare(string x, string y) {
    for (int i = 0; i < x.length(); i++) {
        x[i] = tolower(x[i]);
    }
    for (int i = 0; i < y.length(); i++) {
        y[i] = tolower(y[i]);
    }

    int len1 = x.length();
    int len2 = y.length();
    int _min = min(len1, len2);
    for (int i = 0; i < _min; i++) {
        if ((x[i] -'0') < (y[i] - '0')) return true;
        else if ((x[i] -'0') > (y[i] - '0')) return false;
    }
    if (len1 == _min) return true;
    else if (len2 == _min) return false;
    return true;
}

// insert a node in binary tree
void insert(indexNode*& root, indexNode *n) {
    if (root == NULL) {
        root = n;
    }
    else if (compare(n->value, root->value)) insert(root->left, n);
    else if (compare(root->value, n->value)) insert(root->right, n);
}

// read file stop word into linked list
void readStopWord(Node **head) {
    ifstream input("stopWord.txt");
    
    string line;
    while (!input.eof()) {
        input >> line;
        for (int i = 0; i < line.length(); i++) {
            line[i] = tolower(line[i]);
        }
        Node *href = new Node();
        href = *head;
        Node *n = new Node();
        n->value = line;
        n->next = NULL;
        if (*head == NULL) {
            *head= n;
        }
        else {
            while (href->next != NULL) {
                href = href->next;
            }
            href->next = n;
        }
    }
    input.close();
}

// check if string x is equal to string
bool checkBalance(string x, string y) {
    for (int i = 0; i < x.length(); i++) {
        x[i] = tolower(x[i]);
    }
    for (int i = 0; i < y.length(); i++) {
        y[i] = tolower(y[i]);
    }

    if (x == y)
        return true;
    else
        return false;
}


// check a word is meaning or not
bool check(string word, Node *head) {
    Node *href = head;
    while (href != NULL) {
        if (checkBalance(href -> value,word)) {
            return true;
        }
        href = href -> next;
    }
    return false;
}

// check a word is exist or not by binary search 
indexNode* search( indexNode* root, string value) {
    if (root == NULL || checkBalance(root->value, value))
       return root;

    if (compare(root->value, value)) return search(root->right, value);
 
    return search(root->left, value);
}

// read file and mark index
void readFileIndex(indexNode **root, Node *head) {
    ifstream input( "vanban.txt");
    string word;
    string line;
    int index = 0;
    while (getline(input,line)) {
        index++;
        line += '\n';
        for (auto x : line) {
            if ((int(x)<97 && int(x) > 90) || int(x) > 122|| int(x) <65 ||x == '\n') {
                if (word.length()!=0) {
                    if (check(word, head) || word == "s") {
                        word = "";
                        continue;
                    }
                    else {
                        if (search(*root, word)==NULL) {
                            NodeCount *nodeStart = new NodeCount();
                            nodeStart->value = index;
                            nodeStart->next = NULL;

                            NodeCount *nodeEnd = new NodeCount();
                            nodeEnd->value = index;
                            nodeEnd->next = NULL;

                            indexNode *n = new indexNode();
                            n->value = word;
                            n->count = 1;
                            n->begin = nodeStart;
                            n->end = nodeEnd;
                            n->left = NULL;
                            n->right = NULL;

                            insert(*root, n);
                        }
                        else {
                            search(*root, word)->count++;
                            if (search(*root, word)->end->value != index) {
                                NodeCount *ref = new NodeCount();
                                ref = search(*root, word)->begin;
                                while (ref->next != NULL) {
                                    ref = ref->next;
                                }
                                NodeCount *n = new NodeCount();
                                n->value = index;
                                n->next = NULL;
                                ref->next = n;
                                search(*root, word)->end->value = index;
                            } 
                        }
                    }
                }
            	word = "";
            }
            else {
            	word = word + x;
        	}
        }
    }
    input.close();
}

// output
void Inorder(indexNode* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->value<<" "<<root->count<<" ";
    while (root->begin!=NULL) {
        cout << root->begin->value<< " ";
        root->begin = root->begin->next;
    }
    cout << endl;
    Inorder(root->right);
}

// main
int main() {
    int choice;
    Node *stopWord = NULL;
    indexNode *root = NULL;
    readStopWord(&stopWord);
    readFileIndex(&root, stopWord);
    cout << "Chon phuong thuc xuat file" << endl;
    cout << "1. Man hinh" << endl;
    cout<<"2. Xuat file" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        Inorder(root);
        break;
    case 2:        
        cout << "Ket qua da duoc luu vao file Index.txt ";
        freopen("Index.txt", "w", stdout);
        Inorder(root);
            break;
    default:
        break;
    }
   
}