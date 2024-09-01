#include <stdio.h>
int sum(int k);
int addUp(int h){
    int sum = 0;
    for(int i = 1; i <= h; i++){
        sum += i;
    }
    return sum;
}
int main(){
    int res = addUp(10);
    printf("%d\n", res);
    return 0;
}
int sum(int k){
    if(k > 0){
        return k + sum(k-1);
    }else{
        return 0;
    }
}