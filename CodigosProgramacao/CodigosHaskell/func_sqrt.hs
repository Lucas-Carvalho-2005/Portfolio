main :: IO()
main = do
    let x = 16
    let valor_sqrt = sqrt x
    putStrLn $ "Raiz quadrada de " ++ show (round x) ++ 
                    " = " ++ show (round valor_sqrt)