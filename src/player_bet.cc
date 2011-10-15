#include <iostream>
#include "player.h"
#include "pot.h"

using namespace std;

void PlayerBet(int i, Player& r_player, Pot& r_main_pot) {
  r_player.SetStackAmount(r_player.GetStackAmount() - i);
  r_player.SetInvestAmount(r_player.GetInvestAmount() + i);
  r_main_pot.SetPotAmount(r_main_pot.GetPotAmount() + i);
  r_player.SetActedStatus(true);
}
