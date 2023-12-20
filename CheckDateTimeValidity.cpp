class DateTimeValidator {
public:
//Определяем шаблонный метод CheckDataRange, который принимает значения data, min, max и error.
//Далее, вызываем этот метод для проверки каждого значения в методе Validate.
//При несоответствии диапазону значений, выбрасывается исключение std::domain_error.
    template<typename T>
    static void CheckDataRange(T data, T min, T max, const std::string& error) {
        if (data < min) {
            throw std::domain_error(error + " is too small");
        }
        if (data > max) {
            throw std::domain_error(error + " is too big");
        }
    }

    static void Validate(const DateTime& dt) {
        CheckDataRange(dt.year, 1, 9999, "year");
        CheckDataRange(dt.month, 1, 12, "month");
        CheckDataRange(dt.day, 1, GetMonthLength(dt.month, dt.year), "day");
        CheckDataRange(dt.hour, 0, 23, "hour");
        CheckDataRange(dt.minute, 0, 59, "minute");
        CheckDataRange(dt.second, 0, 59, "second");
    }

private:
//Метод GetMonthLength используется для получения количества дней в заданном месяце с учетом високосного года.
    static int GetMonthLength(int month, int year) {
        const bool is_leap_year = (year % 4 == 0) && !(year % 100 == 0 && year % 400 != 0);
        const std::array<int, 12> month_lengths = { 31, 28 + is_leap_year, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return month_lengths[month - 1];
    }
};

//Теперь можно использовать метод Validate для проверки валидности объекта DateTime. Пример использования:

int main() {
    DateTime dt{ 2022, 9, 15, 12, 30, 0 };
    try {
        DateTimeValidator::Validate(dt);
        std::cout << "datetime is valid" << std::endl;
    }
    catch (const std::domain_error& e) {
        std::cout << "datetime is invalid: " << e.what() << std::endl;
    }
    return 0;
}
