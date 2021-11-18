#pragma once
class Fabrika
{
	int i = 0;
public:
	void incel_smth()
	{
		Menu menu;
		i = menu._Menu();
		if (i == 1)
		{
			Maps map(0);
			Feeld feeld(&map);
			Player_in_labirint player(&feeld);
			feeld.print();
			do
			{
				player.Move(&feeld);
				system("cls");
				feeld.print();
			} while (player.win());
			system("cls");
			i = player.win();
		}
		else if (i == 2)
		{
			Maps map(0);
			Feeld_with_cam feeld(&map);
			Player_in_labirint player(&feeld);
			feeld.print();
			do
			{
				player.Move(&feeld);
				system("cls");
				feeld.print();
			} while (player.win());
			system("cls");
			i = player.win();
		}
		else if (i == 3)
		{
			Maps map(0);
			Feeld_with_tuman feeld(&map);
			Player_in_labirint player(&feeld);
			feeld.print();
			do
			{
				player.Move(&feeld);
				system("cls");
				feeld.print();
			} while (player.win());
			system("cls");
			i = player.win();

		}
		if (i == 0)
		{
			menu.greating();
		}
		else if (i == -1)
		{

		}
	}
};

