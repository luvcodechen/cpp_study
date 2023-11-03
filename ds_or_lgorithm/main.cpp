#include <iostream>
#include "net.h"


int knapsack(int capacity, const std::vector<int>& weights, const std::vector<int>& values, int numItems)
{
	std::vector<std::vector<int>> dp(numItems + 1, std::vector<int>(capacity + 1, 0));

	for (int i = 1; i <= numItems; ++i)
	{
		for (int w = 0; w <= capacity; ++w)
		{
			if (weights[i - 1] <= w)
			{
				dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
			}
			else
			{
				dp[i][w] = dp[i - 1][w];
			}
		}
	}

	return dp[numItems][capacity];
}

int main()
{
	// Net::test();
	IntMatrix::testInMatrix();
	
	std::vector<int> weights = {2, 3, 4, 5, 7, 8, 9};
	std::vector<int> values = {3, 4, 5, 6, 10, 11, 12};
	int capacity = 15; // ±³°üÈÝÁ¿
	int numItems = weights.size();
	
	int maxTotalValue = knapsack(capacity, weights, values, numItems);
	
	std::cout << "sack£º\n" << "Maximum total value: " << maxTotalValue << std::endl;

	return 0;
}
