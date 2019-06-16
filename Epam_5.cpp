#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stack>

using namespace std;

int main() {
	string str;
	stack <char> HelpStack;//�������� ������������ ������������������ ����� ��� ������ �����
	cout << "Enter the string" << endl;
	getline(cin, str);//������� ����������, ������ ��������� ������ � ����������
	if (str.empty() == 1) {//��������� ����� ������������������
		cout << "Error, empty string!" << endl;
		system("pause");
		return 0;
	}
	for (int i = 0; i < str.size(); i++) {//���� ��� ������ �������� �� ���������� ���� ������������������
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {//���� ������ �����������, �� �� � ����� ������ � ��������� ����.
			HelpStack.push(str[i]);
		}
		else if (HelpStack.empty() != 1) {//�����, ���� ������ �� ����������, �� �� �������, ���� ���� �� ������ �� �� ����� ��� �� ������ �������
			if (str[i] == ')' && HelpStack.top() == '(') {//�� ���������� ������, ���� �� ������ ���������� � �� ������ �
				HelpStack.pop();//���� �������, ��� �� ����������� ������, ���� ����� �� ��� ��������� � �����.
			}
			else if (str[i] == '}' && HelpStack.top() == '{') {//���� �� ���� ������� �� �����������, ������ ��� �������� ������ ������, �� ������. �� �������� ��� �����, �� �������� ����� �����
				HelpStack.pop();
			}
			else if (str[i] == ']' && HelpStack.top() == '[') {
				HelpStack.pop();
			}
		}
		else {// ��� ������� ����������� ������ � ��� ������ ���� �� �������� �������� ����������� ������ � ������ ����
			cout << "This string is not a valid bracket sequence." << endl;
			system("pause");
			return 0;
		}
	}
	if (HelpStack.empty() == 1) {//� ����� ��� ���� ������ ���� ������, ���� ��� �� ���, ������ ��� ���� ����� �� ������, ��� �� �������� ������.
		cout << "This string is a valid bracket sequence." << endl;//���� ���� ������ �� ������� ��� �� ������
		system("pause");
		return 1;
	}
	cout << "This string is not a valid bracket sequence." << endl;//���� �� ������ �� �������� �� ������
	system("pause");
	return 0;
}