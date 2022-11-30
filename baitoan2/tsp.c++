#include<bits/stdc++.h>
using namespace std;
#define N 100
int arr[N][N];
int final[N+1];
int final_value = 999999; // gia tri nho nhat can tim
int f0 = INT_MAX; // can cua thuat toan nhanh can
int order[N+1]; // thu tu tham cac thanh pho
bool visited[N + 1]; // xem xet thanh pho i da duoc tham hay chua
int minCost = 0; // chi phi nho nhat de di giua 2 thanh pho
int cost = 0; // chi phi tai thanh pho thu k

void generateRandomCost(int arr[N][N], int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int randVal = rand()%100;
            arr[i][j] = randVal;
            arr[j][i] = randVal;
            if(i==j) arr[i][j]=0;
            if(randVal < minCost && randVal !=0 ){
                minCost = randVal;
            }
        }
    }
}
void Try(int k, int n) {
    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            order[k] = i;
            cost = cost + arr[order[k-1]-1][i-1];
            if (k == n) {
                if ((cost + arr[order[n] - 1][order[1] - 1]) < final_value)
                {
                    final_value = cost + arr[order[n] - 1][order[1] - 1];
                    for (int i = 1; i <= n; i++) {
                        final[i] = order[i];
                    }
                }
            }
            else {
                Try(k+1, n);
            }
            cost -= arr[order[k - 1]-1][i-1];
            visited[i] = false;

        }
    }
}
    

void Try_BB(int k, int n) {
    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            order[k] = i ;
            cost = cost + arr[order[k-1]-1][i-1];
            if (k == n) {
                if((cost + arr[order[n] - 1][order[1] - 1]) < f0) {
                    f0 = (cost + arr[order[n] - 1][order[1] - 1]);
                        final_value = cost+arr[order[n] - 1][order[1] - 1];
                        for (int i = 1; i <= n; i++) {
                            final[i] = order[i];
                        }
                }
            }
            else {
                if (cost + (n-k+1)*minCost < f0) Try_BB(k+1, n);
            }
            cost -= arr[order[k - 1]-1][i-1];
            visited[i] = false;
        }
    }
}


int main() {
    int n;
    cout << "Nhap so thanh pho ";
   
    cin >> n;
    clock_t start, end;

    generateRandomCost(arr, n);    
    for (int i = 1; i<=n; i++) {
        visited[i] = false;
    }
    for (int i = 0; i <= n; i++) {
        order[i] = 0;
    }
    
    order[1] = 1;
    visited[1] = true;
    start = clock();

    cout << "Chon thuat toan" << endl;
    cout << "1. Quay lui" << endl;
    cout << "2. Nhanh can" << endl;
    
    int choice;
    do {
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch(choice) {
            case 1:     
                start = clock();
                Try(2, n);
                end = clock();
                break;
            case 2:
                start = clock();
                Try_BB(2, n);
                end = clock();
                break;
        }
    } while (choice > 2 || choice < 1);

    double time_to_solve = (double)(end-start)/CLOCKS_PER_SEC;

    for (int i = 1; i <= n; i++) {
        cout << final[i]<<" ";
    }
    cout << 1 << " ";
    cout << final_value << endl;
    cout << time_to_solve;
}

