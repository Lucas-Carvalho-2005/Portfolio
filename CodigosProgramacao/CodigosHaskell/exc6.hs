insertionSort :: [Int] -> [Int]
insertionSort [] = []
insertionSort (x:xs) = insere x (insertionSort xs)
  where
    insere y [] = [y]
    insere y (z:zs) = if y <= z then y:z:zs else z : insere y zs

main :: IO ()
main = do
    print (insertionSort [5, 3, 2, 4])