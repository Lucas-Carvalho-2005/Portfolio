class Pilha<T> {
  private elementos: T[];

  constructor() {
    this.elementos = [];
  }

  push(elemento: T): void {
    this.elementos.push(elemento);
  }

  pop(): T | undefined {
    return this.elementos.pop();
  }

  peek(): T | undefined {
    return this.elementos[this.elementos.length - 1];
  }

  isEmpty(): boolean {
    return this.elementos.length === 0;
  }

  size(): number {
    return this.elementos.length;
  }

  imprimir(): void {
    console.log(this.elementos);
  }
}



const pilhaNumeros = new Pilha<number>();


pilhaNumeros.push(10);
pilhaNumeros.push(20);
pilhaNumeros.push(30);

console.log("Pilha após push: ");
pilhaNumeros.imprimir(); 


const topo = pilhaNumeros.peek();
console.log(`Elemento no topo: ${topo}`); 


const removido = pilhaNumeros.pop();
console.log(`Elemento removido: ${removido}`); 

console.log("Pilha após pop: ");
pilhaNumeros.imprimir(); 


console.log(`Tamanho da pilha: ${pilhaNumeros.size()}`); 


console.log(`A pilha está vazia? ${pilhaNumeros.isEmpty()}`); 


pilhaNumeros.pop();
pilhaNumeros.pop();

console.log(`A pilha está vazia? ${pilhaNumeros.isEmpty()}`); 
