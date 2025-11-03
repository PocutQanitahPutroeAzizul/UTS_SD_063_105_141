//Masukkan jawaban disini
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<string> antrianNormal;
    queue<string> antrianDarurat;

    int n;
    cout << "Masukkan jumlah perintah : ";
    cin >> n;

    
    while (n--) {
        string perintah;
        cin >> perintah;

        if (perintah == "DATANG") {
            string nama;
            cin >> nama;
            antrianNormal.push(nama);
        } else if (perintah == "DARURAT") {
            string nama;
            cin >> nama;
            antrianDarurat.push(nama);
        } else if (perintah == "LAYANI") {
            if (!antrianDarurat.empty()) {
                string pasienDilayani = antrianDarurat.front();
                antrianDarurat.pop();
                        
                cout << pasienDilayani << endl;

        } else if (!antrianNormal.empty()) {
            string pasienDilayani = antrianNormal.front();
                antrianNormal.pop();
                        
                cout << pasienDilayani << endl;

        } else {
                cout << "Tidak ada pasien saat ini" << endl;
        }
            }
    }

    return 0;
}

/*
Penjelasan Kode :

Library yang digunakan :
#include <iostream>
#include <queue>
#include <string>


Membuat 2 antrian
int main() {
    queue<string> antrianNormal; => untuk pasien normal
    queue<string> antrianDarurat; => untuk pasien yang darurat (dipriritaskan dahulu walaupin queue FIFO)



Menanyakan berapa banyak N perintah
int n;
    cout << "Masukkan jumlah perintah : ";
    cin >> n;


Melakukan loop sebanyak n kali (n-- artinya setiap n kurang 1)
while (n--) {
        string perintah;
        cin >> perintah;


Membaca nama pasien lalu memasukkannya ke antrian normal
if (perintah == "DATANG") {
            string nama;
            cin >> nama;
            antrianNormal.push(nama);
        }


Membaca nama pasien lalu memasukkannya ke antrian darurat
else if (perintah == "DARURAT") {
            string nama;
            cin >> nama;
            antrianDarurat.push(nama);
        }

jika ada psien darurat, layani dulu
else if (perintah == "LAYANI") {
            if (!antrianDarurat.empty()) {
                string pasienDilayani = antrianDarurat.front(); => ambil pasien pertama
                antrianDarurat.pop(); => setelah itu hapus dari antrian
                        
                cout << pasienDilayani << endl; => lalu cetak nama pasien yang dilayani tadi

        }


Jika tidak ada pasien darurat, maka layani pasien normal
else if (!antrianNormal.empty()) {
            string pasienDilayani = antrianNormal.front();
                antrianNormal.pop();
                        
                cout << pasienDilayani << endl;

        }
                
tampilkan ini jika tidak ada pasien yang di LAYANI
else {
                cout << "Tidak ada pasien saat ini" << endl;
        }
*/
