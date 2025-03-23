public class Aluno {
  String nome;
  String matricula;
  String frequencia;

  public void inserirNome(String nomeDoAluno) {
    nome = nomeDoAluno;
  }

  public void inserirMatricula(String matriculaDoAluno) {
    matricula = matriculaDoAluno;
  }

  public void inserirFrequencia(String frequenciaDoAluno) {
    frequencia = frequenciaDoAluno;
  }

  public void exibirNome() {
    System.out.println(nome);
  }

  public void exibirMatricula() {
    System.out.println(matricula);
  }

  public void exibirFrequencia() {
    System.out.println(frequencia);
  }

  public void exibirDadosAluno() {
    System.out.println("Nome: " + nome);
    System.out.println("Matricula: " + matricula);
    System.out.println("Frequencia: " + frequencia);
  }

}