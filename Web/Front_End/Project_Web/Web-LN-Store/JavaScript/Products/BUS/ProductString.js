'use strict'
import Products from "../DTO/Products.js";
import booksArray from "../books.js";
class Books extends Products {
     #booksArray = [];
     #pTypeOfBook;
     #pGenre;

     constructor (pImage, pTypeOfBook, pGenre, pName, pSale, pPrice) {
          super (pImage, pName, pSale, pPrice);
          this.pTypeOfBook = pTypeOfBook;
          this.pGenre = pGenre;
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

     getBooks () {
          return this.#booksArray;
     }

     addBooks (pImage, pTypeOfBook, pGenre, pName, pSale, pPrice) {
          let newProduct = new Products(pImage, pName, pSale, pPrice);
          this.setGenre(pGenre);
          this.setTypeOfBook(pTypeOfBook);
          let productArray = newProduct.getProduct();
          productArray['type'] = this.#pTypeOfBook;
          productArray['genre'] = this.#pTypeOfBook;
          this.#booksArray.push(productArray);
     }

     removeBooks (id) {
          this.#booksArray.forEach((book, index) => {
               if(book.id === id) {
                    this.#booksArray.splice(index, 1);
               }
          })
     }

     // changeBookInfo (id, ...rest) {

     // }
}

// create an array of object product
function createProductsList () {
     let bookProducts = new Books();
     booksArray.forEach((bookInfo) => {
          bookProducts.addBooks(...bookInfo);
     })
     let books = bookProducts.getBooks();
     console.log(books);
}
createProductsList();
