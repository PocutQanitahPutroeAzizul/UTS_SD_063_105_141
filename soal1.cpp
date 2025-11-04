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

/*penjelasan algoritma kode saya 
1. user diminta utk menginputkan banyak elemen array dan akan disimpan dalam variabel n
2. program akan membuat vector array bernama arr sebanyak n dan user akan dimintakan untuk menginputkan nilai dari array yang ada di vector
3. user diminta untuk menginput jumlah rotasi dan akan di simpan dalam variabel d
4. prgram akan mengoutputkan setiap elemen dalam vector array yang telah di inputkann user sebelumnya
5. program akan membuat vecktor baru bernama hasil yang nilainya akan diisi dari hasil fungsi rotasiKiri dengan parameter arr dan d(jumlah rotasi)
6. di rotasi fungsi kita akan emmbatasi index dari array kita dengan menggunakan d = d % n
7. di dalam fungsi rotasiKiri akan dibuat vector baru bernama hasil sebanyak n
8. pada perulangan di dalma fungsi rotasiKiri dilakukan penyesuaian index setelah dilakukan rotasi dengna menyimpan nilai index dalam variabel index baru yang sama dengan i - d + n dan akan mengisi vector hasil dengan index, indexbaru dengan nilai array berindex i
9.  fungsi akan returning nilai dari elemen vector array yang memiliki index tebaruu
