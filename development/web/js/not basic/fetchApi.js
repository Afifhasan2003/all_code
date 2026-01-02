

const URL = "https://randomuser.me/api/"


const getFacts = async () =>{
    // console.log("getting data")
    let response =await fetch(URL);     //type: get request

    // console.log(response)
    // console.log(response.status)
    const data = await response.json()
    console.log(data.results)

    
}

getFacts()

// Function to fetch exchange rate from any base to target currency
async function getExchangeRate(baseCurrency, targetCurrency) {
  try {
    const response = await fetch(`https://cdn.jsdelivr.net/npm/@fawazahmed0/currency-api@latest/v1/currencies/${baseCurrency}.json`);
    const data = await response.json();
    const rate = data[baseCurrency][targetCurrency];
    console.log(`1 ${baseCurrency.toUpperCase()} = ${rate} ${targetCurrency.toUpperCase()}`);
  } catch (error) {
    console.error('Error fetching exchange rate:', error);
  }
}

// Example usage:
getExchangeRate('usd', 'bdt');
