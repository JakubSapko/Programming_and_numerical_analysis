#include <algorithm>
#include <iostream>
#include <vector>

template <class RandomIt>
RandomIt partition(RandomIt begin, RandomIt end)
{
	RandomIt pivot = begin;
	RandomIt start = std::next(begin);

	for(auto it=start; it!=end; ++it)
	{
		if(*it <= *pivot)
			{
				std::rotate(pivot, it, std::next(it));
				pivot = it;
			}
	}
	return pivot;
}


template <class RandomIt>
void quickSort(RandomIt begin, RandomIt end)
{
	if (begin == end)
		return;
	RandomIt pivot = partition(begin, end);
	quickSort(begin, pivot);
	quickSort(std::next(pivot), end);
}

int main() 
{
	std::vector<int> v = {11, -3, 2, 4, 0, 6, 4, -2, 2, 3, 1};
	quickSort(v.begin(), v.end());
	std::for_each(v.begin(), v.end(), [](auto x) { std::cout << x << " "; });
	std::cout<<std::endl;
	return 0;
}