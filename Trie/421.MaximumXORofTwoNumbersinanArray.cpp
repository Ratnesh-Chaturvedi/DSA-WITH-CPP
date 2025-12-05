struct Node{
    Node*links[2];

    bool containKey(int bit){
        return links[bit]!=nullptr;
    }
    Node *get(int bit){
        return links[bit];
    }
    void put(int bit,Node*node){
        links[bit]=node;
    }
};

class Trie{
    private:
    Node*root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node*node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int findMax(int num){
        Node*node=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containKey(1-bit)){
                maxi=maxi | (1<<i);
                node=node->get(1-bit);
            }
            else node=node->get(bit);
        }
        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
          Trie t;
          for(int i:nums){
            t.insert(i);
          }      
          int maxi=0;
          for(int i:nums){
            maxi=max(maxi,t.findMax(i));
          }
          return maxi;
    }
};