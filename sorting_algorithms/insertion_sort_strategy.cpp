#include "insertion_sort_strategy.hpp"

void InsertionSortStrategy::run() const
{
	for(int i{0}; i < data.getCount(); ++i)
	{
		size_t val = data[i];

		int j{i};
		while(j > 0 && data[j] < data[j-1])
		{
			data[j] = data[j-1];
			data[j-1] = val;
			--j;
		sview.updateDisplay();
		sf::sleep(seconds(0.001));
		}
		data[j] = val;


		sview.updateDisplay();
		sf::sleep(seconds(0.001));
	}
}
