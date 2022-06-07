#include <iostream>
#include <vector>

using namespace std;

class Card
{
public:
    enum suit {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };
    enum value {
        ACE = 1,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING
    };

    void setValue(value _value, suit _suit)
    {
        v = _value;
        s = _suit;
    }

    Card(value _value = ACE, suit _suit = SPADES, bool _cardPosition = true) : v(_value), s(_suit), cardPosition(_cardPosition) {}
    void Flip() 
    {
        if (!cardPosition)
            cardPosition = true;
        else cardPosition = false;
    }
    value getValue()
    {
        if (cardPosition)
        {
            return v;
        }
    }

    friend ostream& operator<<(ostream& str, Card& cards)
    {
        const string RANKS[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
        const string SUITS[] = { "c", "d", "h", "s" };
        if (cards.cardPosition)
            str << "XX";
        else
            str << RANKS[cards.v - 1] << " " << SUITS[cards.s];

        return str;
    }
protected:
    value v;
    suit s;
    bool cardPosition;
};

class Hand
{
public:

    void Add(Card* aCard)
    {
        cards.push_back(aCard);
    }
    void Clear()
    {
        for (auto i : cards)
            delete i;
    }
    int getAmount() const
    {
        if (cards.empty())
            return 0;
        int test = 0;
        for (auto crds : cards)
            test += crds->getValue();
        bool tests = false;
        for (auto crds : cards)
            if (crds->getValue() == crds->ACE) tests = true;
        if (tests && test <= 11)
            test += 10;
        return test;
    }
protected:
    vector<Card*> cards;
};

class GenericPlayer : public Hand
{
public:
    GenericPlayer(string _name = "") {}
    ~GenericPlayer() {}

    virtual bool IsHitting() const = 0 {}

    bool IsBoosted(int _getAmount) 
    {
            if(_getAmount > 21);
            {
                return true;
                Bust();
            }
    }

    void Bust() 
    {
            cout << "У игрока " << name << " перебор" << endl;
    }
protected:
    string name;
};

class Player : public GenericPlayer
{
public:
    virtual bool IsHitting(int _getAmount) const 
    {
        cout << name << " нужна ещё карта?" << endl;
        char answer;
        cin >> answer;
        return (answer == 'y');
    }

    void Win() const 
    {
        cout << name << " Победа" << endl;
    }

    void Lose() const 
    {
        cout << name << " Поражение" << endl;
    }

    void Push() const 
    {
        cout << name << " Ничья" << endl;
    }
};

class House : public GenericPlayer
{
public:
    House(int _gA) { IsHitting(_gA); }
    virtual bool IsHitting(int _getAmount) const
    {
        return (_getAmount <= 16);
    }

    void FlipFirstCard() 
    {
        if (!cards.empty())
        {
            cards[0]->Flip();
        }
        else cout << "Нечего перевернуть" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    Card* C = new Card;
    Card S;
    C->setValue(C->NINE, C->DIAMONDS);
    //cout << C->getValue();
    S.Flip();
    cout << S << endl;
    Hand H;
    Hand* Hs = new Hand();
    H.Add(C);
    cout << H.getAmount() << endl;
    H.Add(C);
    H.Add(C);
    H.Add(C);
    //C->setValue(C->KING, C->DIAMONDS);
    //H.Clear();
    cout << H.getAmount();
}
