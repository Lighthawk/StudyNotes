# opensource配置
由于频繁更改源码调测，下列开源未安装到系统目录下

## openh264
```shell
make -j 8
# (由于hwcloud没有安装 meson，meson 编译就弃了)
```


## x264
```shell
./configure --prefix=/home/workspace/open_source/x264-0.16x/build
make -j 8
```

## ffmpeg - 无 x264 - 作为工具，直接安装到系统中
```shell
# linux 贫民版 ffmpeg 配置
./configure --enable-gpl --enable-version3 --enable-nonfree --enable-pthreads --enable-shared
make -j 8
make install
# ln -sf /home/workspace/open_source/ffmpeg-6.1/build/bin/ffmpeg /usr/local/bin/ffmpeg

# 运行 ffmpeg 或 ldd -r ffmpeg，提示缺库...
# vim /etc/profile
# export LD_LIBRARY_PATH=/usr/local/lib:/usr/local/lib64:$LD_LIBRARY_PATH

# 豪华版（未尝试，这是 2024-04-26 下载的最新 ffmpeg win64-bin 里打印的）
./configure --enable-gpl --enable-version3 --enable-static --disable-w32threads --disable-autodetect --enable-fontconfig --enable-iconv --enable-gnutls --enable-libxml2 --enable-gmp --enable-bzlib --enable-lzma --enable-libsnappy --enable-zlib --enable-librist --enable-libsrt --enable-libssh --enable-libzmq --enable-avisynth --enable-libbluray --enable-libcaca --enable-sdl2 --enable-libaribb24 --enable-libaribcaption --enable-libdav1d --enable-libdavs2 --enable-libuavs3d --enable-libxevd --enable-libzvbi --enable-librav1e --enable-libsvtav1 --enable-libwebp --enable-libx264 --enable-libx265 --enable-libxavs2 --enable-libxeve --enable-libxvid --enable-libaom --enable-libjxl --enable-libopenjpeg --enable-libvpx --enable-mediafoundation --enable-libass --enable-frei0r --enable-libfreetype --enable-libfribidi --enable-libharfbuzz --enable-liblensfun --enable-libvidstab --enable-libvmaf --enable-libzimg --enable-amf --enable-cuda-llvm --enable-cuvid --enable-dxva2 --enable-d3d11va --enable-d3d12va --enable-ffnvcodec --enable-libvpl --enable-nvdec --enable-nvenc --enable-vaapi --enable-libshaderc --enable-vulkan --enable-libplacebo --enable-opencl --enable-libcdio --enable-libgme --enable-libmodplug --enable-libopenmpt --enable-libopencore-amrwb --enable-libmp3lame --enable-libshine --enable-libtheora --enable-libtwolame --enable-libvo-amrwbenc --enable-libcodec2 --enable-libilbc --enable-libgsm --enable-libopencore-amrnb --enable-libopus --enable-libspeex --enable-libvorbis --enable-ladspa --enable-libbs2b --enable-libflite --enable-libmysofa --enable-librubberband --enable-libsoxr --enable-chromaprint
```

## libavc
```shell
mkdir build
cd build
cmake ../ && make -j 8
# 生成在 build/bin 下
```