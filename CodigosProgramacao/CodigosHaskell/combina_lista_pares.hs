main :: IO()
main = do
    let combListas l1 l2 = zip l1 l2
    print (combListas [1,2,3] ['a', 'b', 'c']) 

{- OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{- HLINT ignore "Eta reduce" #-}