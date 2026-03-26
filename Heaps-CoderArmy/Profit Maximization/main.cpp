 Given an array A , representing seats in each row of a stadium. You need to sell tickets to B people.

Each seat costs equal to the number of vacant seats in the row it belongs to. The task is to maximize the profit by selling the tickets to B people.
Problem Constraints
1 <= |A| <= 100000
1 <= B <= 1000000

Input Format
First argument is the array A.
Second argument is integer B.
Output Format
Return one integer, the answer to the problem.
Example Input
Input 1:
A = [2, 3]
B = 3

Input 2:
A = [1, 4]
B = 2


Example Output
Output 1:

7
Output 2:

7



int Solution::solve(vector<int> &A, int B) {
    priority_queue<int>pq;
    
    for(int i=0;i<A.size();i++){
        pq.push(A[i]);
    }
    int sum=0;
    while(!pq.empty() && B--){
        int top=pq.top();
        sum+=top;
        pq.pop();
        if(top>0){
            pq.push(top-1);
        }
        
    }
    return sum;
    
}
