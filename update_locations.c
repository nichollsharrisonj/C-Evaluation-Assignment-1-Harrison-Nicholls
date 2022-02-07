#include "update_locations.h"
// Create a list of 'size' floating point numbers in the range [-bound, bound]
def_type* generate_random_list(int size, int bound) {
        int seed = size;
        srand((unsigned) seed);
        def_type* list = (def_type*)malloc(size * sizeof(def_type));
        for(int  i = 0 ; i < size; i++) {
                float zero_to_one = rand()/ (float)RAND_MAX;
                float randresult = (zero_to_one * 2 * bound) - bound;      
                list[i] = randresult;
        }
        return list; 
}


//Update position by velocity, one time-step. Does not need to return 
void update_coords(def_type* xs, def_type* ys, def_type* zs, def_type* vx, def_type* vy, def_type* vz, int size){
        for (int i = 0; i < size; i++){
                xs[i] = xs[i] + vx[i];
                ys[i] = ys[i] + vy[i];
                zs[i] = zs[i] + vz[i];               
        }
}

//Calculate sum of an arbitrary array, used for checksum
def_type sum(def_type* arr, int size){
        def_type sum = 0;
        for (int i = 0; i < size; i++){
                sum += (arr[i]);                
        }
        return sum;
}

//Take time of execution
double time_to_execute(def_type* xs, def_type* ys, def_type* zs, def_type* vx, def_type* vy, def_type* vz, int size){
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
        
        def_type* xs = generate_random_list(size, 1000.);
        def_type* ys = generate_random_list(size, 1000.);
        def_type* zs = generate_random_list(size, 1000.);
        def_type* vx = generate_random_list(size, 1.);
        def_type* vy = generate_random_list(size, 1.);
        def_type* vz = generate_random_list(size, 1.);


        for (int i = 0; i < iterations; i++){
                timetotal += time_to_execute(xs,ys,zs,vx,vy,vz,size);
                // printf("%.100ld \n",timetotal);
        }
        def_type chksum = sum(xs,size) + sum(ys,size) + sum(zs,size);
        printf("Mean time per coordinate: %.10f us\n",timetotal / (size * iterations));
        printf("Final checksum is: %f\n",chksum);
        return 0;
}


