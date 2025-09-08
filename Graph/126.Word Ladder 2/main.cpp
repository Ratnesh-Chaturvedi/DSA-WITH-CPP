// Approach 1 -> 

// we can not calculate the time complexity because it can be very according to the test case 

vector<vector<string>> findSequences(string sw, string tw,
                                         vector<string>& wl) {
        
        unordered_set<string>st(wl.begin(),wl.end());
        queue<vector<string>>q;
        q.push({sw});
        int lvl=0;
        vector<string>usedOnLvl;
        usedOnLvl.push_back(sw);
        vector<vector<string>>ans;
        
        while(!q.empty()){
            vector<string>vec=q.front();
            string word=vec.back();
            q.pop();
            if(vec.size()>lvl){
                lvl++; // that mean we are on another level
                
            // clear all the occurence of the word that are used on that previous  level
            for(auto it:usedOnLvl){
                st.erase(it);
            }
            
            }
            
            usedOnLvl.clear(); // we can store the new word from the current level
            
            // if last word is the target word 
            if(word==tw){
            // if it is the first sequence we have reached 
            if(ans.size()==0) ans.push_back(vec);
            // only push those sequences which are the shortest 
            else if(ans[0].size()==vec.size()) ans.push_back(vec);
            
            }
            
            for(int i=0;i<word.size();i++){
                char org=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)>0){
                        vec.push_back(word) ; // bat pat 
                        q.push(vec);
                        usedOnLvl.push_back(word);
                        vec.pop_back(); // bat  -> so that we can store bat and pat 
                    }
                }
                word[i]=org;
            }
        }
        return ans;
    }



    // Approach that wont give time limit exceeded 