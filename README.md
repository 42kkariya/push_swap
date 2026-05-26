*This project has been created as part of the 42 curriculum by kkariya, mtaisei.*

# push_swap

## Description

push_swap is a sorting algorithm project from the 42 curriculum. The goal is to sort a list of integers using two stacks (a and b) and a limited set of operations, using the fewest possible moves.

The program implements four distinct sorting strategies and selects the most appropriate one at runtime based on a disorder metric computed from the input.

**Allowed operations:**

| Operation | Description |
|---|---|
| `sa` / `sb` | Swap the top two elements of stack a / b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` / `pb` | Push the top element of stack b to a / a to b |
| `ra` / `rb` | Rotate stack a / b upward (top becomes bottom) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` / `rrb` | Reverse rotate stack a / b (bottom becomes top) |
| `rrr` | `rra` and `rrb` simultaneously |

## Instructions

### Build

```bash
make        # build push_swap
make clean  # remove object files
make fclean # remove object files and binary
make re     # rebuild from scratch
```

### Usage

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <integers>
```

Arguments can be passed as individual values or as a quoted string:

```bash
./push_swap 5 4 3 2 1
./push_swap "5 4 3 2 1"
```

**Optional flags:**

| Flag | Description |
|---|---|
| `--simple` | Force O(n²) selection sort |
| `--medium` | Force O(n√n) chunk sort |
| `--complex` | Force O(n log n) radix sort |
| `--adaptive` | Automatic strategy selection based on disorder (default) |
| `--bench` | Print performance metrics to stderr |

### Verify with checker

```bash
./push_swap 5 3 1 4 2 | ./checker_linux 5 3 1 4 2
```

### Benchmark example

```bash
shuf -i 0-9999 -n 500 > args.txt
./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
cat bench.txt
```

## Algorithm

### Disorder Metric

Before sorting, the program computes a disorder score — the ratio of inversions (pairs out of order) to the maximum possible inversions:

```
disorder = inversions / (n × (n − 1) / 2)
```

- `0.0` = already sorted
- `1.0` = fully reversed

This is measured before any operations are performed.

### Adaptive Dispatch

The adaptive strategy selects an algorithm based on disorder and input size:

| Condition | Strategy | Complexity |
|---|---|---|
| n ≤ 5 | sort_turk | O(1) bounded (≤ 10 ops) |
| disorder < 0.2 | sort_simple | O(n²) |
| 0.2 ≤ disorder < 0.5 | sort_chunk | O(n√n) |
| disorder ≥ 0.5 | sort_turk | O(n log n) empirically |

**Threshold rationale:**
- **n ≤ 5**: For very small inputs, dispatcher overhead is not justified. sort_turk handles all cases within 10 operations.
- **0.2 threshold**: Below 20% inversions, the data is nearly sorted. Selection sort requires very few rotations per step, making O(n²) efficient in practice.
- **0.5 threshold**: Above 50% inversions, the data is sufficiently random that sort_turk's greedy cost minimisation outperforms chunk-based approaches.

### sort_turk — Greedy Insertion Sort

Used for n ≤ 5 and high-disorder inputs (≥ 0.5).

1. Push all but 3 elements to stack b, using a median threshold to split smaller and larger values — this pre-sorts b so adjacent elements in b tend to have adjacent target positions in a
2. Sort the remaining 3 elements in stack a (at most 2 operations)
3. For each element in b, compute the minimum-cost insertion into the correct position in a, combining ra/rra and rb/rrb as rr/rrr where possible
4. Execute the cheapest move and repeat until b is empty
5. Rotate a to bring the minimum to the top

**Complexity argument (Push_swap operation model):**
The pre-sorting step in phase 1 (O(n)) ensures that, on average, each merge step in phase 3 requires O(log n) rotations rather than O(n). The table below shows that ops/n log n stays roughly constant (~0.85–1.16) across a wide range of n, confirming O(n log n) class behaviour. In contrast, ops/n² shrinks as n grows, ruling out O(n²). For reference, radix sort (a formally proven O(n log n) algorithm) shows a higher constant factor (~1.5–1.7×), demonstrating that sort_turk achieves better real-world performance within the same complexity class.

| n | sort_turk avg ops | ops / n log n | ops / n² | radix avg ops | radix ops / n log n |
|---:|---:|---:|---:|---:|---:|
| 50 | 240 | 0.851 | 0.096 | 467 | 1.655 |
| 100 | 567 | 0.853 | 0.057 | 1084 | 1.632 |
| 200 | 1385 | 0.906 | 0.035 | 2468 | 1.614 |
| 300 | 2340 | 0.948 | 0.026 | 4220 | 1.709 |
| 500 | 4571 | 1.020 | 0.018 | 6784 | 1.513 |
| 800 | 8543 | 1.107 | 0.013 | 12272 | 1.591 |
| 1000 | 11600 | 1.164 | 0.012 | 15068 | 1.512 |

### sort_chunk — Chunk Sort

Used for medium-disorder inputs (0.2 ≤ disorder < 0.5).

Divides the value range into √n chunks and pushes elements to b chunk by chunk (smaller chunks first), then pops back to a in sorted order.

**Complexity argument:** √n chunks × O(n) rotations per chunk = O(n√n) Push_swap operations.

### sort_simple — Selection Sort

Used for low-disorder inputs (disorder < 0.2).

Repeatedly finds the minimum element in a, rotates it to the top, pushes to b, then pops all back from b to a in reverse order.

**Complexity argument:** n iterations × O(n) rotations per step = O(n²) Push_swap operations. For nearly-sorted inputs the average rotation cost per step is small, so this is efficient in the low-disorder regime.

### sort_radix — Radix Sort (LSD)

Available via `--complex`. Sorts by bit position from least significant to most significant bit.

**Complexity argument:** ceil(log₂n) bit passes × O(n) operations per pass = O(n log n) Push_swap operations, with constant factors independent of input order.

## Performance Results

| Input | Avg ops | Max ops | Limit | Rating |
|---|---|---|---|---|
| n=5 (all 120 permutations) | 7.9 | 10 | 12 | Excellent |
| n=100 (100 random trials) | ~570 | ~640 | 700 | Excellent |
| n=500 (2000 random trials) | ~4800 | ~5311 | 5500 | Excellent |

Benchmarks run on random permutations of integers in range [1, n] using the default adaptive strategy.

## Contributions

**kkariya** — Algorithm implementation (sort_turk, sort_chunk, sort_simple, sort_radix, adaptive dispatch), overall file structure design and refactoring, bug fixes.

**mtaisei** — Input parsing (argument validation, integer conversion, multi-string support), bonus checker implementation.

## Resources

- [push_swap アルゴリズム解説 (Zenn)](https://zenn.dev/uta_san1012/articles/bfa9cabfeadc51)
- [push_swap の実装 (Qiita)](https://qiita.com/MoriP-K/articles/54ee96dc634148cf40a8)
- [push_swap turk algorithm explained (Medium)](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)
- [転倒数 (Qiita)](https://qiita.com/drken/items/872ebc3a2b5caaa4a0d0)
- [push_swap visualizer](https://github.com/o-reo/push_swap_visualizer)
- [push_swap tester](https://github.com/nafuka11/push_swap_tester)
- [DeepL Translator](https://www.deepl.com/ja/translator)
- Push_swap subject (Version 1.1) — 42 Tokyo

### AI Usage

**kkariya** used Claude (Anthropic) for the following tasks:

- **Algorithm design**: discussing implementation approaches for sort_turk and the adaptive dispatch strategy
- **Code review**: identifying bugs such as integer overflow in `ft_atoi`, missing newlines in error messages, and a segfault on empty input
- **Bug fixing**: working through the correct fix for each issue found during review
- **README**: translating and refining Japanese descriptions into natural English (to avoid the literal phrasing common in machine translation)

All AI-generated suggestions were reviewed, tested, and understood by both team members before being incorporated into the project.

---

# 日本語版

## 概要

push_swap は 42 カリキュラムのソートアルゴリズム課題です。2つのスタック（a と b）と限られた操作のみを使って整数列をソートし、操作回数を最小化することが目標です。

プログラムは4種類のソート戦略を実装しており、入力から計算した disorder（乱雑度）指標に基づいて実行時に最適な戦略を選択します。

**使用できる操作：**

| 操作 | 説明 |
|---|---|
| `sa` / `sb` | スタック a / b の上2要素を入れ替える |
| `ss` | `sa` と `sb` を同時に実行 |
| `pa` / `pb` | スタック b / a の先頭要素を a / b の先頭に移動 |
| `ra` / `rb` | スタック a / b を上方向に1つ回転（先頭が末尾へ） |
| `rr` | `ra` と `rb` を同時に実行 |
| `rra` / `rrb` | スタック a / b を下方向に1つ回転（末尾が先頭へ） |
| `rrr` | `rra` と `rrb` を同時に実行 |

## 使い方

### ビルド

```bash
make        # push_swap をビルド
make clean  # オブジェクトファイルを削除
make fclean # オブジェクトファイルとバイナリを削除
make re     # 最初からリビルド
```

### 実行

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <整数列>
```

引数は個別に渡すこともクォートでまとめて渡すこともできます：

```bash
./push_swap 5 4 3 2 1
./push_swap "5 4 3 2 1"
```

**オプションフラグ：**

| フラグ | 説明 |
|---|---|
| `--simple` | O(n²) 選択ソートを強制使用 |
| `--medium` | O(n√n) チャンクソートを強制使用 |
| `--complex` | O(n log n) 基数ソートを強制使用 |
| `--adaptive` | disorder に基づく自動戦略選択（デフォルト） |
| `--bench` | 操作数などのメトリクスを stderr に出力 |

### チェッカーによる検証

```bash
./push_swap 5 3 1 4 2 | ./checker_linux 5 3 1 4 2
```

### ベンチマーク例

```bash
shuf -i 0-9999 -n 500 > args.txt
./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
cat bench.txt
```

## アルゴリズム

### Disorder（乱雑度）指標

ソート前に disorder スコアを計算します。これは「順序が逆になっているペアの数（転倒数）」を「最大転倒数」で割った値です：

```
disorder = 転倒数 / (n × (n − 1) / 2)
```

- `0.0` = 完全にソート済み
- `1.0` = 完全に逆順

操作を一切行う前に計測します。

### Adaptive（適応的）ディスパッチ

disorder と入力サイズに基づいてアルゴリズムを選択します：

| 条件 | 戦略 | 計算量 |
|---|---|---|
| n ≤ 5 | sort_turk | 定数（≤ 10 操作） |
| disorder < 0.2 | sort_simple | O(n²) |
| 0.2 ≤ disorder < 0.5 | sort_chunk | O(n√n) |
| disorder ≥ 0.5 | sort_turk | O(n log n)（実測） |

**閾値の選定理由：**
- **n ≤ 5**：非常に小さい入力ではディスパッチのオーバーヘッドが不要。sort_turk が全パターンを10操作以内で処理できるため固定使用。
- **閾値 0.2**：転倒数が20%未満はほぼソート済み。選択ソートは各ステップで少ない回転しか必要とせず O(n²) でも実用的に高速。
- **閾値 0.5**：転倒数が50%以上では sort_turk の貪欲法がチャンクソートを上回る。

### sort_turk — 貪欲挿入ソート

n ≤ 5 および high-disorder（≥ 0.5）の入力に使用します。

1. n-3 個の要素を median 閾値で大小に分けながら stack b に push（b内の隣接要素が a 内の近い挿入位置を持つよう事前整列）
2. stack a に残った3要素を最大2操作でソート
3. b の各要素について、a への最小コスト挿入位置を計算し ra/rra と rb/rrb を rr/rrr に統合しながら実行
4. 全要素が a に戻るまで繰り返す
5. a を回転させて最小値を先頭へ

**計算量の根拠（Push_swap 操作数モデル）：**
フェーズ1の事前整列（O(n)）により、フェーズ3の各マージステップで必要な回転数は平均 O(n) ではなく O(log n) となります。以下の実測データが O(n log n) クラスの振る舞いを裏付けています。ops/n log n がほぼ一定（0.85〜1.16）であるのに対し、ops/n² は n の増加に伴い減少しており、O(n²) ではないことも確認できます。また、形式的に O(n log n) が証明されている基数ソートと比較して、定数係数が約1.5〜1.7倍小さく、同じ計算量クラスの中でより実用的な性能を発揮しています。

| n | sort_turk 平均操作数 | ops / n log n | ops / n² | radix 平均操作数 | radix ops / n log n |
|---:|---:|---:|---:|---:|---:|
| 50 | 240 | 0.851 | 0.096 | 467 | 1.655 |
| 100 | 567 | 0.853 | 0.057 | 1084 | 1.632 |
| 200 | 1385 | 0.906 | 0.035 | 2468 | 1.614 |
| 300 | 2340 | 0.948 | 0.026 | 4220 | 1.709 |
| 500 | 4571 | 1.020 | 0.018 | 6784 | 1.513 |
| 800 | 8543 | 1.107 | 0.013 | 12272 | 1.591 |
| 1000 | 11600 | 1.164 | 0.012 | 15068 | 1.512 |

### sort_chunk — チャンクソート

medium-disorder（0.2 ≤ disorder < 0.5）の入力に使用します。

値の範囲を √n 個のチャンクに分割し、小さいチャンクから順に b へ push、その後 a にソートしながら戻します。

**計算量の根拠：** √n チャンク × チャンクあたり O(n) 回転 = O(n√n) Push_swap 操作。

### sort_simple — 選択ソート

low-disorder（disorder < 0.2）の入力に使用します。

a の最小要素を繰り返し先頭に回転させて b へ push し、最後に全要素を a に戻します。

**計算量の根拠：** n イテレーション × 各ステップ O(n) 回転 = O(n²) Push_swap 操作。ほぼソート済みの入力では各ステップの回転数が少なく、この計算量域では実用的に高速。

### sort_radix — 基数ソート（LSD）

`--complex` フラグで使用できます。最下位ビットから最上位ビットへとビット単位でソートします。

**計算量の根拠：** ceil(log₂n) ビットパス × パスあたり O(n) 操作 = O(n log n) Push_swap 操作。入力順序に関わらず定数係数が一定。

## 性能計測結果

| 入力 | 平均操作数 | 最大操作数 | 制限 | 評価 |
|---|---|---|---|---|
| n=5（全120通り） | 7.9 | 10 | 12 | Excellent |
| n=100（100回ランダム試行） | ~570 | ~640 | 700 | Excellent |
| n=500（2000回ランダム試行） | ~4800 | ~5311 | 5500 | Excellent |

計測はデフォルトの adaptive 戦略を使用し、[1, n] の整数のランダム置換で実施。

## 分担

**kkariya** — アルゴリズム実装（sort_turk、sort_chunk、sort_simple、sort_radix、adaptive ディスパッチ）、ファイル構成の設計とリファクタリング、バグ修正

**mtaisei** — 入力パース（引数バリデーション、整数変換、複数文字列対応）、bonus パートのチェッカー実装

## 参考資料

- [push_swap アルゴリズム解説 (Zenn)](https://zenn.dev/uta_san1012/articles/bfa9cabfeadc51)
- [push_swap の実装 (Qiita)](https://qiita.com/MoriP-K/articles/54ee96dc634148cf40a8)
- [push_swap turk algorithm explained (Medium)](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)
- [転倒数 (Qiita)](https://qiita.com/drken/items/872ebc3a2b5caaa4a0d0)
- [push_swap visualizer](https://github.com/o-reo/push_swap_visualizer)
- [push_swap tester](https://github.com/nafuka11/push_swap_tester)
- [DeepL Translator](https://www.deepl.com/ja/translator)
- Push_swap subject (Version 1.1) — 42 Tokyo

### AI の使用について

**kkariya** が Claude（Anthropic）を以下の用途で使用しました：

- **アルゴリズム設計**：sort_turk および adaptive ディスパッチ戦略の実装方針の検討
- **コードレビュー**：`ft_atoi` の整数オーバーフロー、エラーメッセージの改行漏れ、空入力時のセグメンテーションフォルトなどのバグ発見
- **バグ修正**：発見された各問題の修正方法の検討
- **README 作成**：日本語での説明を自然な英語に翻訳・整文（機械翻訳の直訳表現を避けるため）

AI が生成した提案はすべて両メンバーがレビュー・テスト・理解した上でプロジェクトに取り込んでいます。
