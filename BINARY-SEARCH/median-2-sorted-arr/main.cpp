 Median of Two Sorted Arrays


 //brute force
//  TC-O(n1+n2);
//SC- Oc(n1+n2);

class Solution {
public:
vector<int>merge(vector<int>& nums1, vector<int>& nums2){
    int i=0;
    int j=0;
    vector<int>ans;
    int n1=nums1.size();
    int n2=nums2.size();
    while(i<n1 && j<n2){
        if(nums1[i]<=nums2[j]){
            ans.push_back(nums1[i]);
            i++;
        }
        else {
            ans.push_back(nums2[j]);
            j++;
        }
    }
    while(i<n1){
         ans.push_back(nums1[i]);
            i++;
    }
    while(j<n2){
         ans.push_back(nums2[j]);
            j++;
    }
    return ans;
}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans=merge(nums1,nums2);
        int n=ans.size();
        if(n%2!=0) {
            int index=(n/2);
            return ans[index];  
    }
    else {
        int id1=(n-1)/2;
        int id2=((n)/2);
        return ( (double)ans[id1]+ (double)ans[id2])/2;
    }

    }
};

// better  SC-O(1)
double median(vector<int>& a, vector<int>& b) {
	//better apporoach

	int n1=a.size();
	int n2=b.size();
	int n3=n1+n2;
	int i=0;
	int j=0;
	int cnt=0;
	int ind2=n3/2;
	int ind1=ind2-1;
	int ind1el=-1,ind2el=-1;
        while (i < n1 && j < n2) {
		if(a[i]<b[j]){
          if (cnt == ind1) ind1el = a[i];
          if (cnt == ind2) ind2el = a[i];
          cnt++;
          i++;
        }
		else {
			 if (cnt == ind1) ind1el = b[j];
          if (cnt == ind2) ind2el = b[j];
          cnt++;
		  j++;
		}
        }

		while(i<n1){
			 if (cnt == ind1) ind1el = a[i];
          if (cnt == ind2) ind2el = a[i];
          cnt++;
          i++;
		}

		while(j<n2){
			if (cnt == ind1) ind1el = b[j];
          if (cnt == ind2) ind2el = b[j];
          cnt++;
		  j++;
		}

		if(n3%2==1){
			return ind2el;
		}
		return (double)((double)(ind1el+ind2el)/2.0);
}




	//Optimal approach

	int n1=a.size();
	int n2=b.size();
	int n=n1+n2;
	if(n1>n2) return median(b,a); // bcoz we need small size arr for Time Optimise
	int left=(n1+n2+1)/2;
	int low=0;
	int high=n1;
	while(low<=high){
		int mid1=(low+high)>>1; // or (low+high)/2;
		int mid2=left-mid1;
	int l1=INT_MIN , l2=INT_MIN; // if not exist
	int r1=INT_MAX , r2=INT_MAX; // if not exist
		if(mid1 < n1) r1=a[mid1];
		if(mid2 < n2) r2=b[mid2];
		if(mid1-1>=0) l1=a[mid1-1];
		if(mid2-1>=0) l2=b[mid2-1];
		if(l1<=r2 && l2<=r1) {
			if(n%2==1){
				return max(l1,l2);
			}
				return ( (double)( max(l1,l2)+min(r1,r2)))/2.0;

		}
		else if(l1>r2) high=mid1-1;
		else low=mid1+1;
	}

	return 0;



    


    //leetcode optimised inside while
                   
                   // for this case
nums1 =[1,2]
nums2 =[3,4]

    int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
    int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
    int r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
    int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;

