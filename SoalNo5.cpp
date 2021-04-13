#include "iostream"
#include "conio.h"
using namespace std;
class Person{
	private :
		string name, address;
		int telephone;
	public :
		Person(){
			name = "";
			address = "";
			telephone = 0;
		}
		void setName(string n){
			name = n;
		}
		void setAddress(string a){
			address = a;
		}
		void setTelephone(int t){
			telephone = t;
		}
		string getName(){
			return name;
		}
		string getAddress(){
			return address;
		}
		int getTelephone(){
			return telephone;
		}
};
class Customer : public Person{
	private :
		int customerNumber;
		bool mailingList;
	public :
		Customer(){
			customerNumber = 0;
			mailingList = false;
		}
		void setCustomerNumber(int cn){
			customerNumber = cn;
		}
		void setMailingList(bool ml){
			mailingList = ml;
		}
		void printMailingList(bool r){
			if(r == true){
				cout<<"apakah anda telah berlangganan mailing list ? Yes\n";
			} else if(r == false) {
				cout<<"apakah anda telah berlangganan mailing list ? No\n";
			}
		}
		int getCustomerNumber(){
			return customerNumber;
		}
		bool getMailingList(){
			return mailingList;
		}
};
class PrefferedCustomer: public Customer{
	private :
		int purchases, discount;
	public :
		PrefferedCustomer(){
			purchases = 0;
			discount = 0;
		}
		void setPurchases(int p){
			purchases = p;
		}
		void setDiscount(int d){
			discount = d;
		}
		int getPurchases(){
			return purchases;
		}
		int getDiscount(){
			return discount;
		}
};
int main(){
	string nama,alamat, mail;
	int telepon, id, bayar, diskon, x;
	bool loop = true;
	PrefferedCustomer c;
	while(loop){
		awal :
			system("cls");
			cout<<"---------------------------\n";
			cout<<"ahmad fikri husaini\n";
			cout<<"---------------------------\n";
			cout<<"pilih menu berikut ini : \n";
			cout<<"1. masukan data customer\n";
			cout<<"2. print data customer\n";
			cout<<"3. keluar\n";
			cout<<"masukan pilihan anda : "; cin>> x;
			switch(x){
				case 1:
					cout<<"nomer customer : "; cin>>id;
					cout<<"nama customer : "; cin>>nama;
					cout<<"alamat customer : "; cin>>alamat;
					cout<<"telepon customer : "; cin>>telepon;
					masukan :
						cout<<"apakah anda ingin menerima mailing list ? [y/n] :"; cin>>mail;
						c.setName(nama);
						c.setAddress(alamat);
						c.setCustomerNumber(id);
						c.setTelephone(telepon);
						if(mail == "y" || mail == "Y"){
							c.setMailingList(true);
						} else if(mail == "n" || mail == "N"){
							c.setMailingList(false);
						} else {
							goto masukan;
						}
					cout<<"Jumlah pembelian (dalam satuan dolar [$]) : "; cin>>bayar;
					if(bayar >= 500){
						c.setDiscount(5);
					} else if(bayar >= 1000){
						c.setDiscount(6);
					} else if(bayar >= 1500){
						c.setDiscount(7);
					} else if(bayar >= 2000){
						c.setDiscount(10);
					} else {
						c.setDiscount(0);
					}
					c.setName(nama);
					c.setCustomerNumber(id);
					c.setAddress(alamat);
					c.setTelephone(telepon);
					c.setPurchases(bayar);
					cout<<"\ndata berhasil dimasukan\n";
					getch();
					break;
				case 2:
					cout<<"\nnomor Customer : "<<c.getCustomerNumber()<<"\n";
					cout<<"nama customer : "<<c.getName()<<"\n";
					cout<<"alamat customer : "<<c.getAddress()<<"\n";
					cout<<"no. telepon customer : "<<c.getTelephone()<<"\n";
					c.printMailingList(c.getMailingList());
					cout<<"jumlah pembelian terakhir : $"<<c.getPurchases()<<"\n";
					if(c.getDiscount() == 5){
						cout<<"anda memiliki voucher discount sebesar "<<c.getDiscount()<<"% untuk pembelian barang selanjutnya\n";
					} else if(c.getDiscount() == 6){
						cout<<"anda memiliki voucher discount sebesar "<<c.getDiscount()<<"% untuk pembelian barang selanjutnya\n";
					} else if(c.getDiscount() == 7){
						cout<<"anda memiliki voucher discount sebesar "<<c.getDiscount()<<"% untuk pembelian barang selanjutnya\n";
					} else if(c.getDiscount() ==  10){
						cout<<"anda memiliki voucher discount sebesar "<<c.getDiscount()<<"% untuk pembelian barang selanjutnya\n";
					} else {
						cout<<"maaf anda tidak memiliki voucher discount apapun\n";
					}
					getch();
					break;
				case 3:
					loop = 0;
					break;
				default:
					cout<<"\nmaaf perintah yang tersedia hanya 1-3 saja!\n";
					loop = 0;
					break;
			}
	}
	
	return 0;
}
