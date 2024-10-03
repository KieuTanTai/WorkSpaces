

document.addEventListener("DOMContentLoaded", () => {
     let temp = 65000;
     console.log(temp.toLocaleString('vi-VN', {style: "currency", currency: "VND"}));
     let temp2 = {
          "key1" : "hello world",
          "key2" : "javascript",
          "key3" : "python",
          "key4" : "C++", 
          "key5" : "C#"
     }

     let temp3 = new Map(
     [          
          ['key1', '30$'],
          ['key2', '10$'],
          ['key3', '20$'],
          ['key4', '50$'],
          ['key6', '70$']
     ]
     );
     
     console.log(temp3);

});