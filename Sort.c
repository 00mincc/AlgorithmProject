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
int order[MAX_VERTICES]; // ��� �湮 ������ �����ϴ� �迭
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

// ������ ��Ÿ���� ����ü
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

// �׷����� �������� �����ϴ� �迭
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
    printf("[�Է¿���!]\n");
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
        printf("[���� ����]\n");

        printf("\n�迭�� ���̸� �Է��ϼ���: ");
        scanf_s("%d", &n);

        printf("�迭�� ��Ҹ� �Է��ϼ���: ");
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &arr[i]);
        }

        system("cls");

        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n[����]\n");

        selectionSort(arr, n);

        printf("\n���� ���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        goto backtoMain;

    }
    else if (input == 2) {
        system("cls");
        printf("[���� ����]\n");

        printf("\n�迭�� ���̸� �Է��ϼ���: ");
        scanf_s("%d", &n);

        printf("�迭�� ��Ҹ� �Է��ϼ���: ");
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &arr[i]);
        }

        system("cls");

        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n[����]\n");

        insertionSort(arr, n);

        printf("\n���� ���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        goto backtoMain;
    }
    else if (input == 3) {
        system("cls");
        printf("[���� ����]\n");

        printf("\n�迭�� ���̸� �Է��ϼ���: ");
        scanf_s("%d", &n);

        printf("�迭�� ��Ҹ� �Է��ϼ���: ");
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &arr[i]);
        }

        system("cls");

        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n[����]\n");

        bubbleSort(arr, n);

        printf("\n���� ���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        goto backtoMain;
    }
    else if (input == 4) {
        system("cls");
        printf("[���� ����]\n");

        int n;
        printf("�迭�� ���̸� �Է��ϼ���: ");
        scanf_s("%d", &n);

        int* arr = (int*)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("�޸� �Ҵ� ����\n");
            return 1;
        }

        printf("�迭�� ��Ҹ� �Է��ϼ���: ");
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &arr[i]);
        }

        system("cls");

        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        printf("\n\n[����]\n");

        mergeSort(arr, 0, n - 1);

        printf("\n���� ���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        free(arr);

        goto backtoMain;
    }
    else if (input == 5) {

        system("cls");
        printf("[�� ����]\n");

        printf("�迭�� ���̸� �Է��ϼ���: ");
        scanf_s("%d", &n);


        int* arr = (int*)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("�޸� �Ҵ� ����\n");
            return 1;
        }

        printf("�迭�� ��Ҹ� �Է��ϼ���: ");
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &arr[i]);
        }

        system("cls");

        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n[����]\n");

        quickSort(arr, 0, n - 1);

        printf("\n�� ���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        free(arr);

        goto backtoMain;
    }
    else if (input == 6) {
        system("cls");
        printf("[�� ����]\n");

        printf("�迭�� ���̸� �Է��ϼ���: ");
        scanf_s("%d", &n);


        printf("�迭�� ��Ҹ� �Է��ϼ���: ");
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &arr[i]);
        }

        system("cls");

        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        printf("\n\n[����]\n");

        heapSort(arr, n);

        printf("\n�� ���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        goto backtoMain;
    }
    else if (input == 7) {
        system("cls");
        printf("[��� ����]\n");

        printf("\n�迭�� ���̸� �Է��ϼ���: ");
        scanf_s("%d", &n);

        printf("�迭�� ��Ҹ� �Է��ϼ���: ");
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &arr[i]);
        }

        system("cls");

        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n[����]\n");

        radixSort(arr, n);

        printf("\n��� ���� �� �迭: ");
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

        printf("[���� �켱 Ž�� �˰���]\n\n");

        printGraph(MAX_VERTICES);

        printf("���� �켱 Ž�� ���:\n");
        DFS(0, MAX_VERTICES);

        printf("\n");
        printf("���� ����: ");
        for (int i = 0; i < MAX_VERTICES; i++) {
            printf("%d ", order[i]);
        }
        printf("\n");

        goto backtoMain;

    }
    else if (input == 2) {
        system("cls");

        printf("[�ʺ� �켱 Ž�� �˰���]\n\n");

        printGraph(MAX_VERTICES);

        printf("�ʺ� �켱 Ž�� ���:\n");
        BFS(0, MAX_VERTICES);

        printf("\n");
        printf("���� ����: ");
        for (int i = 0; i < MAX_VERTICES; i++) {
            printf("%d ", order[i]);
        }
        printf("\n");

        goto backtoMain;
    }
    else if (input == 3) {
        system("cls");

        printf("[ũ�罺Į �˰���]");

        Edge graph[MAX_VERTICES * MAX_VERTICES] = {
         {0, 1, 1}, {0, 2, 1}, {1, 2, 2}, {1, 3, 3}, {2, 3, 4}, {2, 4, 3}, {3, 4, 5}, {3, 5, 6}, {4, 5, 2}
        };

        int vertices = 6;
        int edgesCount = 9;

        printf("�Է� �׷����� ������:\n");
        for (int i = 0; i < edgesCount; i++) {
            printf("(%d, %d) - ����ġ: %d\n", graph[i].start, graph[i].end, graph[i].weight);
        }

        printf("\nũ�罺Į �˰��� ���:\n\n");
        kruskal(graph, vertices, edgesCount);

        printf("\n");

        goto backtoMain;
    }
    else if (input == 4) {
        system("cls");

        printf("[���� �˰���]\n");

        printf("���� �˰��� ���:\n");
        primMST();

        goto backtoMain;
    }
    else if (input == 5) {
        system("cls");

        printf("[���� ���� �˰���]\n\n");

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

        printf("[���� Ž�� Ʈ��]\n\n");

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

        printf("�ʱ� ��: A B C B D E F G");

        printf("\n\n���� ��ȸ : ");
        preorder(arr_node[2]);  // 'C' is the root
        printf("\n���� ��ȸ : ");
        inorder(arr_node[2]);   // 'C' is the root
        printf("\n���� ��ȸ : ");
        postorder(arr_node[2]); // 'C' is the root

        goto backtoMain;
    }
    else if (input == 2) {
        system("cls");

        printf("[�� Ʈ��ŷ]\n\n");

        printf("���� ����!");

        goto backtoMain;
    }
    else if (input == 3) {
        system("cls");

        printf("[A* �˰���]\n\n");

        printf("���� ����!");

        goto backtoMain;
    }
    else if (input == 4) {
        system("cls");

        printf("[������ �˰���]\n\n");

        printf("���� ����!");

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
//�������� ���ư��� ���� �ڵ�
backtoMain: {
printf("\n\n");
printf("1. ����ȭ��\n2. ����\n");
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
    printf("1. ����\n2. ������\n");
}

void menuDraw() {
    titleDraw();
    printf("0. ���ư���\n1. ����\n2. �׷���\n3. Ʈ��\n");
}

void sortDraw() {
    titleDraw();
    printf("0. ���ư���\n1. ���� ����\n2. ���� ����\n3. ���� ����\n4. ���� ����\n5. �� ����\n6. �� ����\n7. ��� ����\n");
}

void graphDraw() {
    titleDraw();
    printf("0. ���ư���\n1. ���� �켱 Ž��\n2. �ʺ� �켱 Ž��\n3. ũ�罺Į\n4. ����\n5. ���� ����\n");
}

void treeDraw() {
    titleDraw();
    printf("0. ���ư���\n1. ���� Ž��\n2. �� Ʈ��ŷ\n3. A*\n4. ������\n");
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

//��������
void insertionSort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // key���� ū ��Ҹ� ���������� �̵�
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // �� ȸ������ �迭 ���� ���
        printf("%d ȸ��: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

//��������
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // �ּڰ��� ���� ��ġ�� �̵�
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        // �� ȸ������ �迭 ���� ���
        printf("%d ȸ��: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

//��������
void bubbleSort(int arr[], int n) {
    int temp, swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0; // �ʱ⿡�� ��ȯ�� �̷������ �ʾҴٰ� ����

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // ���� ���Ұ� ���� ���Һ��� ū ��� ��ȯ
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // ��ȯ�� �̷�������� ǥ��
            }
        }

        // �� ȸ������ �迭 ���� ���
        printf("%d ȸ��: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");

        // ��� ��ȯ�� �̷������ �ʾ��� ��� ���� ����
        if (swapped == 0) {
            break;
        }
    }
}

//�ΰ��� �迭�� �����ϴ� �ڵ�
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // �ӽ� �迭 ���� �Ҵ�
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // �޸� �Ҵ��� ���������� Ȯ��
    if (L == NULL || R == NULL) {
        // �޸� �Ҵ� ���� �� ó��
        // ���� ���, ���� ��ȯ�ϰų� ���α׷� ����
        return;
    }

    // �����͸� �ӽ� �迭�� ����
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // ���� �ܰ�
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

    // ���� ��� ����
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

    // �������� �Ҵ��� �޸� ����
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);

        // �� ȸ������ �迭 ���� ���
        printf("���� ����: ");
        for (int i = left; i <= right; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

//�迭�� Ư�� ��Ҹ� ��ȯ�ϴ� �ڵ�
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// �ǹ��� �������� �迭�� �����ϰ� �ǹ��� �ε����� ��ȯ
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

//�� ����
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // �� ȸ������ �迭 ���� ���
        printf("�ǹ�: %d, �迭: ", arr[pi]);
        for (int i = low; i <= high; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// �ִ� ���� �����ϴ� �Լ�
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

//�� ����
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, i, 0);

        // �� ȸ������ �迭 ���� ���
        printf("ȸ�� %d: ", n - i);
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
}

// �迭���� �ִ밪�� ã�� �Լ�
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// ��� ������ ���� ī���� ���� �Լ�
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

// ��� ���� �˰���
void radixSort(int arr[], int n) {
    int a = 1;
    int max = getMax(arr, n);

    // �ڸ����� ���� counting sort�� �ݺ�
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);

        // ���ĵ� ��� ���
        printf("%d ȸ��: ", a);
        a++;

        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

    }

}

void printGraph(int vertices) {
    printf("�ʱ� ������ �׷���:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printStep(int vertex) {
    printf("���� ���: %d\n", vertex);
    order[orderIndex++] = vertex; // ��� �湮 ���� ����
}

void DFS(int vertex, int vertices) {
    visited[vertex] = 1;
    printStep(vertex);

    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            printf("���� ���� �̵�: %d\n", i);
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

// �θ� ã�� �Լ�
int find(int vertex) {
    while (parent[vertex] != -1) {
        vertex = parent[vertex];
    }
    return vertex;
}

// �� ������ ��ġ�� �Լ�
void unionSets(int root1, int root2) {
    parent[root1] = root2;
}

// ���� �� �Լ� (����ġ�� �������� �������� ����)
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void kruskal(Edge graph[], int vertices, int edgesCount) {
    // �������� ����ġ�� �������� ����
    qsort(graph, edgesCount, sizeof(Edge), compareEdges);

    // ��� ��带 �������� �������� �ʱ�ȭ
    for (int i = 0; i < vertices; i++) {
        parent[i] = -1;
    }

    int selectedEdges = 0; // ���õ� ������ ��
    int index = 0; // ���� ��� ���� ������ �ε���

    printf("�ּ� ���� Ʈ���� ������:\n");

    // ������ (V-1)���� �� ������ �ݺ�
    while (selectedEdges < vertices - 1) {
        int root1 = find(graph[index].start);
        int root2 = find(graph[index].end);

        // �� ��尡 ���� �ٸ� ���տ� �����ִٸ� ��ġ�� ���
        if (root1 != root2) {
            printf("(%d, %d) - ����ġ: %d\n", graph[index].start, graph[index].end, graph[index].weight);
            unionSets(root1, root2);
            selectedEdges++;
        }

        index++;
    }
}

//���� �˰���
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
    printf("�ּ� ���� Ʈ���� ������:\n");
    for (int i = 1; i < MAX_VERTICES; i++) {
        printf("(%d, %d) - ����ġ: %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void printPrimProcess(int parent[], int key[], int mstSet[], int currentStep) {
    printf("Step %d:\n", currentStep);
    printf("���    Ű ��    �θ� ���\n");
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
    int parent[MAX_VERTICES]; // �ּ� ���� Ʈ���� �θ� ���
    int key[MAX_VERTICES];    // �� ����� Ű ��
    int mstSet[MAX_VERTICES]; // �ּ� ���� Ʈ���� ���� ������� ����

    // ��� Ű ���� INT_MAX�� �ʱ�ȭ�ϰ�, �ּ� ���� Ʈ���� ���� ��带 0���� �ʱ�ȭ
    for (int i = 0; i < MAX_VERTICES; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // ù ��° ��带 ���� ���� ����
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < MAX_VERTICES - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        printPrimProcess(parent, key, mstSet, count + 1); // �� �ܰ躰�� ���

        for (int v = 0; v < MAX_VERTICES; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // ���� ����� ���
    printMST(parent, MAX_VERTICES);
}
//�������� �˰���
void printGraphState(Vertex vertices[], int verticesCount) {
    printf("����    ���� ����    �湮 ����\n");
    for (int k = 0; k < verticesCount; k++) {
        printf("%d       %d             %d\n", k, vertices[k].indegree, vertices[k].visited);
    }
    printf("\n");
}

void printStep2(int step) {
    printf("Step %d:\n", step);
}

void printInitialData(Edge edges[], int edgesCount) {
    printf("�ʱ� ������:\n");
    printf("����    ��� ����    ���� ����\n");
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

    printf("�ʱ� ����:\n");
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

    printf("���� ���� ���� ���:\n");
    for (int i = 0; i < resultIndex; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

// ��� ���� ����
void set_node(node* n, char alphabet, node* left, node* right)
{
    n->alphabet = alphabet;
    n->left = left;
    n->right = right;
}

// ����
void preorder(node* root)
{
    if (root != NULL)
    {
        printf("%c ", root->alphabet); // print node
        preorder(root->left);           // left child
        preorder(root->right);          // right child
    }
}

// ����
void inorder(node* root)
{
    if (root != NULL)
    {
        inorder(root->left);            // left child
        printf("%c ", root->alphabet);  // print node
        inorder(root->right);           // right child
    }
}

// ����
void postorder(node* root)
{
    if (root != NULL)
    {
        postorder(root->left);          // left child
        postorder(root->right);         // right child
        printf("%c ", root->alphabet);  // print node
    }
}