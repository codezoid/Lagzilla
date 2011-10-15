#include "player.h"
#include "pot.h"

void OnTheClockInitiator(Player& r_user, Player& r_bot, Pot& r_main_pot) {
  if (r_main_pot.GetBettingRoundCount() == 1) {
    if (r_user.GetPosition() == 2) {
      r_user.SetOnTheClockStatus(true);
      r_bot.SetOnTheClockStatus(false);
    }
    else {
      r_user.SetOnTheClockStatus(false);
      r_bot.SetOnTheClockStatus(true);
    }
  }
  else {
    if (r_user.GetPosition() == 1) {
      r_user.SetOnTheClockStatus(true);
      r_bot.SetOnTheClockStatus(false);
    }
    else {
      r_user.SetOnTheClockStatus(false);
      r_bot.SetOnTheClockStatus(true);
    }
  }
}
