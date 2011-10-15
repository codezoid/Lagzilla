#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
 public:
  Card();
  std::string GetCardName();
  int GetCardRank() const;
  int GetCardSuit();
  void SetCardName(std::string);
  void SetCardRank(int);
  void SetCardSuit(int);

 private:
  std::string card_name;
  int card_rank;
  int card_suit;
};

#endif
