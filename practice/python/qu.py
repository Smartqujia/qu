# encoding: utf-8
import sys
reload(sys)
sys.setdefaultencoding('utf-8')
import requests
import re
import time
time1=time.time()
'''
main_url = 'http://video.eastday.com/a/170612170956054127565.html'
resp = requests.get(main_url)
#没有这行，打印的结果中文是乱码

resp.encoding = 'utf-8'
html = resp.text
#print html
link = re.findall(r'var mp4 = "(.*?)";', html)[0]
link = 'http:'+'//cdn.e9377f.com/tdyx/39464vcj_wgsylsdftt/20180712-df.mp4'
print link
#'//cdn.e9377f.com/tdyx/39464vcj_wgsylsdftt/20180712-df.mp4'
'''
link = 'https://link.zhihu.com/?target=https%3A//www.zhihu.com/video/968080382617444352'
dest_resp = requests.get(link)
#视频是二进制数据流，content就是为了获取二进制数据的方法
data = dest_resp.content
#print data
#保存数据的路径及文件名
path = r'/home/smart/Desktop/qq.mp4'
f = open(path, 'wb')
f.write(data)
f.close()


time2 = time.time()

print u'ok,下载完成!'
print u'总共耗时：' + str(time2 - time1) + 's'
