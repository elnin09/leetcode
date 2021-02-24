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