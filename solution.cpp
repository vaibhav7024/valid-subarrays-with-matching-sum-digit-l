class Solution {
public:
    int firstdigit(long long num){
        while(num>=10) num/=10;
        return (int)num;
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> temp(n+1,0);
        for(int i=0;i<n;i++){
            temp[i+1]=temp[i]+nums[i];
        }
        int ans=0;
        for(int l=0;l<n;l++){
            for(int r=l+1;r<=n;r++){
                long long sum = temp[r]-temp[l];
                if(firstdigit(sum)==x && sum%10==x) ans++;
            }
        }
        return ans;
    }
};
