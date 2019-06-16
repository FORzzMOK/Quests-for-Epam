#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void filling(int *OurArray, int ArraySize) {
	srand(time(NULL));
	for (int i = 0; i < ArraySize; i++) {
		OurArray[i] = rand() % 200;
	}
}

void show(int *OurArray, int ArraySize) {
	for (int i = 0; i < ArraySize; i++) {
		cout << i << " = " << OurArray[i] << endl;
	}
}

void quicksort(int *OurArray, int ArraySize) {
	int min = OurArray[0], max = OurArray[0], SizeHelpArray = 0, j = 0;
	for (int i = 0; i < ArraySize; i++) {
		if (OurArray[i] > max) {
			max = OurArray[i];
		}
		if (OurArray[i] < min) {
			min = OurArray[i];
		}
	}
	cout << "min and max = " << min << " " << max << endl;
	SizeHelpArray = max - min + 1;
	int *HelpArroy = new int[SizeHelpArray];
	for (int i = 0; i < SizeHelpArray; i++) {
		HelpArroy[i] = 0;
	}
	for (int i = 0; i < ArraySize; i++) {
		HelpArroy[OurArray[i] - min]++;
	}
	for (int i = 0; i < SizeHelpArray; i++) {
		while (HelpArroy[i] != 0) {
			OurArray[j] = i + min;
			HelpArroy[i]--;
			j++;
		}
	}
}

int Search(int *OurArray, int ArraySize, int SearchNumber) {// функция бинарного поиска
	int low = 0, high = ArraySize - 1;// значения хранят границы нашего поиска
	while (low <= high) {//цикл выполняется пока наши границы не пересекутся, пока численное значение нижней границы не станет больше верхней. Если это произошло значит искомого числа нет в массиве
		int mid = (low + high) / 2;// высчитываем средний (опорный) элемен 
		if (OurArray[mid] == SearchNumber) {//сравниваем наше среднне значение с искомым, если находим его, то возвращаем, если нет то изменяет границы поиска
			return mid;
		}
		if (OurArray[mid] < SearchNumber) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return ArraySize;//если не находим, возвращает размер массива. Можно вернуть любое число которое обозначало бы что мы ничего не нашли, но я решил возвращать размер массива, так как это первое число выходящее за диапазон поиска
}

int MinNumberIndex(int *OurArray, int Index, int SearchNumber){//так как у нас может быть несколько одинаковых значений в массиве, эта и следующая функция находят диапазон индексов массива, в которых находится наше искомое значение.
	int min = Index;
	for (int i = Index; i >= 0; i--) {
		if (OurArray[i] == SearchNumber) {
			min = i;
		}
		else {
			break;
		}
	}
	return min;
}
int MaxNumberIndex(int *OurArray, int Index, int SearchNumber, int ArraySize) {
	int max = Index;
	for (int i = Index; i <= ArraySize; i++) {
		if (OurArray[i] == SearchNumber) {
			max = i;
		}
		else {
			break;
		}
	}
	return max;
}
int main() {
	int SearchNumber = 0;//искомое число, 
	int ArraySize = 0;//размер массива, можно изменить на любое значение
	cout << "Enter array size" << endl;//Ввод с клавиатуры размера массива
	cin >> ArraySize;
	cout << "Enter search number" << endl;//Ввод с клавиатуры искомого числа
	cin >> SearchNumber;
	int *OurArray = new int[ArraySize];//создаем массив
	filling(OurArray, ArraySize);//заполняем массив
	quicksort(OurArray, ArraySize);//сортируем массив 
	show(OurArray, ArraySize);//выводим массив в консоль (функции сортировки, вывода и заполнения массива, взяты из первого задания)
	int Result = Search(OurArray, ArraySize, SearchNumber);// получаем результат из функции поиска
	if (Result != ArraySize) { //если число найдено, вернется его порядковый номер в массиве. Если нет, то вернется размер массива, и в консоль выведется False, обозначающее что в массиве нет искомого числа
		int min = MinNumberIndex(OurArray, Result, SearchNumber), max = MaxNumberIndex(OurArray, Result, SearchNumber, ArraySize);//На этом этапе наше значение уже найдено, но оно может быть не одно
		if (min != max) {//что бы найти все индексы, я написал две вспомогательные функции которые ищут минимальный и максимальный индексы в массиве, и показывают их нам
			cout << "Our number is in the array range of " << min << " to " << max << endl;
		}
		else {
			cout << "Our number is in the array under " << Result << " index " << endl;
		}
		system("pause");
		return 1;
	}
	else {
		cout << "False" << endl;
		system("pause");
		return 0;
	}
}
