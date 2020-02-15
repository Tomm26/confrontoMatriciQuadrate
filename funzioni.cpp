#include <iostream>
#include <string>
#include <fstream>
#include "funzioni.h"

int leggiDim(std::string nomefile) {
//funzione che legge le dimensioni di righe e colonne della matrice
	std::fstream file;
	int n;
	file.open(nomefile,std::fstream::in);
	if (!file) {
		std::cout << "Errore durante l'apertura del file"<<nomefile; exit(1);
	}
	else {
		file >> n;
	}
	file.close();
	return n;
}
void caricaMatrice(std::string nomefile, int **m) {
//funzione che carica la matrice
	int n;
	std::fstream file;
	file.open(nomefile, std::fstream::in);
	file >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			file >> m[i][j];
		}
	}
	file.close();
}

void controllaRighe(int **m1, int**m2, int n ) {
//funzione che controlla le righe, stampandone quelle uguali
	int sum = 0;
	for (int i = 0; i < n; i++) {
		//scorre le righe della prima matrice
		for (int k = 0; k < n; k++) {
			//scorre le righe della seconda matrice
			for (int j = 0; j < n; j++) {
				//scorre la colonna, confrontando le diverse celle
				if (m1[i][j] == m2[k][j]) {
					sum++;
				}
			}
			//se il numero di celle uguali è uguale ad n, ho trovato righe uguali
			if (sum == n) {
				std::cout << "La riga " << i << " e' uguale alla riga " << k<<std::endl;
			}
			sum = 0;
			
		}
	}
}
void controllaColonne(int **m1, int**m2, int n) {
//funzione che controlla le colonna, stampandone quelle uguali
	int sum = 0;
	for (int i = 0; i < n; i++) {
		//scorre le colonne della prima matrice
		for (int k = 0; k < n; k++) {
			//scorre le colonne della seconda matrice
			for (int j = 0; j < n; j++) {
				//scorre la riga, confrontando le diverse celle
				if (m1[j][i] == m2[j][k]) {
					sum++;
				}
			}
			//se il numero di celle uguali è uguale ad n, ho trovato righe uguali
			if (sum == n) {
				std::cout << "La colonna " << i << " e' uguale alla colonna " << k << std::endl;
			}
			sum = 0;

		}
	}
}
