import pandas as pd

# Crear un diccionario con las preguntas y respuestas basadas en la guía proporcionada
data = {
    "Pregunta": [
        "¿Qué es una red de información masiva?",
        "¿Qué es la conexión en red?",
        "¿Cuál fue la primera red informática en funcionamiento?",
        "¿Qué es una red de información privada?",
        "¿Qué es una VLAN?",
        "¿Qué es el enrutamiento?",
        "¿Qué es un enrutador y cuáles son sus funciones principales?",
        "¿Qué es el enrutamiento estático?",
        "¿Qué es el enrutamiento dinámico?",
        "¿Qué es un gateway?",
        "¿Qué es un proxy y cuál es su diferencia con una VPN?",
        "¿Qué es un firewall y cuáles son sus clasificaciones principales?",
        "¿Qué es un esquema de cableado y cuáles son sus tipos?",
        "¿Qué es una tarjeta de red y cuál es su función?",
        "¿Qué es un repetidor?",
        "¿Qué es un transductor?",
        "¿Qué es un modem?",
    ],
    "Respuesta": [
        "Un conjunto de recursos que transmiten información a una gran cantidad de personas de forma simultánea.",
        "El proceso de conectar dos o más dispositivos informáticos para permitir la transmisión e intercambio de información y recursos.",
        "DARPANET, creada por el Departamento de Defensa de los Estados Unidos en la década de 1960.",
        "Una red segura que solo pueden utilizar ciertos dispositivos o usuarios, aislada de la red pública del internet.",
        "Es una tecnología que permite crear redes lógicas independientes dentro de la misma red física.",
        "El proceso de selección de rutas en cualquier red.",
        "Es un dispositivo de red que conecta los dispositivos de computación y las redes a otras redes. Sus funciones principales son: determinación de la ruta, reenvío de datos, y balanceo de carga.",
        "Un método en el que un administrador configura manualmente las rutas de red, útil cuando la arquitectura de red es constante.",
        "Un conjunto de reglas que crean, mantienen y actualizan dinámicamente la tabla de enrutamiento, adaptándose a condiciones cambiantes de la red.",
        "Es un nodo de red que conecta dos redes con diferentes protocolos de transmisión.",
        "Un servidor que actúa como intermediario entre un usuario y el internet. A diferencia de una VPN, no cifra los datos.",
        "Un sistema de seguridad de red que inspecciona y controla el tráfico para evitar accesos no autorizados. Sus clasificaciones incluyen basados en red, basados en host, y otros.",
        "Un sistema de cables que permite transportar información dentro de una LAN. Tipos: cableado vertical y horizontal.",
        "Un dispositivo encargado de preparar, transferir y controlar datos en una red.",
        "Un dispositivo que refuerza las señales amplificándolas o regenerándolas.",
        "Un dispositivo que convierte señales de un tipo a otro para facilitar la comunicación y transmisión de datos.",
        "Un dispositivo que conecta equipos computacionales entre sí a través de una conexión.",
    ],
}

# Crear el DataFrame
df = pd.DataFrame(data)

# Guardar el DataFrame como un archivo Excel
file_path = "guia_redes_preguntas_respuestas.xlsx"
df.to_excel(file_path, index=False)
