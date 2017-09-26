 #include <stdio.h>

 int function(int a, int b, int c) {

     char buffer[14];
     int sum;
     int *ret;
 
     ret = buffer + 20;
     ret += 10;
     sum = a + b + c;
     return sum;
  }
 
  void main() {
      int x;
 
      x = 0;
      function(1,2,3);
      x = 1;
      printf("%d\n",x);
  }
