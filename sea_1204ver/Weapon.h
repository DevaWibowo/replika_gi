#pragma once
#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include "Mat_WeapAsc.cpp"
#include "Mat_Mob.cpp"

class Weapon{
	private:
		int Level, AscendLv, Exp, ID, Tier;
		string Nama;
	public:
		Weapon();
		
		void SetLevel(int level);
		void SetAscendLv(int ascend);
		void SetNama(string nama);
		void SetExp(int exp);
		void SetID(int id);
		void SetTier(int tier);
		
		int GetTier();
		int GetID();
		int GetExp();
		int GetLimit();
		int GetLevel();
		int GetAscend();
		int GetBatasExpWeap();
		string GetNama();
		void ReturnVector();
		void Ascend(Mat_WeapAsc& mat1, Mat_WeapAsc& mat2, Mat_WeapAsc& mat3, Mat_WeapAsc& mat4, Mat_Mob& moba1, Mat_Mob&  moba2, Mat_Mob& moba3, Mat_Mob& mobb1, Mat_Mob& mobb2, Mat_Mob& mobb3);
		void ConsumeOre(Mat_Ore &ore, int jumlah);
		void Refine(Weapon& weapon);
};

#endif
