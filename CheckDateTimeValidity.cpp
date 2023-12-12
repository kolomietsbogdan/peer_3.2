class DateTimeValidator {
public:
    static void Validate(const DateTime& dt) {
        ValidateYear(dt.year);
        ValidateMonth(dt.month);
        ValidateDay(dt.day, dt.month, dt.year);
        ValidateHour(dt.hour);
        ValidateMinute(dt.minute);
        ValidateSecond(dt.second);
    }

private:
    static void ValidateYear(int year) {
        if (year < 1) {
            throw std::domain_error("year is too small"s);
        }
        if (year > 9999) {
            throw std::domain_error("year is too big"s);
        }
    }

    static void ValidateMonth(int month) {
        if (month < 1) {
            throw std::domain_error("month is too small"s);
        }
        if (month > 12) {
            throw std::domain_error("month is too big"s);
        }
    }

    static void ValidateDay(int day, int month, int year) {
        const bool is_leap_year = (year % 4 == 0) && !(year % 100 == 0 && year % 400 != 0);
        const std::array<int, 12> month_lengths = { 31, 28 + is_leap_year, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        if (day < 1) {
            throw std::domain_error("day is too small"s);
        }
        if (day > month_lengths[month - 1]) {
            throw std::domain_error("day is too big"s);
        }
    }

    static void ValidateHour(int hour) {
        if (hour < 0) {
            throw std::domain_error("hour is too small"s);
        }
        if (hour > 23) {
            throw std::domain_error("hour is too big"s);
        }
    }

    static void ValidateMinute(int minute) {
        if (minute < 0) {
            throw std::domain_error("minute is too small"s);
        }
        if (minute > 59) {
            throw std::domain_error("minute is too big"s);
        }
    }

    static void ValidateSecond(int second) {
        if (second < 0) {
            throw std::domain_error("second is too small");
        }
        if (second > 59) {
            throw std::domain_error("second is too big"s);
        }
    }
};

void CheckDateTimeValidity(const DateTime& dt) {
    DateTimeValidator::Validate(dt);
}

//Функцию `CheckDateTimeValidity` можно использовать для проверки валидности объекта `DateTime`. Пример:

/*int main() {
    DateTime dt{ 2022, 9, 15, 12, 30, 0 };

    try {
        CheckDateTimeValidity(dt);
        std::cout << "DateTime is valid" << std::endl;
    }
    catch (const std::domain_error& e) {
        std::cout << "DateTime is invalid: " << e.what() << std::endl;
    }

    return 0;
}*/
