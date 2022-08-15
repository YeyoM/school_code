class TreeNode {
  constructor(key, value = key, parent = null) {
    this.key = key;
    this.value = value;
    this.parent = parent;
    this.children = [];
  }

  get isLeaf() {
    return this.children.length === 0;
  }

  get hasChildren() {
    return !this.isLeaf;
  }
}

class Tree {
  constructor(key, value = key) {
    this.root = new TreeNode(key, value);
  }

  *preOrderTraversal(node = this.root) {
    yield node;
    if (node.children.length) {
      for (let child of node.children) {
        yield* this.preOrderTraversal(child);
      }
    }
  }

  *postOrderTraversal(node = this.root) {
    if (node.children.length) {
      for (let child of node.children) {
        yield* this.postOrderTraversal(child);
      }
    }
    yield node;
  }

  insert(parentNodeKey, key, value = key) {
    for (let node of this.preOrderTraversal()) {
      if (node.key === parentNodeKey) {
        node.children.push(new TreeNode(key, value, node));
        return true;
      }
    }
    return false;
  }

  remove(key) {
    for (let node of this.preOrderTraversal()) {
      const filtered = node.children.filter(c => c.key !== key);
      if (filtered.length !== node.children.length) {
        node.children = filtered;
        return true;
      }
    }
    return false;
  }

  find(key) {
    for (let node of this.preOrderTraversal()) {
      if (node.key === key) return node;
    }
    return undefined;
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////

const tree = new Tree(1, '');

const arr = ['a', 'b', 'c', 'd']
const n = arr.length
const r = 3
let actualR = 0
let actualPermutaciones = 0

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

const permutaciones = permutacion(n, r)

const generatePermutationsTree = (arr, n, actualR, r, parent, actualPermutaciones, permutaciones) => {
  for (let i = 0; i < n; i++) {
    if (actualR === r) {
      return
    } else {
      for (let j = 0; j < n - actualR; j++) {
        parent.children.push(new TreeNode(parent.key, `${parent.key}${arr[j]}`, `${parent.key}${arr[j]}`))
        generatePermutationsTree(arr, n, actualR + 1, r, parent.children[parent.children.length - 1], actualPermutaciones, permutaciones)
      }
    }
  }
}

/**
 if (actualPermutaciones === permutaciones) {
    return
  } else {
    for (let i = 0; i < n - actualR; i++) {
      if (i !== 0) {
        parent.children.push(new TreeNode(parent.key, arr[i], arr[i]))
      } else {
        parent.children.push(new TreeNode(parent.key, arr[i], arr[i]))
        
      tree.insert(parent.key, arr[i], arr[i])
      generatePermutationsTree(arr, n, actualR + 1, r, tree.find(arr[i]), actualPermutaciones + 1, permutaciones)
    }
  }
 */

generatePermutationsTree(arr, n, actualR, r, tree.root, actualPermutaciones, permutaciones);
console.log(tree.find('a'))
