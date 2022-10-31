int main(){
    int x;
    scanf("%d", &x);

    int i;
    int isprime = 1;
    for (i = 2; i < x; i++){
        if(x % i == 0){
            isprime = 0;
            break;
        }
    }
    return 0;
}