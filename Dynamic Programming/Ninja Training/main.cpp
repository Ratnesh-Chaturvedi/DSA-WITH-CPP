A ninja has planned a n-day training schedule. Each day he has to perform one of three activities - running, stealth training, or fighting practice. The same activity cannot be done on two consecutive days and the ninja earns a specific number of merit points, based on the activity and the given day.

Given a n x 3-sized matrix, where matrix[i][0], matrix[i][1], and matrix[i][2], represent the merit points associated with running, stealth and fighting practice, on the (i+1)th day respectively. Return the maximum possible merit points that the ninja can earn.

Examples:
Input: matrix = [[10, 40, 70], [20, 50, 80], [30, 60, 90]]
Output: 210
Explanation:
Day 1: fighting practice = 70
Day 2: stealth training = 50
Day 3: fighting practice = 90
Total = 70 + 50 + 90 = 210
This gives the optimal points.

Input: matrix = [[70, 40, 10], [180, 20, 5], [200, 60, 30]]
Output: 290
Explanation:
Day 1: running = 70
Day 2: stealth training = 20
Day 3: running = 200
Total = 70 + 20 + 200 = 290

This gives the optimal points.


 
  int solve(int days,int last,vector<vector<int>>&arr,vector<vector<int>>&dp){
      if(days==0){
         int maxi=0;
          for(int task=0;task<3;task++){
              if(task!=last){
                  maxi=max(maxi,arr[0][task]);
              }
          }
          return dp[days][last]=maxi;
      }
      if(dp[days][last]!=-1) return dp[days][last];
      int maxi=0;
      for(int task=0;task<3;task++){
          if(task!=last){
              int point=arr[days][task]+solve(days-1,task,arr,dp);
              maxi=max(point,maxi);
          }
      }
      return dp[days][last]=maxi;
  }
    int maximumPoints(vector<vector<int>>& arr) {
      int n=arr.size();
      vector<vector<int>>dp(n,vector<int>(4,-1));
    //   return solve(n-1,3,arr,dp);
    
    // Using tabulation
    // dp[0][0]=max(arr[0][1],arr[0][2]);
    // dp[0][1]=max(arr[0][0],arr[0][2]);
    // dp[0][2]=max(arr[0][1],arr[0][0]);
    // dp[0][3]=max(arr[0][1],max(arr[0][2],arr[0][0]));
    
    // for(int day=1;day<n;day++){
    //     for(int last=0;last<=3;last++){
    //   dp[day][last]=0;
    //   int maxi=0;
    //      for(int task=0;task<3;task++){
    //          if(last!=task){
    //              maxi=max(arr[day][task]+dp[day-1][task],maxi);
    //          }
    //      }
    //     dp[day][last]=maxi;
    //     }
    // }
    // return dp[n-1][3];
    
    
    // space optimised
    // we use only 4 size array to carray the ith row values
    vector<int>prev(4,-1);
    prev[0]=max(arr[0][1],arr[0][2]);
    prev[1]=max(arr[0][0],arr[0][2]);
    prev[2]=max(arr[0][1],arr[0][0]);
    prev[3]=max(arr[0][1],max(arr[0][2],arr[0][0]));
    for(int day=1;day<n;day++){
        vector<int>temp(4,0);
        for(int last=0;last<=3;last++){
            temp[last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    
                int point=arr[day][task]+prev[task];
                temp[last]=max(point,temp[last]);
                }
            }
        }
        prev=temp;
    }
    return prev[3];
    }