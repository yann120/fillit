require_relative "validation"
require_relative "helper"

filepath = ARGV[0]

file_is_valid = Validator.new(filepath).validate

if file_is_valid
  pieces = read_pieces_from_file(filepath)
  # fillit
else
  print_error(:usage)
end
