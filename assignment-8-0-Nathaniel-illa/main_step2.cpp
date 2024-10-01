#include "main.hpp"

int main()
{
	int N = 1000;
	int swapcnt;
	vector<int> numbers, copied;
	fillvector(numbers, N);
	copied = numbers;
	// print(numbers);

	// Time Check: Insertion Sort
	auto start = high_resolution_clock::now();
	swapcnt = insertion(numbers);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	printf("The number of swap \t %d and Time taken by insertion %lld\n", swapcnt, duration.count());
	// print(numbers);

	// Time Check: Bubble Sort
	numbers = copied;
	start = high_resolution_clock::now();
	swapcnt = bubble(numbers);
	stop = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(stop - start);
	printf("The number of swap \t %d and Time taken by bubble %lld\n", swapcnt, duration.count());
	// print(numbers);

	// Time Check: Standard Sort
	numbers = copied;
	start = high_resolution_clock::now();
	sort(numbers.begin(), numbers.end());
	stop = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(stop - start);
	cout << "Time taken by sort \t\t" << duration.count() << " nsec\n";
	// print(numbers);
}
