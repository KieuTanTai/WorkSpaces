document.addEventListener('DOMContentLoaded', function() {
     let getClick = document.querySelector('.click');
     let getImage = document.getElementsByTagName('img');
     let getImageLength = getImage.length;
     for(let i = 0; i < getImageLength; i++) {
          console.log(getImage[i].removeAttribute('alt'))
     }
     getClick.style.backgroundColor = 'red';
     console.log(getClick);
     console.log(getImage);
     getClick.addEventListener('click', function(event) {
          console.log(event);
     });
});
