#pragma once
#include <iostream>


class Player
{
private:

	int hitChance;				//	The odds of a player hitting a bullseye.

	int GameRound;				//	Current game round we are on.

	int BullsEyeCount;			//	How many bullseyes does 'this' player have.

	int GameSet;				//	Total sets played

	int TotalRounds;

	float SuccessRate;			//	Out of the games played how likely were they to hit bullseye.
		
	std::string playerName;
	bool hitBullsEye;

	


	void SetName(std::string& l_name);					
	void SetHitChance(int& l_hitchance);		

	bool BullsEye(Player& l_player);

	float CalculateSuccessRate(int& l_tRounds, int& l_HitCount);	

public:

	Player();
	~Player();

	void RunGame(Player& l_player);
	int GetScore();				//
	int GetGameRound();			//	Public Getters 
	int GetGameSet();		

	static int NumOfSetsToPlay;

																			//	Declared static hence no relation to object
	static void CalculateWinner(Player& l_playerOne, Player& l_playerTwo);	//  instance required.
									
	static void SetTotalGameSets(int& l_tGameSets);



};