# openh264命令行


#### https://www.ctyun.cn/developer/article/463831506931781

```shell
* -bf        指定输出的码流。
* -org       输入的视频源，支持 yuv.
* -sw        输入视频源的宽度。
* -sh        输入视频源的高度。
* -utype     编码模式，共有四种：CAMERA_VIDEO_REAL_TIME, SCREEN_CONTENT_REAL_TIME, CAMERA_VIDEO_NON_REAL_TIME,SCREEN_CONTENT_NON_REAL_TIME. 即：实时相机内容编码，实时屏幕内容编码，非实时相机内容编码，非实时屏幕内容编码。
* -savc      simulcast avc 的缩写，编码输出为标准的 h.264/avc 流。
* -frms      视频源需要编码的帧数，从文件头开始计算。
* -frin      视频源码率。
* -numtl     时域层数，默认为 1.
* -iper      I 帧周期，默认为 -1. 在编码器内会折合为 GOP 的 2-整幂次。
* -nalsize   最大 NAL 长度。
* -spsid     编码参数集的策略。
* -cabac     熵编码模式：0 为 Calvc, 1 为 CABAC.
* -complexity 编码决策复杂度：0 是低复杂度，1 是中等复杂度，2 是高复杂度。默认值是 0。
* -denois    降噪模式，默认是关闭的。
* -scene     场景切换检测，默认是关闭的。
* -bgd       背景检测，默认是关闭的。
* -aq        自适应量化，默认是关闭的。
* -ltr       使用长期参考帧，默认是 0。
* -ltrnum    使用长期参考帧的数目，屏幕内容模式建议取 1~4，自然场景建议取 1~2.
* -ltrper    长期参考帧的插入周期。
* -threadIdc 编码线程数。0 代表自动决定线程数，1 代表关闭多线程实现，>1 代表指定线程数。
* -loadbalancing 多线程模式下的负载均衡。0 表示关闭，1 表示开启。默认是开启的。
* -deblockIdc 去方块滤波。0 表示关闭。
* -alphaOffset 去方块滤波的 AlphaOffset, 取值范围为-6~+6.
* -betaOffset 去方块滤波的 BetaOffset, 取值范围为-6~+6.
* -rc        码率控制模式：-1 表示关闭，0 表示质量控制模式，1 表示码率控制模式，2 表示缓冲控制模式，3 表示基于输入时间戳的码率控制模式。        
* -tarb      总体目标码率（针对多层输出）。
* -maxbrTotal总体最大码率。
* -maxqp     最大 QP。默认为 51，屏幕内容模式下为 35.
* -minqp     最小 QP。默认为 0，屏幕内容模式下为 26.
* -trace     日志等级。
* -fixrc     允许码率控制超限。
* -numl      空域层数。

以下是对各空域层的控制参数。其格式为(n, val)，第一个参数表示指定的层数，第二个参数表示指定的参数值：
* -lconfig   指定配置文件。
* -drec      指定重建流。  
* -dprofile  指定 profile。所有层的 profile 必须一致。
* -dw        输出宽度。
* -dh        输出高度。
* -frout     输出帧率。
* -lqp       基础 QP。
* -ltarb     层上目标码率。
* -lmaxb     层上最大码率。
* -slcmd     空域层的 slice 模式。

下面是一个完全使用命令行（不引入配置文件）的例子：
h264enc -org xxx.yuv -sw 720 -sh 1280 -frin 30 -numtl 1 -numl 0 -savc 1 -tarb 3000 -maxbrTotal 4000 -dw 0 720 -dh 0 1280 -frout 0 30 -iper 120 -ltarb 0 3000 -lmaxb 0 4000 -ltr 1 -ltrnum 2 -rc 1 -bf zzz.264
```

#### 附 openh264 命令行 help 打印
```shell
./h264enc --help
You specified pCommand is invalid!!

 Wels SVC Encoder Usage:

 Syntax: welsenc.exe -h
 Syntax: welsenc.exe welsenc.cfg
 Syntax: welsenc.exe welsenc.cfg [options]

 Supported Options:
  -bf          Bit Stream File
  -org         Original file, example: -org src.yuv
  -sw          the source width
  -sh          the source height
  -utype       usage type
  -savc        simulcast avc
  -frms        Number of total frames to be encoded
  -frin        input frame rate
  -numtl       Temporal layer number (default: 1)
  -iper        Intra period (default: -1) : must be a power of 2 of GOP size (or -1)
  -nalsize     the Maximum NAL size. which should be larger than the each layer slicesize when slice mode equals to SM_SIZELIMITED_SLICE
  -spsid       SPS/PPS id strategy: 0:const, 1: increase, 2: sps list, 3: sps list and pps increase, 4: sps/pps list
  -cabac       Entropy coding mode(0:cavlc 1:cabac 
  -complexity  Complexity mode (default: 0),0: low complexity, 1: medium complexity, 2: high complexity
  -denois      Control denoising  (default: 0)
  -scene       Control scene change detection (default: 0)
  -bgd         Control background detection (default: 0)
  -aq          Control adaptive quantization (default: 0)
  -ltr         Control long term reference (default: 0)
  -ltrnum      Control the number of long term reference((1-4):screen LTR,(1-2):video LTR 
  -ltrper      Control the long term reference marking period 
  -threadIdc   0: auto(dynamic imp. internal encoder); 1: multiple threads imp. disabled; > 1: count number of threads 
  -loadbalancing   0: turn off loadbalancing between slices when multi-threading available; 1: (default value) turn on loadbalancing between slices when multi-threading available
  -deblockIdc  Loop filter idc (0: on, 1: off, 
  -alphaOffset AlphaOffset(-6..+6): valid range 
  -betaOffset  BetaOffset (-6..+6): valid range
  -rc          rate control mode: -1-rc off; 0-quality mode; 1-bitrate mode; 2: buffer based mode,can not control bitrate; 3: bitrate mode based on timestamp input;
  -tarb        Overall target bitrate
  -maxbrTotal  Overall max bitrate
  -maxqp       Maximum Qp (default: 51, or for screen content usage: 35)
  -minqp       Minimum Qp (default: 0, or for screen content usage: 26)
  -numl        Number Of Layers: Must exist with layer_cfg file and the number of input layer_cfg file must equal to the value set by this command
  The options below are layer-based: (need to be set with layer id)
  -lconfig     (Layer) (spatial layer configure file)
  -drec        (Layer) (reconstruction file);example: -drec 0 rec.yuv.  Setting the reconstruction file, this will only functioning when dumping reconstruction is enabled
  -dprofile    (Layer) (layer profile);example: -dprofile 0 66.  Setting the layer profile, this should be the same for all layers
  -dw          (Layer) (output width)
  -dh          (Layer) (output height)
  -frout       (Layer) (output frame rate)
  -lqp         (Layer) (base quality layer qp : must work with -ldeltaqp or -lqparr)
  -ltarb       (Layer) (spatial layer target bitrate)
  -lmaxb       (Layer) (spatial layer max bitrate)
  -slcmd       (Layer) (spatial layer slice mode): pls refer to layerX.cfg for details ( -slcnum: set target slice num; -slcsize: set target slice size constraint ; -slcmbnum: set the first slice mb num under some slice modes) 
  -trace       (Level)
  -fixrc       Enable fix RC overshoot(default: 1)
```

```shell
# 日志等级，默认 error
-trace (Level)
/**
* @brief Enumerate the type of wels log
*/
enum {
  WELS_LOG_QUIET       = 0x00,          ///< quiet mode
  WELS_LOG_ERROR       = 1 << 0,        ///< error log iLevel
  WELS_LOG_WARNING     = 1 << 1,        ///< Warning log iLevel
  WELS_LOG_INFO        = 1 << 2,        ///< information log iLevel
  WELS_LOG_DEBUG       = 1 << 3,        ///< debug log, critical algo log
  WELS_LOG_DETAIL      = 1 << 4,        ///< per packet/frame log
  WELS_LOG_RESV        = 1 << 5,        ///< resversed log iLevel
  WELS_LOG_LEVEL_COUNT = 6,
  WELS_LOG_DEFAULT     = WELS_LOG_WARNING   ///< default log iLevel in Wels codec
};
```