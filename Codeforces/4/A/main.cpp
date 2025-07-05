main = do
    line <- getLine
    let n = (read line :: Int)
    putStrLn (if ( mod n 2 == 0 && n > 2)
        then "YES"
        else "NO")
    
