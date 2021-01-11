#include <iostream>
using namespace std;
class Otel
{
private:
	string* musteriAdi[100];
	string* soyadi[100];
	int toplam;
	int sayac1;
	int sayac2;
	enum Statu
	{
		bos,
		dolu
	}odalar[45];
public:
	Otel();
	void OdaIsletmesi();
	void OdaRezervasyonu();
	void OdaBosaltma();
	void MusterilerinSayisi();
	void YatakOdasiRaporu();
	void SeminerOdasiRaporu();
	void Gelir();
};
Otel::Otel()
{
	sayac1 = 0;
	sayac2 = 0;
	toplam = 0;
	OdaIsletmesi();
}
void Otel::OdaIsletmesi()
{
	int sayi;
	for (int a = 1; a < 46; a++)
	{
		odalar[a] = bos;
	}
	do
	{
		cout << endl << "\t---Otel---" << endl;
		cout << "\t\t1. Oda Rezervasyonu" << endl;
		cout << "\t\t2. Oda Bosaltma" << endl;
		cout << "\t\t3. Dolu Oda Sayisi" << endl;
		cout << "\t\t4. Yatak Odasi Raporu" << endl;
		cout << "\t\t5. Seminer Odasi Raporu" << endl;
		cout << "\t\t6. Gunluk Toplam Gelir" << endl;
		cout << "\t\t7. Cikis" << endl << endl;
		cout << "Seciminizin numarasini giriniz:";
		cin >> sayi;
		switch (sayi)
		{
		case 1:
			OdaRezervasyonu();
			break;
		case 2:
			OdaBosaltma();
			break;
		case 3:
			MusterilerinSayisi();
			break;
		case 4:
			YatakOdasiRaporu();
			break;
		case 5:
			SeminerOdasiRaporu();
			break;
		case 6:
			Gelir();
			break;
		case 7:
			exit(1);
		default:
			cout << "Yanlis bir deger girdiniz. Lutfen dogru bir deger giriniz." << endl;
			break;
		}
	} while (sayi != 7);
}
void Otel::OdaRezervasyonu()
{
	int i = 1;
	int j = 6;
	int k = 16;
	int sayi;
	string ad;
	string o_ad;
	int x2;
	cout << endl << "\t\tLutfen bir oda tipi seciniz." << endl << endl;
	cout << "\t\t1. 1 Kisilik Oda (40 TL)" << endl;
	cout << "\t\t2. 2 Kisilik Oda (60 TL)" << endl;
	cout << "\t\t3. 3 Kisilik Oda (300 TL)" << endl;
	cin >> sayi;
	if (sayi == 1)
	{
		while (j < 16)
		{
			if (odalar[j] != dolu)
			{
				odalar[j] = dolu;
				cout << "Adiniz:";
				cin >> ad;
				cout << "Soyadiniz:";
				cin >> o_ad;
				cout << "Kac gun kalacaksiniz? :";
				cin >> x2;
				toplam += (x2 * 40);
				sayac2++;
				musteriAdi[j] = new string;
				*musteriAdi[j] = ad;
				soyadi[j] = new string;
				*soyadi[j] = o_ad;
				break;
			}
			j++;
		}
		if (j==16)
		{
			cout << "1 kisilik odalar dolu.";
		}
		
	}
	else if (sayi == 2)
	{
		while (k < 46)
		{
			if (odalar[k] != dolu)
			{
				odalar[k] = dolu;
				cout << "Adiniz:";
				cin >> ad;
				cout << "Soyadiniz:";
				cin >> o_ad;
				cout << "Kac gun kalacaksiniz? :";
				cin >> x2;
				toplam += (x2 * 60);
				sayac2 = sayac2 + 1;
				musteriAdi[k] = new string;
				*musteriAdi[k] = ad;
				soyadi[k] = new string;
				*soyadi[k] = o_ad;
				break;
			}
			k++;
		}
		if (k == 46)
		{
			cout << "Butun odalar dolu." << endl << endl;
		}
	}
	else if (sayi == 3)
	{
		while (i < 6)
		{
			if (odalar[i] != dolu)
			{
				odalar[i] = dolu;
				cout << "Adiniz:";
				cin >> ad;
				cout << "Soyadiniz:";
				cin >> o_ad;
				cout << "Kac gun kalacaksiniz? :";
				cin >> x2;
				toplam = toplam + x2 * 300;
				sayac1 = sayac1 + 1;
				musteriAdi[i] = new string;
				*musteriAdi[i] = ad;
				soyadi[i] = new string;
				*soyadi[i] = o_ad;
				break;
			}
			i = i + 1;
		}
		if (i == 6)
		{
			cout << "Butun seminer odalari dolu." << endl;
		}
	}
	else
	{
		cout << "Lutfen gecerli bir sayi giriniz.";
	}
}
void Otel::OdaBosaltma()
{
	int sayi;
	cout << "Bosaltacaginiz oda numarasi:";
	cin >> sayi;
	if (odalar[sayi] == dolu)
	{
		if (sayi > 0 && sayi < 6)
		{
			odalar[sayi] = bos;
			delete musteriAdi[sayi];
			delete soyadi[sayi];
			--sayac1;
			cout << "Oda silindi." << endl;
		}
		else if (sayi > 5 && sayi < 46)
		{
			odalar[sayi] = bos;
			delete musteriAdi[sayi];
			delete soyadi[sayi];
			sayac2--;
			cout << "Oda silindi." << endl;
		}
	}
}
void Otel::MusterilerinSayisi()
{
	cout << "Dolu oda sayisi:" << (sayac1 + sayac2) << endl;
}
void Otel::YatakOdasiRaporu()
{
	int i;
	if (sayac2 == 0)
	{
		cout << "Butun odalar bos.";
	}
	else
	{
		cout << "Oda Numarasi  Musteri Adi  Musteri Soyadi  " << endl;
		cout << "===============================" << endl;
		i = 6;
		while (i < 46)
		{
			if (odalar[i] == dolu)
			{
				cout << i << "\t\t" << *musteriAdi[i] << "\t\t" << *soyadi[i] << endl;
			}
			i = i + 1;
		}
	}
}
void Otel::SeminerOdasiRaporu()
{
	int ct;
	while (sayac1 != 6)
	{
		cout << "Seminer odalari dolu." << endl;
		ct = 1;
		while (ct < 6)
		{
			if (odalar[ct] == dolu)
			{
				cout << "Oda numarasi " << ct << endl;
			}
			ct = ct + 1;
		}
	}
}
void Otel::Gelir()
{
	cout << "Gelir: " << toplam << endl;
}
int main()
{
	Otel obj;
	return 0;
}
