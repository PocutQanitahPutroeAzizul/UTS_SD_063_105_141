#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

/**
 * V: Jumlah total orang (Vertex).
 * adj: Daftar pertemanan (Adjacency List).
 * start: Orang pertama yang terinfeksi (Node Awal).
 * K: Hari yang ditanyakan.
 */
vector<int> virus_spread_bfs(int V, const vector<vector<int>>& adj, int start, int K) {
    // 'distance' akan mencatat: "Pada hari ke berapa orang ini terinfeksi?"
    // Nilai -1 berarti belum terinfeksi.
    vector<int> distance(V, -1);
    queue<int> q;
    vector<int> infected_on_K;

    // --- Kasus Khusus: Hari ke-0 ---
    // Jika K=0, hasilnya langsung orang awal itu sendiri.
    if (K == 0) {
        if (start >= 0 && start < V) {
            infected_on_K.push_back(start);
        }
        return infected_on_K;
    }

    // --- Inisialisasi BFS ---
    // Orang pertama terinfeksi pada Hari 0. Masukkan dia ke antrian.
    if (start < 0 || start >= V) {
        return {}; // Node awal tidak valid
    }
    
    distance[start] = 0;
    q.push(start);

    // --- Proses Penyebaran (BFS) ---
    while (!q.empty()) {
        int u = q.front(); // Ambil orang yang akan menularkan
        q.pop();

        // Optimasi: Jika orang ini (u) sudah terinfeksi pada Hari ke-K atau lebih,
        // semua teman barunya akan terinfeksi pada hari > K. Jadi, kita bisa lewati.
        if (distance[u] >= K) {
            continue;
        }

        // Kunjungi semua teman (tetangga) dari orang u
        for (int v : adj[u]) {
            // Jika teman (v) belum terinfeksi (-1)
            if (distance[v] == -1) {
                // Teman v terinfeksi 1 hari setelah u terinfeksi.
                distance[v] = distance[u] + 1;
                q.push(v); // Masukkan teman v ke antrian untuk menularkan besok
            }
        }
    }

    // --- Pengumpulan Hasil ---
    // Cek semua orang (dari 0 sampai V-1)
    for (int i = 0; i < V; ++i) {
        // Jika jarak (hari infeksi) orang i sama persis dengan K
        if (distance[i] == K) {
            infected_on_K.push_back(i);
        }
    }

    // Urutkan hasilnya dari kecil ke besar (menaik)
    sort(infected_on_K.begin(), infected_on_K.end());

    return infected_on_K;
}

int main() {
    // Pengaturan agar input/output lebih cepat
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    // 1. Baca jumlah orang (V) dan jumlah hubungan (E)
    if (!(cin >> V >> E)) return 0;

    // Output detail input
    cout << "Jumlah vertex dan edge: " << V << " " << E << endl;

    // Siapkan wadah untuk daftar pertemanan (Adjacency List)
    vector<vector<int>> adj(V);

    // 2. Baca semua hubungan pertemanan
    for (int i = 0; i < E; ++i) {
        int u, v;
        if (!(cin >> u >> v)) break;

        // Hubungan dua arah (tak berarah): u teman v, dan v teman u
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int S, K;
    // 3. Baca node awal terinfeksi (S) dan hari yang dicari (K)
    if (!(cin >> S >> K)) return 0;

    // Output detail input
    cout << "Node Awal dan Hari Terinfeksi: " << S << " " << K << endl;

    // Panggil fungsi utama BFS untuk simulasi
    vector<int> result = virus_spread_bfs(V, adj, S, K);

    // --- Output Hasil Akhir ---
    cout << "Node terinfeksi: ";
    if (result.empty()) {
        // Jika tidak ada yang terinfeksi
        cout << "(TIDAK ADA)" << endl;
    } else {
        // Cetak daftar node (orang) yang terinfeksi pada hari ke-K
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i] << (i == result.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}
