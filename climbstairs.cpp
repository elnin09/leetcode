/*
https://leetcode.com/problems/climbing-stairs/solution/

You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
    int climbStairs(int n) 
    { 
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> numways(n+1,0);
        numways[1]=1;
        numways[2]=2;
        for(int i=3;i<=n;i++)
        {
            numways[i]=numways[i-1]+numways[i-2];
        }
        return numways[n];
    }