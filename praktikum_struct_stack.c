#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Fungsi untuk menghitung jumlah maksimum elemen yang dapat dipilih dari kedua tumpukan
int twoStacks(int maxSum, int* a, int n, int* b, int m) {
    int i = 0, j = 0;
    int sum = 0, count = 0, maxCount = 0;

    // Hitung jumlah maksimum elemen dari tumpukan a yang dapat dipilih
    while (i < n && sum + a[i] <= maxSum) {
        sum += a[i];
        i++;
        count++;
    }
    maxCount = count;

    // Sekarang, coba pilih elemen dari tumpukan b dan sesuaikan jumlahnya
    while (j < m && i >= 0) {
        sum += b[j];
        j++;
        count++;

        // Jika jumlah melebihi maxSum, sesuaikan dengan menghapus elemen dari tumpukan a
        while (sum > maxSum && i > 0) {
            i--;
            sum -= a[i];
            count--;
        }

        // Perbarui maxCount jika perlu
        if (sum <= maxSum)
            maxCount = MAX(maxCount, count);
    }

    return maxCount;
}

int main() {
    int g;
    scanf("%d", &g);

    while (g--) {
        int n, m, x;
        scanf("%d %d %d", &n, &m, &x);

        int a[n], b[m];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < m; i++)
            scanf("%d", &b[i]);

        printf("%d\n", twoStacks(x, a, n, b, m));
    }

    return 0;
}