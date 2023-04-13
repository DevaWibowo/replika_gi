#pragma once
#ifndef EXPBOOK_H
#define EXPBOOK_H
#include <string>
using namespace std;

class ExpBook{
	private:
		int ID, AmountExp, Jumlah;
		string Nama;
		
	public:
		// CONSTRUCTOR
		ExpBook(int id, string nama, int amount);
		
		// METHOD SETTER
		void SetJumlah(int jml);
		
		// METHOD GETTER
		int GetID();
		int GetExp();
		int GetJumlah();
		string GetNama();
		
		// METHOD PENGURANGAN
		void KurangJumlah();
		void KurangJumlah(int jml);
		
		// METHOD CETAK
		void CetakJumlah();
		void CetakID();
		void CetakAmount();
};

#endif
