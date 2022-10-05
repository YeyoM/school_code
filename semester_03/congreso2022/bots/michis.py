import requests
import webbrowser

#! EN OTROS LENGUAJES SE UTILIZA EL TÉRMINO "fetch" PARA
#! REFERIRSE A LA FUNCIÓN QUE CONSUME APIS....
urlDeLaAPI = "https://api.thecatapi.com/v1/images/search"
respuestaDelRequest = requests.get(url=urlDeLaAPI)
print(respuestaDelRequest)


print(f"Status: {respuestaDelRequest.status_code}\n")
print(f"Content: {respuestaDelRequest.content}\n")
print(f"Text: {respuestaDelRequest.text}\n")
print(f"URL: {respuestaDelRequest.url}\n")
print(f"Headers: {respuestaDelRequest.headers}\n")
print(f"_Content: {respuestaDelRequest._content}\n")
print(f"Encoding: {respuestaDelRequest.encoding}\n")

# Obtener el link de la imagen de gatito #
# Primero se necesita convertir a un JSON #
#* print("\n\n", respuestaDelRequest.json())
respuestaEnJSON = respuestaDelRequest.json()
print(respuestaEnJSON)


urlFotoGatito = respuestaEnJSON[0]["url"]
print(urlFotoGatito)

webbrowser.open(urlFotoGatito)