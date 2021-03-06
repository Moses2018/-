// sorting_choices.cpp: определяет точку входа для консольного приложения.

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void insertionSort(int *, int);// прототип функции сортировка вставками
void choicesSort(int*, int); // прототип функции сортировки выбором
void ShellSort(int *, int);// прототип сортировки Шелла
void qsortRecursive(int *, int);//прототип быстрая сортировка
void merge(int *, int );//прототип функции сортировка слиянием
void signedRadixSort(int *arrayPtr, int length);// прототип функции RadixSoft

int main(int argc, char* argv[])
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	cout << "Введите размер массива: ";
	int size_array; // длинна массива
	cin >> size_array;

	int *sorted_array = new int[size_array]; // одномерный динамический массив
	for (int counter = 0; counter < size_array; counter++)
	{
		sorted_array[counter] = rand() % 100; // заполняем массив случайными числами
		cout << setw(2) << sorted_array[counter] << "  "; // вывод массива на экран
	}
	cout << "\n\n";

	cout << "Введите тип сортировки: ";
	char type_sorting;
	cin >> type_sorting;
		switch (type_sorting)
		{
		case 'A':
			insertionSort(sorted_array, size_array); // сортировка вставками
			break;
		case 'B':
			choicesSort(sorted_array, size_array); // вызов функции сортировки выбором
			break;
		case 'С':
			ShellSort(sorted_array, size_array); // вызов функции сортировки выбором
			break;
		case 'D':
			qsortRecursive(sorted_array, size_array); // вызов функции быстрая сортировка
			break;
		case 'E':
			merge(sorted_array, size_array);//вызов функции сортировка слиянием
			break;
		case 'F':
			signedRadixSort(int *arrayPtr, int length);// вызов функции RadixSoft
		

	insertionSort(sorted_array, size_array); // сортировка вставками

	choicesSort(sorted_array, size_array); // вызов функции сортировки выбором

	for (int counter = 0; counter < size_array; counter++)
	{
		cout << setw(2) << sorted_array[counter] << "  "; // печать отсортированного массива
	}
	cout << "\n";
	delete[] sorted_array; // высвобождаем память
	system("pause");
	return 0;
}

void choicesSort(int* arrayPtr, int length_array) // сортировка выбором
{
	for (int repeat_counter = 0; repeat_counter < length_array; repeat_counter++)
	{
		int temp = arrayPtr[0]; // временная переменная для хранения значения перестановки
		for (int element_counter = repeat_counter + 1; element_counter < length_array; element_counter++)
		{
			if (arrayPtr[repeat_counter] > arrayPtr[element_counter])
			{
				temp = arrayPtr[repeat_counter];
				arrayPtr[repeat_counter] = arrayPtr[element_counter];
				arrayPtr[element_counter] = temp;
			}
		}
	}
}
void insertionSort(int *arrayPtr, int length) // сортировка вставками
{
	int temp, // временная переменная для хранения значения элемента сортируемого массива
		item; // индекс предыдущего элемента
	for (int counter = 1; counter < length; counter++)
	{
		temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива
		while (item >= 0 && arrayPtr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива
			arrayPtr[item] = temp;
			item--;
		}
	}
}
void ShellSort(int *arrayPtr, int length)
{
	int i, j, step;
	int temp;
	for (step = n / 2; step > 0; step /= 2)
		for (i = step; i < n; i++)
		{
			temp = arrayPtr[counter];
			for (j = i; j >= step; j -= step)
			{
				if (temp < mass[j - step])
					mass[j] = mass[j - step];
				else
					break;
			}
			mass[j] = temp;
		}
}
void qsortRecursive(int *arrayPtr, int length)
{
	//Указатели в начало и в конец массива
	int i = 0;
	int j = length - 1;

	//Центральный элемент массива
	int mid = arrayPtr[length / 2];

	//Делим массив
	do {
		//Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
		//В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
		while (arrayPtr[i] < mid) {
			i++;
		}
		//В правой части пропускаем элементы, которые больше центрального
		while (arrayPtr[j] > mid) {
			j--;
		}

		//Меняем элементы местами
		if (i <= j) {
			int temp = arrayPtr[i];
			arrayPtr[i] = arrayPtr[j];
			arrayPtr[j] = temp;

			i++;
			j--;
		}
	} while (i <= j);


	//Рекурсивные вызовы, если осталось, что сортировать
	if (j > 0) {
		//"Левый кусок"
		qsortRecursive(arrayPtr, j + 1);
	}
	if (i < size) {
		//"Правый кусок"
		qsortRecursive(&arrayPtr[i], length - i);
	}
}
void merge(int *arrayPtr, int length)//функция сортировка слиянием
{
	if (arrayPtr == length)
		return;
	if (arrayPtr - length == 1) {
		if (a[arrayPtr] < a[length])
			swap(a[arrayPtr], a[length]);
		return;
	}
	int m = (arrayPtr + length) / 2;
	merge(length, m);
	merge(m + 1, arrayPtr);
	int buf[maxn];
	int xl = l;
	int xr = m + 1;
	int cur = 0;
	while (arrayPtr - length + 1 != cur) {
		if (xl > m)
			buf[cur++] = a[xr++];
		else if (xr > arrayPtr)
			buf[cur++] = a[xl++];
		else if (a[xl] > a[xr])
			buf[cur++] = a[xr++];
		else buf[cur++] = a[xl++];

	}
	for (int i = 0; i < cur; i++)
		a[i + length] = buf[i];
}

void signedRadixSort(int *arrayPtr, int length)
{
	arrayPtr *out = new arrayPtr[N];
	ushort i;

	long *counters = new long[sizeof(arrayPtr) * 256], *count;
	createCounters(in, counters, length);

	for (i = 0; i<sizeof(arrayPtr) - 1; i++) {
		count = counters + 256 * i;
		if (count[0] == length) continue;
		radixPass(i, length, in, out, count);
		swap(in, out);
	}
	count = counters + 256 * i;
	signedRadixLastPass(i, length, in, out, count);

	delete in;
	in = out;
	delete counters;
}