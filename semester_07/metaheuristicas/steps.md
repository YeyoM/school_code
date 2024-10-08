# Jupyter Notebooks in local machine

## Installation

1. Install jupyter notebook by running the following command in terminal:

```
pip install jupyter
```

2. Install jupyter lab by running the following command in terminal:

```
pip install jupyterlab
```

## Notes

Remember to have the python environment activated before running the commands in terminal.

## Run jupyter in local machine by running the following command in terminal:

```
jupyter notebook
```

or with

```
jupyter lab
```

2. Open the notebook you want to run
3. Run the cells in the notebook

## Exporting the notebook

1. There is an option in the file menu to download the notebook as a .ipynb file
2. You can also download the notebook as a .html file by clicking on the file menu and selecting "Download as" and then "HTML (.html)".

## Python script to .ipynb

1. You can convert a .py file to a .ipynb file by running the following command in terminal:

```
p2j filename.py
```

### R

R was installed in ubuntu using the following commands:

```
sudo apt-get update
sudo apt-get install r-base
```

Once R is installed, you can install the IRkernel by running the following command in R:

launch R by typing `R` in terminal and then run the following command in R:

```R
install.packages('IRkernel')
IRkernel::installspec()
```

After installing the IRkernel, you can run the following command in terminal to open a jupyter notebook with R kernel:

```
jupyter notebook
```

Once in the notebook, you can create a new notebook with the R kernel by clicking on the "New" button and selecting "R" from the dropdown menu.
