call vs2010

cl /c  text_demo.c grid_sheet.c /D__WIN32__   /I"..\..\include" /I"..\..\win32\include" 

link  text_demo.obj grid_sheet.obj pdflib.lib

pause