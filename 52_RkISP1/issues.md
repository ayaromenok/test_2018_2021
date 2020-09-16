 Usage: ./rkisp_3A_server to start 3A engine
         --mmedia,  required, mapped media device node
         --silent,  optional, subpress debug lo

error:"
./rkisp_3A_server --mmedia=/dev/media0
media get entity by name: stream_cif is null
media get entity by name: stream_cif_dvp is null
get rkisp1_mainpath devname: /dev/video0
get rkisp1_selfpath devname: /dev/video1
get rkisp1-isp-subdev devname: /dev/v4l-subdev0
get rkisp1-input-params devname: /dev/video4
get rkisp1-statistics devname: /dev/video3
current sensor name, ov4689 1-0036
sensor/lens/flash entity name format is incorrect,pls check driver version !
ERR: Bad media topology
 error 22, Invalid argument
"

4.4.179: driver name is "ov4689 1-0036":0 [ENABLED]
rksip required: m00_b_ob4689 1-0034 - `m` and first `_` is tested

cam driver driver - kernel/drivers/media/i2c/ov4689.c

rkisp version - rkisp_dev_manager.h

//kernel drivers
  CC      drivers/media/i2c/soc_camera/rockchip/ov_camera_module.o 
  CC      drivers/media/i2c/soc_camera/rockchip/ov4689_v4l2-i2c-subdev.o
  CC      drivers/media/i2c/soc_camera/rockchip/ov13850_v4l2-i2c-subdev.o
  LD      drivers/media/i2c/soc_camera/rockchip/built-in.o
  LD      drivers/media/i2c/soc_camera/built-in.o
  CC      drivers/media/i2c/ov4689.o
  CC      drivers/media/i2c/ov13850.o
  LD      drivers/media/i2c/built-in.o

