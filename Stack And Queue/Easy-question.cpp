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