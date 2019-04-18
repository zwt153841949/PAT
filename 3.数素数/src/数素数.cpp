//============================================================================
// Name        : 数素数.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
const int maxn = 1000001;
using namespace std;

bool isPrime(int n){

	for(int i = 2;i * i <= n;i++){
		if(n % i == 0) return false;
	}
	return true;
}
int main() {
	int p[maxn] = {0};
	int j = 0;
	int n = 3000000;
	int M,N;
	int add = 0;
	scanf("%d %d",&M,&N);
	if(M <= N){
		for(int i = 2;i < n;i++){
				if(isPrime(i) == true)
					p[j++] = i;
					if(j == N ){
						for(int k = M - 1;k<= N - 1 ;k++){

							if(add <= 8 ){
								if( k == N - 1)
									printf("%d",p[k]);
								else
									printf("%d ",p[k]);
							}
							if(add == 9 ){
								printf("%d",p[k]);
								printf("\n");
								add = 0;
							}
							else{
								++add;
							}


						}
						break;
					}
			}
	}
	return 0;
}
