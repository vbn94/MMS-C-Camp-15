# 1 "rect.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "rect.c"
int rectInfo(double w, double h, double* P, double *S){
    if (w <= 0 || h <= 0){
        return -1;
    }
    *P = (w + h) * 2;
    *S = w * h;
    return 0;
}
