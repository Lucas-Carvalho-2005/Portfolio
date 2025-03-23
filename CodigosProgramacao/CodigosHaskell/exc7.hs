import Data.List (delete)

selectionSort :: [Int] -> [Int]
selectionSort [] = []
selectionSort xs = let m = minimum xs in m : selectionSort (delete m xs)

main :: IO ()
main = do
    print (selectionSort [5, 3, 2, 4])