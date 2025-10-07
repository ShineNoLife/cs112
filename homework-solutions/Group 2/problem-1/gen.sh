#!/bin/bash
set -e

# =========================
# Lấy seed từ tham số đầu
# =========================
base_seed=${1:-1000}   # nếu không truyền thì mặc định 1000

echo "[Info] Base seed = ${base_seed}"

echo "[Compile] Building generators and solution..."
g++ -std=c++17 -O2 -pipe -static -s validator.cpp  -o validator
g++ -std=c++17 -O2 -pipe -static -s solution.cpp   -o solution
g++ -std=c++17 -O2 -pipe -static -s gen/gen-sub1.cpp   -o gen-sub1
g++ -std=c++17 -O2 -pipe -static -s gen/gen-sub2.cpp   -o gen-sub2
g++ -std=c++17 -O2 -pipe -static -s gen/genEdgeCase.cpp   -o genEdgeCase
g++ -std=c++17 -O2 -pipe -static -s gen/genNormalCase.cpp   -o genNormalCase
g++ -std=c++17 -O2 -pipe -static -s gen/genSpecialCase.cpp   -o genSpecialCase

echo "[Compile] Done."

rm -rf tests
mkdir -p tests

# Tổng số test dự kiến
total_tests=50

# Tính số chữ số cần padding, ví dụ:
# 9 -> 1, 50 -> 2, 123 -> 3
pad_width=${#total_tests}

last=0

gen_and_run() {
    local gen_bin=$1
    local type=$2
    local num=$3
    echo "${gen_bin} ${type} ${num}"

    for ((i=0; i<num; i++)); do
        last=$((last + 1))
        echo "${last}"
        # Tên test có padding động
        local test_name
        test_name=$(printf "test%0${pad_width}d" "${last}")
        mkdir -p "tests/${test_name}"

        # Seed cố định = base_seed + i
        local seed=$((base_seed + last))
        ./${gen_bin} ${type} ${seed} > "tests/${test_name}/input.in"
        ./validator < "tests/${test_name}/input.in"
        
        ./solution < "tests/${test_name}/input.in" > "tests/${test_name}/output.out"

        echo "[Gen] ${gen_bin} type=${type} seed=${seed} -> ${test_name}"
    done
}

# Subtask 1 (20 tests)
gen_and_run genNormalCase 1 10
gen_and_run genEdgeCase 1 1
gen_and_run genEdgeCase 2 1
gen_and_run genEdgeCase 3 1
gen_and_run genEdgeCase 4 5
gen_and_run genEdgeCase 5 1
gen_and_run genEdgeCase 6 1
gen_and_run genEdgeCase 7 1
gen_and_run genEdgeCase 8 5
gen_and_run genEdgeCase 9 5

for ((t=1;t<=4;t++)); do 
    gen_and_run genSpecialCase ${t} 5
done

gen_and_run gen-sub1 1 20
gen_and_run gen-sub2 1 20

echo "✅ All test data generated successfully with base seed ${base_seed}!"
