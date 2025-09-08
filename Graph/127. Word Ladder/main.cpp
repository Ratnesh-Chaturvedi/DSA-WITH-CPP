//My approach 
// TC- O(n*n*l) n->number of node or words in wordlist 
// l->comparison 
//Sc- O(n*n)

// My Approach-> treat each word like a number so that we can form the nodes 
class Solution {
public:
    // finding the shortest path in undirected graph
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> distance(n, -1);
        queue<pair<int, int>> q; // node , distance
        q.push({src, 0});
        distance[src] = 0;
        while (!q.empty()) {
            int v = q.front().first;
            int d = q.front().second;
            q.pop();
            for (auto it : adj[v]) {
                if (distance[it] == -1) {
                    distance[it] = d + 1;
                    q.push({it, d + 1});
                }
            }
        }
        return distance;
    }

    int ladderLength(string bw, string ew, vector<string>& wl) {
        bool present = false;
        int pos = -1; // for getting the position of the endword
        for (int i = 0; i < wl.size(); i++) {
            if (wl[i] == ew) {
                present = true;
                pos = i;
                break;
            }
        }
        if (!present) {
            return 0;
        }
        int nofWords =
            wl.size() + 1; // bcoz begin word is not in wl so we add + 1
        vector<vector<int>> adj(nofWords); // assign each word to a number

        for (int i = 0; i < nofWords; i++) {
            string word = (i > 0)? wl[i - 1]: bw; // bcoz we already included the beginWord

            for (int j = 0; j < wl.size(); j++) {
                int diff =
                    0; // to count that only one digit should be different
                for (int k = 0; k < wl[j].size(); k++) {
                    if (wl[j][k] != word[k]) {
                        diff++;
                        if (diff > 1)
                            break;
                    }
                }
                if (diff == 1) {
                    int u = i;     // current node
                    int v = j + 1; // node which is different by one char
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        vector<int> distance = shortestPath(adj, 0);
        int length =
            distance[pos +
                     1]; // because it has beginword so indexing shiftted by 1
        return length == -1 ? 0 : length + 1; // +1 for word count
    }
};





// Optimised 

    int ladderLength(string bw, string ew, vector<string>& wl) {
        unordered_set<string>st(wl.begin(),wl.end()); // we can also use the map 
        queue<pair<string,int>>q; // string , level 
        q.push({bw,1}); // level start from 1 -> each word count as a length

        while(!q.empty()){
            string word=q.front().first;
            int lvl=q.front().second;
            q.pop();
         // check if it is the endword  
         if(word==ew) return lvl;
         
         // now changing each word character one by one
         for(int i=0;i<word.size();i++){
            char original=word[i];   // we take original so we can  change only one letter then replace it again to change the other letter
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(st.find(word)!=st.end()){
                    st.erase(word);  // erase the word so that it will not iterate again 
                    q.push({word,lvl+1}); 
                }
            }
            word[i]=original; // replace the original word 
         }
            
        } 
        return 0;  // if the word not present in the array 
    }
