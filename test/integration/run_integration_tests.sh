#!/bin/bash

# コンパイル
make re

# 結果を保存するディレクトリの設定
RESULTS_DIR="test/integration/log"

# 結果を保存するディレクトリを作成
mkdir -p "$RESULTS_DIR"

run_test_case() {
  local test_case=$1
  local command=$2

  echo "Running test case $test_case..."
  eval "$command > $RESULTS_DIR/test_case_$test_case.log 2>&1 &"
  local pid=$!

  sleep 5

  if ps -p $pid > /dev/null; then
    echo "Test case $test_case is taking too long, killing process..."
    pkill philo
  else
    echo "Test case $test_case completed successfully."
  fi
}

run_invalid_test_case() {
  local test_case=$1
  local command=$2

  echo "Running invalid test case $test_case..."
  eval "$command 2> $RESULTS_DIR/invalid_test_case_$test_case.log"
  echo "Invalid test case $test_case completed."
}

# 正常なテストケース
run_test_case 1 "./philo 4 400 410 400"
run_test_case 2 "./philo 5 800 200 200"
run_test_case 3 "./philo 2 300 200 100"
run_test_case 4 "./philo 10 800 200 200"
run_test_case 5 "./philo 3 600 300 300 5"
run_test_case 6 "./philo 4 400 500 300"
run_test_case 7 "./philo 1 1000 500 500"
run_test_case 8 "./philo 100 5000 1000 1000"
run_test_case 9 "./philo 4 10 5 5"
run_test_case 10 "./philo 5 1000 500 500"

# 不正な引数のテストケース
run_invalid_test_case 11 "./philo"  # 引数なし
run_invalid_test_case 12 "./philo 3"  # 引数不足
run_invalid_test_case 13 "./philo -1 800 200 200"  # 負の数
run_invalid_test_case 14 "./philo 3 abc 200 200"  # 数値以外の引数
run_invalid_test_case 15 "./philo 3 800 200"  # 引数不足
run_invalid_test_case 16 "./philo 3 800 200 200 5 10"  # 引数過多

echo "All tests completed."
