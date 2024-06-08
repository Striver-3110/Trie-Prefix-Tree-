#include <bits/stdc++.h>
using namespace std;

auto __init__ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return nullptr;
}();

struct Node {
    Node* links[26];
    bool flg = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flg = true;
    }

    bool isEnd() {
        return flg;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        int len = word.length();
        for (int i = 0; i < len; i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        int len = word.length();
        for (int i = 0; i < len; i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        int len = prefix.length();
        for (int i = 0; i < len; i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main() {
    Trie* obj = new Trie();
    
    // Example usage
    obj->insert("hello");
    cout << (obj->search("hello") ? "Found" : "Not Found") << endl; // Should print "Found"
    cout << (obj->search("hell") ? "Found" : "Not Found") << endl;  // Should print "Not Found"
    cout << (obj->startsWith("hell") ? "True" : "False") << endl;   // Should print "True"
    cout << (obj->startsWith("helloa") ? "True" : "False") << endl; // Should print "False"
    cout << (obj->search("hell") ? "Found" : "Not Found") << endl;  // Should print "Not Found"

    delete obj;
    return 0;
}
