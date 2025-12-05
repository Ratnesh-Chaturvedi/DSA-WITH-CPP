struct Node{
    Node*links[2];
    
    bool containKey(int bit){
        return links[bit]!=nullptr;
    }
    void put(int bit,Node*node){
        links[bit]=node;
    }
    Node*get(int bit){
        return links[bit];
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie t;
        int n=queries.size();
        int m=nums.size();
        sort(nums.begin(),nums.end());
        // we can not sort the queries directly it will disrupt the arrangement for answer 
        // we use offline query
        // offline query
        vector<pair<int,pair<int,int>>>oq; // mi,xi,idx;      
        for(int i=0;i<n;i++){
            oq.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(oq.begin(),oq.end());
        vector<int>ans(n,0);
        int index=0; // for inserting the element in trie

        // TC-O(M*32 + N*32)
        for(int i=0;i<n;i++){
            int mi=oq[i].first;
            int xi=oq[i].second.first;
            int idx=oq[i].second.second;
            // insert only those which are not inserted till yet in trie and <=mi
            while(index<m && nums[index]<=mi){
                t.insert(nums[index]);
                index++;
            }
            if(index==0){
                ans[idx]=-1;
            }
            else ans[idx]=t.findMax(xi);
        }
        return ans;
    
    }
};