#include <iostream>

double k(double x, double y, double h);

double funcion(double x, double y);

int main(){

	double x = 0;  
	double y = 1;
	double h = 0.1;
	double N = 3/h;

  for(int i=0; i<N; i++){
    y = y + valor_k(x, y, h);
    x = x+h;

    std::cout << x << " " << y << std::endl;
  }
}

double funcion(double x, double y){
  return -y;
}

double k(double x, double y, double h){
  double k1 = funcion(x, y);
  double k2 = funcion(x + h/2, y+(h/2)*k1);
  double k3 = funcion(x + h/2, y+(h/2)*k2);
  double k4 = funcion(x + h, y+h*k3);

  return (h/6)*(k1+2*k2+2*k3+k4);
}
