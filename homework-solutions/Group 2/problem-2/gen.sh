#!/bin/bash
set -e

# =========================
# Lấy seed từ tham số đầu
# =========================
base_seed=${1:-1000}   # nếu không truyền thì mặc định 1000
echo "[Info] Base seed = ${base_seed}"

# =========================
# Biên dịch tất cả chương trình
# =========================
echo "[Compile] Building generators, validator, and solution..."

g++ -std=c++17 -O2 -pipe -static -s validator.cpp  -o validator
g++ -std=c++17 -O2 -pipe -static -s solution.cpp   -o solution

# Build tất cả generator có trong thư mục gen/
g++ gen/genEdgeCase.cpp         -o genEdgeCase
g++ gen/genEdgeCase2.cpp        -o genEdgeCase2
g++ gen/genHandleTest1.cpp      -o genHandleTest1
g++ gen/genLine.cpp             -o genLine
g++ gen/genMaxDense.cpp         -o genMaxDense
g++ gen/genMaxSparse.cpp        -o genMaxSparse
g++ gen/genMaxStar.cpp          -o genMaxStar
g++ gen/genNormalCase.cpp       -o genNormalCase
g++ gen/genStressCase.cpp       -o genStressCase
g++ gen/gen-1.cpp               -o gen-1
g++ gen/genGPT.cpp              -o genGPT

echo "[Compile] Done."

# =========================
# Chuẩn bị thư mục test
# =========================
rm -rf tests
mkdir -p tests

# Tổng số test dự kiến
total_tests=50
pad_width=${#total_tests}
last=0

# =========================
# Hàm sinh và chạy generator
# =========================
gen_and_run() {
    local gen_bin=$1
    local type=$2
    local num=$3

    echo "[RunGen] ${gen_bin} type=${type} count=${num}"

    for ((i=0; i<num; i++)); do
        last=$((last + 1))
        local test_name
        test_name=$(printf "test%0${pad_width}d" "${last}")
        mkdir -p "tests/${test_name}"

        local seed=$((base_seed + last))
        ./${gen_bin} ${type} ${seed} > "tests/${test_name}/input.in"
        ./validator < "tests/${test_name}/input.in"
        ./solution < "tests/${test_name}/input.in" > "tests/${test_name}/output.out"
        echo "Shortest path: " 
        cat tests/${test_name}/output.out
        echo "[Gen] ${gen_bin} type=${type} seed=${seed} -> ${test_name}"
    done
}

# =========================
# Sinh dữ liệu test
# =========================

gen_and_run genNormalCase 1 10
gen_and_run genEdgeCase 1 1
gen_and_run genEdgeCase2 1 1
gen_and_run genLine 1 3
gen_and_run genMaxDense 1 3
gen_and_run gen-1 0 10
gen_and_run genMaxSparse 1 3
gen_and_run genMaxStar 0 3
gen_and_run genMaxStar 1 3
gen_and_run genStressCase 1 15
gen_and_run genHandleTest1 1 1
gen_and_run gen-1 1 10
for((x=1;x<=10;x++)); do
    gen_and_run genGPT ${x} 3
done

echo "✅ All test data generated successfully with base seed ${base_seed}!"
