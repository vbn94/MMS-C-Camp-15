int rectInfo(double w, double h, double* P, double *S){
    if (w <= 0 || h <= 0){
        return -1;
    }
    *P = (w + h) * 2;
    *S = w * h;
    return 0;
}