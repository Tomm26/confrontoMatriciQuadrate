#include "funzioni.h"
#include <iostream>


using namespace std;

int main()
{
	string nomefile1,nomefile2;
	int **matrice1,**matrice2;
	int n;
	cout << "inserire nome file 1: ";
	cin >> nomefile1;
	cout << "inserire nome file 2: ";
	cin >> nomefile2;
	//ricavo le dimensioni della matrice dal file
	if (leggiDim(nomefile1)==leggiDim(nomefile2)) {
		n=leggiDim(nomefile1);
	}

	//alloco dinamicamente la matrice1 e matrice 2
	matrice1 = new int*[n];
	for (int i = 0; i < n; i++) {
		matrice1[i] = new int[n];
	}
	matrice2 = new int*[n];
	for (int i = 0; i < n; i++) {
		matrice2[i] = new int[n];
	}

	//carico le due matrici
	caricaMatrice(nomefile1, matrice1);
	caricaMatrice(nomefile2, matrice2);

	//controllo le righe e le colonne
	controllaRighe(matrice1, matrice2, n);
	controllaColonne(matrice1, matrice2, n);

	//dealloco la memoria allocata dalle matrici
	for (int i = 0; i < n; i++) {
		delete[] matrice1[i];
	}
	delete[] matrice1;
	for (int i = 0; i < n; i++) {
		delete[] matrice2[i];
	}
	delete[] matrice2;
}
