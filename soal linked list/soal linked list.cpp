#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	string nama;
	int jumlah;
	string tipe;
	Node* next;


};

class ManajemenProduk {
private:
	Node* head;

public:
	ManajemenProduk() {
		head = NULL;
	}

	void tambahProduk() {
		string nama;
		int jumlah;
		string tipe;

		cout << "========== TAMBAH PRODUK ==========" << endl;
		cout << "Nama Produk : ";
		getline(cin, nama);
		cout << "Jumlah Produk : ";
		cin >> jumlah;
		cin.ignore(); // Membersihkan buffer input
		cout << "Tipe Produk : ";
		getline(cin, tipe);

		Node* newProduk = new Node();
		newProduk->nama = nama;
		newProduk->jumlah = jumlah;
		newProduk->tipe = tipe;

		if (head == nullptr || head->nama >= newProduk->nama) {
			newProduk->next = head;
			head = newProduk;
		}
		else {
			Node* current = head;
			Node* previous = NULL;

			while (current != NULL && current->nama < newProduk->nama) {
				previous = current;
				current = current->next;
			}

			newProduk->next = current;
			previous->next = newProduk;
		}

		cout << "Produk berhasil ditambahkan!" << endl;
	}

	void tampilkanSemuaProduk() {
		cout << "========== SEMUA DATA PRODUK ==========" << endl;
		if (head == nullptr) {
			cout << "Belum ada data produk yang tersimpan." << endl;
		}
		else {
			Node* current = head;
			while (current != nullptr) {
				cout << "Nama Produk  : " << current->nama << endl;
				cout << "Jumlah Produk: " << current->jumlah << endl;
				cout << "Tipe Produk  : " << current->tipe << endl;
				cout << endl;
				current = current->next;
			}
		}
	}

	void cariProdukByNama() {
		cout << "========== CARI PRODUK BERDASARKAN NAMA ==========" << endl;
		if (head == nullptr) {
			cout << "Belum ada data produk yang tersimpan." << endl;
		}
		else {
			string targetNama;
			cout << "Nama Produk yang dicari: ";
			getline(cin, targetNama);
			Node* current = head;

			int posisi = 0;

			while (current != nullptr) {
				posisi++;
				if (current->nama == targetNama) {
					cout << "Nama produk  " << targetNama << " DITEMUKAN pada posisi ke-" << posisi << endl;
					cout << "Nama Produk  : " << current->nama << endl;
					cout << "Jumlah Produk: " << current->jumlah << endl;
					cout << "Tipe Produk  : " << current->tipe << endl;
					cout << endl;

					break;
				}
				current = current->next;

			}
			if (current == nullptr) {
				cout << "Nama produk " << targetNama << " TIDAK DITEMUKAN" << endl;
			}


		}
	}


	void bubbleSortByJumlahProduk() {
		if (head == nullptr || head->next == nullptr) {
			return; // Tidak perlu sorting jika hanya terdapat 0 atau 1 node
		}

		Node* current;
		Node* last = nullptr;

		current = head;

		while (current->next != last) {
			if (current->jumlah > current->next->jumlah) {
				// Tukar posisi node
				int tempJumlah = current->jumlah;
				current->jumlah = current->next->jumlah;
				current->next->jumlah = tempJumlah;
			}
			current = current->next;
		}
		last = current;

	}
};

int main() {
	ManajemenProduk manajemenProduk;

	int pilihan;
	do {
		cout << "========== APLIKASI MANAJEMEN DATA PRODUK ==========" << endl;
		cout << "1. Tambah Produk" << endl;
		cout << "2. Tampilkan Semua Produk" << endl;
		cout << "3. Cari Produk berdasarkan Nama" << endl;
		cout << "4. Urutkan Produk berdasarkan Jumlah" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore(); // Membersihkan buffer input

		switch (pilihan) {
		case 1:
			manajemenProduk.tambahProduk();
			break;
		case 2:
			manajemenProduk.tampilkanSemuaProduk();
			break;
		case 3:
			manajemenProduk.cariProdukByNama();
			break;
		case 4:
			manajemenProduk.bubbleSortByJumlahProduk();
			manajemenProduk.tampilkanSemuaProduk();
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
