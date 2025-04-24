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
];

for(let i=0; i<3;i++){
    console.log(items[i])
}

for(let item of items){
    console.log(item.name)
}

items.forEach(function(item){
    console.log(item.name);
})

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