= CSSでの装飾

//abstract{
  この章では、先に学んだ@<code>{CSS}を使って、じゃんけんゲームの意匠を整えていきます。
  iPhone で どのように見えるか、ブラウザでの確認方法を学び、「モバイルファースト」で装飾を行っていきます。
//}

== モバイルファーストでの開発

//sideimage[shortcut_menu][60mm][sep=5mm,side=R]{
iPhone で閲覧する人が、大半を占めるようになりました。せっかくの機会なので、今作成しているじゃんけんゲームを iPhone で閲覧したら、どのように見えるのか確認してみましょう。

画面上で、右クリック @<fn>{migi-click} して表示される「ショートカットメニュー」から「調査」をクリックしましょう。
//}

//footnote[migi-click][システム設定 - トラックパッド - ポイントとクリック - 副ボタンのクリック から 「右下隅をクリック」 に設定すると、右クリックできるようになります。]
//vspace[latex][2mm]

画面下部にいろいろ表示されたことと思います。「開発者ツール」と呼ばれるもので、その名の通り、ウェブサイト / ウェブアプリを作り上げていく上でいろいろ役に立つ便利なツールです。

//image[janken_iphone_non_css][][width=80%]{
//}

絵の右下に、iPhone と iPad が重なったようなアイコンがあります。「レスポンシブデザインモード」と呼ばれるアイコンで、クリックすると、iPhone や iPad でどのように見えるか、切り替えることができます。 @<fn>{rdm}

//footnote[rdm][キーボードショートカットも用意されており、command + option + M でも、切り替えることができます。]

画面上部には、様々な端末に切り替えられるよう、良く用いられている端末名が用意されています。クリックしてみましょう。

//sideimage[device][60mm][sep=5mm,side=R]{
iPadやiPhoneなど様々な端末を選ぶことができます。iPhone SE 2nd gen iOS 14.6 @<fn>{iphone-se-2} を選びましたので、端末の画面サイズ、横 375px 縦 667 px が表示されています。

その右側にある iPhone のマークをクリックすると、横向きにした際の表示も確認できます。

また「リストを編集」をクリックすると良く使う端末だけを表示させたり、新しい端末が発売されたときに、画面サイズを登録することができます。
//}

//footnote[iphone-se-2][iPhone SE 第二世代のことです。現在は第三世代が提供されていますが、画面サイズは同じとなっています。]

//vspace[latex][7mm]

iPhone でも、ブラウザのタブには「じゃんけんゲーム」と表示されています。また、画面上にも「じゃんけんゲーム」の見出しや、グーの絵などが表示されており、とてもうまくいっています。

昨今、iPhone で見る人がとても増えていますので、このままiPhoneモードで開発を進めていきましょう。
#@# @<fn>{mobile-first}
#@# //footnote[mobile-first][「モバイルファースト」と言います。]

//note[ピクセル数について]{
iPhone SE の画面サイズは、横 375px 縦 667 px です。px とは何でしょうか？
「IT用語辞典」に分かりやすい説明がございますので、引用して紹介いたします。

//quote{
ピクセルとは、デジタル画像や画面などを構成する最小単位である、色のついた微細な点のこと。また、その数を表す単位。単位を表す場合は “px” と略記されることもある。
//}

つまり、横に375個、縦に667個、小さな画素を配置することで、iPhone の画面が構成されています。(実際には、@<ruby>{Retina,レティナ}ディスプレイとして、より木目細かく見えるように二倍〜三倍の画素が搭載されています。)
//}


== CSSファイルの作成

それでは、新しく @<file>{janken.css} というファイルを作って装飾を進めていきましょう。

=== 基本設定

それでは、まず、次のように記述しましょう。

//list[][janken.css][1]{
/*=====================================================================
  じゃんけんゲームの為のスタイルシート
=====================================================================*/

/* 基本設定
---------------------------------------------------------------------*/
* {                          /* 全ての要素(*)を対象に */
  margin: 0;                 /* 余白を0にする */
  box-sizing: border-box;    /* 要素の幅を制御しやすくする */
}

img {                         /* 全ての画像要素(img)を対象に */
  display: block;             /* ブロック要素にする */
  width: 100%;                /* 幅を100% にする */
  max-width: 100%;            /* 最大幅を100% にする */
  height: auto;               /* 高さは 幅に応じて 自動調整する */
}
//}

==== コメント（説明書き）
@<code>{/*} と @<code>{*/} で囲まれた部分は「コメント」です。
コメントは、ブラウザが CSS を解釈する際には読み飛ばされ、表示には影響を与えませんので、
「見出し」や「説明書き」として、使うことができます。

CSS は、HTML のそれぞれの要素について、事細かに装飾していくため、長くなります。
表題を入れて、視覚的にも、大まかに何について書かれている部分なのか判別しやすくとともに、
それぞれのコードの意味が分かりやすいよう、一行一行、説明を付けています。

==== ユーザーエージェントスタイルシート と リセットCSS
ブラウザには、「ユーザーエージェントスタイルシート」というスタイルシートが標準で適用されており、自分で、何もCSSを記述しなくても、見やすいようにブラウザが余白の調整などある程度の飾り付けを行っています。せっかく、ブラウザがスタイルシートを適用してくれているのですが、自分でデザインを創り上げる際には少しおせっかいに感じることもあります。

その為、不要・不都合なスタイルを上書きし、初期化するためのCSSを、「リセットCSS」と言います。先の基本設定はその一例です。

自身で作成するのも一法ですが、多くの先人たちの手により、リセットCSSが作成されていますので、それを使うのも良いでしょう。 @<fn>{resetcss}

//footnote[resetcss][@<href>{https://github.com/hankchizljaw/modern-css-reset/tree/master/dist,A Modern CSS Reset}など、多くがリセットCSSがございます。]

#@# //note[補足説明]
#@# TODO
#@# @<code>{box-sizing: border-box;}
#@# //}
#@# ==== ブロック要素とインライン要素
#@# display: block;
#@# 基本設定について 補足説明
#@# @<

=== ヘッダー

//sideimage[j-header][60mm][sep=5mm,side=R]{
  ヘッダーの装飾を行っていきましょう。
  色の指定は良く使うので、先に紹介したCSSカスタムプロパティで、和の色の指定を行えるようにします。
  そして、書体を大きくして、色を付けて、影も付け、中央揃えにします。
  HTMLの各要素と それをどうCSSで装飾するのかにも着目です。
//}

//list[][index.html][19]{
  <header>
    <!-- h1 タグは、大見出しを表すタグです。他に 中見出しを表す h2 タグや
         小見出しを表す h3 タグなど h6 タグまであります。 -->
    <h1>じゃんけんゲーム</h1>
  </header>
//}

//list[][janken.css][19]{
/* 色の指定 (CSSカスタムプロパティ)
---------------------------------------------------------------------*/
:root {
  --kyohiiro:          #ff251e; /* 京緋色(きょうひいろ) */
  --shinonomeiro:      #f19072; /* 東雲色(しののめいろ) */
  --nanohanairo:       #ffec47; /* 菜の花色(なのはないろ) */
  --sanaeiro:          #67a70c; /* 早苗色(さなえいろ) */
  --amairo:            #2ca9e1; /* 天色(あまいろ) */
  --utsushiiro:        #3d6eda; /* 移色(うつしいろ) */
  --botaniro:          #e7609e; /* 牡丹色(ぼたんいろ) */
  --ayameiro:          #674196; /* 菖蒲色(あやめいろ) */
  --sakurairo:         #fef4f4; /* 桜色(さくらいろ) */
  --momijiiro:         #a61017; /* 紅葉色(もみじいろ) */
  --nibiiro:           #9ea1a3; /* 鈍色(にびいろ) */
  --kurohairo:         #0d0d0d; /* 黒羽色(くろはいろ) */

  --harukazeiro:       transparent; /* 春風色(はるかぜいろ) */
}

/* ヘッダー
---------------------------------------------------------------------*/
header h1 {                   /* header 内の h1 (大見出しの指定) */
  font-size: 40px;            /* 書体の大きさは40px */
  color: var(--kurohairo);    /* 文字の色は、黒羽色 #0d0d0d; */
  text-shadow: 3px 4px 5px var(--nibiiro); /* 右に3px 下に4pxずれた所に
                                              ぼかし幅5pxで
                                              鈍色 #9ea1a3 の影を付ける */
  text-align: center;         /* 文字は中央揃えにする */
}
//}

=== メイン(主要機能部)

@<code>{main} は、主要機能部であることを示すタグです。文字通り、じゃんけんゲームの「メイン」となるところです。少し長めのコードになっていますが、HTML と CSS との対応関係を確認しつつ、読み解いていって下さい。

//list[][index.html][25]{
<!-- mainタグは ページの主題(main)となるコンテンツ(内容・出し物)を記述します。-->
<main>
  <!-- figure タグは 図版(figure)を示すタグです -->
  <figure>
    <!-- img タグは、絵(image)を表示するためのタグです -->
    <img id="computer_hand_type" src="guu.webp">
  </figure>

  <!-- p は 段落(paragraph)を表す際に用いるタグです -->
  <p>
    <!-- br タグを入れると、途中で改行できます -->
    みんな知っているじゃんけん<br>
    グー・チョキ・パー どれかを押してね
  </p>

  <!-- div は汎用タグで、適切なタグがない時に用います。
       クラス名をcontrol_areaとし、配置を整え易くします -->
  <div class="control_area">
    <!-- プレイヤーの手を選ぶ為のボタンです。 -->
    <div class="player_hand_type">
      <!-- JavaScriptでの操作用に id属性をguu 値を0 にします。 -->
      <button id="guu"   value="0"></button>
      <button id="choki" value="1"></button>
      <button id="paa"   value="2"></button>
    </div>
    <!-- 得点と開始ボタンの領域です -->
    <div class="score_and_replay">
      <p class="score">
        <!-- JavaScriptからの操作用に id属性をwinにします。 -->
        <span id="win">0</span> 勝
        <span id="lose">0</span> 敗
      </p>
      <!-- button タグを使って、画面に「開始」ボタンを表示します。
           このボタンにも、id="play" と ID を付与しておきます。 -->
      <button id="play" class="button">開始</button>
    </div>
  </div>
</main>
//}

//list[][janken.css][49]{
/* メイン(サイト主要機能部)
---------------------------------------------------------------------*/
main figure img {           /* メインの画像(=コンピュータの手)を対象 */
  margin: 0 auto;           /* 上下に 0px 左右に 均等に 余白を入れる */
                            /* (= 左右中央揃えにする) */
  max-width: 280px;         /* 最大幅を280pxにする */
}

main p {                    /* じゃんけんの説明文 */
  text-align: center;       /* 文字は中央揃えにする */
  margin-bottom: 20px;      /* 下側に少し余白を設ける */
}

main .score,                /* クラス属性 .score */
main #play {                /* ID属性 #playを付与した要素を対象に */
  font-size: 24px;          /* 書体の大きさは24px */
  margin: 10px 0;           /* 上下に10px 左右に0px の余白 */
}

main .player_hand_type button { /* じゃんけん各ボタンの大きさを指定 */
  background: transparent;      /* 背景色を透明に */
  background-size: 100% 100%;   /* 背景画像の大きさは縦横100% */
  border: none;                 /* ボタンの枠線は無し */
  width: 100px;                 /* ボタンの幅は100px */
  height: 100px;                /* ボタンの高さは100px */
  padding: 0;                   /* 内部への詰め物は無し */
  cursor: pointer;              /* カーソルの形状を手のマークに */
}
//}

//sideimage[j-main][60mm][sep=5mm,side=R]{
文字の大きさや配置などの調整を行っている他、注目して欲しいのは、画像に関する装飾です。

//blankline
コンピュータの出す手の画像が中央に大きく表示されています。

//blankline
また、グーチョキパー、それぞれのボタンに @<code>{background-image: url('player_guu.webp');} などと、背景画像を設定しています。
@<small>{（@<code>{main #guu} など、ID要素はページ内で唯一の存在であるため、@<code>{#guu} と書くだけで良いのですが、@<code>{main} 内の要素であることを分かりやすくとの観点から、少し冗長ですが記しています。)}
少し左に寄っていますが、これは後ほど修正することにしましょう。

//blankline
「開始」ボタンも、青地に白文字の角丸に設定して、雰囲気よくなっています。
//}

=== じゃんけん紹介記事

//list[][index.html][64]{
<!-- article は 記事(article) を表す際に用いるタグです -->
<article>
  <div>
    <p>
      じゃんけんは、3種類の指の出し方（グー・パー・チョキ）で三すくみの関係を
      構成し、出した種類により勝敗を決める遊戯です。古来伝承されてきた虫拳などを
      もとに、明治期に九州で発明されたと言われています。
    </p>

    <p>
      <!-- a はanchor(錨)の意味で、他の文書へのリンクを示すタグです。 -->
      詳しくは
      <a href="https://ja.wikipedia.org/wiki/じゃんけん">ウィキペディア</a>
      を見てね。
    </p>
  </div>

  <figure>
    <!-- figcaption で 図版(figure)に 標題(caption)を設定します -->
    <figcaption>じゃんけん相関図</figcaption>
    <img src="janken.webp" alt="じゃんけん説明図">

    <!-- ul は 箇条書き項目(Unorderd List)に用いるタグです-->
    <ul>
      <!-- li は リスト項目(List Item)を示す際に用いるタグです -->
      <li>紙 ＞ 石 ：紙は石を包む</li>
      <li>鋏 ＞ 紙 ：鋏は紙を切る</li>
      <li>石 ＞ 鋏 ：石は鋏に克つ</li>
    </ul>
  </figure>
</article>
//}

//list[][janken.css][93]{
/* じゃんけん紹介記事
---------------------------------------------------------------------*/
article {                     /* aritcle 要素を対象に */
  border: 5px double var(--utsushiiro); /* 枠線は5pxの二重線 色は移色 */
  border-radius:  1rem;       /* 角を1文字分丸くする */
  margin-bottom:  1rem;       /* 要素下側に1文字分余白を設ける */
  padding-bottom: 1rem;       /* 要素下側に1文字分詰め物をする */
}

article p {                   /* aritcle 内の p要素を対象に */
  font-size: 16px;            /* 書体の大きさは16px */
  text-align: left;           /* 文字は左寄せ */
  padding: 1rem;              /* 1文字分詰め物をする */
  text-indent: 1rem;          /* 文字を1文字字下げする */
}

article figure figcaption {   /* igcaption要素を対象に */
  font-size: 24px;            /* 書体の大きさは24px */
  font-weight: bold;          /* 文字は太字 */
  text-align: center;         /* 文字は中央揃え */
  margin-bottom: 1rem;        /* 下側に1文字分間隔を取る */
}

article figure img {          /* img要素を対象に */
  margin: 0 auto;             /* 上下に 0px 左右に 均等に 余白を入れる */
                              /* (= 左右中央揃えにする) */
  max-width: 280px;           /* 最大幅を280pxにする */
}

article ul {                  /* ul要素を対象に */
  list-style: none;           /* 箇条書きの・(黒丸)は不要 */
  padding: 0;                 /* 詰め物も不要 */
}

article ul li {               /* li要素を対象に */
  text-align: center;         /* 文字は中央揃え */
}
//}

//sideimage[j-article][60mm][sep=5mm,side=R]{
みんな、じゃんけんは知っていますが、せっかくなので囲み記事を作成して紹介しています。
記事には @<code>{article} 要素がぴったりですので、HTML でマークアップして、CSS で装飾しています。

//blankline
@<code>{border}プロパティで囲み枠を作って、文字や画像の大きさの調整を行っていき、結果は右のようになります。
どうぞ順に対応関係を追っていって下さい。
//}

=== フッター

//sideimage[j-footer][60mm][sep=5mm,side=R]{
いよいよ、最後はフッターです。
フッターは、サイトの付帯情報や著作権表示などに用いられます。
背景色を付けて、文字を中央揃えにして完了です。
//}

//list[][index.html][96]{
<!-- footer タグは、サイトの付帯情報や著作権表示などに用います。 -->
<footer>
  <div class="container">
    <p>情報技術を夢の架け橋に</p>
    <!--「©」は「こぴーらいと」と入力して変換します -->
    <p>© アトリヱ未來</p>
  </div>
</footer>
//}

//list[][janken.css][131]{
/* フッター
---------------------------------------------------------------------*/
footer {                        /* footer 要素を対象に */
  background: var(--sakurairo); /* 背景色は桜色 */
}

footer div {                  /* footer 内の div 要素を対象に */
  text-align: center;         /* 文字は中央揃え */
}
//}


//clearpage


== CSS グリッドレイアウト
さて、大まかにデザインが完成しました。若干配置が整っていないところがありますので、「CSS グリッドレイアウト」を用いて、調整していきましょう。

通常、ウェブページは、上から下、左から右に、配置されます。従来、ページ上の要素を自由自在に配置するには大変な苦労が伴いました。CSSグリッドレイアウトを用いると、縦と横の補助線（グリッド・格子）を用いて、自由自在に要素を配置することができます。

いつもご紹介しております、ＭＤＮ より、@<href>{https://developer.mozilla.org/ja/docs/Learn/CSS/CSS_layout/Grids,グリッド} について書かれた記事がございますので、引用しつつ進めていきましょう。

@<fn>{grid}

//footnote[grid][@<href>{https://developer.mozilla.org/ja/docs/Web/CSS/CSS_Grid_Layout/Basic_Concepts_of_Grid_Layout,グリッドレイアウトの基本概念}にも分かりやすく説明されており、お勧めです。]

=== グリッドとは
CSS グリッドレイアウト（Grid Layout）は、ウェブ用の二次元レイアウトシステムです。これにより、コンテンツ(内容物・出し物)を行と列にレイアウト（配置）することができ、複雑なレイアウトを簡単に構築できるようにする多くの機能があります。
グリッドは、列と行を定義する水平線と垂直線の集合が交差したものです。要素をグリッドの行と列に並べて配置することができます。

グリッドには通常、列（column）、行（row）、そしてそれぞれの行と列の間の間隔（gap）があります。

//image[cssgridlayout][][width=90%]

=== グリッドを定義する
練習として、以下のように @<file>{grid.html} と @<file>{grid.css} を用意しましょう。

//list[][grid.html][1]{
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>CSSグリッドレイアウト練習</title>
    <link rel="stylesheet" href="grid.css">
  </head>

  <body>
    <h1>CSSグリッドレイアウト練習</h1>

    <div class="container">
      <div>One</div>
      <div>Two</div>
      <div>Three</div>
      <div>Four</div>
      <div>Five</div>
      <div>Six</div>
      <div>Seven</div>
    </div>

  </body>
</html>
//}

//list[][grid.css][1]{
.container > div {
  border-radius: 5px;
  padding: 10px;
  background: #cfe8dc;
  border: 2px solid #4fb9e3;
}
//}

//sideimage[grid0][60mm][sep=5mm,side=R]{
@<code>{.container > div} は、@<code>{container}クラスの @<br>{}@<B>{直下}の@<code>{div}タグを選択するためのセレクタです。

@<code>{<div>One</div>}、@<code>{<div>Two</div>}などが薄い緑地に水色の枠で囲まれるようになります。
//}

グリッドを定義するためには、@<code>{display} プロパティに @<code>{grid} の値を使います。
これによりグリッドレイアウトが有効になり、コンテナの直接の子の全てがグリッド項目(アイテム)になります。
ここでは、コンテナが @<code>{<div class="container">} で、グリッド項目が@<code>{<div>One</div>}、@<code>{<div>Two</div>}などです。

「みかん箱」に「みかん」を入れる、そのような想像をすると分かりやすいかもしれません。
グリッドコンテナ＝「みかん箱」、グリッド項目＝「みかん」です。 @<fn>{irasutoya}

//image[container_mikan][][width=80%]

//footnote[irasutoya][出典: 季節のイベント・動物・子供などのかわいいイラストが沢山見つかるフリー素材サイト @<href>{https://www.irasutoya.com/,いらすとや}]

それでは、CSS に次を追加してみましょう。
//list[][grid.css][8]{
.container {
  display: grid;
}
//}

ブラウザを再読み込みして確認してみても、特に変化が見られません。
@<code>{display: grid} を宣言すると 1 列のグリッドになるので、項目は上下に表示され続けます。

よりグリッドらしく見せるには、グリッドにいくつかの列を追加する必要があります。
ここでは @<code>{grid-template-columns} プロパティにより、200 ピクセルの列を 3 つ追加しましょう
（@<code>{grid-template-rows} プロパティを使うと、行数を指定できます）。

以下のように CSS を更新しましょう。

//list[][grid.css][8]{
.container {
  display: grid;
  grid-template-columns: 100px 100px 100px;
}
//}

//sideimage[grid1][60mm][sep=5mm,side=R]{
CSS 規則に 2 番目の宣言を追加してからページを再読み込みすると、作成したグリッドの各セルに項目が 1 つずつ再配置されていることがわかります。
//}

=== @<code>{fr} 単位での柔軟なグリッド
@<code>{fr} は、@<code>{fraction(分数)} に由来した単位で、CSS グリッドレイアウトのために誕生した新しい単位です。

@<code>{px}などの長さとパーセントを使用してグリッドを作成するだけでなく、この @<code>{fr} 単位を使用して柔軟にグリッドの行と列のサイズを変更できます。 この単位は、グリッドコンテナ内の使用可能スペースの割合を表します。

列のリストを次の定義に変更し、@<code>{1fr} の列を 3 つ作成します。

//list[][grid.css][8]{
.container {
  display: grid;
  grid-template-columns: 1fr 1fr 1fr;
}
//}

//sideimage[grid2][60mm][sep=5mm,side=R]{
グリッドコンテナ内を三等分して、それぞれの @<code>{div} 要素が配置されていることが確認できます。
//}

//vspace[latex][7mm]
//sideimage[grid3][60mm][sep=5mm,side=R]{
より柔軟に列幅を変更することもできます。 @<code>{fr} 単位はスペースを比例して配分するので、各列には異なる正の値を指定できます。

例えば @<code>{grid-template-columns: 2fr 1fr 1fr;} と定義することで、右のようにできます。
//}

=== 行間や列間の間隔
間隔を作成するには、列間の間隔には @<code>{column-gap} プロパティ、行間の間隔には @<code>{row-gap} プロパティ、両方を同時に設定するには @<code>{gap} プロパティを使用します。

//list[][grid.css][8]{
.container {
  display: grid;
  grid-template-columns: 2fr 1fr 1fr;
  gap: 20px;
}
//}

//sideimage[grid4][60mm][sep=5mm,side=R]{
右のように、行間、列間、それぞれ @<code>{20px} の間隔を空けることができました。
//}

=== 行指定や列指定の繰り返し
反復記法を使用して、行指定や列指定を繰り返すことができます。

//list[][grid.css][8]{
.container {
  display: grid;
  grid-template-columns: repeat(4, 1fr);
  gap: 20px;
}
//}

//sideimage[grid5][60mm][sep=5mm,side=R]{
グリッドコンテナ内を四等分して、それぞれの @<code>{div} 要素が配置されていることが確認できます。

@<code>{grid-template-columns: 1fr 1fr 1fr 1fr;} と書いたことと同じですが、繰り返す回数が多いときに便利です。
//}

=== グリッドの線の番号を使った要素の配置
グリッドの作成から、グリッド上に要素を配置することに移ります。
グリッドは @<code>{1} から始まる線番号を持っていてます。列の 1 線目がグリッドの左側にあり、行の 1 線目が一番上にあります。

開始線と終了線を指定することで、これらの線に従って要素を配置できます。

CSS からそれぞれの要素を扱いやすくするために、少しだけ @<file>{grid.html} を次のように更新し、@<code>{<div class="one">One</div>}と、クラス名「@<code>{one}を付けましょう。

//list[][grid.html][12]{
<div class="container">
  <div class="one"  >One</div>
  <div class="two"  >Two</div>
  <div class="three">Three</div>
  <div class="four" >Four</div>
  <div class="five" >Five</div>
  <div class="six"  >Six</div>
  <div class="seven">Seven</div>
</div>
//}

CSS は次のように更新します。

//list[][grid.css][8]{
.container {
  display: grid;
  grid-template-columns: 1fr 1fr 1fr 1fr;
  grid-template-rows:    1fr 1fr 1fr 1fr;
  gap: 20px;
}
//}

//sideimage[shortcut_menu2][60mm][sep=5mm,side=R]{

表示結果は先ほどと変わりませんが、四行四列のグリッド（格子）を作成することができました。
//blankline
「開発者ツール」を使うと、どのようにグリッドが構成されたか、確認することができます。
画面上で、右クリック @<fn>{migi-click2} して表示される「ショートカットメニュー」から「調査」をクリックしましょう。
//}

//footnote[migi-click2][システム設定 - トラックパッド - ポイントとクリック - 副ボタンのクリック から 「右下隅をクリック」 に設定すると、右クリックできるようになります。]
//vspace[latex][7mm]

//image[grid-kakunin][][width=100%]

開発者ツールが表示されましたので、グリッドの線番号を表示させましょう。

「インスペクタ」をクリックします。
  - 1. 下に HTML コードが表示されています。@<code>{<div class="container">} の右側に、「grid」と書かれた小さなボタンがありますので、これをクリックします。
  または、右側の「レイアウト」欄内の「グリッド」の項目にある「グリッドをオーパーレイ表示」にチェックを入れます。
  - 2. 次に、右側の「レイアウト」欄内の「グリッド」の項目にある「グリッドの表示設定」で「線番号を表示」にチェックを入れます。

グリッドの線番号が表示されました。
上部を見ると、左から、1, 2, 3, 4, 5 と番号が振られています（四列作りましたので、線は １〜５までの五本できます）。

それでは、次のように CSS を追加して、「One」から「Seven」までの要素を配置してみましょう。

//list[][grid.css][15]{
.one   { grid-column: 1 / 5;  grid-row: 1;     }
.two   { grid-column: 1;      grid-row: 2 / 4; }
.three { grid-column: 2 / 4;  grid-row: 2;     }
.four  { grid-column: 4;      grid-row: 2;     }
.five  { grid-column: 2 / 4;  grid-row: 3;     }
.six   { grid-column: 4;      grid-row: 3;     }
.seven { grid-column: 1 / 5;  grid-row: 4;     }
//}

結果は次のようになります。
//image[grid6][][width=70%]

@<code>{.one { grid-column: 1 / 5; grid-row: 1;\}} は、列は一本目の線から五本目の線まで、行は一行目に配置されています。

@<code>{.two { grid-column: 1    ; grid-row: 2 / 4;\}} は、列は一本目の線に、行は二本目から四本目に配置されています。

このように、グリッドの線を使って、好きなように要素を配置することができます。

//blankline
また下部を見ると見ると、右から、-1, -2, -3, -4, -5 と番号が振られています。
つまり、一番右端の線を指定する際には、「左から数えて５本目」と指定することもできますし、「右から数えて１本目」と指定することもできるということです。

つまり、
//list[][grid.css][15]{
.one   { grid-column: 1 / 5;  grid-row: 1; }
//}

と記述する代わりに、

//list[][grid.css][15]{
.one   { grid-column: 1 / -1;  grid-row: 1; }
//}

と記述しても同様の結果が得られます。中央に多くの列数がある場合、列数が可変する場合などには、右端から線番号を数えると楽です。活用していきましょう。

=== 要素の左揃え、中央揃え、右揃え
@<code>{justify-self}プロパティを使うと、「@<B>{水平}」方向での要素の配置を制御できます。

CSSを追加して実験してみましょう。
//vspace[latex][2mm]
//sideimage[grid7][60mm][sep=5mm,side=R,border=on]{
@<B>{左揃え} @<code>{.one { justify-self: start; \}}
//}
//sideimage[grid8][60mm][sep=5mm,side=R,border=on]{
@<B>{中央揃え} @<code>{.one { justify-self: center; \}}
//}
//sideimage[grid9][60mm][sep=5mm,side=R,border=on]{
@<B>{右揃え} @<code>{.one { justify-self: end; \}}
//}

=== 要素の上揃え、中央揃え、下揃え
@<code>{align-self}プロパティを使うと、「@<B>{垂直}」方向での要素の配置を制御できます。

CSSを追加して実験してみましょう。
//vspace[latex][2mm]
//sideimage[grid10][10mm][sep=5mm,side=R,border=on]{
@<B>{上揃え} @<code>{.two { align-self: start; \}}
//}
//sideimage[grid11][10mm][sep=5mm,side=R,border=on]{
@<B>{中央揃え} @<code>{.two { align-self: center; \}}
//}
//sideimage[grid12][10mm][sep=5mm,side=R,border=on]{
@<B>{下揃え} @<code>{.two { align-self: end; \}}
//}

=== 線番号に名前を付ける
線番号に名前を付け、より使いやすくすることができます。

//list[][grid.css][]{
.container {
  grid-template-rows: 1fr 1fr 1fr 1fr;
}
//}

と記述して、四行作成しましたが、以下のように書くことで、行のそれぞれの線に名前を付けることができます。

//list[][grid.css][]{
.container {
  grid-template-rows:
    [head]    1fr  /* 一本目の線に head    と命名 */
    [main]    1fr  /* 二本目の線に main    と命名 */
    [article] 1fr  /* 三本目の線に article と命名 */
    [foot]    1fr; /* 四本目の線に foot    と命名 */
}
//}

そして、この線番号に付けた名前を使って、
//list[][grid.css][]{
.one   { grid-column: 1 / 5;  grid-row: head;          }
.two   { grid-column: 1;      grid-row: main / span 2; } /* 二行使い、配置する */
.three { grid-column: 2 / 4;  grid-row: main;          }
.four  { grid-column: 4;      grid-row: main;          }
.five  { grid-column: 2 / 4;  grid-row: article;       }
.six   { grid-column: 4;      grid-row: article;       }
.seven { grid-column: 1 / 5;  grid-row: foot  ;        }
//}

と書くことができます。

結果は同じですが、それぞれの要素をどの行に配置するのか、より分かりやすくなりますので、
ウェブサイト全体など、良く使う線には名前を付けておくと便利です。

== レスポンシブデザイン
その昔、パソコンからウェブサイトを閲覧する時代は、一つのHTMLとCSSを書きました。
携帯電話が登場したことで、携帯用のウェブサイトが作られることになりましたが、当時の携帯電話の性能は低かったため、標準規格のHTMLではなく、少し簡略化された形でウェブサイトを作成していました。

そして、iPhone や iPad の登場により、同一内容の複数のウェブサイトを管理するのではなく、
同じ一つのHTMLとCSSで、様々な端末に対応させる方法が考案されました。
レスポンシブデザインと呼ばれる手法です。

#@# @<code>{@media} は、メディアクエリと呼ばれます。

=== メディアクエリ

簡単な例として、iPhone では 二列で、iPad や Mac では、四列で表示させることとしましょう。
iPad の横幅は、768px ですので、これを境にレイアウトを切り替えることにしましょう。

（この境目となるポイントを、「ブレークポイント」と呼びます。ここでは、画面幅の大小で二つに分けますが、より細かく、480px / 768px / 1024px / 1280px など様々にブレークポイントを設定することもできます。）

//list[][grid.css][]{
.container {
  display: grid;
  grid-template-columns: 1fr 1fr;
}

@media (min-width: 768px){
  .container {
    grid-template-columns: 1fr 1fr 1fr 1fr;
  }
}
//}

それでは、レイアウトが変更されることを確認してみましょう。確認方法は次の二通りがあります。

 - 1. ブラウザの幅を徐々に変えていく。
 - 2. レスポンシブデザインモードに変更する。

2 の レスポンシブデザインモードにすると、ピクセル単位で任意の幅を設定でき、便利です。

レスポンシブデザインモードに変更する方法は次の通りです。

 - 1). ブラウザ上で右クリックします。
 - 2). ショートカットメニューが表示されるので「調査」をクリックします。
 - 3). 開発者ツールが表示されるので、右下の iPhone と iPad が重なったマークをクリックします。
 - 4). 任意の画面幅を持つ端末での表示結果が中央に表示されるので、右端にマウスカーソルを重ねます。
 - 5). マウスカーソルの形状が「@<icon>{col-resize-s}」に変化するので、その状態でクリックし、右へ移動します。
 - 6). 画面上部に 横 x 楯 のピクセル数が表示されます。
 - 7). 逆に、ピクセル数を入力し、画面幅を変更することもできます。

//image[grid-480][][width=100%]
//image[grid-800-half][][width=100%]

768px を境に、二列表示から四列表示に変わることを確認できます。

//blankline
巻末の参考文献 「CSSグリッドで作る HTML5 & CSS3 レッスンブック」には、より詳しくグリッドレイアウトを使ったウェブサイトの作成方法が掲載されております。とても有益な書籍ですので、是非一読なさってください。

//note[メディアクエリの範囲指定構文]{
メディアクエリ レベル4(Media Queries Level 4) では、範囲指定構文(Range Syntax)が、導入されています。

先の例ですと、768px 以上の画面幅の際に適用したい CSS を以下のように書きました。

//list[][]{
@media (min-width: 768px){ ... }
//}

範囲指定構文 を使うと、不等号を使って以下のように分かりやすく書くことができます。
//list[][]{
@media (width >= 768px){ ... }
//}

また、480px 〜 768px までの画面幅の際に適用したい CSS は従来は次のように書きます。
//list[][]{
@media (min-width: 480px) and (max-width: 768px) { ... }
//}

@<code>{min} や @<code>{max} が分かりにくく大変ですが、
範囲指定構文 を使うと、不等号を使って次のようにとても分かりやすく書くことができます。
//list[][]{
@media (480px <= width <= 768px) { ... }
//}

Firefox, Chrome, Edge と、Safari 以外の主要ブラウザが対応しており、Apple 社の対応が待たれます。

//}

//clearpage

== CSS グリッドレイアウト を使った配置

それでは、CSS グリッドレイアウト を使って、じゃんけんゲームの配置を行っていきましょう。

=== ページ全体の設定

//list[][janken.css][141]{
/*---------------------------------------------------------------------
  CSS グリッドレイアウト を使った配置の指定
---------------------------------------------------------------------*/

/* ページ全体の設定
---------------------------------------------------------------------*/
body {                        /* body は全ての要素の親 */
  display: grid;              /* グリッド(格子)を使うモードにする */
  grid-template-columns:      /* column(列) の設定を行う */
        20px 1fr 20px;        /* 左右に20px 残りは中央 */
  grid-template-rows:         /* row(行)の設定を行う */
        [head]     100px      /* 一行目の高さは100px headと命名 */
        [main]     auto       /* 二行目の高さは自動 titleと命名 */
        [article]  auto       /* 三行目の高さは自動 subtitleと命名 */
        [foot]     100px;     /* 四行目の高さは100px footと命名 */
}

/* 部品の配置
---------------------------------------------------------------------*/
body > * {                    /* body直下(>)の全要素(*)を対象に */
  grid-column: 2 / -2;        /* 列配置は 左から2番目の線から
                                 右から数えて二番目(-2)の線まで */
}
//}

//sideimage[g-body][60mm][sep=5mm,side=R]{
@<code>{body}要素は、全ての要素の親で、この下に全ての要素が置かれます。そこで、@<code>{body}要素全体を、コンテナ(箱)として、グリッドを作り上げていきましょう。

//blankline
iPhone での閲覧時は、中央に縦一列で表示することとしますが、左右に少し余白があったほうが見た目が良いので、左右にも小さな列を用意しておきます。

//blankline
行の作成は、ヘッダー、メイン、紹介記事、フッターと、四つの項目がありますので、それぞれの項目に応じた四行を作ることにし、後々使い勝手の良いよう、線に名前を付けておきます。

//blankline
開発者ツールで、グリッドを表示させてみると、右のようになっています。
//}

=== ヘッダー

//list[][janken.css][165]{
/* ヘッダー
---------------------------------------------------------------------*/
header {                      /* header 要素を対象に */
  grid-row: head;             /* 行の配置は先に命名したhead線の下に */
  justify-self: center;       /* 左右中央揃えで配置する */
  align-self: center;         /* 上下中央揃えで配置する */
}
//}

//sideimage[g-header][60mm][sep=5mm,side=R]{
  ヘッダーの配置を行っていきます。

  @<code>{header}要素を、先に命名した@<code>{head}線の下に配置し、上下左右中央揃えにします。
//}

=== メイン(サイト主要機能部)
//list[][janken.css][173]{
/* メイン(サイト主要機能部)
---------------------------------------------------------------------*/
main {                          /* main 要素を対象に */
  grid-row: main;               /* 行の配置は先に命名したmain線の下に */
}

main .control_area {            /* control_areaクラスを対象に */
  display: grid;                /* 内部要素をグリッドで配置 */
  grid-template-columns: 1fr;   /* column(列) は 一列 用意する */
  grid-template-rows: 1fr auto; /* row(行) は 二行 用意する */
  row-gap: 20px;                /* 行の間隔は 20px 開ける */
}

main .control_area .player_hand_type { /* player_hand_typeクラスを対象に */
  display: grid;                       /* 内部要素をグリッドで配置 */
  grid-template-columns: 1fr 1fr 1fr;  /* column(列) は 三列 用意する */
  grid-template-rows:    1fr;          /* row(行) は 一行 用意する */
}

main .control_area .player_hand_type button { /* button要素 を対象に */
  justify-self: center;                       /* 水平方向に中央揃え */
}

main .score_and_replay {          /* 得点領域の指定 */
  display: grid;                  /* 内部要素をグリッドで配置 */
  grid-template-columns: 1fr 1fr; /* column(列) は 二列 用意する */
  grid-template-rows:    1fr;     /* row(行) は 一行 用意する */
  align-self: center;             /* 垂直方向に中央揃え */
}

main .score_and_replay .score,    /* クラス属性 .score */
main .score_and_replay #play {    /* ID属性 #playを付与した要素を対象に */
  align-self: center;             /* 垂直方向で中央揃え */
}
//}

サイト主要部だけあって、少し長くなっていますが、見ていきましょう。

//sideimage[g-main][60mm][sep=5mm,side=R]{
@<code>{main} 要素を、先に命名した @<code>{main}線の下に配置するところは、先ほどと同様です。

ここでの要点は、@<B>{「グリッドの中にグリッドを作っている」}ことです。

@<code>{control_area}要素をグリッドコンテナ(箱)にすることで、抱合されている「プレーヤーの手」と「勝敗・開始ボタン」を配置しやすくします。
//}

//sideimage[g-main-hand][60mm][sep=5mm,side=R]{
「プレーヤーの手」について、グリッドを作成し、それぞれが均等に配置されるよう、調整しています。
//}

//sideimage[g-main-score][60mm][sep=5mm,side=R]{
「勝敗」と「開始ボタン」を横に並べて配置します。
//}

=== じゃんけん紹介記事
//list[][janken.css][208]{
/* じゃんけん紹介記事
---------------------------------------------------------------------*/
article {                         /* aritcle 要素を対象に */
  grid-row: article;              /* 行の配置は 先に命名した article線の下に */
}
//}

//sideimage[g-article][45mm][sep=5mm,side=R]{
@<code>{article} 要素を、先に命名した @<code>{article} 線の下に配置するよう、指定しています。
//}

=== フッター
//list[][janken.css][214]{
/* フッター
---------------------------------------------------------------------*/
footer {                          /* footer 要素を対象に */
  grid-column: 1 / -1;            /* 列配置は、左から一番目の線から、
                                     右から数えて一番目(-1)の線まで */
  grid-row: foot;                 /* 行の配置は 先に命名した foot線の下 */

  display: grid;                  /* 内部要素をグリッドで配置 */
  grid-template-columns: 1fr;     /* column(列) は 一列 用意する */
  grid-template-rows:    1fr;     /* row(行) は 一行 用意する */

}

footer div {                      /* footer内のdiv要素を対象に */
  grid-column: 1;                 /* 1番目のグリッド線の右側に配置 */
  grid-row: 1;                    /* 1番目のグリッド線の下側に配置 */
  justify-self: center;           /* 水平中央揃えで配置する */
  align-self: center;             /* 垂直中央揃えで配置する */
}
//}

//sideimage[g-footer][60mm][sep=5mm,side=R]{
@<code>{footer} 要素を、先に命名した @<code>{foot} 線の下に配置しています。

@<code>{grid-template-columns: 1fr;} @<code>{grid-template-rows: 1fr;} や @<code>{grid-column: 1;} @<code>{grid-row: 1;} と、一行一列のグリッドを作って配置しています。
//}
//vspace[latex][2mm]

実際のところ、これは少し冗長な記述です。
@<code>{display: grid;} とグリッドモードにする旨記述することで「暗黙」のグリッドが作られ、
@<code>{footer} 内のたった一つの @<code>{div} 要素は、正しく配置されます。

そして、今後要素が増えた際に必要になることと、基本形を明示するところから、記してみました。

== レスポンシブ対応

iPhone での表示設定が完了しましたので、iPad や Mac など、より画面幅の広い端末で見たときに心地よく見られるよう、レスポンシブ対応を行っていきましょう。

画面幅を活かし、左側に「じゃんけん機能」、右側に「紹介記事」を配置することとします。

@<code>{body}コンテナの行や列の構成を若干修正し、それに応じて、「じゃんけん機能」と「紹介記事」の配置先を調整して、完成です。

//list[][janken.css][234]{
/*---------------------------------------------------------------------
  レスポンシブ対応 幅768px以上の端末用に追加CSSを記述する
---------------------------------------------------------------------*/
@media (width >= 768px) {

  /* ページ全体の設定
  ---------------------------------------------------------------------*/
  body {                       /* body は全ての要素の親 */
    display: grid;             /* グリッド(格子)線を使うモードにする */
    grid-template-columns:     /* column(列) の設定 */
          1fr 345px 345px 1fr; /* 左右に余白 中央に345pxを二列確保 */
    grid-template-rows:        /* row(行)を用意する */
          [head]         100px /* 一行目の高さは100px */
                               /* 線名をheadと命名 */
          [main article] auto  /* 二行目の高さは自動 */
                               /* 線名を main 及び article と命名 */
                               /* 二つの線を一本に束ねる */
          [foot] 100px;        /* 四行目の高さは100px footと命名 */
    column-gap: 20px;          /* 列の間隔は 20px 開ける */

  }

  /* メイン(サイト主要機能部)
  ---------------------------------------------------------------------*/
  main {                       /* main 要素を対象に */
    grid-column: 2 / 3;        /* main 要素を二列目から三列目までに配置 */
  }

  /* じゃんけん紹介記事
  ---------------------------------------------------------------------*/
  article {
    grid-column: 3 / 4;        /* aritcle 要素を三列目から四列目までに配置 */
  }
}
//}

//image[ipad][][width=74%,border=on]
//image[iphone][][width=41%,border=on]
