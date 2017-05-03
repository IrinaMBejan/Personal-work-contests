#include <cstdio>
#define CROSSOVER 35
#define MIN -100000
#define NMAX 200

typedef struct
{
    int left;
    int right;
    int sum;
} maxTuple;

maxTuple BruteForce(int A[], int st, int fi);
maxTuple GetCrossingSubarray(int A[], int st, int mid, int fi);
maxTuple DivConqMaximumSubarray(int A[], int st, int fi);
maxTuple MixedDivConq(int A[], int st, int fi);

int main()
{
    int n,i;
    int vec[NMAX];
    scanf("%d",&n);

    for(i = 0; i < n; i++)
        scanf("%d",&vec[i]);
    printf("%d\n",MixedDivConq(vec,0,n).sum);
}

maxTuple BruteForce(int A[], int st, int fi)
{
    int i,j;
    maxTuple result = {0, 0, MIN};

    for (i = st; i < fi; i++)
    {
        int sum = 0;
        for (j = i; j < fi; j++)
        {
            sum += A[j];
            if (result.sum < sum)
            {
                result.left = i;
                result.right = j + 1;
                result.sum = sum;
            }
        }
    }

    return result;
}

maxTuple GetCrossingSubarray(int A[], int st, int mid, int fi)
{
    int i,j;

    maxTuple result = {-1, -1, 0};
    int sum = 0, left_sum = MIN, right_sum = MIN;

    for (i = mid - 1; i >= st; i--)
    {
        sum += A[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            result.left = i;
        }
    }

    sum = 0;

    for (j = mid; j < fi; j++)
    {
        sum += A[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            result.right = j + 1;
        }
    }

    result.sum = left_sum + right_sum;
    return result;
}

maxTuple DivConqMaximumSubarray(int A[], int st, int fi)
{
    if (fi == st + 1)
    {
        maxTuple result = {st, fi, A[st]};
        return result;
    }
    else
    {
        int mid = (st + fi) / 2;

        maxTuple left = DivConqMaximumSubarray(A, st, mid);
        maxTuple right = DivConqMaximumSubarray(A, mid, fi);
        maxTuple cross = GetCrossingSubarray(A, st, mid, fi);

        if (left.sum >= right.sum && left.sum >= cross.sum)
        {
            return left;
        }
        else if (right.sum >= left.sum && right.sum >= cross.sum)
        {
            return right;
        }
        else
        {
            return cross;
        }
    }
}

maxTuple MixedDivConq(int A[], int st, int fi)
{
    if (fi - st < CROSSOVER)
    {
        return BruteForce(A, st, fi);
    }
    else
    {
        int mid = (st + fi) / 2;

        maxTuple left = MixedDivConq(A, st, mid);
        maxTuple right = MixedDivConq(A, mid, fi);
        maxTuple cross = GetCrossingSubarray(A, st, mid,fi);

        if (left.sum >= right.sum && left.sum >= cross.sum)
        {
            return left;
        }
        else if (right.sum >= left.sum && right.sum >= cross.sum)
        {
            return right;
        }
        else
        {
            return cross;
        }
    }
}
