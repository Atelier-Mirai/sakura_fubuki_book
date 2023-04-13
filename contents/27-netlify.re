= ウェブサイトの公開

//abstract{
  従来、ウェブサイトを公開するためには、@<B>{サーバー}と呼ばれるコンピュータに適宜様々な設定を施し、運用してきました。安全に運用するためにはそれなりの伎倆が求められるものでしたが、こうした中、台頭してきたのが、各種の@<B>{ホスティングサービス}です。簡単にそして安価に運用することができます。

  ここでは、@<ruby>{Netlify,ネットリファイ} をご紹介します。
//}

== @<ruby>{Netlify,ネットリファイ}

Netlify は、「ウェブサイトを構築する最速の方法です」と紹介されているように、HTML / CSS / JavaScript を簡単に配信できるサイトです。

=== 簡単公開

#@# //sideimage[drag_and_drop][75mm][sep=5mm,side=R]{
@<href>{https://app.netlify.com/drop, https://app.netlify.com/drop} をブラウザで開き、ウェブサイト一式を直接アップロードするだけで、全世界に公開できます。

じゃんけんゲーム一式を、例えば「@<file>{study}フォルダ」に作成したのであれば、
この「@<file>{study}フォルダ」をドラッグ＆ドロップするだけで、じゃんけんゲームを24時間公開できます。
#@# //}

//image[drag_and_drop][][width=80%]

//clearpage

=== 会員登録の利点
Netlifyは、小規模利用 @<fn>{shoukibo}なら無料でサイトを公開できるサービスです。
会員登録せずとも利用可能ですが、登録することにより、

 * サイトを永久的に公開できる。
 * サイト名を好きな名前に変更できる。
 * 問い合わせフォームの投稿を、メールで通知できる。

など、様々な機能が使えるようになりますので、登録がお薦めです。

//blankline
また、バージョン管理システムとして @<ruby>{Git, ギット} や リポジトリサービスである @<ruby>{GitHub, ギットハブ}, @<ruby>{GitLab, ギットラボ}, @<ruby>{Bitbucket, ビットバケット} を使っている方なら、より便利に連携して使うことができます。

//footnote[shoukibo][Starterプラン(無料プラン)は、転送量: 100GB/月まで、容量: 100GB までです。じゃんけんゲームは約100kBの容量があります。単純計算ですが、毎日3万人が見るようになったら、有料プランへの移行を考えると良いでしょう。]

=== 会員登録の方法

 - 1. ブラウザを開いて @<href>{https://www.netlify.com/,Netlify} にアクセスします。
//image[netlify01][][width=100%]

//sideimage[netlify02-1][60mm][sep=5mm,side=R]{
 - 2. 右上の青い「@<code>{Sign up}ボタン」を押すと、次の画面になります。 @<br>{}
  @<ruby>{GitHub, ギットハブ}, @<ruby>{GitLab, ギットラボ}, @<ruby>{Bitbucket, ビットバケット} を使っていると、それぞれのアカウントを利用して、Netlifyへの登録ができますが、ここでは一番下の「Email」を押します。
//}

//sideimage[netlify03-1][60mm][sep=5mm,side=R]{
 - 3. メールアドレスとパスワードを入力し、「@<code>{Sign up}ボタン」を押します。
//}

//sideimage[netlify04-1][60mm][sep=5mm,side=R]{
 - 4. 次の画面が表示されます。メールを送ったので確認してくれとのことです。
//}

 - 5. メールソフトを確認すると、Netlifyからのメールが届いていました。緑色の「Verify email」を押します。@<small>{（不正利用やメールアドレスの入力ミス対策などの為に、良く用いられる仕組みです。）}
//image[netlify05-1][][width=80%]

#@# //clearpage

 - 6. 緑色の「Verify email」ボタンを押すと、利用者登録の続きを行うことができます。利用目的の回答が必須です。「Work」「Client」「Personal」「School」の中から、今回は個人的に使いたいので、「Personal」を選びます。また「Hobby Developer」、「Personal / portfolio site」など、適宜回答します。最後に「チーム名」です。未入力でも適宜設定されますし、後からでも変更できます。 最後に、水色の「Set up and continue」ボタンを押します。これで会員登録は完了です。

//image[netlify07-1][][width=80%]

=== デプロイ（配備・配信）方法

会員登録も完了しましたので、デプロイ（配備・配信）していきましょう。

 - 1. ブラウザを開いて @<href>{https://www.netlify.com/,Netlify} にアクセスし、右上の青い「@<code>{Sign up}ボタン」の左側にある「@<code>{Log in}」を押します。
//image[netlify01-1][][width=100%]

//sideimage[netlify10-5][60mm][sep=5mm,side=R]{
 - 2. 「Email」を押します。
//}

//sideimage[netlify10-6][60mm][sep=5mm,side=R]{
 - 3. メールアドレスをパスワードを入力して、「Log in」ボタンを押します。
//}

 - 4. ログインすると、「Team overview」の画面が開きます。
//image[netlify10][][width=100%]

「@<code>{Sites}欄」には今まで公開したサイトが表示されます(公開後の例です)。
//image[netlify10-7][][width=100%]

今はまだ何も公開したサイトがないので、代わりに公開方法の案内が表示されています。

@<ruby>{GitHub, ギットハブ}, @<ruby>{GitLab, ギットラボ}, @<ruby>{Bitbucket, ビットバケット} を使っている場合には、左上の「Import fro Git」から、取り込むこともできます。 @<br>{}

ここでは、手動で公開することにしましょう。画面中央下の「Drag and drop your site output folder here」に、公開したサイト一式を納めたフォルダを、ドラッグ＆ドロップすると公開できます。@<br>{}

 - 5. しばらくすると、デプロイ（配備・配信）が完了します。@<code>{joyful-churros-1635c9}というサイト名で作成されたようです。
//image[netlify11][][width=90%]

 - 6. 「@<code>{joyful-churros-1635c9}」と付けられたサイト名は、Netlifyが適宜命名したものなので、改名しましょう。「@<code>{Site settings}」を押すと、サイトの詳細を確認できます。
//image[netlify12][][width=75%]

 - 7. 「@<code>{Change site name}」を押すと、名称を変更できます。@<code>{joyful-churros-1635c9} から @<code>{joyful-janken} に変更してみましょう。@<code>{Site name} 欄に入力したら、@<code>{Save} ボタンを押します。
//image[netlify13][][width=75%]

 - 8. ちなみに削除したくなった場合には、一番下までスクロールすると 「Danger zone」に「@<code>{Delete this site}」ボタンがあるので押します。本当に削除して良いのか確認を求められます。「Type in the name of this site to confirm」欄に、サイト名「@<code>{joyful-janken}」と入力すると、「@<code>{Delete}」ボタンが押せるようになります。「@<code>{Delete}」を押すとサイトが削除されます。復活はできないので注意して使ってください。
//image[netlify14][][width=80%]

 - 9. それでは、デプロイ（配備・配信）したサイトを確認しましょう。 @<br>{}
   「@<code>{Site overview}」の画面では、@<code>{https://joyful-janken.netlify.app} と表示されています。クリックすると開きます。
//image[netlify14-8][][width=85%]

//clearpage
 - 10. サイトを開いてみると想定と違います。どうやら CSS が適用されていないようです。
//image[netlify15][][width=75%]

 - 11. ファイルやコードを良く見直して、もう一度デプロイ（配備・配信）しましょう。「@<code>{Site overview}」の隣に「@<code>{Deploys}」メニューがありますので、クリックします。
//image[netlify16][][width=90%]


//clearpage
 - 12. 画面中央下に「Drag and drop your site output folder here」と書かれていますので、サイト一式を納めたフォルダを、もう一度ドラッグ＆ドロップしましょう。
//image[netlify16][][width=85%]

 - 13. しばらくするとデプロイ（配備・配信）が完了し、次の画面になります（時間がかかるようなら、再読み込みしましょう）。
//image[netlify18][][width=85%]

//clearpage

 - 14. 再度 @<code>{https://joyful-janken.netlify.app} を開きます。きちんと配信できました。
//image[netlify20][][width=100%]

 - 15. ログアウトするためには、右上の「Ｈ」ボタン（会員登録した名前によって変わります）をクリックします。いろいろなメニューが表示され、様々な設定を行うことができます。一番下の「@<code>{Sign out}」をクリックし、終了です。
//image[netlify21][][width=40%]
