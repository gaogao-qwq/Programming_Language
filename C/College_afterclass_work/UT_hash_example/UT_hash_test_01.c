#include <stdio.h>
#include "uthash.h"

typedef struct hashTable {
    int key;
    int val;
    UT_hash_handle hh;
}hashTable;

hashTable *hashtable;

hashTable *find(int _key) {
    hashTable *tmp;
    HASH_FIND_INT(hashtable, &_key, tmp);
    return tmp;
}

void insert (int _key, int _val) {
    hashTable *it = find(_key);
    if (it == NULL) {
        hashTable *tmp = malloc(sizeof(hashTable));
        tmp->key = _key, tmp->val = _val;
        HASH_ADD_INT(hashtable, key, tmp);
    }
    if (it != NULL) {
        it->val = _val;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    hashtable = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* it = find(target - nums[i]);
        if (it != NULL) {
            int* ret = malloc(sizeof(int) * 2);
            ret[0] = it->val, ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        insert(nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}

int main() {
    int nums[4] = {2, 7, 11, 15};
    int numsSize = 4;
    int target = 9;
    int returnSize;
    int *ret = malloc(sizeof(int) * returnSize);
    ret = twoSum(nums, numsSize, target, &returnSize);
    printf("%d%d", ret[0], ret[1]);
    return 0;
}