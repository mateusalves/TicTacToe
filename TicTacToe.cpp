#include <iostream>
#include <map>
#include <vector>

class TicTacToe
{
public:
    TicTacToe()
    {
        Reset();
    }
    ~TicTacToe() = default;

    void Play()
    {
        Draw_();
    }

    void Reset()
    {
        moves_left_.reserve(9);
        moves_left_ = {"1a", "1b", "1c",
                       "2a", "2b", "2c",
                       "3a", "3b", "3c"};

        for (const auto& move: moves_left_)
            moves_done_[move] = '-';
    }


    private:
        void Draw_()
        {
            const int number_of_rows = 3;
            const int number_of_columns = 18;
            constexpr int block_column_size = number_of_columns / 3;

        auto print_line = []( char c = ' ')
        {
            for (size_t i = 0; i < number_of_columns; ++i)
                std::cout << (( i % block_column_size != 0 || i == 0) ? c : '|');
            std::cout << std::endl;
        };

        std::cout << std::string(block_column_size / 2, ' ') << 'a';
        std::cout << std::string(block_column_size - 1, ' ') << 'b';
        std::cout << std::string(block_column_size - 1, ' ') << 'c';
        std::cout << std::endl;

        for (size_t row = 0; row < number_of_rows; ++row)
        {
            print_line();
            char letter = 'a';
            for (size_t column = 0; column < number_of_columns; ++column)
            {
                if (column == 0)
                {
                    std::cout << row + 1;
                }
                else if (column % block_column_size != 0)
                {
                    if (column == block_column_size / 2 ||
                        column == block_column_size + block_column_size / 2 ||
                        column == 2 * block_column_size + block_column_size / 2)
                    {
                        std::cout << moves_done_[std::to_string(row + 1) + letter++];
                    }
                    else
                        std::cout << ' ';
                }
                else
                {
                    std::cout << '|';
                }
            }
            std::cout << std::endl;
            if (row != number_of_rows - 1) { print_line('_'); }
            else { print_line(); }
        }
    }

private:
    std::map<std::string, char> moves_done_;
    std::vector<std::string> moves_left_;
};

int main()
{
    TicTacToe ttt;
    ttt.Play();
    return 0;
}
