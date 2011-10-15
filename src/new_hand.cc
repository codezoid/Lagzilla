#include "player.h"
#include "pot.h"
#include "hand_setup.h"
#include "new_round.h"

void NewHand(Player& r_user, Player& r_bot, Pot& r_main_pot) {
  //HAND SETUP
  HandSetup(r_user, r_bot, r_main_pot);

  //HAND ACTION
  NewRound(r_user, r_bot, r_main_pot);

  //START NEW HAND
  NewHand(r_user, r_bot, r_main_pot);
}
