#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>


int main()
{
	srand(time(NULL));

	Player Sid;
	Player Joe;
	

	Player::SetTotalGameSets(Player::NumOfSetsToPlay);

	while (Sid.GetGameSet() != Player::NumOfSetsToPlay && Joe.GetGameSet() != Player::NumOfSetsToPlay)
	{
		
			Sid.RunGame(Sid);
			Joe.RunGame(Joe);
			Player::CalculateWinner(Sid, Joe);
		
	}
	

	Sid.~Player();
	Joe.~Player();

	return 0;
}