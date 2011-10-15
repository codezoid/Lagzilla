#ifndef PLAYER_HAND_H
#define PLAYER_HAND_H

#include "card.h"

class PlayerHand {
 public:
  PlayerHand();
  Card GetPlayerHandArray();
  Card GetPlayerHandCard(int);
  int GetPlayerHandRank();
  void SetPlayerHandCard(int, Card);
  void SetPlayerHandRank(int);

 private:
  Card player_hand[5];
  int hand_rank;
};

#endif
