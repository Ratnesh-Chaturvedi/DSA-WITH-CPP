

struct Node{
    Node * links[26]; // lower case alphabets
    bool flag=false; // indicating that it is not the null node 

    // check if the node contains a letter
    bool containKey(char c){
        return links[c-'a']!=nullptr;
    }

    // insert the node with specific letter into trie
    void put(char c,Node*node){
        links[c-'a']=node;
    }

    // get the node with the specific letter 
    Node*get(char c){
        return links[c-'a'];
    }

    // set the node as the last node so its flag value = true
    void setEnd(){
        flag=true;
    }
    // check it is the end
    bool isEnd(){
        return flag;
    }
};

class Trie {
    private :
    Node*root;
public:
    Trie() {
    root=new Node();
    }
    
    // insert the word into trie
    void insert(string word) {
        Node *node=root;
        for(char c:word){
            if(!node->containKey(c)){
                // create a new node if not present
                node->put(c,new Node());
            }
            // move to next node
            node=node->get(c);
        }
        // marks the end of the word
        node->setEnd();
    }
    
    bool search(string word) {
        Node*node=root;
        for(char c:word){
            if(!node->containKey(c)){
                return false;
            }
            node=node->get(c);
        }
        return node->isEnd();
    }

// find the string that has the starting letter like given letter
    bool startsWith(string prefix) {
        Node*node=root;
        for(char c:prefix){
            if(!node->containKey(c)){
                return false;
            }
            node=node->get(c);
        }
        return true;
    }
};

