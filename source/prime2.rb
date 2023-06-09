# 変数primes に 100までの素数達の配列[3, 5, 7, ... , 97] を代入する
primes = [3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]

# 101から1000まで2つずつ順に数nを増やす
101.step(1000, 2) do |n|
  # flag(旗)を用意する。最初はtrue(眞)にして置く。
  flag = true

  # 素数達の配列primes[3, 5, 7, ... , 97] から順に一つずつ取り出して、
  # prime に セットする。
  # prime は最初は 3 だが、5 になり、 7 になりと、
  # 最後の 97 になるまで、do ~ end 内の処理を繰り返す。
  primes.each do |prime|
    # divmod は、割り算の商と余りを同時に求める演算(メソッド)です。
    # n を prime で割った商をqに、余りをrに代入します。
    q, r = n.divmod(prime)
    # もし 余り r が 0 に等しいならば
    if r == 0
      # flag を 倒す。
      # false(偽)をセットする。
      flag = false
      # break(中断)
      break
    end

    # もし q < prime となっており、
    # その時にまだ flag が眞のままならば
    # 971 ÷ 37 =  26 余り 9 なので 割り切れず、flag は 眞のままである。
    # つまり素数なので、
    if q < prime && flag == true
      # 素数達の配列に、素数として新しく見つかった数nをpush(押し込む)する。
      primes.push(n)
      # 素数として発見できたので、
      # もう他の素数で割って検証する必要もない。
      # なので、break(中断)して、
      # 次の素数候補の検証に移ることとする。
      break
    end
  end
end

# 最後に 素数達を表示する
p primes
