"use strict";

function Hello(h) {
  var hello = h.target;
  h.stopPropagation();
  console.log(hello);
}

var helloValue = document.querySelector('button');
helloValue.addEventListener('click', Hello);
setTimeout(function () {
  helloValue.removeEventListener('click', Hello);
  console.warn("hello");
}, 4000);