main :: IO()
main = do
    let x = 0.5 :: Float
    let valor_acos = acos x
    putStr $ "Arco cosseno de " ++ show x ++ " = " ++ show valor_acos
    putStr " rad"