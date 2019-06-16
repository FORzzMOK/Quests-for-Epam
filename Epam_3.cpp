#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <map>

using namespace std;

int main() {
	bool flag = true;
	string str, HelpStr;
	map <string, int> WordMap;//�������� ����������
	cout << "Enter the string" << endl;
	getline(cin, str);//���� ������ � ����������
	if (str.empty() == 1) {//�������� �� ������ �� ������
		cout << "Error, empty string!" << endl;
		system("pause");
		return 0;
	}
	for (int i = 0; i < str.size(); i++) {//���� ��������� �� ����� ������ ���������� ��� �������
		if (str[i] != ' ' && str[i] != '!' && str[i] != '?' && str[i] != '.' && str[i] != ',') {//�� ���������� ������� � ��������� �� � ���� ��������� ����������
			HelpStr += str[i];//���� � ������ ���� �� ������������� ���� ������ �� �� �� ����������� � ������������
		}
		else if(HelpStr.empty() != 1) {//����� �������� �� ������� ������ ��������������� ������, ����� ������ ��� ���� ������ ��������. ���� ������ �� ������ �� ������� � ������� ��� ����, � ��������� ����� ���������� ����
			for (auto it = WordMap.begin(); it != WordMap.end(); ++it) {//���� ����������� �� �������
				if (HelpStr == it->first) {//�� ��������� ���� �� ��� ����� ��� � �������
					it->second++;//���� ���� �� ����������� �������� ����� �� �������
				}
			}
			WordMap.insert(pair<string, int>(HelpStr, 1));//����� �� ��������� ���� �����. �������� ������� ���, ������ ��� ������������ ���� �������� �� �� �����, � ���� ���� ��� ���� �� �� ��� �������� �� ����� �� ��������
			HelpStr = "";//�������� ��������������� ������
		}
		if (i == (str.size() - 1) && HelpStr.empty() != 1) {//����� ���������� ���� ����� ��� � else if, ������ ��� ���������� �����. ��� ������� if ��������� ����� �� ���������� ��� ��� ���� ������������� � �� ������ �� ���� ������ �� ������� �������� �����
			for (auto it = WordMap.begin(); it != WordMap.end(); ++it) {
				if (HelpStr == it->first) {
					it->second++;
				}
			}
			WordMap.insert(pair<string, int>(HelpStr, 1));
		}
	}
	for (auto it = WordMap.begin(); it != WordMap.end(); ++it) {//�������� �� ������� � �������, ���� �������� ������ 1 �� ������� ��� � �������.
		if (it->second > 1) {
			cout << it->first << " : " << it->second << endl;
			flag = false;//���� ���� ���� �����������, ��� �������� ��� ������������� ���� ���
		}
	}
	if (flag) {//���� ������������� ���� ���, �� ��������� ������� �� ����
		cout << "There are no duplicate words in the string.!" << endl;
		system("pause");
		return 0;
	}
	system("pause");
	return 1;
}