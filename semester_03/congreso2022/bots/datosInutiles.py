import requests
import webbrowser

res = requests.get("https://uselessfacts.jsph.pl/random.json?language=en")
# print(res.json())

resData = res.json()
print(resData["text"]) 

res = requests.get("https://api.thecatapi.com/v1/images/search")
# print(res.json())

resData = res.json()
print(resData[0]["url"])

webbrowser.open(resData[0]["url"])