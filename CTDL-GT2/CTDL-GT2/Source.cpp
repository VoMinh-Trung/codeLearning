#include <stdio.h>



void main() {
    //so luong phan tu mang
    int n = 6;
    //khai bao mang
    int arr[6] = { 1,2,3,4,5,6 };
    //vi tri can xoa trong mang
    int index = 3;
    //hien thi mang ban dau
    printf("MANG BAN DAU\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t", arr[i]);
    }

    // Dich chuyen mang ve ben trai tu vi tri xoa
    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    //sau khi xoa giam so luong phan tu mang
    n--;

    //hien thi mang sau khi xoa tai vi tri index = 3
    printf("\nMANG SAU KHI XOA TAI ARR[%d]\n", index);
    for (int i = 0; i < n; i++) {
        printf("%d \t", arr[i]);
    }
}