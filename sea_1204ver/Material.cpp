#pragma once
#include "Material.h"

Material::Material(){
	
}
void Material::TambahJumlah(int jumlah){
	this->Jumlah += jumlah;
}
void Material::KurangJumlah(int jumlah){
	this->Jumlah -= jumlah;
}
int Material::GetJumlah(){
	return this->Jumlah;
}
void Material::SetJumlah(int jumlah){
	this->Jumlah = jumlah;
}

void CraftMaterial(Material& awal, Material& akhir, int jumlah){
	int JumlahAwal = awal.GetJumlah();
	int JumlahButuh = jumlah * 3;
	if(JumlahAwal >= JumlahButuh){
		int Hasil = JumlahButuh / 3;
		awal.KurangJumlah(JumlahButuh);
		akhir.TambahJumlah(Hasil);
	}
}
