## Performance


| resolution | RPI3 | TegraK1 | Rk3399 | X230 |
| --- | --- | --- | --- | --- |
| cpu/2k | 0 | 90 | 90 | 31 | 
| gpu/2k | 0 | CL load error | outOfRes | 18 |
| cpu/4k | 0 | 318 | 274 | 108 | 
| gpu/4k | 0 | CL load error | outOfRes | 68 |

## errors

- RK3399/armMali T860
error with max group size on Arm Mali - need to report to OpenCV
`OpenCL error CL_OUT_OF_RESOURCES (-5) during call: clEnqueueNDRangeKernel('row_filter_C1_D0', dims=2, globalsize=512x2064x1, localsize=16x16x1) sync=false`
`OpenCL error CL_OUT_OF_RESOURCES (-5) during call: clEnqueueNDRangeKernel('stage1_with_sobel', dims=2, globalsize=2048x2048x1, localsize=32x8x1) sync=false`

- TegraK1
 issue with POCL load: `Failed to load OpenCL runtime (expected version 1.1+)`
