cd $1

# Compile
g++ main.cpp -o main.o

# Run
./main.o > test_output.txt 2>&1 < input/input.txt

# Check result
STATUS="$(cmp --silent test_output.txt output/output.txt; echo $?)"  
if [[ $STATUS -ne 0 ]]; then
    echo "Test failed!"
else
    echo "Test passed!"
fi