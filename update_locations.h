#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


typedef float def_type;

def_type* generate_random_list(int size, int bound);

void update_coords(def_type* xs, def_type* ys, def_type* zs, def_type* vx, def_type* vy, def_type* vz, int size);

def_type sum(def_type* arr, int size);

double time_to_execute(def_type* xs, def_type* ys, def_type* zs, def_type* vx, def_type* vy, def_type* vz, int size);

int main(int argc, char* argv[]);
