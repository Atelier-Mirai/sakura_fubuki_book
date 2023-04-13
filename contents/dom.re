== JavaScriptとHTMLとの関係

ウェブブラウザ と @<code>{DOM(Document Object Model)}

@<B>{JavaScriptからHTMLを操作することができます。}
#@# //blankline
//vspace[latex][2mm]
HTML文書をブラウザで読み込むと、@<code>{DOM(Document Object Model)} と呼ばれるプログラミング用のデータ表現が生成されます。JavaScript には、この @<code>{DOM(Document Object Model)} を操作できる機能が備わっていますので、ブラウザに読み込まれた HTML文書の内容(コンテンツ)やその構造を、JavaScript によって操作できます。
#@# @<code>{DOM} では HTMLドキュメントのタグの入れ子関係を木構造で表現するため、@<code>{DOM} が表現するHTMLタグの木構造を @<code>{DOM} ツリー と呼びます。

例えば、@<code>{DOM} には HTML文書そのものを表現する @<code>{document} グローバルオブジェクトがあります。 @<code>{document} グローバルオブジェクトには、指定したHTML要素を取得したり、新しくHTML要素を作成するためのメソッド(方法・方式・手法、関数)が実装されています。 この @<code>{document} グローバルオブジェクトを使うことで、HTMLに書かれたHTMLを JavaScript から操作できます。
@<fn>{41}
//footnote[41][コードは「JavaScript Primer 迷わないための入門書」より引用・改変]

#@# //list[][HTMLの操作]{
#@# // CSSセレクタを使ってDOMツリー中のh1要素を取得する
#@# const heading = document.querySelector("h1");
#@#
#@# // h1要素に含まれるテキストコンテンツを取得する
#@# const headingText = heading.textContent;
#@#
#@# // 取得したテキストコンテンツを変更する
#@# heading.textContent = "こんにちは"
#@#
#@# // button要素を作成する
#@# const button = document.createElement("button");
#@# button.textContent = "ボタンを押してください";
#@#
#@# // body要素の子要素としてbuttonを挿入する
#@# document.body.appendChild(button);
#@# //}

#@# //blankline
//vspace[latex][2mm]
より理解しやすくするために、例を挙げましょう。
練習(practise)用に、@<file>{practise.html} という HTMLファイルと @<file>{practise.js}
という JavaScriptファイルを作ります。

//list[][practise.html][file=source/practise.html,1]{
//}

//sideimage[practisehtml][50mm][sep=5mm,side=R]{
  * 画面に「おはよう」と表示する
  * @<file>{practise.js} を読み込む

 という、簡潔な HTML で、ブラウザで表示すると、右のようになります。
 JavaScript から HTML を操作できるのですが、今読み込んだ @<file>{practise.js} には、まだ何も書かれていないため、特に変化がない普通の表示になっています。
//}
//vspace[latex][2mm]
それでは、次のように、@<file>{practise.js}を書いてみましょう。

//list[][practise.js][file=source/practise.js,1]{
//}

//sideimage[practisejs][50mm][sep=5mm,side=R]{
「おはよう」とメッセージが表示された後、

  * 画面が「おはよう」から「こんにちは」に更新された
  * 「ボタン」も追加された

と変化していることが分かります。
//}

このように、JavaScript と @<code>{DOM} は ウェブアプリ開発において切り離せない関係で、動的 @<fn>{dynamic} なウェブアプリを作る為には、JavaScriptによる @<code>{DOM} の操作が不可欠です。

//footnote[dynamic][今から作っていくじゃんけんゲームのように、利用者の操作に応じ様々な変化があることを「動的」と表現します。対義語は「静的」で、通常のウェブサイトのように変化しないものを指して言います。]

//blankline
少し難しい説明となりましたが、後ほどまた解説する機会もあります。ここでは「@<B>{JavaScriptからHTMLを操作できる}」ということを把握して、先へ進みましょう。

== イベントリスナと関数

=== イベントリスナ
先程のプログラムでは、利用者(ユーザ)が何もすることなく、勝利メッセージが表示されました。これではゲームらしくありません。「何か操作を行った時」に、「メッセージを表示する」ようにしましょう。

JavaScriptには、@<B>{イベントリスナ} と呼ばれる仕組みが有り、「何か操作を行った時」に指定した動作をする機能が備わっています。

それでは、@<B>{イベント}、@<B>{リスナー} とはなんでしょうか。それぞれの用語の意味を調べてみましょう。
//quote{
//noindent
プログラミングにおけるイベント (英: event) は、プログラム内で発生した動作・出来事、またそれらを表現する信号である。 メッセージあるいはアクション（動作）とも呼ばれる。
イベントの例としてウェブブラウザにおける「ページが読み込まれた時」、「クリック動作」、「スクロール操作」などさまざまなイベントがある。 @<fn>{fn-51}
//}
//footnote[fn-51][出典：Wikipedia]

//quote{
//noindent
リスナーとは、聞く人、聞き手、聴取者、聴講生、などの意味を持つ英単語。一般の外来語としてはラジオ（局/番組）の聴取者を意味する用法が有名である。

プログラミングの分野では、何らかのきっかけに応じて起動されるよう設定されたサブルーチンや関数、メソッドなどをイベントリスナー（event listener）あるいは単にリスナーという。例えば、「マウスがクリックされると起動するよう指定された関数」のことを「マウスクリックを待ち受けるリスナー」といったように呼ぶ。 @<fn>{fn-52}
//}
//footnote[fn-52][出典：IT用語辞典]

つまり、@<B>{イベントリスナー}とは次のようになります。

//quote{
//noindent
「ページ読み込みやクリック動作など、ウェブページで行われる様々な動作を常時起動し待ち受けて(聴取し続けて)、イベントが起きた時に指定された処理を行う関数のこと」@<fn>{fn-53}
//}
//footnote[fn-53][参考：フロントエンドエンジニアを目指す! JavaScript講座(9)イベントリスナーを使用する]

この、@<B>{イベントリスナー} の仕組みを利用して、「利用者」が「グー」を出したときに、勝ち負けを判定するなど、じゃんけんゲームを作り上げていきます。
