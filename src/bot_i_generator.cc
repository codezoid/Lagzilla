#include <cstdlib>
#include "player.h"
#include "pot.h"

int BotIGenerator(Player& r_user, Player& r_bot, Pot& r_main_pot) {
  //randomly determine u to determine whether to call or raise
  int u = (rand() % 3) + 1;
  int i = 0;

  //check and fold logic
  if (u == 1) {
    i = -1;
  }
  //check and call logic
  else if (u == 2) {
    if (r_user.GetInvestAmount() > (r_bot.GetInvestAmount() +
        r_bot.GetStackAmount())) {
      i = r_bot.GetStackAmount();
    }
    else {
      i = (r_user.GetInvestAmount() - r_bot.GetInvestAmount());
    }
  }
  //bet and raise logic
  else {
    //can the bot min raise?
    if ((r_bot.GetStackAmount() + r_bot.GetInvestAmount()) >=
        (r_user.GetInvestAmount() + r_main_pot.GetMinimumRaiseAmount())) {
      //pot sized raise amount
      int pot_raise = ((r_user.GetInvestAmount() - r_bot.GetInvestAmount()) +
                        r_main_pot.GetPotAmount());
      int y;
      if (pot_raise > r_bot.GetStackAmount()) {
        //max bet is stack amount
        y = (r_bot.GetStackAmount() - r_main_pot.GetMinimumRaiseAmount());
      }
      else {
        //max bet is pot sized raise
        y = (pot_raise - r_main_pot.GetMinimumRaiseAmount());
      }
      int x = rand() % (y + 1);
      i = ((2 * (r_user.GetInvestAmount() - r_bot.GetInvestAmount())) + x);
    }
    else {
      i = r_bot.GetStackAmount();
    }
  }
  return i;
}
