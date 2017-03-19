#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream entrada;

struct e{
	int a, b;
};

vector<vector<int> >alturas;
vector<vector<int> >conexiones;
vector <e> maximos;
vector <e> caminoMaximo;

void mirar(int, int, int);
void buscarCamino(int, int);

void mostrarMaximo(){
	vector <e>::iterator it9;
	it9=maximos.begin();
	cout<<maximos.size();
	for(int x=0; x<maximos.size(); x++){
	cout<<(*it9).a<<" "<<(*it9).b<<endl;
	it9++;}
}

void mostrar(){
	for (int x=0; x<conexiones.size(); x++){
		for (int y=0; y<conexiones[x].size(); y++)
			cout<<conexiones[x][y]<<" ";
		cout<<endl; 
	}
}

void comparar(){
      if(caminoMaximo.size()<maximos.size()){
      	caminoMaximo.clear();
      	caminoMaximo.resize(1);
		  caminoMaximo=maximos;
      	maximos.clear();
      	maximos.resize(1);
	  }
}

bool buscarIzq(int x, int y){
	bool r=false;
		if(y-1>=0 && (conexiones[x][y-1]+1)==conexiones[x][y]){
	    	e e1;
			e1.a=x;
			e1.b=y-1;
            r=true;
			maximos.push_back(e1);	
			buscarCamino(x,y-1);}		
return r;
}

bool buscarDer(int x, int y){
	bool r=false;
		if(y+1<alturas.size() && (conexiones[x][y+1]+1)==conexiones[x][y]){
	    	e e1;
			e1.a=x;
			e1.b=y+1;
            maximos.push_back(e1);
			r=true;	
			buscarCamino(x,y+1);		}
return r;
}

bool buscarArriba(int x, int y){
		bool r=false;
		if(x-1>=0 && (conexiones[x-1][y]+1)==conexiones[x][y]){
	    	e e1;
			e1.a=x-1;
			e1.b=y;
            maximos.push_back(e1);	
            r=true;
			buscarCamino(x-1,y);}		
return r;
}

bool buscarAbajo(int x, int y){
	bool r=false;
		if(x+1<alturas.size() && (conexiones[x+1][y]+1)==conexiones[x][y]){
			e e1;
			e1.a=x+1;
			e1.b=y;
            maximos.push_back(e1);
			r=true;		
			buscarCamino(x+1,y);}
			return r;		
}


void buscarCamino(int x, int y){
	bool r=false;
	while(r==false && conexiones[x][y]>0){
		r=buscarAbajo(x,y);
		if(r==false)
		r=buscarArriba(x,y);
		if(r==false)
		r=buscarIzq(x,y);
		if(r==false)
		r=buscarDer(x,y);
	}
}


void encontrarMaximo(){
int max=0,a,b;
for (int x=0; x<alturas.size(); x++){
	for(int y=0; y<alturas.size(); y++){
	 if(conexiones[x][y]>max){
	   max=conexiones[x][y];
	    a=x;
	    b=y;
     }
	}
}
maximos.resize(0);
 buscarCamino(a,b);
}

void moverIzquierda(int x, int y,  int c){
	if(y-1>=0 && alturas[x][y-1]<alturas[x][y] && conexiones[x][y-1]<c){
	conexiones[x][y-1]=c;
	mirar(x, y-1,c);
      }
}

void moverDerecha(int x, int y,  int c){
	if(y+1<alturas.size() && alturas[x][y+1]<alturas[x][y] && conexiones[x][y+1]<c){
	conexiones[x][y+1]=c;
	mirar(x, y+1,c);
      }
}

void moverArriba(int x, int y,  int c){
	if(x-1>=0 && alturas[x-1][y]<alturas[x][y] && conexiones[x-1][y]<c){
	conexiones[x-1][y]=c;
	mirar(x-1, y,c);
      }
}

void moverAbajo(int x, int y,  int c){
	if(x+1<alturas.size() && alturas[x+1][y]<alturas[x][y] && conexiones[x+1][y]<c){
    conexiones[x+1][y]=c;
    mirar(x+1, y,c);
      }
}


void mirar(int x, int y, int c){
	c=c+1;
	bool r=false;
	while(r==false && x<alturas.size() && y<alturas.size() && x>=0 && y>=0){
			moverAbajo(x,y,c);
			moverArriba(x,y,c);
			moverIzquierda(x,y, c);
			moverDerecha(x,y, c);	
	        r=true;
	      }
}

void camino(){
	int c=0;
	  for(int x=0; x<alturas.size(); x++){
	  	for(int y=0; y<alturas[x].size(); y++){
	  		mirar(x,y,c);
		   encontrarMaximo();
		   comparar();}}
	  
}

void recorrer(int m){
	int c=1,d=0;
    conexiones.resize(m);
    for(int x=0; x<conexiones.size(); x++)
       conexiones[x].resize(m);
}

void cargar_datos(int& m){
	int c;
	entrada.open("karting.in");
	entrada>>m;
	alturas.resize(m);
	for (int a=0; a<m; a++)
	 alturas[a].resize(m);
	int cont=0;
	e e3;
	for (int a=0; a<m; a++){
		for (int b=0; b<m; b++){
			entrada>>c;
			alturas[a][b]=c;
		}
	}
}

int main(){
	int m;
	cargar_datos(m);
	recorrer(m);
	caminoMaximo.resize(1);
	 camino();
	 mostrarMaximo();
	 
}
