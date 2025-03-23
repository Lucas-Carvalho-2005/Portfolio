function produto(a: number, b: number): number {
    if (b === 0) {
        return 0;
    }
    if (b < 0) {
        return -produto(a, -b);
    }
    if (b % 2 === 0) {
        return produto(a + a, b / 2);
    } else {
        return a + produto(a, b - 1);
    }
}

console.log(produto(5, 3)); 
console.log(produto(-2, 4));
console.log(produto(7, -3)); 
console.log(produto(0, 5));
