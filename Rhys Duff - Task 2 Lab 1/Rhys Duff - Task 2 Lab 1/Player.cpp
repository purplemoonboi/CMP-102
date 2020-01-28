#include "Player.h"

bool DebugOn = false;

int Player::NumOfSetsToPlay = 0;

Player::Player()
{
	GameRound = 0;
	BullsEyeCount = 0;
	GameSet = 0;
	SuccessRate = 0.0;

	SetName(playerName);
	SetHitChance(hitChance);
}

Player::~Player()
{

}

void Player::SetName(std::string& l_name)
{
	std::cout << "Please enter your name : \n";
	std::cin >> l_name;
	
}

void Player::SetHitChance(int& l_hitChance)
{
	std::cout << "Enter player's odds : \n";
	std::cin >> l_hitChance;
}



void Player::SetTotalGameSets(int& l_gameSets)
{
	std::cout << "Please enter the number of games you wish to run :";
	std::cin >> l_gameSets;
}


bool Player::BullsEye(int& l_chance, Player& l_player)
{

	GameRound = 1;


	std::cout << "Welcome to Round " << GameRound << " Up next " << l_player.playerName << "\n\n";

	
		while(GameRound != 4)
		{
			std::cout << l_player.playerName + "'s turn. Turn " << GameRound << "\n\n";
			if (rand() % 100 < l_chance)
			{

				hitBullsEye = true;
				BullsEyeCount++;
				std::cout << "Bullseye! \n\n";
			}
			else
			{

				hitBullsEye = false;
				std::cout << "Miss! \n\n";
			}
			
			//l_player.SetHitChance(l_chance);    //  <-- Uncomment this to ask the user to alter chance after every turn.
			l_chance = rand() % 75 + 69;		  //  <-- Comment this when the above line is uncommented. - Used to simulate.
			GameRound++;
		}
												 
		
		l_player.GameSet++;
	
	
	

	return hitBullsEye;
}

float Player::CalculateSuccessRate(int& l_tRounds, int& bHitCount)
{
	float tmp_float = ((float)bHitCount / l_tRounds);

	SuccessRate = tmp_float / NumOfSetsToPlay;

	return SuccessRate;
}

void Player::CalculateWinner(Player& l_playerOne, Player& l_playerTwo)
{	
	if (l_playerOne.BullsEyeCount > l_playerTwo.BullsEyeCount)
	{
		std::cout << l_playerOne.playerName << " is the winner." << " They hit " << l_playerOne.BullsEyeCount << " bullseyes in " << l_playerOne.GameSet << " sets. \n\n";

		l_playerOne.SuccessRate = l_playerOne.CalculateSuccessRate(l_playerOne.GameSet, l_playerOne.BullsEyeCount);
		l_playerTwo.SuccessRate = l_playerTwo.CalculateSuccessRate(l_playerTwo.GameSet, l_playerTwo.BullsEyeCount);

		std::cout << l_playerOne.playerName << "s' success rate is " << l_playerOne.SuccessRate << "\n\n";
		std::cout << l_playerTwo.playerName << "s' success rate is " << l_playerTwo.SuccessRate << "\n\n";
	}
	else
	{
		std::cout << l_playerTwo.playerName << " is the winner." << " They hit " << l_playerTwo.BullsEyeCount << " in" << l_playerTwo.GameSet << "\n\n";

		l_playerOne.SuccessRate = l_playerOne.CalculateSuccessRate(l_playerOne.GameSet, l_playerOne.BullsEyeCount);
		l_playerTwo.SuccessRate = l_playerTwo.CalculateSuccessRate(l_playerTwo.GameSet, l_playerTwo.BullsEyeCount);

		std::cout << l_playerOne.playerName << "s' success rate is " << l_playerOne.SuccessRate << "\n\n";
		std::cout << l_playerTwo.playerName << "s' success rate is " << l_playerTwo.SuccessRate << "\n\n";
	}
}

void Player::RunGame(Player& l_player)
{
	hitBullsEye = BullsEye(hitChance, l_player);

	std::cout << l_player.playerName << " scored " << l_player.BullsEyeCount << "\n\n"; 
}


int Player::GetScore() { return BullsEyeCount; }
int Player::GetGameRound() { return GameRound; }
int Player::GetGameSet() { return GameSet; }