#include <iostream>
#include "player_hand.h"
#include "card.h"

PlayerHand::PlayerHand() {
  //card 1
  player_hand[0].SetCardName("X");
  player_hand[0].SetCardRank(0);
  player_hand[0].SetCardSuit(0);

  //card 2
  player_hand[1].SetCardName("X");
  player_hand[1].SetCardRank(0);
  player_hand[1].SetCardSuit(0);

  //card 3
  player_hand[2].SetCardName("X");
  player_hand[2].SetCardRank(0);
  player_hand[2].SetCardSuit(0);

  //card 4
  player_hand[3].SetCardName("X");
  player_hand[3].SetCardRank(0);
  player_hand[3].SetCardSuit(0);

  //card 5
  player_hand[4].SetCardName("X");
  player_hand[4].SetCardRank(0);
  player_hand[4].SetCardSuit(0);

  hand_rank = 0;
}

Card PlayerHand::GetPlayerHandArray() {
  return *player_hand;
}

Card PlayerHand::GetPlayerHandCard(int i) {
  return player_hand[i];
}

int PlayerHand::GetPlayerHandRank() {
  return hand_rank;
}

void PlayerHand::SetPlayerHandCard(int i, Card card) {
  player_hand[i] = card;
}

void PlayerHand::SetPlayerHandRank(int i) {
  hand_rank = i;
}
