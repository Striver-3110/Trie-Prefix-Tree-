#include <bits/stdc++.h> 
using namespace std;
// #include <string>

struct Node{
    Node* links[26];
    int ew = 0;
    int cw = 0;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }

    void incrementCw(){
        cw++;
    }
    void incrementEw(){
        ew++;
    }
    void decrementCw(){
        cw--;
    }
    void decrementEw(){
        ew--;
    }
    int getCw(){
        return cw;
    }
    int getEw(){
        return ew;
    }

};


class Trie{

    private:
    
    Node* root;

    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        int len = word.length();
        for(int i = 0; i < len; i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->incrementCw();
        }
        node->incrementEw();
        // node->incrementCnt();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        // int count = 0;
        int len = word.length();
        for(int i = 0; i < len; i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getEw();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        int len = word.length();
        Node* node = root;
        for(int i = 0; i < len; i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getCw();

    }

    void erase(string &word){
        // Write your code here.
        // we are just ignoring to free the memory for simplicity
        int len = word.length();
        Node* node = root;
        for(int i = 0; i < len; i++){
            if(!node->containsKey(word[i])){
                break;
            }
            node = node->get(word[i]);
            node->decrementCw();
        }
        node->decrementEw();
    }
};

int main() {
    Trie* trie = new Trie();

    // Example usage
    string word1 = "apple";
    trie->insert(word1);
    cout << "Count of words equal to 'apple': " << trie->countWordsEqualTo(word1) << endl; // Should print 1
    string prefix1 = word1.substr(0, 3);
    cout << "Count of words starting with 'app': " << trie->countWordsStartingWith(prefix1) << endl; // Should print 1

    string word2 = "app";
    trie->insert(word2);
    cout << "Count of words equal to 'app': " << trie->countWordsEqualTo(word2) << endl; // Should print 1
    cout << "Count of words starting with 'app': " << trie->countWordsStartingWith(word2) << endl; // Should print 2

    trie->erase(word1);
    cout << "Count of words equal to 'apple' after erase: " << trie->countWordsEqualTo(word1) << endl; // Should print 0
    string prefix2 = word1.substr(0, 3);
    cout << "Count of words starting with 'app' after erasing 'apple': " << trie->countWordsStartingWith(prefix2) << endl; // Should print 1

    delete trie;
    return 0;
}