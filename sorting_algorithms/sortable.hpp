#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Sortable
{
public:
	Sortable(size_t len):
		max{len}
	{
		for(size_t i{0}; i < len;)
			_data.push_back(++i);
		shuffle();
	}

	void shuffle();
	void show() const;
	size_t getCount() const { return _data.size(); };

	friend class SortingStrategy;
	friend class SortingView;

	size_t& operator[](size_t i) {return _data[i];};

private:
	std::vector<size_t> _data;
	size_t max;
};
