import { useEffect } from 'react';
import { useState } from 'react'
import axios from 'axios';

function App() {
  const [data, setData] = useState([]);

  useEffect(()=> {
    axios.get("https://jsonplaceholder.typicode.com/posts")
    .then((res) => {
      setData(res.data);
    })
    .catch((err)=> {
      console.log(err);
    })
  }, []);

  return (
    <ol>
      {data.map((items)=> <li>{items.title}</li>)}
    </ol>
  )
}

export default App
