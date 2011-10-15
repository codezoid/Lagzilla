#include <iostream>
#include "player.h"
#include "pot.h"
#include "card.h"
#include "new_deal.h"
#include <cstdlib>
#include "deck.h"

//TEST LIBRARY
#include "showdown.h"

using namespace std;

void NewDeal(Player& r_user, Player& r_bot, Pot& r_main_pot) {
  //Generate deck object
  Deck MainDeck;

  //Shuffle the deck
  int i;
  for (i = 0; i < 52; i++) {
    //generate random number
    int x = (rand() % 52);
    Card temp_card = MainDeck.GetDeckCard(i);
    MainDeck.SetDeckCard(i, MainDeck.GetDeckCard(x));
    MainDeck.SetDeckCard(x, temp_card);
  }

  //Set user hole cards
  r_user.SetHoleCard(0, MainDeck.GetDeckCard(0));
  r_user.SetHoleCard(1, MainDeck.GetDeckCard(2));
  r_user.SetHoleCard(2, MainDeck.GetDeckCard(4));
  r_user.SetHoleCard(3, MainDeck.GetDeckCard(6));

  //Set bot hole cards
  r_bot.SetHoleCard(0, MainDeck.GetDeckCard(1));
  r_bot.SetHoleCard(1, MainDeck.GetDeckCard(3));
  r_bot.SetHoleCard(2, MainDeck.GetDeckCard(5));
  r_bot.SetHoleCard(3, MainDeck.GetDeckCard(7));

  //Set community cards
  r_main_pot.SetCommunityCard(0, MainDeck.GetDeckCard(9));
  r_main_pot.SetCommunityCard(1, MainDeck.GetDeckCard(10));
  r_main_pot.SetCommunityCard(2, MainDeck.GetDeckCard(11));
  r_main_pot.SetCommunityCard(3, MainDeck.GetDeckCard(13));
  r_main_pot.SetCommunityCard(4, MainDeck.GetDeckCard(15));

  //User cout statements
  cout << "user cards: \t" << r_user.GetHoleCard(0).GetCardName() << ", " <<
  r_user.GetHoleCard(1).GetCardName() << ", " <<
  r_user.GetHoleCard(2).GetCardName() << ", " <<
  r_user.GetHoleCard(3).GetCardName() << endl;

  //Bot cout statements
  cout << "bot cards: \t" << r_bot.GetHoleCard(0).GetCardName() << ", " <<
  r_bot.GetHoleCard(1).GetCardName() << ", " <<
  r_bot.GetHoleCard(2).GetCardName() << ", " <<
  r_bot.GetHoleCard(3).GetCardName() << endl;

  //Community card cout statements
  cout << "board cards: \t" << r_main_pot.GetCommunityCard(0).GetCardName() <<
  ", " << r_main_pot.GetCommunityCard(1).GetCardName() << ", " <<
  r_main_pot.GetCommunityCard(2).GetCardName() << ", " <<
  r_main_pot.GetCommunityCard(3).GetCardName() << ", " <<
  r_main_pot.GetCommunityCard(4).GetCardName() << endl;

  //TEST DUMMY CODE...CAN DEFINITELY REMOVE WHAT IS BELOW:
  //AssignPlayerShowdownHand(r_user, r_main_pot);
}
