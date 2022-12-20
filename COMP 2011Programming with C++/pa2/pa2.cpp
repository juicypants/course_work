#include <iostream>
using namespace std;
//you are NOT allowed to include any additional library
const int ARRAY_MAX_SIZE = 12;

//given; do NOT modify; please refer to the webpage description
void printArray(int array[], int arraySize, int currentPosition)
{
    cout << array[currentPosition];
    if(currentPosition < arraySize-1)
    {
        if(array[currentPosition+1] > 0)
            cout << "+";
        printArray(array, arraySize, currentPosition+1);
    }
    else
        cout << endl;
}

//given; do NOT modify; please refer to the webpage description
void printArray(int array[], int arraySize)
{
     printArray(array, arraySize, 0);
}

//***** Only write your code below this line, remember that NO loop is allowed! ***** 
int arraySum(int array[], int arraySize)
{   
    if (arraySize == 1){return array[0];}
    int sum;
    sum = array[arraySize-1];
    sum+=arraySum(array,arraySize-1);
    return sum;  //change this line if you want
}

int abs(int a){
    if (a>0){
        return a;
    }
    else{
        return -a;
    }
}
int pow(int base, int a) {
    
    if (a != 0){
        return base * pow(base, a - 1);
    }
    else{
        return 1;
    }
}
int power(int base, int a){
    if (base > 0){
    return abs(base* (pow(10,a)));
    }
    else{
        return -abs((base* (pow(10,a))));
    }
}

int reverse(int store[],int input[],int size,int n){
    if(size == n){
        return 0;
    }
    store[size] = input[n-size-1];
    return reverse(store,input,size+1,n);
}

bool real_solve(int input[], int size, int target, int result[], int& resultSize) 
{   
    int sum = input[size-1];
    int sub = -1*input[size-1]; 
    


    if (size == 0){
        if (target == 0){
            resultSize = 0;
            return true;
    }   
        return false;
    }
    
    bool j = real_solve(input, size-1,target-sum,result,resultSize);
    if (j){
            
            
            result[resultSize] = sum;
            resultSize++;
            return true;
        }
    bool l = real_solve(input, size-1,target-sub,result,resultSize);
    if (l){
            
            result[resultSize] = sub;  
            resultSize++;
            return true;
        }

    bool h = real_solve(input,size-1,target,result,resultSize);
    if(h){
        return true;
    }
          
    return ( j || l || h);
}



bool solve(int input[], int size, int target, int result[], int& resultSize) 
{   

    int real_result[size] = {}; 
    

    reverse(real_result,input,0,size);
    real_solve(real_result,size,target,real_result,resultSize);
    reverse(result,real_result,0,resultSize);
    if(resultSize > 0){
        return true;
    }
    return false;








    
    return false;  //change this line if you want
}

int strlen(const char str[], int& len){
    if (str[len] == '\0'){
        return 0;
    }
    len++;
    return strlen(str,len);
}



void printString(const char str[])
{   
    
    cout<< str << endl;
}



int getIntValue(const char str[], int start, int end)
{   
    int diff = end-start;
    
    if (diff == 0){
        
        return power(int(str[start])-48,diff); 
    }
    
    return power(int(str[start])-48,diff) + getIntValue(str,start+1,end);  
}






int check_neg(const char str[], int start, int end, char neg[], int& negSize){
    if (start == end){
        return 0;
    }
    if(str[start] == '+'){
        neg[negSize] = '+';
        negSize++;
    }
    if(str[start] == '-'){
        neg[negSize] = '-';
        negSize++;
    }
    return check_neg(str,start+1,end,neg,negSize);
}

int modify(char neg[],int negSize, int number[], int& numebrSize){
    
    if (neg[negSize] == '-'){
        number[negSize+1] = -number[negSize+1];
    }
    if (negSize == 0){
        return 0;
    }
    return modify(neg,negSize-1,number,numebrSize);
}


int cal(const char str[], int start, int end,int p,int number[],int& numberSize, int& negSize){
    if (start == 0 && str[0] == '-'){
        numberSize++;
        negSize++;
        return cal(str,start+1,end,p,number,numberSize,negSize);
    }


    if (start == end){
        number[numberSize] = getIntValue(str,start-p,start-1);
        numberSize++;
        return 0;
    }
    if (str[start] == '+' || str[start] == '-'){
        number[numberSize] = getIntValue(str,start-p,start-1);
        numberSize++;
        negSize++;
        return cal(str,start+1,end,0,number,numberSize,negSize);
    }
    
    return cal(str,start+1,end,p+1,number,numberSize,negSize);
}


int evaluate(const char str[])
{   
    int len = 0;
    strlen(str,len);
    int number[len] = {};
    int numberSize = 0;
    int negSize = 0;
    cal(str,0,len,0,number,numberSize,negSize);
    char neg[negSize] = {};
    negSize=0;
    check_neg(str,0,len,neg,negSize);
    modify(neg,negSize,number,numberSize);
    return arraySum(number,numberSize);  //change this line if you want
}
//***** Only write your code above this line, remember that NO loop is allowed! *****


int main()
{
    int testCase;
    cout << "Hi, recursion master! Which test case do you want to run?" << endl;
    cin >> testCase;

    cout << endl << "Test case " << testCase << " output:" << endl;
    cout << "===================================" << endl;

    if(testCase == 0) //this test case is used to show you how printArray works; it is NOT used to grade your work and it is NOT on ZINC; no mark is allocated to this; try it on your own computer if you want
    {
        int array1[] = {1, 2, 3};
        printArray(array1, 3);
        int array2[] = {1, 2, 3, -4};
        printArray(array2, 4);
        int array3[] = {-8, 2, 1, -4};
        printArray(array3, 4);
        int array4[] = {99};
        printArray(array4, 1);
        int array5[] = {-1199};
        printArray(array5, 1);
    }
    
    else if(testCase == 1) //test arraySum
    {
        int array[] = {1, 2, 3};
        cout << arraySum(array, 3) << endl;
    }
    else if(testCase == 2) //test arraySum
    {
        int array[] = {-1, -234, 33, 5};
        cout << arraySum(array, 4) << endl;
    }

    else if(testCase == 3) //test solve
    {
        int input[] = {1, 2, 3, 4};
        int size = 4;
        int target = 2;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }
    else if(testCase == 4) //test solve
    {
        int input[] = {1, 2, 3, 4};
        int size = 4;
        int target = -2;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }
    else if(testCase == 5) //test solve
    {
        int input[] = {1, 2, 3, 4};
        int size = 4;
        int target = -9;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }
    else if(testCase == 6) //test solve
    {
        int input[] = {8, 13, 1, 3, 5, 9};
        int size = 6;
        int target = 9;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }
    else if(testCase == 7) //test solve
    {
        int input[] = {88, 13, 1, 3, 5, 9};
        int size = 6;
        int target = 9;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }
    else if(testCase == 8) //test solve
    {
        int input[] = {888, 13333, 20000, 1, 99, 3, 5, 9, 33, 44, 55, 100};
        int size = 12;
        int target = -165;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }

    else if(testCase == 9) //test printString
    {
        printString("1+1-2+1234");
    }
    else if(testCase == 10) //test printString
    {
        printString("Wow this assignment is so much fun!!!");
    }

    else if(testCase == 11) //test getIntValue
    {
        char str[] = "567";
        cout << getIntValue(str, 0, 2) << endl;
    }
    else if(testCase == 12) //test getIntValue
    {
        char str[] = "567";
        cout << getIntValue(str, 0, 1) << endl;
    }
    else if(testCase == 13) //test getIntValue
    {
        char str[] = "567";
        cout << getIntValue(str, 0, 0) << endl;
    }
    else if(testCase == 14) //test getIntValue
    {
        char str[] = "abc567abc";
        cout << getIntValue(str, 4, 5) << endl;
    }
    
    else if(testCase == 15) //test evaluate
    {
        cout << evaluate("172") << endl;
    }
    else if(testCase == 16) //test evaluate
    {
        cout << evaluate("3+2") << endl;
    }
    else if(testCase == 17) //test evaluate
    {
        cout << evaluate("1+2-4") << endl;
    }
    else if(testCase == 18) //test evaluate
    {
        cout << evaluate("11+21-43") << endl;
    }
    else if(testCase == 19) //test evaluate
    {
        cout << evaluate("11+21-43+888") << endl;
    }
    else if(testCase == 20) //test evaluate
    {
        cout << evaluate("-21") << endl;
    }
   
    cout << "===================================" << endl;

    return 0;
}

