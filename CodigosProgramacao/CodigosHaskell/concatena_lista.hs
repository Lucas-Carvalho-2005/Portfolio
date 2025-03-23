main :: IO()
main = do
    let concatListas l1 l2 = l1 ++ l2
    print (concatListas [2,3,4,5] [6,7]) 

{- OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{- HLINT ignore "Eta reduce" #-}