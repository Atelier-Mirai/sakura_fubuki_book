= じゃんけんゲームの完成
//abstract{
  長かったじゃんけんゲームの旅もあと一息です。
  前章では、利用者に心地よく使ってもらえるよう、CSSを導入し綺麗な意匠を整えました。
  この章では、JavaScriptのコードを追加し、いよいよじゃんけんゲームを完成させます。
  ウェブサイトへの公開方法も記載いたしましたので、是非遊んでみてください。
//}

利用者に心地よく使ってもらえるよう、HTMLを追記し、CSSを導入したことで、綺麗な意匠を実現しました。
美しい見栄えになったことで、創作意欲も湧きます。

この章では次の四点を実装し、遂にじゃんけんゲームが完成を迎えます。

  1. プレイヤーがどの手を出すのか、今までは、0, 1, 2 と、数字で入力していました。より人に分かりやすい、グーチョキパーの3つのボタンを用意し、それを押すことで、プレイヤーが手を選べるようにします。
  2. 今までは、コンピュータがどの手を出したのか、表示する機能がありませんでした。グーチョキパーどれを出しているのか明示し、アニメーション機能も実装します。
  4. ○勝○敗と、今までの勝敗を表示できるようにします。
#@# 5. 開始ボタンを分かりやすくするために、色を付け、大きくします。
#@#   6. じゃんけんを知らない人はいないとは思いますが、簡単な紹介文とWikipediaへのリンクを用意します。
#@#   7. じゃんけんゲームを見る端末はさまざまです。iPhoneで見る人もいますし、Macで見る人もいます。さまざまな端末で好ましい見た目を提供できるよう「レスポンシブデザイン」を行っていきます。
#@#
#@# このうち、5, 6, 7は既に完了していますから、残りの部分を、JavaScriptで実装していきましょう。

== プレイヤーの手の取得と コンピュータの手の表示

=== プレイヤーの手の取得
//list[][janken.js]{
// player の手を取得
const jankenInputBox = document.getElementById("player_hand_type");
let player = parseInt(jankenInputBox.value);
//}

これまでは、数値入力枠の中に利用者が0, 1, 2の数字を入力することによって、グーチョキパーを得ていました。今回より利用者に分かりやすいよう「UI/UX」の改善を図ったので、グーチョキパー、どのボタンが押されたのか取得する必要があります。
そのため、次のように書き換えましょう。

//list[][janken.js]{
const guu_button   = document.getElementById("guu");
const choki_button = document.getElementById("choki");
const paa_button   = document.getElementById("paa");
guu_button.addEventListener('click', jankenHandler);
choki_button.addEventListener('click', jankenHandler);
paa_button.addEventListener('click', jankenHandler);
//}

@<code>{document.getElementById("guu")} で、グーボタン要素を取得します。
そして、プログラム内で扱いやすいよう、 @<code>{guu_button} という変数に代入します。この後、 @<code>{guu_button} という名前で呼ぶことで、利用者が押したボタンの値を取得します。

@<code>{guu_button.addEventListener('click', jankenHandler);}
では、@<code>{click} イベントを聴取する関数として @<code>{jankenHandler} を設定しています。
これで、三つのボタンそれぞれが押されたら、ともに @<code>{jankenHandler} 関数が呼ばれるようになりました。
//blankline

それでは、@<code>{player}の手(@<code>{0}, @<code>{1}, @<code>{2})は、@<code>{jankenHandler}関数内ではどのようにして取得すれば良いのでしょうか？

//list[][]{
function jankenHandler(event) {
  // (略)
}
//}

@<code>{jankenHandler}に、引数 @<code>{event} が渡されていることに着目してください。@<code>{event.target} で、イベントの呼び出し元の要素を取得することができます。つまり、グー、チョキ、パー、どのボタンが押されたのかを知ることができます。

@<code>{event.target.value} と書くことで、 @<code>{<button id="guu" value="0"></button>} と書かれていた @<code>{value} 属性の値 @<code>{"0"} が取得できます。

@<code>{parseInt}は、文字列としての@<code>{"0"}を解析(@<code>{parse})し、整数値 @<code>{0}を返す関数です。

これで、グーボタンを押した時は @<code>{0}、チョキボタンを押した時は @<code>{1}, パーボタンを押した時は @<code>{2} が、@<code>{player}変数に格納されます。

//list[][]{
const player = parseInt(event.target.value);
//}

=== コンピュータの手の表示
今までは、コンピュータの手は表示されていませんでしたので、HTMLで次のように書くことで、グーの絵が表示されるようにしました。

//emlist[][html]{
<img id="computer_hand_type" src="guu.png">
//}

出来ればこれも、無作為に変わるようにしたいものです。JavaScriptでは、書かれたHTMLをプログラム上から動的に書き換えることができます。

//list[][]{
// コンピュータの手を無作為に決定する
computer = rand(0, 2);
// コンピュータの手の画像を動的に変更する
document.getElementById('computer_hand_type').src =
        ["guu.png", "choki.png", "paa.png"][computer];
//}

一行目は以前に触れた乱数でコンピュータの手を決定しています。二行目を解説します。

@<code>{document.getElementById('computer_hand_type')} で、HTMLファイルに書いた イメージ要素 を取得します。
@<code>{img} 変数には、 @<code>{<img id="computer_hand_type" src="guu.png">} が入っています。
 @<code>{src="guu.png"} と書いたので、グーの画像が表示されていました。

@<code>{const img = document.getElementById('computer_hand_type');} として、取得した要素を @<code>{img} という変数に格納します。そして取得した @<code>{img} 要素の @<code>{src} 属性を @<code>{choki.png} にすればチョキの画像を、 @<code>{paa.png} にすればパーの画像を表示させることができます。

JavaScript では、取得した要素の属性をいろいろ操作することができます。画像を変更するには、次のように書きます。

//list[][]{
  img.src = "choki.png";
//}

==== 配列

配列はとてもよく使われるデータ構造です。いくつかの変数を一緒のものとして扱いたい時に、重宝します。

グーの画像、チョキの画像、パーの画像 それぞれをまとめて扱いたいので、配列を使うととても便利です。

じゃんけんの手の画像の集まり（配列）として、 @<code>{images} という変数を宣言し、初期値として @<code>{"guu.png", "choki.png", "paa.png"} 三つの画像名があるようにします。

//list[][じゃんけん画像配列の宣言]{
const images = ["guu.png", "choki.png", "paa.png"];
//}

@<code>{const images = [];} と書くと、中身が空っぽの配列を作成することができます。
@<code>{const images = ["guu.png", "choki.png", "paa.png"]} と書くと、 @<code>{配列 images} の中に、 @<code>{"guu.png", "choki.png", "paa.png"} の三つの要素があるようになります。@<fn>{array}

//footnote[array][容器だけで中身は空っぽの幕の内弁当と、おかずとしてグーチョキパーの三つが入っている幕の内弁当を想像すると分かりやすいでしょうか。]

==== 配列内の要素の指定法

配列内の各要素を指定するには、配列名の後に @<code>{[何番目かを指示する数字]} と書きます。この「何番目かを指示する数字」のことを、@<B>{添字(そえじ)}と呼びます。

配列の要素は、 @<code>{0, 1, 2} と  @<code>{0} から数え始めますので、 @<code>{images[0]} と書くと、 @<code>{"guu.png"} を指定でき、 @<code>{images[1]} と書くと、 @<code>{"choki.png"} を指定できます。

逆に、@<code>{"paa.png"}が欲しい時には、@<code>{images[2]} と書くと良いです。

配列はとってもよく使う基礎的な@<B>{データ構造}で、少し大きなプログラムでは不可欠です。是非、習得なさってください。

//note[]{
  配列と並ぶ重要な@<B>{データ構造}に、 @<B>{連想配列} (ハッシュや辞書とも呼ばれます)があり、これもとても重要なのですが、紙幅の関係上、割愛いたします。さまざまな学習資源がありますので、ぜひ学んでみてください。
//}

無作為にグーチョキパーが表示されるようにしたいので、「乱数」を使うと便利です。
JavaScriptに標準で備わっている乱数からは、@<code>{0} から @<code>{1} の浮動小数点数が得られます。既にじゃんけん用の乱数を自作したので、それを使いましょう。

//list[][]{
// 乱数を利用して、コンピュータの手を無作為に決定する
computer = rand(0, 2);
//}

ですので、乱数で選ばれた画像ファイル名は、次のようになります。

//list[][]{
const image_filename = images[computer];
//}

よって、以下のように書くことで、画像ファイルを都度都度変更することができます。

//list[][]{
img.src = image_filename;
//}

つまり、一行ずつ分けて書くと次のようなコードになります。
//list[][一行ずつ分けて書いたコード]{
  computer             = rand(0, 2);
  images               = ["guu.png", "choki.png", "paa.png"];
  const image_filename = images[computer];
  img                  = document.getElementById('computer_hand_type');
  img.src              = image_filename;
//}

これを、それぞれの変数に代入するのではなく、まとめて書くと次のようになります。
//list[][まとめて書いたコード]{
computer = rand(0, 2);
document.getElementById('computer_hand_type').src =
         ["guu.png", "choki.png", "paa.png"][computer];
//}

ご自身の分かりやすいと感じる書き方で、実践してみてください。

== アニメーション機能と勝敗更新機能

=== アニメーション機能
JavaScriptから、コンピュータの手を切り替える方法は分かりました。
せっかくですので、アニメーション機能を実装したいところです。
「グー、チョキ、パー」と1秒間に24回絵が切り替わるとアニメーションの完成です。

//quote{
//noindent
fps 【frames per second】 フレーム毎秒
fpsとは、動画のなめらかさを表す単位の一つで、画像や画面を1秒間に何回書き換えているかを表したもの。24fpsの動画は1秒あたり24枚の静止画で構成され、約0.041秒（41ミリ秒）ごとに画像を切り替えて再生される。 @<fn>{fn-fps}
//}
//footnote[fn-fps][出典：IT用語辞典]

一定周期ごとに、処理を繰り返したいときに使う関数として、JavaScriptでは、 @<code>{setTimeout} という関数が用意されています。使い方は次の通りです。

//list[][]{
setTimeout(タイマーが満了した後に実行したい関数,
           指定した関数を実行する前に待つ時間をミリ秒単位で指定);
//}

関数名は、 @<code>{animation} や @<code>{changeComputerHand} も良いでしょう。そしてここでは、アニメーション機能がこのじゃんけんプログラムの主となる機能であることから、 @<code>{main} @<fn>{fn-101}という関数名にします。すると、次のように書けます。
//footnote[fn-101][JavaScriptはプログラムは上から順に実行されますが、C言語やJavaではmain関数から始まります。]

//list[][]{
setTimeout(main, 41);
//}

@<code>{41}ミリ秒ごとに一回ですから、@<code>{1000}ミリ秒ごとに、@<code>{24}回、じゃんけんの絵が入れ替わることになります。
そして、@<code>{41}と書くと、意味が分かりにくいので、 @<code>{FPS}という定数を定義しましょう。@<code>{FPS} は、@<code>{Frame Per Second} の略で、「一秒間あたり、何コマ（フレーム）を表示するか？」の意味です。

//list[][]{
const FPS   = 24; // 一秒間あたり、24コマ表示する
//}

この @<code>{FPS}を使って、次のように書き直してみましょう。

//list[][]{
setTimeout(main, 1000 / FPS);
//}

意味も明確になりますし、毎秒 @<code>{60} コマのフレームレートに変更したければ、一箇所、更新するだけですみますので、保守性も上がります。

#@# //list[フレームレートを変更した例][]{
#@# const FPS   = 60; // 一秒間あたり、60コマ表示する
#@# //}

いつもアニメーション表示中ではなく、「開始」ボタンを押した時に、アニメーションが始まり、プレイヤーが手を選んだら、アニメーションが停止するようにしましょう。

アニメーション実行中か、否かを表す変数として、 @<code>{isPause} 変数 @<fn>{is} を用いることにすると、次のように書けます。

//footnote[is][Animation is pause? が 変数名の由来です。]


//list[][]{
// グー・チョキ・パーの切替アニメを制御するための変数
// true なら、アニメーション停止
let isPause = true;

// コンピュータの手を無作為に変更し、
// グー・チョキ・パーの切替アニメを表示させる関数
function main(){
  if(!isPause){ // 停止中でなければ
    computer = rand(0, 2);
    document.getElementById('computer_hand_type').src =
            ["guu.png", "choki.png", "paa.png"][computer];
  }
  setTimeout(main, 1000 / FPS);
}
//}

コードの解説を行っていきます。

//list[][]{
if(!isPause){ // 停止中でなければ
//}

if 文の中の条件式には、真偽値を直接書くこともできます。
「!」は否定演算子です。isPauseがtrue(真)だった時には、!isPauseはfalse(偽)となりますので、 @<code>{if(!isPause){ // 停止中でなければ \}} として、アニメーション切り替えのための @<code>{setTimeout関数} を呼び出しています。

注目して欲しいのは、main関数の中に書かれているsetTimeout関数から、もう一度、自分自身の関数mainを呼び出していることです。
自分自身を呼び出す関数のことを「@<B>{再帰関数}」といいます。
プログラミングを行う際に、時々出現するテクニックです。

=== アニメーションの開始と終了処理

//list[][]{
// グー・チョキ・パーの切替アニメを制御するための変数
// trueなら、アニメーション停止
let isPause = true;
//}

//list[][]{
// 切替アニメを停止し、もう一度、じゃんけんを行います
function pause(){
  isPause = true;
}

// 切替アニメを再開し、もう一度、じゃんけんを行います
function resume(){
  isPause = false;
}
//}

@<code>{isPause} という変数に、@<code>{true}, または @<code>{false} をセットしているだけの関数ですが、 @<code>{pause 停止}、 @<code>{resume 再開} と名前を付けることで、コードを読むだけで意図を汲み取ることができ、とても分かりやすくなります。名前はとっても重要です。

#@# 少し、寄り道とはなりますが、@<B>{プログラミング言語Ruby}の作者として名高い、@<B>{まつもとゆきひろ}さんのエッセイをご紹介いたします。
#@#


=== 勝敗更新機能の実装
最後に、勝敗更新機能を実装しましょう。

勝負の結果に応じて、○勝○敗を更新していきたいので、@<code>{jankenHandler}内に実装するのが良さそうです。

既に勝敗結果を得る処理は書いていますから、次のように書くと良いでしょう。

//list[][]{
// 勝敗に応じ、メッセージ表示＆勝敗更新
if (result === DRAW) {
  alert('引き分けです!');
} else if (result === LOSE) {
  alert('あなたの負けです!');
  // 敗数を一つ増やす
  updateScore(LOSE);
} else {
  alert('あなたの勝ちです!');
  // 勝数を一つ増やす
  updateScore(WIN);
}
//}

@<code>{updateScore} という関数を作って、その引数として、 @<code>{LOSE} 敗北か、 @<code>{WIN} 勝利を渡しています。実際の処理は、 @<code>{updateScore} 内で行っていますが、こうやって字面を読むだけでも処理の内容が分かり、コードの見通しがよくなります。

それでは、 @<code>{updateScore} 関数ですが、どのように書けば良いでしょうか？
勝ち数、負け数は、HTML内で @<code>{<span id="win">0</span>} のように書いていました。

JavaScriptで扱いやすいよう、ID属性を付与したので、 @<code>{document.getElementById("win")} と書けばこの @<code>{win} 要素を取得できます。早速 @<code>{win} 変数に格納しましょう。

@<code>{win.textContent} と書くことで、 @<code>{<span id="win">0</span>} と書いていた「@<code>{0}」を取得することができます。この「@<code>{0}」は、@<B>{文字列としての「@<code>{"0"}」} です。
一般にプログラミングでは、文字列としての @<code>{"0"} と、数値としての @<code>{0} は区別されます。
//list[][文字列 "0" と 数値 0 は区別される]{
"0" + "1" // =>  "01" と文字列の追加が行われます。
 0  +  1  // =>   1  と、数値演算が行われます。
//}

ですので、 @<code>{parseInt関数} を用いて、文字列としての @<code>{"0"} を解析(parse)し、整数値としての @<code>{0} を得ます。整数値としての @<code>{0} を得ることができましたから、「@<code>{+ 1}」と足し算することで、勝ち数を一つ増やせます。

@<code>{win.innerText = 1} と書くことで、@<code>{<span id="win">0</span>}  と書かれていた HTML をを JavaScript から @<code>{<span id="win">1</span>}  のように更新できます。

以上をまとめると @<code>{updateScore関数} は 次のようになります。

//list[][]{
// 勝敗更新処理
function updateScore(result) {
  // 要素を取得
  const win  = document.getElementById("win");
  const lose = document.getElementById("lose");

  if (result === WIN) { // 勝ちの場合
    win.innerText = parseInt(win.textContent) + 1;
  } else if (result === LOSE) { // 負けの場合
    lose.innerText = parseInt(lose.textContent) + 1;
  }
}
//}

== じゃんけんプログラム完成

長い道のりを経て、遂に完成したじゃんけんプログラム。ソースコードは次の通りです。

//list[][janken.js][file=source/janken.js, 1]{
//}

#@# == ウェブサイトへの公開
#@# //sideimage[netlify][35mm][sep=5mm,side=R]{
#@# 遂に完成したじゃんけんプログラムを、インターネットに公開しましょう。@<href>{https://www.netlify.com, Netlify} は、静的サイトを公開できるウェブサービスです。
#@# 小規模利用なら無料です。
#@# @<code>{Sign up} から、利用者登録を行うとより便利に使うことができます。
#@# //}
#@#
#@# //vspace[latex][2mm]
#@#
#@# //sideimage[deployment][35mm][sep=5mm,side=R]{
#@#   今回は簡単に体験できるよう、 @<href>{https://app.netlify.com/drop, https://app.netlify.com/drop}より直接アップロードしましょう。
#@#   ドラッグ＆ドロップで簡単に、作ったウェブサイトを24時間公開できます。
#@# //}

//clearpage
===[column] 日本最初のホームページ @<fn>{first}
　
//sideimage[firstmap][80mm][sep=5mm]{
日本最初のホームページは、平成4年9月30日に茨城県つくば市にある文部科学省高エネルギー加速器研究機構 計算科学センターの森田洋平博士によって発信されました。左のサーバー世界地図は、ティム博士の論文からのものです。
//}
//vspace[latex][2mm]

//blankline
//sideimage[first_website][80mm][sep=5mm]{
当時、世界にあったサーバーの位置が記されており日本の部分には、KEKと記されています。
//blankline
ソースコードには、@<code>{<HTML>}や @<code>{<BODY>} といったタグはなく、タグが大文字で書かれているのも時代を感じます。
//}
#@# //vspace[latex][2mm]


//footnote[first][@<href>{http://www.ibarakiken.gr.jp/www/, 日本最初のホームページ} よりのご紹介です。]

//image[source_color][][width=100%]
