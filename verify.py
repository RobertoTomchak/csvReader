import pandas as pd
import numpy as np

df = pd.read_csv("enem_data.csv", encoding="iso-8859-1", delimiter=";")
data = df["NU_NOTA_REDACAO"]
data[np.isnan(data)] = 0
print(np.mean(data))
