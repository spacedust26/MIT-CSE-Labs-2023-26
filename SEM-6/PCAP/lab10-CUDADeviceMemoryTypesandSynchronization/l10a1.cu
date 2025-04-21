// Additional exercise 1 - Write a program in CUDA which displays a shopping mall item menu with its price, The N number of friens are allowed to purchse as many items as they want. Calculate the total purchase done by N freinds

#include <stdio.h>
#include <cuda_runtime.h>

#define NUM_ITEMS 5
#define NUM_FRIENDS 3

// CUDA kernel to calculate total purchase for each friend
__global__ void calculateTotal(float* itemPrices, int* quantities, float* totals, int numItems) {
    int friendId = blockIdx.x;
    float sum = 0.0f;

    for (int i = 0; i < numItems; i++) {
        sum += itemPrices[i] * quantities[friendId * numItems + i];
    }

    totals[friendId] = sum;
}

int main() {
    // Item names and prices
    const char* itemNames[NUM_ITEMS] = {"Shoes", "Shirt", "Jeans", "Watch", "Bag"};
    float itemPrices[NUM_ITEMS] = {50.0f, 30.0f, 60.0f, 120.0f, 40.0f};

    // Quantities each friend purchased [NUM_FRIENDS x NUM_ITEMS]
    int quantities[NUM_FRIENDS][NUM_ITEMS] = {
        {1, 2, 0, 0, 1}, // Friend 1
        {0, 1, 1, 0, 0}, // Friend 2
        {2, 0, 1, 1, 0}  // Friend 3
    };

    // Device pointers
    float *d_itemPrices, *d_totals;
    int *d_quantities;

    // Allocate memory on device
    cudaMalloc((void**)&d_itemPrices, NUM_ITEMS * sizeof(float));
    cudaMalloc((void**)&d_quantities, NUM_FRIENDS * NUM_ITEMS * sizeof(int));
    cudaMalloc((void**)&d_totals, NUM_FRIENDS * sizeof(float));

    // Copy data to device
    cudaMemcpy(d_itemPrices, itemPrices, NUM_ITEMS * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_quantities, quantities, NUM_FRIENDS * NUM_ITEMS * sizeof(int), cudaMemcpyHostToDevice);

    // Launch kernel: 1 block per friend
    calculateTotal<<<NUM_FRIENDS, 1>>>(d_itemPrices, d_quantities, d_totals, NUM_ITEMS);

    // Copy totals back to host
    float totals[NUM_FRIENDS];
    cudaMemcpy(totals, d_totals, NUM_FRIENDS * sizeof(float), cudaMemcpyDeviceToHost);

    // Print menu
    printf("\n--- Shopping Mall Menu ---\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("%s: $%.2f\n", itemNames[i], itemPrices[i]);
    }

    // Print individual and grand total
    printf("\n--- Friends' Purchases ---\n");
    float grandTotal = 0.0f;
    for (int i = 0; i < NUM_FRIENDS; i++) {
        printf("Friend %d total: $%.2f\n", i + 1, totals[i]);
        grandTotal += totals[i];
    }

    printf("\nTotal purchase by all friends: $%.2f\n", grandTotal);

    // Free device memory
    cudaFree(d_itemPrices);
    cudaFree(d_quantities);
    cudaFree(d_totals);

    return 0;
}
