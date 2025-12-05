Given a string array nums of length n. A string is called a complete string if every prefix of this string is also present in the array nums.
Find the longest complete string in the array nums.

If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None" (without quotes).

Examples:
Input : nums = [ "n", "ni", "nin", "ninj" , "ninja" , "nil" ]
Output : ninja
Explanation :

The word "ninja" is the longest word which has all its prefixes present in the array.

Input : nums = [ "ninja" , "night" , "nil" ]

Output : None

Explanation :

There is no string that has all its prefix present in array. So we return None.

Constraints:
1 <= n <= 105
1 <= nums[i].length <= 105
1 <= sum(nums[i].length) <= 105
nums[i] consist only of lowercase English characters


struct Node{
    Node*links[26];
    bool flag=false;

    bool containKey(char ch){
        return links[ch-'a']!=nullptr;
    }
    Node*get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node*node){
        links[ch-'a']=node;
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:
    Node*root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string s){
        Node*node=root;
        for(char ch:s){
            if(!node->containKey(ch)){
                node->put(ch,new Node());
            }
                node=node->get(ch);
        }
        node->setEnd();

    }
    bool checkPrefixExist(string s){
        bool fl=false;
        Node *node=root;
        for(char ch:s){
            if(node->containKey(ch)){
                node=node->get(ch);
                if(!node->isEnd()) return false;
            }
            else  return false;
        }
        return true;
    }
};


class Solution {
public:
    string completeString(vector<string>& nums) {
    Trie trie;
    for(auto &s:nums){
        trie.insert(s);
    }
    string longest="";
    for(auto ch:nums){
        if(trie.checkPrefixExist(ch)){
            if(ch.size()>longest.size()){
                longest=ch;
            }
            else if(ch.size()==longest.size() && ch<longest) {
                longest=ch;
            }
        }
    }

    if(longest=="") return "None";
    return longest;
    }
};








