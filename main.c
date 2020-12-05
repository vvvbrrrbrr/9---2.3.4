#include <stdio.h>
#include <stdlib.h>

int** funk(int n, int k)
{
	int** a = malloc(n*sizeof(int*));
	for(int i=0; i<n; i++)
		a[i]=malloc(k*sizeof(int));
	return a;
}

void pomenyatt (int*a, int*b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void bababa(int a[], int**d, int p, int n)
{
        int i, k, m;
        for(k=0; k<n-1; k++)
        {
            m=k;
            for(i=k+1; i<n; i++)
            {
                if (a[i]<a[m])
                    m=i;
            }
            if(k!=m)
            {
                pomenyatt(a+k, a+m);
                for(i=0; i<p; i++)
                    pomenyatt(&d[i][k], &d[i][m]);
            }
        }
}


void summa_v_stolbtse(int** a, int n, int k)
{
    int i, j;
    int* s;
    s = (int*) calloc(k, sizeof(int));
    for(i=0; i<k; i++)
        for(j=0; j<n; j++)
            s[i]=s[i]+a[j][i];
    for(i=0; i<k; i++)
        printf("%d ", s[i]);
    printf("\n");
    bababa(s, a, n, k);
    for(i=0; i<k; i++)
        printf("%d ", s[i]);
}

int main2()
{
	int n, k, i, j;
	printf("Vvedite kol-vo strok i stolbtsov\n");
	scanf("%d%d", &n, &k);
	int** a = funk(n, k);
	for (j=0; j<n; j++)
    for (i=0; i<k; i++)
    {
        a[j][i]=abs(i-j)+1;
    }
    for (j=0; j<n; j++)
    {
    for (i=0; i<k; i++)
        printf("%d ", a[j][i]);
    printf("\n");
    }


    int s=1, p=k, q=n, m;
    int** b = funk(n, k);
    j=-1, i=-1;
    do{
    m=i; j++;
    for(i=m+1; i<m+1+p; i++)
    {
        b[j][i]=s;
        s++;
    }
    q--;
    if(s-1==n*k)
        break;
    m=j; i--;
    for(j=m+1; j<m+1+q; j++)
    {
        b[j][i]=s;
        s++;
    }
    p--;
    if(s-1==n*k)
        break;
    m=i; j--;
    for(i=m-1; i>m-1-p; i--)
    {
        b[j][i]=s;
        s++;
    }
    q--;
    if(s-1==n*k)
        break;
    m=j; i++;
    for(j=m-1; j>m-1-q; j--)
    {
        b[j][i]=s;
        s++;
    }
    p--;
    if(s-1==n*k)
        break;
    } while (s<=n*k);


    for (j=0; j<n; j++)
    {
    for (i=0; i<k; i++)
        printf("%d ", b[j][i]);
    printf("\n");
    }
	return 0;
}

int summa_romba(int** a)
{
    int i, j, s=0;
    for(i=0; i<9; i++)
        for(j=abs(4-i); j<9-abs(4-i); j++)
            s=s+a[i][j];
    return s;
}

int main3()
{
	int n=9, k=9, i, j;
	int** a = funk(n, k);
	for (j=0; j<n; j++)
    for (i=0; i<k; i++)
    {
        a[j][i]=rand%10;
    }
    for (j=0; j<n; j++)
    {
    for (i=0; i<k; i++)
        printf("%d ", a[j][i]);
    printf("\n");
    }
    printf("%d", summa_romba(a));
    printf("\n");
    return 0;
}


int main4()
{
    int n, k, i, j;
	printf("Vvedite kol-vo strok i stolbtsov\n");
	scanf("%d%d", &n, &k);
	int** a = funk(n, k);
	for (j=0; j<n; j++)
    for (i=0; i<k; i++)
    {
        a[j][i]=rand()%10; // scanf("%d", &a[i][j]);
    }
    for (j=0; j<n; j++)
    {
    for (i=0; i<k; i++)
        printf("%d ", a[j][i]);
    printf("\n");
    }
    summa_v_stolbtse(a, n, k);
    printf("\n");
    for (j=0; j<n; j++)
    {
    for (i=0; i<k; i++)
        printf("%d ", a[j][i]);
    printf("\n");
    }
    return 0;
}


int main()
{
    int k;
    do
    {
    printf("Task 9\nvyberite zadanie:\nnomer 2\nnomer 3\nnomer 4\n");
    scanf("%d", &k);
    switch(k)
    {
    case 2:
        k=main2();
        break;
    case 3:
        k=main3();
        break;
    case 4:
        k=main4();
        break;
    default:
        printf("Takogo nomera net, poprobuyte eshche raz\n");
        k=0;
    }
    printf("nazhmite <<1>>, esli hotite prodolzhitb\n");
    scanf("%d", &k);
    } while (k==1);
    return 0;
}
