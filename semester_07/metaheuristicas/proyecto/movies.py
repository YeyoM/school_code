import nltk
import time
import json
import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer

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

    processed_reviews = []
    stopwords_ingles = set(nltk.corpus.stopwords.words("english")).union(PROHIBIDAS)
    total_time = 0

    # Vectorizer to convert text to numeric values
    vectorizer = TfidfVectorizer(
        max_features=1000,  # limit the number of features
        stop_words=list(stopwords_ingles),  # Convert the set to a list
        lowercase=True,
    )

    # Fit the vectorizer on the reviews and transform them into numeric form
    start_time = time.time()
    tfidf_matrix = vectorizer.fit_transform(texto["review"])
    end_time = time.time()

    # Get the feature names (tokens)
    feature_names = vectorizer.get_feature_names_out()

    for i, review in enumerate(texto["review"]):
        processing_time = (
            end_time - start_time
        )  # Use the vectorization time for all reviews

        # Get the numeric vector for each review
        vector = tfidf_matrix[i].toarray().flatten().tolist()

        processed_reviews.append(
            {"review": review, "tokens": vector, "time": processing_time}
        )

        total_time += processing_time

    return processed_reviews, total_time


def procesar_texto():
    palabras_por_review, total_time = texto_a_vector()

    # Save to JSON
    with open(OUTPUT_JSON, "w") as json_file:
        json.dump(palabras_por_review, json_file, indent=4)

    return palabras_por_review, total_time


def main():
    palabras_por_review, total_time = procesar_texto()

    print(f"Total processing time: {total_time:.4f} seconds")


if __name__ == "__main__":
    main()
