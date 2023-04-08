//This is the definition for the class Money.

//Values of this type are amounts of money in U.S. currency.
#include <iostream>
using namespace std;

class Money {
public:
    Money(long dollars, int cents);
    //Initializes the object so its value represents an amount with
    // the dollars and cents given by the arguments. If the amount
    // is negative, then both dollars and cents should be negative.
    Money(long dollars);
    //Initializes the object so its value represents $dollars.00.
    Money( );
    //Initializes the object so its value represents $0.00.
    double get_value( ) const;
    //Returns the amount of money recorded in the data portion of the calling object.
    friend Money operator +(const Money& amount1, const Money& amount2);
    //Returns the sum of the values of amount1 and amount2.
    friend Money operator -(const Money& amount1, const Money& amount2);
    //Returns amount1 minus amount2.
    friend Money operator -(const Money& amount);
    //Returns the negative of the value of amount.
    Money& operator +=(const Money& rhs);
    friend bool operator ==(const Money& amount1, const Money& amount2);
    //Returns true if amount1 and amount2 have the same value; false otherwise.
    friend bool operator <(const Money& amount1, const Money& amount2);
    //Returns true if amount1 is less than amount2; false otherwise.
     friend istream& operator >>(istream& ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type
    // Money. Notation for inputting negative amounts is as in − $100.00.
    // Precondition: If ins is a file input stream, then ins has already been
    // connected to a file.
    friend ostream& operator <<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to output values of type
    // Money. Precedes each output value of type Money with a dollar sign.
    // Precondition: If outs is a file output stream, then outs has already been
    // connected to a file.


private:
    long all_cents;
};

class Check {
public:
    Check(int number, long dollars, int cents, bool is_cashed);
    Check(int number, long dollars, bool is_cashed);
    Check();
    int getCheckNumber() const;
    Money get_amount() const;
    bool get_is_cashed() const;
    void set_number(int number);
    void set_amount(const Money& amount);
    void set_is_cashed(bool is_cashed);
    friend bool operator <(const Check& lhs, const Check& rhs);
    friend istream& operator >>(istream& ins, Check& check);
    friend ostream& operator <<(ostream& outs, const Check& check);
private:
    int number;
    Money amount;
    bool is_cashed;
};


int digit_to_int(char c);
Money get_total_cashed_checks(const Check checks[], int num_of_checks);
Money get_total_uncashed_checks(const Check checks[], int num_of_checks);
Money get_total_deposits(const Money deposits[], int num_of_deposits);
void list_cashed_checks(const Check checks[], int num_of_checks);
void list_uncashed_checks(const Check checks[], int num_of_checks);


int main() {
    int inputCheckCount;

    cout << "||| VIRTUAL CHECKBOOK |||\n"
         << "Balance your account by entering check information.\n"
         << "Begin with the number of checks you will be recording.\n"
         << "Next, for each check, include the check number, check amount, and if it has been cashed or not.\n"
         << "Use the format: $##.## for the check amount.\n"
         << "Enter Y/yes/y) if the check has been cashed; enter N/no/n if it has not been cashed.\n"
         << "E.g. \"1 $1.11 Y\", \"2 $22.22 no\"\n"
         << "Enter the number of your checks: ";
    cin >> inputCheckCount;
    cout << "Enter your checks:\n";

    Check* checks = new Check[inputCheckCount];

    for (int i = 0; i < inputCheckCount; ++i) {
        cin >> checks[i];
    }

    int inputDeposits;

    cout << "Enter your deposits, starting with the number of deposits followed by the amount of each deposit on a separate line.\n"
         << "The amount of a deposit should be in the format: $##.##.\n"
         << "Enter the number of your deposits: ";
    cin >> inputDeposits;
    cout << "Enter your deposits:\n";

    Money* deposits = new Money[inputDeposits];

    for (int i = 0; i < inputDeposits; ++i) {
        cin >> deposits[i];
    }

    Money initialBalance;

    cout << "Input the initial account balance using the format $##.## : ";
    cin >> initialBalance;
    cout << endl;

    Money total_cashed_checks, total_uncashed_checks, total_deposits, calculated_bank_balance, calculated_customer_balance;
    total_cashed_checks = get_total_cashed_checks(checks, inputCheckCount);
    total_uncashed_checks = get_total_uncashed_checks(checks, inputCheckCount);
    total_deposits = get_total_deposits(deposits, inputDeposits);
    calculated_bank_balance = initialBalance - total_cashed_checks + total_deposits;
    calculated_customer_balance = initialBalance - (total_cashed_checks + total_uncashed_checks) + total_deposits;

    cout << "Total cashed checks: " << total_cashed_checks << endl
         << "Total deposits: " << total_deposits << endl
         << "New account balance from bank: " << calculated_bank_balance << endl
         << "New account balance from customer: " << calculated_customer_balance << endl
         << "Account balance discrepancy: " << total_uncashed_checks << "\n\n";

    sort(checks, checks + inputCheckCount);
    list_cashed_checks(checks, inputCheckCount);
    cout << endl;
    list_uncashed_checks(checks, inputCheckCount);

    delete [] checks;
    delete [] deposits;

    return 0;
}



Money::Money(long dollars, int cents) {
    if (dollars * cents < 0) {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}

Money::Money(long dollars) : all_cents(dollars * 100) {}

Money::Money() : all_cents(0) {}

double Money::get_value() const {
    return all_cents * 0.01;
}

Money operator +(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount) {
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

bool operator ==(const Money& amount1, const Money& amount2) {
    return amount1.all_cents == amount2.all_cents;
}

Money & Money::operator+=(const Money& rhs) {
    this->all_cents += rhs.all_cents;

    return *this;
}

istream& operator >>(istream& ins, Money& amount) {
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;
    bool negative;

    ins >> one_char;

    if (one_char == '-') {
        negative = true;
        ins >> one_char; // read '$'
    } else {
        negative = false;
    }

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)) {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;

    if (negative) {
        amount.all_cents = -amount.all_cents;
    }

    return ins;
}

ostream& operator <<(ostream& outs, const Money& amount) {
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0) {
        outs << "-$" << dollars << '.';
    } else {
        outs << '$' << dollars << '.';
    }

    if (cents < 10) {
        outs << '0';
    }

    outs << cents;

    return outs;
}

Check::Check(int number, long dollars, int cents, bool is_cashed) : number(number), amount(Money(dollars, cents)), is_cashed(is_cashed) {}

Check::Check(int number, long dollars, bool is_cashed) : number(number), amount(Money(dollars)), is_cashed(is_cashed) {}

Check::Check() : number(0), amount(Money()), is_cashed(false) {}

int Check::getCheckNumber() const {
    return number;
}

Money Check::get_amount() const {
    return amount;
}

bool Check::get_is_cashed() const {
    return is_cashed;
}

void Check::set_number(int number) {
    this->number = number;
}

void Check::set_amount(const Money& amount) {
    this->amount = amount;
}

void Check::set_is_cashed(bool is_cashed) {
    this->is_cashed = is_cashed;
}

bool operator <(const Check& lhs, const Check& rhs) {
    return lhs.number < rhs.number;
}

istream& operator >>(istream& ins, Check& check) {
    string is_cashed;

    ins >> check.number >> check.amount >> is_cashed;

    if (is_cashed == "y" || is_cashed == "yes" || is_cashed == "Y") {
        check.is_cashed = true;
    } else if (is_cashed == "n" || is_cashed == "no" || is_cashed == "N") {
        check.is_cashed = false;
    } else {
        cout << "Error illegal form for whether or not a check has been cashed\n";
        exit(1);
    }

    return ins;
}

ostream& operator <<(ostream& outs, const Check& check) {
    outs << check.number << ' ' << check.amount << ' ';

    if (check.is_cashed) {
        outs << "Cashed";
    } else {
        outs << "Not cashed";
    }

    return outs;
}

int digit_to_int(char c) {
    return static_cast<int>(c) - static_cast<int>('0');
}

Money get_total_cashed_checks(const Check checks[], int num_of_checks) {
    Money temp;

    for (int i = 0; i < num_of_checks; ++i) {
        if (checks[i].get_is_cashed()) {
            temp += checks[i].get_amount();
        }
    }

    return temp;
}

Money get_total_uncashed_checks(const Check checks[], int num_of_checks) {
    Money temp;

    for (int i = 0; i < num_of_checks; ++i) {
        if (!checks[i].get_is_cashed()) {
            temp += checks[i].get_amount();
        }
    }

    return temp;
}

Money get_total_deposits(const Money deposits[], int num_of_deposits) {
    Money temp;

    for (int i = 0; i < num_of_deposits; ++i) {
        temp += deposits[i];
    }

    return temp;
}

void list_cashed_checks(const Check checks[], int num_of_checks) {
    cout << "List of cashed checks (number amount status):\n";

    for (int i = 0; i < num_of_checks; ++i) {
        if (checks[i].get_is_cashed()) {
            cout << checks[i] << endl;
        }
    }
}

void list_uncashed_checks(const Check checks[], int num_of_checks) {
    cout << "List of uncashed checks (number amount status):\n";

    for (int i = 0; i < num_of_checks; ++i) {
        if (!checks[i].get_is_cashed()) {
            cout << checks[i] << endl;
        }
    }
}