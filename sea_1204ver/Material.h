#pragma once
#include <string>
using namespace std;

class Material{
	private:
		int ID, Jumlah=0;
		string Nama;
		
	public:
		Material();
		void SetNama(string nama);
		void SetID(int ID);
		
		void SetJumlah(int jumlah);
		void TambahJumlah();
		void TambahJumlah(int jumlah);
		void KurangJumlah();
		void KurangJumlah(int jumlah);
		
		int GetJumlah();
		int GetID();
		string GetNama();
		
		void CraftMaterial(Material& awal, Material& akhir, int jumlah);
};
