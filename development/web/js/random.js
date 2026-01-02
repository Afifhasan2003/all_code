let hag = document.querySelectorAll(".myclass")  //if used 

// h2Tag.innerHTML = "<h1>hello from hasan </h1>"
hag.innerText = "modified by hasan"

console.log(hag) // this will give the entire html document in a tree structure
hag[0].innerText = "modified by hasan"

hag[1].innerHTML = "<h1>hello from hasan </h1>"