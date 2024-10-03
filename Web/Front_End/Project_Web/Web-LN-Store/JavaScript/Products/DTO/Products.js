'use strict'
class Products {
     #image; 
     #sale; 
     #name; 
     #price;
     #id;

     constructor (id, image, name, sale, price) {
          this.#id = id;
          this.#image = image;
          this.#name = name;
          this.#sale= sale;
          this.#price = price;
     }

     setId(id) {
          this.#id = id;
     }

     getId() {
          return this.#id;
     }

     getProduct() {
          return {
               "id" : this.#id, 
               "image" : this.#image,
               "name" :this.#name,
               "sale" : this.#sale, 
               "price" : this.#price            
          }
     }

     getImage () {
          return this.#image; 
     }

     setImage (reImage) {
          this.#image = reImage;
     }

     getSale () {
          return this.#sale;
     }

     setSale (reSale) {
          this.#sale = reSale;
     }

     getName () {
          return this.#name;
     }

     setName (rename) {
          this.#name = rename;
     }

     getPrice () {
          return this.#price;
     }

     setPrice (reprice) {
          this.#price = reprice;
     }
}

export default Products;