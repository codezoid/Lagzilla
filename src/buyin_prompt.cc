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
    cout << "The amount specified does not meet the minimum buyin!" << endl;
    cout << "Buyin set at 20 BBs\n" << endl;
    r_user.SetStackAmount(20 * r_main_pot.GetBigBlindAmount());
  }
  else if (i > (200 * r_main_pot.GetBigBlindAmount())) {
    cout << "The amount specified exceeds the maximum buyin!" << endl;
    cout << "Buyin set at 200 BBs\n" << endl;
    r_user.SetStackAmount(200 * r_main_pot.GetBigBlindAmount());
  }
  else {
    r_user.SetStackAmount(i);
  }
}
