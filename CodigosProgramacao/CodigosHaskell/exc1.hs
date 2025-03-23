main :: IO ()
main = do
    let somaProduto (a, b) (c, d) = (a + c, b * d)
    let resultado = somaProduto (2, 3) (4, 5)
    print resultado
