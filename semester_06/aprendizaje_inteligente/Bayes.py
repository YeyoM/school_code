from collections import Counter

import nltk
import pandas as pd
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize

# Si es la primera vez que corres este codigo Descomenta las siguientes lineas

nltk.download("punkt")
nltk.download("stopwords")

global PROHIBIDAS
PROHIBIDAS = ["br", "movie", "film", "one"]
global ARCHIVO
ARCHIVO = "Peliculas.csv"
global DATASET
DATASET = pd.read_csv(ARCHIVO)
global INITAL_GUESS
INITAL_GUESS = 0.5

Review_Prueba_Positiva = "I loved the movie, it was great"
Review_Prueba_Negativa = "I hated the movie, it was terrible"

# Nuestra inital Guess tanto para los positivos como para los negativos es de 0.5


# Funcion para obtener los indices de las reviews positivas y negativas
def Obtener_Indices():
    Indices_Positivos = []
    Indices_Negativos = []
    for i in range(len(DATASET)):
        if DATASET["sentiment"][i] == 1:
            Indices_Positivos.append(i)
        else:
            Indices_Negativos.append(i)
    return Indices_Positivos, Indices_Negativos


# Funcion para obtener las palabras de las reviews positivas y negativas
def Vectores_Palabras():
    Indices_Positivos, Indices_Negativos = Obtener_Indices()
    Palabras_Positivas = []
    Palabras_Negativas = []
    for i in range(len(DATASET)):
        if i in Indices_Positivos:
            Palabras_Positivas.append(DATASET["review"][i])
        else:
            Palabras_Negativas.append(DATASET["review"][i])
    return Palabras_Positivas, Palabras_Negativas


# Funcion para filtrar las palabras que no queremos de las reviews
def Filtar_Palabras(Palabras):
    Palabras_Filtradas = []
    for review in Palabras:
        tokens = word_tokenize(review)
        stopwords_ingles = set(stopwords.words("english"))
        Palabras_Filtradas.extend(
            [
                Palabra.lower()
                for Palabra in tokens
                if Palabra.isalpha()
                and Palabra.lower() not in stopwords_ingles
                and Palabra.lower() not in PROHIBIDAS
            ]
        )
    return Palabras_Filtradas


# Funcion para Obtener la probabilidad de una palabra en una review
def Probabilidad_Palabra(Palabra, Review):
    Probabilidad_Palabra = (Review.count(Palabra) + 1) / len(Review)
    return Probabilidad_Palabra


# Funcion para obtener la frecuencia de las palabras en las reviews
def Frecuencia_Palabras(Palabras):
    Frecuencia = Counter(Palabras)
    print(Frecuencia.most_common(10))
    return Frecuencia


# Funcion para obtener la probabilidad de que una review sea positiva o negativa
def Naive_Bayes(Review, Palabras):
    Probabilidad = INITAL_GUESS
    Probabilidades = []
    Review_Filtrada = Filtar_Palabras([Review])
    for Palabra in Review_Filtrada:
        Probabilidad_Individual = Probabilidad_Palabra(Palabra, Palabras)
        Probabilidades.append(Probabilidad_Individual)
        Probabilidad *= Probabilidad_Individual
    print(Probabilidades)
    return Probabilidad


# Funcion para hacer pruebas
def Pruebas(Palabras_Positivas, Palabras_Negativas, Review_Prueba):
    print("Probabilidad de la review de prueba :)")
    print()

    print(
        "Las probabilidades de las palabras en las reviews positivas y negativas son las siguientes :)"
    )

    print("Review de prueba:", Review_Prueba)

    Probabilidad_De_Ser_Positiva = Naive_Bayes(Review_Prueba, Palabras_Positivas)
    Probabilidad_De_Ser_Negativa = Naive_Bayes(Review_Prueba, Palabras_Negativas)

    print("Probabilidad de ser positiva:", Probabilidad_De_Ser_Positiva)
    print("Probabilidad de ser negativa:", Probabilidad_De_Ser_Negativa)

    if Probabilidad_De_Ser_Positiva > Probabilidad_De_Ser_Negativa:
        print("La review es positiva")
    else:
        print("La review es negativa")


def main():
    print()
    Palabras_Positivas, Palabras_Negativas = Vectores_Palabras()
    print("Reviews Separadas :) ")
    print()

    Palabras_Positivas = Filtar_Palabras(Palabras_Positivas)
    print("Palabras Positivas Filtradas :)")
    print("Cantidad de palabras positivas:", len(Palabras_Positivas))
    print()

    Palabras_Negativas = Filtar_Palabras(Palabras_Negativas)
    print("Palabras Negativas Filtradas :)")
    print("Cantidad de palabras negativas:", len(Palabras_Negativas))
    print()

    print("Frecuencia de las palabras positivas y negativas :)")
    Frecuencia_Palabras(Palabras_Positivas)
    Frecuencia_Palabras(Palabras_Negativas)
    print()

    Pruebas(Palabras_Positivas, Palabras_Negativas, Review_Prueba_Positiva)
    print()

    Pruebas(Palabras_Positivas, Palabras_Negativas, Review_Prueba_Negativa)


if __name__ == "__main__":
    main()
