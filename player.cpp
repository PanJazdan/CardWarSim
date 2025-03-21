#include "player.h"

Player::Player(int count){
    this->first = NULL;
    this->last = NULL;
    this->card_count = count;
} 

void Player::print_player(){
    Card* tmp1 = this->first;
    while(tmp1){
        std::cout<<*tmp1<<",";
        tmp1 = tmp1->get_prev();
    }
     std::cout<<"       "<<this->card_count<<std::endl;
}

void Player::move_card_at_end(Card* card){
    this->last->set_prev(card);
    card->set_next(this->last);
    this->last = card;
    this->last->null_prev();
}

void Player::first_change(){
    if(this->card_count <=1)
        return;
    this->first = this->first->get_prev();
    this->first->null_next();
    
}