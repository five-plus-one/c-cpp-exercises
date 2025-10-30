#include<stdio.h>
struct t {
    int x;
    int y;
    int z;
};
void swap(struct t *ps1,struct t *ps2){
    struct t tmp;
    tmp = *ps1;
    *ps1 = *ps2;
    *ps2 = tmp;
}
int main(){
    struct t a[10];
    a[0].x = 1;
    a[0].y = 2;
    a[0].z = 3;
    a[1].x = 4;
    a[1].y = 5;
    a[1].z = 6;
    swap(&a[0],&a[1]);
    printf("a[0] .x=%d .y=%d .z=%d\na[1] .x=%d .y=%d .z=%d",a[0].x,a[0].y,a[0].z,a[1].x,a[1].y,a[1].z);
    return 0;
}