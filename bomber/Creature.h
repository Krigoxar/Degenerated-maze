#pragma once
#include <string>

using namespace std;
class Creature
{
protected:
	int hp=0;
	int curent_position[2]{ 9,0 };//добавить функционал для точек спауна
	int prew_position[2]{ 9,0 };
	bool is_chenged = 0;
public:
	
};
class Player : public Creature
{

	string sign_under_player[2]{"_","_"};
public:

	void Move(Feeld* feeld)
	{
		char key = ' ';
		prew_position[0] = curent_position[0]; prew_position[1] = curent_position[1];
		key = _getch();
		int is_chenged = 0;
		switch (key)
		{
		case 'w':

			if (curent_position[1] != 0 && feeld->Get(curent_position[0] * 2 + 1, curent_position[1] * 2) != '-')
			{
				curent_position[1] -= 1;
				is_chenged = 1;
			}
			break;
		case 's':

			if (curent_position[1] != 19 && feeld->Get(curent_position[0] * 2 + 1, curent_position[1] * 2 + 2) != '-')
			{
				curent_position[1] += 1;
				is_chenged = 1;
			}
			break;
		case 'a':
			if (curent_position[0] != 0 && feeld->Get(curent_position[0] * 2, curent_position[1] * 2 + 1) != '|')
			{
				curent_position[0] -= 1;
				is_chenged = 1;
			}
			break;
		case 'd':
			if (curent_position[0] != 19 && feeld->Get(curent_position[0] * 2 + 2, curent_position[1] * 2 + 1) != '|')
			{
				curent_position[0] += 1;
				
				is_chenged = 1;
			}
			break;
		default:
			break;
		}
		sign_under_player[0] = feeld->Get(curent_position[0] * 2 + 1, curent_position[1] * 2 + 1);
		feeld->Set(curent_position[0] * 2 + 1, curent_position[1] * 2 + 1, "P");
		
		

		if (is_chenged)
		{
			feeld->Set(prew_position[0] * 2 + 1, prew_position[1] * 2 + 1, sign_under_player[1]);
			sign_under_player[1] = sign_under_player[0];
		}

		
	}
};
class Player_in_labirint : public Player
{
	int win_pos[2];
public:
	Player_in_labirint(Feeld* feeld)
	{
		win_pos[1] = feeld->Get_win_pos(1) / 2 ;
		win_pos[0] = feeld->Get_win_pos(0) / 2 ;
	}
	int win()
	{
		if (curent_position[0] == win_pos[0] && curent_position[1] == win_pos[1])
		{
			return false;
		}
		return true;
	}
};

