class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int i=0;
        int j=0;
        int maxi=0;
        int imaxi=0;
        int jmaxi=0;
        int customerSum=0;

        while(j<n){
            if(grumpy[j]==1){
                customerSum+=customers[j];
            }

            if(j-i+1<minutes){
                j++;
            }

            else if(j-i+1==minutes){
                if(customerSum>maxi){
                    imaxi=i;
                    jmaxi=j;
                    maxi=customerSum;
                }

                if(grumpy[i]==1){
                    customerSum-=customers[i];
                }

                i++;
                j++;
            }
        }

        int ans=0;
        for(int k=0;k<imaxi;k++){
            if(grumpy[k]==0){
                ans+=customers[k];
            }
        }

        for(int k=imaxi;k<=jmaxi;k++){
            ans+=customers[k];
        }

        for(int k=jmaxi+1;k<n;k++){
            if(grumpy[k]==0){
                ans+=customers[k];
            }
        }
        return ans;
    }
};