import java.util.Scanner;

public class Main {
  public static void main(String[] args) {

    System.out.println("<<<<< Lista de Alunos >>>>>");
    
    Aluno aluno0 = new Aluno();
    aluno0.nome = "José";
    aluno0.matricula = "12345";
    aluno0.frequencia = "p";
    aluno0.exibirDadosAluno();
    System.out.println("-------------------");

    Aluno aluno1 = new Aluno();
    aluno1.inserirNome("João");
    aluno1.inserirMatricula("201910001");
    aluno1.inserirFrequencia("p");
    aluno1.exibirDadosAluno();
    System.out.println("-------------------");

    Aluno aluno2 = new Aluno();
    aluno2.inserirNome("Maria");
    aluno2.inserirMatricula("201910002");
    aluno2.inserirFrequencia("p");
    aluno2.exibirDadosAluno();
    System.out.println("-------------------");

    Aluno aluno3 = new Aluno();
    aluno3.inserirNome("Pedro");
    aluno3.inserirMatricula("201910003");
    aluno3.inserirFrequencia("f");
    aluno3.exibirDadosAluno();

    System.out.println("-------Via Terminal----------");

    String estadoNovoAluno;

    Scanner scanner = new Scanner(System.in);

    Aluno novoAluno = new Aluno();

    System.out.println("Digite o nome do aluno: ");
    estadoNovoAluno = scanner.nextLine();
    novoAluno.inserirNome(estadoNovoAluno);

    System.out.println("Digite a matricula do aluno: ");
    estadoNovoAluno = scanner.nextLine();
    novoAluno.inserirMatricula(estadoNovoAluno);

    System.out.println("Digite a frequencia do aluno: ");
    estadoNovoAluno = scanner.nextLine();
    novoAluno.inserirFrequencia(estadoNovoAluno);

    novoAluno.exibirDadosAluno();
    scanner.close();

  }

}