from flask import Flask, render_template, request, redirect, url_for, flash
import sqlite3
import webbrowser
import threading

app = Flask(__name__)
app.secret_key = "supersecretkey"  # Necessário para exibir mensagens flash

# Função para conectar ao banco de dados
def connect_db():
    return sqlite3.connect('produtos.db')

@app.route('/')
def menu():
    return render_template('menu.html')

@app.route('/cadastrarTipoProduto', methods=['GET', 'POST'])
def cadastrar_tipo():
    if request.method == 'POST':
        nome = request.form['nome']
        conn = connect_db()
        cursor = conn.cursor()
        cursor.execute("INSERT INTO TIPO_PRODUTO (nome) VALUES (?)", (nome,))
        conn.commit()
        conn.close()
        return {"status": "success", "message": "Tipo de produto cadastrado com sucesso!"}, 200
        
    return render_template('cadastrar_tipo.html')

@app.route('/cadastrarProduto', methods=['GET', 'POST'])
def cadastrar_produto():
    conn = connect_db()
    cursor = conn.cursor()
    cursor.execute("SELECT idTipoProduto, nome FROM TIPO_PRODUTO")
    tipos = cursor.fetchall()
    conn.close()

    if request.method == 'POST':
        idTipoProduto = request.form['idTipoProduto']
        nome = request.form['nome']
        descricao = request.form['descricao']
        conn = connect_db()
        cursor = conn.cursor()
        cursor.execute(
            "INSERT INTO PRODUTO (idTipoProduto, nome, descricao, dataCadastro) VALUES (?, ?, ?, datetime('now'))",
            (idTipoProduto, nome, descricao)
        )
        conn.commit()
        conn.close()
        return {"status": "success", "message": "Produto cadastrado com sucesso!"}, 200

    return render_template('cadastrar_produto.html', tipos=tipos)

@app.route('/listarProdutos')
def listar_produtos():
    conn = connect_db()
    cursor = conn.cursor()
    cursor.execute("""
        SELECT p.idProduto, p.nome, p.descricao, p.dataCadastro, t.nome 
        FROM PRODUTO p 
        JOIN TIPO_PRODUTO t ON p.idTipoProduto = t.idTipoProduto
    """)
    produtos = cursor.fetchall()
    conn.close()
    return render_template('listar_produtos.html', produtos=produtos)

@app.route('/excluirProduto/<int:idProduto>')
def excluir_produto(idProduto):
    conn = connect_db()
    cursor = conn.cursor()
    cursor.execute("DELETE FROM PRODUTO WHERE idProduto = ?", (idProduto,))
    conn.commit()
    conn.close()
    flash("Produto excluído com sucesso!", "success")
    return redirect(url_for('listar_produtos'))

@app.route('/listarTipos')
def listar_tipos():
    conn = connect_db()
    cursor = conn.cursor()
    cursor.execute("SELECT idTipoProduto, nome FROM TIPO_PRODUTO")
    tipos = cursor.fetchall()
    conn.close()
    return render_template('listar_tipos.html', tipos=tipos)

@app.route('/excluirTipo/<int:idTipoProduto>')
def excluir_tipo(idTipoProduto):
    conn = connect_db()
    cursor = conn.cursor()
    # Verificar se há produtos associados ao tipo
    cursor.execute("SELECT COUNT(*) FROM PRODUTO WHERE idTipoProduto = ?", (idTipoProduto,))
    count = cursor.fetchone()[0]
    if count > 0:
        flash("Não é possível excluir este tipo de produto, pois existem produtos associados a ele.", "danger")
    else:
        cursor.execute("DELETE FROM TIPO_PRODUTO WHERE idTipoProduto = ?", (idTipoProduto,))
        conn.commit()
        flash("Tipo de produto excluído com sucesso!", "success")
    conn.close()
    return redirect(url_for('listar_tipos'))

if __name__ == '__main__':
    threading.Timer(1.5, lambda: webbrowser.open('http://127.0.0.1:5000')).start()
    app.run(debug=True, use_reloader=False)