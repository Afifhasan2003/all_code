import React, { use } from 'react'
import Link from 'next/link'

interface User{
  id: number;
  name: string;
  username:string;
}

const usersPage = async () => {

  const res = await fetch('https://jsonplaceholder.typicode.com/users',
    {cache:'no-store'}
    // {next:{revalidate:100}}
  );
  const users:User[] = await res.json();

  return (
    <>
        <h1>Users</h1>
        <p>{ new Date().toLocaleTimeString() }</p>

        <ul>
            {users.map(user => <li key = {user.id}> {user.username} </li> )}
        </ul>
    </>
  )
}

export default usersPage
