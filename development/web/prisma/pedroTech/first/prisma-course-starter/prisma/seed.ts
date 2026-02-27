import {PrismaClient} from '@prisma/client'
const prisma = new PrismaClient();

async function seed(){
  await prisma.user.createMany({
    data:[

      {name:"afif", email:"afif@example.com", age:20, isMarried:true, nationality:"Bangladeshi"},
      {name:"hasan", email:"hasan@example.com", age:25, isMarried:false, nationality:"Indian"}
    ]

  })
}


seed().then(()=> prisma.$disconnect());