#include <bits/stdc++.h> 
using namespace std;

struct Node{
    Node* links[26];
    int cw = 0;
    int ew = 0;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void put(char ch,Node* node){
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
    int getEw(){
        return ew;
    }
    int getCw(){
        return cw;
    }
};

class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string s){
        int len = s.length();
        Node * node = root;
        for(int i = 0; i < len; i++){
          if (!node->containsKey(s[i])) {
            node->put(s[i], new Node());
          }
          node = node->get(s[i]);
          node->incrementCw();
        }
        node->incrementEw();
    }
    bool checkPrefixes(string& str){
        Node* node = root;
        int len = str.length();
        for(int i = 0; i < len; i++){
            // if(!node->containsKey(str[i])){
            //     return false;
            // }
            node = node->get(str[i]);
            if(node->getEw() == 0){
                return false;
            }
        }
        return true;
    }
    string longestStr(vector<string>& a){
        string longest = "";
        for(auto& str: a){
            if(checkPrefixes(str)){
                if(longest.length() < str.length()){
                    longest = str;
                }else if(longest.length() == str.length()){
                    if(longest > str){
                        longest = str;
                    }
                }
            }
        }
        if(longest == "")return "None";
        else return longest;
    }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie* root = new Trie();
    for(int i = 0; i < n; i++){
        root->insert(a[i]);
    }
    return root->longestStr(a);

}


int main() {
    vector<string> words = {"apple", "app", "apricot", "bat", "ball", "ap", "a","b","ba","bal"};
    int n = words.size();
    cout << completeString(n, words) << endl; // Example usage
    return 0;
}