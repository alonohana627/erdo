./build/RationalTest.exe
./build/VectorTest.exe
./build/MatrixTest.exe

Set-Location build
ctest .
Set-Location ..