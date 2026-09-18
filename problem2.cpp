#include <iostream>

int hitungPanjang(const char str[]) {
    int len = 0;
    while (str[len] != '\0' && str[len] != '\n') {
        len++;
    }
    return len;
}


char ubahKapital(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}


void enkripsiCipher(const char asal[], char hasil[]) {
    int len = hitungPanjang(asal);
    if (len == 0) {
        hasil[0] = '\0';
        return;
    }

    
    hasil[0] = ubahKapital(asal[0]);

    
    for (int i = 1; i < len; i++) {
        char curr = ubahKapital(asal[i]);
        char prev = ubahKapital(asal[i - 1]);

        if (curr >= 'A' && curr <= 'Z' && prev >= 'A' && prev <= 'Z') {
            int val_curr = curr - 'A' + 1;
            int val_prev = prev - 'A' + 1;

            int val_new = (val_curr + val_prev - 1) % 26 + 1;
            hasil[i] = 'A' + (val_new - 1);
        } else {
            hasil[i] = curr;
        }
    }
    hasil[len] = '\0';
}

int main() {
    char pesanAsli[500];
    char pesanSandi[500];

    std::cout << "Masukkan pesan asli: ";
    std::cin >> pesanAsli;

    enkripsiCipher(pesanAsli, pesanSandi);

    std::cout << "Pesan terenkripsi: " << pesanSandi << "\n";

    return 0;
}