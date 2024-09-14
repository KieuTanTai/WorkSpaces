document.addEventListener('DOMContentLoaded', function () {
     var bodyIndex = document.getElementsByClassName('body-index');
     var background = document.getElementsByClassName('js-bg-white');
     var button = document.getElementById('change-bg-btn');
     button.onclick = function () {
         if (background.length) {
             // set dark background for elements have class js-bg-white
             var elementsWhite = document.querySelectorAll('.js-bg-white');
             elementsWhite.forEach((element) => {
                 element.classList.add('js-bg-dark');
                 element.classList.remove('js-bg-white');
             })
             if (bodyIndex.length === 1) {
                 // set dark background for body tags
                 var mainBody = document.querySelectorAll('.body-index');
                 mainBody.forEach((bodyTheme) => {
                     bodyTheme.classList.add('body-theme');
                 });
             }
         } 
         else {
             // if not have any elements have js-bg-white class 
             // so query elements have js-bg-dark class and change it
             var elementsDark = document.querySelectorAll('.js-bg-dark');
             elementsDark.forEach((element) => {
                 element.classList.add('js-bg-white');
                 element.classList.remove('js-bg-dark');
             });
             // remove body theme
             var mainBody = document.querySelectorAll('.body-index');            
             mainBody.forEach((bodyTheme) => {
                 bodyTheme.classList.remove('body-theme');
             });
         }
     }
  });