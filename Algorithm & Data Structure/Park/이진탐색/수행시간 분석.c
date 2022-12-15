#include <stdio.h>
int key, cnt, n, r, a[6]={1, 2, 3, 4, 5, 6};

int sh(int s, int e){
    int mid;
    if(s<=e){
        cnt++;
        mid=(s+e)/2;
        if(key==a[mid]) return cnt;
        else if(key<a[mid]) return sh(s, mid-1);
        else if(key>a[mid]) return sh(mid+1, e);
    }
    return -1;
}

int main(){
    n=sizeof(a)/sizeof(int);
    scanf("%d", &key);
    r=sh(0, n-1);
    if(r==-1) printf("실패");
    else printf("%d", r);
    return 0;
}