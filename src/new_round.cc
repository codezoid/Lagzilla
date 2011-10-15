#include <iostream>
#include "player.h"
#include "pot.h"
#include "player_bet.h"
#include "on_the_clock_initiator.h"
#include "on_the_clock_prompt.h"
#include "betting_evaluation.h"

using namespace std;

void NewRound(Player& r_user, Player& r_bot, Pot& r_main_pot) {

  //This function is based off of position because position will always be set.
  //This runs at the start of every betting round.  It knows that positions are
  //set and that a betting round has just started, and thus it is used simply to
  //set the first OTC value for a given betting round.
  OnTheClockInitiator(r_user, r_bot, r_main_pot);

  cout << "\nuser OTC: " << r_user.GetOnTheClockStatus() << endl;
  cout << "bot OTC: " << r_bot.GetOnTheClockStatus() << endl;

  OnTheClockPrompt(r_user, r_bot, r_main_pot);

  BettingEvaluation(r_user, r_bot, r_main_pot);
}
