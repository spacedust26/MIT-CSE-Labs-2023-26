#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define maxres 5
#define maxt 10

int avl[maxres];
int maxi[maxt][maxres];
int allocation[maxt][maxres];
int need[maxt][maxres];
int numth, numres;

pthread_mutex_t lock;

bool is_safe(int thread_id) {
    int work[maxres];
    bool finish[maxt] = {false};
    
    for (int i = 0; i < numres; i++)
        work[i] = avl[i];
    
    for (int i = 0; i < numth; i++) {
        if (!finish[i]) {
            bool canalloc = true;
            for (int j = 0; j < numres; j++) {
                if (need[i][j] > work[j]) {
                    canalloc = false;
                    break;
                }
            }
            if (canalloc) {
                finish[i] = true;
                for (int j = 0; j < numres; j++)
                    work[j] += allocation[i][j];
                i = -1;
            }
        }
    }
    
    for (int i = 0; i < numth; i++)
        if (!finish[i])
            return false;
    return true;
}

void* thread_function(void* arg) {
    int thread_id = *(int*)arg;
    
    while (1) {
        int request[maxres];
        for (int i = 0; i < numres; i++)
            request[i] = rand() % (maxi[thread_id][i] - allocation[thread_id][i] + 1);
        
        pthread_mutex_lock(&lock);
        
        bool canalloc = true;
        for (int i = 0; i < numres; i++) {
            if (request[i] > avl[i] || request[i] > need[thread_id][i]) {
                canalloc = false;
                break;
            }
        }
        
        if (canalloc) {
            for (int i = 0; i < numres; i++) {
                avl[i] -= request[i];
                allocation[thread_id][i] += request[i];
                need[thread_id][i] -= request[i];
            }
            
            if (is_safe(thread_id)) {
                printf("Thread %d: Request granted\n", thread_id);
            } else {
                for (int i = 0; i < numres; i++) {
                    avl[i] += request[i];
                    allocation[thread_id][i] -= request[i];
                    need[thread_id][i] += request[i];
                }
                printf("Thread %d: Request denied (unsafe state)\n", thread_id);
            }
        } else {
            printf("Thread %d: Request denied (insufficient resources)\n", thread_id);
        }
        
        pthread_mutex_unlock(&lock);
        
        usleep(rand() % 1000000);
        
        pthread_mutex_lock(&lock);
        for (int i = 0; i < numres; i++) {
            int release = rand() % (allocation[thread_id][i] + 1);
            allocation[thread_id][i] -= release;
            avl[i] += release;
            need[thread_id][i] += release;
        }
        printf("Thread %d: Resources released\n", thread_id);
        pthread_mutex_unlock(&lock);
        
        usleep(rand() % 1000000);
    }
    
    return NULL;
}

int main() {
    srand(time(NULL));
    
    printf("Enter the number of threads: ");
    scanf("%d", &numth);
    printf("Enter the number of resources: ");
    scanf("%d", &numres);
    
    printf("Enter the avl resources:\n");
    for (int i = 0; i < numres; i++)
        scanf("%d", &avl[i]);
    
    printf("Enter the maxi resources for each thread:\n");
    for (int i = 0; i < numth; i++)
        for (int j = 0; j < numres; j++)
            scanf("%d", &maxi[i][j]);
    
    for (int i = 0; i < numth; i++)
        for (int j = 0; j < numres; j++) {
            allocation[i][j] = 0;
            need[i][j] = maxi[i][j];
        }
    
    pthread_mutex_init(&lock, NULL);
    
    pthread_t threads[maxt];
    int thread_ids[maxt];
    
    for (int i = 0; i < numth; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }
    
    for (int i = 0; i < numth; i++)
        pthread_join(threads[i], NULL);
    
    pthread_mutex_destroy(&lock);
    
    return 0;
}

// SAMPLE INPUT

// Enter the number of threads: 3
// Enter the number of resources: 3
// Enter the available resources:
// 10 5 7
// Enter the maximum resources for each thread:
// 3 2 2
// 6 1 3
// 3 1 4

// OUTPUT - DIY :p