#include<iostream>
using namespace std;
#define m 100

class Heapsort {
private:
	int a[m];
	int n;

public:
	Heapsort(){};
	void swap(int&a, int&b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	// Ta xem i là nút cha
	void MaxHeapify(int i)
	{
		int left = 2 * (i + 1) - 1;
		int right = 2 * (i + 1);
		int max;

		// Tìm nút cha lớn nhất
		if (left < n && a[left] > a[i]) max = left;
		else max = i;
		if (right < n && a[right] > a[max]) max = right;

		if (i != max)
		{
			swap(a[i], a[max]);
			MaxHeapify(max); // Đệ quy với nút cha lần này là max
		}
	}

	void BuildHeap()
	{
		// Xây dựng heap chỉ lặp nửa so với dãy mảng
		// Do ta cần xây dựng cây nhị phân nên cần phải đi từ nhánh về gốc
		// Vì vậy mảng cần phải duyệt từ giữa (nút con) về đầu (nút gốc)
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			MaxHeapify(i);
		}
	}

	void HeapSort()
	{
		BuildHeap();
		// Lúc này a[0] là phần tử lớn nhất
		for (int i = n - 1; i > 0; i--)
		{
			swap(a[0], a[i]);
			MaxHeapify(i, );
		}
	}
	~Heapsort(){};
};