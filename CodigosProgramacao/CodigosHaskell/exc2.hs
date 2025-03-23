main :: IO ()
main = do
    let maiorESegundo a b c = (maximum lista, maximum (filter (/= maximum lista) lista))
            where lista = [a, b, c]
    let resultado = maiorESegundo 5 7 3
    print resultado
