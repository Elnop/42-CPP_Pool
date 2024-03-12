#include <vector>
#include <algorithm>
#include <iostream>

template <class T>
class PmergeMe {
public:
    static void sort_and_print(T &container) {
        std::cout << "Before ";
        print(container);
        std::cout << std::endl;
        double timer_start = clock();
        sort(container);
        double duration = clock() - timer_start;
        std::cout << "After ";
        print(container);
        std::cout << std::endl;
        std::cout << "Duration: " << duration << " us" << std::endl;
    }
private:
    static void sort(T &c)
	{
		if (!c.empty()) {
			fordJohnsonMergeInsertionSort(c, 0, c.size() - 1);
		}
	}
    static void print(T &container) {
        for (typename T::iterator it = container.begin(); it != container.end(); it++) {
            std::cout << *it << " ";
        }
    }
	static void fordJohnsonMergeInsertionSort(T &c, int start, int end)
	{
		if (start >= end) return;
		if (end - start == 1) {
			if (c[start] > c[end]) {
				std::swap(c[start], c[end]);
			}
			return;
		}
		std::vector<int> medians;
		for (int i = start; i < end; i += 2) {
			if (c[i] > c[i + 1]) {
				std::swap(c[i], c[i + 1]);
			}
			medians.push_back(i + 1);
		}
		if ((end - start + 1) % 2 != 0) {
			medians.push_back(end);
		}
		int medianOfMedians = selectMedian(c, medians);
		int mid = partition(c, start, end, medianOfMedians);
		fordJohnsonMergeInsertionSort(c, start, mid - 1);
		fordJohnsonMergeInsertionSort(c, mid, end);
	}
	static int partition(T &c, int start, int end, int pivotIndex) {
		std::swap(c[pivotIndex], c[end]);
		int storeIndex = start;
		for (int i = start; i < end; i++) {
			if (c[i] < c[end]) {
				std::swap(c[i], c[storeIndex]);
				storeIndex++;
			}
		}
		std::swap(c[storeIndex], c[end]);
		return storeIndex;
	}
    struct Compare {
		const T& c;
		Compare(const T& set) : c(set) {}
		bool operator()(int a, int b) { return c[a] < c[b]; }
	};
	static int selectMedian(T &c, const std::vector<int> &medians) {
		std::vector<int> temp = medians;
		std::sort(temp.begin(), temp.end(), Compare(c));
		return temp[temp.size() / 2];
	}
};