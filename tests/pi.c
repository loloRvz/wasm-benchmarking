#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "time.h"
#include "errno.h"

//what this one does
int mul_mod(int a, int b, int m) {
    int res = 0;
    while (a != 0) {
        if (a & 1) res = (res + b) % m;
        a >>= 1;
        b = (b << 1) % m;
    }
    return res;
}

/* return the inverse of x mod y */
int inv_mod(int x, int y) {
    int q, u, v, a, c, t;

    u = x;
    v = y;
    c = 1;
    a = 0;
    do {
    q = v / u;

    t = c;
    c = a - q * c;
    a = t;

    t = u;
    u = v - q * u;
    v = t;
    } while (u != 0);
    a = a % y;
    if (a < 0)
    a = y + a;
    return a;
}

/* return (a^b) mod m */
int pow_mod(int a, int b, int m) {
    int r, aa;

    r = 1;
    aa = a;
    while (1) {
    if (b & 1)
        r = mul_mod(r, aa, m);
    b = b >> 1;
    if (b == 0)
        break;
    aa = mul_mod(aa, aa, m);
    }
    return r;
}

/* return true if n is prime */
int is_prime(int n) {
    int r, i;
    if ((n % 2) == 0)
    return 0;

    r = (int) (sqrt(n));
    for (i = 3; i <= r; i += 2)
    if ((n % i) == 0)
        return 0;
    return 1;
}

/* return the prime number immediatly after n */
int next_prime(int n) {
    do {
    n++;
    } while (!is_prime(n));
    return n;
}

int n_pi(int n) {
    int av, a, vmax, N, num, den, k, kq, kq2, t, v, s, i;
    double sum;

    if (n <= 0) {
    printf("This program computes the n'th decimal digit of \\pi\n"
           "usage: pi n , where n is the digit you want\n");
    exit(1);
    }

    N = (int) ((n + 20) * log(10) / log(2));

    sum = 0;

    for (a = 3; a <= (2 * N); a = next_prime(a)) {

    vmax = (int) (log(2 * N) / log(a));
    av = 1;
    for (i = 0; i < vmax; i++)
        av = av * a;

    s = 0;
    num = 1;
    den = 1;
    v = 0;
    kq = 1;
    kq2 = 1;

    for (k = 1; k <= N; k++) {

        t = k;
        if (kq >= a) {
        do {
            t = t / a;
            v--;
        } while ((t % a) == 0);
        kq = 0;
        }
        kq++;
        num = mul_mod(num, t, av);

        t = (2 * k - 1);
        if (kq2 >= a) {
        if (kq2 == a) {
            do {
            t = t / a;
            v++;
            } while ((t % a) == 0);
        }
        kq2 -= a;
        }
        den = mul_mod(den, t, av);
        kq2 += 2;

        if (v > 0) {
        t = inv_mod(den, av);
        t = mul_mod(t, num, av);
        t = mul_mod(t, k, av);
        for (i = v; i < vmax; i++)
            t = mul_mod(t, a, av);
        s += t;
        if (s >= av)
            s -= av;
        }

    }

    t = pow_mod(10, n - 1, av);
    s = mul_mod(s, t, av);
    sum = fmod(sum + (double) s / (double) av, 1.0);
    }
    //printf("Decimal digits of pi at position %d: %09d\n", n, (int) (sum * 1e9));
	return 0;
}


int main(int argc, char *argv[]){
	//First argument: ceiling, second argument:increment
	
	//Variables
	char *p;
	errno = 0;
	int n = strtol(argv[1], &p, 10);
	int m = strtol(argv[2], &p, 10);

	//Check input
	if(argc != 3){printf("Incorrect input!\n");return 0;}
	if(errno != 0 || *p != '\0'){
		printf("Incorrect input!\n");return 0;
	}
	
	float start_time,end_time,time_elapsed;
	
	for(int i=1; i<n; i+=m){
		start_time = (float)clock()/CLOCKS_PER_SEC*1000;
		n_pi(i);
		end_time = (float)clock()/CLOCKS_PER_SEC*1000;
		
		time_elapsed = end_time - start_time;
	
		printf("%4d \t %.3f\n", i, time_elapsed);
	}
	
	return 0;
}
