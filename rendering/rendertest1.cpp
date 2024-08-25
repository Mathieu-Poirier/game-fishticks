#include <stdio.h>
#include <stdlib.h>

int main(){


    int frame_count = 0;

    // TODO: struct of frame_arrays?

    

    char frame_array[] = "@@@@@@@\n@     @\n";

    while (frame_count < 100){
        fprintf(stdout, "%s", frame_array);
        frame_count++;
        system("clear");
    }

    return 0;
}