class Solution {
public:
    int missingNumber(vector<int>& nums) {
       //sum approach
       int n=nums.size();
       int sum=(n*(n+1))/2;
       int total;
       int pre=0;
      for(int num:nums){
        pre+=num;
      }
     // total=sum-pre;

       
       return total= sum-pre;
    }
};
