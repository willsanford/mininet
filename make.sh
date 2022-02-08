rm -rf build
cmake -S. -Bbuild
cmake --build build

echo
echo "*************************************************"
echo "****************RUNNING UNITTESTS****************"
./build/unittest
echo "****************UNITTEST FINISHED****************"
echo "*************************************************"

echo

echo "*************************************************"
echo "****************RUNNING SPEEDTEST****************"
variable=`./build/speedtest`
echo "1000x1000 Tensor multiplication ran in"
echo $variable
echo "microseconds"
echo "****************SPEEDTEST FINISHED***************"
echo "*************************************************"
