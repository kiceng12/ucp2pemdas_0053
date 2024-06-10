#include <iostream>
#include <vector>
using namespace std;

class perusahaan;
class karyawan {   
public:
    string nama;
    vector<perusahaan*> daftar_proyek;
    karyawan(string pNama) : nama(pNama) {
        cout << "karyawan \"" << nama << "\" ada\n";
    }
    ~karyawan() {
        cout << "karyawan \"" << nama << "\" tidak ada\n";
    }

    void tambahPerusahaan(perusahaan*);
    void cetakPerusahaan();
};

class perusahaan {
public:
    string nama;
    vector<karyawan*> daftar_karyawan;

    perusahaan(string pNama) : nama(pNama) {
        cout << "perusahaan \"" << nama << "\" ada\n";
    }
    ~perusahaan() {
        cout << "perusahaan \"" << nama << "\" tidak ada\n";
    }

    void tambahKaryawan(karyawan*);
    void cetakKaryawan();
};

void karyawan::tambahPerusahaan(perusahaan* pPerusahaan) {
    daftar_proyek.push_back(pPerusahaan);
}

void karyawan::cetakPerusahaan() {
    cout << "Daftar proyek karyawan perusahaan \"" << this->nama << "\":\n";
    for (auto& a : daftar_proyek) { 
        cout << a->nama << "\n";
    }
    cout << endl;
}

void perusahaan::tambahKaryawan(karyawan* pKaryawan) {
    daftar_karyawan.push_back(pKaryawan);
}

void perusahaan::cetakKaryawan() {
    cout << "Daftar karyawan dari perusahaan\"" << this->nama << "\":\n";
    for (auto& a : daftar_karyawan) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

int main() {
    perusahaan* varPerusahaan1 = new perusahaan("Sistem Informasi");
    perusahaan* varPerusahaan2 = new perusahaan("Sistem Keamanan");
    karyawan* varKaryawan1 = new karyawan("Budi");
    karyawan* varKaryawan2 = new karyawan("Andi");

    varPerusahaan1->tambahKaryawan(varKaryawan1);
    varPerusahaan1->tambahKaryawan(varKaryawan2);
    varPerusahaan2->tambahKaryawan(varKaryawan1);

    varKaryawan1->tambahPerusahaan(varPerusahaan1);
    varKaryawan2->tambahPerusahaan(varPerusahaan1);
    varKaryawan1->tambahPerusahaan(varPerusahaan2);

    varPerusahaan1->cetakKaryawan();
    varPerusahaan2->cetakKaryawan();
    varKaryawan1->cetakPerusahaan();
    varKaryawan2->cetakPerusahaan();

    delete varKaryawan1;
    delete varKaryawan2;
    delete varPerusahaan1;
    delete varPerusahaan2;

    return 0;
}
