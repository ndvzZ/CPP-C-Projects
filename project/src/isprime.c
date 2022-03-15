int is_prime(int num){
for (int i=num-1;i>=sqrt(num);i--){
if (num%i==0) return 0;
else {return 1;}
break;
}
}