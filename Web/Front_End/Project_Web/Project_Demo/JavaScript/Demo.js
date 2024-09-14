//call back examples
//method find with expression function
Array.prototype.myFind = function(callBack) {
     if (typeof callBack === 'function') {
          for (let key in this) {
               if (this.hasOwnProperty(key)) {
                    let result = callBack(this[key], key, this);
                    if (result)
                         return this[key];
               }
          }
          return undefined;
     }
     return undefined;
}

//method forEach with declaration function
Array.prototype.myForEach = myForEach;
function myForEach(callBack) {
     if(typeof callBack === 'function') {
          let output = [];
          for(let key in this) {
               if(this.hasOwnProperty(key)) {
                    callBack(this[key], key, this);
               }
          }
     }
}

//method every
Array.prototype.myEvery = function(callBack) {
     if (typeof callBack === 'function') {
          for (let key in this) {
               if (this.hasOwnProperty(key)) {
                    let result = callBack(this[key], key, this);
                    if (!result) 
                         return false;
               }
          }
          return true;
     }
     return undefined;
}

//method some
Array.prototype.mySome = function(callBack) {
     let boolValue = false;
     if (typeof callBack === 'function') {
          for (let key in this) {
               if (this.hasOwnProperty(key)) {
                    let result = callBack(this[key], key, this);
                    if (result) {
                         boolValue = true;
                         break;
                    }
               }
          }
          return boolValue;
     }
     return undefined;
}

//method filter 
Array.prototype.myFilter = function(callBack) {
     if(typeof callBack === 'function') {
          let output = [];
          for(let key in this) {
               if(this.hasOwnProperty(key)) {
                    let result = callBack(this[key], key, this);
                    if(result) {
                         output.push(this[key]);
                    }
               }
          }
     return output;
     }
     return undefined;
}

//method map
Array.prototype.myMap = function(callBack) {
     if(typeof callBack === 'function') {
          let output = [];
          for(let key in this) {
               if(this.hasOwnProperty(key)) {
                    var result = callBack(this[key], key, this);
                    output.push(result);
               }
          }
          return output;
     }
     return undefined;
}

//method Reduce
Array.prototype.myReduce = function(callBack, initialValue) {
     if(typeof callBack === 'function') {
          let index = 0;
          //this case is not have initial value
          if(arguments.length < 2) {
               let initialValue = this[0];
               //In case not have initial value then initial value is the first element in Array
               // Current Value is the second element in Array
               index = 1; 
               for(index in this) {
                    if(this.hasOwnProperty(index)) {
                         initialValue = callBack(initialValue, this[index], index, this);
                    }
               }
          }
          //this case is have initial value
          else {
               for(index in this) {
                    if(this.hasOwnProperty(index)) {
                         initialValue = callBack(initialValue, this[index], index, this);
                    }
               }
          return initialValue;
          }
     return undefined;
     }
}
//value input
var languages = [
     'JavaScript',
     'PHP',
     'C++',
     'Python',
];
let courses = [
     {
          'name': 'JavaScript',
          'id':  12341,
          'coin': 180,
     },

     {
          'name': 'Python',
          'id':  12342,
          'coin': 200,
     },

     {
          'name': 'Sass',
          'id':  12332,
          'coin': 100,
     },

     {
          'name': 'Html, CSS',
          'id':  12351,
          'coin': 90,
     },

     {
          'name': 'Ruby',
          'id':  12381,
          'coin': 1810,
     },

     {
          'name': 'JavaScript',
          'id':  12341,
          'coin': 180,
     },


     {
          'name': 'Sass',
          'id':  12332,
          'coin': 100,
     },
];

//call function 
var value = languages.myFind(function(language, index) {
     return language === 'PHP';
});
var value1 = courses.myForEach(function(course, index) {
     console.log(index, course);
});
var value2 = courses.myEvery(function(course, index) {
     return course.coin > 100;
});
var value3 = courses.mySome((course, index) => {
     return course.coin > 100;
});
var value4 = courses.myFilter((course, index) => {
     return course.name === 'Sass';
});
var value5 = courses.myMap((course, index) => {
     return (`<h1> ${course.name} </h1>`);
});
var value6 = courses.myReduce((previousValue, currentValue, currentIndex) => {
     console.table({
          'currentIndex': currentIndex,
          'previousValue': previousValue,
          'currentValue': currentValue,
     });
     return previousValue.concat(currentValue.coin);
}, []);

console.log(`Index: ${value}`);
console.log(`Every: ${value2}`);
console.log(`Some: ${value3}`);
console.log(`Filter:`, value4);
console.log('Map:', value5.join('\n'));
console.log(`Reduce:`, value6);
console.log(languages.concat('JavaScript'));

