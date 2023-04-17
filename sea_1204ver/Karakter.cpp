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
void Karakter::SetTalentNormal(int level){
	this->TalentNormal = level;
}
void Karakter::SetTalentSkill(int level){
	this->TalentSkill = level;
}
void Karakter::SetTalentBurst(int level){
	this->TalentBurst = level;
}
int Karakter::GetTalentNormal(){
	return this->TalentNormal;
}
int Karakter::GetTalentSkill(){
	return this->TalentSkill;
}
int Karakter::GetTalentBurst(){
	return this->TalentBurst;
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

int PilihanTalent;
void PreTalentUp(){
	cout << "Menu LevelUp Talent" << endl;
	cout << "1. Talent Normal" << endl;
	cout << "2. Talent Skill" << endl;
	cout << "3. Talent Burst" << endl;
	cin >> PilihanTalent;
}
void Karakter::TalentUp(
	Mat_Talent& talent1, Mat_Talent& talent2, Mat_Talent& talent3,
	Mat_Mob& mob1, Mat_Mob& mob2, Mat_Mob& mob3,
	Mat_Weekly& weekly, Mat_Talent& crown)
{
	int 
	switch(PilihanTalent){
		case 1:
			cout << "Anda akan meningkatkan Talent Normal" << endl;
			break;
		case 2:
			cout << "Anda akan meningkatkan Talent Skill" << endl;
			break;
		case 3:
			cout << "Anda akan meningkatkan Talent Burst" << endl;
			break;
		defautl:
			cout << "Out of bound" << endl;
	}
	
	int Teachings = talent1.GetJumlah();
	int Guides = talent2.GetJumlah();
	int Philosophy = talent3.GetJumlah();
	int Mob1 = mob1.GetJumlah();
	int Mob2 = mob2.GetJumlah();
	int Mob3 = mob3.GetJumlah();
	int Weekly = weekly.GetJumlah();
	int Crown = crown.GetJumlah();
	int LvNormal = this->GetTalentNormal();
	
	vector<int> vLimitTalent = {3, 2, 4, 6, 9, 4, 6, 12, 16};
	vector<int> vLimitMob    = {6, 3, 4, 6, 9, 4, 6, 9, 12};
	vector<int> vLimitWeekly = {0, 0, 0, 0, 0, 0, 1, 1, 2};
	vector<int> vLimitCrown  = {0, 0, 0, 0, 0, 0, 0, 0, 1};

	int LimitTalent = vLimitTalent[LvNormal];
	int LimitMob = vLimitMob[LvNormal];
	int LimitWeekly = vLimitWeekly[LvNormal];
	int LimitCrown = vLimitCrown[LvNormal];
	
	switch(LvNormal){
		case 0:
			if(Teachings >= LimitTalent && Mob1 >= LimitMob){
				talent1.KurangJumlah(LimitTalent);
				mob1.KurangJumlah(LimitMob);
				this->SetTalentNormal(1);
			}
			break;
		case 1:
			if(Guides >= LimitTalent && Mob2 >= LimitMob){
				talent2.KurangJumlah(LimitTalent);
				mob2.KurangJumlah(LimitMob);
				this->SetTalentNormal(2);
			}
			break;
		case 2:
			if(Guides >= LimitTalent && Mob2 >= LimitMob){
				talent2.KurangJumlah(LimitTalent);
				mob2.KurangJumlah(LimitMob);
				this->SetTalentNormal(3);
			}
			break;
		case 3:
			if(Guides >= LimitTalent && Mob2 >= LimitMob){
				talent2.KurangJumlah(LimitTalent);
				mob2.KurangJumlah(LimitMob);
				this->SetTalentNormal(4);
			}
			break;
		case 4:
			if(Guides >= LimitTalent && Mob2 >= LimitMob){
				talent2.KurangJumlah(LimitTalent);
				mob2.KurangJumlah(LimitMob);
				this->SetTalentNormal(5);
			}
			break;
		case 5:
			if(Philosophy >= LimitTalent && Mob3 >= LimitMob && Weekly >= LimitWeekly){
				talent3.KurangJumlah(LimitTalent);
				mob3.KurangJumlah(LimitMob);
				weekly.KurangJumlah(LimitWeekly);
				this->SetTalentNormal(6);
			}
			break;
		case 6:
			if(Philosophy >= LimitTalent && Mob3 >= LimitMob && Weekly >= LimitWeekly){
				talent3.KurangJumlah(LimitTalent);
				mob3.KurangJumlah(LimitMob);
				weekly.KurangJumlah(LimitWeekly);
				this->SetTalentNormal(7);
			}
			break;
		case 7:
			if(Philosophy >= LimitTalent && Mob3 >= LimitMob && Weekly >= LimitWeekly){
				talent3.KurangJumlah(LimitTalent);
				mob3.KurangJumlah(LimitMob);
				weekly.KurangJumlah(LimitWeekly);
				this->SetTalentNormal(8);
			}
			break;
		case 8:
			if(Philosophy >= LimitTalent && Mob3 >= LimitMob && Weekly >= LimitWeekly && Crown >= LimitCrown){
				talent3.KurangJumlah(LimitTalent);
				mob3.KurangJumlah(LimitMob);
				weekly.KurangJumlah(LimitWeekly);
				crown.KurangJumlah(LimitCrown);
				this->SetTalentNormal(9);
			}
			break;
		default:
			cout << "Out of Bound!!" << endl;
	}
}
