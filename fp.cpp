#include<iostream>
#include<stdio.h>
#include<conio.h>
#define MAX 10
#include <windows.h>

using namespace std;

string Jenis[MAX];
string Nama[MAX];
string Kendaraan[MAX];
string Merek[MAX];
int antrianuser[MAX];

int B=1, P=1, A=0;
int head=-1;
int tail=-1;

struct member{ // struct member 
	string Nama;
	string Alamat;
	int Centang;
}temp;

member mbr[100];

bool Empty(){  
	if(tail == -1){
		return true;
	}else{
		return false;
	}
}

bool Full(){
	if(tail== MAX-1){
		return true;
	}else{
		return false;
	}
}

void gotoxy(int x, int y) //fungsi untuk menggunakan gotoxy
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void AntrianMasuk(string jenis, string nama, string kendaraan, string merek, int nomer){ // fungsi untuk masuk ke antrian 
	if(Empty()){
		head=tail=0;
	}else{
		tail++;}
		Jenis[tail]=jenis;
		Nama[tail]=nama;
		Kendaraan[tail]=kendaraan;
		Merek[tail]=merek;
		antrianuser[tail]=nomer;
}

void AntrianKeluar(){ // fungsi untuk menghapus antrian
	if(Empty()){
		cout<<"Antrian sudah kosong !";
		getch();
	}else{
		for(int a=head; a<tail; a++){
			Jenis[a]=Jenis[a+1];
			Nama[a]=Nama[a+1];
			Kendaraan[a]=Kendaraan[a+1];
			Merek[a]=Merek[a+1];
			antrianuser[a]=antrianuser[a+1];
		}tail--;
		if(tail == -1){
			head = -1;
		}
	}
}

void View(){ // fungsi untuk melihat daftar antrian
	if(Empty()){
		cout<<"Antrian kosong !"; 
	}else{
		system("cls");
		gotoxy(25, 2);
		cout<<"======================================================"<<endl;
		gotoxy(25, 3);
		cout<<"|		Jasa Service Motor Dan Cuci	      |"<<endl;
		gotoxy(25, 4);
		cout<<"======================================================"<<endl;
		for(int a=head; a<=tail; a++){
			cout<<"============================="<<endl;
			cout<<"Nama		: "<<Nama[a]<<endl;
			cout<<"Kendaraan	: "<<Kendaraan[a]<<endl;
			cout<<"Merk Kendaraan	: "<<Merek[a]<<endl;
			cout<<"Kategori	: "<<Jenis[a]<<endl;
			cout<<"Nomer Antrian	: "<<antrianuser[a]<<endl;
		}
	}
}

void Masuk();
void Member();
void Daftar();
void Urut();
void Cari();
void Ceklist();
void Tampil();

int main(){
	
	int *pilihan; // alokasi memori dinamis
	pilihan = new int;
	
	int urut;
	
	menu:
		system("cls");
		
		gotoxy(25, 2);
		cout<<"======================================================"<<endl;
		gotoxy(25, 3);
		cout<<"|		Jasa Cuci dan Service Motor	      |"<<endl;
		gotoxy(25, 4);
		cout<<"======================================================"<<endl;
		gotoxy(25, 5);
		cout<<"|1. Tambahkan Antrian				      |"<<endl;
		gotoxy(25, 6);
		cout<<"|2. Panggil Antrian				      |"<<endl;
		gotoxy(25, 7);
		cout<<"|3. Daftar Antrian				      |"<<endl;
		gotoxy(25, 8);
		cout<<"|4. Member Service atau Cuci		 	      |"<<endl;
		gotoxy(25, 9);
		cout<<"|5. Keluar					      |"<<endl;
		gotoxy(25, 10);
		cout<<"======================================================"<<endl;
		gotoxy(25, 11);
		cout<<"Pilih : ";
		cin>>*pilihan;
		
		cout<<endl;
		
		if(*pilihan == 1){
			Masuk();
			
		}else if(*pilihan == 2){
			if(Empty()){
				system("cls");
				cout<<"Masih kosong !"<<endl;
				cout<<"Tekan sembarang untuk kembali...";
				getch();
				goto menu;
				
			}else{
				cout<<"Nomer Antrian ke "<<B<<" Silahkan Menuju Tempat Service atau Pencucian"<<endl;
				cout<<"Tekan sembarang untuk kembali...";
				AntrianKeluar();
				B++;
				getch();
				goto menu;
			}
			
		}else if(*pilihan == 3){
			system("cls");
			View();
			cout<<"Tekan sembarang untuk kembali...";
			getch();
			goto menu;
			
		}else if (*pilihan == 4){
			system("cls");
			Member();
			cout<<"Tekan sembarang untuk kembali...";
			getch();
			goto menu;
			
		}else if (*pilihan == 5){
			cout<<"Terima kasih sudah datang di tempat kami :)"<<endl;
			cout<<"Tekan sembarang untuk kembali...";
			getch();
			exit(0);
			
		}else{
			gotoxy(25, 12);
			cout<<"Tidak tersedia pilihan !";
			gotoxy(25, 13);
			cout<<"Tekan sembarang untuk kembali...";
			getch();
			system("cls");
			goto menu;
		}
	delete pilihan; // membebaskan memori data
}

void Masuk(){ // fungsi untuk masuk ke dalam antrian
	if (Full()){ // antrian jika penuh
		cout<<"Maaf antrian sudah penuh, mohon tunggu sebentar !"<<endl;
		cout<<"Tekan sembarang untuk kembali...";
		getch();
		main();
		
	}else{ // masuk ke antrian 
		menu2:
		string jenis, nama, kendaraan, merk;
		int nomer;
		int pilihan2;
		
		system("cls");
		gotoxy(25, 2);
		cout<<"======================================================"<<endl;
		gotoxy(25, 3);
		cout<<"|		Jasa Cuci dan Service Motor	      |"<<endl;
		gotoxy(25, 4);
		cout<<"======================================================"<<endl;
		gotoxy(25, 5);
		cout<<"|1. Service Ringan                                   |"<<endl;
		gotoxy(25, 6);
		cout<<"|2. Ganti Oli                                        |"<<endl;
		gotoxy(25, 7);
		cout<<"|3. Ganti Ban Dalam                                  |"<<endl;
		gotoxy(25, 8);
		cout<<"|4. Cuci Motor                                       |"<<endl;
		gotoxy(25, 9);
		cout<<"|5. Kembali                                          |"<<endl;
		gotoxy(25, 10);
		cout<<"======================================================"<<endl;
		gotoxy(25, 11);
		cout<<"Pilih : ";
		cin>>pilihan2;
		
		if(pilihan2 == 1){
			jenis="Service Ringan";
			
		}else if(pilihan2 == 2){
			jenis="Ganti Oli";
			
		}else if(pilihan2 == 3){
			jenis="Ganti Ban Dalam";
			
		}else if(pilihan2 == 4){
			jenis="Cuci Motor";
			
		}else if(pilihan2 == 5){
			main();
			
		}else {
			cout<<"Tidak tersedia pilihan !";
			goto menu2;
		}
		
		system("cls");
		cin.ignore();
		gotoxy(25, 2);
		cout<<"======================================================"<<endl;
		gotoxy(25, 3);
		cout<<"|		Jasa Cuci dan Service Motor		      |"<<endl;
		gotoxy(25, 4);
		cout<<"|          Masukkan Data Pelanggan Antian            |"<<endl;
		gotoxy(25, 5);
		cout<<"======================================================"<<endl;
		gotoxy(25, 6);
		cout<<"| Nama			: ";getline (cin, nama);
		gotoxy(25, 7);
		cout<<"| Kendaraan		: ";getline (cin, kendaraan);
		gotoxy(25, 8);
		cout<<"| Merk Kendaraan	: ";getline (cin, merk);
		nomer=P;
		cout<<endl;
		gotoxy(25, 9);
		cout<<"======================================================"<<endl;
		gotoxy(25, 10);
		cout<<"|              Berhasil Masuk Antrian                |"<<endl;
		gotoxy(25, 11);
		cout<<"======================================================"<<endl;
		gotoxy(25, 12);
		cout<<"| No.Antrian 	: "<<P<<"				      |"<<endl;
		AntrianMasuk(jenis, nama, kendaraan, merk, nomer);
		P++;
		gotoxy(25, 13);
		cout<<"______________________________________________________"<<endl;
		gotoxy(25, 14);
		cout<<"Tekan sembarang untuk kembali...";
		getch();
		main();
	} 
}

void Member(){ // fungsi untuk masuk ke menu member 
	system("cls");
	
	int pil;
	
	menu:
	gotoxy(25, 2);
	cout<<"======================================================"<<endl;
	gotoxy(25, 3);
	cout<<"|		Jasa Cuci dan Service Motor	      |"<<endl;
	gotoxy(25, 4);
	cout<<"======================================================"<<endl;
	gotoxy(25, 5);
	cout<<"|1. Daftar Member                                    |"<<endl; 
	gotoxy(25, 6);
	cout<<"|2. Urutkan Member                                   |"<<endl;
	gotoxy(25, 7);	
	cout<<"|3. Cari Member                                      |"<<endl;
	gotoxy(25, 8);
	cout<<"|4. Ceklist                                          |"<<endl;
	gotoxy(25, 9);
	cout<<"|5. Data Member                                      |"<<endl;
	gotoxy(25, 10);
	cout<<"|6. Kembali                                          |"<<endl;
	gotoxy(25, 11);
	cout<<"======================================================"<<endl;
	gotoxy(25, 12);
	cout<<"Masukkan Pilihan anda [1-5]: ";
	cin>>pil;
	
	if(pil == 1){
		Daftar();
		cout<<"Tekan sembarang untuk kembali...";
		getch();
		main();
		
	}else if(pil == 2){
		Urut();
		system("cls");
		cout<<"Data telah diurutkan"<<endl;
		cout<<"Tekan sembarang untuk kembali...";
		getch();
		Member();
		
	}else if(pil== 3){
		Cari();
		cout<<"Tekan sembarang untuk kembali...";
		getch();
		main();
		
	}else if (pil == 4){
		Ceklist();
		cout<<"Tekan sembarang untuk kembali...";
		getch();
		Member();
		
	}else if(pil == 5){
		Tampil();
		cout<<"Data Masih Kosong"<<endl;
		cout<<"Tekan sembarang untuk kembali...";
		getch();
		Member();
		
	}else if (pil == 6){
		main();	
		
	}else{
		goto menu;
	}
}

void Daftar(){ // fungsi untuk mendaftar ke member 
	
	system("cls");
	bool ketemu=false;
	int nomer;
	string cari;
	cin.ignore();
	
	lagi:
	gotoxy(25, 1);
	cout<<"============================================="<<endl;
	gotoxy(25, 2);
	cout<<"|		Daftar Member		     |"<<endl;
	gotoxy(25, 3);
	cout<<"============================================="<<endl;
	gotoxy(25, 4);
	
	nomer=1;
	
	gotoxy(25, 5);
	cout<<"Masukkan Nama anda 	: ";getline(cin, mbr[A].Nama);
	gotoxy(25, 6);
	cout<<"Masukkan Alamat anda	: ";getline (cin, mbr[A].Alamat);
	gotoxy(25, 7);
	cout<<"Centang Masih 1"<<endl;
	gotoxy(25, 8);
	mbr[A].Centang=nomer;
	A++;
	gotoxy(25, 9);
	cout<<"Tekan sembarang untuk kembali..."<<endl;
	getch();
	Member();
}


void Urut(){ // fungsi untuk mengurutkan nama member
	
	for (int j=0; j<A; j++){ // buble sorting ascending
		for (int k=j+1; k<A; k++){
			if (mbr[j].Nama > mbr[k].Nama){
				temp.Nama = mbr[j].Nama;
				mbr[j].Nama = mbr[k].Nama;
				mbr[k].Nama = temp.Nama;
				
				temp.Alamat = mbr[j].Alamat;
				mbr[j].Alamat = mbr[k].Alamat;
				mbr[k].Alamat = temp.Alamat;
				
				temp.Centang = mbr[j].Centang;
				mbr[j].Centang = mbr[k].Centang;
				mbr[k].Centang = temp.Centang;
			}
		}
	}
}

void Tampil(){ // fungsi untuk menampilkan identitas member
	system("cls");
	
	gotoxy(25, 2);
	cout<<"======================================================"<<endl;
	gotoxy(25, 3);
	cout<<"|		Jasa Cuci dan Service Motor	     |"<<endl;
	gotoxy(25, 4);
	cout<<"======================================================"<<endl;
	for (int i=0; i<A; i++){
		cout<<"========================================="<<endl;
		cout<<"            Data Member ke "<<i+1<<endl;
		cout<<"========================================="<<endl;
		cout<<"Nama	: "<<mbr[i].Nama<<endl;
		cout<<"Alamat	: "<<mbr[i].Alamat<<endl;
		cout<<"Centang	: "<<mbr[i].Centang<<endl;
	}
}

void Cari(){ // fungsi untuk mencari nama member
	string cari;
	int ket;
	bool ketemu=false;
	
	cin.ignore();
	system("cls");
	
	gotoxy(25, 2);
	cout<<"======================================================"<<endl;
	gotoxy(25, 3);
	cout<<"|		Jasa Cuci dan Service Motor	      |"<<endl;
	gotoxy(25, 4);
	cout<<"======================================================"<<endl;
	gotoxy(25, 5);
	cout<<"| Masukkan Nama yang ingin dicari : ";
	getline (cin,cari);
	gotoxy(25, 6);
	cout<<"______________________________________________________"<<endl;
	
	for (int i=0; i<100; i++){
		if (cari == mbr[i].Nama){
			ketemu = true;
			ket=i;
			break;
		}
	}if (ketemu){
		system("cls");
		gotoxy(25, 2);
		cout<<"======================================================"<<endl;
		gotoxy(25, 3);
		cout<<"|		Jasa Cuci dan Service Motor	      |"<<endl;
		gotoxy(25, 4);
		cout<<"-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o"<<endl;
		gotoxy(25, 5);
		cout<<"|                 Data Member Ketemu                 |"<<endl;
		gotoxy(25, 6);
		cout<<"======================================================"<<endl;
		gotoxy(25, 7);
		cout<<"| Nama		: "<<mbr[ket].Nama<<endl;
		gotoxy(25, 8);
		cout<<"| Alamat	: "<<mbr[ket].Alamat<<endl;
		gotoxy(25, 9);
		cout<<"| Centang	: "<<mbr[ket].Centang<<endl;
		gotoxy(25, 10);
		cout<<"_______________________________________________________"<<endl;
		gotoxy(25, 11);
		cout<<"Tekan sembarang untuk kembali...";
		getch();
		Member();
	}else{
		cout<<"Nama member tidak ada"<<endl;
		cout<<"Tekan sembarang untuk kembali...";
		getch();
		Member();
	}
}

void Ceklist(){ // fungsi untuk menambah ceklis member dan akan mendapat gratis jika sudah mendapatkan 5 ceklis
	system("cls");
	
	string nama;
	int tampung, ket;
	bool ketemu=false;
	cin.ignore();
	
	cout<<"Masukkan Nama Member : ";
	getline (cin, nama);
	
	for (int i=0; i<100; i++){
		if(nama == mbr[i].Nama){
			ketemu=true;
			ket=i;
			break;
		}
	}if (ketemu){
		cout<<"Centang Anda "<<mbr[ket].Centang<<endl;
		if(mbr[ket].Centang==5){
			cout<<"Selamat anda Mendapatkan gratis Service dan Cuci"<<endl;
		}cout<<"Centang ditambahkan 1 "<<endl;
		tampung=mbr[ket].Centang;
		tampung++;
		mbr[ket].Centang=tampung;
	}else{
		cout<<"Nama tidak ditemukan !"<<endl;
	}
}
