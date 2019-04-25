def plus(poly1, poly2):
    len1 = len(poly1[0])
    len2 = len(poly2[0])
    #result = [['x' for i in range(len1)] for i in range(2)]
    result = [[],[]]
    index = 0
    idx1 = 0
    idx2 = 0
    
    while(True):
        if poly1[1][idx1] == poly2[1][idx2]:
            result[1].append(poly1[1][idx1])
            result[0].append(poly1[0][idx1] + poly2[0][idx2])
            #index += 1
            idx1 += 1
            idx2 += 1

        elif poly1[1][idx1] > poly2[1][idx2]:
            result[1].append(poly2[1][idx1])
            result[0].append(poly1[0][idx1])
            #index += 1
            idx1 += 1
        
        elif poly1[1][idx1] < poly2[1][idx2]:
            result[1].append(poly2[1][idx2])
            result[0].append(poly2[0][idx2])
            #index += 1
            idx2 += 1

        if idx1 == len1 or idx2 == len2:
            break
    
    #for i in range(


    return result



test_data_1 = [[3, 5, 6, 4], [4, 2, 1, 0]]
test_data_2 = [[5, 4, -6, 1], [3, 2, 1, 0]]

print(plus(test_data_1, test_data_2))
