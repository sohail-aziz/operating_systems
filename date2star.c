#include <stdio.h>

int main() {
    int day, month;
    printf("Enter your date of birth (dd-mm): ");
    scanf("%d-%d", &day, &month); // 

    switch (month) {
        case 1:  // January
            printf("Your Zodiac sign is %s.\n", (day < 20) ? "Capricorn" : "Aquarius");
            break;
        case 2:  // February
            printf("Your Zodiac sign is %s.\n", (day < 19) ? "Aquarius" : "Pisces");
            break;
        case 3:  // March
            printf("Your Zodiac sign is %s.\n", (day < 21) ? "Pisces" : "Aries");
            break;
        case 4:  // April
            printf("Your Zodiac sign is %s.\n", (day < 20) ? "Aries" : "Taurus");
            break;
        case 5:  // May
            printf("Your Zodiac sign is %s.\n", (day < 21) ? "Taurus" : "Gemini");
            break;
        case 6:  // June
            printf("Your Zodiac sign is %s.\n", (day < 21) ? "Gemini" : "Cancer");
            break;
        case 7:  // July
            printf("Your Zodiac sign is %s.\n", (day < 23) ? "Cancer" : "Leo");
            break;
        case 8:  // August
            printf("Your Zodiac sign is %s.\n", (day < 23) ? "Leo" : "Virgo");
            break;
        case 9:  // September
            printf("Your Zodiac sign is %s.\n", (day < 23) ? "Virgo" : "Libra");
            break;
        case 10: // October
            printf("Your Zodiac sign is %s.\n", (day < 23) ? "Libra" : "Scorpio");
            break;
        case 11: // November
            printf("Your Zodiac sign is %s.\n", (day < 22) ? "Scorpio" : "Sagittarius");
            break;
        case 12: // December
            printf("Your Zodiac sign is %s.\n", (day < 22) ? "Sagittarius" : "Capricorn");
            break;
        default:
            printf("Invalid date.\n");
    }

    return 0;
}
