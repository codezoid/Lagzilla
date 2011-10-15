#include <iostream>
#include "player.h"
#include "pot.h"
#include "new_round.h"
#include "on_the_clock_prompt.h"

using namespace std;

bool OriginalStackAmountsEqual(Player&, Player&);
bool InvestAmountsEqual(Player&, Player&);
bool AnyPlayersAllin(Player&, Player&);
void AllinEvaluation(Player&, Player&, Pot&);
void DifferingStacksEvaluation(Player&, Player&, Pot&);
void NoShowdown(Player&, Player&, Pot&);
void Showdown(Player&, Player&, Pot&);

void BettingEvaluation(Player& r_user, Player& r_bot, Pot& r_main_pot) {
  //ANYONE FOLDED?
  if (r_user.GetFoldedStatus() == true ||
      r_bot.GetFoldedStatus() == true) {
    //NO SHOWDOWN
    cout << "NO SHOWDOWN\n" << endl;
    NoShowdown(r_user, r_bot, r_main_pot);
  }
  //EVERYONE ACTED?
  else if (r_user.GetActedStatus() == false ||
           r_bot.GetActedStatus() == false) {
    //NOT OVER
    OnTheClockPrompt(r_user, r_bot, r_main_pot);
    BettingEvaluation(r_user, r_bot, r_main_pot);
  }
  //ORIGINAL STACK SIZES EQUAL?
  else if (OriginalStackAmountsEqual(r_user, r_bot) == true) {
    //INVEST AMOUNT EQUAL?
    if (InvestAmountsEqual(r_user, r_bot) == true) {
      //ANYONE ALLIN?
      AllinEvaluation(r_user, r_bot, r_main_pot);
    }
    else {
      //NOT OVER
      OnTheClockPrompt(r_user, r_bot, r_main_pot);
      BettingEvaluation(r_user, r_bot, r_main_pot);
    }
  }
  else {
    //INVEST AMOUNT EQUAL?
    if (InvestAmountsEqual(r_user, r_bot) == true) {
      //ANYONE ALLIN?
      AllinEvaluation(r_user, r_bot, r_main_pot);
    }
    else {
      //DIFFERING STACKS EVALUATION
      DifferingStacksEvaluation(r_user, r_bot, r_main_pot);
    }
  }
}

bool OriginalStackAmountsEqual(Player& r_user, Player& r_bot) {
  int i = r_user.GetStackAmount() + r_user.GetInvestAmount();
  int x = r_bot.GetStackAmount() + r_bot.GetInvestAmount();
  if (i == x) {
    return true;
  }
  else {
    return false;
  }
}

bool InvestAmountsEqual(Player& r_user, Player& r_bot) {
  if (r_user.GetInvestAmount() == r_bot.GetInvestAmount()) {
    return true;
  }
  else {
    return false;
  }
}

bool AnyPlayersAllin(Player& r_user, Player& r_bot) {
  if (r_user.GetStackAmount() == 0 || r_bot.GetStackAmount() == 0) {
    return true;
  }
  else {
    return false;
  }
}

void AllinEvaluation(Player& r_user, Player& r_bot, Pot& r_main_pot) {
  if (AnyPlayersAllin(r_user, r_bot) == true) {
    //ROUND COUNT < 4?
    if (r_main_pot.GetBettingRoundCount() < 4) {
      //show all cards
      cout << "Show all cards" << endl;
    }
    //SHOWDOWN
    cout << "SHOWDOWN\n" << endl;
    Showdown(r_user, r_bot, r_main_pot);
  }
  else {
    //ROUND COUNT < 4?
    if (r_main_pot.GetBettingRoundCount() < 4) {
      //show next card
      //betting round count ++
      int i = r_main_pot.GetBettingRoundCount() + 1;
      r_main_pot.SetBettingRoundCount(i);
      //set acted status back to false at end of a round
      r_user.SetActedStatus(false);
      r_bot.SetActedStatus(false);
      //CALL NEW ROUND
      cout << "NEW ROUND" << endl;
      NewRound(r_user, r_bot, r_main_pot);
    }
    else {
      //SHOWDOWN
      cout << "SHOWDOWN\n" << endl;
      Showdown(r_user, r_bot, r_main_pot);
    }
  }
}

void DifferingStacksEvaluation(Player& r_user, Player& r_bot, Pot& r_main_pot) {
  //BIG STACK AND SHORT STACK ASSIGNED
  int i = r_user.GetStackAmount() + r_user.GetInvestAmount();
  int x = r_bot.GetStackAmount() + r_bot.GetInvestAmount();
  //USER DEEP STACK
  if (i > x) {
    if (r_user.GetInvestAmount() > r_bot.GetInvestAmount()) {
      if (r_bot.GetStackAmount() == 0) {
        if (r_main_pot.GetBettingRoundCount() < 4) {
          //show all cards
          cout << "Show all cards" << endl;
        }
        //SHOWDOWN
        cout << "SHOWDOWN\n" << endl;
        Showdown(r_user, r_bot, r_main_pot);
      }
      else {
        //NOT OVER
        OnTheClockPrompt(r_user, r_bot, r_main_pot);
        BettingEvaluation(r_user, r_bot, r_main_pot);
      }
    }
    else {
      //NOT OVER
      OnTheClockPrompt(r_user, r_bot, r_main_pot);
      BettingEvaluation(r_user, r_bot, r_main_pot);
    }
  }
  //BOT DEEP STACK
  else {
    if (r_bot.GetInvestAmount() > r_user.GetInvestAmount()) {
      if (r_user.GetStackAmount() == 0) {
        if (r_main_pot.GetBettingRoundCount() < 4) {
          //show all cards
          cout << "Show all cards" << endl;
        }
        //SHOWDOWN
        cout << "SHOWDOWN\n" << endl;
        Showdown(r_bot, r_user, r_main_pot);
      }
      else {
        //NOT OVER
        OnTheClockPrompt(r_user, r_bot, r_main_pot);
        BettingEvaluation(r_user, r_bot, r_main_pot);
      }
    }
    else {
      //NOT OVER
      OnTheClockPrompt(r_user, r_bot, r_main_pot);
      BettingEvaluation(r_user, r_bot, r_main_pot);
    }
  }
}

void NoShowdown(Player& r_user, Player& r_bot, Pot& r_main_pot) {
  if (r_user.GetFoldedStatus() == false) {
    int i = r_user.GetStackAmount() + r_main_pot.GetPotAmount();
    r_user.SetStackAmount(i);
    r_main_pot.SetPotAmount(0);
  }
  else {
    int i = r_bot.GetStackAmount() + r_main_pot.GetPotAmount();
    r_bot.SetStackAmount(i);
    r_main_pot.SetPotAmount(0);
  }
}

void Showdown(Player& player_1, Player& player_2, Pot& r_main_pot) {
  //i is a magic number right now, but is likely to change or get removed once
  //a showdown function is created, and it is understood what exactly it will
  //return, if anything
  int i = 0;
  //user wins
  if (i == 1) {
    if (player_1.GetInvestAmount() < (r_main_pot.GetPotAmount() / 2)) {
      int x = player_1.GetInvestAmount() * 2;
      player_1.SetStackAmount(player_1.GetStackAmount() + x);
      r_main_pot.SetPotAmount(r_main_pot.GetPotAmount() - x);
      player_2.SetStackAmount(player_2.GetStackAmount() +
                              r_main_pot.GetPotAmount());
    }
    else {
      player_1.SetStackAmount(player_1.GetStackAmount() +
                            r_main_pot.GetPotAmount());
    }
  }
  //bot wins
  else if (i == 2) {
    if (player_2.GetInvestAmount() < (r_main_pot.GetPotAmount() / 2)) {
      int x = player_2.GetInvestAmount() * 2;
      player_2.SetStackAmount(player_2.GetStackAmount() + x);
      r_main_pot.SetPotAmount(r_main_pot.GetPotAmount() - x);
      player_1.SetStackAmount(player_1.GetStackAmount() +
                            r_main_pot.GetPotAmount());
    }
    else {
      player_2.SetStackAmount(player_2.GetStackAmount() +
                            r_main_pot.GetPotAmount());
    }
  }
  //chop, i == 0
  else {
    player_1.SetStackAmount(player_1.GetStackAmount() +
                            player_1.GetInvestAmount());
    player_2.SetStackAmount(player_2.GetStackAmount() +
                            player_2.GetInvestAmount());
  }
  r_main_pot.SetPotAmount(0);
}
