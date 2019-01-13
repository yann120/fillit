require_relative "validation"
require_relative "pieces"
require_relative "helper"
require_relative "fillit"

filepath = ARGV[0]

file_is_valid, filetext = Validator.new(filepath).validate

if file_is_valid
  pieces = read_pieces_from_file(filetext)
  fillit(pieces)
else
  print_error(:usage)
end
