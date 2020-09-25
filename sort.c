#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    int x = strcmp(a,b);
    if(x>0)
        return 1;
    else
        return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
     int x = strcmp(a,b);
    if(x>0)
        return 0;
    else
        return 1;
}
int distinct(const char *a){
    int x[26],i;
    
    for(i = 0; i<26;i++){
        x[i] = 0;

    }
       
    for(i=0;a[i] != '\0'; i++){
        x[a[i] - 'a']++;
    }
    int count = 0;
    for(i=0;i<26;i++){
        if(x[i] >= 1)
            count++;
    }
    return count;
}
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int d1 = distinct(a), d2 = distinct(b);
    int  x = strcmp(a,b);
    if(d1>d2){
        return 1;
    }else if(d1 == d2){
        if(x>0)
            return 1;
         else
            return 0;
    }else{
        return 0;
    }
}

int sort_by_length(const char* a, const char* b) {
    int x = strlen(a), y = strlen(b), z = strcmp(a,b);
    
    if(x==y){
        if(z>0)
            return 1;
        else
            return 0;
    }else if(x>y){
        return 1;
    }else {
        return 0;
    }

}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
int i,j;
for(i=0;i<len;i++){
        for(j=0;j<len-1;j++){
            if(cmp_func(arr[j], arr[j+1])){
             char *temp;
            strcpy(temp, arr[j]);
             
            strcpy(arr[j], arr[j+1]);
            strcpy(arr[j+1], temp);

            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
    int i;
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}