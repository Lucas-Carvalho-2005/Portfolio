function intercalarListas(lista1: number[], lista2: number[]): number[] {
    const intercalada: number[] = [];
    const maxLength = Math.max(lista1.length, lista2.length);

    for (let i = 0; i < maxLength; i++) {
        if (i < lista1.length) {
            intercalada.push(lista1[i]);
        }
        if (i < lista2.length) {
            intercalada.push(lista2[i]);
        }
    }

    return intercalada;
}

const lista1 = [1, 3, 5];
const lista2 = [2, 4, 6, 8];
const resultado = intercalarListas(lista1, lista2);
console.log(resultado);