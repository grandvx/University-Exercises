#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np


# In[10]:


import os
import pandas as pd
import chardet

file_path = os.path.join(os.path.expanduser('~'), 'Downloads', 'Corona_NLP_train.csv')

with open(file_path, 'rb') as f:
    result = chardet.detect(f.read())
encoding = result['encoding']
#Load the dataset
df = pd.read_csv(file_path, encoding=encoding)


# In[11]:


#Check the first rows
df.head()


# In[12]:


#See the number of rows and columns
num_rows, num_cols = df.shape
print("Number of rows:", num_rows)
print("Number of columns:", num_cols)


# In[13]:


#Obtain summary statistics
df.describe()


# In[14]:


#Verify the data types of each column
df.dtypes


# In[15]:


#Check missing values
df.isnull().sum()


# In[16]:


#Explore target variable distribution
df['Sentiment'].value_counts()


# In[38]:


import nltk
from nltk.tokenize import word_tokenize
from sklearn.feature_extraction.text import CountVectorizer

nltk.download('punkt')

# Clean the text data
df_copy = df[['tweet', 'sentiment']].copy()
df_copy.loc[:, 'tweet'] = df_copy['tweet'].str.lower()

# Tokenize the tweets
df_copy.loc[:, 'tokenized_text'] = df_copy['tweet'].apply(word_tokenize)

# Convert tweets into numerical representations using bag-of-words
vectorizer = CountVectorizer()
X = vectorizer.fit_transform(df_copy['tweet'])


# In[40]:


from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(X, df['sentiment'], test_size=0.2, random_state=42)


# In[41]:


from sklearn.naive_bayes import MultinomialNB

#Initialize and train the Naive Bayes classifier
classifier = MultinomialNB()
classifier.fit(X_train, y_train)


# In[42]:


from sklearn.metrics import accuracy_score, confusion_matrix, classification_report

# Make predictions on the test set
y_pred = classifier.predict(X_test)

# Calculate accuracy
accuracy = accuracy_score(y_test, y_pred)
print("Accuracy:", accuracy)

# Generate confusion matrix
confusion_mat = confusion_matrix(y_test, y_pred)
print("Confusion Matrix:")
print(confusion_mat)

# Generate classification report
classification_rep = classification_report(y_test, y_pred)
print("Classification Report:")
print(classification_rep)


# In[ ]:




