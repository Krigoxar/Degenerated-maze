#pragma once
class Menu
{
	char say(string String = "")
	{
		cout << String << endl;
		char i;
		i = _getch();
		return i;
	}
public:
	void greating()
	{
		system("cls");
		cout << "Вы победили спасибо за игру" << endl;
		say("Для закрытия игры нажмите любую клавишу");
	}
	int _Menu()
	{
		while (1)
		{
			system("cls");
			int chose;
			say("Для того что-бы начать нажмите любую клавишу.");
			system("cls");
			cout << "Выберите режим игры" << endl;
			cout << "1-Лабиринт с авто генерацией" << endl;
			cout << "2-Лабиринт с авто генерацией и камерой" << endl;
			cout << "3-Лабиринт с авто генерацией и туманом войны" << endl;
			cout << "4-Бомбер" << endl;
			cout << "5-Данжик" << endl;
			cout << "6-" << endl;
			cout << "7-" << endl;
			cout << "8-" << endl;
			cin >> chose;
			if (chose > 0 && chose < 6)
			{
				system("cls");
				return chose;
			}
			else
			{
				system("cls");
				cout << "Не тормоши прогу неправельным ответом. Не видешь? Ещё не готово!!!(или такого просто нет)" << endl;
				say();
			}
		}
	}
};

