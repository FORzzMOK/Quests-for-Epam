#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int factorial(int num) {//������� ������������� ���������, �������� ��� ������ ��������
	if (num > 1) {//���� ���� ����� ������ �������, �� �� �������� ���� ����� �� ��������� ������ �����, �� �� ������� ������
		return (num * factorial(num - 1));
	}
	if (num == 1) {//��������� �������, � ����� ����� ������� ���������� ���������, ������ ������� � �������� ������ 
		return 1;
	}
	if (num == 0) {// ��� �� �������������� ��� ���������� ��� ������ 0, ����� �������� 0
		return 0;
	}
	else {//��� �� �������������� ��� �� ������ �������������, ��� ������� �����.
		return 3;//������������ ����� ������ ��� ����������� ��� �� �� ����� ��������� ���������. ������������ ������ 3, ������ ��� ��� ������ ����� ������� �� ����� ���� ��������� ���������� ������ �����.
	}
}

int main() {
	int num = 0;
	cout << "Enter the number" << endl;
	cin >> num;//������ ���� ������� � ����������
	int FactorialNum = factorial(num);//�������� ���� �������
	if (FactorialNum == 3) {//���� ���������� 3, ������ �� �� ����� ��������� ��������� ���������� �����
		cout << "False" << endl;//����� false
	}
	else {//���� ������������ ����� �� 3, �� ������� �������� ����������
		cout << "Factorial of number " << num << " is " << FactorialNum << endl;
	}
	system("pause");
	return 1;
}