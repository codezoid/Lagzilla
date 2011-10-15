#ifndef POT_H
#define POT_H

#include "card.h"

class Pot {
 public:
  Pot();
  int GetPotAmount();
  int GetBettingRoundCount();
  int GetMinimumRaiseAmount();
  int GetSmallBlindAmount();
  int GetBigBlindAmount();
  Card GetCommunityCard(int);
  void SetPotAmount(int);
  void SetBettingRoundCount(int);
  void SetMinimumRaiseAmount(int);
  void SetSmallBlindAmount(int);
  void SetBigBlindAmount(int);
  void SetCommunityCard(int, Card);

 private:
  int pot_amount;
  int betting_round_count;
  int minimum_raise_amount;
  int small_blind_amount;
  int big_blind_amount;
  Card community_cards[5];
};

#endif
