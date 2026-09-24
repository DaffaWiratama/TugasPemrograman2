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

/*
PENJELASAN
1. Alur program
- Program dimulai dengan mendeklarasikan array konsumsi_daya untuk menyimpan konsumsi daya harian selama seminggu.
- Program meminta pengguna untuk memasukkan konsumsi daya harian selama tujuh hari.
- Program memeriksa apakah ada nilai negatif yang dimasukkan. Jika ada, program akan menampilkan peringatan.
- Program menghitung total konsumsi daya selama seminggu.
- Program menghitung rata-rata konsumsi daya dengan memanggil fungsi hitungRataRata.
- Program mencari nilai konsumsi daya tertinggi dan terendah beserta hari ke berapa nilai tersebut terjadi.
- Program menampilkan hasil total konsumsi daya, rata-rata konsumsi daya, dan status konsumsi daya setiap hari apakah di atas atau di bawah rata-rata.
- Program menampilkan hari dengan konsumsi daya tertinggi dan terendah beserta nilainya.

2. Variabel
- konsumsi_daya[JUMLAH_HARI] (double): menyimpan tujuh nilai konsumsi daya harian.
- adaNegatif (int): penanda apakah ada nilai input yang negatif (0 = tidak ada, 1 = ada).
- total_konsumsi (double): menyimpan hasil penjumlahan seluruh nilai konsumsi daya.
- rata_rata (double): menyimpan hasil rata-rata konsumsi daya dari fungsi hitungRataRata.
- konsumsi_tertinggi, konsumsi_terendah (double): menyimpan nilai konsumsi daya tertinggi dan terendah.
- konsumsi_tertinggi_hari, konsumsi_terendah_hari (int): menyimpan hari ke berapa nilai tertinggi dan terendah terjadi.
- konsumsi_diatas_rata_rata (int): menghitung banyaknya hari yang konsumsinya di atas rata-rata.

3. Fungsi
hitungRataRata(double total, int n) menerima total konsumsi daya dan jumlah hari,
lalu mengembalikan nilai double berupa hasil bagi total dengan jumlah hari.
Fungsi ini dipisah dari main agar perhitungan rata-rata dilakukan oleh fungsi
tersendiri sesuai ketentuan tugas, bukan dihitung langsung di dalam main.

4. Contoh eksekusi
Input: 120, 150, 100, 200, 180, 90, 160
Output:
Total konsumsi daya selama seminggu adalah: 1000
Rata-rata konsumsi daya selama seminggu adalah: 142.857
Konsumsi daya pada hari ke-1 di bawah rata-rata.
Konsumsi daya pada hari ke-2 di atas rata-rata.
Konsumsi daya pada hari ke-3 di bawah rata-rata.
Konsumsi daya pada hari ke-4 di atas rata-rata.
Konsumsi daya pada hari ke-5 di atas rata-rata.
Konsumsi daya pada hari ke-6 di bawah rata-rata.
Konsumsi daya pada hari ke-7 di atas rata-rata.
Konsumsi daya tertinggi terjadi pada hari ke-4 dengan konsumsi daya sebesar 200
Konsumsi daya terendah terjadi pada hari ke-6 dengan konsumsi daya sebesar 90
Jumlah hari dengan konsumsi daya di atas rata-rata adalah: 4

5. Catatan
Kesulitan utama ada pada pencarian nilai tertinggi dan terendah tanpa membandingkan
elemen di luar batas array. Masalah ini diatasi dengan menjadikan hari pertama
sebagai nilai acuan awal, lalu membandingkannya dengan hari kedua sampai ketujuh.
*/