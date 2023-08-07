class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        
        // INTUITION: You don't have to worry about the future pricing, just focus on
        //  the day after, it.
        // We would buy a stock at day 'd' only if it's price increases at 'd+1' day.
        
        //  Kyuki yaa mai har vo profit consider karunga, jaha agle din mujhe cost me
        // increment milega.
        int profit =0 ;
        for(int i = 0; i < n-1; i++)
        {
            if(prices[i+1] > prices[i])
            {
                profit+= prices[i+1] - prices[i];
            }
        }
        
        return profit;
    }
    
    //  3 1 5 7 9
};
