import java.util.ArrayList;

public class Funcionario {
  private String nome;
  private String cargo;
  private Departamento departamento;

  public Funcionario(String nome, String cargo, Departamento departamento) {
    this.nome = nome;
    this.cargo = cargo;
    this.departamento = departamento;
  }

  public String getNome(){
    return nome;
  }

  public void setNome(String nome){
    this.nome = nome;
  }

  public String getCargo(){
    return cargo;
  }

  public void setMatricula(String matricula){
    this.cargo = cargo;
  }
  

  
  
}