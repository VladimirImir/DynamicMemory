#include<iostream>
using namespace std;

template<typename T>void FillRand(T arr[], T n);
template<typename T>void Print(T arr[], T n);

template<typename T>void push_back(T* &arr, T& n, T value);
template<typename T>void push_front(T* &arr, T& n, T value);

template<typename T>void insert(T* &arr, T& n, T index, T value);

template<typename T>void pop_back(T* &arr, T& n);
template<typename T>void pop_front(T* &arr, T& n);

template<typename T>void erase(T* &arr, T& n, T index);

void main()
{
	setlocale(LC_ALL, "");
	int n;
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

template<typename T>void FillRand(T arr[], T n)
{
	for (T i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

template<typename T>void Print(T arr[], T n)
{
	for (T i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

template<typename T>void push_back(T*& arr, T& n, T value)
{

	T* buffer = new T[n + 1];
	
	for (T i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	buffer[n] = value;
	n++;
	delete[]arr;
	
	arr = buffer;
	

}

template<typename T>void push_front(T*& arr, T& n, T value)
{
	T* buffer = new T[n + 1]{};
	for (T i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}

template<typename T>void insert(T*& arr, T& n, T index, T value)
{
	T* buffer = new T[n + 1]{};
	for (T i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (T i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	
}

template<typename T>void pop_back(T*& arr, T& n)
{
	T* buffer = new T[n - 1]{};
	for (T i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
}

template<typename T>void pop_front(T*& arr, T& n)
{
	T* buffer = new T[--n]{};
	for (T i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}

	delete[] arr;
	arr = buffer;
}

template<typename T>void erase(T*& arr, T& n, T index)
{
	T* buffer = new T[n - 1];
	for (T i = 0; i < n; i++)
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