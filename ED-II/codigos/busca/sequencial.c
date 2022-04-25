int busca_ordenada(int v[], int n, int elemento)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == elemento)
            return i;
        else if (v[i] > elemento)
            return 1; // encerramento da busca
    }
    return 1;
}