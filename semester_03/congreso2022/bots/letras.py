import requests
import lxml.html as html

cancion = input("Ingrese el nombre de una canción: ")
cancion = cancion.lower()
cancion = cancion.replace(" ", "%20")

url = f"https://www.lyricsfreak.com/search.php?q={cancion}"
res = requests.get(url)

resData = res.content

linksRegex = '//a[@class="song"]/@href'

resData.decode("utf-8")
links = html.fromstring(resData)
links = links.xpath(linksRegex)

urlCancion = f"https://www.lyricsfreak.com{links[0]}"
res = requests.get(urlCancion)
resData = res.content
resData.decode("utf-8")
lyrics = html.fromstring(resData)

lyricsRegex = '//div[@id="content"]//text()'
lyrics = lyrics.xpath(lyricsRegex)

for lyric in lyrics:
    print(lyric)