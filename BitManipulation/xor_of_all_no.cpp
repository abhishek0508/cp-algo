// xor of all number from 0 to N
100, 1000, 10000, 100000
int fun(int n){
    if(n%4==0){
        return n;
    }
    else if(n%2==0){
        return n+1;
    }
    else if(n%4==3){
        return 0;
    }
    else{
        return n;
    }
}