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
        return -(abs(base* (pow(10,a))));
    }
}

int len(int a[],int size){
    if(size == 1){
        if  (a[size-1]==0){
            return 0;
        }
        else
        {
           return 1;
        }
    }
    if  (a[size-1]==0){
            return 0 + len(a,size-1);
        }
        else
        {
           return 1 + len(a,size-1);
        } 
}

int exact(int test[],int input[],int size,int n){
    if(size == n-1){
        if(test[size] == input[size]){
            return power(test[size],n-size-1);
        }
        return 0;
    }

    if(test[size] == input[size]){
        return power(test[size],n-size-1) + exact(test,input,size+1,n);
    }
    return 0 + exact(test,input,size+1,n);
}




int exact_minus(int test[],int input[],int size,int n){
    if(size == n-1){
        if(abs(test[size]) == abs(input[size])){
            return abs(power(test[size],n-size-1));
        }
        return 0;
    }

    if(abs(test[size]) == abs(input[size])){
        return abs(power(test[size],n-size-1)) + exact_minus(test,input,size+1,n);
    }
    return 0 + exact_minus(test,input,size+1,n);
}




bool compare(int test[],int result[], int input[],int size){
    
    if(exact(test,input,0,size) > exact(result,input,0,size)){
        return true;
    }
    
    
    
    
        
    return false;

    
}


bool if_empty(int result[],int size){
    if (size == 0){
        return true;
    }
    if (result[size-1] != 0){
        return false;
    }
    return if_empty(result,size-1);
}




bool real_solve(int input[], int size, int target, int result[], int resultSize,int real_result[]) 
{   
    
    if (size == 0){
        return false;
    }
   
    int sum[resultSize] = {};
    int sub[resultSize] = {};
    int ing[resultSize] = {};
    
    for (int i=0;i<resultSize;i++){
        sum[i] = result[i];
        sub[i] = result[i];
        ing[i] = result[i];
    }

    sub[size-1] = -1*input[size-1];
    ing[size-1] = 0;
    
    int Sum[resultSize] = {};
    int Sub[resultSize] = {};
    int Ing[resultSize] = {};
    int j = 0;
    for (int i=0;i<resultSize;i++){
        if(sum[i]!=0){
            Sum[j] = sum[i];
            j++;
        }
    }
    j = 0;
    for (int i=0;i<resultSize;i++){
        if(sub[i]!=0){
            Sub[j] = sub[i];
            j++;
        }
    }
    j = 0;
    for (int i=0;i<resultSize;i++){
        if(ing[i]!=0){
            Ing[j] = ing[i];
            j++;
        }
    }

    
    
   

  
    if(arraySum(sum,resultSize) == target){
        
        if(compare(sum,real_result,input,resultSize) || if_empty(real_result,resultSize)){
        for (int i=0;i<resultSize;i++){
        real_result[i] = Sum[i];  
        }
    }
        cout << endl; 
        return true;
    }
    
    if(arraySum(sub,resultSize) == target){
        
        if(compare(sub,real_result,input,resultSize) || if_empty(real_result,resultSize)){
        for (int i=0;i<resultSize;i++){
        real_result[i] = Sub[i];  
        }   
    }
        cout << endl; 
        return true;
    }
    
    if(arraySum(ing,resultSize) == target){
        
      

        if(compare(ing,real_result,input,resultSize) || if_empty(real_result,resultSize)){
            for (int i=0;i<resultSize;i++){
                real_result[i] = Ing[i];  
            }   
        }
        
    
        cout << endl; 
        return true;
    }
    real_solve(input,size-1,target,sum,resultSize,real_result);
    real_solve(input,size-1,target,sub,resultSize,real_result);
    real_solve(input,size-1,target,ing,resultSize,real_result);

    return false;
}




int main(){
    
    int input[6] = {88,13,1,3,5,9};
    int target = 9;
    int result[12] = {};
    int resultSize = 6; 
    int real_result[12] = {};
    real_solve(input,6,target,input,resultSize,real_result);
    cout << "result" << endl;
    for (int i=0;i<resultSize;i++){
        cout << real_result[i]<<" ";
    }
    
    
    return 0;
}