require_relative "helper"

def read_pieces_from_file(filetext)
  pieces = []     # max size 26
  piece_index = 0

  filetext.blocks.each do |block_str|
    pieces << create_piece_from_block(block_str, piece_index)
    piece_index += 1
  end

  return pieces
end

def create_piece_from_block(block_str, piece_index)
  piece = {
    letter: letter_from_index(piece_index),
    coordinates: [],
    height: 0,
    width: 0,
  }

  block = block_string_to_array(block_str)

  for i in 0..3
    for j in 0..3
      if block[i][j] == "#"
        piece[:coordinates] << [i,j]
      end
    end
  end

  piece = set_axis_to_zero(piece)
  piece[:height] = calculate_height(piece)
  piece[:width] = calculate_width(piece)

  return piece
end

def letter_from_index(index)
  return ("A".ord + index).chr
end

def calculate_height(piece)
  points = piece[:coordinates].map(&:first)
  (points.max - points.min).abs + 1
end

def calculate_width(piece)
  points = piece[:coordinates].map(&:last)
  (points.max - points.min).abs + 1
end
