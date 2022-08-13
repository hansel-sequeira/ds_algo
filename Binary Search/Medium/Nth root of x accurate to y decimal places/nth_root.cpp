//given integers n, x and y, find the nth root of x accurate to y decimal places.
//y here is 5 

double multiply(double x, int n){
	double res = 1.0;
	for(int i=0;i<n;i++) res*=x;
	return res;
}

//accurate to 5 decimal places
double root(int n, int x){
  if(x == 1 || n == 1) return n;
  double low = 1, high = x, diff = 1e-6; //remember that e = 10 to the power of
  while(abs(low-high)>diff){
  	double mid = (low+high)/2.0;
  	double res = multiply(mid, n);
  	if(res > x) high = mid;
  	else low = mid;
  }
  return low;
}
