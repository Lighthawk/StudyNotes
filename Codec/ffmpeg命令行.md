# ffmpeg命令行

# 2024-05 Lighthawk@126.com

## 1、ffmpeg常用命令

```shell
# 已封装的视频提取yuv并转为yuv420p
ffmpeg -i life_1080p30.mp4 -pix_fmt yuv420p life_1080p30.yuv
```



## 2、ffplay常用命令

```shell
# 记录ffplay主要是... 没有yuv查看器
# yuv 数据里不记录宽高数据，所以必须额外输入
# framerate 指定播放帧率
# -f h264 指定H.264格式
ffplay [-f rawvideo] [-framerate 30] [-f h264] -video_size 1920x1080 life_1080p30.yuv
```

> 更详细命令可查看：[FFplay命令 ---- 播放与参数选项 - Vzf - 博客园 (cnblogs.com)](https://www.cnblogs.com/vczf/p/13450998.html)