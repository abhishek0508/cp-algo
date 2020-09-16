// reset last bit or lsb
int fun(int n){
    int x = n&(n-1);
    return x;
}