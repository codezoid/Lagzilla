#include <iostream>
#include "player.h"
#include "card.h"

Player::Player() {
  position = 0;
  stack_amount = 0;
  invest_amount = 0;
  folded_status = false;
  acted_status = false;
  on_the_clock_status = false;
}

int Player::GetPosition() {
  return position;
}

int Player::GetStackAmount() {
  return stack_amount;
}

int Player::GetInvestAmount() {
  return invest_amount;
}

bool Player::GetFoldedStatus() {
  return folded_status;
}

bool Player::GetActedStatus() {
  return acted_status;
}

bool Player::GetOnTheClockStatus() {
  return on_the_clock_status;
}

Card Player::GetHoleCard(int i) {
  return hole_cards[i];
}

void Player::SetPosition(int i) {
  position = i;
}

void Player::SetStackAmount(int i) {
  stack_amount = i;
}

void Player::SetInvestAmount(int i) {
  invest_amount = i;
}

void Player::SetFoldedStatus(bool i) {
  folded_status = i;
}

void Player::SetActedStatus(bool i) {
  acted_status = i;
}

void Player::SetOnTheClockStatus(bool i) {
  on_the_clock_status = i;
}

void Player::SetHoleCard(int i, Card card) {
  hole_cards[i] = card;
}
