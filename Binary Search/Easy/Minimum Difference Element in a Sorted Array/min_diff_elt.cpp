/*
sorted array: 1 3 6 8 10 15
x: 12. The min absolute difference possible is 2 (with 10). Print that element (10).
*/

intuition: simply find the floor and ceil of that element. Floor of 12 here is 10. Ceil is 15. Then compare with the absolute differences!.
  Floor and ceil of 8 is 8 only.
  
  pseudocode:

  int sol1 = abs(floor(x) - x);
  int sol2 = abs(ceil(x) - x);
  return sol1 > sol2 ? floor(x) : ceil(x);
