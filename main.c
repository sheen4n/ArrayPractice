#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
//    int A[10];
    int size;
    int length;
};

void Display(struct Array arr) {
    printf("\nElements are \n");
    for (int i = 0; i < arr.length; i++) printf("%d ", arr.A[i]);
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Append(struct Array *arr, int x) {
    if (arr->length < arr->size) {
        arr->A[arr->length] = x;
        (*arr).length++;
    } else {
        printf("Array is already full!");
    }
}

void Insert(struct Array *arr, int index, int x) {
    if (index < 0 || arr->length == arr->size) {
        printf("Invalid Index");
        return;
    }

    for (int i = arr->length; i > index; i--) {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = x;
    arr->length++;
}

int Delete(struct Array *arr, int index) {
    // [1,2,3,4,5] index to remove = 2
    // [1,2,4,5]
    // x = A[2]
    // For A[2] to A[3],
    // A[2] = A[3],
    // A[3] = A[4]
    // A[5] = 0
    // A length - 1

    printf("A");

    if (index < 0 || index >= arr->length) {
        printf("Invalid Index");
        return -1;
    }

    printf("B");

    int x = arr->A[index];
    for (int i = index; i < arr->length - 1; i++)
        arr[i] = arr[i + 1];

    printf("C");


    arr->A[arr->length--] = 0;
    return x;
}

int LinearSearch(struct Array *arr, int key) {
    int i;
    for (i = 0; i < arr->length; i++) {
        if (key == arr->A[i]) return i;
    }
    return -1;
}

// Time Complexity = O(log N)
// Space Complexity = O(1)
int BinarySearch(struct Array arr, int key) {
    int l, mid, h;
    l = 0;
    h = arr.length - 1;

    while (l <= h) {
        mid = (l + h) / 2;
        if (key == arr.A[mid]) return mid;

        if (key > arr.A[mid]) l = mid + 1;
        if (key < arr.A[mid]) h = mid - 1;
    }
    return -1;
}

int RecursiveBinarySearch(int a[], int l, int h, int key) {
    int mid;

    if (l < h) {
        mid = (l + h) / 2;
        if (key == a[mid])return mid;
        if (key < a[mid]) return RecursiveBinarySearch(a, l, mid - 1, key);
        return RecursiveBinarySearch(a, mid + 1, h, key);
    }
    return -1;
}

int Get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length) {
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int value) {
    if (index >= 0 && index < arr->length) {
        arr->A[index] = value;
    }
}

int Max(struct Array arr) {
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] > max) max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr) {
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] < min) min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr) {
    int sum = 0;

    for (int i = 0; i < arr.length; i++)
        sum += arr.A[i];

    return sum;
}

float Avg(struct Array arr) {
    return (float) Sum(arr) / arr.length;
}

void Reverse(struct Array *arr) {
    int *B;
    int i, j;

    B = (int *) malloc(arr->length * sizeof(int));
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = arr->A[i];
    }

    for (i = 0; i < arr->length; i++) {
        arr->A[i] = B[i];
    }
}

void Reverse2(struct Array *arr) {
    int i, j;

    for (i = 0, j = arr->length - 1; i < j; i++, j--)
        swap(&arr->A[i], &arr->A[j]);
}

void InsertAlreadySorted(struct Array *arr, int x) {
    // No Free Space
    if (arr->length == arr->size) return;

    int i = arr->length - 1;


    while (i >= 0 && arr->A[i] > x) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }

    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array arr) {
    for (int i = 0; i < arr.length - 1; i++) {
        if (arr.A[i + 1] < arr.A[i]) return 0;
    }

    return 1;
}

void RearrangePositiveNegative(struct Array *arr) {
    int i, j;
    i = 0;
    j = arr->length - 1;

    while (i < j) {

        while (arr->A[i] < 0)i++;
        while (arr->A[j] >= 0)j--;

        if (i < j)swap(&arr->A[i], &arr->A[j]);
    }
}

struct Array *Merge(struct Array *arr1, struct Array *arr2) {

    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else {
            arr3->A[k++] = arr2->A[j++];
        }
    }

    while (i < arr1->length) arr3->A[k++] = arr1->A[i++];
    while (j < arr2->length) arr3->A[k++] = arr2->A[j++];

    arr3->length = arr3->size = k;

    return arr3;
}

struct Array *Union(struct Array *arr1, struct Array *arr2) {

    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else if (arr2->A[j] < arr1->A[i]) {
            arr3->A[k++] = arr2->A[j++];
        } else {
            // Increment both i and j , if both values are equal
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    while (i < arr1->length) arr3->A[k++] = arr1->A[i++];
    while (j < arr2->length) arr3->A[k++] = arr2->A[j++];

    arr3->length = arr3->size = k;

    return arr3;
}

struct Array *Intersection(struct Array *arr1, struct Array *arr2) {

    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            i++;
        } else if (arr2->A[j] < arr1->A[i]) {
            j++;
        } else {
            // Increment both i and j , if both values are equal
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = arr3->size = k;
    return arr3;
}

struct Array *Difference(struct Array *arr1, struct Array *arr2) {

    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else if (arr2->A[j] < arr1->A[i]) {
            j++;
        } else {
            // Increment both i and j , if both values are equal
            i++;
            j++;
        }
    }

    while (i < arr1->length) arr3->A[k++] = arr1->A[i++];

    arr3->length = arr3->size = k;

    return arr3;
}


int main() {
    struct Array arr1;
    int ch;
    int x, index;

    printf("Enter Size of Array");
    scanf("%d", &arr1.size);
    arr1.A = (int *) malloc(arr1.size * sizeof(int));
    arr1.length = 0;

    do {
        printf("\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6.Exit\n");

        printf("enter your choice ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter an element and index");
                scanf("%d%d", &x, &index);
                Insert(&arr1, index, x);
                break;
            case 2:
                printf("Enter index ");
                scanf("%d", &index);
                x = Delete(&arr1, index);
                printf("Deleted Element is %d\n", x);
                break;
            case 3:
                printf("Enter element to search ");
                scanf("%d", &x);
                index = LinearSearch(&arr1, x);
                printf("Element index %d", index);
                break;
            case 4:
                printf("Sum is %d\n", Sum(arr1));
                break;
            case 5:
                Display(arr1);

        }
    } while (ch < 6);
    return 0;

}
