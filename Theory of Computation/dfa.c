// WAP to design a DFA for the given language cases
#include <stdio.h>
#include <string.h>

// 1. L = {w : na(w) = 1; w belongs to (a, b)*}
void q1(char str[], int i);
void q2(char str[], int i);
void q0(char str[], int i)
{
	if (strlen(str) == i)
	{
		printf("Rejected\n");
		return;
	}
	if (str[i] == 'a')
		q1(str, ++i);
	else
		q0(str, ++i);
}
void q1(char str[], int i)
{
	if (strlen(str) == i)
	{
		printf("Accepted\n");
		return;
	}
	if (str[i] == 'a')
		q2(str, ++i);
	else
		q1(str, ++i);
}
void q2(char str[], int i)
{
	if (strlen(str) == i)
	{
		printf("Rejected\n");
		return;
	}
	q2(str, ++i);
}

// 2. L = {w : na(w) > 1; w belongs to (a, b)*}
void r1(char str[], int i);
void r2(char str[], int i);
void r0(char str[], int i)
{
	if (strlen(str) == i)
	{
		printf("Rejected\n");
		return;
	}
	if (str[i] == 'a')
		r1(str, ++i);
	else
		r0(str, ++i);
}
void r1(char str[], int i)
{
	if (strlen(str) == i)
	{
		printf("Rejected\n");
		return;
	}
	if (str[i] == 'a')
		r2(str, ++i);
	else
		r1(str, ++i);
}
void r2(char str[], int i)
{
	if (strlen(str) == i)
	{
		printf("Accepted\n");
		return;
	}
	r2(str, ++i);
}

// 3. L = {w : na(w) >= 1 and nb(w) = 2; w belongs to (a, b)*}
void s1(char str[], int i);
void s2(char str[], int i);
void s3(char str[], int i);
void s4(char str[], int i);
void s5(char str[], int i);
void s6(char str[], int i);
void s0(char str[], int i)
{
	if (strlen(str) == i)
	{
		printf("Rejected\n");
		return;
	}
	if (str[i] == 'a')
		s1(str, ++i);
	else
		s5(str, ++i);
}
void s1(char str[], int i)
{
	if (strlen(str) == i)
	{
		printf("Rejected\n");
		return;
	}
	if (str[i] == 'a')
		s1(str, ++i);
	else
		s2(str, ++i);
}
void s2(char str[], int i)
{
	if (strlen(str) == i)
	{
		printf("Rejected\n");
		return;
	}
	if (str[i] == 'a')
		s2(str, ++i);
	else
		s3(str, ++i);
}
void s3(char str[], int i)
{
	if (strlen(str) == i)
	{
		printf("Accepted\n");
		return;
	}
	if (str[i] == 'a')
		s3(str, ++i);
	else
		s4(str, ++i);
}
void s4(char str[], int i)
{
	if (strlen(str) == i)
	{
		printf("Rejected\n");
		return;
	}
	s4(str, ++i);
}
void s5(char str[], int i)
{
	if (strlen(str) == i)
	{
		printf("Rejected\n");
		return;
	}
	if (str[i] == 'a')
		s2(str, ++i);
	else
		s6(str, ++i);
}
void s6(char str[], int i)
{
	if (strlen(str) == i)
	{
		printf("Rejected\n");
		return;
	}
	if (str[i] == 'a')
		s3(str, ++i);
	else
		s4(str, ++i);
}

// 4. L = {w1 ab w2; w1 & w2 belongs to (a, b)*}
void t1(char str[], int i);
void t2(char str[], int i);
void t0(char str[], int i)
{
	if (strlen(str) == i)
	{
		printf("Rejected\n");
		return;
	}
	if (str[i] == 'a')
		t1(str, ++i);
	else
		t0(str, ++i);
}
void t1(char str[], int i)
{
	if (strlen(str) == i)
	{
		printf("Rejected\n");
		return;
	}
	if (str[i] == 'a')
		t1(str, ++i);
	else
		t2(str, ++i);
}
void t2(char str[], int i)
{
	if (strlen(str) == i)
	{
		printf("Accepted\n");
		return;
	}
	t2(str, ++i);
}

// Driver program
void main()
{
	printf("\nCase 1: a=1\n");
	printf("Case 2: a>1\n");
	printf("Case 3: a>=1, b=2\n");
	printf("Case 4: substring 'ab'\n");

	char str[100];
	int n;

	while (1)
	{
		printf("\nEnter case and string: ");
		scanf("%d", &n);
		gets(str);
		printf("Status: ");

		switch (n)
		{
		case 1:
			q0(str, 0);
			break;
		case 2:
			r0(str, 0);
			break;
		case 3:
			s0(str, 0);
			break;
		case 4:
			t0(str, 0);
			break;
		default:
			printf("TRY AGAIN\n");
		}
	}
}
