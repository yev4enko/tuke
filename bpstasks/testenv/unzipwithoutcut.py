import os 
import zipfile

def filesearch(directory = '.'):
    for folder in os.listdir(directory):
        if folder.startswith("test"):
            path_folder = os.path.join(directory, folder)
            if os.path.isdir(path_folder):
                for filename in os.listdir(path_folder):
                    if filename.startswith("test") and filename.endswith(".zip.pdf"):
                        oldname = os.path.join(path_folder, filename)   
                        try: 
                            with zipfile.ZipFile(oldname,'r') as zip_ref:
                                zip_ref.extractall(path_folder)
                                print("UNZIP - OK") 
                        except Exception as e:
                            print("UNZIP - FAILED (name)")   
                        
    
def main():
        filesearch()
        
                
if __name__ == "__main__":
    main()                