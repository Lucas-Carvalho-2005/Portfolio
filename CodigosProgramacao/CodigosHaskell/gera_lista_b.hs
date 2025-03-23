main :: IO ()
main = do
    let c = [x | x <- [0..], all (x <=) [0 .. x]]
    putStr $ "C = " ++ show (take 1 c)