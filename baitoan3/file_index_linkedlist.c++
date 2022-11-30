#include<bits/stdc++.h>
using namespace std;

//define node
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
        string value;
        int count;
        NodeCount *begin;
        NodeCount *end;
        indexNode *next;
};

void printList(indexNode *node) 
{ 
    while (node!= NULL) 
    {
        cout << node->value << " " << node->count<<" ";
        while (node->begin!=NULL) {
            cout << node->begin->value<< " ";
            node->begin = node->begin->next;
        }
        cout << endl;
        node = node->next; 
    } 
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
// check a word is meaning or not
bool check(string word, Node *head) {
    for (int i = 0; i < word.length(); i++) {
        word[i] = tolower(word[i]);
    }
    Node *href = head;
    // href = head;
    while (href != NULL) {
        if (href -> value == word) {
            return true;
        }
        href = href -> next;
    }
    return false;
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

// check a word in exist in answer or not
indexNode *checkExist(string word, indexNode *head) {
    indexNode *href = new indexNode();  
    href = head;
    while (href!=NULL) {
        if (checkBalance(href->value, word)) {
            return href;
        }
        href = href -> next;
    }
    return NULL;
}

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


// read file vanban.txt
void readMainFlie(indexNode **headIndex, Node *head) {
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
                        // kiem tra xem tu do co trong danh sach hay chua
                        if (checkExist(word, *headIndex)!=NULL) {
                            checkExist(word, *headIndex)->count++;
                            if (checkExist(word, *headIndex)->end->value != index) {
                                NodeCount *ref = new NodeCount();
                                ref = checkExist(word, *headIndex)->begin;
                                while (ref->next != NULL) {
                                    ref = ref->next;
                                }
                                NodeCount *n = new NodeCount();
                                n->value = index;
                                n->next = NULL;
                                ref->next = n;
                                checkExist(word, *headIndex)->end->value = index;
                            } 
                        }
                        else {
                            indexNode *headIndexRef = new indexNode();
                            headIndexRef = *headIndex;

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
                            n->next = NULL;

                            if (*headIndex == NULL) {
                                *headIndex = n;
                            }
                            else {
                                if (!compare((*headIndex)->value,n->value)) {
                                    n->next = *headIndex;
                                    *headIndex = n;
                                }
                                else {
                                    while (headIndexRef->next != NULL && compare(headIndexRef->next->value, n->value)) {
                                        headIndexRef = headIndexRef->next;
                                    }
                                    n->next = headIndexRef->next;
                                    headIndexRef->next = n;
                                }
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

//main
int main() {
    int choice;
    Node *stopWord = NULL;
    indexNode *head = NULL;
    readStopWord(&stopWord);
    readMainFlie(&head, stopWord);

    cout << "Chon phuong thuc xuat file" << endl;
    cout << "1. Man hinh" << endl;
    cout<<"2. Xuat file" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        printList(head);
        break;
    case 2:        
        cout << "Ket qua da duoc luu vao file Index.txt ";
        freopen("Index.txt", "w", stdout);
        printList(head);
        break;
    default:
        break;
    }
   
}