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
		cout << "�� �������� ������� �� ����" << endl;
		say("��� �������� ���� ������� ����� �������");
	}
	int _Menu()
	{
		while (1)
		{
			system("cls");
			int chose;
			say("��� ���� ���-�� ������ ������� ����� �������.");
			system("cls");
			cout << "�������� ����� ����" << endl;
			cout << "1-�������� � ���� ����������" << endl;
			cout << "2-�������� � ���� ���������� � �������" << endl;
			cout << "3-�������� � ���� ���������� � ������� �����" << endl;
			cout << "4-������" << endl;
			cout << "5-������" << endl;
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
				cout << "�� ������� ����� ������������ �������. �� ������? ��� �� ������!!!(��� ������ ������ ���)" << endl;
				say();
			}
		}
	}
};

