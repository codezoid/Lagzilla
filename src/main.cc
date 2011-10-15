#include <iostream>
#include "player.h"
#include "pot.h"
#include "buyin_prompt.h"
#include "new_hand.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
  //1. APP SETUP
  //Welcome message
  cout << "Welcome to HU PLO!\n" << endl;

  //2. SESSION SETUP
  //random number seed, done once per program execution
  srand(time(0));

  //Create objects
  Player User;
  Player Bot;
  Pot MainPot;

  //Create references
  Player& r_user = User;
  Player& r_bot = Bot;
  Pot& r_main_pot = MainPot;

  //Set blind amounts
  r_main_pot.SetSmallBlindAmount(1);
  r_main_pot.SetBigBlindAmount(2);

  //Prompt user for their stack size; hardcode bot stack size
  BuyinPrompt(r_user, r_main_pot);
  r_bot.SetStackAmount(100 * r_main_pot.GetBigBlindAmount());

  //3. START NEW HAND, loop through new hands indefinitely
  NewHand(r_user, r_bot, r_main_pot);
}
