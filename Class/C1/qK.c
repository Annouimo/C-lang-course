#include <stdio.h>

int g(int a_list, int n){
    int min;
    int a,b;
    a=a_list[n];
    b=a_list[n+1];
    if (a<b)
    {
        min = a;
    }
    else{
        min = b;
    }
    
    for (size_t i = min; i > 0; i--)
    {
        if (a%i==0 && b%i==0)
        {
            return i;
        }
        
    }
}

int f(int input, int ni){ //n_i为奇数
    int output[10];
    for (size_t i = 1; ; i=i+1)
    {
        input[ni+1]=i
        if(g(input, ni-1)<g(input, ni+1) && g(input, ni+1)>g(input, ni)){
            for (size_t j = 1; j<i; j=j+1)
            {
                input[ni+2]=j
                if(g(input, ni)<g(input, ni+2) && g(input, ni+2)<g(input, ni+1)){
                    output[0]=i;
                    output[1]=j;
                    return output;
                }
            }
        }
    }

}

int main(){
    int n;
    scanf("%d", n);
    int a[n+10];
    a[1]=1;
    
}

