#include <iostream>
#include "pot.h"

#include "card.h"

Pot::Pot() {
  pot_amount = 0;
  betting_round_count = 1;
  minimum_raise_amount = 0;
  small_blind_amount = 0;
  big_blind_amount = 0;
}

int Pot::GetPotAmount() {
  return pot_amount;
}

int Pot::GetBettingRoundCount() {
  return betting_round_count;
}

int Pot::GetMinimumRaiseAmount() {
  return minimum_raise_amount;
}

int Pot::GetSmallBlindAmount() {
  return small_blind_amount;
}

int Pot::GetBigBlindAmount() {
  return big_blind_amount;
}

Card Pot::GetCommunityCard(int i) {
  return community_cards[i];
}

void Pot::SetPotAmount(int i) {
  pot_amount = i;
}

void Pot::SetBettingRoundCount(int i) {
  betting_round_count = i;
}

void Pot::SetMinimumRaiseAmount(int i) {
  minimum_raise_amount = i;
}

void Pot::SetSmallBlindAmount(int i) {
  small_blind_amount = i;
}

void Pot::SetBigBlindAmount(int i) {
  big_blind_amount = i;
}

void Pot::SetCommunityCard(int i, Card card) {
  community_cards[i] = card;
}
