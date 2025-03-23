interface Aluno {
    codigo: number;
    nome: string;
    cpf: string;
  }
  
  const alunos: Aluno[] = [
    { codigo: 103, nome: "Paulo", cpf: "321.654.987-03" },
    { codigo: 100, nome: "Lúcio", cpf: "999.888.777-66" },
    { codigo: 102, nome: "Maria", cpf: "123.456.789-01" },
    { codigo: 104, nome: "Bruna", cpf: "111.222.333-44" },
    { codigo: 101, nome: "Mário", cpf: "987.654.321-00" },
  ];
  
  function quickSort(alunos: Aluno[]): Aluno[] {
    if (alunos.length <= 1) {
      return alunos;
    }
  
    const pivo = alunos[0];
    const menores = alunos.slice(1).filter(aluno => aluno.codigo < pivo.codigo);
    const maiores = alunos.slice(1).filter(aluno => aluno.codigo >= pivo.codigo);
  
    return [...quickSort(menores), pivo, ...quickSort(maiores)];
  }
  
  console.log("Lista de alunos desordenada:");
  alunos.forEach(aluno => {
    console.log(`${aluno.codigo} - ${aluno.nome} - ${aluno.cpf}`);
  });
  
  const alunosOrdenados = quickSort(alunos);
  
  console.log("\nLista de alunos ordenada por código:");
  alunosOrdenados.forEach(aluno => {
    console.log(`${aluno.codigo} - ${aluno.nome} - ${aluno.cpf}`);
  });