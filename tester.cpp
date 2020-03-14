#include <stdio.h>

int main(){
    int t;
    for(scanf("%d",&t);t;t--){
        char data[15];
        scanf("%s",data);
        bool check[10]={0};
        for(int i=0;data[i];i++){
            check[data[i]-'0']=1;
        }
        int cnt=0;
        for(int i=0;i<10;i++){
            if(check[i])
                cnt++;
       
        printf("%d\n",cnt);
    }
    return 0;
}
t