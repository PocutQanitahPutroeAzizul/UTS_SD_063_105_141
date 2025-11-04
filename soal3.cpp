#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// inti Mencari semua node yang berjarak tepat K dari S menggunakan BFS.
vector<int> bfs_infected(int V, const vector<vector<int>>& adj, int S, int K) {
    // dist berfungsi menyimpan jarak/hari dari S. -1 = Belum dikunjungi.
    vector<int> dist(V, -1);   // Digunakan untuk melacak jarak terpendek dari node awal S ke setiap node lain
    queue<int> q; // Menjamin node-node diproses secara berurutan berdasarkan jarak/hari
    
    // Inisialisasi Node S pada Hari 0.
    if (S < 0 || S >= V || K < 0) return {}; // Cek S dan K (K harus >= 0)
    dist[S] = 0;
    q.push(S);
    
    // BFS berfungsi menjelajahi lapis demi lapis dan hari.
    while (!q.empty()) {
        int u = q.front(); q.pop();
        
        // Optimasi untuk tidak menyebar jika sudah mencapai target hari (K).
        if (dist[u] >= K) continue;
        
        // Iterasi tetangga
        for (int v : adj[u]) {
            // Cek v valid & belum dikunjungi (-1).
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    // Kumpulkan hasil Node yang jaraknya TEPAT K.
    vector<int> result;
    for (int i = 0; i < V; ++i) {
        if (dist[i] == K) result.push_back(i);
    }
            
    // Urutkan hasil
    sort(result.begin(), result.end());
    return result;
}

int main() {
    int V, E;
    cout << "Masukkan jumlah vertex dan edge : " << flush;
    if (!(cin >> V >> E)) return 0;
    
    vector<vector<int>> adj(V);
    cout << "Masukkan " << E << " edge (format: u v), satu per baris:\n";
    
    // Membangun jaringan tidak berarah
    for (int i = 0; i < E; ++i) {
        int u, v;
        if (!(cin >> u >> v)) return 0;
        // Cek validitas u dan v
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
    int S, K;
    cout << "Masukkan node awal dan hari (S K): " << flush;
    if (!(cin >> S >> K)) return 0;
    
    // Cek validitas input
    if (S < 0 || S >= V || K < 0) {
        cout << "Input S atau K tidak valid.\n";
        return 0;
    }
    
    cout << "Awal terinfeksi: node " << S << " pada hari 0\n";
    
    // memanggil atau menjalankan fungsi BFS yang berisi seluruh logika algoritma BFS untuk simulasi penyebaran infeksi
    vector<int> result = bfs_infected(V, adj, S, K);
    
    // Output hasil.
    cout << "Node terinfeksi pada hari " << K << ": ";
    if (result.empty()) {
        cout << "(TIDAK ADA)\n";
    } else {
        // Cetak dengan pemisah spasi.
        for (size_t i = 0; i < result.size(); ++i) {
            cout << (i ? " " : "") << result[i];
        }
        cout << '\n';
    }
    
    return 0;
}
