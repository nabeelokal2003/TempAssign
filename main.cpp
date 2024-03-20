#include <iostream>
using namespace std;


void heap(int ex[], int i){
    int n = sizeof ex / sizeof ex[0];
    if (2 * i <= n){            // check
        heap(ex, 2 * i);
        heap(ex, (2 * i) + 1);
        if (ex[2 * i] > ex[i] && ex[2 * i] > ex[(2 * i) + 1]){
            int t4 = ex[(2 * i) + 1];
            ex[(2 * i) + 1] = ex[i];
            ex[i] = t4;
            heap(ex, 2 * i);
        }
        else if (ex[(2 * i) + 1] > ex[i] && ex[(2 * i) + 1] > ex[2 * i]){
            int t5 = ex[(2 * i) + 1];
            ex[(2 * i) + 1] = ex[i];
            ex[i] = t5;
            heap(ex, (2 * i) + 1);
        }
    }
}
// Stage 2
void heap_sort(int ex[]){
    int n = sizeof ex / sizeof ex[0];
    for (int i = 1; i < n; i++){
        int t1 = ex[1];
        ex[1] = ex[n - i + 1];
        ex[n - i + 1] = t1;
        int j = 1;

        while(2 * j <= n - i){
            if(ex[2 * j] > ex[j] && ex[2 * j] > ex[(2 * j) + 1]){
                int t2 = ex[2 * j];
                ex[2 * j] = ex[j];
                ex[j]  = t2;
                j = 2 * j;
            }
            else if(ex[(2 * j) + 1] > ex[j] && ex[(2 * j) + 1] > ex[2 * j]){
                int t3 = ex[(2 * j) + 1];
                ex[(2 * j) + 1] = ex[j];
                ex[j] = t3;
                j = (2 * j) + 1;
            }
        }
    }
}

void print_arr(int ex[], int n){
    cout << "Sorted array is [";
    for(int i = 1; i <= n; i++)
        cout << ex[i] << " ";
    cout << "]";
}

void go(int i, int n, int G[][], int visited[], int finished[], int stage[]){
    visited[i] = 1;
    for(int j = 1; j <= n; j++){
        if(G[j][i] == 1)
            if(visited[j] == 1)
                if(finished[j] == 0)
                    break;
        else
            go(i, n, G, visited, finished, stage);
        if(stage[i] <= stage[j])
            stage[i] = stage[j] + 1;
    }
    finished[i] = 1;
}

void top_sort(int G[][], int n){
    int visited[] {}, finished[] {}, stage[] {}, out[] {};
    for(int i = 1; i <= n; i++) visited[i] = 0;
    for(int i = 1; i <= n; i++) finished[i] = 0;
    for(int i = 1; i <= n; i++) stage[i] = 1;
    for(int i = 1; i <= n; i++) out[i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(G[i][j] == 1)
                out[i] = out[i] + 1;
        }
    }

    for(int i = 1; i <= n; i++){
        if(out[i] == 0)
            go(i, n, G, visited, finished, stage);
    }
}
int main() {
    int arr[] {10,2,8,4,6};
    for(int i {0}; i < 5; i++){
        arr[i] = 0;
    }

    cout << "["
    for(int i: arr)
        cout << i << " ";
    cout << "]" << endl;

    return 0;
}