import ReactDOM from 'react-dom/client'
import { StrictMode } from 'react'
import './index.css'
import App from './App'
import 'bootstrap/dist/css/bootstrap.css';


ReactDOM.createRoot(document.getElementById('root') as HTMLElement).render(
  <StrictMode>
    <App />
  </StrictMode>,
)
