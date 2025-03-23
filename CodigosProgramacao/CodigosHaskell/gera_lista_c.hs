main :: IO ()
main = do
    let d = [x | x <- [2..5], all (x >=) [2, 3, 4, 5]]
    putStr $ "D = " ++ show d