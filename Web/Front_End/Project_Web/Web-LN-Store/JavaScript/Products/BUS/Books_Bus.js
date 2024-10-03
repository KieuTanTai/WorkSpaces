import Books from "../DTO/ProductString.js";
import booksArray from "../books.js";
// import {writeFileSync} from "../../../../../../../../node_modules/dlv"
class Books_Bus {
     #booksList = [];

     getBookList () {
          return this.#booksList;
     }

     // renderId() {
     //      const character = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
     //      const charLength = character.length;
     //      return `${Math.round(Math.random() * 100) + character.charAt(Math.random() * charLength) + Math.round(Math.random() * 100)}`;
     // }

     importList () {
          booksArray.forEach((bookInfo) => {
               let productBooks = new Books(...bookInfo);
               // productBooks.setId(this.renderId());
               productBooks.getProduct();
               this.#booksList.push(productBooks);
          })
     }

     exportList () {
          let newArray = [];
          this.#booksList.forEach((bookElement) => {
               let tempArray = [
                    bookElement.getId(), 
                    bookElement.getImage(), 
                    bookElement.getTypeOfBook(), 
                    bookElement.getGenre(), 
                    bookElement.getName(), 
                    bookElement.getSale(), 
                    bookElement.getPrice()
               ];
               newArray.push(tempArray);
          }) 
          return newArray;
     }

     addBook (book) {
          if(book instanceof Books) 
               this.#booksList.push(book);
     }

     removeBook (id) {
          this.#booksList.forEach((bookElement, index) => {
               if(bookElement.getId() === id)
                    this.#booksList.splice(index, 1);
          }); 
     }

     editBook (book) {
          if(book instanceof Books) {
               this.#booksList.forEach((bookElement) => {
                    if(bookElement instanceof Books) {
                         if(book.getId() === bookElement.getId()) {
                              bookElement.setGenre(book.getGenre());
                              bookElement.setImage(book.getImage());
                              bookElement.setName(book.getName());
                              bookElement.setSale(book.getSale());
                              bookElement.setPrice(book.getPrice());
                              bookElement.setTypeOfBook(book.getTypeOfBook());
                         }
                    }
               })
          }
     }

}

function getData (arrayProduct) {
     const JSONToFile = (arrayProduct, tempFile) => {
          const blob = new Blob([JSON.stringify(arrayProduct)], {
            type: 'application/json',
          });
          const url = URL.createObjectURL(blob);
          const a = document.createElement('a');
          a.href = url;
          a.download = `${tempFile}.json`;
          a.click();
          URL.revokeObjectURL(url);
        };
        
        JSONToFile(...arrayProduct, 'testJsonFile');
}

document.addEventListener("DOMContentLoaded", () => {
     let temp = new Books_Bus();
     temp.importList();
     let arrayProduct = temp.getBookList();
     let id = arrayProduct[3].getId();
     // temp.removeBook(id);
     let temp2 = arrayProduct[3];
     console.log(temp2);
     // temp2.setName("Hello World");
     // temp.editBook(temp2);
     console.log(...arrayProduct);
     console.log(temp);
     // getData(arrayProduct);
});