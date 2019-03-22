#pragma once
#include<string>
using namespace std;



//This class lets players choose their names
class players
{
private:
	string player_1 = "Player 1";
	string player_2 = "Player 2";

public:

	
	void setplayer1(string p)
	{player_1 = p;}
	void setplayer2(string t)
	{player_2 = t;}

	string getplayer1()
	{return player_1;}
	string getplayer2()
	{return player_2;}
};

