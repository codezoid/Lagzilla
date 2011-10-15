#include <iostream>
#include "player.h"
#include "pot.h"
#include "new_round.h"
#include "validate_user_bet_amount.h"
#include "player_bet.h"
#include <cmath>
#include "bot_i_generator.h"

using namespace std;

void OnTheClockPrompt(Player& r_user, Player& r_bot, Pot& r_main_pot) {
  int i = 0;

  //Check if the betting round is set
  cout << "\nBetting Round: " << r_main_pot.GetBettingRoundCount() << endl;

  //player OTC
  if (r_user.GetOnTheClockStatus() == true) {
    cout << "\nEnter wager: ";
    cin >> i;
    int x = ValidateUserBetAmount(r_user, r_bot, r_main_pot, i);
    if (i == -1) {
      if (r_user.GetInvestAmount() >= r_bot.GetInvestAmount()) {
        PlayerBet(0, r_user, r_main_pot);
      }
      else {
        r_user.SetFoldedStatus(true);
      }
    }
    else {
      PlayerBet(x, r_user, r_main_pot);
    }
  }
  //bot OTC
  else {
    int i = BotIGenerator(r_user, r_bot, r_main_pot);
    if (i < 0) {
      if (r_bot.GetInvestAmount() >= r_user.GetInvestAmount()) {
        cout << "\nBot is checking" << endl;
        PlayerBet(0, r_bot, r_main_pot);
      }
      else {
        cout << "\nBot folded" << endl;
        r_bot.SetFoldedStatus(true);
      }
    }
    else {
      cout << "\nBot wager: " << i << endl;
      PlayerBet(i, r_bot, r_main_pot);
    }
  }

  //Set minimum raise amount
  int x = abs(r_user.GetInvestAmount() - r_bot.GetInvestAmount());
  r_main_pot.SetMinimumRaiseAmount(x);

  //Switch players who are OTC
  if (r_user.GetOnTheClockStatus() == true) {
    r_user.SetOnTheClockStatus(false);
    r_bot.SetOnTheClockStatus(true);
  }
  else {
    r_user.SetOnTheClockStatus(true);
    r_bot.SetOnTheClockStatus(false);
  }
}
