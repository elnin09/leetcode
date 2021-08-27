   /*
   https://leetcode.com/problems/single-number/
   Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
   */
   
    int singleNumber(vector<int>& nums) 
    {
       int number = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            number = number^nums[i];
        }
        return number;
    }