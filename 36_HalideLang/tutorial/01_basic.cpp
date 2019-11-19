#include <Halide/Halide.h>
#include <stdio.h>

int main (int argc, char **argv) 
{
    Halide::Func gradient;
    Halide::Var x,y; //x-cols,y-rows
    Halide::Expr e = x+y;
    
    gradient(x,y)=e;
    Halide::Buffer<int32_t> output = gradient.realize(800,600);

    for (int j=0; j<output.height(); j++){
	for (int i=0; i<output.width(); i++){
	
	    if (output(i,j) != i+j){
		printf("Something went wrong\n"
			"Pixel %d, %d was supposed to be %d, but instead it's %d\n",
			i, j, i+j, output(i,j));
    		return -1;	    
	    }
	}
    }
    printf("Succeess!\n");
    return 0;
}