#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 6
#define MAX_QUEUE_SIZE 100
#define node_num 7

void titleDraw();
void selectDraw();
void menuDraw();
void sortDraw();
void graphDraw();
void treeDraw();
void exitDraw();
void errorDraw();

void insertionSort();
void selectionSort();
void bubbleSort();
void merge();
void mergeSort();
void swap();
int partition();
void quickSort();
void maxHeapify();
void heapSort();
int getMax();
void countingSort();
void radixSort();
void printGraph();
void printStep();
void DFS();
void enqueue();
int dequeue();
void BFS();
int find();
void unionSets();
int compareEdges();
void kruskal();
int minKey();
void printMST();
void printPrimProcess();
void primMST();
void printGraphState();
void printStep2();
void printInitialData();
void topologicalSort();
void set_node();
void preorder();
void inorder();
void postorder();

int visited[MAX_VERTICES];
int order[MAX_VERTICES]; // 노드 방문 순서를 저장하는 배열
int orderIndex = 0;
int graph[MAX_VERTICES][MAX_VERTICES] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 1, 1},
    {0, 1, 1, 1, 0, 1},
    {0, 0, 0, 1, 1, 0}
};
int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

// 간선을 나타내는 구조체
typedef struct {
    int start, end, weight;
} Edge;

typedef struct {
    int indegree;
    int visited;
    int adjacent[MAX_VERTICES];
} Vertex;

// node struct
typedef struct node
{
    char alphabet;  // alphabet
    struct node* left;  // left child node
    struct node* right; // right child node
} node;

// 그래프의 간선들을 저장하는 배열
Edge edges[MAX_VERTICES * MAX_VERTICES];

int parent[MAX_VERTICES];


int main() {
    int input = 0;
    int n;
    int arr[20];

select_Screen: {
    system("cls");
    selectDraw();
    scanf_s("%d", &input);
    }

menu_Screen: {
if (input == 1) {
    system("cls");
    menuDraw();
}
else if (input == 2) {
    system("cls");
    exitDraw();
    return 0;
}
else if (input == 0) {
    goto select_Screen;
}
else {
    system("cls");
    printf("[입력오류!]\n");
    exitDraw();
    return 0;
}
}

scanf_s("%d", &input);

while (1) {
    if (input == 1) {
        system("cls");
        sortDraw();
        goto sort;
    }
    else if (input == 2) {
        system("cls");
        graphDraw();
        goto graph;
    }
    else if (input == 3) {
        system("cls");
        treeDraw();
        goto tree;
    }
    else if (input == 0) {
        goto menu_Screen;
    }
    else {
        system("cls");
        errorDraw();
        return 0;
    }
}

sort: {
scanf_s("%d", &input);

while (1) {

    if (input == 1) {
        system("cls");
        printf("[선택 정렬]\n");

        printf("\n배열의 길이를 입력하세요: ");
        scanf_s("%d", &n);

        printf("배열의 요소를 입력하세요: ");
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &arr[i]);
        }

        system("cls");

        printf("정렬 전 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n[과정]\n");

        selectionSort(arr, n);

        printf("\n선택 정렬 후 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        goto backtoMain;

    }
    else if (input == 2) {
        system("cls");
        printf("[삽입 정렬]\n");

        printf("\n배열의 길이를 입력하세요: ");
        scanf_s("%d", &n);

        printf("배열의 요소를 입력하세요: ");
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &arr[i]);
        }

        system("cls");

        printf("정렬 전 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n[과정]\n");

        insertionSort(arr, n);

        printf("\n삽입 정렬 후 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        goto backtoMain;
    }
    else if (input == 3) {
        system("cls");
        printf("[버블 정렬]\n");

        printf("\n배열의 길이를 입력하세요: ");
        scanf_s("%d", &n);

        printf("배열의 요소를 입력하세요: ");
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &arr[i]);
        }

        system("cls");

        printf("정렬 전 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n[과정]\n");

        bubbleSort(arr, n);

        printf("\n버블 정렬 후 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        goto backtoMain;
    }
    else if (input == 4) {
        system("cls");
        printf("[병합 정렬]\n");

        int n;
        printf("배열의 길이를 입력하세요: ");
        scanf_s("%d", &n);

        int* arr = (int*)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("메모리 할당 오류\n");
            return 1;
        }

        printf("배열의 요소를 입력하세요: ");
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &arr[i]);
        }

        system("cls");

        printf("정렬 전 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        printf("\n\n[과정]\n");

        mergeSort(arr, 0, n - 1);

        printf("\n병합 정렬 후 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        free(arr);

        goto backtoMain;
    }
    else if (input == 5) {

        system("cls");
        printf("[퀵 정렬]\n");

        printf("배열의 길이를 입력하세요: ");
        scanf_s("%d", &n);


        int* arr = (int*)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("메모리 할당 오류\n");
            return 1;
        }

        printf("배열의 요소를 입력하세요: ");
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &arr[i]);
        }

        system("cls");

        printf("정렬 전 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n[과정]\n");

        quickSort(arr, 0, n - 1);

        printf("\n퀵 정렬 후 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        free(arr);

        goto backtoMain;
    }
    else if (input == 6) {
        system("cls");
        printf("[힙 정렬]\n");

        printf("배열의 길이를 입력하세요: ");
        scanf_s("%d", &n);


        printf("배열의 요소를 입력하세요: ");
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &arr[i]);
        }

        system("cls");

        printf("정렬 전 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        printf("\n\n[과정]\n");

        heapSort(arr, n);

        printf("\n힙 정렬 후 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        goto backtoMain;
    }
    else if (input == 7) {
        system("cls");
        printf("[기수 정렬]\n");

        printf("\n배열의 길이를 입력하세요: ");
        scanf_s("%d", &n);

        printf("배열의 요소를 입력하세요: ");
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &arr[i]);
        }

        system("cls");

        printf("정렬 전 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n[과정]\n");

        radixSort(arr, n);

        printf("\n기수 정렬 후 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        goto backtoMain;
    }
    else if (input == 0) {
        input = 1;
        goto menu_Screen;
    }
    else {
        system("cls");
        errorDraw();
        return 0;
    }
}
}

graph: {
scanf_s("%d", &input);

while (1) {

    if (input == 1) {
        system("cls");

        printf("[깊이 우선 탐색 알고리즘]\n\n");

        printGraph(MAX_VERTICES);

        printf("깊이 우선 탐색 결과:\n");
        DFS(0, MAX_VERTICES);

        printf("\n");
        printf("최종 순서: ");
        for (int i = 0; i < MAX_VERTICES; i++) {
            printf("%d ", order[i]);
        }
        printf("\n");

        goto backtoMain;

    }
    else if (input == 2) {
        system("cls");

        printf("[너비 우선 탐색 알고리즘]\n\n");

        printGraph(MAX_VERTICES);

        printf("너비 우선 탐색 결과:\n");
        BFS(0, MAX_VERTICES);

        printf("\n");
        printf("최종 순서: ");
        for (int i = 0; i < MAX_VERTICES; i++) {
            printf("%d ", order[i]);
        }
        printf("\n");

        goto backtoMain;
    }
    else if (input == 3) {
        system("cls");

        printf("[크루스칼 알고리즘]");

        Edge graph[MAX_VERTICES * MAX_VERTICES] = {
         {0, 1, 1}, {0, 2, 1}, {1, 2, 2}, {1, 3, 3}, {2, 3, 4}, {2, 4, 3}, {3, 4, 5}, {3, 5, 6}, {4, 5, 2}
        };

        int vertices = 6;
        int edgesCount = 9;

        printf("입력 그래프의 간선들:\n");
        for (int i = 0; i < edgesCount; i++) {
            printf("(%d, %d) - 가중치: %d\n", graph[i].start, graph[i].end, graph[i].weight);
        }

        printf("\n크루스칼 알고리즘 결과:\n\n");
        kruskal(graph, vertices, edgesCount);

        printf("\n");

        goto backtoMain;
    }
    else if (input == 4) {
        system("cls");

        printf("[프림 알고리즘]\n");

        printf("프림 알고리즘 결과:\n");
        primMST();

        goto backtoMain;
    }
    else if (input == 5) {
        system("cls");

        printf("[위상 정렬 알고리즘]\n\n");

        Vertex vertices[MAX_VERTICES];
        topologicalSort(vertices, MAX_VERTICES);
        
        goto backtoMain;
    }
    else if (input == 0) {
        input = 1;
        goto menu_Screen;
    }
    else {
        system("cls");
        errorDraw();
        return 0;
    }
}


}

tree: {
scanf_s("%d", &input);

while (1) {
    if (input == 1) {
        system("cls");

        printf("[이진 탐색 트리]\n\n");

        int i;
        node* arr_node[node_num];
        for (i = 0; i < node_num; i++)
            arr_node[i] = (node*)malloc(sizeof(node));

        set_node(arr_node[0], 'A', NULL, NULL);
        set_node(arr_node[1], 'B', arr_node[0], NULL);
        set_node(arr_node[2], 'C', arr_node[1], arr_node[4]);
        set_node(arr_node[3], 'D', NULL, NULL);
        set_node(arr_node[4], 'E', arr_node[3], arr_node[5]);
        set_node(arr_node[5], 'F', NULL, arr_node[6]);
        set_node(arr_node[6], 'G', NULL, NULL);

        printf("초기 값: A B C B D E F G");

        printf("\n\n전위 순회 : ");
        preorder(arr_node[2]);  // 'C' is the root
        printf("\n중위 순회 : ");
        inorder(arr_node[2]);   // 'C' is the root
        printf("\n후위 순회 : ");
        postorder(arr_node[2]); // 'C' is the root

        goto backtoMain;
    }
    else if (input == 2) {
        system("cls");

        printf("[백 트래킹]\n\n");

        printf("구현 실패!");

        goto backtoMain;
    }
    else if (input == 3) {
        system("cls");

        printf("[A* 알고리즘]\n\n");

        printf("구현 실패!");

        goto backtoMain;
    }
    else if (input == 4) {
        system("cls");

        printf("[유전자 알고리즘]\n\n");

        printf("구현 실패!");

        goto backtoMain;
    }
    else if (input == 0) {
        input = 1;
        goto menu_Screen;
    }
    else {
        system("cls");
        errorDraw();
        return 0;
    }
}

}
//메인으로 돌아가기 선택 코드
backtoMain: {
printf("\n\n");
printf("1. 메인화면\n2. 종료\n");
scanf_s("%d", &input);
}

switch (input) {
case 1:
    goto select_Screen;
case 2:
    system("cls");
    exitDraw();
    return 0;
default:
    system("cls");
    errorDraw();
    return 0;
}
}




void titleDraw() {
    printf("\n\n");
    printf("   ###    ##        ######    #######  ########  #### ######## ##     ## ##     ## \n");
    printf("  ## ##   ##       ##    ##  ##     ## ##     ##  ##     ##    ##     ## ###   ### \n");
    printf(" ##   ##  ##       ##        ##     ## ##     ##  ##     ##    ##     ## #### #### \n");
    printf("##     ## ##       ##   #### ##     ## ########   ##     ##    ######### ## ### ## \n");
    printf("######### ##       ##    ##  ##     ## ##   ##    ##     ##    ##     ## ##     ## \n");
    printf("##     ## ##       ##    ##  ##     ## ##    ##   ##     ##    ##     ## ##     ## \n");
    printf("##     ## ########  ######    #######  ##     ## ####    ##    ##     ## ##     ## \n");
    printf("\n\n");
}

void selectDraw() {
    titleDraw();
    printf("1. 시작\n2. 나가기\n");
}

void menuDraw() {
    titleDraw();
    printf("0. 돌아가기\n1. 정렬\n2. 그래프\n3. 트리\n");
}

void sortDraw() {
    titleDraw();
    printf("0. 돌아가기\n1. 선택 정렬\n2. 삽입 정렬\n3. 버블 정렬\n4. 병합 정렬\n5. 퀵 정렬\n6. 힙 정렬\n7. 기수 정렬\n");
}

void graphDraw() {
    titleDraw();
    printf("0. 돌아가기\n1. 깊이 우선 탐색\n2. 너비 우선 탐색\n3. 크루스칼\n4. 프림\n5. 위상 정렬\n");
}

void treeDraw() {
    titleDraw();
    printf("0. 돌아가기\n1. 이진 탐색\n2. 백 트래킹\n3. A*\n4. 유전자\n");
}

void exitDraw() {
    printf("\n\n");
    printf("######## ##     ##    ###    ##    ## ##    ##    ##    ##  #######  ##     ##\n");
    printf("   ##    ##     ##   ## ##   ###   ## ##   ##      ##  ##  ##     ## ##     ##\n");
    printf("   ##    ##     ##  ##   ##  ####  ## ##  ##        ####   ##     ## ##     ##\n");
    printf("   ##    ######### ##     ## ## ## ## #####          ##    ##     ## ##     ##\n");
    printf("   ##    ##     ## ######### ##  #### ##  ##         ##    ##     ## ##     ##\n");
    printf("   ##    ##     ## ##     ## ##   ### ##   ##        ##    ##     ## ##     ##\n");
    printf("   ##    ##     ## ##     ## ##    ## ##    ##       ##     #######   ####### \n");
    printf("\n\n");
}

void errorDraw() {
    printf("\n\n");
    printf("######## ########  ########   #######  ########  \n");
    printf("##       ##     ## ##     ## ##     ## ##     ## \n");
    printf("##       ##     ## ##     ## ##     ## ##     ## \n");
    printf("######   ########  ########  ##     ## ########  \n");
    printf("##       ##   ##   ##   ##   ##     ## ##   ##   \n");
    printf("##       ##    ##  ##    ##  ##     ## ##    ##  \n");
    printf("######## ##     ## ##     ##  #######  ##     ## \n");
    printf("\n\n");
}

//삽입정렬
void insertionSort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // key보다 큰 요소를 오른쪽으로 이동
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // 각 회전마다 배열 상태 출력
        printf("%d 회전: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

//선택정렬
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // 최솟값을 현재 위치로 이동
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        // 각 회전마다 배열 상태 출력
        printf("%d 회전: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

//버블정렬
void bubbleSort(int arr[], int n) {
    int temp, swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0; // 초기에는 교환이 이루어지지 않았다고 가정

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 현재 원소가 다음 원소보다 큰 경우 교환
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // 교환이 이루어졌음을 표시
            }
        }

        // 각 회전마다 배열 상태 출력
        printf("%d 회전: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");

        // 모든 교환이 이루어지지 않았을 경우 루프 종료
        if (swapped == 0) {
            break;
        }
    }
}

//두개의 배열을 병합하는 코드
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 임시 배열 동적 할당
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // 메모리 할당이 성공적인지 확인
    if (L == NULL || R == NULL) {
        // 메모리 할당 실패 시 처리
        // 예를 들어, 오류 반환하거나 프로그램 종료
        return;
    }

    // 데이터를 임시 배열로 복사
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // 병합 단계
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 남은 요소 복사
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // 동적으로 할당한 메모리 해제
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);

        // 각 회전마다 배열 상태 출력
        printf("정렬 상태: ");
        for (int i = left; i <= right; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

//배열의 특정 요소를 교환하는 코드
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 피벗을 기준으로 배열을 분할하고 피벗의 인덱스를 반환
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

//퀵 정렬
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // 각 회전마다 배열 상태 출력
        printf("피벗: %d, 배열: ", arr[pi]);
        for (int i = low; i <= high; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 최대 힙을 구성하는 함수
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

//힙 정렬
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, i, 0);

        // 각 회전마다 배열 상태 출력
        printf("회전 %d: ", n - i);
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
}

// 배열에서 최대값을 찾는 함수
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 기수 정렬을 위한 카운팅 정렬 함수
void countingSort(int arr[], int n, int exp) {
    const int RANGE = 10;

    int output[20];
    int count[10] = { 0 };

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % RANGE]++;
    }

    for (int i = 1; i < RANGE; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % RANGE] - 1] = arr[i];
        count[(arr[i] / exp) % RANGE]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// 기수 정렬 알고리즘
void radixSort(int arr[], int n) {
    int a = 1;
    int max = getMax(arr, n);

    // 자릿수에 따라 counting sort를 반복
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);

        // 정렬된 결과 출력
        printf("%d 회전: ", a);
        a++;

        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

    }

}

void printGraph(int vertices) {
    printf("초기 상태의 그래프:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printStep(int vertex) {
    printf("현재 노드: %d\n", vertex);
    order[orderIndex++] = vertex; // 노드 방문 순서 저장
}

void DFS(int vertex, int vertices) {
    visited[vertex] = 1;
    printStep(vertex);

    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            printf("인접 노드로 이동: %d\n", i);
            DFS(i, vertices);
        }
    }
}

void enqueue(int vertex) {
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = vertex;
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    int vertex = queue[front];
    front++;
    if (front > rear) {
        front = rear = -1;
    }
    return vertex;
}

void BFS(int startVertex, int vertices) {
    visited[startVertex] = 1;
    enqueue(startVertex);

    while (front != -1) {
        int currentVertex = dequeue();
        printStep(currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

// 부모를 찾는 함수
int find(int vertex) {
    while (parent[vertex] != -1) {
        vertex = parent[vertex];
    }
    return vertex;
}

// 두 집합을 합치는 함수
void unionSets(int root1, int root2) {
    parent[root1] = root2;
}

// 간선 비교 함수 (가중치를 기준으로 오름차순 정렬)
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void kruskal(Edge graph[], int vertices, int edgesCount) {
    // 간선들을 가중치를 기준으로 정렬
    qsort(graph, edgesCount, sizeof(Edge), compareEdges);

    // 모든 노드를 독립적인 집합으로 초기화
    for (int i = 0; i < vertices; i++) {
        parent[i] = -1;
    }

    int selectedEdges = 0; // 선택된 간선의 수
    int index = 0; // 현재 고려 중인 간선의 인덱스

    printf("최소 신장 트리의 간선들:\n");

    // 간선이 (V-1)개가 될 때까지 반복
    while (selectedEdges < vertices - 1) {
        int root1 = find(graph[index].start);
        int root2 = find(graph[index].end);

        // 두 노드가 서로 다른 집합에 속해있다면 합치고 출력
        if (root1 != root2) {
            printf("(%d, %d) - 가중치: %d\n", graph[index].start, graph[index].end, graph[index].weight);
            unionSets(root1, root2);
            selectedEdges++;
        }

        index++;
    }
}

//프림 알고리즘
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < MAX_VERTICES; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int n) {
    printf("최소 신장 트리의 간선들:\n");
    for (int i = 1; i < MAX_VERTICES; i++) {
        printf("(%d, %d) - 가중치: %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void printPrimProcess(int parent[], int key[], int mstSet[], int currentStep) {
    printf("Step %d:\n", currentStep);
    printf("노드    키 값    부모 노드\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (mstSet[i]) {
            if (key[i] == INT_MAX) {
                printf("%d       -          -\n", i);
            }
            else {
                printf("%d       %d         %d\n", i, key[i], parent[i]);
            }
        }
        else {
            printf("%d       -          -\n", i);
        }
    }
    printf("\n");
}

void primMST() {
    int parent[MAX_VERTICES]; // 최소 신장 트리의 부모 노드
    int key[MAX_VERTICES];    // 각 노드의 키 값
    int mstSet[MAX_VERTICES]; // 최소 신장 트리에 속한 노드인지 여부

    // 모든 키 값을 INT_MAX로 초기화하고, 최소 신장 트리에 속한 노드를 0으로 초기화
    for (int i = 0; i < MAX_VERTICES; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // 첫 번째 노드를 시작 노드로 선택
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < MAX_VERTICES - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        printPrimProcess(parent, key, mstSet, count + 1); // 각 단계별로 출력

        for (int v = 0; v < MAX_VERTICES; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // 최종 결과만 출력
    printMST(parent, MAX_VERTICES);
}
//위상정렬 알고리즘
void printGraphState(Vertex vertices[], int verticesCount) {
    printf("정점    진입 차수    방문 여부\n");
    for (int k = 0; k < verticesCount; k++) {
        printf("%d       %d             %d\n", k, vertices[k].indegree, vertices[k].visited);
    }
    printf("\n");
}

void printStep2(int step) {
    printf("Step %d:\n", step);
}

void printInitialData(Edge edges[], int edgesCount) {
    printf("초기 데이터:\n");
    printf("간선    출발 정점    도착 정점\n");
    for (int i = 0; i < edgesCount; i++) {
        printf("%d       %d             %d\n", i, edges[i].start, edges[i].end);
    }
    printf("\n");
}

void topologicalSort(Vertex vertices[], int verticesCount) {
    int result[MAX_VERTICES];
    int resultIndex = 0;

    Edge edges[] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {0, 2}, {1, 3}, {3, 5}
    };
    int edgesCount = sizeof(edges) / sizeof(edges[0]);

    printInitialData(edges, edgesCount);

    for (int i = 0; i < verticesCount; i++) {
        vertices[i].indegree = 0;
        vertices[i].visited = 0;
        for (int j = 0; j < verticesCount; j++) {
            vertices[i].adjacent[j] = -1;
        }
    }

    for (int i = 0; i < edgesCount; i++) {
        int start = edges[i].start;
        int end = edges[i].end;
        vertices[start].adjacent[vertices[start].indegree++] = end;
    }

    printf("초기 상태:\n");
    printGraphState(vertices, verticesCount);

    for (int i = 0; i < verticesCount; i++) {
        if (vertices[i].indegree == 0 && !vertices[i].visited) {
            result[resultIndex++] = i;
            vertices[i].visited = 1;

            for (int j = 0; j < verticesCount; j++) {
                int adjVertex = vertices[i].adjacent[j];
                if (adjVertex != -1) {
                    vertices[adjVertex].indegree--;
                }
            }

            printStep2(resultIndex);
            printGraphState(vertices, verticesCount);
        }
    }

    printf("최종 위상 정렬 결과:\n");
    for (int i = 0; i < resultIndex; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

// 노드 정보 설정
void set_node(node* n, char alphabet, node* left, node* right)
{
    n->alphabet = alphabet;
    n->left = left;
    n->right = right;
}

// 전위
void preorder(node* root)
{
    if (root != NULL)
    {
        printf("%c ", root->alphabet); // print node
        preorder(root->left);           // left child
        preorder(root->right);          // right child
    }
}

// 중위
void inorder(node* root)
{
    if (root != NULL)
    {
        inorder(root->left);            // left child
        printf("%c ", root->alphabet);  // print node
        inorder(root->right);           // right child
    }
}

// 후위
void postorder(node* root)
{
    if (root != NULL)
    {
        postorder(root->left);          // left child
        postorder(root->right);         // right child
        printf("%c ", root->alphabet);  // print node
    }
}