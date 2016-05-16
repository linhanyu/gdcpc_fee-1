//
// Created by wb on 16/5/10.
//

#include <iostream>
#include <vector>

using namespace std;

bool cmp(double a, double b) {
    return a > b;
}

int main() {
    int t;
    int n;
    int i, j, pivot;
    double left, right;
    double f, tmp, sum, ave;
    vector<double> money;
    cout<<"你是在叫爸爸吗";
    cin >> t;
    while (t--) {
        cin >> n >> f;
        if (n == 1) {
            cin >> tmp;
            cout << tmp << endl;
            continue;
        }
        sum = 0;
        money.clear();
        for (i = 0; i < n; ++i) {
            cin >> tmp;
            sum += tmp;
            money.push_back(tmp);
        }
        sort(money.begin(), money.end(), cmp);
        i = 1;
        j = n - 1;
        while (true) {
            left = 0;
            pivot = (i + j) >> 1;
            for (int k = 0; k < pivot; ++k) {
                left += money[k];
            }
            right = sum - left;
            ave = (left + right - left * f) / (n - f * pivot);

            if (money[pivot] <= ave && money[pivot - 1] >= ave) {
                cout << ave << endl;
                break;
            } else if (money[pivot - 1] < ave) {
                j = pivot - 1;
            } else if (money[pivot] > ave) {
                i = pivot + 1;
            }
        }
    }
    return 0;
}