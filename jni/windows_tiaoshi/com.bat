

cl /c png2pdf_last.c /D__WIN32__ /DTEST /I".\include"

link png2pdf_last.obj pdflib.lib

png2pdf_last.exe

