/*
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Input:
[4,3,2,7,8,2,3,1]
Output:
[5,6]
*/

    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
      int hashFunctionNumber = nums.size()+1;
      int n = nums.size();  
        
        
      for(int i=0;i<n;i++)
      {
         nums[nums[i]%hashFunctionNumber - 1]+=hashFunctionNumber;  
      }
        
      vector<int> retval;
        
      for(int i=0;i<n;i++)
      {
          if(nums[i]/hashFunctionNumber == 0)
              retval.push_back(i+1);
      }
        
        return retval;
    }