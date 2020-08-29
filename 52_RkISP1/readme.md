

### Image sinks
 - rkximagesink - X11, fast. require io-mode=4
 - glimagesink - GL, some delay, works with dual-cam
 - multifilesink - save to file. since AWB required some time to work correctly, tupically need 3-4 frames to stabilize AWB. num-buffers - # of files

### RKISP1/gst params
 - device - /dev/video0 etc
 - io-mode - 0..4 (memory mode) - V4L2: 
	- 1 - mmap;
	- 2 - userptr
	- 3 - overlay
	- 4 - dmabuf
	- 0 - NULL
 - field - V4L2: 
	- 1 none
	- 2 top
	- 3 bottom
	- 4 interlaced
	- 5 seq-tb (both fields sequential, top first)
	- 6 seq-bt (--//--,bottom first)
	- 7 interlaced-tb (interlaced fielsd, top first)
	- 8 interlace-bt (--//--, bottom first)
	- 0 NULL
 - buffercount: - number

 - imageprocessor
	- rkisp

 - analyzer (only with cam_iq)
    - 0 - NULL
    - 1 - simple
    - 2 - aiq
    - 3 - rockchip(dynamic)
    - 4 - rockchip(qkiq, hybrid)

 - input-format

 - fake-input 
    (file instead of life cam)