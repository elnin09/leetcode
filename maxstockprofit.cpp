/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
*/    
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        if(n==0) return 0;
        int curlowest = prices[0];
        int maxprofit = 0;
        for(int i=0;i<n;i++)
        {
            if(prices[i]>curlowest)
            {
                maxprofit = max(maxprofit,prices[i]-curlowest);
            }
            else
            {
                curlowest = prices[i];
            }
            
        }
        
        return maxprofit;
    }