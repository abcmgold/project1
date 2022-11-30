bool checkBalance(string x, string y) {
    for (int i = 0; i < x.length(); i++) {
        x[i] = tolower(x[i]);
    }
    for (int i = 0; i < y.length(); i++) {
        y[i] = tolower(y[i]);
    }

    if (x == y)
        return true;
    else
        return false;
}
