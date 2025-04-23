#include <bits/stdc++.h>
using namespace std;


// Infix to Postfix

int priority(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    return -1;
}
bool isRightAssociative(char c) {
    return c == '^';
}

string InfixToPostfix(string s) {
    string ans = "";
    stack<char> st;

    for(int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if(isalnum(ch)) {
            ans += ch;  // Append operand directly to result
        } 
        else if(ch == '(') {
            st.push(ch);
        } 
        else if(ch == ')') {
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // Pop the '('
        } 
        else { // Operator
            while(!st.empty() && st.top() != '(' &&
                  (priority(ch) < priority(st.top()) || 
                  (priority(ch) == priority(st.top()) && !isRightAssociative(ch)))) {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}


string infixToPrefix(string s) {
    // Step 1: Reverse and swap parentheses
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
    }

    // Step 2: Convert to postfix (on reversed string)
    string result = "";
    stack<char> st;

    for(int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if(isalnum(ch)) {
            result += ch;
        } 
        else if(ch == '(') {
            st.push(ch);
        } 
        else if(ch == ')') {
            while(!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        } 
        else {
            while(!st.empty() && st.top() != '(' &&
                  (priority(ch) < priority(st.top()) ||
                  (priority(ch) == priority(st.top()) && !isRightAssociative(ch)))) {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    // Step 3: Reverse postfix result to get prefix
    reverse(result.begin(), result.end());
    return result;
}

string PostfixToInfix(string s) {
    stack<string> st;

    for(int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if(isalnum(ch)) {
            st.push(string(1, ch)); // convert char to string
        } 
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string cont = "(" + t2 + ch + t1 + ")";
            st.push(cont);
        }
    }

    return st.top();
}
string PrefixToInfix(string s) {
    stack<string> st;

    for(int i = s.size()-1; i>=0; i--) {
        char ch = s[i];

        if(isalnum(ch)) {
            st.push(string(1, ch)); // convert char to string
        } 
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string cont = "(" + t1 + ch + t2  + ")";
            st.push(cont);
        }
    }

    return st.top();
}

string PostfixToPrefix(string s) {
    stack<string> st;

    for(int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if(isalnum(ch)) {
            st.push(string(1, ch)); // convert char to string
        } 
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string cont =  ch + t2  + t1 ;
            st.push(cont);
        }
    }

    return st.top();
}

string PrefixToPostfix(string s) {
    stack<string> st;

    for(int i = s.size()-1; i >=0; i--) {
        char ch = s[i];

        if(isalnum(ch)) {
            st.push(string(1, ch)); // convert char to string
        } 
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string cont =  t1+t2+ch ;
            st.push(cont);
        }
    }

    return st.top();
}
int main(){
    string s="/-ab*+def";
    cout<<PrefixToPostfix(s);
} 
