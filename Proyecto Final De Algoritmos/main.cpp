#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void menu();
void crear();
void mostrar();
void actualizar();
void eliminar();
int getNumeroLineas();

int main(){
	
	setlocale(LC_ALL, "spanish");	
	menu();	
	return 0;
	
}

void menu(){
	
	int opcion = 0;
	
	do{
		
		cout<<"Menú"<<endl;
		cout<<"    1.Crear palabra"<<endl;
		cout<<"    2.Mostrar palabras"<<endl;
		cout<<"    3.Actualizar palabra"<<endl;
		cout<<"    4.Eliminar palabra"<<endl;
		cout<<"    5.Salir\n"<<endl;
		
		cout<<"Ingresar una opción: ";
		cin>>opcion;
		
		switch(opcion){
			
			case 1:
				cout<<"\n----------------------------------------------------\n"<<endl;
				crear();
				cout<<"\n----------------------------------------------------\n"<<endl;
				break;
				
			case 2:
				cout<<"\n----------------------------------------------------\n"<<endl;
				mostrar();
				cout<<"\n----------------------------------------------------\n"<<endl;
				break;
					
			case 3:
				cout<<"\n----------------------------------------------------\n"<<endl;
				actualizar();
				cout<<"\n----------------------------------------------------\n"<<endl;
				break;
						
			case 4:
				cout<<"\n----------------------------------------------------\n"<<endl;
				eliminar();
				cout<<"\n----------------------------------------------------\n"<<endl;
				break;
							
			case 5:
				cout<<"\n--------------------------------"<<endl;
				exit(-1);
				break;
								
			default:
				cout<<"¡La opción es incorrecta!"<<endl;
                cout<<"\n----------------------------------------------------\n"<<endl;
                
		}

		
	}while(true);
	
}

void crear(){
	
	FILE *fichero;
    fichero = fopen("../listado.txt", "a");
    char palabra[100], traduccion[100], funcionalidad[1000];
    
    fputs("\n\n", fichero);
    
	cin.ignore();
	
	cout<<"Ingrese Palabra: ";
	cin.getline(palabra, sizeof(palabra));
    strcat(palabra, "\n");
    fputs(palabra, fichero);
    
    cout<<"Ingrese Traducción: ";
	cin.getline(traduccion, sizeof(traduccion));
    strcat(traduccion, "\n");
    fputs(traduccion, fichero);
    
    cout<<"Ingrese Funcionalidad: ";
	cin.getline(funcionalidad, sizeof(funcionalidad));
    strcat(funcionalidad, "");
    fputs(funcionalidad, fichero);
    
    fclose(fichero);
    
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),160);
	cout<<"\nPalabra creada con éxito\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
}

void mostrar(){
	
	ifstream archivo_entrada("../listado.txt");
    string linea;
    int contador = 0;

    while(getline(archivo_entrada, linea)){
    	
    	if(contador == 0){
    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
    		cout<<"Palabra:";
    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
    		cout<<" ";
    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),224);
			cout<<linea + "\n"<<endl;
		}else if(contador == 1){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
			cout<<"Traducción:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<" " + linea + "\n"<<endl;
		}else if(contador == 2){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
			cout<<"Funcionalidad:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<" " + linea + "\n"<<endl;
		}else{
			cout<<endl;
			contador = -1;
		}

		contador++;
		
    }
	
}

void actualizar(){

	ifstream fs("../listado.txt");
	ofstream fstemp("../listadotemp.txt");
    string palabra, nuevaPalabra, nuevaTraduccion, nuevaFuncionalidad, linea;
    bool bandera = false;
    int contador = 0, lineas = 0;
    
    cin.ignore();
    
    cout<<"Nombre de la palabra que desea actualizar: ";
    getline(cin, palabra);

    while(getline(fs, linea)){
    	
    	lineas++;
    
		if(linea == palabra){
			
			cout<<"Ingresar nueva palabra: ";
    		getline(cin, nuevaPalabra);
    
    		cout<<"Ingresar nueva traduccioón: ";
    		getline(cin, nuevaTraduccion);
    
    		cout<<"Ingresar nueva funcionalidad: ";
    		getline(cin, nuevaFuncionalidad);
		  
      		fstemp<<nuevaPalabra<<endl;
      		fstemp<<nuevaTraduccion<<endl;
      		if(lineas < getNumeroLineas()-2) fstemp<<nuevaFuncionalidad<<endl;
      		else fstemp<<nuevaFuncionalidad;
      		contador = 3;
      		bandera = true;
    	}
    	
    	if(contador <= 0){
    		if(lineas < getNumeroLineas()) fstemp<<linea<<endl;
    		else fstemp<<linea;
		}else{
			contador--;	
		} 
		
  	}
  	
  	fs.close();
  	fstemp.close();
  	remove("../listado.txt");
  	rename("../listadotemp.txt", "../listado.txt");
	
	
	if(bandera){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),160);
		cout<<"\nPalabra actualizada con éxito\n";
	}else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),207);
		cout<<"\nLa palabra ingresada no existe\n";
	} 
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
}

void eliminar(){
	
	ifstream fs("../listado.txt");
	ofstream fstemp("../listadotemp.txt");
    string palabra, linea;
    bool bandera = false;
    int contador = 0, lineas = 0;
    
    cin.ignore();
    
    cout<<"Nombre de la palabra que desea eliminar: ";
    getline(cin, palabra);

    while(getline(fs, linea)){
    	
    	lineas++;
    	
    	if(!bandera && lineas == getNumeroLineas()-4){
    		fstemp<<linea;
    		bandera = true;
    		break;
		}
    
		if(linea == palabra){
      		contador = 4;
      		bandera = true;
    	}
    	
    	if(contador <= 0){
    		if(lineas < getNumeroLineas()) fstemp<<linea<<endl;
    		else fstemp<<linea;
		}else{
			contador--;	
		} 
		
  	}
  	
  	fs.close();
  	fstemp.close();
  	remove("../listado.txt");
  	rename("../listadotemp.txt", "../listado.txt");
	
	if(bandera){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),160);
		cout<<"\nPalabra eliminada con éxito\n";
	}else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),207);
		cout<<"\nLa palabra ingresada no existe\n";
	} 
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
}

int getNumeroLineas(){
	
	int numero = 0;
	ifstream archivo_entrada("../listado.txt");
	string linea;
	
    while(getline(archivo_entrada, linea)) numero++;
    
	return numero;
	
}
