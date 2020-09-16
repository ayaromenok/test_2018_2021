export OPENCV_OPENCL_DEVICE=AMD:GPU:
~/sdk/build/opencv_pc/bin/opencv_perf_dnn > _perf_dnn_amd.txt
export OPENCV_OPENCL_DEVICE=NVIDIA:GPU:
~/sdk/build/opencv_pc/bin/opencv_perf_dnn > _perf_dnn_nv.txt

#DNN_BACKEND_VKCOM
#DNN_BACKEND_CUDA

#DNN_BACKEND_OPENCV

#DNN_TARGET_OPENCL
#DNN_TARGET_OPENCL_FP16
#DNN_TARGET_CPU
#DNN_TARGET_CUDA
#DNN_TARGET_CUDE_FP16
#export OPENCV_DNN_BACKEND=DNN_BACKEND_CUDA
#export OPENCV_DNN_TARGET=DNN_TARGET_CUDA
#export DNN_BACKEND=DNN_BACKEND_CUDA
#export DNN_TARGET=DNN_TARGET_CUDA

#~/sdk/build/opencv_pc/bin/opencv_perf_dnn 