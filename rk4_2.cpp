#include <iostream>

double k(double x, double y, double h);
double k_2(double z, double h);
double funcion1(double x, double y);
double funcion2(double z);

int main(){
 
	double x = 0;

	double y = 1;

	double z = 0;

	double h = 0.1;

	double N = 10/h;

  for(int i=0; i<N; i++){
    z = z + k(x, y, h);
    y = y + k_2(z, h);
    x = x+h;

    std::cout << x << " " << y << std::endl;
  }
}

double funcion1(double x, double y){
  return -y;
}

double funcion2(double z){
  return z;
}
double k(double x, double y, double h){
	double k1 = funcion1(x, y);
	double k2 = funcion1(x + h/2, y+(h/2)*k1);
	double k3 = funcion1(x + h/2, y+(h/2)*k2);
	double k4 = funcion1(x + h, y+h*k3);

  return (h/6)*(k1+2*k2+2*k3+k4);
}


double k_2(double z,  double h){
  double k1 = f2(z);
  double k2 = f2(z+(h/2)*k1);
  double k3 = f2(z+(h/2)*k2);
  double k4 = f2(z+h*k3);

  return (h/6)*(k1+2*k2+2*k3+k4);
