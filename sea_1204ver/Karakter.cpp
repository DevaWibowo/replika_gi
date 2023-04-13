#pragma once
#include "kamus.h"
#include "Karakter.h"
#include "Akun.cpp"

vector<int> vBatasExp = { 1000,1325,1700,2150,2625,3150,3725,4350,5000,5700,6450,7225,8050,8925,9825,10750,11725,12725,13775,14875,16800,18000,19250,20550,21875,23250,24650,26100,27575,29100 };
vector<int> vAscend = { 0, 1, 2, 3, 4, 5, 6 };
vector<int> vLimit = { 20, 40, 50, 60, 70, 80, 90};

//void Karakter::AscendChar(){
//	int AscendC = this->GetAscend();
//	if(AscendC < 6){
//		this->Ascend++;
//	}
//}

// IMPLEMENTASI CONSTRUCTOR
Karakter::Karakter(){
	
}

// IMPLEMENTASI METHOD SETTER
void Karakter::SetNama(string nama){
	this->Nama = nama;
}
void Karakter::SetHealthPoint(double hp){
	this->HealthPoint = hp;
}
void Karakter::SetExp(int exp){
	this->Experience = exp;
}
void Karakter::SetLevel(int level){
	this->Level = level;
}
void Karakter::SetLimitLevel(int limit){
	this->LimitLevel = limit;
}
void Karakter::SetAscend(int ascend){
	this->Ascend = ascend;
}

// IMPLEMENTASI METHOD GETTER
string Karakter::GetNama(){
	return this->Nama;
}
double Karakter::GetHealthPoint(){
	return this->HealthPoint;
}
int Karakter::GetBatasExpV(){
	int Level = this->GetLevel();
	return vBatasExp[Level-1];
}
int Karakter::GetExp(){
	return this->Experience;
}
int Karakter::GetBatasExp(){
	return this->BatasExp;
}
int const Karakter::GetLevel(){
	return this->Level;
}
int Karakter::GetTier(){
	return this->Tier;
//	int tier = this->Tier;
//	switch(tier){
//		case 0:
//			cout << "Tier 0" << endl;
//			break;
//		case 1:
//			cout << "Tier 1" << endl;
//			break;
//		case 2:
//			cout << "Tier 2" << endl;
//			break;
//	}
}
int Karakter::GetAscend(){
	return this->Ascend;
}
int Karakter::GetLimitLevel(){
	int ascend = this->GetAscend();
	return vLimit[ascend];
}

// IMPLEMENTASI METHOD TAMBAH PROPERTI
void Karakter::TambahHealthPoint(double hp){
	this->HealthPoint += hp;
}
void Karakter::TambahAllHealthPoint(double hp){
	this->HealthPoint += hp;
}
void Karakter::TambahLevel(){
	this->Level++;
}

// IMPLEMENTASI METHOD SKILL
void Karakter::HealTarget(Karakter *karakter){
	double hp = this->GetHealthPoint() * 0.5;
	karakter->HealthPoint += hp;
}
void Karakter::HealTeam(Karakter *karakter[], int size){
	double hp = this->GetHealthPoint() * 0.2;
	for(int i = 0; i < size; i++){
		karakter[i]->HealthPoint += hp;
	}
	cout << endl;
}

// IMPLEMENTASI METHOD CETAK VEKTOR
void Karakter::PrintArray(int arr[], int size){
	for(int i = 0; i < size; i++){
		cout << arr[i] << ' ';
	}
	cout << endl;
}
void Karakter::PrintArray(string arr[], int size){
	for(int i = 0; i < size; i++){
		cout << arr[i] << ' ';
	}
	cout << endl;
}

// IMPLEMENTASI METHOD GROWTH
void Karakter::ConsumeExpBook(ExpBook& buku, int amount){
	int ExpChar = this->GetExp();
	int LevelChar = this->GetLevel();
	int Limit = this->GetLimitLevel();
	if(LevelChar < 90){
		if(LevelChar != Limit){
			int JumlahBuku = buku.GetJumlah();
			if(JumlahBuku >= 0 && amount <= JumlahBuku){
				int ExpBuku = buku.GetExp() * amount;
				int TotalExp = ExpChar + ExpBuku;
				int Batas = this->GetBatasExpV();
				
				if(TotalExp < Batas){
					this->SetExp(TotalExp);
				}else{
					while(TotalExp >= Batas){
						if(LevelChar != Limit){
							if(TotalExp >= Batas){
								this->Level++;
								TotalExp -= Batas;
								this->SetExp(TotalExp);
								Batas = this->GetBatasExpV();
								if(LevelChar == Limit){
									this->SetExp(0);
								}
							}
						}
					}
				}
				buku.KurangJumlah(amount);
			}
		}
	}
}
void Karakter::LevelUp(){
	int Exp, Batas;
	Exp = this->GetExp();
	Batas = this->GetBatasExpV();
	while(Exp >= Batas){
		this->Level++;
		Exp -= Batas;
		if(Exp <= 0){
			this->SetExp(0);
		}
		//cout << this->GetExp() << endl;
		vBatasExp.erase(vBatasExp.begin());
	}
}
void Karakter::LimitBreak(int level, Material tier1, Material tier2){
	string pesan = "Tidak bisa Limit Break!!";
	int lmd = Satu->GetLMD(), biaya = 50000;
	if(level != 50){
		cout << pesan << endl;
		cout << "Level tidak mencukupi" << endl;
	}else{
		if(lmd < biaya){
			cout << pesan << endl;
			cout << "LMD tidak mencukupi!!" << endl;
		}else{
			if(this->GetTier() == 2){
				cout << pesan << endl;
				cout << "Karakter sudah mencapai tingkatan tertinggi!!" << endl;
			}else{
				this->Tier++;
				this->Level = 0;
				Satu->SetLMD(lmd - biaya);
			}
		}
	}
	
}

// IMPLEMENTASI METHOD CETAK
void Karakter::CetakExp(){
	cout << "Exp Karakter: " << this->GetExp() << endl;
}
void Karakter::CetakBatasExp(vector<int> vector){
	for(int i : vector){
		cout << i << endl;
	}
//	for(int i = 0; i < vector.size(); i++){
//		cout << vector[i] << endl;
//	}
}
void Karakter::CetakLv(){
	cout << "Level Karakter: " << this->GetLevel() << endl;
}
void Karakter::CetakHP(){
	cout << "HealthPoint Karakter: " << this->GetHealthPoint() << endl;
}
void Karakter::CetakTier(){
	cout << "Tier Karakter: " << this->GetTier() << endl;
}
void Karakter::CetakNama(){
	cout << "Nama Karakter: " << this->GetNama() << endl;
}
void Karakter::CetakBatasExp(){
	cout << "Batas Exp Karakter: " << this->GetBatasExpV() << endl;
}
void Karakter::Display(){
	cout << "Level Karakter      : " << this->GetLevel() << endl;
	cout << "Ascend Tier Karakter: " << this->GetAscend() << endl;
	cout << "Limit Level Karakter: " << this->GetLimitLevel() << endl;
	cout << "Batas Exp Karakter  : " << this->GetBatasExpV() << endl;
//	cout << "EXP Karakter  : " << this->GetExp() << endl;

	cout << endl;
}
//void Karakter::AscendChar(Mat_Gem& silver, Mat_Gem& fragment, Mat_Gem& chunk, Mat_Gem& gemstone, Mat_Boss& boss, Mat_Local& local, Mat_Mob& mob1, Mat_Mob& mob2, Mat_Mob& mob3){
//	int JmlGemSilver = silver.GetJumlah();
//	cout << JmlGemSilver << endl;
//	silver.SetJumlah(5);
//	cout << JmlGemSilver << endl;
//	cout << "ASCEND BERHASIL" << endl;
//	int AscendLv = this->GetAscend();	
//}
void Karakter::AscendChar(
	Mat_Gem& silver, 
	Mat_Gem& fragment, 
	Mat_Gem& chunk, 
	Mat_Gem& gemstone, 
	Mat_Boss& boss, 
	Mat_Local& local, 
	Mat_Mob& mob1, 
	Mat_Mob& mob2, 
	Mat_Mob& mob3
){
	int AscendLv = this->GetAscend();
	int JmlSilver = silver.GetJumlah();
	int JmlFragment = fragment.GetJumlah();
	int JmlChunk = chunk.GetJumlah();
	int JmlGemstone = gemstone.GetJumlah();
	int JmlBoss = boss.GetJumlah();
	int JmlLocal = local.GetJumlah();
	int JmlMob1 = mob1.GetJumlah();
	int JmlMob2 = mob2.GetJumlah();
	int JmlMob3 = mob3.GetJumlah();
	
	vector<int> vLimitGem = { 1, 3, 6, 3, 6, 6 };
	vector<int> vLimitBoss = { 0, 2, 4, 8, 12, 20 };
	vector<int> vLimitMob = { 3, 15, 12, 18, 12, 24 };
	vector<int> vLimitLocal = { 3, 10, 20, 30, 45, 60 };
	
	int BatasGem = vLimitGem[AscendLv];
	int BatasLocal = vLimitLocal[AscendLv];
	int BatasMob = vLimitMob[AscendLv];
	int BatasBoss = vLimitMob[AscendLv];
	
	switch(AscendLv){
		case 0:
			if(JmlSilver >= BatasGem && JmlLocal >= BatasLocal && JmlMob1 >= BatasMob){
				silver.KurangJumlah(BatasGem);
				local.KurangJumlah(BatasLocal);
				mob1.KurangJumlah(BatasMob);
				this->SetAscend(1);
			}
			break;
		case 1:
			if(JmlFragment >= BatasGem && JmlBoss >= BatasBoss && JmlLocal >= BatasLocal && JmlMob1 >= BatasMob){
				fragment.KurangJumlah(BatasGem);
				boss.KurangJumlah(BatasBoss);
				local.KurangJumlah(BatasLocal);
				mob1.KurangJumlah(BatasMob);
				this->SetAscend(2);
			}
			break;
		case 2:
			if(JmlFragment >= BatasGem && JmlBoss >= BatasBoss && JmlLocal >= BatasLocal && JmlMob2 >= BatasMob){
				fragment.KurangJumlah(BatasGem);
				boss.KurangJumlah(BatasBoss);
				local.KurangJumlah(BatasLocal);
				mob2.KurangJumlah(BatasMob);
				this->SetAscend(3);
			}
			break;
		case 3:
			if(JmlChunk >= BatasGem && JmlBoss >= BatasBoss && JmlLocal >= BatasLocal && JmlMob2 >= BatasMob){
				chunk.KurangJumlah(BatasGem);
				boss.KurangJumlah(BatasBoss);
				local.KurangJumlah(BatasLocal);
				mob2.KurangJumlah(BatasMob);
				this->SetAscend(4);
			}
			break;
		case 4:
			if(JmlChunk >= BatasGem && JmlBoss >= BatasBoss && JmlLocal >= BatasLocal && JmlMob3 >= BatasMob){
				chunk.KurangJumlah(BatasGem);
				boss.KurangJumlah(BatasBoss);
				local.KurangJumlah(BatasLocal);
				mob3.KurangJumlah(BatasMob);
				this->SetAscend(5);
			}
			break;
		case 5:
			if(JmlGemstone >= BatasGem && JmlBoss >= BatasBoss && JmlLocal >= BatasLocal && JmlMob3 >= BatasMob){
				gemstone.KurangJumlah(BatasGem);
				boss.KurangJumlah(BatasBoss);
				local.KurangJumlah(BatasLocal);
				mob3.KurangJumlah(BatasMob);
			}
			break;
		default:
			cout << "UNDEFINED" << endl;
	}
}


