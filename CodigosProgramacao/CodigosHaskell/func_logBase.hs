main :: IO()
main = do
    let base = 10 :: Float
    let x = 1000 :: Float
    let valor_logBase = logBase base x
    putStrLn $ "Logaritmo na base " ++ show (round base) ++ 
               " de " ++ show (round x) ++ 
               " = " ++ show (round valor_logBase)
