#include <iostream>
#include <vector>
//AADARSH MOURYA
using namespace std;

int getMax(const vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    vector<int> count(10, 0);

    for (int i = 0; i < arr.size(); i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    arr = output;
}

void radixsort(vector<int>& arr) {
    int exp, m;
    m = getMax(arr);

    for (exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, exp);
}

int main() {
    int n;
    cout << "\nEnter the number of data element to be sorted: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    radixsort(arr);

    cout << "\nSorted Data ";
    for (int i = 0; i < n; i++)
        cout << "->" << arr[i];

    return 0;
}
