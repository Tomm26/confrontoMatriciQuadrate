#pragma once
#include <string>

int leggiDim(std::string nomefile);
void caricaMatrice(std::string nomefile, int **m);
void controllaRighe(int **m1, int**m2, int n);
void controllaColonne(int **m1, int**m2, int n);
