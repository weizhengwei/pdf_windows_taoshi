

cl /c png2pdf.c /D__WIN32__ /I".\include"

link png2pdf.obj pdflib.lib

png2pdf.exe

