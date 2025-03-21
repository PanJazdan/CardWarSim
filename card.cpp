#include "card.h"

Card::Card(){
    this->next = NULL;
    this->prev = NULL;
    this->value = 0;
}

Card::Card(int val){
    this->next = NULL;
    this->prev = NULL;
    this->value = val;
}
 
void Card::null_next(){
    this->next =NULL;
}

void Card::null_prev(){
    this->prev = NULL;
}

void Card::set_next(Card* card){
    this->next = card;
}

void Card::set_prev(Card* card){
    this->prev = card;
}

int Card::get_value() const{
    return this->value;
}

void Card::set_value(int val){
    this->value = val;
}

std::ostream& operator<<(std::ostream& os, Card card){
    os << card.value;
    return os;
}

void Card::check_next() const{
    if(this->next)
        std::cout<<this->next->get_value();
    else
        std::cout<<"NULL";
}

void Card::check_prev() const{
    if(this->prev)
        std::cout<<this->prev->get_value();
    else
        std::cout<<"NULL";
}

Card* Card::get_next() const{
    return this->next;
}
Card* Card::get_prev() const{
    return this->prev;
}
