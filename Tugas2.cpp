/*
    Nama           : Muhammad Daffa Wiratama
    NIM            : 26/581146/PA/24366
    Program Studi  : Ilmu Komputer
    Kelas          : PRG4
*/

#include <iostream>
using namespace std;

const int JUMLAH_HARI = 7;
double hitungRataRata(double total, int n);

int main() {
    double konsumsi_daya[JUMLAH_HARI];
    int adaNegatif = 0;
    double konsumsi_tertinggi = 0;
    double konsumsi_terendah = 0;
    int konsumsi_tertinggi_hari = 0;
    int konsumsi_terendah_hari = 0;

    cout<<"Program untuk menghitung konsumsi daya listrik selama seminggu."<<endl;
    for (int i = 0; i < JUMLAH_HARI; i++) {
        cout << "Masukkan konsumsi daya untuk hari ke-" << (i + 1) << ": ";
        cin >> konsumsi_daya[i];
        if (konsumsi_daya[i] < 0) {
            adaNegatif = 1;
        }
    }
    
    cout<<"----------------------------------------"<<endl;

    double total_konsumsi = 0;
    for (int i = 0; i < JUMLAH_HARI; i++) {
        total_konsumsi += konsumsi_daya[i];
    }

    double rata_rata = hitungRataRata(total_konsumsi, JUMLAH_HARI);

    konsumsi_tertinggi=konsumsi_daya[0];
    konsumsi_terendah=konsumsi_daya[0];
    konsumsi_tertinggi_hari= 1;
    konsumsi_terendah_hari= 1;

    for (int i = 1; i < JUMLAH_HARI; i++) {
        if (konsumsi_daya[i] > konsumsi_tertinggi) {
            konsumsi_tertinggi = konsumsi_daya[i];
            konsumsi_tertinggi_hari = i + 1;
        }
        if (konsumsi_daya[i] < konsumsi_terendah) {
            konsumsi_terendah = konsumsi_daya[i];
            konsumsi_terendah_hari = i + 1;
        }
    }
    
    if (adaNegatif == 1) {
        cout<<"Peringatan: Nilai bersifat negatif"<<endl;
    }

    cout<<"Total konsumsi daya selama seminggu adalah: "<<total_konsumsi<<endl;
    cout<<"Rata-rata konsumsi daya selama seminggu adalah: "<<rata_rata<<endl;

    cout<<"----------------------------------------"<<endl;
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

    return 0;
}

double hitungRataRata(double total, int n) {
    return total / n;
}