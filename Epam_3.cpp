#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <map>

using namespace std;

int main() {
	bool flag = true;
	string str, HelpStr;
	map <string, int> WordMap;//создание переменных
	cout << "Enter the string" << endl;
	getline(cin, str);//ввод строки с клавиатуры
	if (str.empty() == 1) {//проверка не пустая ли строка
		cout << "Error, empty string!" << endl;
		system("pause");
		return 0;
	}
	for (int i = 0; i < str.size(); i++) {//цикл пробегает по нашей строке перечисляя все символы
		if (str[i] != ' ' && str[i] != '!' && str[i] != '?' && str[i] != '.' && str[i] != ',') {//мы перебираем сомволы и добавляем их в нашу временную переменную
			HelpStr += str[i];//если в строке один из перечисленных выше знаков то он не добавляется и пропускается
		}
		else if(HelpStr.empty() != 1) {//здесь проверка на наличие пустой вспомогательной строки, такое бывает при двух подрят пробелах. Если строка не пустая то давляем в словарь как ключ, а значением будет количество слов
			for (auto it = WordMap.begin(); it != WordMap.end(); ++it) {//цикл пробегающий по словарю
				if (HelpStr == it->first) {//мы проверяем есть ли это слово уже в словаре
					it->second++;//если есть то увеличиваем значение ключа на единицу
				}
			}
			WordMap.insert(pair<string, int>(HelpStr, 1));//здесь мы добавляем наше слово. Проверки никакой нет, потому что перезаписать наше значение мы не можем, и если ключ уже есть то на его значение мы никак не повлияем
			HelpStr = "";//обнуляем вспомогательную строку
		}
		if (i == (str.size() - 1) && HelpStr.empty() != 1) {//здесь происходит тоже самое что и else if, только для последнего слова. Без данного if последнее слово не добавиться так как цикл заканчивается и он просто из него выйдет не добавив последне слово
			for (auto it = WordMap.begin(); it != WordMap.end(); ++it) {
				if (HelpStr == it->first) {
					it->second++;
				}
			}
			WordMap.insert(pair<string, int>(HelpStr, 1));
		}
	}
	for (auto it = WordMap.begin(); it != WordMap.end(); ++it) {//проходим по словарю и смотрим, если значение больше 1 то выводим его в консоль.
		if (it->second > 1) {
			cout << it->first << " : " << it->second << endl;
			flag = false;//если этот флаг срабатывает, это означает что повторяющихся слов нет
		}
	}
	if (flag) {//Если повторяющихся слов нет, то программа напишет об этом
		cout << "There are no duplicate words in the string.!" << endl;
		system("pause");
		return 0;
	}
	system("pause");
	return 1;
}