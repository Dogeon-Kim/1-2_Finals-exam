#include <stdio.h>
int i, key, cnt, n, r, a[5]={10, 9, 8, 7, 6};

int sh(){
    for(i=0; i<n; i++){
        cnt++;
        if(a[i]==key) return cnt;
    }
    return -1;
}

int main(){
    n=sizeof(a)/sizeof(int);
    scanf("%d", &key);
    r=sh();
    if(r==-1) printf("실패");
    else printf("%d회", r);
    return 0;
}