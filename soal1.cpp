#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk melakukan rotasi kiri sebanyak d kali
vector<int> rotasiKiri(vector<int> arr, int d) {
    int n = arr.size();
    d = d % n; // Jika d > n, ambil sisa bagi
    vector<int> hasil(n);

    for (int i = 0; i < n; i++) {
        hasil[i] = arr[(i + d) % n];
    }
    return hasil;
}

int main() {
    int n, d;
    cout << "Masukkan n dan banyak rotasi: ";
    cin >> n >> d;

    // Buat array otomatis dari 1 sampai n
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    
    for (int x : arr) cout << x << " ";
    cout << endl;

    // Rotasi kiri sebanyak d kali
    vector<int> hasil = rotasiKiri(arr, d);

    for (int x : hasil) cout << x << " ";
    cout << endl;

    return 0;
}
//Masukkan jawaban disini
