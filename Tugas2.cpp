/*
    Nama           : Muhammad Daffa Wiratama
    NIM            : 26/581146/PA/24366
    Program Studi  : Ilmu Komputer
    Kelas          : PRG4
*/

#include <iostream>
using namespace std;

const int JUMLAH_HARI = 7;
double hitung_rata_rata(int konsumsi_daya[], int JUMLAH_HARI) {
    double total = 0;
    for (int i = 0; i < JUMLAH_HARI; i++) {
        total += konsumsi_daya[i];
    }
    return total / JUMLAH_HARI;
}

int main() {
    int konsumsi_daya[JUMLAH_HARI];
    for (int i = 0; i < JUMLAH_HARI; i++) {
        cout << "Masukkan konsumsi daya untuk hari ke-" << (i + 1) << ": ";
        cin >> konsumsi_daya[i];
    }
    
    double total_konsumsi = 0;
    for (int i = 0; i < JUMLAH_HARI; i++) {
        total_konsumsi += konsumsi_daya[i];
    }

    double rata_rata = hitung_rata_rata(konsumsi_daya, JUMLAH_HARI);

    for (int i=0; i<JUMLAH_HARI; i++) {
        if (konsumsi_daya[i]<konsumsi_daya[i+1]) {
            konsumsi_tertinggi = konsumsi_daya[i+1];
            konsumsi_tertinggi_hari = i+2;
            konsumsi_terendah = konsumsi_daya[i];
            konsumsi_terendah_hari = i+1;
        }
    }
    
    if (total_konsumsi<0) {
        cout<<"Peringatan: Nilai bersifat negatif"<<endl;
    }

    cout<<"Total konsumsi daya selama seminggu adalah: "<<total_konsumsi<<endl;
    cout<<"Rata-rata konsumsi daya selama seminggu adalah: "<<rata_rata<<endl;

    for (int i=0; i<JUMLAH_HARI; i++) {
        (konsumsi_daya[i] > rata_rata) ? cout<<"Konsumsi daya pada hari ke-"<<(i+1)<<" di atas rata-rata."<<endl : cout<<"Konsumsi daya pada hari ke-"<<(i+1)<<" di bawah rata-rata."<<endl;
    }

    cout<<"Konsumsi daya tertinggi terjadi pada hari ke-"<<konsumsi_tertinggi_hari<<" dengan konsumsi daya sebesar "<<konsumsi_tertinggi<<endl;
    cout<<"Konsumsi daya terendah terjadi pada hari ke-"<<konsumsi_terendah_hari<<" dengan konsumsi daya sebesar "<<konsumsi_terendah<<endl;
    
    int konsumsi_diatas_rata_rata = 0;
    for (int i=0; i<JUMLAH_HARI; i++) {
        if (konsumsi_daya[i] > rata_rata) {
            konsumsi_diatas_rata_rata++;
        }
    }

    cout<<"Jumlah hari dengan konsumsi daya di atas rata-rata adalah: "<<konsumsi_diatas_rata_rata<<endl;

    
}