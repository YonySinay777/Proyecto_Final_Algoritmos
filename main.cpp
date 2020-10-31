#include <iostream>
#include <fstream>
#include <sstream>
#include "Traductor.cpp"

using namespace std;

void agregarPalabras();
string ingresarCodigo();
string traducirCodigo(string);

Traductor palabras[100];

int main(){
	
	agregarPalabras();
	string traduccion = traducirCodigo(ingresarCodigo());
	cout<<"\n-----------------------TRADUCCIÓN-----------------------\n\n";
	cout<<traduccion;
	
	return 0;
	
}


void agregarPalabras(){
	
	ifstream archivo_entrada("listado.txt");;
    string linea, palabra1, palabra2;
    int contador = 0;
    bool bandera;

    while(getline(archivo_entrada, linea)) {

    	string str(linea);
        istringstream isstream(str);
        bandera = true;

    	while(!isstream.eof()){
        	string tempStr;
        	isstream >> tempStr;
        	
        	if(bandera) palabra1 = tempStr;
			else palabra2 = tempStr;
			
			if(!bandera) break;
			bandera = false;    	
    	}

    	palabras[contador] = Traductor(palabra1, palabra2);
    	contador++;
        
    }

}

string ingresarCodigo(){
	
	string codigo, linea;
	
	cout<<"Ingrese el código"<<endl;
	cout<<"Escriba \"fin\" y presione enter para traducir"<<endl<<endl;
	
	while(true){
		getline(cin, linea);
		
        if(linea != "fin") codigo += linea + "\n";
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
						llaveFin = "fin si\n";
					}else if(tempStr == "else"){
						llaveInicio = "inicio entonces";
						llaveFin = "fin entonces\n";
					}else if(tempStr == "while"){
						llaveInicio = "inicio mientras";
						llaveFin = "fin mientras\n";
					}else if(tempStr == "for"){
						llaveInicio = "inicio para";
						llaveFin = "fin para\n";
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
