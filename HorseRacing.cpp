#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

//prototype
class Horse{
    private:
        int position;
    public:
        Horse();
        void advance();
        int getPosition();

};

//constructor class horse

Horse::Horse(){
    Horse::position = 0;
    //tanda"::"untuk parameter class kuda(Horse)
    srand(time(NULL));
} 

//Advance=maju,if 0 horse can't moving, if 1 horse move a dot
void Horse::advance(){
    int moveChance = rand()%2;

    if(moveChance == 1){
        position++;
    } 

}

int Horse::getPosition(){
    return position;
}

class Race{
    private:
        Horse h[5]; //how many horse in race?
    public:
        int length;
        Race();
        Race(int length);
        void printLane(int horseNum);
        void start();
};

Race::Race(){
    length = 25;
} //end Race

Race::Race(int length){
    Race::length = length;
} //end Race(int length)

//Print Map Horse Race
void Race::printLane(int horseNum){
    for (int i = 0; i < length; i++){
        int location = h[horseNum].getPosition();
        if (i == location){
            cout << horseNum +1; //+1 for numbering purposes. Normal counting starts at 1, not 0
        } 
        else{
            cout << ".";
        } 
    } 
        cout << endl;
} 

void Race::start(){
    bool keepGoing = true;


    for(int n = 0; n < 5; n++){
        printLane(n); //initial print statement
    } 

    cout << "\nReady, set, go!\n" << endl;
    cin.ignore();

    while(keepGoing){
        for(int n = 0;  n < 5; n++){
            h[n].advance();
            printLane(n);
            if(h[n].getPosition() == (length)){ //win condition
                keepGoing = false;
                cout << "Horse " << n+1 << " wins!" << endl; // the +1 is because of numbering purposes
            } 
        } 

        cout << "\nPress enter to continue: " << endl; 
        cin.ignore(); 

        cout << "\n" << endl;

    } 
} 

main(){

    cout << "Welcome to the Horse Racing Game! Press Enter to begin the race." << endl;
    cin.ignore();

    Race race;
    race.start();
    cout << "Thank You for Playing :)" << endl;
    cin.ignore();
} 
