#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "pot.h"
#include "player_bet.h"
#include <cmath>
#include "new_deal.h"

using namespace std;

void SetAllPositions(Player&, Player&);
void AutoReload(Player&, Player&, Pot&);
void ExtractBlinds(Player&, Player&, Pot&);
void ResetPlayerStatuses(Player&, Player&);

void HandSetup(Player& r_user, Player& r_bot, Pot& r_main_pot) {
  //Set positions (randomly if 0, switch if already set)
  SetAllPositions(r_user, r_bot);

  //Auto reload
  AutoReload(r_user, r_bot, r_main_pot);

  //Reset the invest values in between hands
  r_user.SetInvestAmount(0);
  r_bot.SetInvestAmount(0);

  //Extract blinds
  //NOTE THAT THIS FUNCTION SETS ACTED STATUS TO TRUE, since it uses player_bet
  ExtractBlinds(r_user, r_bot, r_main_pot);

  //Reset folded & acted statuses
  ResetPlayerStatuses(r_user, r_bot);

  //Deal out all cards
  NewDeal(r_user, r_bot, r_main_pot);

  //Check to see if blinds are extracted
  cout << "\nPlayer (after blinds):" << endl;
  cout << "Stack: "<< r_user.GetStackAmount() << endl;
  cout << "Invest: "<< r_user.GetInvestAmount() << endl;
  cout << "\nBot (after blinds):" << endl;
  cout << "Stack: "<< r_bot.GetStackAmount() << endl;
  cout << "Invest: "<< r_bot.GetInvestAmount() << endl;
  cout << "\nMain pot (after blinds):" << endl;
  cout << "Pot: "<< r_main_pot.GetPotAmount() << endl;

  //Set betting round to 1 (preflop)
  r_main_pot.SetBettingRoundCount(1);
}

void SetAllPositions(Player& r_user, Player& r_bot) {
  if (r_user.GetPosition() == 1) {
    r_user.SetPosition(2);
    r_bot.SetPosition(1);
  }
  else {
    if (r_user.GetPosition() == 2) {
      r_user.SetPosition(1);
      r_bot.SetPosition(2);
    }
    else {
      srand(time(0));
      int i = (rand() % 2) + 1;
      if (i == 1) {
        r_user.SetPosition(1);
        r_bot.SetPosition(2);
      }
      else {
        r_user.SetPosition(2);
        r_bot.SetPosition(1);
      }
    }
  }
}

void AutoReload(Player& r_user, Player& r_bot, Pot& r_main_pot) {
  if (r_user.GetStackAmount() < (20 * r_main_pot.GetBigBlindAmount())) {
    r_user.SetStackAmount(200);
  }
  if (r_bot.GetStackAmount() < (20 * r_main_pot.GetBigBlindAmount())) {
    r_bot.SetStackAmount(200);
  }
}

void ExtractBlinds(Player& r_user, Player& r_bot, Pot& r_main_pot) {
  int big = r_main_pot.GetBigBlindAmount();
  int small = r_main_pot.GetSmallBlindAmount();
  if (r_user.GetPosition() == 1) {
    PlayerBet(big, r_user, r_main_pot);
    PlayerBet(small, r_bot, r_main_pot);
  }
  else {
    PlayerBet(small, r_user, r_main_pot);
    PlayerBet(big, r_bot, r_main_pot);
  }
  //Set minimum raise amount
  int i = abs(r_user.GetInvestAmount() - r_bot.GetInvestAmount());
  r_main_pot.SetMinimumRaiseAmount(i);
}

void ResetPlayerStatuses(Player& r_user, Player& r_bot) {
  r_user.SetFoldedStatus(false);
  r_bot.SetFoldedStatus(false);

  r_user.SetActedStatus(false);
  r_bot.SetActedStatus(false);
}
