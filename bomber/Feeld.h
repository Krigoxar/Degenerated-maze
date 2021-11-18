#pragma once
#include <string>
#include <iostream>

using namespace std;
class Feeld
{
	
protected:
	char _feeld[100][10];
	string feeld[41];
	int player_pos[2]{ 9,7 };;
	int win_pos[2];
	
public:

	Feeld()
	{

	}

	Feeld(Maps *map_from_maps)
	{
		for (int i = 0;i < 41;i++)
		{
			
			feeld[i] = map_from_maps->import_map(i);
			if (feeld[i].find('W') != -1)
			{
				win_pos[0] = feeld[i].find('W');
				win_pos[1] = i;

			}
		}
	}
	int Get_win_pos(int i)
	{
		return win_pos[i];
	}
	void Set(int x,int y,string Char)
	{
		feeld[y].replace(x, 1, Char);
	}
	char Get(int x, int y)
	{
		return feeld[y][x];
	}
	
	void print()
	{
		for (string String : feeld)
		{
			for (int i = 0;i < 41; i++)
			{
				if (String.compare(i,1,"#") == 0)
				{
					cout << "#";
				}
				else if (String.compare(i, 1, "-") == 0)
				{
					cout << "---";
				}
				else if (String.compare(i, 1, " " ) == 0 && i % 2 == 0)
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
};
class Feeld_with_cam : public Feeld
{
protected:
	string view[15];
	void get_view()
	{
		for (int i = 0; i < 41; i++)
		{
			if (feeld[i].find('P') != -1)
			{
				if (feeld[i].find('P') < 34 && feeld[i].find('P') > 6)
				{
					player_pos[0] = feeld[i].find('P');
				}
				if (i > 6 && i < 34)
				{
					player_pos[1] = i;
				}




			}
		}
		for (int i = -7; i < 8; i++)
		{
			view[i + 7] = feeld[player_pos[1] + i].substr(player_pos[0] - 7, 15);
		}
	}

public:

	Feeld_with_cam()
	{

	}

	Feeld_with_cam(Maps* map_from_maps)
	{
		for (int i = 0; i < 41; i++)
		{

			feeld[i] = map_from_maps->import_map(i);
			if (feeld[i].find('W') != -1)
			{
				win_pos[0] = feeld[i].find('W');
				win_pos[1] = i;

			}
		}
	}
	void print()
	{
		get_view();
		for (string String : view)
		{
			for (int i = 0; i < 15; i++)
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
};
class Feeld_with_tuman : public Feeld_with_cam
{
	string feeld_of_tuman[41];
	string feeld_of_tuman1;
	void get_feeld_of_tuman()
	{
		for (int i = 0; i < 41; i++)
		{
			if (feeld[i].find('P') != -1)
			{
				if (feeld[i].find('P') < 34 && feeld[i].find('P') > 6)
				{
					player_pos[0] = feeld[i].find('P');
				}
				if (i > 6 && i < 34)
				{
					player_pos[1] = i;
				}




			}
		}

		for (int k = -7; k < 8; k++)
		{
			for (int j = -7; j < 8; j++)
			{
				feeld_of_tuman[player_pos[1] + k][player_pos[0] + j] = '1';
			}
		}
	}
public:

	Feeld_with_tuman(Maps* map_from_maps)
	{
		for (int i = 0; i < 41; i++)
		{

			feeld[i] = map_from_maps->import_map(i);
			if (feeld[i].find('W') != -1)
			{
				win_pos[0] = feeld[i].find('W');
				win_pos[1] = i;

			}
		}
		for (int k = 0; k < 41; k++)
		{
			
			feeld_of_tuman[k] = "000000000000000000000000000000000000000000";
			
		}
	}

	void print()
	{
		get_feeld_of_tuman();
		int j = -1;
		for (string String : feeld)
		{
			j++;
			for (int i = 0; i < 41; i++)
			{
				if (feeld_of_tuman[j].compare(i, 1, "1") == 0)
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
				else if (String.compare(i, 1, "#") == 0)
				{
					cout << " ";
				}
				else if (String.compare(i, 1, "-") == 0)
				{
					cout << "   ";
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
					cout << " ";
				}
				else
				{
					cout << "   ";
				}
				
			}
			cout << endl;
		}
	}

};

