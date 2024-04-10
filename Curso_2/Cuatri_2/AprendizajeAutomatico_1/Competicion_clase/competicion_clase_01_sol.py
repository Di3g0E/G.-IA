'''
URJC / GIA / Aprendizaje Automático 1 / Curso 23-24
alfredo.cuesta@urjc.es
'''
import pandas as pd
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import confusion_matrix
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import PolynomialFeatures

#%% -- cargar ficheros de entrenamiento
path_name = 'C:/Users/Diego/OneDrive - Universidad Rey Juan Carlos/Documentos/GIA_URJC/Curso 2023-24/G.-IA/G.-IA/Curso_2/Cuatri_2/AprendizajeAutomatico_1/Competicion_clase/dataset_cc01/'
Xtrain = pd.read_csv(path_name + 'Xtrain.csv',
                     sep=';', decimal='.', header=0, index_col='id')
Ytrain = pd.read_csv(path_name + 'Ytrain.csv',
                     sep=';', decimal='.', header=0, index_col='id')

#%% -- separar un 20% para validación
val_size = .2
Xtrain, Xval, Ytrain, Yval = train_test_split(Xtrain, Ytrain, test_size=val_size, stratify=Ytrain)

#%% -- aumento de dimensionalidad
degree = 2
polyF = PolynomialFeatures(degree=degree)
polyF.set_output(transform='pandas')
polyF.fit(Xtrain)
Xtrain_ext = polyF.transform(Xtrain)

#%% -- Aprendizaje del modelo lineal con el conjunto de entrenamiento
max_iter = 5000
model = LogisticRegression(max_iter=max_iter, fit_intercept=False)
model.fit(Xtrain_ext, Ytrain)

#%% -- Inferencia con el conjunto de validación
Xval_ext = polyF.transform(Xval)
y_pred_ext = model.predict(Xval_ext)
cf_mat_ext = confusion_matrix(Yval, y_pred_ext)
print(f'Validation set.\nConfusion matrix with polynomial features\n {cf_mat_ext}')


#%% -- Aplicación del sistema de ML al conjunto de test
Xtest = pd.read_csv(path_name + 'Xtest.csv',
                    sep=';', decimal='.', index_col='id')
Xtest_ext = polyF.transform(Xtest)
y_hat = model.predict(Xtest_ext)
y_hat = pd.DataFrame(y_hat, columns=['y'], index = Xtest.index)
y_hat.to_csv(path_name+'Y_hat.csv', sep=';', decimal='.')
#%%

'''
Si se tiene acceso al ground truth de test, entonces el siguiente código
devuelve la matriz de confusión.

Ytest = pd.read_csv(path_name + 'Ytest.csv',
                    sep=';', decimal='.', index_col='id')
cf_mat_ext = confusion_matrix(Ytest, y_hat)
print(f'Test set.\nConfusion matrix with polynomial features\n {cf_mat_ext}')
'''