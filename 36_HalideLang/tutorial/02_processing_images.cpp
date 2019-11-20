#include <Halide/Halide.h>
#include <Halide/halide_image_io.h>
#include <stdio.h>

using namespace Halide::Tools;

int main (int argc, char **argv)
{
    Halide::Buffer<uint8_t> input = load_image("../images/rgb.png");

    Halide::Func brighter;
    Halide::Var x,y,c;

    //line by line
    Halide::Expr value = input(x, y, c);
    value = Halide::cast<float>(value);
    value = value * 1.5f;
    value = Halide::min(value, 255.0f);
    value = Halide::cast<uint8_t>(value);
    brighter(x, y, c) = value;
    //single line
    //brighter(x, y, c) = Halide::cast<uint8_t>(min(input(x, y, c) * 1.5f, 255));
    Halide::Buffer<uint8_t> output = 
	brighter.realize(input.width(), input.height(), input.channels());
    save_image(output, "brighter.png");
    printf("success!\n");
    return 0;
}
