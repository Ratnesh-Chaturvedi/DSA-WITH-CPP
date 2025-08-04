// 424. Longest Repeating Character Replacement
 int characterReplacement(string s, int k) {
        int n = s.size();
        int r = 0, l = 0, len = 0;
        unordered_map<char, int> hash;
        int maxfreq = 0;
        while (r < n) {
            hash[s[r]]++;
            // maxfreq is the used to take the character which has highest count
            maxfreq = max(maxfreq, hash[s[r]]);
            if ((r - l + 1) - maxfreq > k) {
                hash[s[l]]--;
                l++;
            }
            len = max(len, r - l + 1);
            r++;
        }
        return len;
    }

    