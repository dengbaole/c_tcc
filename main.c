#include <stdio.h>
#include <string.h>

typedef struct{
    uint8_t i;
    uint8_t j;
    uint8_t f;
}student;


int  get_num(int n){
    int num = 1;
    for(int i = 1;i<=n;i++){
       num  = num*i;
    }
    return num;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    uint8_t sz;
    sz = sizeof(arr)/sizeof(arr[0]);
    uint8_t left = 0;
    uint8_t right = sz -1;
    uint8_t mid  = right/2;
    uint8_t targe  = 11;
    while(right>=left){
        if(arr[mid] > targe){
            right = mid - 1;
            mid = (right + left)/2;
        }else if(arr[mid] < targe){
            left = mid + 1;
             mid = (right + left)/2;
        }else{
            printf("%d\n",arr[mid]);
            break;
        }
    }
    return 0;
}



// int main(){
//     printf("hello\n");
//     printf("char        %d字节 %2d位\n",sizeof(char),sizeof(char)*8);   
//     printf("short       %d字节 %2d位\n",sizeof(short),sizeof(short)*8);  
//     printf("int         %d字节 %2d位\n",sizeof(int),sizeof(int)*8);
//     printf("long        %d字节 %2d位\n",sizeof(long),sizeof(long)*8);
//     printf("long long   %d字节 %2d位\n",sizeof(long long),sizeof(long long)*8);
//     printf("float       %d字节 %2d位\n",sizeof(float),sizeof(float)*8);
//     printf("double      %d字节 %2d位\n",sizeof(double),sizeof(double)*8);
//     printf("long double %d字节 %2d位\n",sizeof(long double),sizeof(long double)*8);

//     return 0;
// }

