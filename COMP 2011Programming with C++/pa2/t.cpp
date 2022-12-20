#include <iostream>
using namespace std;

int arraySum(int array[], int arraySize)
{   
    if (arraySize == 1){return array[0];}
    int sum;
    sum = array[arraySize-1];
    
    sum+=arraySum(array,arraySize-1);
    return sum;  //change this line if you want
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
    return base* (pow(10,a));
    }
    else{
        return -(base* (pow(10,a)));
    }
}

int result_sum(int result[],int resultSize,int roller){
    
    if (roller == 0){
        return power(result[roller],resultSize-roller);
    }
    return power(result[roller],resultSize-roller) + result_sum(result,resultSize,roller-1);
}
bool compare(int result[], int resultSize,int sum,int index){
    
    int a = result_sum(result,resultSize,resultSize-1);
    
    int b = a+power(sum,index);

    cout << "a" << a << "b" << b;
    return (b>a);
}

int reverse(int store[],int input[],int size,int n){
    if(size == n){
        return 0;
    }
    store[size] = input[n-size-1];
    return reverse(store,input,size+1,n);
}





bool solve(int input[], int size, int target, int result[], int& resultSize) 
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
    
    bool j = solve(input, size-1,target-sum,result,resultSize);
    if (j){
            
            
            result[resultSize] = sum;
            resultSize++;
            return true;
        }
    bool l = solve(input, size-1,target-sub,result,resultSize);
    if (l){
            
            result[resultSize] = sub;  
            resultSize++;
            return true;
        }

    bool h = solve(input,size-1,target,result,resultSize);
    if(h){
        return true;
    }      
    return ( j || l || h);
}



int getIntValue(const char str[], int start, int end)
{   
    int diff = end-start;
    
    if (diff == 0){
        
        return power(int(str[start])-48,diff); 
    }
    
    return power(int(str[start])-48,diff) + getIntValue(str,start+1,end);  
}




void printString(const char str[])
{
    cout << "\"" << str << "\"" << endl;
}



int strlen(const char str[], int& len){
    if (str[len] == '\0'){
        return 0;
    }
    len++;
    return strlen(str,len);
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

int main(){
   
    int input[8] = {12,18,33,13,66,78,999,9};
    int target = 970;
    int result[12] = {};
    int resultSize = 0; 
    int store[8] = {};
    reverse(store,input,0,8);
    solve(store,8,target,result,resultSize);
    cout << "result" << endl;
    for (int i=0; i<resultSize;i++){
        cout << result[i] << " ";
    }
    
    /*
    int r[4] = {1,2,3,4};
    cout << result_sum(r,4,3);
    return 0;
    */
   
  
}



