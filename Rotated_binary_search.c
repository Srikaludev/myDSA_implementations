#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud_record{
    int roll_no;
    char name[20];
    float marks[3];
};

struct stud_record * record_search(struct stud_record * record_array[], int n, int roll){ 
    int low = 0,high = n-1;
    while (low <= high){
        int mid = (low + high)/2;
        if (record_array[mid]->roll_no == roll){
            return record_array[mid];
        }
        else if (record_array[mid]->roll_no < roll){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return NULL;
}

int binarySearch(int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;
 
    int mid = (low + high) / 2;
    if (key == arr[mid])
        return mid;
 
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
 
    return binarySearch(arr, low, (mid - 1), key);
}

int modified_binary_search(int arr[], int n, int key, int k) {
    if (k == -1)
        return binarySearch(arr,0,n-1,key);
    if (arr[k] == key)
        return k;
    if (arr[0] <= key)
        return binarySearch(arr,0,k-1,key);
    else 
        return binarySearch(arr,k+1,n-1,key);
} 

int main(){
    struct stud_record a = {3,"xyz",{0.1,0.2,0.3}};
    struct stud_record b = {2,"yz",{0.2,0.3,0.4}};
    struct stud_record c = {1,"z",{0.5,0.6,0.7}};

    struct stud_record *records[] = {&a,&b,&c};

    int n = 3;

    int search_roll = 3;
    struct stud_record *found_record = record_search(records, n, search_roll);

    if (found_record == NULL) {
        printf("Record with roll number %d not found.\n", search_roll);
    } else {
        printf("Record with roll number %d found: %s\n", found_record->roll_no, found_record->name);
    }

    int arr[]={3,4,5,6,1,2};
    int k = 4;
    int x = sizeof(arr)/sizeof(arr[0]);
    int key = 4;
    int ans = modified_binary_search(arr,x,key,k);
    if (ans != -1){
        printf("The index at which the key is present is %d \n",ans);
    }
    else printf("The element is not present in the array\n");
    return 0;
}