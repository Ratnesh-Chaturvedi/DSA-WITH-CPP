class Solution {
public:

// similar to LIS  remember that we can start from anywhere and can take any element not follow subsequece 
    bool isPredecessor(string& a, string& b) {
        if (b.size() != a.size() + 1)
            return false;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j])
                i++, j++;
            else
                j++;
        }
        return (i == a.size());
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.size() < b.size(); });
        int n = words.size();
        int ans = 1;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int pi = 0; pi < i; pi++) {
                if (isPredecessor(words[pi], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[pi]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};