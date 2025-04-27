#include <stdio.h>
#include <string.h>

// 8. Palíndromo
int ehPalindromo(char str[], int inicio, int fim) {
    if (inicio >= fim) return 1;
    if (str[inicio] != str[fim]) return 0;
    return ehPalindromo(str, inicio + 1, fim - 1);
}
int main_palindromo() {
    char palavra[] = "arara";
    printf("Palindromo: %d\n", ehPalindromo(palavra, 0, strlen(palavra) - 1));
    return 0;
}

// 9. MDC
int mdc(int a, int b) {
    if (b == 0) return a;
    return mdc(b, a % b);
}
int main_mdc() {
    printf("MDC: %d\n", mdc(48, 18));
    return 0;
}

// 10. Multiplicação
int multiplicar(int a, int b) {
    if (b == 0) return 0;
    return a + multiplicar(a, b - 1);
}
int main_multiplicar() {
    printf("Multiplicacao: %d\n", multiplicar(4, 5));
    return 0;
}

// 11. Contar caractere
int contarChar(char str[], char c) {
    if (*str == '\0') return 0;
    return (*str == c) + contarChar(str + 1, c);
}
int main_contarChar() {
    char texto[] = "abracadabra";
    printf("Contar 'a': %d\n", contarChar(texto, 'a'));
    return 0;
}

// 12. Soma Array
int somaArray(int arr[], int n) {
    if (n == 0) return 0;
    return arr[0] + somaArray(arr + 1, n - 1);
}
int main_somaArray() {
    int v[] = {1, 2, 3, 4};
    printf("Soma Array: %d\n", somaArray(v, 4));
    return 0;
}

// 13. Primo
int ehPrimoAux(int n, int divisor) {
    if (divisor * divisor > n) return 1;
    if (n % divisor == 0) return 0;
    return ehPrimoAux(n, divisor + 1);
}
int ehPrimo(int n) {
    if (n <= 1) return 0;
    return ehPrimoAux(n, 2);
}
int main_primo() {
    printf("Primo 7: %d\n", ehPrimo(7));
    printf("Primo 9: %d\n", ehPrimo(9));
    return 0;
}

// 14. Decimal para Binário
void decimalParaBinario(int n) {
    if (n == 0) return;
    decimalParaBinario(n / 2);
    printf("%d", n % 2);
}
int main_decimalParaBinario() {
    int num = 10;
    printf("Binario de 10: ");
    decimalParaBinario(num);
    printf("\n");
    return 0;
}

// 15. Pares
void imprimirPares(int n, int atual) {
    if (atual > n) return;
    printf("%d ", atual);
    imprimirPares(n, atual + 2);
}
int main_pares() {
    printf("Pares até 6: ");
    imprimirPares(6, 0);
    printf("\n");
    return 0;
}

// 16. Ímpares
void imprimirImpares(int n, int atual) {
    if (atual > n) return;
    printf("%d ", atual);
    imprimirImpares(n, atual + 2);
}
int main_impares() {
    printf("Impares até 7: ");
    imprimirImpares(7, 1);
    printf("\n");
    return 0;
}

// 17. Buscar elemento
int buscarElemento(int arr[], int n, int x) {
    if (n == 0) return 0;
    if (arr[0] == x) return 1;
    return buscarElemento(arr + 1, n - 1, x);
}
int main_buscarElemento() {
    int v[] = {2, 4, 6, 8};
    printf("Buscar 6: %d\n", buscarElemento(v, 4, 6));
    printf("Buscar 5: %d\n", buscarElemento(v, 4, 5));
    return 0;
}

// 18. Comprimento da String
int comprimento(char str[]) {
    if (*str == '\0') return 0;
    return 1 + comprimento(str + 1);
}
int main_comprimento() {
    char palavra[] = "recursivo";
    printf("Comprimento: %d\n", comprimento(palavra));
    return 0;
}

// 19. Torre de Hanoi
void hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        return;
    }
    hanoi(n - 1, origem, auxiliar, destino);
    printf("Mover disco %d de %c para %c\n", n, origem, destino);
    hanoi(n - 1, auxiliar, destino, origem);
}
int main_hanoi() {
    int n = 2;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}

// 20. Permutação
void trocar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
void permutar(char str[], int l, int r) {
    if (l == r) {
        printf("%s\n", str);
        return;
    }
    for (int i = l; i <= r; i++) {
        trocar(&str[l], &str[i]);
        permutar(str, l + 1, r);
        trocar(&str[l], &str[i]);
    }
}
int main_permutar() {
    char palavra[] = "abc";
    permutar(palavra, 0, strlen(palavra) - 1);
    return 0;
}

// 21. Combinação
void combinar(int arr[], int n, int k, int index, int data[], int i) {
    if (index == k) {
        for (int j = 0; j < k; j++)
            printf("%d ", data[j]);
        printf("\n");
        return;
    }
    if (i >= n) return;
    data[index] = arr[i];
    combinar(arr, n, k, index + 1, data, i + 1);
    combinar(arr, n, k, index, data, i + 1);
}
int main_combinar() {
    int v[] = {1, 2, 3};
    int data[2];
    combinar(v, 3, 2, 0, data, 0);
    return 0;
}

// 22. Subconjuntos
void subconjuntos(int arr[], int n, int index, int subset[], int subsetSize) {
    if (index == n) {
        printf("{");
        for (int i = 0; i < subsetSize; i++)
            printf("%d ", subset[i]);
        printf("}\n");
        return;
    }
    subset[subsetSize] = arr[index];
    subconjuntos(arr, n, index + 1, subset, subsetSize + 1);
    subconjuntos(arr, n, index + 1, subset, subsetSize);
}
int main_subconjuntos() {
    int v[] = {1, 2};
    int subset[2];
    subconjuntos(v, 2, 0, subset, 0);
    return 0;
}

// 23. Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    i = j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main_mergeSort() {
    int v[] = {5, 3, 8, 1};
    mergeSort(v, 0, 3);
    printf("Merge Sort: ");
    for (int i = 0; i < 4; i++) printf("%d ", v[i]);
    printf("\n");
    return 0;
}

