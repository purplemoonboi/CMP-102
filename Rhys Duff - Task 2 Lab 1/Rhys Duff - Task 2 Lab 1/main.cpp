#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
//test//test
int main()
{
	srand(time(0));

	Player Sid;
	Player Joe;
	
	Player::SetGameAim(Player::BullsEyeAimCount);
	
	Sid.RunGame(Sid);
	Joe.RunGame(Joe);

	Player::CalculateWinner(Sid, Joe);

	Sid.~Player();
	Joe.~Player();

	return 0;
}