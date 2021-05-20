#include "sortable.hpp"

void swap(size_t& a, size_t& b)
{
	size_t tmp = a;
	a = b;
	b = tmp;
}

void Sortable::shuffle()
{
	srand(time(NULL));
	size_t l{_data.size()};
	for(size_t i{0}; i < l; ++i)
		swap(_data[i], _data[rand() % l]);
}


void Sortable::show() const
{
	for(size_t i{0}; i < _data.size(); ++i)
		std::cout << _data[i] << " | ";
}
