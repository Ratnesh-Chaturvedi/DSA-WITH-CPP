class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long >pq;
        long long  sum=0;
        for(int i=0;i<target.size();i++){
            sum+=target[i];
            pq.push(target[i]);
        }
        long long  remainSum,el,maxEl;
        while(pq.top()!=1){
            maxEl=pq.top();
            pq.pop();
            remainSum=sum-maxEl;
            if(remainSum==0) return false;
            el=maxEl%remainSum;
            //edge case 1
            if(el==0){
                if(remainSum==1) return true;
                else return false;
            }
            // edge case 2
            if(remainSum<=0 || remainSum>=maxEl) return false;
            pq.push(el);
            sum=remainSum+el;
            
        }
       return true;
    }
};