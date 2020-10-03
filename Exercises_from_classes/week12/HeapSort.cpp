#include <iostream> 
#include <vector>
#include <algorithm>

template<typename I>
void heapify(I begin, I end, std::size_t current)
{
	// NON RECURSIVE
    // std::size_t size = std::distance(begin, end);
    // std::size_t current = index;
    // std::size_t child;

    // while ((child = 2 * current + 1) < size)
    // {
    //     I itr_child   = begin + child;
    //     I itr_current = begin + current;

    //     if(child < size - 1 
    //         && (*itr_child < *(itr_child + 1)))
    //     {
    //         ++itr_child;
    //     }

    //     if (!(*itr_current <  *itr_child))
    //     {
    //         break;
    //     }
    //     std::swap(*itr_current, *itr_child);
    //     current = child;
    // }

    //RECURSIVE
    std::size_t size = std::distance(begin, end);
    if(current >= size) 
    	return;
    // PIERWSZE DZIECKO
    std::size_t child = 2 * current + 1;
    if (child >= size)
    	return;
    // ITERATORY NA RODZICA I DZIECKO
    I itr_child   = begin + child;
    I itr_current = begin + current;
    // MOZLIWE WYBRANIE DRUGIEGO DZIECKA
    if(child < size - 1  && (*itr_child < *(itr_child + 1)))
    {
        ++itr_child;
        child++;
    }
    // ZAMIANA NIEPOTRZEBNA
    if (*itr_current > *itr_child)
    	return;
    // ZAMIANA
    std::swap(*itr_current, *itr_child);
    // REKURSJA
    heapify(begin, end, child);
}

template<typename I>
void heapSort(I begin, I end)
{
    std::size_t size = std::distance(begin, end);
    // KOPCUJEMY TABLICE
    for (int i = size / 2 - 1; i > -1; --i) 
    {
        heapify(begin, end, i);
    }
   	// SORTOWANIE, NA KONIEC UMIESZCZAMY KORZENIE
    for (std::size_t i = size - 1; i > 0; --i)
    {
    	// PRZESUWAMY KORZEN NA KONIEC
        std::swap(*begin, *(begin+i));
        // KOPCUJEMY TO CO ZOSTALO
        heapify(begin, begin+i, 0);
    }
}
int main() 
{ 
	std::vector<int> v = {25, 1, 3, 13, 2, 8, 0, -2, 4, -2, 2, -3, -1, 1, 24};
	heapSort(v.begin(), v.end());
	std::for_each(v.begin(), v.end(), [](auto x) { std::cout << x << " "; });
	std::cout<<std::endl;
	return 0;

} 
