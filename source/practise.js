// 厳格モードを呼び出すことで 潜在的なバグを減らす
'use strict';

// CSSセレクタを使ってDOMツリー中のh1要素を取得する
const heading       = document.querySelector("h1");

// 取得したh1要素に含まれるテキストコンテンツ(=おはよう)を取得する
const headingText   = heading.textContent;

// 「おはよう」が取得されているはずなので、表示する。
alert(headingText);

// 取得したテキストコンテンツを変更する
heading.textContent = "こんにちは"

// button要素を作成する
const button = document.createElement("button");
button.textContent = "ボタンを押してください";

// body要素の子要素としてbuttonを挿入する
document.body.appendChild(button);
