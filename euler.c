#include <stdio.h>
#include <stdlib.h>

int multiple(int x, int n)
{
	int i = 1, somme = 0;
	
	while(i < n)
	{
		if(i % x == 0)
			somme += i;
		i++;
	}
	
	return somme;
}

int fibonacci_pair(int n)
{
	int resultat = 0, a = 1, b = 1, tmp;
	
	while(b <= n)
	{
		if(b % 2 == 0)
			resultat += b;
		tmp = a;
		a = b;
		b = tmp + b;
	}
	
	return resultat;
}

int nombre_premiers(long int n)
{
	int d = 2, max = 0;
	
	while(n > 1)
	{
		while(n % d == 0)
		{
			if(max < d)
				max = d;
			n /= d;
		}
		d++;
	}
	
	return max;
}

int palindrome(int n)
{
	int temp = n, reverse = 0;

	while (temp != 0)
	{
		reverse = reverse * 10;
		reverse = reverse + temp % 10;
		temp = temp / 10;
	}
	
	if(n == reverse)
		return 0;
	else return 1;
}

int palindrome_product()
{
	int max = 0, i, j, produit;
	
	for(i = 999; i > 99; i--)
	{
		for(j = 999; j > 99; j--)
		{
			produit = i * j;
			if(palindrome(produit) == 0 && produit > max)
				max = produit;
		}
	}
	
	return max;
}

int plus_petit_multiple(int x, int y)
{
	int i = 1, j;
	
	while(1)
	{
		for(j = x; j <= y; j++)
		{
			if(i % j != 0)
				break;
			
			if(j == y)
				return i;
		}
		i++;
	}
}

int main(int argc, char* argv[]) 
{
	// Project 1 - Multiples of 3 and 5
	printf("Project 1 - %d\n", multiple(3, 1000) + multiple(5, 1000) - multiple(15, 1000));
	
	// Project 2 - Even Fibonacci numbers
	printf("Project 2 - %d\n", fibonacci_pair(4000000));
	
	// Project 3 - Largest prime factor
	printf("Project 3 - %d\n", nombre_premiers(600851475143));
	
	// Project 4 - Largest palindrome product
	printf("Project 4 - %d\n", palindrome_product());
	
	// Project 5 - Smallest Multiple
	printf("Project 5 - %d\n", plus_petit_multiple(1, 20));
	
	return 0;
}
