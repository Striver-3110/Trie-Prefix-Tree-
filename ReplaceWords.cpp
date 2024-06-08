#include<bits/stdc++.h>
#include <cstddef>
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
    void containsWordThenReplace(string& s){
        int len = s.length();
        Node* node = root;
        for(int i = 0; i < len; i++){
            if(!node->containsKey(s[i])){
                // return false;
                break;
            }
            node = node->get(s[i]);
            if(node->getEw() > 0){
                s = s.substr(0,i+1);
                break;
            }
        }
    }
    // bool checkPrefixes(string& str){
    //     Node* node = root;
    //     int len = str.length();
    //     for(int i = 0; i < len; i++){
    //         // if(!node->containsKey(str[i])){
    //         //     return false;
    //         // }
    //         node = node->get(str[i]);
    //         if(node->getEw() == 0){
            
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // string longestStr(vector<string>& a){
    //     string longest = "";
    //     for(auto& str: a){
    //         if(checkPrefixes(str)){
    //             if(longest.length() < str.length()){
    //                 longest = str;
    //             }else if(longest.length() == str.length()){
    //                 if(longest > str){
    //                     longest = str;
    //                 }
    //             }
    //         }
    //     }
    //     if(longest == "")return "None";
    //     else return longest;
    // }
};


class Solution {
public:
    vector<string> split(string s, char del){
        vector<string> tokens;
        string token;
        stringstream ss(s);
        while(getline(ss,token,del)){
            tokens.push_back(token);
        }
        return tokens;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root = new Trie();
        int n = dictionary.size();
        for(int i = 0; i < n; i++){
            root->insert(dictionary[i]);
        }
        vector<string> sent = split(sentence,' ');
        for(int i = 0; i < sent.size(); i++){
            root->containsWordThenReplace(sent[i]);
        }
        string ans = "";
        for(int i = 0; i < sent.size(); i++){
            ans += sent[i];
            if(i != sent.size()-1){
                ans+=" ";
            }
        }
        return ans;
    }
};
int main() {
    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    
    Solution solution;
    string result = solution.replaceWords(dictionary, sentence);
    
    cout << result << endl; // Output: "the cat was rat by the bat"

    return 0;
}