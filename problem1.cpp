#include <iostream>

// Fungsi buatan sendiri untuk mensimulasikan eliminasi astronot
void prosesEliminasi(int N, int K) {
    bool tereliminasi[1000] = {false};
    int sisa = N;
    int pos = 1;

    std::cout << "Urutan astronot yang tereliminasi:\n";

    while (sisa > 1) {
        int hitung = 0;

        while (hitung < K) {
            if (!tereliminasi[pos]) {
                hitung++;
            }
            if (hitung == K) {
                break;
            }
            pos = (pos % N) + 1;
        }

        tereliminasi[pos] = true;
        sisa--;
        std::cout << "Astronot " << pos << " tereliminasi.\n";

        // Aturan perubahan nilai K
        if (pos % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }

        // Batas minimum nilai K
        if (K < 2) {
            K = 2;
        }

        // Mencari posisi astronot aktif berikutnya
        if (sisa > 1) {
            do {
                pos = (pos % N) + 1;
            } while (tereliminasi[pos]);
        }
    }

    // Menentukan astronot terakhir yang bertahan
    for (int i = 1; i <= N; i++) {
        if (!tereliminasi[i]) {
            std::cout << "\nAstronot terakhir yang bertahan: " << i << "\n";
            break;
        }
    }
}

int main() {
    int N, K;
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> N;
    std::cout << "Masukkan nilai awal K: ";
    std::cin >> K;

    if (N <= 0 || K < 2) {
        std::cout << "Input tidak valid.\n";
        return 0;
    }

    prosesEliminasi(N, K);

    return 0;
}