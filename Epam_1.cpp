#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void quicksort(int *OurArray, int ArraySize) {//������� ���������� ���������. ������������ ������ ���������� � �������� �����������. Ÿ ���������� � ��� ��� ��������������� ������, � ������ ������ ���� ����������� ������ ��������� �������
	int min = OurArray[0], max = OurArray[0], SizeHelpArray = 0, j = 0;//��� ��, ��������������� ������ ����� �������� ����� ����� ������, �� ��� ����� �������� ���������� ��������, ��� ��� ��������������� ������ ����� �� ������ 200 ��������.
	for (int i = 0; i < ArraySize; i++) {//������� ������� � �������� ��� ���� ��� �� ������� ��������������� ������
		if (OurArray[i] > max) {
			max = OurArray[i];
		}
		if (OurArray[i] < min) {
			min = OurArray[i];
		}
	}
	SizeHelpArray = max - min + 1;//������ ���������������� �������
	int *HelpArroy = new int[SizeHelpArray];//������� ��������������� ������ � ��������� ��� ������
	for (int i = 0; i < SizeHelpArray; i++) {
		HelpArroy[i] = 0;
	}
	for (int i = 0; i < ArraySize; i++) {//������������ ����� � �������� �������
		HelpArroy[OurArray[i] - min]++;//������ �������� �� �������, ��� ���� ��� �� ����������� �������� ��������������� �������� ������� ������
	}
	for (int i = 0; i < SizeHelpArray; i++) {//������������ ��� ������ �������� ������������ ������ �� ���������������� � ��������
		while (HelpArroy[i] != 0) {
			OurArray[j] = i + min;
			HelpArroy[i]--;
			j++;
		}
	}
}

void show(int *OurArray, int ArraySize) {//������� ������� ������ �� �����, � ������ �� 20 ����� ��� �������� ������
	for (int i = 0; i < ArraySize; i++) {
		cout << OurArray[i] << " ";
		if (i % 20 == 0 && i != 0) {
			cout << endl;
		}
	}
	cout << endl;
}

void filling(int *OurArray, int ArraySize) {//��������� ������ ���������� ������� �� 0 �� 200
	srand(time(NULL));
	for (int i = 0; i < ArraySize; i++) {
		OurArray[i] = rand() % 200;//��� ����� ����� ������ � ���� ������� ���������������� �������, ��� ��� ������� ������ ����� 0, ��� ����� ����, � �������� 200 ��� ������ � �����
	}//� ������ ���������������� �������, ��� ������� ��������� � ��������
}

int main() {
	int ArraySize = 100;//������ ������ �������
	int *OurArray = new int[ArraySize];// ������ ������� �������������, 100 ���������
	filling(OurArray, ArraySize);
	cout << "This is not a sorted array." << endl;
	show(OurArray, ArraySize);
	quicksort(OurArray, ArraySize);
	cout << "This is a sorted array." << endl;
	show(OurArray, ArraySize);
	system("pause");
}