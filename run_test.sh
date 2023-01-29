cd $1

# Compile
g++ main.cpp -o main.o

INPUTS=($(ls input/* | sort))
OUTPUTS=($(ls output/* | sort))
for (( i=0; i<${#INPUTS[*]}; ++i)); do
    # Run test
    ./main.o > test_output.txt 2>&1 < ${INPUTS[$i]}

    # Check result
    STATUS="$(cmp --silent test_output.txt ${OUTPUTS[$i]}; echo $?)"  
    if [[ $STATUS -ne 0 ]]; then
        echo "Test ${INPUTS[$i]} failed!"
    else
        echo "Test ${INPUTS[$i]} passed!"
    fi

    # Remove output file
    rm -f test_output.txt
done