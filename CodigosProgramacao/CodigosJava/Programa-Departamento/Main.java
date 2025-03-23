public class Main {
  public static void main(String[] args) {

    Departamento departamento = new Departamento("Departamento de TI", "TI");

    Funcionario funcionario1 = new Funcionario("João", "Desenvolvedor", departamento);
    Funcionario funcionario2 = new Funcionario("Maria", "Analista", departamento);
    Funcionario funcionario3 = new Funcionario("Pedro", "Gerente", departamento);

    departamento.addFuncionario(funcionario1);
    departamento.addFuncionario(funcionario2);
    departamento.addFuncionario(funcionario3);

    departamento.listarFuncionarios();
    departamento.removeFuncionario(funcionario2);
    System.out.println("\n");
    departamento.listarFuncionarios();
    
  }
}