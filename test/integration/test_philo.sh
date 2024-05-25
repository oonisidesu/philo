#!/bin/bash

# ログディレクトリの作成
mkdir -p test/integration/log

# テストケース 1: 1 800 200 200 哲学者は食事せず、死ぬべき
echo "Running Test Case 1: 1 800 200 200"
./philo 1 800 200 200 > test/integration/log/output1.txt &
PID1=$!
sleep 2
kill $PID1
wait $PID1 2>/dev/null
if grep -q "died" test/integration/log/output1.txt; then
  echo "Test Case 1 Passed"
else
  echo "Test Case 1 Failed"
fi

# テストケース 2: 5 800 200 200 哲学者は誰も死ぬべきでない
echo "Running Test Case 2: 5 800 200 200"
./philo 5 800 200 200 > test/integration/log/output2.txt &
PID2=$!
sleep 5
kill $PID2
wait $PID2 2>/dev/null
if grep -q "died" test/integration/log/output2.txt; then
  echo "Test Case 2 Failed"
else
  echo "Test Case 2 Passed"
fi

# テストケース 3: 5 800 200 200 7 哲学者は誰も死ぬべきでなく、全ての哲学者が少なくとも7回食事したときにシミュレーションが終了するべき
echo "Running Test Case 3: 5 800 200 200 7"
./philo 5 800 200 200 7 > test/integration/log/output3.txt &
PID3=$!
sleep 10
kill $PID3
wait $PID3 2>/dev/null
if grep -q "died" test/integration/log/output3.txt; then
  echo "Test Case 3 Failed"
else
  echo "Test Case 3 Passed"
fi

# テストケース 4: 4 410 200 200 哲学者は誰も死ぬべきでない
echo "Running Test Case 4: 4 410 200 200"
./philo 4 410 200 200 > test/integration/log/output4.txt &
PID4=$!
sleep 5
kill $PID4
wait $PID4 2>/dev/null
if grep -q "died" test/integration/log/output4.txt; then
  echo "Test Case 4 Failed"
else
  echo "Test Case 4 Passed"
fi

# テストケース 5: 4 310 200 100 1人の哲学者が死ぬべき
echo "Running Test Case 5: 4 310 200 100"
./philo 4 310 200 100 > test/integration/log/output5.txt &
PID5=$!
sleep 2
kill $PID5
wait $PID5 2>/dev/null
if grep -q "died" test/integration/log/output5.txt; then
  echo "Test Case 5 Passed"
else
  echo "Test Case 5 Failed"
fi

# テストケース 6: 2人の哲学者でテストし、異なる時間を確認
echo "Running Test Case 6: 2 800 200 200"
./philo 2 800 200 200 > test/integration/log/output6.txt &
PID6=$!
sleep 5
kill $PID6
wait $PID6 2>/dev/null
if grep -q "died" test/integration/log/output6.txt; then
  echo "Test Case 6 Failed"
else
  echo "Test Case 6 Passed"
fi
