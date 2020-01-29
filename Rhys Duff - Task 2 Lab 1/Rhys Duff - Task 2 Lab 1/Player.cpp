#include "Player.h"

bool DebugOn = false;

int Player::NumOfSetsToPlay = 0;

Player::Player()
{
	GameRound = 0;
	BullsEyeCount = 0;
	GameSet = 0;
	SuccessRate = 0.0;
	TotalRounds = 0;
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


bool Player::BullsEye(Player& l_player)
{

	l_player.GameRound = 1;


	std::cout << "Welcome to Round " << GameRound << " Up next " << l_player.playerName << "\n\n";

	
		while(l_player.GameRound != 4)
		{
			std::cout << l_player.playerName + "'s turn. Turn " << GameRound << "\n\n";
			if (rand() % 100 + 1 < l_player.hitChance)
			{

				hitBullsEye = true;
				l_player.BullsEyeCount++;
				std::cout << "Bullseye! \n\n";
				
			}
			else
			{

				hitBullsEye = false;
				std::cout << "Miss! \n\n";
				
			}
			
			//l_player.SetHitChance(l_chance);    //  <-- Uncomment this to ask the user to alter chance after every turn.
			
			l_player.GameRound++;
			l_player.TotalRounds++;
		}


	return hitBullsEye;
}

float Player::CalculateSuccessRate(int& l_tRounds, int& bHitCount)
{
	SuccessRate = ((float)bHitCount / (float)l_tRounds) * 100;

	

	return SuccessRate;
}

void Player::CalculateWinner(Player& l_playerOne, Player& l_playerTwo)
{	
	
	if (l_playerOne.BullsEyeCount == 10)
	{
		std::cout << l_playerOne.playerName << " is the winner." << " They hit " << l_playerOne.BullsEyeCount << " bullseyes in " << l_playerOne.TotalRounds << " sets. \n\n";

		l_playerOne.SuccessRate = l_playerOne.CalculateSuccessRate(l_playerOne.TotalRounds, l_playerOne.BullsEyeCount);
		l_playerTwo.SuccessRate = l_playerTwo.CalculateSuccessRate(l_playerTwo.TotalRounds, l_playerTwo.BullsEyeCount);

		std::cout << l_playerOne.playerName << "s' success rate is " << l_playerOne.SuccessRate << "\n\n";
		std::cout << l_playerTwo.playerName << "s' success rate is " << l_playerTwo.SuccessRate << "\n\n";

		l_playerOne.GameSet++;
		l_playerTwo.GameSet++;

	}
	else
	{
		std::cout << l_playerTwo.playerName << " is the winner." << " They hit " << l_playerTwo.BullsEyeCount << " in" << l_playerTwo.TotalRounds << "\n\n";

		l_playerOne.SuccessRate = l_playerOne.CalculateSuccessRate(l_playerOne.TotalRounds, l_playerOne.BullsEyeCount);
		l_playerTwo.SuccessRate = l_playerTwo.CalculateSuccessRate(l_playerTwo.TotalRounds, l_playerTwo.BullsEyeCount);

		std::cout << l_playerOne.playerName << "s' success rate is " << l_playerOne.SuccessRate << "\n\n";
		std::cout << l_playerTwo.playerName << "s' success rate is " << l_playerTwo.SuccessRate << "\n\n";

		l_playerOne.GameSet++;
		l_playerTwo.GameSet++;

	}
}

void Player::RunGame(Player& l_player)
{
	hitBullsEye = BullsEye(l_player);

	std::cout << l_player.playerName << " scored " << l_player.BullsEyeCount << "\n\n"; 
}


int Player::GetScore() { return BullsEyeCount; }
int Player::GetGameRound() { return GameRound; }
int Player::GetGameSet() { return GameSet; }