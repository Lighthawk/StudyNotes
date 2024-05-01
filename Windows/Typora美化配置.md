### Typora主题和常用的字体配置方法

###### 0、增加主题/调整markdown显示宽度/调整markdown编辑状态宽度

- 配置启蒙博客：[Typora常用好看主题推荐!!!_typora主题-CSDN博客](https://blog.csdn.net/weixin_52023681/article/details/120251523)

- 增加主题：直接将主题名字的 .css 文件放入主题目录即可。下面所有操作都是在该主题css文件中进行，且需要重启Typora才会生效。
- 调整markdown显示宽度：

```css
/* 修改 write，调整 max-width，推荐 90~95%，或 2500px */
#write {
    max-width: 92%;
    margin: 0 auto;
    padding: 20px 30px 100px;
}
```

- 调整markdown编辑状态宽度

```css
/* 增加该配置，推荐 70~80% */
#typora-source .CodeMirror-lines {
    max-width: 70%;
}
```



###### 1、界面/显示字体

```css
/* 最外配置应该是在 :root 中，字体配置习惯等宽字体，从左到右依次生效 */
/* 其实后续配置核心都是 font-family，如果想改的标签实在找不到，就在 css 里搜 font-family。XD */
:root {
    --font-family: "Cascadia Code", HYZhengYuan, Menlo, Consolas;
}
```



###### 2、代码块字体

```css
/* 代码块字体是通过增加该配置实现 */
.CodeMirror-wrap .CodeMirror-code pre {
    font-family: "Cascadia Code", HYZhengYuan;
}
```



###### 3、代码块内注释字体

```css
/* 注释字体修改在这里，实在找不到搜 font-family，一个一个试出来的。 */
/* P.S. 在尝试期间发现个有趣的现象，如果没做下面字体修改，注释字体随语言变化；
比如 shell 脚本下的 # 是注释，那么如果输入 // 就认为是正常代码语言，两者字体就不同 */
span.cm-comment {
    /* color: #b8f1cc !important; */
    color: #82e0aa !important;
    /* font-style: italic; */
    /* font-family: Monaco, Consolas, 'Courier New', monospace; */
    font-family: "Cascadia Code", HYZhengYuan;
    font-size: 16px;
}
```



- ###### 4、代码不换行
```css
#write .CodeMirror-wrap .CodeMirror-code pre {
    padding-left: 12px;
    white-space: nowrap;
}

#write .CodeMirror-code {
    white-space: nowrap;
    overflow-y: hidden;
    overflow-x: scroll;
}
```
