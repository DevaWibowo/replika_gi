#pragma once
#include "ExpBook.h"
#include <iostream>

ExpBook* WandererAdvice = new ExpBook(1, "Wanderer's' Advice", 1000);
ExpBook* AdventurerExperience = new ExpBook(2, "Adventurer's' Experience", 5000);
ExpBook* HeroWit = new ExpBook(3, "Hero's Wit", 20000);

// IMPLEMENTADI CONSTRUCTOR
ExpBook::ExpBook(int id, string nama, int amount) : ID(id), Nama(nama), AmountExp(amount){
	
}

// IMPLEMENTASI METHOD GETTER
int ExpBook::GetExp(){
	return this->AmountExp;
}
int ExpBook::GetJumlah(){
	return this->Jumlah;
}
int ExpBook::GetID(){
	return this->ID;
}
string ExpBook::GetNama(){
	return this->Nama;
}

// IMPLEMENTASI METHOD PENGURANGAN
void ExpBook::KurangJumlah(int jml){
	this->Jumlah -= jml;
}

// IMPLEMENTASI METHOD SETTER
void ExpBook::SetJumlah(int jml){
	this->Jumlah = jml;
}


// IMPLEMENTASI METHOD CETAK
void ExpBook::CetakJumlah(){
	cout << "Jumlah EXP Book: " << this->GetJumlah() << endl;
}
void ExpBook::CetakID(){
	cout << "ID EXP Book: " << this->GetID() << endl;
}
void ExpBook::CetakAmount(){
	cout << "Amount EXP " << this->GetNama() << ": " << this->GetExp() << endl;
}

//void ExpBook::KurangJumlah(){
//	this->Jumlah--;
//}
