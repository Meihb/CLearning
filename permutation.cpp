#include <stdio.h>
#include <windows.h>

const int maxn = 11;
int n, P[maxn], hashtable[maxn] = {false};

void generateP(int index) {
    if (index == n + 1) {
        for (int i = 1; i <=n; ++i) {
            printf("%d ", P[i]);
        }
        printf("\n");
        return;
    }

    for (int x = 1; x <= n; x++) {
//        printf("x %d flag is :%d ;", x,hashtable[x]);
        if (hashtable[x] == 0) {//当前数字未被放入
            P[index] = x;
            hashtable[x] = 1;
            generateP(index + 1);
            hashtable[x] = 0;
        }
    }
}
int main() {

    n=3;
    generateP(1);
}


