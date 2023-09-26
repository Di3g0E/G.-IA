bool isPalindrome(int x){
if (x < 0) {return false;}

else {

// Creamos las variables que vamos a usar en el while
  int num = x;
  long int reversed = 0;

  while (num > 0){

    int digit = num % 10;   // Sacamos el último dígito de num
    reversed = reversed * 10 + digit; // Añade los dígitos por la cola

    num /= 10;  // Elimina el último dígito de num para dar la vuelta al número x
  }

  return reversed == x;
}
}
