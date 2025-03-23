import java.util.ArrayList;

public class Departamento {
  private String nome;
  private String sigla;
  private ArrayList<Funcionario> funcionarios;


  public Departamento(String nome, String sigla) {
    this.nome = nome;
    this.sigla = sigla;
    this.funcionarios = new ArrayList<Funcionario>();
  }

  public ArrayList<Funcionario> getFuncionarios() {
    return funcionarios;
  }

  public String getNome() {
    return nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getSigla() {
    return sigla;
  }

  public void setSigla(String sigla) {
    this.sigla = sigla;
  }

  public void addFuncionario(Funcionario funcionario) {
    this.funcionarios.add(funcionario); // método add vindo do ArrayList importado
  }

  public void listarFuncionarios() {
    for (Funcionario funcionario : this.funcionarios) {
      System.out.println(funcionario.getNome());
    }
  }

  public void removeFuncionario(Funcionario funcionario) {
    this.funcionarios.remove(funcionario); // método remove vindo do ArrayList importado
  }
  
}