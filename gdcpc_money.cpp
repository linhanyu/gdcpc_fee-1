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

    cin >> t;
    while (t--) {
        cin >> n >> f;
        sum = 0;
        money.clear();
        for (i = 0; i < n; ++i) {
            cin >> tmp;
            sum += tmp;
            money.push_back(tmp);
        }
        sort(money.begin(), money.end(), cmp);
        i = 0;
        j = n;
        while (true) {
            left = 0;
            pivot = (i + j) / 2;
            for (int k = 0; k < pivot; ++k) {
                left += money[k];
            }
            right = sum - left;
            ave = (left + right - left * f) / (n - f * pivot);

            if (money[pivot] <= ave && money[pivot - 1] >= ave) {
                cout << ave << endl;
                break;
            } else if (money[pivot - 1] < ave) {
                j = pivot;
            } else if (money[pivot] > ave) {
                i = pivot;
            }
        }
    }
    return 0;
}