//No 2 Bubble Sort, Linear Search, Array
//No 3 Stack Last In First Out(Lifo), Queue First In First Out (Fifo)
//No 4 Penggunaan stack digunakan ketika dimana data yang terakhir dimasukan itu adalah data yang paling awal di delete
//No 5A 5 Kedalaman
//No 5B In = 1 5 8 12 15 10 20 22 25 28 30 36 38 40 45 48 50
//Preorder = 25 20 10 5 1 8 12 15 22 36 30 28 40 38 48 45 50
//Post = 1 8 5 15 12 10 22 20 28 38 45 50 48 30 40 36 25




#include <iostream>
#include <string>

using namespace std;

const int MAX_MAHASISWA = 100;

int NIM[MAX_MAHASISWA];
string nama[MAX_MAHASISWA];
string jurusan[MAX_MAHASISWA];
int tahunMasuk[MAX_MAHASISWA];

int jumlahMahasiswa = 0;

void tambahMahasiswa();
void tampilkanSemuaMahasiswa();
void algorithmacariMahasiswaByNIM();
void algorithmaSortByTahunMasuk();

int main() {
	int pilihan;
	do {
		cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
		cout << "1. Tambah Mahasiswa" << endl;
		cout << "2. Tampilkan Semua Mahasiswa" << endl;
		cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
		cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore(); // Membersihkan buffer input

		switch (pilihan) {
		case 1:
			tambahMahasiswa();
			break;
		case 2:
			tampilkanSemuaMahasiswa();
			break;
		case 3:
			algorithmacariMahasiswaByNIM();
			break;
		case 4:
			algorithmaSortByTahunMasuk();
			tampilkanSemuaMahasiswa();
			break;
		case 5:
			cout << "Terima kasih! Program selesai." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}
		cout << endl;
	} while (pilihan != 5);

	return 0;
}

void tambahMahasiswa() {
	if (jumlahMahasiswa < MAX_MAHASISWA) {
		cout << "========== TAMBAH MAHASISWA ==========" << endl;
		cout << "NIM        : ";
		cin >> NIM[jumlahMahasiswa];
		cin.ignore(); // Membersihkan buffer input
		cout << "Nama       : ";
		getline(cin, nama[jumlahMahasiswa]);
		cout << "Jurusan    : ";
		getline(cin, jurusan[jumlahMahasiswa]);
		cout << "Tahun Masuk: ";
		cin >> tahunMasuk[jumlahMahasiswa];
		cin.ignore(); // Membersihkan buffer input

		jumlahMahasiswa++;
		cout << "Mahasiswa berhasil ditambahkan!" << endl;
	}
	else {
		cout << "Kapasitas maksimum mahasiswa telah tercapai." << endl;
	}
}

void tampilkanSemuaMahasiswa() {
	cout << "========== SEMUA DATA MAHASISWA ==========" << endl;
	if (jumlahMahasiswa > 0) {
		for (int i = 0; i < jumlahMahasiswa; i++) {
			cout << "NIM        : " << NIM[i] << endl;
			cout << "Nama       : " << nama[i] << endl;
			cout << "Jurusan    : " << jurusan[i] << endl;
			cout << "Tahun Masuk: " << tahunMasuk[i] << endl;
			cout << endl;
		}
	}
	else {
		cout << "Belum ada data mahasiswa yang tersimpan." << endl;
	}
}

void algorithmacariMahasiswaByNIM() {
	int targetNIM;
	int i;
	int ctr = 0;
	cout << "========== CARI MAHASISWA BERDASARKAN NIM ==========" << endl;
	cout << "NIM yang dicari: ";
	cin >> targetNIM;
	cin.ignore(); // Membersihkan buffer input


	for (i = 0; i < jumlahMahasiswa; i++) {
		ctr++;
		if (NIM[i] == targetNIM) {
			cout << "Mahasiswa dengan NIM: " << targetNIM << " found at position " << (i + 1) << endl;
			cout << "NIM        : " << NIM[i] << endl;
			cout << "Nama       : " << nama[i] << endl;
			cout << "Jurusan    : " << jurusan[i] << endl;
			cout << "Tahun Masuk: " << tahunMasuk[i] << endl;
			cout << endl;

			break;
		}
	}

	if (i == MAX_MAHASISWA) {
		cout << "Mahasiswa dengan NIM " << targetNIM << " tidak ditemukan." << endl;
	}
}

void algorithmaSortByTahunMasuk() {
	for (int i = 0; i < jumlahMahasiswa - 1; i++) {
		for (int j = 0; j < jumlahMahasiswa - i - 1; j++) {
			if (tahunMasuk[j] > tahunMasuk[j + 1]) {
				// Tukar data
				int temp = tahunMasuk[j];
				tahunMasuk[j] = tahunMasuk[j + 1];
				tahunMasuk[j + 1] = temp;
			}
		}
	}
}
