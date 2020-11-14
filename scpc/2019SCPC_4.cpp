#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;
int t, cs = 1;
struct str {
    int idx;
    double val;
};
str arr[110], brr[110], ans[110], temp_ans[110];

bool comp1(str a, str b) {
    if (a.val < b.val)
        return true;
    else
        return false;
}

bool comp2(str a, str b) {
    if (a.idx < b.idx)
        return true;
    else
        return false;
}

int main() {
    setbuf(stdout, NULL);
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &arr[i].val);
            arr[i].idx = i;
            brr[i] = arr[i];
        }
//        double prv_len = -1;
//        for (int i = 0; i < n; ++i) {
//            for(int j = 0;j<n;++j) {
//                swap(brr[i], brr[j]);
//                temp_ans[0] = {brr[0].idx, 0};
//                double mn = -brr[0].val, mx = brr[0].val;
//                for (int k = 1; k < n; ++k) {
//                    double r1 = fabs(brr[k - 1].val - brr[k].val);
//                    double r2 = brr[k - 1].val + brr[k].val;
//                    double r3 = sqrt(r2 * r2 - r1 * r1);
//                    temp_ans[k] = {brr[k].idx, temp_ans[k - 1].val + r3};
//                    mn = min(mn, temp_ans[k].val - brr[k].val);
//                    mx = max(mx, temp_ans[k].val + brr[k].val);
//                }
//                double temp_len = mx - mn;
//                if ((temp_len > prv_len) && prv_len != -1) {
//                    swap(brr[i], brr[j]);
//                } else {
//                    prv_len = temp_len;
//                    for (int k = 0; k < n; ++k)
//                        ans[k] = temp_ans[k];
//                }
//            }
//        }

        for (int k = 1; k < n; ++k) {
            double r1 = fabs(brr[k - 1].val - brr[k].val);
            double r2 = brr[k - 1].val + brr[k].val;
            double r3 = sqrt(r2 * r2 - r1 * r1);
            temp_ans[k] = {brr[k].idx, temp_ans[k - 1].val + r3};
        }
        printf("Case #%d\n", cs++);
        sort(ans, ans + n, comp2);
        for (int i = 0; i < n; ++i)
            printf("%.15lf\n", ans[i].val);
    }
    return 0;
}