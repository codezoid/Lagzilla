#include <iostream>
#include "deck.h"
#include "card.h"

Deck::Deck() {
  //2c
  deck[0].SetCardName("2c");
  deck[0].SetCardRank(2);
  deck[0].SetCardSuit(1);

  //3c
  deck[1].SetCardName("3c");
  deck[1].SetCardRank(3);
  deck[1].SetCardSuit(1);

  //4c
  deck[2].SetCardName("4c");
  deck[2].SetCardRank(4);
  deck[2].SetCardSuit(1);

  //5c
  deck[3].SetCardName("5c");
  deck[3].SetCardRank(5);
  deck[3].SetCardSuit(1);

  //6c
  deck[4].SetCardName("6c");
  deck[4].SetCardRank(6);
  deck[4].SetCardSuit(1);

  //7c
  deck[5].SetCardName("7c");
  deck[5].SetCardRank(7);
  deck[5].SetCardSuit(1);

  //8c
  deck[6].SetCardName("8c");
  deck[6].SetCardRank(8);
  deck[6].SetCardSuit(1);

  //9c
  deck[7].SetCardName("9c");
  deck[7].SetCardRank(9);
  deck[7].SetCardSuit(1);

  //Tc
  deck[8].SetCardName("Tc");
  deck[8].SetCardRank(10);
  deck[8].SetCardSuit(1);

  //Jc
  deck[9].SetCardName("Jc");
  deck[9].SetCardRank(11);
  deck[9].SetCardSuit(1);

  //Qc
  deck[10].SetCardName("Qc");
  deck[10].SetCardRank(12);
  deck[10].SetCardSuit(1);

  //Kc
  deck[11].SetCardName("Kc");
  deck[11].SetCardRank(13);
  deck[11].SetCardSuit(1);

  //Ac
  deck[12].SetCardName("Ac");
  deck[12].SetCardRank(14);
  deck[12].SetCardSuit(1);

  //2d
  deck[13].SetCardName("2d");
  deck[13].SetCardRank(2);
  deck[13].SetCardSuit(2);

  //3d
  deck[14].SetCardName("3d");
  deck[14].SetCardRank(3);
  deck[14].SetCardSuit(2);

  //4d
  deck[15].SetCardName("4d");
  deck[15].SetCardRank(4);
  deck[15].SetCardSuit(2);

  //5d
  deck[16].SetCardName("5d");
  deck[16].SetCardRank(5);
  deck[16].SetCardSuit(2);

  //6d
  deck[17].SetCardName("6d");
  deck[17].SetCardRank(6);
  deck[17].SetCardSuit(2);

  //7d
  deck[18].SetCardName("7d");
  deck[18].SetCardRank(7);
  deck[18].SetCardSuit(2);

  //8d
  deck[19].SetCardName("8d");
  deck[19].SetCardRank(8);
  deck[19].SetCardSuit(2);

  //9d
  deck[20].SetCardName("9d");
  deck[20].SetCardRank(9);
  deck[20].SetCardSuit(2);

  //Td
  deck[21].SetCardName("Td");
  deck[21].SetCardRank(10);
  deck[21].SetCardSuit(2);

  //Jd
  deck[22].SetCardName("Jd");
  deck[22].SetCardRank(11);
  deck[22].SetCardSuit(2);

  //Qd
  deck[23].SetCardName("Qd");
  deck[23].SetCardRank(12);
  deck[23].SetCardSuit(2);

  //Kh
  deck[24].SetCardName("Kh");
  deck[24].SetCardRank(13);
  deck[24].SetCardSuit(2);

  //Ad
  deck[25].SetCardName("Ad");
  deck[25].SetCardRank(14);
  deck[25].SetCardSuit(2);

  //2h
  deck[26].SetCardName("2h");
  deck[26].SetCardRank(2);
  deck[26].SetCardSuit(3);

  //3h
  deck[27].SetCardName("3h");
  deck[27].SetCardRank(3);
  deck[27].SetCardSuit(3);

  //4h
  deck[28].SetCardName("4h");
  deck[28].SetCardRank(4);
  deck[28].SetCardSuit(3);

  //5h
  deck[29].SetCardName("5h");
  deck[29].SetCardRank(5);
  deck[29].SetCardSuit(3);

  //6h
  deck[30].SetCardName("6h");
  deck[30].SetCardRank(6);
  deck[30].SetCardSuit(3);

  //7h
  deck[31].SetCardName("7h");
  deck[31].SetCardRank(7);
  deck[31].SetCardSuit(3);

  //8h
  deck[32].SetCardName("8h");
  deck[32].SetCardRank(8);
  deck[32].SetCardSuit(3);

  //9h
  deck[33].SetCardName("9h");
  deck[33].SetCardRank(9);
  deck[33].SetCardSuit(3);

  //Th
  deck[34].SetCardName("Th");
  deck[34].SetCardRank(10);
  deck[34].SetCardSuit(3);

  //Jh
  deck[35].SetCardName("Jh");
  deck[35].SetCardRank(11);
  deck[35].SetCardSuit(3);

  //Qh
  deck[36].SetCardName("Qh");
  deck[36].SetCardRank(12);
  deck[36].SetCardSuit(3);

  //Kh
  deck[37].SetCardName("Kh");
  deck[37].SetCardRank(13);
  deck[37].SetCardSuit(3);

  //Ah
  deck[38].SetCardName("Ah");
  deck[38].SetCardRank(14);
  deck[38].SetCardSuit(3);

  //2s
  deck[39].SetCardName("2s");
  deck[39].SetCardRank(2);
  deck[39].SetCardSuit(4);

  //3s
  deck[40].SetCardName("3s");
  deck[40].SetCardRank(3);
  deck[40].SetCardSuit(4);

  //4s
  deck[41].SetCardName("4s");
  deck[41].SetCardRank(4);
  deck[41].SetCardSuit(4);

  //5s
  deck[42].SetCardName("5s");
  deck[42].SetCardRank(5);
  deck[42].SetCardSuit(4);

  //6s
  deck[43].SetCardName("6s");
  deck[43].SetCardRank(6);
  deck[43].SetCardSuit(4);

  //7s
  deck[44].SetCardName("7s");
  deck[44].SetCardRank(7);
  deck[44].SetCardSuit(4);

  //8s
  deck[45].SetCardName("8s");
  deck[45].SetCardRank(8);
  deck[45].SetCardSuit(4);

  //9s
  deck[46].SetCardName("9s");
  deck[46].SetCardRank(9);
  deck[46].SetCardSuit(4);

  //Ts
  deck[47].SetCardName("Ts");
  deck[47].SetCardRank(10);
  deck[47].SetCardSuit(4);

  //Js
  deck[48].SetCardName("Js");
  deck[48].SetCardRank(11);
  deck[48].SetCardSuit(4);

  //Qs
  deck[49].SetCardName("Qs");
  deck[49].SetCardRank(12);
  deck[49].SetCardSuit(4);

  //Ks
  deck[50].SetCardName("Ks");
  deck[50].SetCardRank(13);
  deck[50].SetCardSuit(4);

  //As
  deck[51].SetCardName("As");
  deck[51].SetCardRank(14);
  deck[51].SetCardSuit(4);
}

Card Deck::GetDeckCard(int i) {
  return deck[i];
}

void Deck::SetDeckCard(int i, Card card) {
  deck[i] = card;
}
