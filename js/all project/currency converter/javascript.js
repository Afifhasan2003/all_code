const dropdowns = document.querySelectorAll(".dropDown select");
const button = document.querySelector("form button")
const inFrom = document.querySelector(".from select")
const inTo = document.querySelector(".to select")
const msg = document.querySelector(".msg p")

const Base = `https://cdn.jsdelivr.net/npm/@fawazahmed0/currency-api@latest/v1/currencies/`


for(let select of dropdowns){
    for(currencyCode in countryList){
        let newOption = document.createElement("option")
        newOption.innerText = currencyCode;
        newOption.value = currencyCode
        if(select.name === "from" && currencyCode === "USD")
            newOption.selected = "selected";
        else if(select.name ==="to" && currencyCode ==="BDT")
            newOption.selected = "selected";

        select.append(newOption)
    }
    select.addEventListener("change",(evt)=>{
        updateFlag2(evt.target);
        // console.log(evt.target)
    })
}
const updateFlag2 = (element) =>{
    let currencyCode = element.value;
    let countryCode = countryList[currencyCode];
    let imgSrc = `https://flagsapi.com/${countryCode}/flat/64.png`;
    let img = element.parentElement.querySelector("img");
    img.src = imgSrc;
}




const updateExchangeRate = async () => {
  let amount = document.querySelector(".amount input");
  let amtVal = amount.value;
  if (amtVal === "" || amtVal < 1) {
    amtVal = 1;
    amount.value = "1";
  }
  const URL = `${BASE_URL}/${fromCurr.value.toLowerCase()}/${toCurr.value.toLowerCase()}.json`;
  let response = await fetch(URL);
  let data = await response.json();
  let rate = data[toCurr.value.toLowerCase()];

  let finalAmount = amtVal * rate;
  msg.innerText = `${amtVal} ${fromCurr.value} = ${finalAmount} ${toCurr.value}`;
};



const updateExchangeRate2 = async ()=>{
    let amount = document.querySelector(".amount input")
    let enteredAmount = amount.value;
    if(enteredAmount < 1) {enteredAmount = 1 , amount.value = "1"}
    let from = inFrom.value.toLowerCase();
    let to = inTo.value.toLowerCase()
    const URL = `${Base}${from}ab.json`;

    try{
        // let response = await fetch(URL);
        let response = await fetch(`https://cdn.jsdelivr.net/npm/@fawazahmed0/currency-api@latest/v1/currencies/${from}.json`)
        let data = await response.json();
        let rate = data[from][to];
        let finalAmount = enteredAmount * rate;
        msg.innerText = `${enteredAmount} ${from.toUpperCase()} = ${finalAmount} ${to.toUpperCase()}`;
    } catch(error){
        console.error("There was an errorrrrrr",error)
    }

}



button.addEventListener("click",(evt)=>{
    evt.preventDefault();
    updateExchangeRate2();
})







// Function to fetch exchange rate from any base to target currency
async function getExchangeRate(baseCurrency, targetCurrency) {
  try {
    const response = await fetch(`https://cdn.jsdelivr.net/npm/@fawazahmed0/currency-api@latest/v1/currencies/${baseCurrency}.json`);
    const data = await response.json();
    // const rate = data.baseCurrency.targetCurrency  this wont work
    const rate = data[baseCurrency][targetCurrency];
    // console.log(`${rate} `);
  } catch (error) {
    console.error('Error fetching exchange rateeeee:',error);
  }
}

// Example usage:
getExchangeRate('usd', 'bdt');



