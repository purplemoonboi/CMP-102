#include "Player.h"

bool DebugOn = false;
int Player::BullsEyeAimCount = 0;


Player::Player()
{
	GameRound = 0;
	BullsEyeCount = 0;
	TotalGameRounds = 0;
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

void Player::SetGameAim(int& l_aim)
{
	
	std::cout << "Please enter the number of bullseyes required to win :";
	std::cin >> l_aim;
}


bool Player::BullsEye(int& l_chance, Player& l_player)
{
	if(!DebugOn)std::cout << "Debug: var set to " << BullsEyeAimCount << "\n\n";
	
	while (BullsEyeCount < BullsEyeAimCount)
	{
		std::cout << l_player.playerName + "'s turn. Round " << TotalGameRounds << "\n\n";
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
		l_chance = rand() % 75 + 69;		  //  <-- Comment this when the above line is uncommented.
		TotalGameRounds++;
		DebugOn = true;
	}
	GameRound = TotalGameRounds;
	return hitBullsEye;
}

float Player::CalculateSuccessRate(int& l_tRounds, int& bHitCount)
{
	SuccessRate = ((float)bHitCount / l_tRounds) * 100;

	return SuccessRate;
}

void Player::CalculateWinner(Player& l_playerOne, Player& l_playerTwo)
{
	l_playerOne.SuccessRate = l_playerOne.CalculateSuccessRate(l_playerOne.TotalGameRounds, l_playerOne.BullsEyeCount);
	l_playerTwo.SuccessRate = l_playerTwo.CalculateSuccessRate(l_playerTwo.TotalGameRounds, l_playerTwo.BullsEyeCount);

	if (l_playerOne.SuccessRate > l_playerTwo.SuccessRate)
	{
		std::cout << l_playerOne.playerName + " is the winner. \n";
		std::cout << l_playerOne.playerName + "'s success rate was : " << l_playerOne.SuccessRate << ". \n\n";
		std::cout << l_playerOne.playerName + " took " << l_playerOne.GameRound << " turns to hit " << BullsEyeAimCount << " buyllseyes. \n\n";
		std::cout << l_playerTwo.playerName + "'s success rate was : " << l_playerTwo.SuccessRate << ". \n\n";
		std::cout << l_playerTwo.playerName + " took " << l_playerTwo.GameRound << " turns to hit " << BullsEyeAimCount << " buyllseyes. \n\n";
	}
	else
	{
		std::cout << l_playerTwo.playerName + " is the winner. \n";
		std::cout << l_playerTwo.playerName + "'s success rate was : " << l_playerTwo.SuccessRate << ". \n\n";
		std::cout << l_playerTwo.playerName + " took " << l_playerTwo.GameRound << " turns to hit " << BullsEyeAimCount << " buyllseyes. \n\n";
		std::cout << l_playerOne.playerName + "'s success rate was : " << l_playerOne.SuccessRate << ". \n\n";
		std::cout << l_playerOne.playerName + " took " << l_playerOne.GameRound << " turns to hit " << BullsEyeAimCount << " buyllseyes. \n\n";
	}

}

void Player::RunGame(Player& l_player)
{
	hitBullsEye = BullsEye(hitChance, l_player);
}


int Player::GetScore() { return BullsEyeCount; }
int Player::GetGameRound() { return GameRound; }
int Player::GetTotalRounds() { return TotalGameRounds; }