using namespace std;

int fib(int num, int* calls ) {
    int result;
    if (num == 1)
        return 1;
    else if(num == 0)
        return 0;
    else {
        result = fib(num - 1, calls) + fib(num - 2, calls);
        *calls += 2;
    }
    
    return result;
}

int main()
{
    int N, num, result;
    cin >> N;

    while (N--) {
        int calls = 0;
        cin >> num;
        result = fib(num, &calls);
        printf("fib(%d) = %d calls = %d\n", num, calls, result);
    }
}
