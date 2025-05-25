// 455. Assign Cookies
 int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        int cnt = 0;
        while (i < n && j < m) {
            if (s[j] >= g[i]) {
                cnt++;
                j++, i++;
            } else
                j++;
        }
        return cnt;
}

// 860. Lemonade Change
bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        if (bills[0] == 10 || bills[0] == 20)
            return false;
        int n = bills.size();
        for (int i = 0; i < n; i++) {
            if (bills[i] == 5)
                five++;
            else if (bills[i] == 10) {
                ten++;
                if (five <= 0)
                    return false;
                five = five - 1;
            } else {
                if (ten && five) {
                    ten = ten - 1;
                    five--;
                } else if (five >= 3)
                    five -= 3;
                else {
                    return false;
                }
            }
        }
        return true;
    }


//Shortest Job first
   long long solve(vector<int>& bt) {
   sort(bt.begin(),bt.end());
   long long   n=bt.size();
   long long t=0;
   long long wt=0;
   for(long long i=0;i<n;i++){
     wt+=t;
     t+=bt[i];
   }
   return wt/n;
 }





// 678. Valid Parenthesis String
  bool check(string s, int idx, int cnt) {
        if (cnt < 0)
            return false;
        if (idx == s.size())
            return cnt == 0;
        if (s[idx] == '(')
            return check(s, idx + 1, cnt + 1);
        if (s[idx] == ')')
            return check(s, idx + 1, cnt - 1);
        // if it is *
        return (check(s, idx + 1, cnt + 1) || check(s, idx + 1, cnt - 1) ||
                check(s, idx + 1, cnt));
    }
    bool checkValidString(string s) {
        // by using recursion
        // return check(s,0,0);

        // optimised
        int mini = 0, maxi = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                mini++;
                maxi++;
            } else if (s[i] == ')') {
                maxi--;
                mini--;
            } else {
                mini--;
                maxi++;
            }
            if (mini < 0)
                mini = 0;
            if (maxi < 0)
                return false;
        }
        return mini == 0;
    }

    
// 55. Jump Game
//My brute force -but gives tle;

bool check(vector<int>& nums,int idx,int n){
    if(nums[idx]>=n) return true;
    if(idx>=n) return true;
    if(nums[idx]==0) return false;
    for(int i=1;i<=nums[idx];i++){
   if( check(nums,idx+i,n)) return true;
    }
    return false;
}
    bool canJump(vector<int>& nums) {
     int n=nums.size();
      return   check(nums,0,n-1);
    }

// optimised using greedy
   bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxIdx=nums[0];
       if(nums[0]==0 && n>1) return false;
        for(int i=1;i<n;i++){
         if(maxIdx< i) return false; 
         maxIdx=max(maxIdx,nums[i]+i);
        }
        return true;
    }


// 45. Jump Game II
// int minJump(vector<int>&nums,int jump,int idx){
//    if(idx >=nums.size()-1) return jump;
//    int mini=INT_MAX;
//    for(int i=1;i<=nums[idx];i++){
//     mini=min(mini,minJump(nums,jump+1,idx+i));
//    }
//    return mini;
// }
    int jump(vector<int>& nums) {
        //recursive approach
// return minJump(nums,0,0);

 //optimised by greedy appproach
 int jmp=0;
 int l=0,r=0; // these variable are for storing range
 while(r<nums.size()-1){
    int farthest=0;
    for(int i=l;i<=r;i++){
        farthest=max(i+nums[i],farthest);
    }
    l=r+1;
    r=farthest;
    jmp=jmp+1;
 }
return jmp;   
 }



 // Job Sequencing Problem
 vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
     int n=deadline.size();
     
     vector<pair<int,int>>jobs;
     for(int i=0;i<n;i++){
         jobs.push_back({deadline[i],profit[i]});
     }
     sort(jobs.begin(),jobs.end());
     priority_queue<int,vector<int>,greater<int>>pq;
     int totalsum=0,cnt=0;
     
     for(int i=0;i<n;i++){
         if(jobs[i].first>cnt){
             cnt++;
             totalsum+=jobs[i].second;
             pq.push(jobs[i].second);

         }
         else if(jobs[i].second>pq.top()){
             totalsum-=pq.top();
             pq.pop();
             totalsum+=jobs[i].second;
             pq.push(jobs[i].second);
         }
     }
     return {cnt,totalsum};
        
    }


// N N meetings in one room
 bool sortBysecondel(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    }
class Solution {
  public:
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
      int cnt=0;
      int n=start.size();
vector<pair<int,int>>meet;
for(int i=0;i<n;i++){
    meet.push_back({start[i],end[i]});
}
      sort(meet.begin(),meet.end(),sortBysecondel);
      
vector<pair<int,int>>ans;
for(int i=0;i<n;i++){
    if(ans.empty() || meet[i].first>ans.back().second){
        ans.push_back(meet[i]);
    }
}
      int size=ans.size();
      
        return size;
    }
}