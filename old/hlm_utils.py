from pathlib import Path
import time 
import os
import pandas as pd

def parse_and_cache(org_dir, file_path="./data/hlm.xlsx"):
    """
    Parse the files in "org_dir" and cache a url and return a prepared DataFrame object.
    
    org_dir: the directory that contains the original text
    file_path: the file in which to save the DataFrame object.    
    return: The DataFrame object.
    """
    # If the file already exists and we want to force a new version then
    # delete the file first so that the creation date is correct.

    print('Parsing...', end=' ')
    filenames = os.listdir(org_dir)
    filenames.sort(key= lambda x:int(x[:-4]))
    chapters = []
    chapter_name = []
    chapter_content = []
    for filename in filenames:
        with open(os.path.join(org_dir, filename)) as f:
            title = f.readline()
            content = f.read()
            title = title.strip('\n').split('\u3000')
            chapters.append(title[0])
            chapter_name.append(title[1])
            chapter_content.append(content)
    data_dict = {'Chapter': chapters, 'Title': chapter_name, 'Content': chapter_content}
    df = pd.DataFrame(data_dict)
    df.to_excel(file_path, index=None)
    print('Done!')
    return df
