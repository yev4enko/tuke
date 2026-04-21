import shutil
import os

def fillallthedirs(directory = '.'):
    filesdirectory1 = './files/test1.zip.pdf'
    filesdirectory2 = './files/test2.zip.pdf'
    filesdirectory3 = './files/test3.zip.pdf'
    t1 = './test1/test1.zip.pdf'
    t2 = './test2/test2.zip.pdf'
    t3 = './test3/test3.zip.pdf'
    
    shutil.copyfile(filesdirectory1, t1)  
    shutil.copyfile(filesdirectory2, t2)  
    shutil.copyfile(filesdirectory3, t3) 
        
fillallthedirs()          