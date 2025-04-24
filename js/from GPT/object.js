let person = {
    name: "Alice",        // Key: "name", Value: "Alice"
    age: 25,             // Key: "age", Value: 25
    isStudent: true      // Key: "isStudent", Value: true
  };
  
  // Accessing object properties
  console.log(person.name);      // "Alice"
  console.log(person["age"]);    // 25
  
  // Adding a property
  person.country = "USA";
  console.log(person);           // { name: "Alice", age: 25, isStudent: true, country: "USA" }
  
  // Modifying a property
  person.age = 26;
  console.log(person.age);       // 26
  
  // Removing a property
  delete person.isStudent;
  console.log(person);           // { name: "Alice", age: 26, country: "USA" }
  