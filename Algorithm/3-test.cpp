#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define CHAR 26

struct Node {
    Node *children[CHAR];
    Node *fail;
    bool output;
};

Node* createNode() {
    Node* node = new Node;
    for(int i = 0; i < CHAR; i++) node->children[i] = NULL;
    node->fail = NULL;
    node->output = false;
    return node;
}

void insert(Node *root, char *pattern) {
    Node *p = root;
    for(int i = 0; pattern[i]; i++) {
        int index = pattern[i]-'a';
        if(!p->children[index])
            p->children[index] = createNode();
        p = p->children[index];
    }
    p->output = true;
}

void buildFailure(Node *root) {
    queue<Node*> q;
    root->fail = root;
    for(int i = 0; i < CHAR; i++) {
        if(root->children[i]) {
            root->children[i]->fail = root;
            q.push(root->children[i]);
        }
    }

    while(!q.empty()) {
        Node* curr = q.front(); q.pop();
        for(int i = 0; i < CHAR; i++) {
            if(curr->children[i]) {
                Node* f = curr->fail;
                while(f != root && !f->children[i])
                    f = f->fail;
                if(f->children[i])
                    f = f->children[i];
                curr->children[i]->fail = f;
                q.push(curr->children[i]);
            }
        }
    }
}

void search(Node *root, char *text) {
    Node *p = root;
    for(int i = 0; text[i]; i++) {
        int index = text[i]-'a';
        while(p != root && !p->children[index])
            p = p->fail;
        if(p->children[index])
            p = p->children[index];

        Node *temp = p;
        while(temp != root) {
            if(temp->output)
                cout << "Pattern found ending at index " << i << endl;
            temp = temp->fail;
        }
    }
}

int main() {
    // Program name
    cout << "Program Name: Aho-Corasick Multiple Pattern Matching Algorithm" << endl;

    Node* root = createNode();

    int n;
    cout << "Enter number of patterns: ";
    cin >> n;
    char patterns[10][50]; // Up to 10 patterns

    for(int i = 0; i < n; i++) {
        cout << "Enter pattern " << i+1 << ": ";
        cin >> patterns[i];
        insert(root, patterns[i]);
    }

    buildFailure(root);

    char text[200];
    cout << "Enter text: ";
    cin >> text;

    search(root, text);
    return 0;
}