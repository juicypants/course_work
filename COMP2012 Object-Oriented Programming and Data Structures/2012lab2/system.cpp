#include <iostream>
#include <cstring>
#include "system.h"

using namespace std;

//helper functions for Event::print_info()
const char* get_team(Team_Type type, const char* first_country_name, const char* second_country_name){
    if(type == FIRST){
        return first_country_name;
    }
    else{
        return second_country_name;
    }
}

void print_action(Event_Type type, const char* first_country_name, const char* second_country_name){
    switch (type){
        case SCORE_FIRST:
            cout << "scores 1 points for " << second_country_name << "!!!";
            break;
        case SCORE_SECOND:
            cout << "scores 1 points for " << first_country_name << "!!!";
            break;
        case YELLOW_CARD:
            cout << "received a yellow card.";
            break;
        case RED_CARD:
            cout << "received a red card!!";
            break;
        default:
            cout << "Unknown type of Action.";
    }
}

//class Event implementation
Event::Event(Event_Type event_type, Team_Type team_type, const char* name, int minute)
: event_type{event_type}, team_type{team_type}, minute{minute} {
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

Event::Event(const Event& event): event_type{event.event_type}, team_type{event.team_type}, minute{event.minute} {
    name = new char[strlen(event.name)+1];
    strcpy(name, event.name);
}

Event::~Event(){
    delete [] name;
}

void Event::print_info(const char* first_country_name, const char* second_country_name) const {
    const char* team = get_team(team_type, first_country_name, second_country_name);
    cout << "At minute " << minute << ", " << name << " from " << team << " ";
    print_action(event_type, first_country_name, second_country_name);
}

//class Match implementation
//Task1: Constructor
Match::Match(const char* first_country_name, const char* second_country_name, const char** first_players, int num_first_players, const char** second_players, int num_second_players){
    this->first_country_name = new char[strlen(first_country_name)+1];
    strcpy(this->first_country_name,first_country_name);
    this->second_country_name = new char[strlen(second_country_name)+1];
    strcpy(this->second_country_name,second_country_name);
    this->num_first_players = num_first_players;
    this->num_second_players = num_second_players;
    this->first_players = new char*[num_first_players];
    this->second_players = new char*[num_second_players];
    for (int i=0;i<num_first_players;i++){
        this->first_players[i] = new char[strlen(first_players[i])+1];
        strcpy(this->first_players[i],first_players[i]);
    }
    for (int i=0;i<num_second_players;i++){
        this->second_players[i] = new char[strlen(second_players[i])+1];
        strcpy(this->second_players[i],second_players[i]);
    }
    
    for (int i=0;i<30;i++){
        this->events[i] = nullptr;
    }


}

//Task2: Copy Constructor
Match::Match(const Match& match){
    
    for (int i=0;i<30;i++){
       if (match.events[i] != nullptr){
           this->create_event(match.events[i]->event_type,match.events[i]->team_type,match.events[i]->name,match.events[i]->minute);
       }
       else{
            this->events[i] = nullptr;
       }
    }
    this->first_country_name = new char[strlen(match.first_country_name)+1];
    strcpy(this->first_country_name,match.first_country_name);
    this->second_country_name = new char[strlen(match.second_country_name)+1];
    strcpy(this->second_country_name,match.second_country_name);
    
    this->first_players = new char*[match.num_first_players];
    this->second_players = new char*[match.num_second_players];
    for (int i=0;i<match.num_first_players;i++){
        this->first_players[i] = new char[strlen(match.first_players[i])+1];
        strcpy(this->first_players[i],match.first_players[i]);
    }

    for (int i=0;i<match.num_second_players;i++){
        this->second_players[i] = new char[strlen(match.second_players[i])+1];
        strcpy(this->second_players[i],match.second_players[i]);
    }

    this->num_first_players = match.num_first_players;
    this->num_second_players = match.num_second_players;
}

//Task3: Destructor
Match::~Match(){
    delete [] this->first_country_name;
    delete [] this->second_country_name;
    this->first_country_name = nullptr;
    this->second_country_name = nullptr;

    for (int i=0;i<this->num_first_players;i++){
        delete [] this->first_players[i];
        this->first_players[i] = nullptr;
    }
    for (int i=0;i<this->num_second_players;i++){
        delete [] this->second_players[i];
        this->second_players[i] = nullptr;
    }
    delete [] this->first_players;
    delete [] this->second_players;
    this->first_players = nullptr;
    this->second_players = nullptr;

    for (int i=0;i<30;i++){
        if (this->events[i] != nullptr){
            delete this->events[i];
            this->events[i]=nullptr;
        }
    }


}

void Match::create_event(Event_Type event_type, Team_Type team_type, const char* name, int minute){
    if(num_event < 30){
        events[num_event] = new Event{event_type, team_type, name, minute};
        num_event++;
    }
}

void Match::print_info() const {
    cout << "---LISTING PLAYERS---" << endl;

    cout << "FIRST COUNTRY: " << first_country_name << endl;
    
    for(int i = 0; i < num_first_players; ++i){
        cout << first_players[i];
        if(i != num_first_players-1){
            cout << ", ";
        }
    }
    cout << "\n\nSECOND COUNTRY: " << second_country_name << endl;
    for(int i = 0; i < num_second_players; ++i){
        cout << second_players[i];
        if(i != num_second_players-1){
            cout << ", ";
        }
    }

    cout << "\n\nTHE GAME START!!" << endl;
    for(int i = 0; i < num_event; ++i){
        events[i]->print_info(first_country_name, second_country_name);
        cout << endl;
    }

    cout << "THE GAME ENDS!!" << endl;
}

//class System implementation
System::System(): matches{}{

}

System::System(const System& system): num_matches{system.num_matches} {
    for(int i = 0; i < num_matches; ++i){
        Match* src_match = system.matches[i];
        matches[i] = new Match{*src_match};
    }
}

System::~System(){
    for(int i = 0; i < num_matches; ++i){
        delete matches[i];
    }
}

void System::add_match(Match* match){
    matches[num_matches] = match;
    num_matches++;
}


void System::print_info() const {
    cout << "---SYSTEM PRINTING INFO---" << endl;
    for(int i = 0; i < num_matches; ++i){
        cout << "--------------------------" << endl;
        cout << "MATCH " << i+1 << endl;
        matches[i]->print_info();
        cout << endl;
    }
    cout << "---SYSTEM END PRINTING---" << endl;
}
