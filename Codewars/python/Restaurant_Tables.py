def restaurant(single_tables, double_tables, visitors) -> int:
    remain_single_table, remain_double_table, remain_double_table_person, deny = single_tables * 1, double_tables, double_tables * 2, 0
    for v in visitors:
        if v == 1:
            if remain_single_table != 0:
                remain_single_table -= 1
            elif remain_double_table >= 1:
                remain_double_table -= 1
                remain_double_table_person -= 1
            elif remain_double_table_person >= 1:
                remain_double_table_person -= 1
            else:
                deny += 1
        else:
            if remain_double_table >= 1:
                remain_double_table -= 1
                remain_double_table_person -= 2
            else:
                deny += 2

    return deny


print(restaurant(1, 2, [1, 2, 1, 1]))
print(restaurant(2, 1, [2, 1, 2, 2, 2, 2, 1, 2, 1, 2]))
