import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import App from './App.jsx'
import Props from './Props.jsx'

createRoot(document.getElementById('root')).render(
  <StrictMode>
    <Props name={"Abhay"} age={21} uniName={"GEHU"} ></Props>
  </StrictMode>
)
