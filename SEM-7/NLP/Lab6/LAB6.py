#!/usr/bin/env python
# coding: utf-8

# #### Name: Aditi Ganji
# #### Roll.No. : 21102A0056

# In[2]:


import nltk
from nltk.corpus import brown
nltk.download('brown')

bsf = brown.tagged_words(categories = 'science_fiction')
tagList = {}

for (word, tag) in bsf:
    if tag not in tagList:
        tagList.update({tag: 1})
    else:
        tagList[tag] += 1
        
tagList = sorted(tagList.items(), key = lambda item: (item[1], item[0]), reverse = True)
print('Tag\t\tCount')

for (tag, count) in tagList:
    print('{}\t\t{}'.format(tag, count))


# In[ ]:




