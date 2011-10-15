#include <iostream>
#include "player.h"
#include "pot.h"

using namespace std;

void BuyinPrompt(Player& r_user, Pot& r_main_pot) {
  cout << "Your starting stack size must be >= 40 and <= 400." << endl;
  cout << "Please enter your starting stacksize: ";
  int i;
  cin >> i;
  cout << endl;

  //validate user input
  if (i < (20 * r_main_pot.GetBigBlindAmount())) {
    cout << "The amount specified does not meet the minimum buyin!\n" << endl;
    BuyinPrompt(r_user, r_main_pot);
  }
  else if (i > (200 * r_main_pot.GetBigBlindAmount())) {
    cout << "The amount specified exceeds the maximum buyin!\n" << endl;
    BuyinPrompt(r_user, r_main_pot);
  }
  else {
    r_user.SetStackAmount(i);
  }
}
