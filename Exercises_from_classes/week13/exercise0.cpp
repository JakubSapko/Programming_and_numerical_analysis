#include <algorithm>
#include <iostream>
#include <vector>


template <class RandomIter>
void mergeSort(RandomIter begin, RandomIter end)
{
	int d = std::distance(begin, end);
	if(d<2)
		return;
	RandomIter center = begin + d/2;
	mergeSort(begin, center);
	mergeSort(center, end);
	RandomIter tab = merge(begin, center, end);

}

int main() {
std::vector<int> v = {6, 4, 2, 2, 3, 1, 24, -12, 0, 3, 1};
mergeSort(v.begin(), v.end());
std::for_each(v.begin(), v.end(), [](auto x) { std::cout << x << " "; });
return 0;
}