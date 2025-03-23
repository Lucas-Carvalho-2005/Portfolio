import javax.swing.JOptionPane;

public class Main 
{

  public static void main(String[] args) 
  {

    Pessoa[] nomes = new Pessoa[10];
    int numAlunos = 10;

    for (int i = 0; i < numAlunos; i++)
    {
      String nome = JOptionPane.showInputDialog("Digite um nome: ");
      nomes[i] = new Pessoa(nome);
    }

    int numSorteado = (int) (Math.random() * 10);
    String nomeSorteado = nomes[numSorteado].getNome();

    JOptionPane.showMessageDialog(null, "\nO nome sorteado foi: " + nomeSorteado);


    System.out.println(numSorteado);
    for (int i = 0; i < nomes.length; i++) {
      System.out.println(nomes[i].getNome());
    }

  }

}

// fssilva@uea.edu.br -> convidar professor