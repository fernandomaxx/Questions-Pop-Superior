#include<iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, NC, value, count[231];
    cin >> NC;
    memset(count, 0, sizeof(count));
    while (NC--) {
        int k = 1;
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &value);
            count[value]++;
        }

        for (int i = 20; i <=230; i++) {
            while (count[i] > 0) {
                printf("%d", i);
                if (k != n)
                    printf(" ");
                count[i]--;
                k++;
            }
        }
        printf("\n");
    }
}