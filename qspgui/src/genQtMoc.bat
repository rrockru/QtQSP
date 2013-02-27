rem @ECHO OFF
FOR %%f IN (*.h) DO moc.exe %%f -o moc_%%~nf.cpp
