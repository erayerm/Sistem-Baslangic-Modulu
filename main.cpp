#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void islem(int);
void program();
void cikisKontrol(int);


int main(){
	
	program();
	
	return 0;
}

void program(){
	
	cout<<"Opsiyon 1 : Arp Taraması"<< endl;
	cout<<"Opsiyon 2 : SMB Paylaşımları"<< endl;
	cout<<"Opsiyon 3 : SMB üzerinden İşletim Sistemi Kontrolleri"<< endl;
	cout<<"Opsiyon 4 : SNMP Bulk DOS Saldırısı"<< endl;
	cout<<"Seçiminizi girin (1-4):  ";
	int secim;
	cin>>secim;
	islem(secim);
	cout<<"Devam Etmek İçin 1, Programı Sonlandırmak İçin 0:  ";
	int ikinciSecim;
	cin>>ikinciSecim;
	cikisKontrol(ikinciSecim);
	
}

void cikisKontrol( int a){
	switch(a){
		case 0:
			cout<<"Program Sonlandı...";
			break;
		case 1:
			program();
			break;
		default:
			cout<<"Hatalı Giriş Yaptınız! - Devam Etmek İçin 1, Programı Sonlandırmak İçin 0"<<endl;
			cin>>a;
			cikisKontrol(a);
	}
}

void islem (int a){
	
	switch(a){
		case 1:
			//Arp Taraması
			system("sudo arp-scan -l");
			break;
		case 2:
			//SMB Paylaşımları
			enumIslem();
			break;
		case 3:
			//SMB üzerinden İşletim Sistemi Kontrolleri
			break;
		case 4:
			//SNMP Bulk DOS Saldırısı
			break;
		default:
			cout<<"Hatalı Giriş Yaptınız! - ";
			program();
	}
	
}

void enumIslem(){
	
	string enumHedefIP;
	cout<<"Hedef IP'yi girin:  ";
	cin>>enumHedefIP;
	string komutEnum4Linux_S = "enum4linux " + enumHedefIP;
	int enumSayi = komutEnum4Linux_S.length();
	char komutEnum4Linux_C[enumSayi + 1];
	strcpy(komutEnum4Linux_C, komutEnum4Linux_S.c_str());
	system(komutEnum4Linux_C);
	
}