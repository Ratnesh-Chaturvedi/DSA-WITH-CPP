// 901. Online Stock Span
            //brute force 
            // TC-O(No. of days)
            //Sc-O(total number of calls)
             class StockSpanner {
                public:
                vector<int>arr;   
                    StockSpanner() {  
                    }
                    
                    int next(int price) {
                        int cnt=1;
                        if(arr.size()==0){
                            arr.push_back(price);
                            return cnt;
                        }
                        else {
                             
                              for(int i=arr.size()-1;i>=0;i--){
                                if(arr[i]<=price) cnt++;
                                else break;
                              }
                 arr.push_back(price);
                        }
                        return cnt; 
                    }
                    
                };

                // optimised
                class StockSpanner {
                    public:
                    stack<pair<int,int>>st;
                    int idx=-1;
                        StockSpanner() {
                            idx=-1;
                            while(!st.empty()) st.pop();
                        }
                        
                        int next(int price) {
                            idx=idx+1;
                            while(!st.empty() && st.top().first<=price){
                                st.pop();
                            }
                            int ans=idx-(st.empty()?-1:st.top().second);
                            st.push({price,idx});
                            return ans;
                        }
                    };




                    // 239. Sliding Window Maximum
 vector<int> maxSlidingWindow(vector<int>& arr, int k) {
                        // brute this gives tle;
                        int n=arr.size();
                        if(k==1) return arr;
                    //     vector<int>ans;
                    //    for(int i=0;i<=n-k;i++){
                    //     int maxi=arr[i];
                    //     for(int j=i;j<i+k;j++){
                    //         maxi=max(maxi,arr[j]);
                    //     }
                    //     ans.push_back(maxi);
                    //    }
                    //     return ans;
                

        //  better soltuion 
        
        map<pair<int,int>,int>hash;
        int n=nums.size();
        vector<int>ans(n-k+1);
        for(int i=0;i<k;i++){
            hash[{nums[i],i}]=1;
        }
        int index=0;
        ans[index++]=hash.rbegin()->first.first;
        for(int i=k;i<n;i++){
            int last=i-k;
            int el=nums[last];
           hash.erase({el,last});
            int newel=nums[i];
            hash[{newel,i}]=1;
            ans[index++]=hash.rbegin()->first.first; 
        }
       
        return ans;
    


                        // using deque;
                           deque<int>dq; // it stores the indexes
                           vector<int>ans;
                           for(int i=0;i<n;i++){
                            if(!dq.empty() && dq.front()<=i-k){
                                dq.pop_front();
                            }
                            //for maintaining the monotonic increasing order
                            while(!dq.empty() && arr[dq.back()] <arr[i] ) 
                            dq.pop_back();
                            dq.push_back(i);
                           if(i>=k-1) ans.push_back(arr[dq.front()]);
                           }
                           return ans;
                    }

                    // The Celebrity Problem

                    //Brute Force
                    int celebrity(vector<vector<int> >& mat) {
                        int n=mat.size();
                        if(n==1) return 0;
                      vector<int>knowMe(n,0),iKnow(n,0);
                      for(int i=0;i<n;i++){
                          for(int j=0;j<n;j++){
                              if(mat[i][j]==1 && i!=j){
                                  knowMe[j]++;
                                  iKnow[i]++;
                              }
                          }
                      }
                      for(int i=0;i<n;i++){
                          if(knowMe[i]==(n-1) && (iKnow[i]==0) ) return i;
                      }
                      return -1;
                      
                    }


                    // using stack
                    int n = mat.size();
    stack<int> st;

    // push everybody in stack
    for (int i = 0; i < n; i++)
        st.push(i);

    // find a potential celebrity
    while (st.size() > 1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        // if a knows b -> a cannot be celebrity
        if (mat[a][b] == 1) {
            st.push(b);
        } else {
            // if a doesn't know b -> b cannot be celebrity
            st.push(a);
        }
    }

    int c = st.top();  // candidate
    st.pop();

    // verify candidate
    for (int i = 0; i < n; i++) {
        if (i == c) continue;
        // if candidate knows anyone
        // or anyone doesn't know candidate
        if (mat[c][i] == 1 || mat[i][c] == 0)
            return -1;
    }

    return c;

    
// optimised;
int celebrity(vector<vector<int> >& mat) {
    int n=mat.size();
    if(n==1) return 0;
      int top=0,down=n-1;
      while(top<down){
          if(mat[top][down]==1) top++;
          else if(mat[down][top]==1) down--;
          else {
              top++;
              down--;
          }
          
      }
      int ok=1;
      if(top>down) return -1;
      for(int i=0;i<n;i++){
          if(top==i) continue;
          if(mat[top][i]==0 && mat[i][top]==1)  ok=1;
          else return -1;
      }
      return top;
  
}

// 146. LRU Cache
class LRUCache {
public:
    class Node {
    public:
        int key_;
        int val;
        Node* next;
        Node* prev;
        Node(int key1, int val1) {
            key_ = key1;
            val = val1;
            next = nullptr;
            prev = nullptr;
        }
    };

public:
    unordered_map<int, Node*> mpp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
 
    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head->next = tail;
        tail->prev = head;
    }
   void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* afterNode = node->next;
        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }
    void insertAfterHead(Node* node) {
        Node* afterHead = head->next;
        head->next = node;
        node->prev = head;
        node->next = afterHead;
        afterHead->prev = node;
    }
    int get(int key) {
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }
        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }

    void put(int key_, int value) {
        if (mpp.find(key_) != mpp.end()) {
            Node* node = mpp[key_];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        } else {
            if (mpp.size() == cap) {

                Node* node = tail->prev;
                mpp.erase(node->key_);
                deleteNode(node);
                delete node;
            }
        Node* newNode = new Node(key_, value);
        mpp[key_] = newNode;
        insertAfterHead(newNode);
        }
    }
};




//
// 460. LFU Cache

class Node {
public:
    int key, value, cnt;
    Node *next, *prev;
    Node(int _key, int _value) {
        key = _key;
        value = _value;
        cnt = 1;
        next = prev = nullptr;
    }
};

class List {
public:
    int size;
    Node *head, *tail;
    
    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *node) {
        Node *temp = head->next;
        node->prev = head;
        node->next = temp;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void deleteNode(Node *delnode) {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache {
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node *node) {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);

        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
            minFreq++;

        List *nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }

        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key) {
        if (keyNode.find(key) != keyNode.end()) {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (maxSizeCache == 0) {
            return;
        }

        if (keyNode.find(key) != keyNode.end()) {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        } else {
            if (curSize == maxSizeCache) {
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                list->deleteNode(list->tail->prev);
                curSize--;
            }

            curSize++;
            minFreq = 1;

            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            }

            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};
