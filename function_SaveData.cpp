void SaveData_mini()
{
	string Name;
	SetColor(7);
	int m = 10;
	int n = 30;
	int x = (WIDTH_WALL / 2);
	int y = (WIDTH_WALL / 2) - 30;
	for (int i = 0; i < m; i++)
	{
		GotoXY(x, y + i);
		for (int j = 0; j < n; j++)
		{
			if (i == 0)
			{
				cout << (char)219;

			}
			else if (i == m - 1)
			{
				cout << (char)219;
			}
			else if (j == 0 || j == n - 1)
			{
				cout << (char)219;
			}
			else
				cout << " ";
		}
	}
	GotoXY(x + 9, y + 2);
	cout << "Save and Exit:";
	GotoXY(x + 14, y + 7);
	HighLightText(3, ok);
	GotoXY(x + 3, y + 4);
	cout << "Name:";
	do {
		GotoXY(x + 9, y + 4);
		cin >> Name;
		GotoXY(x + 3, y + 4);
		if (ExistedName(Name) == true)
			cout << "Name is existed....Retype!";
	} while (ExistedName(Name));
	for (int i = 0; i < m; i++)
	{
		GotoXY(x, y + i);
		for (int j = 0; j < n; j++)
		{
			if (i == 0)
				cout << " ";
			else if (i == m - 1)
				cout << " ";
			else if (j == 0 || j == n - 1)
				cout << " ";
			else
				cout << " ";
		}
	}
	ofstream f(".\\Users\\" + Name);
	ofstream fo;
	fo.open("username.txt", ios::app);
	fo << Name << endl;
	fo.close();
	f << snakdis;
	f << snake.size();
	for (int i = 0; i < snake.size(); i++)
	{
		f << snake[i].x << "     " << snake[i].y << endl;
	}
	f << sc;
	f << FOOD_INDEX << endl;
	f << food[FOOD_INDEX].x << " " << food[FOOD_INDEX].y;
	f << Extence_Gate;
	if (Extence_Gate)
	{
		f << gate[0].x << "   " << gate[0].y;
	}
	f << SPEED;
	f << MOVING;
	f << CHAR_LOCK;
	f.close();
	NewLength.name = Name;
	NewLength.length = snake.size();
	NewHighLength();
	SortHighLength();
}

bool ExistedName(string Name)
{
	ifstream f_user;
	f_user.open("username.txt");
	string tmp;

	while (f_user >> tmp)
		if (tmp == Name)
		{
			f_user.close();
			return true;
		}
	f_user.close();
	return false;
}

void DeleteBox()
{
	int a = 10;
	int b = 30;
	int x = (WIDTH_WALL / 2);
	int y = (HEIGH_WALL / 2) - 30;

	for (int i = 0; i <a ; i++)
	{
		GotoXY(x, y + i);
		for (int j = 0; j < b; j++)
		{
			if (i == 0)
				cout << " ";
			else if (i == a - 1)
				cout << " ";
			else if (j == 0 || j == b- 1)
				cout << " ";
			else
				cout <<" ";
		}
	}
}
void LoadData_mini()
{
	string Name = loadName();
	/*SetColor(7);
	int m = 10;
	int n = 30;
	int x = (WIDTH_WALL / 2);
	int y = (WIDTH_WALL / 2) - 30;
	for (int i = 0; i < m; i++)
	{
		GotoXY(x, y + i);
		for (int j = 0; j < n; j++)
		{
			if (i == 0)
			{
				cout << (char)219;

			}
			else if (i == m - 1)
			{
				cout << (char)219;
			}
			else if (j == 0 || j == n - 1)
			{
				cout << (char)219;
			}
			else
				cout << " ";
		}
	}
	GotoXY(x + 9, y + 2);
	cout << "Loading Data:";
	GotoXY(x + 14, y + 7);
	HighLightText(3, ok);
	GotoXY(x + 3, y + 4);
	cout << "Name:";
	do {
		
		GotoXY(x + 9, y + 4);
		cin >> Name;
		GotoXY(x + 3, y + 4);
		if (!ExistedName(Name))
			cout << "No Data!.....";
	} while (!ExistedName(Name));
	for (int i = 0; i < m; i++)
	{
		GotoXY(x, y + i);
		for (int j = 0; j < n; j++)
		{
			if (i == 0)
				cout << " ";
			else if (i == m - 1)
				cout << " ";
			else if (j == 0 || j == n - 1)
				cout << " ";
			else
				cout << " ";
		}
	}*/
	/*for (int i = 0; i < snake.size(); i++)
	{
		GotoXY(snake[i].x, snake[i].y);
		cout << " ";
	}
	GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);

	cout << " ";*/
	ifstream fi(".\\users\\" + Name);
	//fi >> snake.size();
	fi >> snakdis;
	fi >> sc;
	fi>> Extence_Gate;
	GotoXY(91, 16);
	cout << sc;
	for (int i = 0; i < snake.size(); i++)
	{
		fi >> snake[i].x >> snake[i].y;
	}
	
		fi >> food[FOOD_INDEX].x >> food[FOOD_INDEX].y;

		fi >> gate[0].x >> gate[0].y;
		//fi >> index_id;
		fi >> SPEED;
		fi >> MOVING;
		fi >> CHAR_LOCK;
		fi.close();
}
char* loadName()
{
cout << R"(
			 **         *******       **     *******   ** ****     **   ******** 
			/**        **/////**     ****   /**////** /**/**/**   /**  **//////**
			/**       **     //**   **//**  /**    /**/**/**//**  /** **      // 
			/**      /**      /**  **  //** /**    /**/**/** //** /**/**         
			/**      /**      /** **********/**    /**/**/**  //**/**/**    *****
			/**      //**     ** /**//////**/**    ** /**/**   //****//**  ////**
			/******** //*******  /**     /**/*******  /**/**    //*** //******** 
			////////   ///////   //      // ///////   // //      ///   ////////  
     

                        
        


)";
char BACK[] = "1:Back";
char TOP[] = "PLAYER";

int width = 40;
int height = 18;
int xbox = (WIDTH_WALL / 2)+3;
int ybox = (HEIGH_WALL / 2)-1;
for (int i = 0; i < height; i++)
{
	GotoXY(xbox, ybox + i);
	for (int k = 0; k < width; k++)
	{
		if (i == 0)
		{
			cout << (char)167;

		}
		else if (i == height - 1)
		{
			cout << (char)167;

		}

		else if (k == width - 1 || k == 0)
		{
			cout << (char)167;

		}
		else
		{
			cout << " ";
		}

	}
}
GotoXY(xbox + 30, ybox + 15);
cout << BACK;

char **list = new char* [20];

int direct = 1;
char key;
int Set[] = { 2,7,7,7,7,7,7,7,7,7 };
for (int i = 0; i < 9; i++)
{
	list[i] = new char[50];
}
FILE* fi = fopen("username.txt", "r");
for (int i = 0; i < 6; i++)
{
		fgets(list[i], 40, fi);
		
		if (strcmp(list[i], "NODATA") == 0)
		{
			strcpy(list[i], "NODATA");
		}
	
}
fclose(fi);
while (true)
{
	for (int i = 0; i < 6; i++)
	{
		SetColor(Set[i]);
		GotoXY(50, 15+i);
		cout << list[i];

	}
	key = _getch();
	if (key == 'w')
	{
		direct--;
		if (direct == 0)
		{
			direct = 6;
		}

	}
	if (key == 's')
	{
		direct++;
		if (direct >6)
			direct = 1;

	}

	if (key == 13)
	{
		if (strcmp(list[direct - 1], "NODATA") != 0)
		{
			return *(list + (direct - 1));
		}
	}
	for (int i = 0; i < 6; i++)
	{
		Set[i] = 7;
	}
	if (direct!= 0)
	{
		Set[direct - 1] = 2;
	}


}


}
