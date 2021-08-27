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

/*

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
You are given an array prices for which the ith element is the price of a given stock on day i.
Find the maximum profit you can achieve. You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
    
    int maxProfit2(vector<int>& prices) 
    {
        string flag = "buy";
        int profit = 0;
        int costprice;
        
        for(int i=0;i<prices.size();i++)
        {
            if(flag=="buy")
            {
                if(i!=prices.size()-1 && prices[i]<prices[i+1])
                {
                    flag="sell";
                    costprice = prices[i];
                }
            }
            else
            {
                if(i==prices.size()-1 || prices[i]>prices[i+1])
                {
                    flag = "buy";
                    profit+=prices[i]-costprice;
                }
            }
        }
        
        return profit;
        
    }