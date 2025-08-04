// 1423. Maximum Points You Can Obtain from Cards
int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxsum = 0;
        if (k >= n) {
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }

        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += cardPoints[i];
        maxsum = sum;
        int ridx = n - 1;
        for (int i = k - 1; i >= 0; i--) {
            sum -= cardPoints[i];
            sum += cardPoints[ridx];
            ridx--;
            maxsum = max(sum, maxsum);
        }
        return maxsum;
    }
