#ifndef DECRESCENTE_H
#define DECRESCENTE_H

#include "base.h"
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;


void DECRESCENTE(int alg, int taminst, FILE* entrada, FILE* saida) {
	srand(time(NULL));

	double tempexec; //tempo de execucao

	time_t Comeco, Fim; // medir tempo de execucao

	int n = 0, seed, * vet; //tamanho do array, semente e array

	seed = (rand() % 1000000) * 100; //gerar numero aleatorio

	char arq1[200], arq2[200], arq3[200]; //strings com o caminho dos arquivos


	char command[400];

	switch (alg) { //Coloca a string com o caminho na variavel
        case 1:
			//MERGE SORT
			sprintf(command, "mkdir .\\MergeSort\\ArquivosEntrada\\Decrescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\MergeSort\\ArquivosSaida\\Decrescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\MergeSort\\ArquivosTempo\\Decrescente"); //Cria a pasta
			system(command);

			cout << "Merge" << endl << endl;
			strcpy(arq1, ".//MergeSort//ArquivosEntrada//Decrescente//");
			strcpy(arq2, ".//MergeSort//ArquivosSaida//Decrescente//");
			strcpy(arq3, ".//MergeSort//ArquivosTempo//Decrescente//");
			cout << endl << endl;
			break;

        case 2:
			//QUICK SORT - VERSAO 1

			sprintf(command, "mkdir .\\QuickSort_v1\\ArquivosEntrada\\Decrescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\QuickSort_v1\\ArquivosSaida\\Decrescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\QuickSort_v1\\ArquivosTempo\\Decrescente"); //Cria a pasta
			system(command);

			cout << "Quick_v1" << endl << endl;
			strcpy(arq1, ".//QuickSort_v1//ArquivosEntrada//Decrescente//");
			strcpy(arq2, ".//QuickSort_v1//ArquivosSaida//Decrescente//");
			strcpy(arq3, ".//QuickSort_v1//ArquivosTempo//Decrescente//");
			cout << endl << endl;
			break;

        case 3:
			//QUICK SORT - VERSAO 2

			sprintf(command, "mkdir .\\QuickSort_v2\\ArquivosEntrada\\Decrescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\QuickSort_v2\\ArquivosSaida\\Decrescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\QuickSort_v2\\ArquivosTempo\\Decrescente"); //Cria a pasta
			system(command);

			cout << "Quick_v2" << endl << endl;
			strcpy(arq1, ".//QuickSort_v2//ArquivosEntrada//Decrescente//");
			strcpy(arq2, ".//QuickSort_v2//ArquivosSaida//Decrescente//");
			strcpy(arq3, ".//QuickSort_v2//ArquivosTempo//Decrescente//");
			cout << endl << endl;
			break;
        
        case 4:
			//QUICK SORT - VERSAO 3

			sprintf(command, "mkdir .\\QuickSort_v3\\ArquivosEntrada\\Decrescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\QuickSort_v3\\ArquivosSaida\\Decrescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\QuickSort_v3\\ArquivosTempo\\Decrescente"); //Cria a pasta
			system(command);

			cout << "Quick_v3" << endl << endl;
			strcpy(arq1, ".//QuickSort_v3//ArquivosEntrada//Decrescente//");
			strcpy(arq2, ".//QuickSort_v3//ArquivosSaida//Decrescente//");
			strcpy(arq3, ".//QuickSort_v3//ArquivosTempo//Decrescente//");
			cout << endl << endl;
			break;
    }

    switch (taminst){
		case 1:
			cout << "INSTANCIA TAMANHO 10" << endl;
			n = 10; //define tamanho


			vet = new int[n]; //aloca array
			cout << "SEMENTE GERADA:" << seed << endl;

			strcat(arq1, "10CRES.txt"); //arqentrada
			strcat(arq2, "10SAID.txt"); //arqsaida
			strcat(arq3, "10TEMPO.txt"); //arqtemp

			entrada = fopen(arq1, "w"); //abre arquivo, escreve o que está em arq1

			fprintf(entrada, "10\n"); //escreve a primeira linha do arquivo como 10;

			for (int i = 0; i < n; i++) { //escreve os numeros em ordem deDecrescente no arquivo
				vet[i] = seed;
				fprintf(entrada, "%d\n", vet[i]);
				seed--;
			}

			fclose(entrada); //fecha os arquivos

			cout << endl;

			if (alg == 1) {
				Comeco = clock(); //marca o tempo de inicio
				MergeSort(vet, 0, n-1); //roda o algoritmo e ordena
				Fim = clock(); //marca o tempo do fim
			}
			if (alg == 2) {
				Comeco = clock(); // Marca o tempo de início
				QuickSort_v1(vet, 0, n - 1); // Roda o algoritmo e ordena
				Fim = clock(); // Marca o tempo do fim
			}
			if (alg == 3) {
				Comeco = clock(); //marca o tempo de inicio
				QuickSort_v2(vet, 0, n - 1); //roda o algoritmo e ordena
				Fim = clock(); //marca o tempo do fim
			}
			if (alg == 4) {
				Comeco = clock(); //marca o tempo de inicio
				QuickSort_v3(vet, n); //roda o algoritmo e ordena
				Fim = clock(); //marca o tempo do fim
			}


			cout << "ORDENACAO FEITA" << endl;
			saida = fopen(arq2, "w");

			fprintf(saida, "10\n"); //escreve a primeira linha do arquivo como 10;

			for (int m = 0; m < n; m++) {
				fprintf(saida, "%d\n", vet[m]);
			}

			fclose(saida);

			tempexec = ((Fim - Comeco) / (double)CLOCKS_PER_SEC); //calcula o tempo

			entrada = fopen(arq3, "w");
			fprintf(entrada, "O TEMPO DE EXECUCAO FOI: %.50f", tempexec); //grava o tempo no arquivo
			
			fclose(entrada);

			delete[] vet;
			break;
		

		case 2:
			cout << "INSTANCIA TAMANHO 100" << endl;
			n = 100; //define tamanho


			vet = new int[n]; //aloca array
			cout << "SEMENTE GERADA:" << seed << endl;

			strcat(arq1, "100CRES.txt"); //arqentrada
			strcat(arq2, "100SAID.txt"); //arqsaida
			strcat(arq3, "100TEMPO.txt"); //arqtemp

			entrada = fopen(arq1, "w"); //abre arquivo, escreve o que está em arq1

			fprintf(entrada, "100\n"); //escreve a primeira linha do arquivo como 10;

			for (int i = 0; i < n; i++) { //escreve os numeros em ordem Decrescente no arquivo
				vet[i] = seed;
				fprintf(entrada, "%d\n", vet[i]);
				seed--;
			}

			fclose(entrada); //fecha os arquivos

			cout << endl;

            if (alg == 1) {
                Comeco = clock(); //marca o tempo de inicio
                MergeSort(vet, 0, n-1); //roda o algoritmo e ordena
                Fim = clock(); //marca o tempo do fim
		    }
            if (alg == 2) {
                Comeco = clock(); // Marca o tempo de início
                QuickSort_v1(vet, 0, n - 1); // Roda o algoritmo e ordena
                Fim = clock(); // Marca o tempo do fim
            }
            if (alg == 3) {
				Comeco = clock(); //marca o tempo de inicio
				QuickSort_v2(vet, 0, n - 1);//roda o algoritmo e ordena
				Fim = clock(); //marca o tempo do fim
		    }
            if (alg == 4) {
				Comeco = clock(); //marca o tempo de inicio
				QuickSort_v3(vet, n); //roda o algoritmo e ordena
				Fim = clock(); //marca o tempo do fim
		    }

			cout << "ORDENACAO FEITA" << endl;
			saida = fopen(arq2, "w");

			fprintf(saida, "100\n"); //escreve a primeira linha do arquivo como 10;

			for (int m = 0; m < n; m++) {
				fprintf(saida, "%d\n", vet[m]);
			}

			fclose(saida);

			tempexec = ((Fim - Comeco) / (double)CLOCKS_PER_SEC); //calcula o tempo

			entrada = fopen(arq3, "w");
			fprintf(entrada, "O TEMPO DE EXECUCAO FOI: %.50f", tempexec); //grava o tempo no arquivo
			
			fclose(entrada);

			delete[] vet;
			break;

		case 3:
			cout << "INSTANCIA TAMANHO 1000" << endl;
			n = 1000; //define tamanho


			vet = new int[n]; //aloca array
			cout << "SEMENTE GERADA:" << seed << endl;

			strcat(arq1, "1000CRES.txt"); //arqentrada
			strcat(arq2, "1000SAID.txt"); //arqsaida
			strcat(arq3, "1000TEMPO.txt"); //arqtemp

			entrada = fopen(arq1, "w"); //abre arquivo, escreve o que está em arq1

			fprintf(entrada, "1000\n"); //escreve a primeira linha do arquivo como 10;

			for (int i = 0; i < n; i++) { //escreve os numeros em ordem Decrescente no arquivo
				vet[i] = seed;
				fprintf(entrada, "%d\n", vet[i]);
				seed--;
			}

			fclose(entrada); //fecha os arquivos

			cout << endl;

            if (alg == 1) {
                Comeco = clock(); //marca o tempo de inicio
                MergeSort(vet, 0, n-1); //roda o algoritmo e ordena
                Fim = clock(); //marca o tempo do fim
		    }
            if (alg == 2) {
                Comeco = clock(); // Marca o tempo de início
                QuickSort_v1(vet, 0, n - 1); // Roda o algoritmo e ordena
                Fim = clock(); // Marca o tempo do fim
        }
            if (alg == 3) {
				Comeco = clock(); //marca o tempo de inicio
				QuickSort_v2(vet, 0, n - 1); //roda o algoritmo e ordena
				Fim = clock(); //marca o tempo do fim
		    }
            if (alg == 4) {
				Comeco = clock(); //marca o tempo de inicio
				QuickSort_v3(vet, n); //roda o algoritmo e ordena
				Fim = clock(); //marca o tempo do fim
		    }

			cout << "ORDENACAO FEITA" << endl;
			saida = fopen(arq2, "w");

			fprintf(saida, "1000\n"); //escreve a primeira linha do arquivo como 10;

			for (int m = 0; m < n; m++) {
				fprintf(saida, "%d\n", vet[m]);
			}

			fclose(saida);

			tempexec = ((Fim - Comeco) / (double)CLOCKS_PER_SEC); //calcula o tempo

			entrada = fopen(arq3, "w");
			fprintf(entrada, "O TEMPO DE EXECUCAO FOI: %.50f", tempexec); //grava o tempo no arquivo
			
			fclose(entrada);

			delete[] vet;
			break;

		case 4:
			cout << "INSTANCIA TAMANHO 10000" << endl;
			n = 10000; //define tamanho


			vet = new int[n]; //aloca array
			cout << "SEMENTE GERADA:" << seed << endl;

			strcat(arq1, "10000CRES.txt"); //arqentrada
			strcat(arq2, "10000SAID.txt"); //arqsaida
			strcat(arq3, "10000TEMPO.txt"); //arqtemp

			entrada = fopen(arq1, "w"); //abre arquivo, escreve o que está em arq1

			fprintf(entrada, "10000\n"); //escreve a primeira linha do arquivo como 10;

			for (int i = 0; i < n; i++) { //escreve os numeros em ordem Decrescente no arquivo
				vet[i] = seed;
				fprintf(entrada, "%d\n", vet[i]);
				seed--;
			}

			fclose(entrada); //fecha os arquivos

			cout << endl;

            if (alg == 1) {
                Comeco = clock(); //marca o tempo de inicio
                MergeSort(vet, 0, n-1); //roda o algoritmo e ordena
                Fim = clock(); //marca o tempo do fim
                }
             if (alg == 2) {
                Comeco = clock(); // Marca o tempo de início
                QuickSort_v1(vet, 0, n - 1); // Roda o algoritmo e ordena
                Fim = clock(); // Marca o tempo do fim
            }
            if (alg == 3) {
				Comeco = clock(); //marca o tempo de inicio
				QuickSort_v2(vet, 0, n - 1); //roda o algoritmo e ordena
				Fim = clock(); //marca o tempo do fim
		    }
            if (alg == 4) {
				Comeco = clock(); //marca o tempo de inicio
				QuickSort_v3(vet, n); //roda o algoritmo e ordena
				Fim = clock(); //marca o tempo do fim
		    }

			cout << "ORDENACAO FEITA" << endl;
			saida = fopen(arq2, "w");

			fprintf(saida, "10000"); //escreve a primeira linha do arquivo como 10;

			for (int m = 0; m < n; m++) {
				fprintf(saida, "%d\n", vet[m]);
			}

			fclose(saida);

			tempexec = ((Fim - Comeco) / (double)CLOCKS_PER_SEC); //calcula o tempo

			entrada = fopen(arq3, "w");
			fprintf(entrada, "O TEMPO DE EXECUCAO FOI: %.50f", tempexec); //grava o tempo no arquivo
			
			fclose(entrada);

			delete[] vet;
			break;

		case 5:
			cout << "INSTANCIA TAMANHO 100.000" << endl;
			n = 100000; //define tamanho


			vet = new int[n]; //aloca array
			cout << "SEMENTE GERADA:" << seed << endl;

			strcat(arq1, "100000DECR.txt"); //arqentrada
			strcat(arq2, "100000SAID.txt"); //arqsaida
			strcat(arq3, "100000TEMPO.txt"); //arqtemp

			entrada = fopen(arq1, "w"); //abre arquivo, escreve o que está em arq1

			fprintf(entrada, "100000\n"); //escreve a primeira linha do arquivo como 1000000;

			for (int i = 0; i < n; i++) { //escreve os numeros em ordem Decrescente no arquivo
				vet[i] = seed;
				fprintf(entrada, "%d\n", vet[i]);
				seed--;
			}

			fclose(entrada); //fecha os arquivos

			cout << endl;

            if (alg == 1) {
                Comeco = clock(); //marca o tempo de inicio
                MergeSort(vet, 0, n-1); //roda o algoritmo e ordena
                Fim = clock(); //marca o tempo do fim
		    }
            if (alg == 2) {
                Comeco = clock(); 
                QuickSort_v1(vet, 0, n - 1); // Roda o algoritmo e ordena
                Fim = clock(); // Marca o tempo do fim
            }
            if (alg == 3) {
				Comeco = clock(); //marca o tempo de inicio
				QuickSort_v2(vet, 0, n - 1); //roda o algoritmo e ordena
				Fim = clock(); //marca o tempo do fim
		    }
            if (alg == 4) {
				Comeco = clock(); //marca o tempo de inicio
				QuickSort_v3(vet, n); //roda o algoritmo e ordena
				Fim = clock(); //marca o tempo do fim
		    }

			cout << "ORDENACAO FEITA" << endl;
			saida = fopen(arq2, "w");

			fprintf(saida, "100000\n"); //escreve a primeira linha do arquivo como 1000000;

			for (int m = 0; m < n; m++) {
				fprintf(saida, "%d\n", vet[m]);
			}

			fclose(saida);

			tempexec = ((Fim - Comeco) / (double)CLOCKS_PER_SEC); //calcula o tempo

			entrada = fopen(arq3, "w");
			fprintf(entrada, "O TEMPO DE EXECUCAO FOI: %.50f", tempexec); //grava o tempo no arquivo

			fclose(entrada);

			delete[] vet;
			break;

		case 6:
			cout << "INSTANCIA TAMANHO 1.000.000" << endl;
			n = 1000000; //define tamanho


			vet = new int[n]; //aloca array
			cout << "SEMENTE GERADA:" << seed << endl;

			strcat(arq1, "1000000DECR.txt"); //arqentrada
			strcat(arq2, "1000000SAID.txt"); //arqsaida
			strcat(arq3, "1000000TEMPO.txt"); //arqtemp

			entrada = fopen(arq1, "w"); //abre arquivo, escreve o que está em arq1

			fprintf(entrada, "1000000\n"); //escreve a primeira linha do arquivo como 1000000;

			for (int i = 0; i < n; i++) { //escreve os numeros em ordem Decrescente no arquivo
				vet[i] = seed;
				fprintf(entrada, "%d\n", vet[i]);
				seed--;
			}

			fclose(entrada); //fecha os arquivos

			cout << endl;

            if (alg == 1) {
                Comeco = clock(); //marca o tempo de inicio
                MergeSort(vet, 0, n-1); //roda o algoritmo e ordena
                Fim = clock(); //marca o tempo do fim
		    }
            if (alg == 2) {
                Comeco = clock(); 
                QuickSort_v1(vet, 0, n - 1); // Roda o algoritmo e ordena
                Fim = clock(); // Marca o tempo do fim
            }
            if (alg == 3) {
				Comeco = clock(); //marca o tempo de inicio
				QuickSort_v2(vet, 0, n - 1); //roda o algoritmo e ordena
				Fim = clock(); //marca o tempo do fim
		    }
            if (alg == 4) {
				Comeco = clock(); //marca o tempo de inicio
				QuickSort_v3(vet, n); //roda o algoritmo e ordena
				Fim = clock(); //marca o tempo do fim
		    }

			cout << "ORDENACAO FEITA" << endl;
			saida = fopen(arq2, "w");

			fprintf(saida, "1000000\n"); //escreve a primeira linha do arquivo como 1000000;

			for (int m = 0; m < n; m++) {
				fprintf(saida, "%d\n", vet[m]);
			}

			fclose(saida);

			tempexec = ((Fim - Comeco) / (double)CLOCKS_PER_SEC); //calcula o tempo

			entrada = fopen(arq3, "w");
			fprintf(entrada, "O TEMPO DE EXECUCAO FOI: %.50f", tempexec); //grava o tempo no arquivo

			fclose(entrada);

			delete[] vet;
			break;

		default:
			cout << "ERRO, OPCAO INVALIDA" << endl << endl;
			break;
		}
    
}
#endif //!DEDecrescente_H