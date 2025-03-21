#ifndef PLAY
#define PLAY
#include "card.h"

class Player{
    public:
    Card* first;
    Card* last;
    int card_count;

    public: 
    Player(int count);
    void print_player();
    void move_card_at_end(Card* card);
    void first_change();

    
};

#endif