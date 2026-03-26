// in this question we first start by assuming that the even number is 1 and odd is -1 
// and take the cumulative sum of the elements 
// yaha par ye kar rahe hai ki agr koi ele mai or uska picle wale ke sath cumulattive sum ==0 then we can assume that ki usmai evencnt==oddcnt hai  // agr nahi hai toh aage toh uska leftmost zero find karenge then wo us range mai hamara answer hoga like 
// 1,2,3,2 
// here we have 1->-1// 2->+1 // for this index 1-> we have 1+-1=0 so len=r-l+1 =2
// // now 3->-1 // last index -> +1 // and iska sum akrenge => 1+-1 =0;  but agr -1 pure mai add kare toh woh 1st el ke pass jakar -1 ho jayega opr hume  sirf waha tak chaiye jaha zero mil -> [2,3] l=2
// // smae for [2,3,2]  ab 2 already seen hai par range mai contribute toh karega hi toh iska bhi cumulative mai sum kar denge  so len=3 

// baki segment tree lazy progation ke sath ye upadation and finding leftmost zero ke liye help karega 



class Solution {
public:
    vector<int> segmax, segmin, lazy;
    int n;
    void propagate(int i, int l, int r) {
        if (lazy[i] != 0) {
            segmax[i] += lazy[i];
            segmin[i] += lazy[i];
            // check that that tree has its child nodes or not
            if (l != r) {
                lazy[2 * i + 1] +=lazy[i];
                lazy[2 * i + 2] += lazy[i];
            }
            // reset the lazy value because it is progated successfully
            lazy[i] = 0;
        }
    }

    void updateRange(int st, int end, int i, int l, int r, int val) {
        propagate(i, l, r);
        // out of bound
        if (l > end || r < st) {
            return;
        }
        // overlap
        if (l >= st && r <= end) {
            lazy[i] += val;
            propagate(i, l, r);
            return; // it reduces the time and only update the topmost node of
                    // the range instead of updating the entire range nodes
        }

        int mid = (r + l) / 2;
        updateRange(st, end, 2 * i + 1, l, mid, val);
        updateRange(st, end, 2 * i + 2, mid + 1, r, val);

        segmin[i] = min(segmin[2 * i + 1], segmin[2 * i + 2]);
        segmax[i] = max(segmax[2 * i + 1], segmax[2 * i + 2]);
    }

    // finding the leftmost index where the cumsum ==0
    int findLMIdx(int i, int l, int r) {
        propagate(i, l, r);

        // kyuki age max hi chota hoga then there is no chance that 0 ie
        // odd==even will exist
        if (segmin[i] > 0 || segmax[i] < 0)
            return -1;

           if(l==r)return l; 
        int mid =  (r + l) / 2;
        int left = -1;
        left = findLMIdx(2 * i + 1, l, mid);
        if (left != -1)
            return left;

        // right side
        return findLMIdx(2 * i + 2, mid + 1, r);
    }

    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        segmax.assign(4 * n, 0);
        segmin.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        unordered_map<int, int> hash;
        int mxl = 0;
        // vector<int>cumsum(n,0);
        for (int r = 0; r < n; r++) {
            int val = (nums[r] % 2 == 0) ? 1 : -1;

            int prevSeen =
                -1; // variable to check we have seen this earlier or not
            if (hash.count(nums[r]))
                prevSeen = hash[nums[r]];
            // it means we dont have this element yet in the hash // not seen
            // till yet
            if (prevSeen != -1) {
                // for(int l=0;l<=prevSeen;l++)cumsum[l]-=val;
                // updating the tree using lazy propagation
                updateRange(0, prevSeen,0, 0, n - 1, -val);
            }

            // for(int l=0;l<=r;l++){
            //     cumsum[l]+=val;
            // }

            // updating the tree using lazy propagation
            updateRange(0, r, 0,0, n - 1, val);

            // finding the leftmost zero -> represent that in this range we have
            // equal even and odd for(int l=0;l<=r;l++){
            //     if(cumsum[l]==0){
            //         mxl=max(r-l+1,mxl);
            //         break;
            //     }
            // }

            // finding leftmost ussing the segtree
            int l = findLMIdx(0, 0, n - 1);
            if (l != -1)
                mxl = max(mxl, r - l + 1);
            hash[nums[r]] = r;
        }
        return mxl;
    }
};