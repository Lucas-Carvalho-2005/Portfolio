data class Aluno(val codigo: Int, val nome: String, val cpf: String)

fun ordenarAlunos(alunos: MutableList<Aluno>) {
    if (alunos.size <= 1) 
    return val pivo = alunos[0]
    
    val menores = alunos.filter { it.codigo < pivo.codigo }.toMutableList()
    
    val maiores = alunos.filter { it.codigo > pivo.codigo }.toMutableList()
    
    ordenarAlunos(menores)
    ordenarAlunos(maiores)
    
    alunos.clear()
    
    alunos.addAll(menores)
    alunos.add(pivo)
    alunos.addAll(maiores)
}

fun main() {
    val alunos = mutableListOf(
        Aluno(3, "Ana", "123.456.789-00"),
        Aluno(1, "Melissa", "987.654.321-00"),
        Aluno(2, "João", "111.222.333-44")
    )

    ordenarAlunos(alunos)

    alunos.forEach { println(it) }
}
