#include <iostream>
#include <map>
#include <string>
#include <vector>

class TicTacToe
{
public:
    TicTacToe(){ ResetGame_(); }
    ~TicTacToe() = default;

    void Play()
    {
        Draw_();
    }

private:
    void Draw_()
    {
        constexpr int number_of_rows = 3;
        constexpr int number_of_columns = 18;
        constexpr int block_of_columns = number_of_columns / 3;

        auto print_line = [&](char c = ' ')
        {
            for (size_t i = 0; i < number_of_columns; ++i)
                std::cout << ((i % block_of_columns != 0 || i == 0)? c: '|');
            std::cout << std::endl;
        };

        //Header
        std::cout << std::string(block_of_columns / 2, ' ') << 'a';
        std::cout << std::string(block_of_columns - 1, ' ') << 'b';
        std::cout << std::string(block_of_columns - 1, ' ') << 'c';
        std::cout << std::endl;

        //Board
        for(size_t row = 0; row < number_of_rows; ++row)
        {
            print_line();
            char letter = 'a';
            for (size_t column = 0; column < number_of_columns; ++ column)
            {
                // Insert the line number
                if (column == 0)
                {
                    std::cout << row + 1;
                    continue;
                }

                if (column % block_of_columns != 0 )
                {
                    if (column % (block_of_columns/2) == 0 ||
                        column % (block_of_columns/2 + block_of_columns) == 0 ||
                        column % (block_of_columns/2 + 2*block_of_columns) == 0)
                    {
                        std::cout << moves_[std::to_string(row + 1) + letter++];
                    }
                    else
                        std::cout << ' ';
                }
                else
                    std::cout << '|';
            }
            std::cout << std::endl;

            if (row != number_of_rows - 1) { print_line('_');}
            else { print_line(); }
        }
    }
    void ResetGame_()
    {
        moves_left_.reserve(9);
        moves_left_ = { "1a", "1b", "1c",
                        "2a", "2b", "2c",
                        "3a", "3b", "3c" };
        for(const auto& move : moves_left_)
            moves_[move] = '-';
    }

private:
    std::map<std::string, char> moves_;
    std::vector<std::string> moves_left_;
};

int main()
{
    TicTacToe ttt;
    ttt.Play();

    return 0;
}
