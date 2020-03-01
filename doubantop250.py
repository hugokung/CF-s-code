# @ModuleName: spider
# @Function: 
# @Author: Hugo
# @Time: 2020/2/18 15:21

from lxml import etree
import requests
from selenium import webdriver

headers = {'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.130 Safari/537.36'}
url = 'https://movie.douban.com/top250'
resposed = requests.get(url, headers=headers)
html = resposed.text
seletor = etree.HTML(html)

items = seletor.xpath('//div[@class="item"]')
for item in items:
    title = item.xpath('./div[@class="pic"]/a/img/@alt')[0]
    print(title)
    link = item.xpath('./div[@class="pic"]/a/img/@src')[0]
    print(link)
