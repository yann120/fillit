make re
clear

echo "\nTEST - EMPTY FILE"
./fillit test_files/empty
./fillit test_files/empty
./fillit test_files/empty
./fillit test_files/empty
./fillit test_files/empty
./fillit test_files/empty
./fillit test_files/empty
./fillit test_files/empty
./fillit test_files/empty
./fillit test_files/empty
./fillit test_files/empty
./fillit test_files/empty
./fillit test_files/empty
valgrind --log-fd=1 ./fillit test_files/empty | grep -E "definitely lost:|Invalid read|Conditional jump"

echo "\nTEST - VALID PIECES 1"
./fillit test_files/valid_pieces_1
./fillit test_files/valid_pieces_1
./fillit test_files/valid_pieces_1
./fillit test_files/valid_pieces_1
./fillit test_files/valid_pieces_1
./fillit test_files/valid_pieces_1
./fillit test_files/valid_pieces_1
./fillit test_files/valid_pieces_1
./fillit test_files/valid_pieces_1
./fillit test_files/valid_pieces_1
./fillit test_files/valid_pieces_1
./fillit test_files/valid_pieces_1
./fillit test_files/valid_pieces_1
valgrind --log-fd=1 ./fillit test_files/valid_pieces_1 | grep -E "definitely lost:|Invalid read|Conditional jump"

echo "\nTEST - VALID PIECES 4"
./fillit test_files/valid_pieces_4
./fillit test_files/valid_pieces_4
./fillit test_files/valid_pieces_4
./fillit test_files/valid_pieces_4
./fillit test_files/valid_pieces_4
./fillit test_files/valid_pieces_4
./fillit test_files/valid_pieces_4
./fillit test_files/valid_pieces_4
./fillit test_files/valid_pieces_4
./fillit test_files/valid_pieces_4
./fillit test_files/valid_pieces_4
./fillit test_files/valid_pieces_4
valgrind --log-fd=1 ./fillit test_files/valid_pieces_4 | grep -E "definitely lost:|Invalid read|Conditional jump"

echo "\nTEST - VALID PIECES 8"
./fillit test_files/valid_pieces_8
./fillit test_files/valid_pieces_8
./fillit test_files/valid_pieces_8
./fillit test_files/valid_pieces_8
./fillit test_files/valid_pieces_8
./fillit test_files/valid_pieces_8
./fillit test_files/valid_pieces_8
./fillit test_files/valid_pieces_8
./fillit test_files/valid_pieces_8
./fillit test_files/valid_pieces_8
./fillit test_files/valid_pieces_8
./fillit test_files/valid_pieces_8
./fillit test_files/valid_pieces_8
./fillit test_files/valid_pieces_8
valgrind --log-fd=1 ./fillit test_files/valid_pieces_8 | grep -E "definitely lost:|Invalid read|Conditional jump"

# echo "\nTEST - VALID PIECES 19"
# ./fillit test_files/valid_pieces_19
# valgrind --log-fd=1 ./fillit test_files/valid_pieces_19 | grep -E "definitely lost:|Invalid read|Conditional jump"

# echo "\nTEST - VALID PIECES 25"
# ./fillit test_files/valid_pieces_25
# valgrind --log-fd=1 ./fillit test_files/valid_pieces_25 | grep -E "definitely lost:|Invalid read|Conditional jump"

echo "\nTEST - VALID PIECES 26"
./fillit test_files/valid_pieces_26
./fillit test_files/valid_pieces_26
./fillit test_files/valid_pieces_26
./fillit test_files/valid_pieces_26
./fillit test_files/valid_pieces_26
./fillit test_files/valid_pieces_26
./fillit test_files/valid_pieces_26
./fillit test_files/valid_pieces_26
./fillit test_files/valid_pieces_26
./fillit test_files/valid_pieces_26
./fillit test_files/valid_pieces_26
./fillit test_files/valid_pieces_26
./fillit test_files/valid_pieces_26
./fillit test_files/valid_pieces_26
./fillit test_files/valid_pieces_26
./fillit test_files/valid_pieces_26
./fillit test_files/valid_pieces_26
./fillit test_files/valid_pieces_26
valgrind --log-fd=1 ./fillit test_files/valid_pieces_26 | grep -E "definitely lost:|Invalid read|Conditional jump"

echo "\nTEST - VALID PIECES 26 AND 1 LINE"
./fillit test_files/valid_pieces_26_1_line
./fillit test_files/valid_pieces_26_1_line
./fillit test_files/valid_pieces_26_1_line
./fillit test_files/valid_pieces_26_1_line
./fillit test_files/valid_pieces_26_1_line
./fillit test_files/valid_pieces_26_1_line
./fillit test_files/valid_pieces_26_1_line
./fillit test_files/valid_pieces_26_1_line
./fillit test_files/valid_pieces_26_1_line
./fillit test_files/valid_pieces_26_1_line
./fillit test_files/valid_pieces_26_1_line
./fillit test_files/valid_pieces_26_1_line
./fillit test_files/valid_pieces_26_1_line
./fillit test_files/valid_pieces_26_1_line
./fillit test_files/valid_pieces_26_1_line
./fillit test_files/valid_pieces_26_1_line
./fillit test_files/valid_pieces_26_1_line
./fillit test_files/valid_pieces_26_1_line
valgrind --log-fd=1 ./fillit test_files/valid_pieces_26_1_line | grep -E "definitely lost:|Invalid read|Conditional jump"

echo "\nTEST - INVALID SHAPE"
./fillit test_files/invalid_shape
./fillit test_files/invalid_shape
./fillit test_files/invalid_shape
./fillit test_files/invalid_shape
./fillit test_files/invalid_shape
./fillit test_files/invalid_shape
./fillit test_files/invalid_shape
./fillit test_files/invalid_shape
./fillit test_files/invalid_shape
./fillit test_files/invalid_shape
./fillit test_files/invalid_shape
./fillit test_files/invalid_shape
./fillit test_files/invalid_shape
./fillit test_files/invalid_shape
./fillit test_files/invalid_shape
./fillit test_files/invalid_shape
./fillit test_files/invalid_shape
valgrind --log-fd=1 ./fillit test_files/invalid_shape | grep -E "definitely lost:|Invalid read|Conditional jump"

echo "\nTEST - 27 PIECES"
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
./fillit test_files/27_pieces
valgrind --log-fd=1 ./fillit test_files/27_pieces | grep -E "definitely lost:|Invalid read|Conditional jump"

echo "\nTEST - 30 PIECES"
./fillit test_files/30_pieces
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
./fillit test_files/30_pieces | grep -v error
valgrind --log-fd=1 ./fillit test_files/30_pieces | grep -E "definitely lost:|Invalid read|Conditional jump"
