import pandas as pd
obj1=pd.Series([4,7,-5,3])

obj2=pd.Series([4,7,-5,3],index=['d','b','a','c'])

#? dictionary
sdata={'Ohio':35000}
obj3=pd.Series(sdata)

#* List Indexing
#print(obj2[['d','a']]) #! error
print(obj2[['d', 'a']]) # right  必要的空格

#* Slicing Indexing
print(obj2[:3])

#* Bool Indexing
print(obj2[obj2>0])

df=pd.DataFrame({
    "Fruit": ["Apple", "Banana", "Orange"],
    "Price":[2,3,4]
})
print(df)

