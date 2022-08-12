const arr = ['a', 'b', 'c', 'd']
const n = arr.length

const factorial = (n) => {
  if (n === 1) {
    return n
  } else {
    return n * factorial(n - 1)
  }
}

const permutacion = (n, r) => {
  return (factorial(n) / factorial(n - r))
}

const seleccionarUno = (arr, seleccionados, iterador) => {
  let seleccionado
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] !== seleccionados[iterador]) {
      seleccionado = arr[i]
      break
    }
  }
  return seleccionado
}

const mostrarPermutaciones = (arr) => {
  var result = [];
    var backtrack = (i, nums) => {
      if(i===nums.length){
        result.push(nums.slice());
        return;
      }  
      for(let j = i; j < nums.length; j++){
        [nums[i],nums[j]] = [nums[j],nums[i]];
        backtrack(i+1, nums);
        [nums[i],nums[j]] = [nums[j],nums[i]];
      }
    }
    backtrack(0, nums);
    console.log(result);
    return result;
}

console.log(permutacion(n, 3))
mostrarPermutaciones(arr)
