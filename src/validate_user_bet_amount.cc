#include <iostream>
#include "player.h"
#include "pot.h"
#include "on_the_clock_prompt.h"

using namespace std;

//Does not return anything.  Instead, it continues to prompt until it receives a
//valid bet amount.
int ValidateUserBetAmount(Player& r_user, Player& r_bot,
                          Pot& r_main_pot, int i) {
  //indicative of a fold
  if (i < 0) {
    return -1;
  }

  //is user raising?
  else if ((r_user.GetInvestAmount() + i) > r_bot.GetInvestAmount()) {
    //can user min raise?
    if ((r_user.GetInvestAmount() + i) >=
         r_bot.GetInvestAmount() + r_main_pot.GetMinimumRaiseAmount()) {
      //define pot limit cap
      int pot_raise = ((2 * (r_bot.GetInvestAmount() -
                             r_user.GetInvestAmount())) +
                             r_main_pot.GetPotAmount());
      if(i <= pot_raise) {
        return i;
      }
      else {
        //fail
        cout << "illegal operation (pot limit kiddo)" << endl;
        cout << "\nEnter wager: ";
        cin >> i;
        ValidateUserBetAmount(r_user, r_bot, r_main_pot, i);
      }
    }
    else {
      //if user betting allin, they do not have to comply with min raise amt
      if (i == r_user.GetStackAmount()) {
        return i;
      }
      else {
        //user not allin and is not raising the minimum amount
        cout << "illegal operation" << endl;
        cout << "\nEnter wager: ";
        cin >> i;
        ValidateUserBetAmount(r_user, r_bot, r_main_pot, i);
      }
    }
  }
  //user invest value is less than bot invest value
  else if ((r_user.GetInvestAmount() + i) < r_bot.GetInvestAmount()) {
    if (i == r_user.GetStackAmount()) {
      return i;
    }
    else {
      //user not allin and is not matching opponent invest value
      cout << "illegal operation" << endl;
      cout << "\nEnter wager: ";
      cin >> i;
      ValidateUserBetAmount(r_user, r_bot, r_main_pot, i);
    }
  }
  //action is even
  else {
    return i;
  }
}
