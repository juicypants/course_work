#include <iostream>
#include "pa1.h"
#include <fstream>

using namespace std;

const int VALUE_COMPARE_LEN = 5; //Task 4
const int MAX_INPUT_LEN = 16; // For Task 1,2,3

void printNums(int cards_num[], int length){
    cout<<"cards="<<endl;
    for(int i=0; i<length; ++i){
        cout<<cards_num[i];
        if(i!=length-1){
            cout<<", ";
        }
    }
    cout<<endl;
}

void printChar(char cards[], int length){
    cout<<"cards_num="<<endl;
    for(int i=0; i<length; ++i){
        cout<<cards[i];
        if(i!=length-1){
            cout<<", ";
        }
    }
    cout<<endl;
}

void testTask1(char cards[], int length, int cards_num[]){
    cout << "************************ Task 1 test settings ************************" << endl;
    printChar(cards, length);
    cout << "length=" << endl;
    cout << length << endl;
    cout << "********************** Calling Task 1 function ***********************" << endl;
    cardToNumbers(cards, length, cards_num);
    cout << "After function call:" << endl;
    printNums(cards_num, length);
}

void testTask2(int cards_num[], int length){
    cout << "************************ Task 2 test settings ************************" << endl;
    cout <<"Before sorting:"<<endl;
    printNums(cards_num, length);
    cout << "length=" << endl;
    cout << length << endl;
    cout << "********************** Calling Task 2 function ***********************" << endl;
    sortCards(cards_num, length);
    cout <<"After sorting:"<<endl;
    printNums(cards_num, length);
}

void testTask3(char cards[], int length, int cards_num[]){
    cout << "************************ Task 3 test settings ************************" << endl;
    printChar(cards, length);
    cout << "length=" << endl;
    cout << length << endl;
    cout << "********************** Calling Task 3 function ***********************" << endl;
    bool result = isContinuous(cards, length, cards_num);
    cout << "result="<<endl;
    cout <<boolalpha<< result<<endl;
}

void testTask4(char handA[], char handB[], int& valueA, int& valueB){
    cout << "************************ Task 4 test settings ************************" << endl;
    cout <<"hand A ";
    printChar(handA, VALUE_COMPARE_LEN);
    cout <<"hand B ";
    printChar(handB, VALUE_COMPARE_LEN);
    cout << "********************** Calling Task 4 function ***********************" << endl;
    int result = compareValue(handA, handB, valueA, valueB);
    cout <<"value of hand A="<<endl;
    cout << valueA<<endl;
    cout <<"value of hand B="<<endl;
    cout << valueB<<endl;
    cout <<"result"<<endl;
    cout <<result<<endl;
}


int test(int testCase)
{
    

    cout << "Please enter the test case number: ";
    cout << endl;
    cout << "============================================" << endl;
    cout << "Showing the output for test case " << testCase << ":" << endl;

    /* Task 1 */
    if(testCase == 1) //test digits
    {
        char cards[] = {'2', '3', '4', '5', '6', '7', '8', '9'};
        int length = 8;
        int cards_num[8];
        testTask1(cards, length, cards_num);
    }

    else if(testCase == 2) //test 10
    {
        char cards[] = {'!'};
        int length = 1;
        int cards_num[1];
        testTask1(cards, length, cards_num);
    }

    else if(testCase == 3) //test J, Q, K, A
    {
        char cards[] = {'A', 'J', 'Q', 'K'};
        int length = 4;
        int cards_num[4];
        testTask1(cards, length, cards_num);
    }

    else if(testCase == 4) //test joker
    {
        char cards[] = {'*'};
        int length = 1;
        int cards_num[1];
        testTask1(cards, length, cards_num);
    }

    else if(testCase == 5) //test 1-13
    {
        char cards[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '!', 'J', 'Q', 'K'};
        int length = 13;
        int cards_num[13];
        testTask1(cards, length, cards_num);
    }

    else if(testCase == 6) //test 0-13
    {
        char cards[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '!', 'J', 'Q', 'K', '*'};
        int length = 14;
        int cards_num[14];
        testTask1(cards, length, cards_num);
    }

    else if(testCase == 7) //test 0-13-1
    {
        char cards[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '!', 'J', 'Q', 'K', '*', 'A'};
        int length = 15;
        int cards_num[15];
        testTask1(cards, length, cards_num);
    }

    else if(testCase == 8) //test repeated digits
    {
        char cards[] = {'A', 'A', 'A', 'A'};
        int length = 4;
        int cards_num[4];
        testTask1(cards, length, cards_num);
    }

    else if(testCase == 9) //test repeated digits
    {
        char cards[] = {'9', '9', '2', '2'};
        int length = 4;
        int cards_num[4];
        testTask1(cards, length, cards_num);
    }

    else if(testCase == 10) //test repeated digits
    {
        char cards[] = {'K', 'K', 'Q', 'Q', 'J', 'J'};
        int length = 6;
        int cards_num[6];
        testTask1(cards, length, cards_num);
    }

    else if(testCase == 11) //test repeated digits
    {
        char cards[] = {'A', 'A', 'A', '!', '!', '!', '!', '*', '*'};
        int length = 9;
        int cards_num[9];
        testTask1(cards, length, cards_num);
    }

    else if(testCase == 12) //test mixed cards
    {
        char cards[] = {'A', '2', '3', '9', '!', '*'};
        int length = 6;
        int cards_num[6];
        testTask1(cards, length, cards_num);
    }

    else if(testCase == 13) //test mixed cards
    {
        char cards[] = {'!', '!', '!', '!', '*', '*'};
        int length = 6;
        int cards_num[6];
        testTask1(cards, length, cards_num);
    }

    else if(testCase == 14) //test mixed cards
    {
        char cards[] = {'5', '5', '!', '!', '*', '*'};
        int length = 6;
        int cards_num[6];
        testTask1(cards, length, cards_num);
    }

    else if(testCase == 15) //test randomly
    {
        char cards[] = {'Q', 'J', 'Q', 'J', 'K', '!', '!', '!', '*', '*'};
        int length = 10;
        int cards_num[10];
        testTask1(cards, length, cards_num);
    }

    else if(testCase == 16) //test 0-13-1
    {
        char cards[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '!', 'J', 'Q', 'K', '*', 'A', '*'};
        int length = 16;
        int cards_num[16];
        testTask1(cards, length, cards_num);
    }

    /* Task 2 */
    else if(testCase == 17) // test length 1
    {
        int cards_num[] = {0};
        int length = 1;
        testTask2(cards_num, length);
    }

    else if(testCase == 18) // test length 2
    {
        int cards_num[] = {3, 2};
        int length = 2;
        testTask2(cards_num, length);
    }

    else if(testCase == 19) // test length 3
    {
        int cards_num[] = {6, 4, 11};
        int length = 3;
        testTask2(cards_num, length);
    }

    else if(testCase == 20) // test length 4
    {
        int cards_num[] = {10, 8, 5, 11};
        int length = 4;
        testTask2(cards_num, length);
    }

    else if(testCase == 21) // test length 5
    {
        int cards_num[] = {10, 8, 5, 11, 1};
        int length = 5;
        testTask2(cards_num, length);
    }

    else if(testCase == 22) // test length 6
    {
        int cards_num[] = {7,8,11,6,3,4};
        int length = 6;
        testTask2(cards_num, length);
    }

    else if(testCase == 23) // test length 7
    {
        int cards_num[] = {5,8,6,0,4,12,2};
        int length = 7;
        testTask2(cards_num, length);
    }

    else if(testCase == 24) // test length 8
    {
        int cards_num[] = {0,11,7,6,10,2,9,12};
        int length = 8;
        testTask2(cards_num, length);
    }

    else if(testCase == 25) // test length 9
    {
        int cards_num[] = {7,5,9,4,0,2,10,12,3};
        int length = 9;
        testTask2(cards_num, length);
    }

    else if(testCase == 26) // test length 10
    {
        int cards_num[] = {11,12,0,8,6,3,7,5,10,2};
        int length = 10;
        testTask2(cards_num, length);
    }

    else if(testCase == 27) // test length 11
    {
        int cards_num[] = {8,12,7,1,9,3,10,5,11,6,0};
        int length = 11;
        testTask2(cards_num, length);
    }

    else if(testCase == 28) // test length 12
    {
        int cards_num[] = {0,11,7,10,8,5,2,1,9,3,12,6};
        int length = 12;
        testTask2(cards_num, length);
    }

    else if(testCase == 29) // test length 13
    {
        int cards_num[] = {0,13,11,1,2,5,8,9,6,12,10,4,7};
        int length = 13;
        testTask2(cards_num, length);
    }

    else if(testCase == 30) // test length 14
    {
        int cards_num[] = {11,7,2,13,12,6,10,3,1,5,9,0,4,8};
        int length = 14;
        testTask2(cards_num, length);
    }

    else if(testCase == 31) // test length 15
    {
        int cards_num[] = {12,11,5,11,7,9,5,6,3,12,12,4,12,2,7};
        int length = 15;
        testTask2(cards_num, length);
    }

    else if(testCase == 32) // test length 16
    {
        int cards_num[] = {8,13,7,2,12,9,3,7,12,3,3,2,11,7,2,8};
        int length = 16;
        testTask2(cards_num, length);
    }

    else if(testCase == 33) // test random length 14
    {
        int cards_num[] = {10,10,11,12,12,9,6,12,5,3,6,10,11,11};
        int length = 14;
        testTask2(cards_num, length);
    }

    else if(testCase == 34) // test random length 1
    {
        int cards_num[] = {5};
        int length = 1;
        testTask2(cards_num, length);
    }

    else if(testCase == 35) // test random length 4
    {
        int cards_num[] = {1,1,1,1};
        int length = 4;
        testTask2(cards_num, length);
    }

    else if(testCase == 36) // test random length 14
    {
        int cards_num[] = {3,3,6,7,6,4,5,3,6,7,6,13,7,0};
        int length = 14;
        testTask2(cards_num, length);
    }

    else if(testCase == 37) // test random length 10
    {
        int cards_num[] = {2,3,10,13,4,9,6,10,9,1};
        int length = 10;
        testTask2(cards_num, length);
    }

    else if(testCase == 38) // test random length 5
    {
        int cards_num[] = {5,11,12,7,0};
        int length = 5;
        testTask2(cards_num, length);
    }

    else if(testCase == 39) // test random length 6
    {
        int cards_num[] = {3,2,9,13,1,2};
        int length = 6;
        testTask2(cards_num, length);
    }

    else if(testCase == 40) // test random length 7
    {
        int cards_num[] = {7,7,11,5,0,3,1};
        int length = 7;
        testTask2(cards_num, length);
    }

    /* Task 3 */
    // Without jokers and is a straight
    else if(testCase == 41) // test length 1
    {
        char cards [] = {'A'};
        int length = 1;
        int cards_num[1];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 42) // test length 2
    {
        char cards [] = {'J', '!'};
        int length = 2;
        int cards_num[2];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 43) // test length 3
    {
        char cards [] = {'K', 'J', 'Q'};
        int length = 3;
        int cards_num[3];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 44) // test length 4
    {
        char cards [] = {'A', 'K', 'Q', 'J'};
        int length = 4;
        int cards_num[4];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 45) // test length 5
    {
        char cards [] = {'3', '4', '5', '2', 'A'};
        int length = 5;
        int cards_num[5];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 46) // test length 6
    {
        char cards [] = {'2', '3', '4', '5', '7', '6'};
        int length = 6;
        int cards_num[6];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 47) // test length 7
    {
        char cards [] = {'K', 'A', 'J', 'Q', '!', '9', '8'};
        int length = 7;
        int cards_num[7];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 48) // test length 8
    {
        char cards [] = {'3', '2', 'A', '4', '6', '5', '7', '8'};
        int length = 8;
        int cards_num[8];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 49) // test length 9
    {
        char cards [] = {'4', '2', '7', '6', '3', '5', '9', '8', '!'};
        int length = 9;
        int cards_num[9];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 50) // test length 10
    {
        char cards [] = {'4', '2', '7', '6', 'A', '3', '5', '9', '8', '!'};
        int length = 10;
        int cards_num[10];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 51) // test length 11
    {
        char cards [] = {'9', '6', '4', '8', '7', 'J', '3', '!', '5', 'A', '2'};
        int length = 11;
        int cards_num[11];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 52) // test length 12
    {
        char cards [] = {'K', '3', 'Q', '5', 'J', '4', '6', '2', '7', '!', '9', '8'};
        int length = 12;
        int cards_num[12];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 53) // test length 13
    {
        char cards [] = {'!', 'A', '8', 'Q', '6', '4', '2', '9', '3', '5', '7', 'K', 'J'};
        int length = 13;
        int cards_num[13];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 54) // test length 14
    {
        char cards [] = {'A', '!', 'A', '8', 'Q', '6', '4', '2', '9', '3', '5', '7', 'K', 'J'};
        int length = 14;
        int cards_num[14];      

        testTask3(cards, length, cards_num);
    }

	// 14 
    // Without jokers and not a straight
        else if(testCase == 55) //length is 2
    {
        char cards [] = {'7', '!'};
        int length = 2;
        int cards_num[2];
    }


    else if(testCase == 56) //length is 3
    {
        char cards [] = {'4', '5', 'J'};     
        int length = 3;
        int cards_num[3];
    }


    else if(testCase == 57) //length is 4
    {
        char cards [] = {'J', '3', 'Q', '4'};
        int length = 4;
        int cards_num[4];
    }


    else if(testCase == 58) //length is 5
    {
        char cards [] = {'Q', '5', '2', '9', 'K'};
        int length = 5;
        int cards_num[5];
    }


    else if(testCase == 59) //length is 6
    {
        char cards [] = {'Q', '2', '6', '8', 'J', 'K'};
        int length = 6;
        int cards_num[6];
    }


    else if(testCase == 60) //length is 7
    {
        char cards [] = {'3', 'A', 'Q', '5', '2', '6', '7'};
        int length = 7;
        int cards_num[7];
    }

    else if(testCase == 61) //length is 8
    {
        char cards [] = {'6', 'A', '8', 'J', '!', '9', '7', 'Q'};
        int length = 8;
        int cards_num[8];
    }


    else if(testCase == 62) //length is 9
    {
        char cards [] = {'K', '4', '8', 'J', '5', 'A', 'Q', 'A', '6'};
        int length = 9;
        int cards_num[9];
    }


    else if(testCase == 63) //length is 10
    {
        char cards [] = {'A', '4', '3', '2', '9', 'Q', 'K', 'A', 'J', '!'};
        int length = 10;
        int cards_num[10];
    }


    else if(testCase == 64) //length is 11
    {
        char cards [] = {'8', 'K', '9', '7', 'Q', '4', '2', 'A', '3', 'J', '6'};
        int length = 11;
        int cards_num[11];
    }


    else if(testCase == 65) //length is 12
    {
        char cards [] = {'K', '9', 'Q', '4', '2', '3', '6', '!', 'A', '5', '7', '8'};
        int length = 12;
        int cards_num[12];
    }


    else if(testCase == 66) //length is 13
    {
        char cards [] = {'7', '9', '8', 'K', 'A', '!', 'A', 'Q', '2', '6', 'J', '4', '3'};
        int length = 13;
        int cards_num[13];
    }


    else if(testCase == 67) //length is 15
    {
        char cards [] = {'A', '!', 'A', '8', 'Q', '6', '4', '2', '9', '3', '5', '7', 'K', 'J', '2'};
        int length = 15;
        int cards_num[15];
    }

    // 14 + 13 test cases
    // with one joker
    else if(testCase == 68) // test length 1
    {
        char cards [] = {'*'};
        int length = 1;
        int cards_num[1];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 69) // test length 2
    {
        char cards [] = {'J', '*'};
        int length = 2;
        int cards_num[2];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 70) // test length 3
    {
        char cards [] = {'K', '*', 'J'};
        int length = 3;
        int cards_num[3];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 71) // test length 3
    {
        char cards [] = {'K', '3', '*'};
        int length = 3;
        int cards_num[3];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 72) // test length 4
    {
        char cards [] = {'7', '*', '5', '8'};
        int length = 4;
        int cards_num[4];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 73) // test length 4
    {
        char cards [] = {'7', '2', '*', '8'};
        int length = 4;
        int cards_num[4];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 74) // test length 5
    {
        char cards [] = {'3', 'A', '*', '5', 'J'};
        int length = 5;
        int cards_num[5];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 75) // test length 5
    {
        char cards [] = {'3', 'A', '*', '5', '2'};
        int length = 5;
        int cards_num[5];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 76) // test length 6
    {
        char cards [] = {'J', '8', '*', 'K', 'A', 'Q'};
        int length = 6;
        int cards_num[6];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 77) // test length 6
    {
        char cards [] = {'J', '9', '*', 'K', 'A', 'Q'};
        int length = 6;
        int cards_num[6];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 78) // test length 7
    {
        char cards [] = {'K', '3', '2', 'Q', '*', 'J', '4'};
        int length = 7;
        int cards_num[7];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 79) // test length 7
    {
        char cards [] = {'K', '!', '8', 'Q', '*', 'J', '9'};
        int length = 7;
        int cards_num[7];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 80) // test length 8
    {
        char cards [] = {'*', '2', '7', '6', 'Q', '5', 'A', '!'};
        int length = 8;
        int cards_num[8];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 81) // test length 8
    {
        char cards [] = {'*', '2', '7', '6', '3', '5', 'A', '4'};
        int length = 8;
        int cards_num[8];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 82) // test length 9
    {
        char cards [] = {'K', '2', '7', '6', 'Q', '5', '*', '!', 'A'};
        int length = 9;
        int cards_num[9];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 83) // test length 9
    {
        char cards [] = {'3', '2', '7', '6', '4', '5', '*', '9', 'A'};
        int length = 9;
        int cards_num[9];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 84) // test length 10
    {
        char cards [] = {'5', '4', '3', 'K', 'Q', '8', '6', '*', '7', '!'};
        int length = 10;
        int cards_num[10];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 85) // test length 10
    {
        char cards [] = {'5', '4', '3', 'J', 'Q', '8', '6', '*', '7', '!'};
        int length = 10;
        int cards_num[10];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 86) // test length 11
    {
        char cards [] = {'9', '6', '4', '8', '*', 'Q', '3', '!', '5', 'A', '2'};
        int length = 11;
        int cards_num[11];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 87) // test length 11
    {
        char cards [] = {'9', '6', '4', '8', '*', 'J', '3', '!', '5', 'A', '2'};
        int length = 11;
        int cards_num[11];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 88) // test length 12
    {
        char cards [] = {'K', '3', 'A', '5', '*', '4', '6', '2', '7', '!', '9', '8'};
        int length = 12;
        int cards_num[12];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 89) // test length 12
    {
        char cards [] = {'Q', '3', 'A', '5', '*', '4', '6', '2', '7', '!', '9', '8'};
        int length = 12;
        int cards_num[12];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 90) // test length 13
    {
        char cards [] = {'*', 'A', '8', 'Q', '6', '4', '2', '9', '3', '5', '7', 'K', 'J'};
        int length = 13;
        int cards_num[13];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 91) // test length 13
    {
        char cards [] = {'*', 'A', '8', 'Q', '6', '4', '2', 'A', '3', '5', '7', 'K', 'J'};
        int length = 13;
        int cards_num[13];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 92) // test length 14
    {
        char cards [] = {'A', '!', '*', '8', 'Q', '6', '4', '2', '9', '3', '5', '7', 'K', 'J'};
        int length = 14;
        int cards_num[14];      

        testTask3(cards, length, cards_num);
    }

    // 14 + 13 + 25 = 52
    // with two jokers
    else if(testCase == 93) // test length 2 y
    {
        char cards [] = {'*', '*'};
        int length = 2;
        int cards_num[2];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 94) // test length 4 y
    {
        char cards [] = {'6', '5', '*', '*'};
        int length = 4;
        int cards_num[4];
    }
    else if(testCase == 95) // test length 5 y
    {
        char cards [] = {'8', '*', '7', '*', '6'};
        int length = 5;
        int cards_num[5];
    }
    else if(testCase == 96) // test length 6 n 
    {
        char cards [] = {'7', '*', '6', '9', '*', 'A'};
        int length = 6;
        int cards_num[6];
    }
    else if(testCase == 97) // test length 7 n
    {
        char cards [] = {'!', '*', 'J', '*', '3', 'A', '9'};
        int length = 7;
        int cards_num[7];
    }
    else if(testCase == 98) // test length 8 n
    {
        char cards [] = {'*', '2', '7', '9', '*',  '5', '!', '6'};
        int length = 8;
        int cards_num[8];
    }
    else if(testCase == 99) // test length 9 n
    {
        char cards [] = {'8', '*', '*', 'Q', '4', '3', 'A', '!', 'J'};
        int length = 9;
        int cards_num[9];
    }
    else if(testCase == 100) // test length 10 n
    {
        char cards [] = {'5', '*',  '3', '9', 'A', '*', '4', '!', 'Q', '2'};
        int length = 10;
        int cards_num[10];
    }
    else if(testCase == 101) // test length 15 n
    {
        char cards [] = {'*', 'J', '2', 'K', '8', 'Q', '9', '5', '6', '!', '4', '3', '7', 'A', '*'};
        int length = 15;
        int cards_num[15];
    }
    else if(testCase == 102) // test length 12 y
    {
        char cards [] = {'6', '4', '*', 'J', 'A', 'Q', '2', '9', '*', '7', '3', '8'};
        int length = 12;
        int cards_num[12];
    }
    else if(testCase == 103) // test length 13 y
    {
        char cards [] = {'A', '2', '*', '!', 'J', '*', '6', 'K', '8', '3', '9', '4', 'Q'};
        int length = 13;
        int cards_num[13];
    }
    else if(testCase == 104)  // test length 14 y
    {
        char cards [] = {'A', '2', '!', '*', '*', '6', '7', '3', '9', '4', 'Q', 'J', 'K', '8'};
        int length = 14;
        int cards_num[14];
    }

    // 14 + 13 + 25 + 12 = 64
    // length is longer than 14
    else if(testCase == 105) // test length 15
    {
        char cards [] = {'Q', '6', '9', '9', '2', '7', '!', 'K', '8', '*', '3', '*', '6', '4', 'A'};
        int length = 15;
        int cards_num[15];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 106) // test length 16
    {
        char cards [] = {'J', 'A', '7', '4', '9', 'J', 'J', '9', '2', 'K', 'J', '4', '6', '9', 'K', '6'};
        int length = 16;
        int cards_num[16];      

        testTask3(cards, length, cards_num);
    }

    // 14 + 13 + 25 + 12 + 2 = 66 
    // with repeated cards
    else if(testCase == 107) // test length 5
    {
        char cards [] = {'3', 'A', '2', '2', '4'};
        int length = 5;
        int cards_num[5];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 108) // test length 5
    {
        char cards [] = {'3', 'A', '4', '2', '4'};
        int length = 5;
        int cards_num[5];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 109) // test length 5
    {
        char cards [] = {'3', '*', '4', '2', '4'};
        int length = 5;
        int cards_num[5];      

        testTask3(cards, length, cards_num);
    }

    else if(testCase == 110) // test length 5
    {
        char cards [] = {'3', '*', '4', '*', '4'};
        int length = 5;
        int cards_num[5];      

        testTask3(cards, length, cards_num);
    }
    // Total 70 cases for task 3
    
    // Task 4
    // two straight A<B
    else if(testCase == 111) 
    {
        char handA[] = {'A', '2', '3', '4', '5'};
        char handB[] = {'2', '3', '4', '5', '6'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    else if(testCase == 112) 
    {
        char handA[] = {'2', '3', '4', '5', '6'};
        char handB[] = {'3', '4', '5', '6', '7'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    else if(testCase == 113) 
    {
        char handA[] = {'3', '4', '5', '6', '7'};
        char handB[] = {'4', '5', '6', '7', '8'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    else if(testCase == 114) 
    {
        char handA[] = {'4', '5', '6', '7', '8'};
        char handB[] = {'5', '6', '7', '8', '9'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    else if(testCase == 115) 
    {
        char handA[] = {'5', '6', '7', '8', '9'};
        char handB[] = {'6', '7', '8', '9', '!'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    else if(testCase == 116) 
    {
        char handA[] = {'6', '7', '8', '9', '!'};
        char handB[] = {'7', '8', '9', '!', 'J'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    else if(testCase == 117) 
    {
        char handA[] = {'7', '8', '9', '!', 'J'};
        char handB[] = {'8', '9', '!', 'J', 'Q'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    else if(testCase == 118) 
    {
        char handA[] = {'8', '9', '!', 'J', 'Q'};
        char handB[] = {'9', '!', 'J', '*', '*'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    else if(testCase == 119) 
    {
        char handA[] = {'9', '!', 'J', 'Q', 'K'};
        char handB[] = {'*', '!', 'J', 'Q', 'K'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    // 9
    // two straight A=B
    else if(testCase == 120)
    {
        char handA[] = {'4', '2', 'A', '5', '3'};
        char handB[] = {'*', '2', 'A', '5', '3'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 121)
    {
        char handA[] = {'6', '5', '4', '3', '2'};
        char handB[] = {'*', '5', '4', '3', '2'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 122)
    {
        char handA[] = {'3', '4', '6', '7', '5'};
        char handB[] = {'3', '4', '*', '7', '5'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 123)
    {
        char handA[] = {'5', '4', '6', '7', '8'};
        char handB[] = {'5', '4', '6', '*', '8'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 124)
    {
        char handA[] = {'7', '8', '9', '5', '6'};
        char handB[] = {'7', '8', '9', '*', '6'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 125)
    {
        char handA[] = {'9', '7', '!', '8', '6'};
        char handB[] = {'9', '*', '*', '8', '6'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 126)
    {
        char handA[] = {'7', '9', 'J', '!', '8'};
        char handB[] = {'*', '9', 'J', '*', '8'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 127)
    {
        char handA[] = {'J', 'Q', '8', '!', '9'};
        char handB[] = {'*', 'Q', '8', '!', '*'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 128)
    {
        char handA[] = {'Q', 'J', '!', 'K', '9'};
        char handB[] = {'*', 'J', '!', '*', '9'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 129)
    {
        char handA[] = {'K', '!', 'A', 'Q', 'J'};
        char handB[] = {'*', '!', 'A', '*', 'J'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    // 9 + 10 = 19
    // two straight A>B
    else if(testCase == 130)
    {
        char handA[] = {'*', '5', '3', '2', '4'};
        char handB[] = {'5', '*', '2', 'A', '3'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 131)
    {
        char handA[] = {'5', '7', '6', '3', '4'};
        char handB[] = {'4', '*', '5', '2', '3'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 132)
    {
        char handA[] = {'7', '5', '4', '8', '*'};
        char handB[] = {'6', '*', '3', '7', '5'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 133)
    {
        char handA[] = {'9', '6', '7', '5', '8'};
        char handB[] = {'8', '5', '6', '4', '7'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 134)
    {
        char handA[] = {'!', '7', '8', '6', '9'};
        char handB[] = {'9', '6', '7', '5', '8'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 135)
    {
        char handA[] = {'J', '8', '7', '9', '!'};
        char handB[] = {'!', '7', '6', '8', '9'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 136)
    {
        char handA[] = {'*', '*', '9', 'J', '8'};
        char handB[] = {'J', '9', '8', '!', '7'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 137)
    {
        char handA[] = {'*', 'J', '9', '*', 'Q'};
        char handB[] = {'Q', '!', '8', '9', 'J'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 138)
    {
        char handA[] = {'J', '*', '*', 'K', 'Q'};
        char handB[] = {'!', '9', 'K', 'Q', 'J'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    // 9 + 10 + 9 = 28
    // A is non straight and B is straight
    else if(testCase == 139)
    {
        char handA[] = {'2', '3', '6', '4', '5'};
        char handB[] = {'A', 'K', 'Q', 'A', '6'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 140)
    {
        char handA[] = {'5', '6', '3', '7', '4'};
        char handB[] = {'*', '2', 'A', '2', 'A'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 141)
    {
        char handA[] = {'5', '3', 'A', '4', '2'};
        char handB[] = {'!', '4', '!', '2', 'A'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 142)
    {
        char handA[] = {'Q', '8', '9', '!', 'J'};
        char handB[] = {'3', '9', '8', '*', '!'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 143)
    {
        char handA[] = {'8', '7', '5', '4', '6'};
        char handB[] = {'2', '!', 'K', 'Q', 'A'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 144)
    {
        char handA[] = {'3', '4', '5', '2', 'A'};
        char handB[] = {'!', '5', '4', 'A', '6'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 145)
    {
        char handA[] = {'4', '6', '8', '7', '5'};
        char handB[] = {'*', 'A', '6', 'J', '*'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 146)
    {
        char handA[] = {'Q', 'J', 'K', '*', '!'};
        char handB[] = {'*', '9', 'J', 'J', '!'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 147)
    {
        char handA[] = {'7', '8', '*', '4', '5'};
        char handB[] = {'A', '!', 'J', '6', '!'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 148)
    {
        char handA[] = {'9', '6', '7', '8', '5'};
        char handB[] = {'2', 'A', '9', '3', 'A'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    
    // 28 + 10 = 38
    // A is straight and B is non
    else if(testCase == 149)
    {
        char handA[] = {'K', '8', 'A', '6', 'Q'};
        char handB[] = {'A', '3', '5', '4', '2'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 150)
    {
        char handA[] = {'A', '2', '!', '3', '8'};
        char handB[] = {'3', '6', '4', '5', '7'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 151)
    {
        char handA[] = {'9', '9', '5', '9', '9'};
        char handB[] = {'3', '5', '2', '4', '6'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 152)
    {
        char handA[] = {'J', 'J', 'Q', '7', '5'};
        char handB[] = {'5', '4', 'A', '2', '3'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 153)
    {
        char handA[] = {'J', '8', '2', '7', '7'};
        char handB[] = {'7', '5', '3', '6', '4'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 154)
    {
        char handA[] = {'!', 'Q', 'Q', 'J', 'A'};
        char handB[] = {'J', 'K', 'Q', '9', '!'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 155)
    {
        char handA[] = {'7', '5', 'J', '2', '7'};
        char handB[] = {'Q', '!', '9', 'J', 'K'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 156)
    {
        char handA[] = {'J', '*', 'Q', 'J', '6'};
        char handB[] = {'5', '8', '7', '6', '4'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 157)
    {
        char handA[] = {'K', 'A', '!', '5', 'J'};
        char handB[] = {'7', '8', '6', '9', '5'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 158)
    {
        char handA[] = {'J', '4', '*', 'A', '5'};
        char handB[] = {'5', '8', '6', '9', '7'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    // 28 + 10 + 10 = 48
    // straight has same value with non-straight
    else if(testCase == 159)
    {
        char handA[] = {'J', 'Q', '*', 'A', 'K'};
        char handB[] = {'2', '2', '2', '4', '4'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    else if(testCase == 160)
    {
        char handA[] = {'J', 'Q', '*', 'A', 'K'};
        char handB[] = {'2', '3', '2', '3', '4'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    else if(testCase == 161)
    {
        char handA[] = {'J', 'Q', '*', 'A', 'K'};
        char handB[] = {'2', '3', '3', '3', '3'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    else if(testCase == 162)
    {
        char handA[] = {'J', 'Q', '!', '*', '9'};
        char handB[] = {'2', '2', '3', '3', '3'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 163)
    {
        char handA[] = {'2', '3', '2', '3', '4'};
        char handB[] = {'J', 'Q', '*', 'A', 'K'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    else if(testCase == 164)
    {
        char handA[] = {'2', '3', '3', '3', '3'};
        char handB[] = {'J', 'Q', '*', 'A', 'K'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    else if(testCase == 165)
    {
        char handA[] = {'2', '2', '3', '3', '3'};
        char handB[] = {'J', 'Q', '!', '*', '9'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }

    // 28 + 10 + 10 + 7 = 55
    // two non
    else if(testCase == 166)
    {
        char handA[] = {'Q', '2', '4', '*', 'A'};
        char handB[] = {'Q', '9', 'J', 'J', '9'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 167)
    {
        char handA[] = {'!', '2', 'Q', '4', 'J'};
        char handB[] = {'A', 'A', '4', 'A', '7'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 168)
    {
        char handA[] = {'5', 'A', '4', '2', '7'};
        char handB[] = {'*', 'Q', '7', '4', 'A'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 169)
    {
        char handA[] = {'7', '5', 'J', '6', '9'};
        char handB[] = {'A', '9', '!', '4', '2'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 170)
    {
        char handA[] = {'Q', '6', '*', '3', 'A'};
        char handB[] = {'8', '2', '6', '8', 'J'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 171)
    {
        char handA[] = {'A', '8', '7', '*', '5'};
        char handB[] = {'A', '!', '2', 'A', '6'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 172)
    {
        char handA[] = {'8', 'Q', '7', 'A', '3'};
        char handB[] = {'5', 'A', 'Q', 'J', 'A'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 173)
    {
        char handA[] = {'A', '8', '7', 'A', 'Q'};
        char handB[] = {'*', '5', '7', '*', '!'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 174)
    {
        char handA[] = {'8', '7', '4', '2', 'J'};
        char handB[] = {'5', '8', '!', 'K', '!'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 175)
    {
        char handA[] = {'9', 'K', '*', '2', 'A'};
        char handB[] = {'6', 'A', '2', '*', 'A'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 176)
    {
        char handA[] = {'7', '6', '8', '*', '3'};
        char handB[] = {'A', '5', 'A', '4', '8'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 177)
    {
        char handA[] = {'4', 'Q', '2', '7', 'J'};
        char handB[] = {'2', '4', '5', '4', '7'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 178)
    {
        char handA[] = {'2', 'J', '3', '6', 'Q'};
        char handB[] = {'*', 'K', '2', '7', '8'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 179)
    {
        char handA[] = {'!', '*', '5', 'K', 'A'};
        char handB[] = {'Q', '4', '4', '8', '8'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 180)
    {
        char handA[] = {'6', '8', '*', '!', 'A'};
        char handB[] = {'9', 'A', 'Q', '7', '5'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 181)
    {
        char handA[] = {'A', '!', 'J', '7', 'K'};
        char handB[] = {'6', '7', '6', 'A', '8'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 182)
    {
        char handA[] = {'Q', '7', '8', '3', '6'};
        char handB[] = {'J', 'A', 'A', '3', '3'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 183)
    {
        char handA[] = {'7', '4', 'A', '3', 'K'};
        char handB[] = {'*', '7', 'K', '9', 'A'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 184)
    {
        char handA[] = {'9', '6', '7', '4', '3'};
        char handB[] = {'J', '4', 'J', '2', '5'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 185)
    {
        char handA[] = {'K', '2', '7', 'A', 'Q'};
        char handB[] = {'A', 'A', 'A', '!', '!'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 186)
    {
        char handA[] = {'9', 'A', '2', 'K', 'Q'};
        char handB[] = {'J', 'K', 'Q', 'Q', '*'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 187)
    {
        char handA[] = {'5', '!', '7', '3', '9'};
        char handB[] = {'6', '8', 'A', '9', '5'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 188)
    {
        char handA[] = {'J', '6', '5', 'A', 'Q'};
        char handB[] = {'A', 'A', '!', 'K', '5'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 189)
    {
        char handA[] = {'3', '5', '6', '9', '8'};
        char handB[] = {'4', 'K', 'J', '7', 'Q'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    else if(testCase == 190)
    {
        char handA[] = {'9', 'J', 'Q', '!', '6'};
        char handB[] = {'4', '3', '!', '6', '!'};
        int valueA = 0;
        int valueB = 0;
        testTask4(handA, handB, valueA, valueB);
    }
    cout << "============================================" << endl << endl;

    return 0;
}

int main()
{
    streambuf *psbuf,*backup;
    ofstream file;
    file.open("test.txt");
    backup=cout.rdbuf();
    psbuf=file.rdbuf();
    cout.rdbuf(psbuf);//将cout输出重定向到文件
    cout<<"- file: test.out"<<endl;
        cout<<"  All the test cases: "<<endl;
    for(int i=1; i<=190; ++i){        
		test(i);
        if (i>=1 && i<=8){
            cout<<"score: 1"<<endl;
        }
        else if (i>=9 && i<=16){
            cout<<"score: 0.25"<<endl;
        }
        else if( i>=17 && i<=32){
            cout<<"score: 0.75"<<endl;
        }
        else if( i>=33 && i<=40){
            cout<<"score: 0.375"<<endl;
        }
        else if( i>=41 && i<=110){
            cout<<"score: 0.5"<<endl;
        }
        else if( i>=111 && i<=190){
            cout<<"score: 0.5"<<endl;
        }
		cout<<endl;
    } 
      
      
    

    cout.rdbuf(backup);//恢复cout输出重定向到终端
    file.close();
    
}