const items = [
    { 
        id: 1,
        name: "Pen" ,
        iscomplete: true
    },
    { 
        id: 2, 
        name: "Bottle" ,
        iscomplete: false
    },
    { 
        id: 3,  
        name: "Food",
        iscomplete: true
    }
    , 
    { 
        id: 4, 
        name: "Book" ,
        iscomplete: false
    },
    { 
        id: 5,  
        name: "Pencil",
        iscomplete: true
    }
];
//its an array of objects


for(let i=0; i<3;i++){
    console.log(items[i])
}

for(let item of items){
    console.log(item.name)
}

items.forEach(function(item){
    console.log(item.name);
})

let i = 0;
while (i < items.length){
    console.log(items[i]);
    i++;
}

do{
    console.log(items[i]);
    i++;
}while (i < items.length);




const itemNames = items.map(function(item){     //map returns an array
    return item.name;
});

console.log(itemNames);  //here itemName is array of item.name 




console.log('filtering completed items')
const completeditems = items.filter(function(item){
    return item.iscomplete === true;
});

console.log(completeditems);

console.log('filtering just the names of completed items')
const completeditemNames = items.filter(function(item){
    return item.iscomplete === true;
}).map(function(item){
    return item.name;
});
console.log(completeditemNames);

