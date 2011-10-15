#include <iostream>
#include "card.h"

Card::Card() {
  std::string card_name = "X";
  int card_rank = 0;
  int card_suit = 0;
}

std::string Card::GetCardName() {
  return card_name;
}

int Card::GetCardRank() const {
  return card_rank;
}

int Card::GetCardSuit() {
  return card_suit;
}

void Card::SetCardName(std::string i) {
  card_name = i;
}

void Card::SetCardRank(int i) {
  card_rank = i;
}

void Card::SetCardSuit(int i) {
  card_suit = i;
}
