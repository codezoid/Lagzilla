#include <iostream>
#include "player.h"
#include "pot.h"
#include "on_the_clock_prompt.h"

using namespace std;

//Returns bet amount as an int
int ValidateUserBetAmount(Player& r_user, Player& r_bot,
                          Pot& r_main_pot, int i) {
  //indicative of a fold
  if (i < 0) {
    return -1;
  }
  
  //is user attempting to bet more than they have and/or go allin?
  else if (i >= r_user.GetStackAmount()) {
    i = r_user.GetStackAmount();
    cout << "going allin for " << i << endl;
    return i;
  }
  
  //is user raising?
  else if ((r_user.GetInvestAmount() + i) > r_bot.GetInvestAmount()) {
    //can user min-raise?  if so, they must at least min-raise
    if ((r_user.GetInvestAmount() + i) >=
         r_bot.GetInvestAmount() + r_main_pot.GetMinimumRaiseAmount()) {
      return i;
    }
    else {
      //user not allin and is not raising the minimum amount
      //therefore, by default, they call
      cout << "illegal operation (invalid raise amount)" << endl;
      int x;
      x = r_bot.GetInvestAmount() - r_user.GetInvestAmount();
      if (x >= r_user.GetStackAmount()) {
        i = r_user.GetStackAmount();
      }
      else {
        i = x;
      }
      cout << "calling instead for " << i << endl;
      return i;
    }
  }
  
  //user invest value is less than bot invest value
  else if ((r_user.GetInvestAmount() + i) < r_bot.GetInvestAmount()) {
    //user not allin and is not matching opponent invest value
    //therefore, by default, they call
    cout << "illegal operation (invalid call amount)" << endl;
    int x;
    x = r_bot.GetInvestAmount() - r_user.GetInvestAmount();
    if (x >= r_user.GetStackAmount()) {
      i = r_user.GetStackAmount();
    }
    else {
      i = x;
    }
    cout << "calling instead for " << i << endl;
    return i;
  }
  
  //action is even
  else {
    return i;
  }
}
