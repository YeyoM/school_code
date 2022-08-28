import { useState, useEffect } from 'react'
import getConjuntoPotencia from './conjuntoPotencia'
import getCardinalidad from './cardinalidad'
import getProbabilidad from './probabilidad'
import './App.css'

function App() {

  const initialArray = ['aaa', 'aas', 'asa', 'ass', 'saa', 'sas', 'ssa', 'sss']
  const [conjuntoPotencia, setConjuntoPotencia] = useState([])
  const [cardinalidad, setCardinalidad] = useState([])
  const [probabilidad, setProbabilidad] = useState([])

  useEffect(() => {
    setConjuntoPotencia(getConjuntoPotencia(initialArray))
    setCardinalidad(getCardinalidad(initialArray))
    setProbabilidad(getProbabilidad(initialArray))
  }, [])

  return (
    <div className="App">
      <h1>Eventos posibles</h1>
      <h4>By: Diego Emilio Moreno Sachez</h4>
      <h4>ID: 264776</h4>
      <h3>Conjunto de eventos simples</h3>
      <h4>{"{ "}{initialArray.join(', ')}{" }"}</h4>
      <table> 
        <thead>
          <tr>
            <th>Evento A</th>
            <th>Cardinalidad Evento A</th>
            <th>Probabilidad Evento A</th>
          </tr>
        </thead>
        <tbody>
          {conjuntoPotencia.map((subconjunto, index) => (
            <tr key={index}>
              <td>
                {"{ "}
                  {subconjunto.map((elemento) => (
                    <span key={elemento}>{elemento} </span>
                  ))}
                {"}"}
              </td>
              <td>{cardinalidad[index]}</td>
              <td>{probabilidad[index]}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  )
}

export default App
