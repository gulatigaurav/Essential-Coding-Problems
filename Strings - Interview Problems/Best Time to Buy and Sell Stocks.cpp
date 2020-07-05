// Approach 1
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max_profit = INT_MIN;
        int min_price = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                int currentPrice = prices[i];
                min_price = min(min_price, currentPrice);
                max_profit = max(max_profit, prices[j] - min_price);
            }
        }
        if (max_profit < 0)
            return 0;
        return max_profit;
    }
};

// Approach 2

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int max_profit = INT_MIN;
        int min_price = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            min_price = min(min_price, prices[i]);
            max_profit = max(max_profit, prices[i] - min_price);
        }
        return max_profit;
    }
};