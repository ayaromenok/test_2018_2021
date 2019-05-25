Send videostream from Rpi(stereo in particular) to another devboards with suitable speed/quality

### Rpi

 - runRaspiVid_640x480.sh - ok
 - runRaspiVidStereo_1296x486.sh - ok
 - runMJpegStreamer - ok. no stereo
	[requre mjpg-streamer](https://github.com/jacksonliam/mjpg-streamer)
	can be lag, which rlated to network speed. 
	320x240 - 90fps on eth0
	640x480 - 30fps on eth0, less on wifi
	1296x972 - 15fps on eth0, around 10 on wifi
	2592x1944 - around 4-5fps on eth0
	
### Host

	- runVlc.sh/PC - looks like issues with some keyframes
	- runVlc.sh/Tegra - crash of vlc/cvlc
	- runMJpegStreamer - OK in browser. can handle many hosts.
		- added OpenCV version. any url should contain ".mjpg" prefix
