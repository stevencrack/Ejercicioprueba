#include <iostream>

using namespace std;


double dydx(double x, double y, double z);
double dzdx(double x, double y, double z);
void rk4(double *x, double *y, double *z, double h);

double dydx(double x, double y, double z){
  return z;
}

double dzdx(double x, double y, double z){
  return -y;
}


void rk4(double *x, double *y, double *z, double h){

  double x_in, y_in, z_in;

  double ky_1, ky_2, ky_3, ky_4;

  double kz_1, kz_2, kz_3, kz_4;

  x_in = *x;
  y_in = *y;
  z_in = *z;

  ky_1 = dydx(x_in, y_in, z_in);
  kz_1 = dzdx(x_in, y_in, z_in);

  ky_2 = dydx(x_in + h/2, y_in + ky_1 * h/2, z_in + kz_1 * h/2);
  kz_2 = dzdx(x_in + h/2, y_in + ky_1 * h/2, z_in + kz_1 * h/2);

  ky_3 = dydx(x_in + h/2, y_in + ky_2 * h/2, z_in + kz_2 * h/2);
  kz_3 = dzdx(x_in + h/2, y_in + ky_2 * h/2, z_in + kz_2 * h/2);

  ky_4 = dydx(x_in + h, y_in + ky_3 * h, z_in + kz_3 * h);
  kz_4 = dzdx(x_in + h, y_in + ky_3 * h, z_in + kz_3 * h);

  x_in = x_in + h;
  y_in = y_in + h * (ky_1 + 2*ky_2 + 2*ky_3 + ky_4)/6.0;
  z_in = z_in + h * (kz_1 + 2*kz_2 + 2*kz_3 + kz_4)/6.0;

  *x = x_in;
  *y = y_in;
  *z = z_in;
}

int main(){
  double x, y, z, h;
  double delta_x, delta_y, delta_z;
  
  h = 0.1;
 
  z = 0.0;

  y = 1.0;

  x = 0.0;
  while(x<10.0){
    cout << x << " " << y << " " << z << endl;
    rk4(&x, &y, &z, h);
  }


  return 0;
}
