const array = ['aaa', 'aas', 'asa', 'ass', 'saa', 'sas', 'ssa', 'sss']
const length = array.length

const tam_conjuntoPotencia = Math.pow(2, length)

for (let i = 0; i < tam_conjuntoPotencia; i++) {
  let conjuntoPotencia = []
  for (let j = 0; j < length; j++) {
    // Hacemos la comparacion de bits
    if (i & (1 << j)) {
      conjuntoPotencia.push(array[j])
    }
  }
  console.log('{' + conjuntoPotencia.join(', ') + '}' + ' -> ' + (conjuntoPotencia.length) + ' -> ' + (conjuntoPotencia.length / array.length))
  conjuntoPotencia.length = 0
}
console.log(tam_conjuntoPotencia)

///////////////////////////////////////////////////////////////////////////

const [subconjuntoPotencia, setSubconjuntoPotencia] = useState([])
const [conjunto, setConjunto] = useState(['aaa', 'aas', 'asa', 'ass', 'saa', 'sas', 'ssa', 'sss'])
const [tamConjuntoPotencia, setTamCOnjuntoPotencia] = useState(Math.pow(2, conjunto.length))

return(
  <div>
    <table>
      <thead>
        <tr>
          <td>
            Evento A
          </td>
          <td>
            Cardinalidad A
          </td>
          <td>
            Probabilidad P(A)
          </td>
        </tr>
      </thead>
      {
        for (let i = 0; i < tamConjuntoPotencia; i++) {
          
        }
      }
    </table>
  </div>
)