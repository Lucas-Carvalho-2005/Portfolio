var __spreadArray = (this && this.__spreadArray) || function (to, from, pack) {
    if (pack || arguments.length === 2) for (var i = 0, l = from.length, ar; i < l; i++) {
        if (ar || !(i in from)) {
            if (!ar) ar = Array.prototype.slice.call(from, 0, i);
            ar[i] = from[i];
        }
    }
    return to.concat(ar || Array.prototype.slice.call(from));
};
var alunos = [
    { codigo: 103, nome: "Paulo", cpf: "321.654.987-03" },
    { codigo: 100, nome: "Lúcio", cpf: "999.888.777-66" },
    { codigo: 102, nome: "Maria", cpf: "123.456.789-01" },
    { codigo: 104, nome: "Bruna", cpf: "111.222.333-44" },
    { codigo: 101, nome: "Mário", cpf: "987.654.321-00" },
];
function quickSort(alunos) {
    if (alunos.length <= 1) {
        return alunos;
    }
    var pivo = alunos[0];
    var menores = alunos.slice(1).filter(function (aluno) { return aluno.codigo < pivo.codigo; });
    var maiores = alunos.slice(1).filter(function (aluno) { return aluno.codigo >= pivo.codigo; });
    return __spreadArray(__spreadArray(__spreadArray([], quickSort(menores), true), [pivo], false), quickSort(maiores), true);
}
console.log("Lista de alunos desordenada:");
alunos.forEach(function (aluno) {
    console.log("".concat(aluno.codigo, " - ").concat(aluno.nome, " - ").concat(aluno.cpf));
});
var alunosOrdenados = quickSort(alunos);
console.log("\nLista de alunos ordenada por código:");
alunosOrdenados.forEach(function (aluno) {
    console.log("".concat(aluno.codigo, " - ").concat(aluno.nome, " - ").concat(aluno.cpf));
});
