#include <cstdio>
#include <cstdlib>
#include <climits>

#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2 * i + 1)
#define RIGHT(i)  (2 * i + 2)

using namespace std;

typedef struct
{
    int *elements;
    int maxLen, hsize;
} heap;

int GetMin(heap *H);
void MinHeapify(heap *H, int i);
int ExtractMin(heap *H);
void DescreaseKey(heap *H, int i, int key);
void InsertHeap(heap *H,int key);

int main()
{
    int n,x;

    heap h;
    h.hsize = 0;
    h.elements = new int[100];
    h.maxLen = 100;

    scanf("%d\n",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&x);
        InsertHeap(&h, x);
    }

    for(int i = 1; i <= n; i++)
        printf("%d ",h.elements[i]);
}

int GetMin(heap *H)
{
    return H.elements[0];
}

void MinHeapify(heap *H, int i)
{
    int left  = LEFT(i),
        right = RIGHT(i),
        smallest;

    smallest = i;

    if (left < H.hsize && H.elements[left] < H.elements[i])
    {
        smallest = left;
    }

    if (right < H.hsize && H.elements[right] < H.elements[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        int val = H.elements[i];
        H.elements[i] = H.elements[smallest];
        H.elements[smallest] = val;

        MinHeapify(H, smallest);
    }
}

int ExtractMin(heap *H)
{
    if (H.hsize == 0)
    {
        fprintf(stderr, "Heap underflow");
        exit(0);
    }

    int minim = H.elements[0];
    H.elements[0] = H.elements[H.hsize - 1];
    H.hsize--;
    MinHeapify(H, 0);

    return minim;
}

void DescreaseKey(heap *H, int i, int key)
{
    if (key > H.elements[i])
    {
        fprintf(stderr, "Key must be smaller");
        exit(0);
    }

    H.elements[i] = key;
    while (i > 0 && H.elements[PARENT(i)] > H.elements[i])
    {
        int par = H.elements[PARENT(i)];
        H.elements[PARENT(i)] = H.elements[i];
        H.elements[i] = par;
        i = PARENT(i);
    }
}

void InsertHeap(heap *H, int key)
{
    if (H.maxLen == H.hsize)
    {
        fprintf(stderr, "Heap overflow");
        exit(0);
    }

    H.elements[H.hsize] = INT_MAX;
    H.hsize++;
    DescreaseKey(H, H.hsize - 1, key);
}
