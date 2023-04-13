#include "Weapon.h"

vector<int> vAscendLv = { 0, 1, 2, 3, 4, 5, 6 };
vector<int> vLimitWeap = { 20, 40, 50, 60, 70, 80, 90 };
vector<int> vLimitLv = { 600, 950, 1350, 1800, 2325, 2925, 3525, 4200, 4950, 5700, 6525, 7400, 8300, 9225, 10200, 11250, 12300, 13425, 14600, 15750 };

Weapon::Weapon(){
	
}
int Weapon::GetLimit(){
	int AscendChar = this->GetAscend();
	return vLimitWeap[AscendChar];
}
int Weapon::GetBatasExpWeap(){
	int LevelWeap = this->GetLevel();
	return vLimitLv[LevelWeap-1];
}
void Weapon::SetLevel(int level){
	this->Level = level;
}
void Weapon::SetAscendLv(int ascend){
	this->AscendLv = ascend;
}
void Weapon::SetNama(string nama){
	this->Nama = nama;
}
int Weapon::GetLevel(){
	return this->Level;
}
int Weapon::GetAscend(){
	return this->AscendLv;
}
string Weapon::GetNama(){
	return this->Nama;
}
void Weapon::ConsumeOre(Mat_Ore& ore, int jumlah){
	int ExpWeap = this->GetExp();
	int LevelWeap = this->GetLevel();
	int LimitWeap = this->GetLimit();
//	cout << "ExpWeap  : " << ExpWeap << endl;
//	cout << "LevelWeap: " << LevelWeap << endl;
//	cout << "LimitWeap: " << LimitWeap << endl;
//	cout << ore.GetExp() << endl;
//	cout << endl;
	
	if(LevelWeap < 90){
		if(LevelWeap != LimitWeap){
			int JumlahOre = ore.GetJumlah();
			if(JumlahOre > 0 && jumlah <= JumlahOre ){
				int ExpOre = ore.GetExp() * jumlah;
				int TotalExp = ExpOre + ExpWeap;
				int Batas = this->GetBatasExpWeap();
				cout << "Jumlah Ore: " << JumlahOre << endl;
				cout << "Exp Ore   : " << ExpOre << endl;
				cout << "Total Exp : " << TotalExp << endl;
				cout << "Batas Exp : " << Batas << endl;
				cout << endl;
				
				if(TotalExp < Batas){
					this->SetExp(TotalExp);
				}else{
					while(TotalExp >= Batas){
						if(LevelWeap != LimitWeap){
							if(TotalExp >= Batas){
								this->Level++;
								TotalExp -= Batas;
								this->SetExp(TotalExp);
								Batas = this->GetBatasExpWeap();
								if(LevelWeap == LimitWeap){
									this->SetExp(0);
								}
							}
						}
					}
				}
				ore.KurangJumlah(jumlah);
			}
		}
	}
}
void Weapon::SetExp(int exp){
	this->Exp = exp;
}
int Weapon::GetExp(){
	return this->Exp;
}
void Weapon::SetID(int id){
	this->ID = id;
}
int Weapon::GetID(){
	return this->ID;
}
void Weapon::Refine(Weapon& weapon){
	if(this->GetID() == weapon.GetID()){
		cout << "Berhasil refine" << endl;
	}else{
		cout << "Gagal Refine" << endl;
	}
}
void Weapon::SetTier(int tier){
	this->Tier = tier;
}
int Weapon::GetTier(){
	return this->Tier;
}
void Weapon::ReturnVector(){
	int AscendLv = this->GetAscend();
	int TierWeap = this->GetTier();
	
	vector<int> vLimitMatWeap, vLimitMobA, vLimitMobB;
	switch(TierWeap){
		case 0:
			vLimitMatWeap = { 1, 1, 2, 1 }; // 2, 3, 3, 4
			vLimitMobA = { 1, 4, 2, 4 }; // 2, 2, 3, 3
			vLimitMobB = { 1, 2, 2, 3 }; // 1, 1, 2, 2
			break;
		case 1:
			vLimitMatWeap = { 1, 1, 3, 1 }; // 2, 3, 3, 4
			vLimitMobA = { 1, 5, 3, 5 };  // 2, 2, 3, 3
			vLimitMobB = { 1, 4, 3, 4 }; // 1, 1, 2, 2
			break;
		case 2:
			vLimitMatWeap = { 5, 5, 9, 5, 9, 6 }; // 2, 3, 3, 4, 4, 5
			vLimitMobA = { 5, 18, 9, 18, 14, 27}; // 2, 2, 3, 3, 4, 4
			vLimitMobB = { 3, 12, 9, 14, 9, 18 }; // 1, 1, 2, 2, 3, 3
			break;
		case 3:
			vLimitMatWeap = { 5, 5, 9, 5, 9, 6 }; // 2, 3, 3, 4, 4, 5
			vLimitMobA = { 5, 18, 9, 18, 14, 27}; // 2, 2, 3, 3, 4, 4
			vLimitMobB = { 3, 12, 9, 14, 9, 18 }; // 1, 1, 2, 2, 3, 3
			break;
		case 4:
			vLimitMatWeap = { 5, 5, 9, 5, 9, 6 }; // 2, 3, 3, 4, 4, 5
			vLimitMobA = { 5, 18, 9, 18, 14, 27}; // 2, 2, 3, 3, 4, 4
			vLimitMobB = { 3, 12, 9, 14, 9, 18 }; // 1, 1, 2, 2, 3, 3
			break;
		default:
			cout << "Nothing" << endl;
	}
}
void Weapon::Ascend(
	Mat_WeapAsc& mat1, Mat_WeapAsc& mat2, Mat_WeapAsc& mat3, Mat_WeapAsc& mat4,
	Mat_Mob& moba1, Mat_Mob&  moba2, Mat_Mob& moba3,
	Mat_Mob& mobb1, Mat_Mob& mobb2, Mat_Mob& mobb3){
	int AscendLv = this->GetAscend();
	int TierWeap = this->GetTier();
	
	vector<int> vLimitMatWeap, vLimitMobA, vLimitMobB;
	switch(TierWeap){
		case 0:
			vLimitMatWeap = { 1, 1, 2, 1 }; // 2, 3, 3, 4
			vLimitMobA = { 1, 4, 2, 4 }; // 2, 2, 3, 3
			vLimitMobB = { 1, 2, 2, 3 }; // 1, 1, 2, 2
			break;
		case 1:
			vLimitMatWeap = { 1, 1, 3, 1 }; // 2, 3, 3, 4
			vLimitMobA = { 1, 5, 3, 5 };  // 2, 2, 3, 3
			vLimitMobB = { 1, 4, 3, 4 }; // 1, 1, 2, 2
			break;
		case 2:
			vLimitMatWeap = { 2, 2, 4, 2, 4, 3 }; // 2, 3, 3, 4, 4, 5
			vLimitMobA = { 2, 8, 4, 8, 6, 12}; // 2, 2, 3, 3, 4, 4
			vLimitMobB = { 1, 5, 4, 6, 4, 8 }; // 1, 1, 2, 2, 3, 3
			break;
		case 3:
			vLimitMatWeap = { 3, 3, 6, 3, 6, 4 }; // 2, 3, 3, 4, 4, 5
			vLimitMobA = { 3, 12, 6, 12, 9, 18}; // 2, 2, 3, 3, 4, 4
			vLimitMobB = { 2, 8, 6, 9, 6, 12 }; // 1, 1, 2, 2, 3, 3
			break;
		case 4:
			vLimitMatWeap = { 5, 5, 9, 5, 9, 6 }; // 2, 3, 3, 4, 4, 5
			vLimitMobA = { 5, 18, 9, 18, 14, 27}; // 2, 2, 3, 3, 4, 4
			vLimitMobB = { 3, 12, 9, 14, 9, 18 }; // 1, 1, 2, 2, 3, 3
			break;
		default:
			cout << "Nothing" << endl;
}
	
	int Jmlmat1 = mat1.GetJumlah();
	int Jmlmat2 = mat2.GetJumlah();
	int Jmlmat3 = mat3.GetJumlah();
	int Jmlmat4 = mat4.GetJumlah();
	int Jmlmoba1 = moba1.GetJumlah();
	int Jmlmoba2 = moba2.GetJumlah();
	int Jmlmoba3 = moba3.GetJumlah();
	int Jmlmobb1 = mobb1.GetJumlah();
	int Jmlmobb2 = mobb2.GetJumlah();
	int Jmlmobb3 = mobb3.GetJumlah();
	
	switch(AscendLv){
		case 0:
			break;
		default:
			cout << "Ascend Sudah Maksimal!!" << endl;
	}
};
