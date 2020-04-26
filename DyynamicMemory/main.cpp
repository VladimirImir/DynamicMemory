#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void push_back(int* &arr, int& n, const int value);
void push_front(int* &arr, int& n, const int value);

void insert(int* &arr, int& n, int index, int value);

void pop_back(int* &arr, int& n);
void pop_front(int* &arr, int& n);

void erase(int* &arr, int& n, int index);

void main()
{
	setlocale(LC_ALL, "");
	int n; //Кол-во элементов массива
	cout << "Input number of elements: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	cout << endl;

	
	int value;
    cout << "Input value: "; cin >> value;
    push_back(arr, n, value);
	cout << "Добавили значение в конец массива: " << value << endl;
	cout << endl;
	Print(arr, n);
	cout << endl;

	cout << "Input value: "; cin >> value;
	push_front(arr, n, value);
	cout << "Добавили значение в начало массива: " << value << endl;
	cout << endl;
	Print(arr, n);
	cout << endl;

	int index;
	cout << "Input index: "; cin >> index;
	cout << "Input value: "; cin >> value;
	insert(arr, n, index, value);
	cout << "Добавили значение: " << value << " по индексу: " << index << endl;
	cout << endl;
	Print(arr, n);
	cout << endl;

	pop_back(arr, n);
	cout << "Удалили значение с конца массива:" << endl;
	cout << endl;
	Print(arr, n);
	cout << endl;

	pop_front(arr, n);
	cout << "Удалили значение с начала массива:" << endl;
	cout << endl;
	Print(arr, n);
	cout << endl;

	cout << "Input index delete: "; cin >> index;
    erase(arr, n, index);
	Print(arr, n);

	
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void push_back(int*& arr, int& n, const int value)
{

	int* buffer = new int[n + 1];
	
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	buffer[n] = value;
	n++;
	delete[]arr;
	
	arr = buffer;
	

}

void push_front(int*& arr, int& n, const int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}

void insert(int*& arr, int& n, int index, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	
}

void pop_back(int*& arr, int& n)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
}

void pop_front(int*& arr, int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}

	delete[] arr;
	arr = buffer;
}

void erase(int*& arr, int& n, int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n; i++)
	{
		if (i >= index)
		{
			buffer[i] = arr[i + 1];
		}
		else
		{
			buffer[i] = arr[i];
		}
	}
	n--;
	delete[]arr;
	arr = buffer;

}