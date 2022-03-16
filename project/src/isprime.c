

int is_prime(int num) {
  for (int i=num-1; i >= 1; i--) {
if (num%i == 0)
return 1;
}
return 0;
}
