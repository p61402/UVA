def find_compliant():
    for key, value in proposal_item_dict.items():
        if len(value) == number_of_requirement:
            return key

    compliance_dict = {}
    highest_compliance = 0
    for key, value in proposal_item_dict.items():
        compliance_dict[key] = len(value) / number_of_requirement
        highest_compliance = max(highest_compliance, compliance_dict[key])

    candidate_list = []
    for key, value in compliance_dict.items():
        if value == highest_compliance:
            candidate_list.append(key)

    if len(candidate_list) == 1:
        return candidate_list[0]

    lowest_price = proposal_price_dict[candidate_list[0]]
    for candidate in candidate_list:
        lowest_price = min(lowest_price, proposal_price_dict[candidate])

    new_candidate_list = []
    for candidate in candidate_list:
        if proposal_price_dict[candidate] == lowest_price:
            new_candidate_list.append(candidate)

    return new_candidate_list[0]


if __name__ == "__main__":
    turn = 0
    while True:
        number_of_requirement, number_of_proposal = input().split()

        number_of_requirement = int(number_of_requirement)
        number_of_proposal = int(number_of_proposal)

        if number_of_requirement == 0 and number_of_proposal == 0:
            break

        requirement_list = []
        for i in range(number_of_requirement):
            requirement_list.append(input())

        proposal_item_dict = {}
        proposal_price_dict = {}
        for j in range(number_of_proposal):
            proposal_name = input()
            price, numOfItem = input().split()

            proposal_price_dict[proposal_name] = float(price)

            proposal_list = []
            for k in range(int(numOfItem)):
                proposal_list.append(input())

            proposal_item_dict[proposal_name] = proposal_list

        turn += 1
        if turn >= 2:
            print()
        print("RFP #{0}".format(turn))
        print(find_compliant())
