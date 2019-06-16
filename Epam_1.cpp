#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void quicksort(int *OurArray, int ArraySize) {//функция сортировки подсчетом. Преимущество данной сортировки в линейной асимптотике. Её недостаток в том что вспомогательный массив, в иделае должен быть значительно меньше основного массива
	int min = OurArray[0], max = OurArray[0], SizeHelpArray = 0, j = 0;//так же, вспомогательный массив может занимать очень много памяти, но для нашей ситуации сортировка подходит, так как вспомогательный массив будет не больше 200 значений.
	for (int i = 0; i < ArraySize; i++) {//находим минимум и максимум для того что бы создать вспомогательный массив
		if (OurArray[i] > max) {
			max = OurArray[i];
		}
		if (OurArray[i] < min) {
			min = OurArray[i];
		}
	}
	SizeHelpArray = max - min + 1;//размер вспомогательного массива
	int *HelpArroy = new int[SizeHelpArray];//создаем вспомогательный массив и заполняем его нулями
	for (int i = 0; i < SizeHelpArray; i++) {
		HelpArroy[i] = 0;
	}
	for (int i = 0; i < ArraySize; i++) {//подсчитываем числа в основном массиве
		HelpArroy[OurArray[i] - min]++;//делаем смещение на минимум, для того что бы минимульное значение соответствовало нулевому индексу мссива
	}
	for (int i = 0; i < SizeHelpArray; i++) {//переписываем наш массив согласно подсчитанным числам из вспомогательного в основной
		while (HelpArroy[i] != 0) {
			OurArray[j] = i + min;
			HelpArroy[i]--;
			j++;
		}
	}
}

void show(int *OurArray, int ArraySize) {//функция выводит массив на экран, в строку по 20 чисел для удобства чтения
	for (int i = 0; i < ArraySize; i++) {
		cout << OurArray[i] << " ";
		if (i % 20 == 0 && i != 0) {
			cout << endl;
		}
	}
	cout << endl;
}

void filling(int *OurArray, int ArraySize) {//заполняет массив случайными числами от 0 до 200
	srand(time(NULL));
	for (int i = 0; i < ArraySize; i++) {
		OurArray[i] = rand() % 200;//Это число грубо говоря и есть раззмер вспомогательного массива, так как минимум обычно равен 0, или около того, а максимум 200 или близко к этому
	}//и размер вспомогательного массива, это разница максимума и минимума
}

int main() {
	int ArraySize = 100;//размер нашего массива
	int *OurArray = new int[ArraySize];// Размер массива фиксированный, 100 элементов
	filling(OurArray, ArraySize);
	cout << "This is not a sorted array." << endl;
	show(OurArray, ArraySize);
	quicksort(OurArray, ArraySize);
	cout << "This is a sorted array." << endl;
	show(OurArray, ArraySize);
	system("pause");
}