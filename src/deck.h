#ifndef DECK_H
#define DECK_H

#include "card.h"

class Deck {
 public:
  Deck();
  Card GetDeckCard(int);
  void SetDeckCard(int, Card);

 private:
  Card deck[52];
};

#endif
