'use strict'
import Products from "./Products.js"
class Books extends Products {
     // #booksArray = [];
     #pTypeOfBook;
     #pGenre;

     constructor (id, pImage, pTypeOfBook, pGenre, pName, pSale, pPrice) {
          super (id, pImage, pName, pSale, pPrice);
          this.#pTypeOfBook = pTypeOfBook;
          this.#pGenre = pGenre;
     }

     getTypeOfBook () {
          return this.#pTypeOfBook;
     }

     getGenre () {
          return this.#pGenre;
     }

     setTypeOfBook(pTypeOfBook) {
          this.#pTypeOfBook = pTypeOfBook; 
     }

     setGenre(pGenre) {
          this.#pGenre = pGenre;
     }

}

export default Books;

 