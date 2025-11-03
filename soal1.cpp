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

/*
1. Program meminta input:
   - n (jumlah elemen array)
   - d (jumlah rotasi kiri)

2. Program membuat array otomatis dari 1 sampai n.
   Contoh jika n = 5 → [1, 2, 3, 4, 5]

3. Fungsi rotasiKiri akan menggeser elemen ke kiri sebanyak d kali.
   Rumusnya: hasil[i] = arr[(i + d) % n]
   Operator % (modulus) memastikan rotasi bersifat melingkar.

4. Setelah pergeseran selesai, hasil ditampilkan ke layar.
   Contoh:
   Input: n = 5, d = 4
   Array awal: [1, 2, 3, 4, 5]
   Hasil rotasi: [5, 1, 2, 3, 4]
-------------------------------------------
*/
