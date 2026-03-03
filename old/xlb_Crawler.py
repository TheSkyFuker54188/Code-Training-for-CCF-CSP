import requests
from bs4 import BeautifulSoup

# 定义目标网址
url = 'https://ruc.yunshangxiaoyuan.cn/treehole/20220429RUC'

# 发送请求并获取网页内容
response = requests.get(url)
response.encoding = 'utf-8'

#? 检查request 是否成功
"""
# 打印 HTTP 状态码，应该是 200
print("HTTP 状态码:", response.status_code)

# 打印网页内容的一部分，看看是否是你预期的内容
print(response.text[:1000])  # 只打印前1000字符，避免太多内容
"""
web_content = response.text

# 使用 BeautifulSoup 解析网页内容
soup = BeautifulSoup(web_content, 'html.parser')

#? 检查网页结构
""" 
# 打印网页的结构或某一部分的 HTML
print(soup.prettify()[:1000])  # 只打印前1000字符的 HTML 内容，看看网页结构
"""

# 查找与信息学院、计算机、保研相关的信息
# 假设相关信息包含在 <p> 标签中，你需要根据实际网页结构调整选择器
related_info = []
keywords = ['信息', '计算机', '保研']

for paragraph in soup.find_all('p'):
    text = paragraph.get_text()
    if any(keyword in text for keyword in keywords):
        related_info.append(text)

# 输出抓取到的相关信息
for info in related_info:
    print(info)
