#include "card.h"
#include "player.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

#define L_K 52 //max liczba kart

void swap_value(Card &a,Card &b){
    int val = a.get_value();
    a.set_value(b.get_value());
    b.set_value(val);
}

void print(Card talia[L_K]){ //funkcja wypisuje w dwóch kolumnach wartości
    for(int i=0;i<L_K/2;i++)
        std::cout<<talia[i]<<"      "<<talia[i+L_K/2]<<std::endl;
    std::cout<<std::endl;
}

bool walcz(Player &gracz1,Player &gracz2,int level){ //główna mechanika wojny
    if(gracz1.card_count < level+1 || gracz2.card_count < level+1){
    //    std::cout<<"KONIEC GRY"<<std::endl;
        return false;
    }

    Card* tmp1 = gracz1.first;
    Card* tmp2 = gracz2.first;
    for(int i=0;i<level;i++){ //pętla potrzebna żeby dzialało w razie wielokrotnej wojny, wywołanie rekurencyjne
        tmp1 = tmp1->get_prev();
        tmp2 = tmp2->get_prev();
    }
    if(tmp1->get_value() > tmp2->get_value()){
        for(int i=0 ;i<=level ;i++){ //ta pętla tak samo potrzebna
            tmp1 = gracz1.first;
            tmp2 = gracz2.first;
            gracz1.first_change();
            gracz2.first_change();
            gracz1.move_card_at_end(tmp1);
            gracz1.move_card_at_end(tmp2);
            gracz1.card_count++;
            gracz2.card_count--;
        }
    }
    else if(tmp1->get_value() < tmp2->get_value()){
        for(int i=0 ;i<=level ;i++){ //ta pętla tak samo potrzebna
            tmp1 = gracz1.first;
            tmp2 = gracz2.first;
            gracz2.first_change();
            gracz1.first_change();
            gracz2.move_card_at_end(tmp2);
            gracz2.move_card_at_end(tmp1);
            gracz2.card_count++;
            gracz1.card_count--;
        }
    }
    else{
        level = level+2;
        return walcz(gracz1,gracz2,level);
    }
    return true;
}


int main(void){
    std::srand(std::time(0));

    std::ofstream File("dane.txt");

    File << "LP\tRUNDY\tAVG1\t\tAVG2\t\tWIN\n";
    int round_avg =0;
    int winner1=0,winner2=0;
    float total_avg1=0, total_avg2=0;
    int total_rounds = 200;

    for(int i=0; i<total_rounds ;i++){ //opcjonalna pętla do zbierania danych

    Player gracz1(L_K/2), gracz2(L_K/2);
    Card talia[L_K]; //tworzenie talii
    int value = L_K/4; 

    for(int i = 0 ; i<L_K ;i++){
        talia[i].set_value(i%value + 2); //ustawianie kart tak że są dokładnie 4 takie same wartości
    }


    int random1, random2; //dwa losowe indexy tablicy talii
    for(int i=0 ; i<L_K*4 ; i++){
        random1 = rand()%L_K;
        random2 = rand()%L_K;
        swap_value(talia[random1],talia[random2]);  //zamiana losowych dwóch wartości
                                                    // w obrębie tablicy aby uzyskać potasowanie talii
    }
  
    /////////////// USTAWIENIE PIERWSZEGO GRACZA
        gracz1.first = talia; //ustawiam podział na pierwszy i środkowy element całej talii
        gracz1.last = talia-1 + L_K/2;

        Card* tmp1 = gracz1.first; //dwa temporary elementy by ustalić liste i sąsiedztwo
        Card* tmp2 = gracz1.first+1;
        while(tmp1 != gracz1.last){
            tmp1->set_prev(tmp2); 
            tmp2->set_next(tmp1);
            tmp1 = tmp2;
            tmp2++;
        }
    
    //    gracz1.print_player();
    ///////////////

    /////////////// USTAWIENIE DRUGIEGO GRACZA
        gracz2.first = talia + L_K/2;
        gracz2.last = talia + L_K-1;

        tmp1 = gracz2.first;
        tmp2 = gracz2.first+1;

        while(tmp1 != gracz2.last){
            tmp1->set_prev(tmp2); 
            tmp2->set_next(tmp1);
            tmp1 = tmp2;
            tmp2++;
        }

    //    gracz2.print_player();
    ///////////////


    float avg1=0,avg2=0;
    for(int i=0; i<L_K/2 ;i++){ //policzenie se średniej dla każdej z talii początkowych
        avg1 = avg1 + talia[i].get_value();
        avg2 = avg2 + talia[i+L_K/2].get_value();
    }
    avg1 = avg1/(float)L_K;
    avg2 = avg2/(float)L_K;

    total_avg1 = total_avg1 + avg1;
    total_avg2 = total_avg2 + avg2;
    
    //ofstream MyWriteFile("dane.txt");

    int rounds =0;
    while(walcz(gracz1,gracz2,0)){
        rounds++;
        // gracz1.print_player();
        // gracz2.print_player();
        //std::cout<<std::endl;
    }
    // std::cout<<rounds<<std::endl;
    // std::cout<<avg1<<"\n"<<avg2<<std::endl;

    int winner=0;

    if(gracz1.card_count > gracz2.card_count){
        // std::cout<<"GRACZ 1 wygrał"<<std::endl;
        winner = 1;
        winner1++;
    }
    else{
        // std::cout<<"GRACZ 2 wygrał"<<std::endl;
        winner = 2;
        winner2++;
    }
    
    round_avg = round_avg + rounds;

    File << i+1<<"\t";
    File << rounds<<"\t\t";
    File << avg1<<"\t\t";
    File << avg2<<"\t\t";
    File << winner <<"\n";

    }
    round_avg  = round_avg/total_rounds;
    total_avg1 = total_avg1/total_rounds;
    total_avg2 = total_avg2/total_rounds;
    File <<"Średnio rund\t" << round_avg << "\n";
    File <<"Zwycięstwa gracza1\t" << winner1 << "\n";
    File <<"Zwycięstwa gracza2\t" << winner2 << "\n";
    File <<"Średnia średnich talii począkowych gracza1\t" << total_avg1 << "\n";
    File <<"Średnia średnich talii począkowych gracza2\t" << total_avg2 << "\n";
    File.close();


    return 0;
}