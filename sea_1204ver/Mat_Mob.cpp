#pragma once
#include "Material.cpp"

class Mat_Mob : public Material{
	private:
		string Nama;
	public:
		Mat_Mob(){
			
		}
};

Mat_Mob* SlimeCondensate = new Mat_Mob();
Mat_Mob* SlimeSecretion = new Mat_Mob();
Mat_Mob* SlimeConcentrate = new Mat_Mob();

Mat_Mob* HeavyHorn = new Mat_Mob();
Mat_Mob* BlackBronzeHorn = new Mat_Mob();
Mat_Mob* BlackCrystalHorn = new Mat_Mob();

Mat_Mob* FirmArrowhead = new Mat_Mob();
Mat_Mob* SharpArrowhead = new Mat_Mob();
Mat_Mob* FeatheredArrowhead = new Mat_Mob();

Mat_Mob* DamagedPrism = new Mat_Mob();
Mat_Mob* TurbidPrism = new Mat_Mob();
Mat_Mob* RadiantPrism = new Mat_Mob();

Mat_Mob* FungalSpores = new Mat_Mob();
Mat_Mob* LuminescentPollen = new Mat_Mob();
Mat_Mob* CrystallineCystDust = new Mat_Mob();

Mat_Mob* HunterSacKnife = new Mat_Mob();
Mat_Mob* AgentSacKnife = new Mat_Mob();
Mat_Mob* InspSacKnife = new Mat_Mob();

Mat_Mob* DiviningScroll = new Mat_Mob();
Mat_Mob* SealedScroll = new Mat_Mob();
Mat_Mob* ForbiddenCScroll = new Mat_Mob();

Mat_Mob* LeyLineBranch = new Mat_Mob();
Mat_Mob* LeyLineLeaves = new Mat_Mob();
Mat_Mob* LeyLineSprout = new Mat_Mob();

//void CraftSlimeSecretion(int jumlah){
//	int JumlahSConden = SlimeCondensate->GetJumlah();
//	int JumlahPerlu = jumlah*3;
//	if(JumlahSConden >= JumlahPerlu){
//		int Sisa = JumlahPerlu % 3;
//		int Hasil = (JumlahPerlu - Sisa) / 3;
//		cout << "Sisa Slime Conden: " << Sisa << endl;
//		cout << "Hasil Slime Secre: " << Hasil << endl;
//		SlimeCondensate->KurangJumlah(JumlahPerlu);
//		SlimeSecretion->TambahJumlah(Hasil);
//	}
//	
//	//SlimeCondensate->KurangJumlah(JumlahPerlu);
//	
////	int JumlahSlimeConden = SlimeCondensate->GetJumlah();
////	if(JumlahSlimeConden >= 3){
////		int Sisa = JumlahSlimeConden % 3;
////		int SlimeSec = (JumlahSlimeConden - Sisa) / 3;
////	}else{
////		cout << "Tidak bisa craft" << endl;
////	}
//
////Mat_Mob SlimeCondensate, SlimeSecretion, SlimeConcentrate;
////Mat_Mob* pSlimeCondensate = &SlimeCondensate;
////Mat_Mob* pSlimeSecretion = &SlimeSecretion;
////Mat_Mob* pSlimeConcentrate = &SlimeConcentrate;
//}
