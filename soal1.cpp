#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk melakukan rotasi kiri sebanyak d kali
vector<int> rotasiKiri(vector<int> arr, int d) {
    int n = arr.size();
    d = d % n; // Jika d > n, ambil sisa bagi
    vector<int> hasil(n);

    for (int i = 0; i < n; i++) {
        int indexbaru = (i - d + n) % n; // Hitung indeks baru setelah rotasi
        hasil[indexbaru] = arr[i];
    }
    return hasil;
}

int main() {
    int n, d;
   cout << "Masukkan jumlah elemen array: ";
cin >> n;

vector<int> arr(n);
cout << "Masukkan elemen array: ";
for (int i = 0; i < n; i++){ 
    cin >> arr[i]; 
}

 cout << "Masukkan jumlah rotasi: ";
    cin >> d;

    for (int x : arr) cout << x << " ";
    cout << endl;

    // Rotasi kiri sebanyak d kali
    vector<int> hasil = rotasiKiri(arr, d);

    for (int x : hasil) cout << x << " ";
    cout << endl;

    return 0;
}
