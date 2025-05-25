let xp = 0;
let health = 100;
let gold = 50; 
let currenWeapon=0;
let fighting;
let monsterHealth;
let inventory= ["stick"];

const button1 = document.querySelector("#button1");
const button2 = document.querySelector("#button2");
const button3 = document.querySelector("#button3");

const text = document.querySelector("#text");
const xpText = document.querySelector("#xpText");
const healthText = document.querySelector("#healthText");
const goldText = document.querySelector("#goldText");

const monsterStats = document.querySelector("#monsterStats");
const monsterNameText = document.querySelector("#monsterName");
const monsterHealthText = document.querySelector("#monsterHealth");

//lets start with the buttons

button1.onclick = goStore;
button2.onclick = goCave ;
button3.onclick = fightDragon;


const locations = [
      {
            name : "town",
            "button text" : ["go to store","Go Cave", " Fight Dragon"  ],
            "button function":[goStore ,goCave, fightDragon],
            text : "you are at the town hall",
      },
      {
            name : "Store",
            "button text" : ["Buy 10 health", "Buy weapon", "Go to town"],
            "button function" : [buyHealth, buyWeapon, goTown],
            text:"you entered the store"
      },
      {
            name: "cave",
            "button text": ["fight slime", "fight beast", "Go to town"],
            "button function": [fightSlime, fightBeast, goTown],
            text:"You entered the cave. You see many mosters"
      },
      {
            name: "fight",
            "button text": ["Attack", "Dodge", "Run"],
            "button function": [attack,dodge,goTown],
            text:"You are fighting!!!"
      }
]

const weapons =[
  {
    name:"stick",
    power: 5
  },
  {
    name: "dagger",
    power: 30
  },
  {
    name: "hammer",
    power: 50
  },
  {
    name: "sword",
    power: 100
  }
]

const monsters =[
    {
      name: "slime",
      level: 2,
      health: 15
    },
    {
      name: "beast",
      level: 8,
      health:60
    },
    {
      name:"dragon",
      level:20,
      health:300
    }
]

function update(location){
      button1.innerText = location["button text"][0];
      button2.innerText = location["button text"][1];
      button3.innerText = location["button text"][2];
      button1.onclick = location["button function"][0];
      button2.onclick = location["button function"][1];
      button3.onclick = location["button function"][2];
   // text.innerText = location["text"];                        both works.. if two word then it has to be with " "
      text.innerText = location.text;
}

function goStore() {

     update(locations[1]);

}

function goTown(){
      update(locations[0]);
}

function goCave(){
      update(locations[2]);
}

function buyHealth(){
  if (gold >=10) {
      gold -=10;
      health +=10;
      healthText.innerText=health;
      goldText.innerText=gold;
    } 
    else{
      text.innerText="you dont enough gold ";
    }
 
}
function buyWeapon(){

  if (currenWeapon< weapons.length -1) {
      if (gold >=30) {
        gold -=30;
        goldText.innerText=gold;
        currenWeapon++;
        let newWeapon=weapons[currenWeapon].name;         
        text.innerText = "you now have a "+ newWeapon + ".";
        inventory.push(newWeapon);     //keeping new weapons in the inventory
        text.innerText +="you have " + inventory + " in your inventory";
      }
      else{
        text.innerText="you dont have enough gold"
      }
  }
  else{
    
    text.innerText = "you already have the most powerful weapon";
    button2.innerText="sell weapon(15gold)";
    button2.onclick=sellWeapon;
  }
  
}
function sellWeapon(){
  if (inventory.length>1) {
    gold +=15;
    goldText.innerText=gold;
      let curWeapon=inventory.shift();
      text.innerText="you sold " + curWeapon ;
      text.innerText +="you have " + inventory + " in your inventory";
    }
    else {
      text.innerText = " dont sell your only weapon!!";
    }
  }




  function fightSlime(){
    fighting =0;
    goFight();
  }

  function fightBeast(){

  }

  function fightDragon(){
    
  }

  function goFight(location){
      update(locations[3])
  }