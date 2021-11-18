#pragma once
#include <string>

using namespace std;
class Maps
{
	bool end = 1;
	int start_pos[2] = { 9,0 };
	int const map_size = 41;
	int curent_position_of_gen[2] = { start_pos[0],start_pos[1] };
	int prew_position_of_gen[2] = { start_pos[0],start_pos[1] };
	int list_of_sticks[2][1000];
	int sticknumer = -1;
	string bufer[41];
	bool is_chenged;
	string sign_under_gen[2]{ "_","_" };
	string map[3][41]
	{
	{
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	},
	{
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	"                                         ",
	"# # # # # # # # # # # # # # # # # # # # #",
	},
	{
	}
	};
	
	char Get(int x, int y)
	{
		return map[0][y][x];
	}
	void Set(int x, int y, string Char)
	{
		map[0][y].replace(x, 1, Char);
	}
	bool zastral()
	{
		if (curent_position_of_gen[1] != 0 && this->Get(curent_position_of_gen[0] * 2 + 1, (curent_position_of_gen[1] - 1) * 2 + 1) != '_')
		{
			return 0;
		}
		if (curent_position_of_gen[1] != 19 && this->Get(curent_position_of_gen[0] * 2 + 1, (curent_position_of_gen[1] + 1) * 2 + 1) != '_')
		{
			return 0;
		}
		if (curent_position_of_gen[0] != 0 && this->Get((curent_position_of_gen[0] - 1) * 2 + 1, curent_position_of_gen[1] * 2 + 1) != '_')
		{
			return 0;
		}
		if (curent_position_of_gen[0] != 19 && this->Get((curent_position_of_gen[0] + 1) * 2 + 1, curent_position_of_gen[1] * 2 + 1) != '_')
		{
			return 0;
		}
		return 1;

	}
	void map_set_start()
	{
		for (int i = 0; i < map_size; i++)
		{
			map[0][i] = map[1][i];
		}
	}
	void do_qbe(char Char)
	{

		this->Set(curent_position_of_gen[0] * 2 + 1, curent_position_of_gen[1] * 2 + 1, "_");
		switch (Char)
		{
		case 'u':
		{
			this->Set(curent_position_of_gen[0] * 2 + 1, curent_position_of_gen[1] * 2 + 2, " ");
			this->Set(curent_position_of_gen[0] * 2 + 2, curent_position_of_gen[1] * 2 + 1, "|");
			this->Set(curent_position_of_gen[0] * 2, curent_position_of_gen[1] * 2 + 1, "|");
			this->Set(curent_position_of_gen[0] * 2 + 1, curent_position_of_gen[1] * 2, "-");
			break;
		}
		case 'd':
		{
			this->Set(curent_position_of_gen[0] * 2 + 1, curent_position_of_gen[1] * 2 + 2, "-");
			this->Set(curent_position_of_gen[0] * 2 + 2, curent_position_of_gen[1] * 2 + 1, "|");
			this->Set(curent_position_of_gen[0] * 2, curent_position_of_gen[1] * 2 + 1, "|");
			this->Set(curent_position_of_gen[0] * 2 + 1, curent_position_of_gen[1] * 2, " ");
			break;
		}
		case 'l':
		{
			this->Set(curent_position_of_gen[0] * 2 + 1, curent_position_of_gen[1] * 2 + 2, "-");
			this->Set(curent_position_of_gen[0] * 2 + 2, curent_position_of_gen[1] * 2 + 1, " ");
			this->Set(curent_position_of_gen[0] * 2, curent_position_of_gen[1] * 2 + 1, "|");
			this->Set(curent_position_of_gen[0] * 2 + 1, curent_position_of_gen[1] * 2, "-");
			break;
		}
		case 'r':
		{
			this->Set(curent_position_of_gen[0] * 2 + 1, curent_position_of_gen[1] * 2 + 2, "-");
			this->Set(curent_position_of_gen[0] * 2 + 2, curent_position_of_gen[1] * 2 + 1, "|");
			this->Set(curent_position_of_gen[0] * 2, curent_position_of_gen[1] * 2 + 1, " ");
			this->Set(curent_position_of_gen[0] * 2 + 1, curent_position_of_gen[1] * 2, "-");
			break;
		}
		default:
			break;
		}
	}
	void rand_turn()
	{

		int randnum1 = rand() % 4 + 1;
		switch (randnum1)
		{
		case 1:
		{
			if (curent_position_of_gen[1] != 0 && this->Get(curent_position_of_gen[0] * 2 + 1, (curent_position_of_gen[1] - 1) * 2 + 1) == ' ')
			{

				curent_position_of_gen[1] -= 1;
				is_chenged = 1;
				do_qbe('u');
			}
			break;
		}
		case 2:
		{
			if (curent_position_of_gen[1] != 19 && this->Get(curent_position_of_gen[0] * 2 + 1, (curent_position_of_gen[1] + 1) * 2 + 1) == ' ')
			{

				curent_position_of_gen[1] += 1;
				is_chenged = 1;
				do_qbe('d');
			}
			break;
		}
		case 3:
		{
			if (curent_position_of_gen[0] != 0 && this->Get((curent_position_of_gen[0] - 1) * 2 + 1, curent_position_of_gen[1] * 2 + 1) == ' ')
			{

				curent_position_of_gen[0] -= 1;
				is_chenged = 1;
				do_qbe('l');
			}
			break;
		}
		case 4:
		{
			if (curent_position_of_gen[0] != 19 && this->Get((curent_position_of_gen[0] + 1) * 2 + 1, curent_position_of_gen[1] * 2 + 1) == ' ')
			{

				curent_position_of_gen[0] += 1;
				is_chenged = 1;
				do_qbe('r');
			}
			break;
		}
		default:
			break;
		}
	}
	void gen_main_tunel()
	{
		while (curent_position_of_gen[1] != 19)
		{
			rand_turn();

			int randnum2 = rand() % 5 + 1;
			if (randnum2 == 1 && curent_position_of_gen[1] != 19)
			{
				sticknumer++;
				list_of_sticks[0][sticknumer] = curent_position_of_gen[0];
				list_of_sticks[1][sticknumer] = curent_position_of_gen[1];
			}
			if (zastral())
			{
				for (int i = sticknumer; i >-1;i--)
				{
					list_of_sticks[0][i] = 0;
					list_of_sticks[1][i] = 0;
				}
				sticknumer = -1;
				curent_position_of_gen[0] = start_pos[0];
				curent_position_of_gen[1] = start_pos[1];
				map_set_start();
			}
		}
	}
	void gen_stick(int stick_num,int u)
	{
		curent_position_of_gen[0] = list_of_sticks[0][stick_num];
		curent_position_of_gen[1] = list_of_sticks[1][stick_num];
		for(int i = rand() % u + 1;0<i;i--)
		{
			if (!zastral())
			{
				end = 1;
				rand_turn();
				int randnum2 = rand() % 7 + 1;
				if (randnum2 == 1)
				{
					sticknumer++;
					list_of_sticks[0][sticknumer] = curent_position_of_gen[0];
					list_of_sticks[1][sticknumer] = curent_position_of_gen[1];
				}
			}
		}
	}
	void rand_turn_test()
	{
		print_test();
		char key = ' ';
		key = _getch();
		int randnum1 = rand() % 4 + 1;
		switch (randnum1)
		{
		case 1:
		{
			if (curent_position_of_gen[1] != 0 && this->Get(curent_position_of_gen[0] * 2 + 1, (curent_position_of_gen[1] - 1) * 2 + 1) != '_')
			{

				curent_position_of_gen[1] -= 1;
				is_chenged = 1;
				do_qbe('u');
			}
			break;
		}
		case 2:
		{
			if (curent_position_of_gen[1] != 19 && this->Get(curent_position_of_gen[0] * 2 + 1, (curent_position_of_gen[1] + 1) * 2 + 1) != '_')
			{

				curent_position_of_gen[1] += 1;
				is_chenged = 1;
				do_qbe('d');
			}
			break;
		}
		case 3:
		{
			if (curent_position_of_gen[0] != 0 && this->Get((curent_position_of_gen[0] - 1) * 2 + 1, curent_position_of_gen[1] * 2 + 1) != '_')
			{

				curent_position_of_gen[0] -= 1;
				is_chenged = 1;
				do_qbe('l');
			}
			break;
		}
		case 4:
		{
			if (curent_position_of_gen[0] != 19 && this->Get((curent_position_of_gen[0] + 1) * 2 + 1, curent_position_of_gen[1] * 2 + 1) != '_')
			{

				curent_position_of_gen[0] += 1;
				is_chenged = 1;
				do_qbe('r');
			}
			break;
		}
		default:
			break;
		}
	}
	void print_test()
	{
		system("cls");
		char key = ' ';
		key = _getch();
		for (string String : map[0])
		{
			for (int i = 0; i < 41; i++)
			{
				if (String.compare(i, 1, "#") == 0)
				{
					cout << "#";
				}
				else if (String.compare(i, 1, "-") == 0)
				{
					cout << "---";
				}
				else if (String.compare(i, 1, " ") == 0 && i % 2 == 0)
				{
					cout << " ";
				}
				else if (String.compare(i, 1, " ") == 0 && i % 2 == 1)
				{
					cout << "   ";
				}
				else if (String.compare(i, 1, "|") == 0)
				{
					cout << "|";
				}
				else
				{
					cout << " " << String.substr(i, 1) << " ";
				}
			}
			cout << endl;
		}
	}
public:
	Maps(int i)
	{
		gen_map();
		for (int j = 0;41 > j;j++)
		{
			
			bufer[j] = map[i][j];
		}
	}
	void gen_map()
	{ 
		srand(time(0));
		gen_main_tunel();
		int sticknumnum[2] = {0,0};
		this->Set(curent_position_of_gen[0] * 2 + 1, curent_position_of_gen[1] * 2 + 1, "W");
		while (end)
		{
			sticknumnum[0] = sticknumer;
			end = 0;
			for (int i = sticknumer; i >= sticknumnum[1]; i--)
			{
				gen_stick(i,30);
			}
			sticknumnum[1] = sticknumnum[0];
		}
		cout << "вот столько кординат палок:" << sticknumer << endl;
		this->Set(start_pos[0]*2+1, start_pos[1] * 2 + 1, "P");
		
	}
	string import_map(int i)
	{
		return bufer[i];
	}
	
};

