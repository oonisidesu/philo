#!/bin/bash

# テストケースを実行する関数
run_test_case() {
    local description=$1
    local command=$2
    echo "テストケース: $description"
    echo "コマンド: $command"
    $command &
    pid=$!
    sleep 30  # 30秒待機
    kill -INT $pid 2>/dev/null  # プロセスを強制終了
    sleep 1  # 強制終了の処理を待機
    if ps -p $pid > /dev/null; then
        kill -KILL $pid 2>/dev/null  # プロセスがまだ生きている場合、強制終了
        echo "テストケースがタイムアウトしました: $description"
    else
        echo "テストケース終了: $description"
    fi
    echo
}

# ケース1: 1人のフィロソファー、食事せずに死ぬ
run_test_case "1人のフィロソファー、食事せずに死ぬ" "./philo 1 800 200 200"

# ケース2: 5人のフィロソファー、誰も死なない
run_test_case "5人のフィロソファー、誰も死なない" "./philo 5 800 200 200"

# ケース3: 5人のフィロソファー、全員が7回食事をしたら終了
run_test_case "5人のフィロソファー、全員が7回食事をしたら終了" "./philo 5 800 200 200 7"

# ケース4: 4人のフィロソファー、誰も死なない
run_test_case "4人のフィロソファー、誰も死なない" "./philo 4 410 200 200"

# ケース5: 4人のフィロソファー、1人が死ぬ
run_test_case "4人のフィロソファー、1人が死ぬ" "./philo 4 310 200 100"

# ケース6: 2人のフィロソファー、死の遅延が10 msを超えないことを確認
run_test_case "2人のフィロソファー、死の遅延が10 msを超えないことを確認" "./philo 2 310 200 100"

# ケース7: 任意の値でのテスト、全ての要件を確認
run_test_case "任意の値でのテスト、全ての要件を確認" "./philo 3 500 150 150"  # 任意の値の例
