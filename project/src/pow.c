
int custom_pow(int base,int power) {
    int x=1;
    for (int i=1;i < power;i++){
x*=base;
    }
    return x;
}
