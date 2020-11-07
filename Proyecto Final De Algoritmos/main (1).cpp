#include <iostream>
#include <fstream>
#include <sstream>
#include "Traductor.cpp"
#include <windows.h>

using namespace std;

void agregarPalabras();
string ingresarCodigo();
string traducirCodigo(string);
int getNumeroLineas();

Traductor palabras[100];

int main(){
	
	agregarPalabras();
	string traduccion = traducirCodigo(ingresarCodigo());
	cout<<traduccion;
	
	return 0;
	
}


void agregarPalabras(){
	
	ifstream archivo_entrada("../listado.txt");;
    string linea, palabra, traduccion;
    int indice = 0, contador = 0, lineas = 0;

    while(getline(archivo_entrada, linea)) {
    	
    	lineas++;
    	
    	if(contador == 0){
    		palabra = linea;
		}else if(contador == 1){
			traduccion = linea;
		}else if(contador == 3){
			palabras[indice++] = Traductor(palabra, traduccion);
			contador = -1;
		}else if(lineas == getNumeroLineas()){
			palabras[indice++] = Traductor(palabra, traduccion);
			break;
		}
		
		contador++;
        
    }

}

string ingresarCodigo(){
	
	string codigo, linea;
	
	cout<<"Ingrese el texto"<<endl;
	cout<<"Escriba ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
	cout<<"fin";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<" y presione ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
	cout<<"ENTER";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout<<" para traducir"<<endl<<endl;
	
	while(true){
		getline(cin, linea);
		
        if(linea != "fin") codigo += linea + " \n";
        else break;
	}
	
	return codigo;
	
}

string traducirCodigo(string codigo){
	
	string str(codigo);
    istringstream isstream(str);
    string llaveInicio = "", llaveFin = "";

    while(!isstream.eof()){
        string tempStr;
        isstream >> tempStr;
        
        if(tempStr != "{" && tempStr != "}"){
	
			for(int i = 0; i<100; i++){
				
				if(tempStr == palabras[i].getPalabra()){
					
					if(tempStr == "if"){
						llaveInicio = "inicio si";
						llaveFin = "fin si";
					}else if(tempStr == "else"){
						llaveInicio = "inicio entonces";
						llaveFin = "fin entonces";
					}else if(tempStr == "while"){
						llaveInicio = "inicio mientras";
						llaveFin = "fin mientras";
					}else if(tempStr == "for"){
						llaveInicio = "inicio para";
						llaveFin = "fin para";
					}  
						
					string::size_type pos = codigo.find(tempStr, 0);
	                if (pos < string::npos) codigo.replace(pos, string(tempStr).length(), palabras[i].getTraduccion());	
						
			    }
				
			}
			
		}else if(tempStr == "{" && llaveInicio != ""){
			
			string::size_type pos = codigo.find(tempStr, 0);
	        if (pos < string::npos) codigo.replace(pos, string(tempStr).length(), llaveInicio);
			llaveInicio = "";		
			
		}else if(tempStr == "}" && llaveFin != ""){
			
			string::size_type pos = codigo.find(tempStr, 0);
	        if (pos < string::npos) codigo.replace(pos, string(tempStr).length(), llaveFin);
			llaveFin = "";			
					
		}else if(tempStr == "{"){
			
			string::size_type pos = codigo.find(tempStr, 0);
	        if (pos < string::npos) codigo.replace(pos, string(tempStr).length(), "_");
			
		}
	
    }
    
    string::size_type pos = codigo.find("_", 0);
	if (pos < string::npos) codigo.replace(pos, string("=_").length(), "{");
    
    return codigo;
		
}

int getNumeroLineas(){
	
	int numero = 0;
	ifstream archivo_entrada("../listado.txt");
	string linea;
	
    while(getline(archivo_entrada, linea)) numero++;
    
	return numero;
	
}
