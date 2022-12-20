#include <iostream>
#include "system.h"

using namespace std;


int main(){

    System* system = new System();

    //MATCH 1: 2018 World Cup final
    const char* m1_first[11] = {"Lloris","Pavard","Varane","Umtiti","Hernandez","Kante","Matuidi","Pogba","Griezmann","Mbappe","Giroud"};
    const char* m1_second[11] = {"Subasic","Vrsaljko","Strinic","Lovren","Vida","Rakitic","Modric","Brozovic","Perisic","Mandzukic","Rebic"};
    Match* m1 = new Match("FRANCE", "CROATIA", m1_first, 11, m1_second, 11);
    m1->create_event(SCORE_SECOND, SECOND, "Mandzukic", 18);
    m1->create_event(YELLOW_CARD, FIRST, "Kante", 27);
    m1->create_event(SCORE_FIRST, SECOND, "Perisic", 28);
    m1->create_event(SCORE_SECOND, FIRST, "Griezmann", 38);
    m1->create_event(YELLOW_CARD, FIRST, "Hernandez", 27);
    m1->create_event(SCORE_SECOND, FIRST, "Pogba", 59);
    m1->create_event(SCORE_SECOND, FIRST, "Mbappe", 65);
    m1->create_event(SCORE_FIRST, SECOND, "Mandzukic", 69);
    m1->create_event(YELLOW_CARD, SECOND, "Vrsaljko", 92);

    system->add_match(m1);

    //MATCH 2: 2014 World Cup final
    const char* m2_first[11] = {"Lloris","Pavard","Varane","Umtiti","Hernandez","Kante","Matuidi","Pogba","Griezmann","Mbappe","Giroud"};
    const char* m2_second[11] = {"Lloris","Pavard","Varane","Umtiti","Hernandez","Kante","Matuidi","Pogba","Griezmann","Mbappe","Giroud"};
    Match* m2 = new Match("GERMANY", "ARGENTINA", m2_first, 11, m2_second, 11);
    m2->create_event(YELLOW_CARD, FIRST, "Bastian Schweinsteiger", 29);
    m2->create_event(YELLOW_CARD, FIRST, "Benedikt Höwedes", 33);
    m2->create_event(YELLOW_CARD, SECOND, "Javier Mascherano", 64);
    m2->create_event(YELLOW_CARD, SECOND, "Sergio Agüero", 65);
    m2->create_event(SCORE_SECOND, FIRST, "Mario Götze", 113);
    
    system->add_match(m2);

    //MATCH 3: 2010 World Cup final
    const char* m3_first[11] = {"Lloris","Pavard","Varane","Umtiti","Hernandez","Kante","Matuidi","Pogba","Griezmann","Mbappe","Giroud"};
    const char* m3_second[11] = {"Lloris","Pavard","Varane","Umtiti","Hernandez","Kante","Matuidi","Pogba","Griezmann","Mbappe","Giroud"};
    Match* m3 = new Match("Netherlands", "Spain", m3_first, 11, m3_second, 11);
    m3->create_event(YELLOW_CARD, FIRST, "Robin van Persie", 15);
    m3->create_event(YELLOW_CARD, SECOND, "Carles Puyol", 17);
    m3->create_event(YELLOW_CARD, FIRST, "Mark vam Bommel", 22);
    m3->create_event(YELLOW_CARD, SECOND, "Sergio Ramos", 23);
    m3->create_event(YELLOW_CARD, FIRST, "Nigel de Jong", 28);
    m3->create_event(YELLOW_CARD, FIRST, "Giovanni van Bronckhorst", 54);
    m3->create_event(YELLOW_CARD, FIRST, "John Heitinga", 57);
    m3->create_event(YELLOW_CARD, SECOND, "Joan Capdevila", 67);
    m3->create_event(YELLOW_CARD, FIRST, "Arjen Robben", 84);
    m3->create_event(RED_CARD, FIRST, "John Heitinga", 109);
    m3->create_event(YELLOW_CARD, FIRST, "Gregory van der Wiel", 111);
    m3->create_event(SCORE_FIRST, SECOND, "Andres Iniesta", 116);
    m3->create_event(YELLOW_CARD, FIRST, "Joris Mathijsen", 117);
    m3->create_event(YELLOW_CARD, SECOND, "Andres Iniesta", 118);
    m3->create_event(YELLOW_CARD, SECOND, "Xavi Hernández", 120);
    
    system->add_match(m3);

    
            system->print_info();
            
    

        
            
            
        

        
            system->print_info();
            delete system;
            
        

       
            System* system2 = new System(*system);
            system2->print_info();
            delete system;
            delete system2;
            
        
            
        
            cout << "No such Test Case. Please input again." << endl;
            
        
    
    return 0;
}