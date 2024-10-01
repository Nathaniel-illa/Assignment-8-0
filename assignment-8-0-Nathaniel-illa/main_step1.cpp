#include "main.hpp"

int main()
{
	int N = 1000;
	int swapcnt;
	vector<int> numbers, copied;
	fillvector(numbers, N);
	copied = numbers;
	print(numbers);

	// Insertion Sort
	swapcnt = insertion(numbers);
	print(numbers);

	// Bubble Sort
	numbers = copied;
	swapcnt = bubble(numbers);
	print(numbers);
}
