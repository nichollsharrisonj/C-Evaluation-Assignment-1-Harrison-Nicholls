#include "update_locations.h"
// Create a list of 'size' floating point numbers in the range [-bound, bound]
vec_t* generate_random_list(int size, int bound) {
        int seed = size;
        srand((unsigned) seed);
        vec_t* list = (vec_t*)malloc(size * sizeof(vec_t));
        for(int  i = 0 ; i < size; i++) {
                float zero_to_one = rand()/ (float)RAND_MAX;
                float randresult = (zero_to_one * 2 * bound) - bound;      
                list[i] = randresult;
        }
        return list; 
}


//Update position by velocity, one time-step. Does not need to return 
void update_coords(vec_t* xs, vec_t* ys, vec_t* zs, vec_t* vx, vec_t* vy, vec_t* vz, int size){
        for (int i = 0; i < size; i++){
                xs[i] = xs[i] + vx[i];
                ys[i] = ys[i] + vy[i];
                zs[i] = zs[i] + vz[i];               
        }
}

//Calculate sum of an arbitrary array, used for checksum
vec_t sum(vec_t* arr, int size){
        vec_t sum = 0;
        for (int i = 0; i < size; i++){
                sum += (arr[i]);                
        }
        return sum;
}

//Take time of execution
double time_to_execute(vec_t* xs, vec_t* ys, vec_t* zs, vec_t* vx, vec_t* vy, vec_t* vz, int size){
        double time;

        clock_t start = clock();
        update_coords(xs,ys,zs,vx,vy,vz,size);
        clock_t end = clock();

        time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000;

        return (time);
}



//Main
int main(int argc, char* argv[]) {


        if (argc != 3) {
                printf("Expected 2 arguments: num objects, and num iterations");
                return 0;
        }
        int size = atoi(argv[1]);
        int iterations = atoi(argv[2]);
        //printf("Size: %d, Iterations: %d \n", size, iterations);

        double timetotal = 0;
        
        vec_t* xs = generate_random_list(size, 1000.);
        vec_t* ys = generate_random_list(size, 1000.);
        vec_t* zs = generate_random_list(size, 1000.);
        vec_t* vx = generate_random_list(size, 1.);
        vec_t* vy = generate_random_list(size, 1.);
        vec_t* vz = generate_random_list(size, 1.);


        for (int i = 0; i < iterations; i++){
                timetotal += time_to_execute(xs,ys,zs,vx,vy,vz,size);
                // printf("%.100ld \n",timetotal);
        }
        //vec_t chksum = sum(xs,size) + sum(ys,size) + sum(zs,size);
        printf("Mean time per coordinate: %.10f us\n",timetotal / (size * iterations));
        // printf("Final checksum is: %f\n",chksum);
        return 0;
}


