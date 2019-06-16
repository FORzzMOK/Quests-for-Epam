#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stack>

using namespace std;

int main() {
	string str;
	stack <char> HelpStack;//выяснять правильность последовательности будем при помощи стека
	cout << "Enter the string" << endl;
	getline(cin, str);//создаем переменные, вводим скобочную строку с клавиатуры
	if (str.empty() == 1) {//проверяем длину последовательности
		cout << "Error, empty string!" << endl;
		system("pause");
		return 0;
	}
	for (int i = 0; i < str.size(); i++) {//цикл при помощи которого мы перебираем нашу последовательность
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {//если скобка открывающая, то мы в любом случае её добаляемв стек.
			HelpStack.push(str[i]);
		}
		else if (HelpStack.empty() != 1) {//далее, если скобка не окрывающая, то мы смотрим, если стек не пустой то мы можем что то оттуда удалить
			if (str[i] == ')' && HelpStack.top() == '(') {//мы перебираем скобки, пока не найдем подходящую и не удалим её
				HelpStack.pop();//ищем условие, что бы закрывающая скобка, была такой же как последняя в стеке.
			}
			else if (str[i] == '}' && HelpStack.top() == '{') {//если не одно условие не выполнилось, значит был добавлен другой символ, не скобка. Мы вычислим его позже, на проверке длины стека
				HelpStack.pop();
			}
			else if (str[i] == ']' && HelpStack.top() == '[') {
				HelpStack.pop();
			}
		}
		else {// это условие выполняется только в том случае если мы пытаемся добавить закрывающую скобку в пустой стек
			cout << "This string is not a valid bracket sequence." << endl;
			system("pause");
			return 0;
		}
	}
	if (HelpStack.empty() == 1) {//в итоге наш стек должен быть пустым, если это не так, значит там есть какой то символ, или не закрытая скобка.
		cout << "This string is a valid bracket sequence." << endl;//Если стек пустой то выводим что всё хорошо
		system("pause");
		return 1;
	}
	cout << "This string is not a valid bracket sequence." << endl;//если не пустой то сообщаем об ошибке
	system("pause");
	return 0;
}