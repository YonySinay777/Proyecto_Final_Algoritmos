#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<string>
#include<windows.h>
#include<cstdlib>
#include<fstream>
#include<iomanip>

using namespace std; 

int opcion;

 main(){
	system("color 1f");
	do{
	
	cout << "\n\n \t\t\t\t\t\t\t\t\t\t *** BIENVENIDO *** \n\n" << endl;
		cout<<"_________________"<<endl;
		cout<<"Menu de programas \n";
		cout<<"_________________ \n \n"<<endl;
			cout<<"_________________ \n"<<endl;
		cout<<" 1. Diccionario \n ";
	
		cout<<"\n 2. Traductor \n";
		
		cout<<"\n 3. Salir \n";
	
		cout<<"\n Ingrese la opcion a ejecutar: "; cin>>opcion; 
	
	switch(opcion){
			case 1:
				
				system("diccionario.exe");
				system("cls");
				break;
				
				case 2:
		
				system("cls");
				system("main.exe");
				system("cls");
				}
			}while(opcion<=2);
		}
