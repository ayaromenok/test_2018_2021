## Performance


| resolution | RPI3 | TegraK1 | Rk3399 | X230 |
| --- | --- | --- | --- | --- |
| cpu/512 | 10.66 | 7.52 | 12.92 | 2.61 | 
| gpu/512 | - | - | - | 2.75 | 
| cpu/1k | 33.85 | 23.65 | 31.71 | 10.10 | 
| gpu/1k | - | - | - | 4.48 | 
| cpu/2k | 127.01 | 82.18 | 89.45 | 30.30 | 
| gpu/2k | - | - | - | 16.59 |
| cpu/4k | 526.543 | 330.84 | 305.52 | 105.978 | 
| gpu/4k | - | - | - | 65.08 |

## errors

- RaspberryPi 3 don't have CL/CUDA
- RK3399/armMali T860
error with max group size on Arm Mali - need to report to OpenCV
`OpenCL error CL_OUT_OF_RESOURCES (-5) during call: clEnqueueNDRangeKernel('row_filter_C1_D0', dims=2, globalsize=512x2064x1, localsize=16x16x1) sync=false`
`OpenCL error CL_OUT_OF_RESOURCES (-5) during call: clEnqueueNDRangeKernel('stage1_with_sobel', dims=2, globalsize=2048x2048x1, localsize=32x8x1) sync=false`
- TegraK1
 issue with POCL load: `Failed to load OpenCL runtime (expected version 1.1+)`
