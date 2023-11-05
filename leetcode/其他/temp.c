/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define TABLE_SIZE 100 // 哈希表的大小，可以根据需要调整

// 哈希表中的元素结构
struct HashElement {
    int key;
    int value;
    int is_empty; // 用于标记是否为空槽位
};

// 哈希表结构
struct HashTable {
    struct HashElement* table[TABLE_SIZE];
};

// 创建并初始化哈希表
struct HashTable* createHashTable() {
    struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// 哈希函数，这里简单地使用取余操作
int hash(int key) {
    return key % TABLE_SIZE;
}

// 插入元素
void insert(struct HashTable* ht, int key, int value) {
    int index = hash(key);

    while (ht->table[index] != NULL && ht->table[index]->is_empty == 0) {
        // 线性探查，直到找到一个空槽位
        index = (index + 1) % TABLE_SIZE;
    }

    // 创建新元素并插入
    struct HashElement* new_element = (struct HashElement*)malloc(sizeof(struct HashElement));
    new_element->key = key;
    new_element->value = value;
    new_element->is_empty = 0;
    ht->table[index] = new_element;
}

// 查找元素，如果找到返回值，否则返回-1表示未找到
int find(struct HashTable* ht, int key) {
    int index = hash(key);

    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key && ht->table[index]->is_empty == 0) {
            return ht->table[index]->value;
        }
        index = (index + 1) % TABLE_SIZE;
    }

    return -1; // 未找到
}

// 删除元素
void delete(struct HashTable* ht, int key) {
    int index = hash(key);

    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key && ht->table[index]->is_empty == 0) {
            ht->table[index]->is_empty = 1; // 标记为空
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    }
}

// 释放哈希表内存
void destroyHashTable(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] != NULL) {
            free(ht->table[i]);
        }
    }
    free(ht);
}



int binarySearch(int* arr, int* begin, int length, int num){
    // 从升序序列arr中找到有几个小于等于 num 的元素，
    int left = *begin;
    int right = length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    *begin = right;
    return right + 1;
}

int cmp(const void* _a, const void* _b){
    int* a = (int*) _a;
    int* b = (int*) _b;
    return *a - *b;
}

int* fullBloomFlowers(int** flowers, int flowersSize, int* flowersColSize, int* people, int peopleSize, int* returnSize){
    // 二分查找，只需要知道 people[i] 的时候总共开了几朵花，谢了几朵花
    int* start = malloc(sizeof(int)*flowersSize);
    int* end = malloc(sizeof(int)*flowersSize);
    int* ret = malloc(sizeof(int)*peopleSize);

    for(int i = 0; i < flowersSize; i++){
        start[i] = flowers[i][0];
        end[i]   = flowers[i][1] + 1;
    }
    qsort(end, flowersSize, sizeof(int), cmp);
    qsort(start, flowersSize, sizeof(int), cmp);
    
    // 先将 people 数组排序，减少 binary search 的复杂度，填入哈希，最后再对排序前的 people 数组通过哈希表实现 O(1)
    // 如果 people 数组中有很多重复元素，这样做应该很高效，但是如果重复不多，就需要很大空间
    // 算了，数据量太大了，哈希表浪费空间

    // 试一下 哈希
    struct HashTable *ht = createHashTable();
    for(int i = 0; i < peopleSize; i++){
        ret[i] = people[i];
    }
    qsort(ret,peopleSize,sizeof(int),cmp);

    int begin1 = 0;
    int begin2 = 0;
    for(int i = 0; i < peopleSize; i++){
        if(find(ht, people[i]) != -1){
            int s = binarySearch(start, &begin1, flowersSize, ret[i]);
            int e = binarySearch(end, &begin2, flowersSize, ret[i]);
            insert(ht, ret[i], s - e);
        }
        else    continue;
    }

    *returnSize = 0;
    for(int i = 0; i < peopleSize; i++){
        ret[(*returnSize)++] = find(ht, people[i]);
    }

    free(start);
    free(end);
    destroyHashTable(ht);
    return ret;
}