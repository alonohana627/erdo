./build/RationalTest.exe
./build/VectorTest.exe
./build/MatrixTest.exe
./build/BasicTypeTraitsTest.exe

Set-Location build
ctest .
Set-Location ..
