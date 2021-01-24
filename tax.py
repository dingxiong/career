

def get_tax_bucket(income, tax_from, tax_to, rate):
    if income < tax_from:
        return 0
    else:
        return (min(income, tax_to) - tax_from)  * rate

def get_tax(income, mode = 'single'):
    if mode == 'single':
        buckets = [
            # tax_to, rate
            [9875, 0.1],
            [40125, 0.12],
            [85525, 0.22],
            [163300, 0.24],
            [207350, 0.35],
            [1e10, 0.37],
        ]
    elif mode == 'family_joint':
        buckets = [
            # tax_to, rate
            [19750, 0.1],
            [80250, 0.12],
            [171050, 0.22],
            [326600, 0.24],
            [414700, 0.32],
            [622050, 0.35],
            [1e10, 0.37],
        ]
    
    tax = 0.0
    for i in range(len(buckets)):
        tax_to, rate = buckets[i]
        tax_from = buckets[i-1][0] + 1 if i > 0 else 0
        tax += get_tax_bucket(income, tax_from, tax_to, rate)

    return tax, tax / income
