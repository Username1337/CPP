
if(/* booleanExpression */) {
    // booleanExpression evaluates to true
} else { // can be left out
    // booleanExpression evaluates to false
}

// switch possible with integer values and char
switch (/* expression */) {
    case /* value1 */:
        // code to be executed if value1 is met
        // be aware of fallthrough
    case /* value2 */:
        // code to be executed if value2 is met
        break;
    default: // can be left out
        // code to be executed if no other case is met
        // fallthrough also includes default
}

// do not use gotos
label:
    // do something
    goto label; // jump to a labeled point in the code
