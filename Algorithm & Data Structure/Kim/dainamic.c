#include <stdio.h>
int dt[10001][10001];
int main(){
    long long int n, k;
    scanf("%lld %lld", &n, &k);
    for(long long int i=1; i<=n; i++){
        for(long long int j=1; j<=k && j<=1; j++){
            if(i==j) dt[i][j]=1;
            else if(j==1) dt[i][j]=i;
            else dt[i][j]=(dt[i-1][j-1]+dt[i-1][j])%100000007;
        }
    }
    printf("%lld", dt[n][k]);
    return 0;
}