# Antes de iniciar

Es necesario inicializar un entorno virtual de python para poder instalar las dependencias necesarias para correr el proyecto.

```bash
python -m venv python3-virtualenv
```

Una vez creado el entorno virtual, es necesario activarlo para poder instalar las dependencias.

En windows
```bash
source python3-virtualenv/Scripts/activate
```

En linux
```bash
source python3-virtualenv/Scripts/activate
```

Una vez activado el entorno virtual, es necesario instalar las dependencias.

```bash
pip install -r requirements.txt
```

Para detener el entorno virtual, es necesario ejecutar el siguiente comando.

```bash
deactivate
```