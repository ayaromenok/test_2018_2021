#include <Halide/Halide.h>
#include <Halide/halide_image_io.h>
#include <stdio.h>

using namespace Halide::Tools;

int main (int argc, char **argv)
{
    Halide::Buffer<uint8_t> input = load_image("../images/rgb.png");

    save_image(input, "brighter.png");
    return 0;
}
