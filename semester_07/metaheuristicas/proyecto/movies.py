import nltk
import time
import json
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
import pandas as pd

# Si lo corres por primera vez descomenta las siguientes líneas
nltk.download("punkt")
nltk.download("stopwords")

global PROHIBIDAS
PROHIBIDAS = ["br", "movie"]
global ARCHIVO
ARCHIVO = "movie_data.csv"
global COLUMNAS
COLUMNAS = ["review"]
global CANTIDAD
CANTIDAD = 50000
global OUTPUT_JSON
OUTPUT_JSON = "reviews.json"


def leer_texto():
    # Reads only the "Review" column
    texto = pd.read_csv(ARCHIVO, usecols=COLUMNAS)
    return texto


def texto_a_vector():
    texto = leer_texto()
    # Process only the first CANTIDAD rows
    texto = texto.head(CANTIDAD)

    stopwords_ingles = set(stopwords.words("english"))
    processed_reviews = []

    total_time = 0

    for review in texto["review"]:
        start_time = time.time()  # Start timing
        palabras = word_tokenize(review)  # Tokenize each review
        palabras_filtradas = [
            palabra.lower()
            for palabra in palabras
            if palabra.isalpha()
            and palabra.lower() not in stopwords_ingles
            and palabra.lower() not in PROHIBIDAS
        ]
        palabras_filtradas = list(set(palabras_filtradas))  # Avoid duplicates

        end_time = time.time()  # End timing
        processing_time = end_time - start_time  # Calculate processing time

        # Save the original review, processed tokens, and time taken for this review
        processed_reviews.append(
            {"review": review, "tokens": palabras_filtradas, "time": processing_time}
        )

        total_time += processing_time

    return processed_reviews, total_time


def procesar_texto():
    # Process each review individually and track the total time
    palabras_por_review, total_time = texto_a_vector()

    # Duplicate the list of reviews (palabras_por_review)
    palabras_por_review = palabras_por_review * 2

    # Save to JSON
    with open(OUTPUT_JSON, "w") as json_file:
        json.dump(palabras_por_review, json_file, indent=4)

    return palabras_por_review, total_time


def main():
    palabras_por_review, total_time = procesar_texto()

    # Print each review's tokens and time taken
    # for idx, review_data in enumerate(palabras_por_review, start=1):
    #    print(f"Review {idx}:")
    #    print(f"Original: {review_data['review']}")
    #    print(f"Tokens: {review_data['tokens']}")
    #    print(f"Time to process: {review_data['time']:.4f} seconds")
    #    print()

    # Print total time taken for all reviews
    print(f"Total processing time: {total_time * 2:.4f} seconds")


if __name__ == "__main__":
    main()
