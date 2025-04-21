// 225. Implement Stack using Queues
class MyStack {
    public:
            queue<int>q;
        MyStack() {
        }
        void push(int x) {
            int n=q.size(); 
            q.push(x);
           for(int i=0;i<n;i++){
            q.push(q.front());
            q.pop();
           }
        }
        int pop() {
            int n=q.front();
             q.pop();
             return n;
        }
        int top() {
            return q.front();
        } 
        bool empty() {
            int n=q.size();
            if(n==0) return true;
            return false;
        }
    };



    //232. Implement Queue using Stacks


    // Approach 1-

    struct Queue {
        stack < int > input, output;
        
        // Push elements in queue
        void Push(int data) {
          // Pop out all elements from the stack input
          while (!input.empty()) {
            output.push(input.top());
            input.pop();
          }
          // Insert the desired element in the stack input
          cout << "The element pushed is " << data << endl;
          input.push(data);
          // Pop out elements from the stack output and push them into the stack input
          while (!output.empty()) {
            input.push(output.top());
            output.pop();
          }
        }
        // Pop the element from the Queue
        int Pop() {
          if (input.empty()) {
            cout << "Stack is empty";
            exit(0);
          }
          int val = input.top();
          input.pop();
          return val;
        }
        // Return the Topmost element from the Queue
        int Top() {
          if (input.empty()) {
            cout << "Stack is empty";
            exit(0);
          }
          return input.top();
        }
        // Return the size of the Queue
        int size() {
          return input.size();
        }
      };


    // Apprroach 2 - Better
class MyQueue {
        public:
        stack<int>s1,s2;
        
            MyQueue() {    
            }
            void push(int x) {
             s1.push(x);
            }
            int pop() {
               if(s2.empty()){
                while(s1.size()){
                    s2.push(s1.top());
                    s1.pop();
                }}
                int x=s2.top();
                s2.pop();
                return x;
            }
            int peek() {
                if(s2.empty()){
                    while(s1.size()){
                        s2.push(s1.top());
                        s1.pop();
                    }
                }
                    return s2.top();
            }
            
            bool empty() {
          if(s1.size()!=0 || s2.size()!=0) return false;
          return true;      
            }
        };



// 20. Valid Parentheses
        bool isValid(string s) {
          stack<char>st;
          for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
          st.push(s[i]);
        }
        else {
          if(st.empty()) return false;
          char ch=st.top();
          st.pop();
          if((s[i]==')' && ch=='('  ) || (s[i]=='}' && ch=='{' )  || (s[i]==']' && ch=='[' )) continue;
          else return false;
        }
          }
        if(st.empty()) return true;
        return false;
      }      



      // 155. Min Stack
//TC-O(1) SC-O(2*n)
      class MinStack {
        public:
        stack<pair<int,int>>st;
            MinStack() {   
            }
            void push(int val) {
                if(st.empty()){
                    int mini=val;
                    st.push({val,mini});
                }
                else {
                    int mini=st.top().second;
                     mini=min(mini,val);
                    st.push({val,mini});   }
            }
            void pop() {
                st.pop();
            }
            int top() {
                if(st.empty()) return -1;
                return st.top().first;
            }
            int getMin() {
                return st.top().second;
            }
        };

        //space Optimised
        class MinStack {
          public:
          stack<long long >st;
          long long  mini=INT_MAX;
              MinStack() {
                  
              }
              
              void push(int val) {
                  long long value=(long long)val;
                  if(st.empty()){
                      mini=value;
                      st.push(value);
                  }
                  else {
                      if(val>mini) st.push(val);
                      else {
                          st.push(2ll*val - mini);
                          mini=val;
                      }
                  }
              }
              
              void pop() {
                 if(st.empty()) return;
                 long long x=st.top();
                 st.pop();
                 if(x < mini) mini=2*mini-x;
              }
              
              int top() {
                 if(st.empty()) return-1;
                 long long x=st.top();
                 if(mini<x) return x;
                 return mini;
                 }
              
              int getMin() {
                 return mini;
              }
          };