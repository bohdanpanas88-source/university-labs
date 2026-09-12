#include <iostream>

struct elem
{
    int first, second;
};

void print(elem arr[], int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << "(" << arr[i].first << "," << arr[i].second << ")  ";
    std::cout << "\n";
}

bool contains(elem arr[], int size, elem e)
{
    for (int i = 0; i < size; ++i)
        if (arr[i].first == e.first && arr[i].second == e.second)
            return true;
    return false;
}

elem* inverse(elem arr[], int size)
{
    elem* res = new elem[size];

    for (int i = 0; i < size; ++i)
    {
        res[i].first = arr[i].second;
        res[i].second = arr[i].first;
    }

    return res;
}

elem* intersection(elem a[], int sizeA, elem b[], int sizeB, int& newSize)
{
    elem* res = new elem[sizeA];
    newSize = 0;

    for (int i = 0; i < sizeA; ++i)
        if (contains(b, sizeB, a[i]))
            res[newSize++] = a[i];

    return res;
}

elem* unionSet(elem a[], int sizeA, elem b[], int sizeB, int& newSize)
{
    elem* res = new elem[sizeA + sizeB];
    newSize = 0;

    for (int i = 0; i < sizeA; ++i)
        res[newSize++] = a[i];

    for (int i = 0; i < sizeB; ++i)
        if (!contains(res, newSize, b[i]))
            res[newSize++] = b[i];

    return res;
}

elem* symmetricDifference(elem a[], int sizeA, elem b[], int sizeB, int& newSize)
{
    elem* res = new elem[sizeA + sizeB];
    newSize = 0;

    for (int i = 0; i < sizeA; ++i)
        if (!contains(b, sizeB, a[i]))
            res[newSize++] = a[i];

    for (int i = 0; i < sizeB; ++i)
        if (!contains(a, sizeA, b[i]))
            res[newSize++] = b[i];

    return res;
}

elem* difference(elem s[], int sizeS, elem r[], int sizeR, int& newSize)
{
    elem* res = new elem[sizeS];
    newSize = 0;

    for (int i = 0; i < sizeS; ++i)
        if (!contains(r, sizeR, s[i]))
            res[newSize++] = s[i];

    return res;
}

int main()
{
    const int n = 6, k = 4;

    elem R[n] = { {1,1}, {1,2}, {1,3}, {2,2}, {2,3}, {3,3} };
    elem S[k] = { {1,1}, {1,2}, {2,2}, {3,1} };

    std::cout << "Array R:\n";
    print(R, n);

    std::cout << "Array S:\n";
    print(S, k);

    elem* arr = inverse(R, n);
    std::cout << "R^(-1):\n";
    print(arr, n);
    delete[] arr;

    int newSize;

    arr = intersection(R, n, S, k, newSize);
    std::cout << "R ^ S:\n";
    print(arr, newSize);
    delete[] arr;

    arr = unionSet(R, n, S, k, newSize);
    std::cout << "R + S:\n";
    print(arr, newSize);
    delete[] arr;

    arr = symmetricDifference(R, n, S, k, newSize);
    std::cout << "R (+) S:\n";
    print(arr, newSize);
    delete[] arr;

    arr = difference(S, k, R, n, newSize);
    std::cout << "S \\ R:\n";
    print(arr, newSize);
    delete[] arr;

    system("pause");
    return 0;
}
