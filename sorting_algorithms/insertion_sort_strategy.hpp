#pragma once

#include <SFML/Graphics.hpp>

#include "sorting_strategy.hpp"


class InsertionSortStrategy: public SortingStrategy
{
public:
	InsertionSortStrategy(SortingView& v, Sortable& data):
		SortingStrategy{v, data} {};

	~InsertionSortStrategy() = default;

	void run() const override;
};
