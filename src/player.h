#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"

class Player {
 public:
  Player();
  int GetPosition();
  int GetStackAmount();
  int GetInvestAmount();
  bool GetFoldedStatus();
  bool GetActedStatus();
  bool GetOnTheClockStatus();
  Card GetHoleCard(int);
  void SetPosition(int);
  void SetStackAmount(int);
  void SetInvestAmount(int);
  void SetFoldedStatus(bool);
  void SetActedStatus(bool);
  void SetOnTheClockStatus(bool);
  void SetHoleCard(int, Card);

 private:
  int position;
  int stack_amount;
  int invest_amount;
  bool folded_status;
  bool acted_status;
  bool on_the_clock_status;
  Card hole_cards[4];
};

#endif
