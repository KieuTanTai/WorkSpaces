'use strict'
class Products {
     #pImage; 
     #pSale; 
     #pName; 
     #pPrice;

     // add a static private variable 
     static #pId = () => {
          const character = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
          const charLength = character.length;
          return `${Math.round(Math.random() * 100) + character.charAt(Math.random() * charLength) + Math.round(Math.random() * 100)}`;
     }

     // get value of this variable with getters
     static getPId() {
          return Products.#pId;
     }

     constructor (pImage, pName, pSale, pPrice) {
          this.#pImage = pImage;
          this.#pName = pName;
          this.#pSale= pSale;
          this.#pPrice = pPrice;
     }

     getProduct() {
          return {
               "id" : Products.#pId(), 
               "image" : this.#pImage,
               "name" :this.#pName,
               "sale" : this.#pSale, 
               "price" : this.#pPrice            
          }
     }

     setProduct_pImage (repImage) {
          this.#pImage = repImage;
     }

     setProduct_pSale (repSale) {
          this.#pSale = repSale;
     }

     setProduct_pName (repName) {
          this.#pName = repName;
     }

     setProduct_pPrice (repPrice) {
          this.#pPrice = repPrice;
     }
}

export default Products;