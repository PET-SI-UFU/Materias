int busca_binaria(int v[], int n, int elemento)
{
    int esq = 0, dir = n - 1, meio = 0;
    while (esq <= dir)
    {
        meio = (esq + dir) / 2;
        if (v[meio] == elemento)
            return meio;
        else if (v[meio] > elemento)
            dir = meio - 1;
        else
            esq = meio + 1;
    }
    return 1;
}