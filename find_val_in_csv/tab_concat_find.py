import csv

# csv_filename = 'data.csv'
# search_column = 'Column1'
# search_value = 'ValueToSearch'
# target_columns = ['Column2', 'Column3']
def find_value_and_get_other_values(csv_filename, search_column_index, search_value, target_column_indices):
    result = []

    with open(csv_filename, 'r', newline='') as csv_file:
        reader = csv.reader(csv_file)
        
        # Find the index of the columns to retrieve
        header_row = next(reader)
        target_column_indices = [header_row.index(idx) for idx in target_column_indices]
        
        # Find the index of the column to search in
        search_column_index = header_row.index(search_column_index)
        
        for row in reader:
            if row[search_column_index] == search_value:
                other_values = [row[idx] for idx in target_column_indices]
                result.append(other_values)

    return result

def combine_list_value(input_list):
    result = []
    for iter_row in input_list:
        if not result:
            result = list(iter_row)
        else:
            result = [item1 +
                      item2 for item1, item2 in zip(result, iter_row)]
    return result



# Open the input CSV file
input_filename1 = 'in1.csv'
input_filename2 = 'in2.csv'
output_filename = 'out.csv'

search_column = 'abc'
target_columns = ['res1', 'res2']

with open(input_filename1, 'r', newline='') as input_file1,\
    open(output_filename, 'w', newline='') as output_file:
    reader1 = csv.reader(input_file1)
    writer = csv.writer(output_file)
    header_row = next(reader1)
    new_header_row = header_row + target_columns
    writer.writerow(new_header_row)
    
    for row in reader1:
        # Assuming columns 0, 1, and 2 are to be concatenated
        concatenated_value = row[0] + row[1] + row[2]
        results = find_value_and_get_other_values(input_filename2, search_column, concatenated_value, target_columns)
        combined_res = combine_list_value(results)
        new_row = row + combined_res
        print(f"concatenated: {concatenated_value} results: {results}")
        print(f"new_row: {new_row}")
        writer.writerow(new_row)
