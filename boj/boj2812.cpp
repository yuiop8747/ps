#include <iostream>

using namespace std;
int main() {
    char got[500005], stack[500000], end = 1;
    int n, k;
    cin >> n >> k;
    cin >> got;
    stack[0] = got[0];
    for (int i = 1; i < n; i++) {
        if (k) {
            while (got[i] > stack[end - 1] && end && k) {
                k--;
                end--;
            }
        }
        stack[end++] = got[i];
    }
    while (k--)
        end--;
    for (int i = 0; i < end; i++)
        cout << stack[i];
    return 0;
}
