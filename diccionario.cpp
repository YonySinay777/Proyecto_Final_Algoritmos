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

 
 void gotoxy(int x, int y){
 	HANDLE hcon;
 	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
 	COORD dwPos;
 	dwPos.X = x;
 	dwPos.Y = y;
 	SetConsoleCursorPosition(hcon,dwPos);
 	
 	
 }
 
int opcion;
struct traduccion{
	char palabra[50];
	char traduccion[50];
	char funcionalidad[50];
}datos;

void listado(ofstream &archivo){
	system("cls");
	int i;
	
	archivo.open("listado.txt", ios::out | ios::app);
	cout<<"Traduccion de palabras \n\n";
	cout<<"Palabra en espa�ol: ";gets(datos.palabra);gets(datos.palabra);
	cout<<"\n Traduccion: ";gets(datos.traduccion);
	cout<<"\n Funcionalidad: ";gets(datos.funcionalidad);
	
	archivo<<"\n Palabra: "<<datos.palabra<<"\n Traduccion: "<<datos.traduccion <<"\n Funcionalidad: "<<datos.funcionalidad<<"\n ---------------------- \n";

	
	archivo.close();
}

void consulta(ifstream &archivoconsulta){
	system("cls");
	int fila=0, columna=0;
	int control=1;
	archivoconsulta.open("listado.txt", ios::out | ios::app);
	
		string mostrar, line;
		
		while (getline(archivoconsulta, line))
		{
			mostrar =line;
			gotoxy (columna,fila); cout <<mostrar;
			fila++;
		}
		archivoconsulta.close();
		getch(); 
}
main(){
	
	ofstream archivover_palabras;
	ifstream archivoconsulta;
	do{
		system("cls");
		cout << "*** BIENVENIDO *** \n\n" << endl;
		cout<<"_________________"<<endl;
		cout<<"Menu de opciones \n\n";
		cout<<"_________________ \n \n"<<endl;
		cout<<"\n 1. Ingresar palabras \n ";
		cout<<"----------------------"<<endl;
		cout<<"\n 2. Ver palabras \n";
		cout<<"----------------------"<<endl;
		cout<<"\n 3. Eliminar \n";
		cout<<"----------------------"<<endl;
		cout<<"\n 4. Salir \n";
		cout<<"------------------"<<endl;
		cout<<"\n Ingrese la opcion a ejecutar: "; cin>>opcion; 
		
		
	
		
		switch(opcion){
			case 1:
				listado(archivover_palabras);
				break;
				
				case 2:
				consulta(archivoconsulta);
		
					break;	
					
				case 3:	
				remove("listado.txt");
				break;			
		}
	}while(opcion<=3);

}
