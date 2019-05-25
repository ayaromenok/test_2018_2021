Send videostream from Rpi(stereo in particular) to another devboards with suitable speed/quality

### Rpi

 - runRaspiVid_640x480.sh - ok
 - runRaspiVidStereo_1296x486.sh - ok
 - runMJpegStreamer - ok. no stereo
	[requre mjpg-streamer](https://github.com/jacksonliam/mjpg-streamer)
	
### Host

	- runVlc.sh/PC - looks like issues with some keyframes
	- runVlc.sh/Tegra - crash of vlc/cvlc
	- runMJpegStreamer - OK. can handle many hosts
