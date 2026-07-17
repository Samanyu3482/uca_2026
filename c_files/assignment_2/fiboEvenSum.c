#include<stdio.h>

int fibo ( int n );

int main () {
	int n;
	printf("Enter the value of n : ");
	scanf("%d", &n);
	int result =  fibo(n);
	printf("%d\n", result);
	return 0;
}

/*int fibo( int n ){
	if ( n == 0 || n == 1 ) return 0;
	int sum = 0;
	int dp [ n + 1 ];
	dp [0] = 0;
	dp [1] = 1;
	for ( int i = 2; i <= n; i++ ){
		dp[i] = dp[i - 1] + dp[i - 2];
		if ( dp[i] % 2 == 0 ){
			sum += dp [i];
		}
		if ( dp[i] > n ) break;
	}

	return sum;
}*/

int fibo ( int n ){
	if ( n == 0 || n == 1 ) return 0;
	int prev2 = 0;
	int prev1 = 1;
	int curr;
	int sum = 0;
	for ( int i = 2; i <= n; i++ ){
		curr = prev1 + prev2;
		if ( curr % 2 == 0 ){
			sum += curr;
		}
		prev2 = prev1;
		prev1 = curr;
		if ( curr > n ) break;
	}
	return sum;
}

	
