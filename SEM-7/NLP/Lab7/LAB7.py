#!/usr/bin/env python
# coding: utf-8

# #### Name: Aditi Ganji
# #### Roll.No. : 21102A0056

# In[5]:


import nltk
from nltk.corpus import brown
nltk.download('brown')
categories = brown.categories()
print('Categories in Brown Corpus:')

for category in categories:
    print(category)
    
science_fiction = brown.sents(categories = 'science_fiction')
print('Number of Sentences in Science Fiction Category:', len(science_fiction))


# In[ ]:




