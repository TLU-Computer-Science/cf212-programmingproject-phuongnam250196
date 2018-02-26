#include<iostream>

using namespace std;
#define m 100
int a[];
int n;

void swap(int&a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}

// Ta xem i là nút cha
void MaxHeapify(int a[], int n, int i)
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
		MaxHeapify(a, n, max); // Đệ quy với nút cha lần này là max
	}
}
void BuildHeap(int a[], int n)
{
	// Xây dựng heap chỉ lặp nửa so với dãy mảng
	// Do ta cần xây dựng cây nhị phân nên cần phải đi từ nhánh về gốc
	// Vì vậy mảng cần phải duyệt từ giữa (nút con) về đầu (nút gốc)
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		MaxHeapify(a, n, i);
	}
}
void HeapSort(int a[], int n)
{
	BuildHeap(a, n);
	// Lúc này a[0] là phần tử lớn nhất
	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		MaxHeapify(a, i, 0);
	}
}
void Nhap(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu a[" << i + 1 << "] = ";
		cin >> a[i];
	}
	cout << "-------------------------------------------" << endl;
}
void Xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout <<"	"<< a[i];
	}
	cout << endl;
}
int main() {
	int a[m], n;
	cout << "Nhap n vao: ";
	cin >> n;
	Nhap(a, n);
	cout << "	Day ban dau sau khi nhap la: " << endl;
	Xuat(a, n);
	cout << "	Day ban dau sau khi sap xep la: " << endl;
	HeapSort(a, n);
	Xuat(a, n);
	//HeapSort(a, n);
	return 0;
}