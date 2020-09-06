#	test RkISP repo
#git clone https://github.com/rockchip-linux/camera_engine_rkisp.git ~/sdk/src/camera_engine_rkisp

# 	replace config
rm ~/sdk/src/camera_engine_rkisp/productConfigs.mk
cp ./productConfigs.mk ~/sdk/src/camera_engine_rkisp/

cd ~/sdk/src/camera_engine_rkisp/

#git log > _log.txt
#replace hardcoded path to compiler
#git checkout 3fee8b50715804c49bbcc8097c909012e662be6b
#make -j 2

sudo cp ./build/lib/*so /usr/lib
sudo cp ./plugins/3a/rkiq/aec/lib64/librkisp_aec.so /usr/lib/rkisp/ae/librkisp_aec.so
sudo cp ./plugins/3a/rkiq/aaf/lib64/librkisp_af.so /usr/lib/rkisp/af/librkisp_af.so
sudo cp ./plugins/3a/rkiq/awb/lib64/librkisp_awb.so /usr/lib/rkisp/awb/librkisp_awb.so
#_rkisp_demo.sh 
