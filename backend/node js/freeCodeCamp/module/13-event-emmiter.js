const EventEmitter = require('events');  //EventEmitter is a class in the 'events' module

const customEmitter = new EventEmitter() // Create an instance/object of EventEmitter

customEmitter.on('response',()=>{        // Register an event listener for the 'response' event
    console.log(`data recieved`)         //event name is 'response'
})
customEmitter.on('response',()=>{        // Register another listener for the same event
    console.log(`some other logic here`)  // This will also run when the 'response' event is emitted
})




// You can also pass arguments to the event listeners
customEmitter.on('response2', (name, id) => { // Register a listener that takes parameters
    console.log(`data received with name: ${name} and id: ${id}`) // This will log the name and id passed when the event is emitted
})


customEmitter.emit('response')           // Emit the 'response' event, triggering the listener
customEmitter.emit('response2', 'john', 34) // Emit the 'response2' event with parameters 'john' and 34
