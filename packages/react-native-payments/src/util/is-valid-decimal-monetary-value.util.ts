import isDecimal from 'validator/es/lib/isDecimal';

import { isNumber, isString } from '../shared';

import type { AmountValue } from '../type/amount-value.type';

const isValidStringAmount = (stringAmount: string): boolean => {
    if (stringAmount.endsWith('.')) {
        return false;
    }

    return isDecimal(stringAmount);
};

export const isValidDecimalMonetaryValue = (amountValue: AmountValue): boolean => {
    if (!isNumber(amountValue) && !isString(amountValue)) {
        return false;
    }

    return isNumber(amountValue) || isValidStringAmount(amountValue);
};
