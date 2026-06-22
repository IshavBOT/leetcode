class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int i=0;
        int j=0;
        long long minSum=INT_MAX;
        long long totalSum=0;

        for(int points:cardPoints){
            totalSum+=points;
        }

        int windowSize=n-k;

        if(windowSize==0){
            return totalSum;
        }

        long long sum=0;

        while(j<n){
            sum+=cardPoints[j];

            if(j-i+1<windowSize){
                j++;
            }

            else if(j-i+1==windowSize){
                minSum=min(minSum,sum);
                sum=sum-cardPoints[i];
                i++;
                j++;
            }
        }

        return totalSum-minSum;

    }
};