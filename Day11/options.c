#include <stdio.h>
#include <getopt.h>

int main(int argc, char **argv){
    int opt;
    while ((opt = getopt(argc, argv, ":b:ca")) != -1){
        switch (opt){
            case 'a': 
                printf("a = %s\n", optarg);
                break;
            case 'b': 
                printf("b = %s\n", optarg);
                break;
            case 'c': 
                printf("c = %s\n", optarg);
                break;
            case '?':
                printf("Unknown option: %c\n", optopt);
            break;
            case ':':
                printf("Missing arg for %c\n", optopt);
            break;
        }
    }
    return 0;
}