import shutil
import os 

def cutallfilesiindirs(directory = '.'):
    for folder in os.listdir(directory):
        if folder.startswith("test"):
            folder_path = os.path.join(directory, folder)
            for root, dirs, files in os.walk(folder_path):
                for filename in files:
                    file_cut = os.path.join(folder_path, filename)
                  #  print(f"{file_cut}")
                    try:
                        os.remove(file_cut)
                        print(f"FILE '{file_cut}' DELLETTED.")
                    except FileNotFoundError as e: 
                        print(f"FILE '{file_cut}' NOT FOUND")
                for directory in dirs:        
                    dir_path = os.path.join(folder_path, directory)
                    print(f"{dir_path}")
                    try:
                        shutil.rmtree(dir_path)
                        print(f"FILE '{dir_path}' DELLETTED.")
                    except FileNotFoundError as e: 
                        print(f"FILE '{dir_path}' NOT FOUND")
                    
                    
cutallfilesiindirs()            