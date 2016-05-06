#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "mystrings.h"

boolean IsInteger(String TheCString) {

    boolean NoBadDigits = TRUE;
    int StringIndex,StringLength;

    StringIndex = 0;
    StringLength = strlen(TheCString);
    
    while (NoBadDigits && (StringIndex < StringLength)) {
        if (! isdigit(TheCString[StringIndex])) {
            NoBadDigits = FALSE;
        } else {
            ++StringIndex;
        }
    }
    
    return(NoBadDigits);
}

int ToInteger(String TheCString) {

    return(atoi(TheCString));
}

boolean ReadString(String TheCString) {

    return(scanf("%s",TheCString) != EOF);
}

boolean Concatenate(String TheCString,String AnotherString) {

    if (strlen(TheCString) + strlen(AnotherString) < MAX_STRING_SIZE) {
        strcat(TheCString,AnotherString);
        return(TRUE);
    } else {
        return(FALSE);
    }
}

boolean StringGreater(String TheCString,String ASmallerString) {

    return(strcmp(TheCString,ASmallerString) > 0);
}

boolean StringEqual(String TheCString,String AnotherString) {

    return(strcmp(TheCString,AnotherString) == 0);
}

boolean StringSmaller(String TheCString,String ALargerString) {

    return(strcmp(TheCString,ALargerString) < 0);
}
