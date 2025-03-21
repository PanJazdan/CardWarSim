#ifndef CARD
#define CARD
#include <iostream>

class Card{
    private:
    Card* next;
    Card* prev;
    int value;
     

    public:
    Card();
    Card(int val);
    void null_next();
    void null_prev();
    void set_next(Card* card);
    void set_prev(Card* card);
    Card* get_next() const;
    Card* get_prev() const;
    int get_value() const;
    void set_value(int val);
    void check_next() const;
    void check_prev() const;
    friend std::ostream& operator<<(std::ostream &os, Card card);
};

#endif