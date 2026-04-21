import os 
import zipfile

def filesearch(directory = '.'):
    for folder in os.listdir(directory):
        if folder.startswith("test"):
            path_folder = os.path.join(directory, folder)
            if os.path.isdir(path_folder):
                for filename in os.listdir(path_folder):
                    if filename.startswith("test") and filename.endswith(".zip.pdf"):
                        onld_path_folder = os.path.join(path_folder, filename)
                        newname = filename.replace(".zip.pdf",".zip")
                        new_path_foder = os.path.join(path_folder, newname)
                        os.rename(onld_path_folder, new_path_foder)
                        print(f"OK - RENAMED FROM {onld_path_folder } TO {new_path_foder}")
                    try: 
                        with zipfile.ZipFile(new_path_foder,'r') as zip_ref:
                            zip_ref.extractall(path_folder)
                            print("UNZIP - OK") 
                    except Exception as e:
                        print("UNZIP - FAILED (name)")   
                        
    
def main():
        filesearch()
        
                
if __name__ == "__main__":
    main()                