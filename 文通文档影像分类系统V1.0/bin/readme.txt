
1、由于测试是采用扫描与识别分离的方式，分类结果保存的配置没有设成对话框的形式，而采用配置文档的形式。若要修改配置，请打开classifyPara.cfg手动修改。classifyPara.cfg配置如下：

[ClassifyInterface]
bSaveClassifyResult = 0
                        ;是否保存分类的结果
SaveFlag = 0
	                ;保存标志,0表示到图片的同级目录,1表示手动设置			
ClassifyResultPath = d:\wintone
	                ;保存路径。


2、没有修改模板编辑器，但是仍然是按照票据名称做分类保存，若票据名称为空，则按照模板名做分类保存。这是在Demo中控制的。这样做的目的是可以跟老的模板兼容，以前做的模板票据名称为空时同样可以用来做分类测试。


3、将需要替换的三个文件放到开发包bin文件夹下即可。