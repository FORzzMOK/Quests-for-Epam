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

int Search(int *OurArray, int ArraySize, int SearchNumber) {// ������� ��������� ������
	int low = 0, high = ArraySize - 1;// �������� ������ ������� ������ ������
	while (low <= high) {//���� ����������� ���� ���� ������� �� �����������, ���� ��������� �������� ������ ������� �� ������ ������ �������. ���� ��� ��������� ������ �������� ����� ��� � �������
		int mid = (low + high) / 2;// ����������� ������� (�������) ������ 
		if (OurArray[mid] == SearchNumber) {//���������� ���� ������� �������� � �������, ���� ������� ���, �� ����������, ���� ��� �� �������� ������� ������
			return mid;
		}
		if (OurArray[mid] < SearchNumber) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return ArraySize;//���� �� �������, ���������� ������ �������. ����� ������� ����� ����� ������� ���������� �� ��� �� ������ �� �����, �� � ����� ���������� ������ �������, ��� ��� ��� ������ ����� ��������� �� �������� ������
}

int MinNumberIndex(int *OurArray, int Index, int SearchNumber){//��� ��� � ��� ����� ���� ��������� ���������� �������� � �������, ��� � ��������� ������� ������� �������� �������� �������, � ������� ��������� ���� ������� ��������.
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
	int SearchNumber = 0;//������� �����, 
	int ArraySize = 0;//������ �������, ����� �������� �� ����� ��������
	cout << "Enter array size" << endl;//���� � ���������� ������� �������
	cin >> ArraySize;
	cout << "Enter search number" << endl;//���� � ���������� �������� �����
	cin >> SearchNumber;
	int *OurArray = new int[ArraySize];//������� ������
	filling(OurArray, ArraySize);//��������� ������
	quicksort(OurArray, ArraySize);//��������� ������ 
	show(OurArray, ArraySize);//������� ������ � ������� (������� ����������, ������ � ���������� �������, ����� �� ������� �������)
	int Result = Search(OurArray, ArraySize, SearchNumber);// �������� ��������� �� ������� ������
	if (Result != ArraySize) { //���� ����� �������, �������� ��� ���������� ����� � �������. ���� ���, �� �������� ������ �������, � � ������� ��������� False, ������������ ��� � ������� ��� �������� �����
		int min = MinNumberIndex(OurArray, Result, SearchNumber), max = MaxNumberIndex(OurArray, Result, SearchNumber, ArraySize);//�� ���� ����� ���� �������� ��� �������, �� ��� ����� ���� �� ����
		if (min != max) {//��� �� ����� ��� �������, � ������� ��� ��������������� ������� ������� ���� ����������� � ������������ ������� � �������, � ���������� �� ���
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
