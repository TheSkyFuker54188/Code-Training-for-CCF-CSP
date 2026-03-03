from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from bs4 import BeautifulSoup

# 设置 WebDriver 的路径（替换为你的实际路径）
chrome_driver_path = 'C:/chromedriver-win64/chromedriver.exe'

# 配置 Chrome 浏览器选项
chrome_options = Options()
chrome_options.add_argument("--headless")  # 无头模式，不显示浏览器窗口

# 初始化 WebDriver
service = Service(chrome_driver_path)
driver = webdriver.Chrome(service=service, options=chrome_options)

# 打开目标网页
url = 'https://ruc.yunshangxiaoyuan.cn/treehole/20220429RUC'
driver.get(url)

try:
    # 等待页面加载完成，确保内容可见
    WebDriverWait(driver, 20).until(
        EC.presence_of_element_located((By.CSS_SELECTOR, '#app'))
    )

    # 获取网页内容
    html = driver.page_source
    print(driver.page_source)

    # 使用 BeautifulSoup 解析网页内容
    soup = BeautifulSoup(html, 'html.parser')

    # 关键词列表：我们要找与“信息学院”、“计算机”、“保研”相关的信息
    keywords = ['信息学院', '计算机', '保研']

    # 查找网页中的所有文字内容
    related_info = []
    
    # 假设相关内容可能出现在 div、span、p 标签中
    for element in soup.find_all(['div', 'span', 'p']):
        text = element.get_text()
        if any(keyword in text for keyword in keywords):
            related_info.append(text)

    # 输出抓取到的相关信息
    if related_info:
        print("抓取到以下相关信息：")
        for info in related_info:
            print(info)
            print('-' * 50)
    else:
        print("未找到与关键词相关的信息。")

finally:
    # 关闭 WebDriver
    driver.quit()
