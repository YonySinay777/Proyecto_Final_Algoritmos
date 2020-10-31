using namespace std;

class Traductor{
	
	private:
		string palabra;
		string traduccion;
		
	public:
		Traductor();
		Traductor(string, string);
		string getPalabra();
		string getTraduccion();
	
};

Traductor::Traductor(){
}

Traductor::Traductor(string _palabra, string _traduccion){
	palabra = _palabra;
	traduccion = _traduccion;
}

string Traductor::getPalabra(){
	return palabra;
}

string Traductor::getTraduccion(){
	return traduccion;
}
