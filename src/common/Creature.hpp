#ifndef COMMON_CREATURE_H
#define COMMON_CREATURE_H

#include "MapObject.hpp"
#include <cmath>

namespace common
{

    /**
    * @brief
    * Abstrakcyjna klasa reprezentująca stworzenie
    */
    class Creature: public MapObject
    {
    public:
        /**
        * @brief
        * Konstruktor wywoływany w momencie narodzin stworzenia. Parametry stworzenia są
        * ustalane na podstawie odpowiednich parametrów ojca i matki.
        *
        * Ten konstruktor zakłada, że matka i ojciec znajdują się w tym samym miejscu.
        * Nowe stworzenie również pojawi się w tym samym miejscu.
        *
        * @param mother referencja do matki
        * @param father referencja do ojca
        */
        Creature(const Creature &mother, const Creature &father):
            MapObject(mother),
            radius_(0),
            angle_(0),
            speed_(0),
            fecundity_(0),
            max_repletion_(0),
            max_hydration_(0),
            max_energy_(0),
            max_age_(0)
        {
            /// @todo write me
        }

        /**
        * @brief
        * Konstruktor wywoływany w przypadku, gdy stworzenie jest generowane na początku gry.
        * Wspolrzedne stworzenia są podawane jako parametry konstruktora.
        *
        * Stworzenie pojawi się w wybranym miejscu na planszy (powinno ono byc wolne).
        */
        Creature(double x_pos, double y_pos):
            MapObject(x_pos, y_pos),
            radius_(0),
            angle_(0),
            speed_(0),
            fecundity_(0),
            max_repletion_(0),
            max_hydration_(0),
            max_energy_(0),
            max_age_(0)
        {
            /// @todo write me
        }

        /**
         * @brief
         * Tworzy głęboką kopię obiektu
         *
         * @returns wskaznik do nowego obiektu (utworzonego przez new)
         *
         * @todo moze zmienic na sprytny wskaznik?
         */
        virtual MapObject *clone() = 0;

        /**
        * @brief
        * Funkcja podaje informację czy stworzenie jest martwe.
        *
        * Dzieje się tak, gdy najedzenie, napojenie lub energia spadnie do zera
        * lub gdy stworzenie osiągnie swój maksymalny wiek.
        *
        * Po stwierdzeniu, że stworzenie jest martwe, funkcja wołająca powinna zniszczyć
        * obiekt klasy Creature.
        *
        * @returns true wtedy i tylko wtedy gdy osobnik jest martwy.
        */
        bool isDead() const
        {
            return is_dead_;
        }

        /**
         * @brief
         * Przyjecie (acceptance) wizytatora.
         */
        virtual void accept(Visitor &) = 0;

        /**
        * @brief
        * Serializacja
        *
        * Serializuje skladowe obiektu oraz klase bazowa.
        *
        * @see Map::serialize
        */
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & boost::serialization::base_object<MapObject>(*this);
    //         ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(MapObject);
            ar & radius_;
            ar & angle_;
            ar & speed_;
            ar & fecundity_;
            ar & max_repletion_;
            ar & max_hydration_;
            ar & max_energy_;
            ar & max_age_;
            ar & repletion_;
            ar & hydration_;
            ar & energy_;
            ar & age_;
        }

        struct WrongRotationException: public std::exception{};

        /**
         * @brief
         * Obraca zwierzę o zadany kąt wokół własnej osi.
         *
         * @param degrees Zadany kąt w stopniach. Jeśli degrees > 0, to obrót w prawo; gdy degrees < 0 - obrót w lewo.
         * @pre -360 > #degrees > 360
         * @throws WrongRotationException
         * @see direction_
         */
        void rotateByAngleInDegrees(double degrees)
        {
            if(degrees <= -360 or degrees >= 360)
            {
                throw new WrongRotationException();
            }
            direction_ += degrees;
            // pilnujemy niezmiennika
            direction_ += 360.0;
            // fmod - odpowiednik operator % dla floatów
            direction_ = fmod(direction_, 360.0);
        }

        /**
         * @brief
         * Obraca zwierzę o zadany kąt wokół własnej osi.
         *
         * @param degrees Zadany kąt w radianach. Jeśli radians > 0, to obrót w prawo; gdy radians < 0 - obrót w lewo.
         * @pre -2pi > #degrees > 2pi
         * @throws WrongRotationException
         * @see direction_
         */
        void rotateByAngleInRadians(double radians)
        {
            rotateByAngleInDegrees(radians * 180.0 / M_PI);
        }

        /**
         * @brief
         * Zwraca kierunek patrzenia zwierzęcia w stopniach.
         *
         * @see direction_
         */
        double getDirectionInDegrees()
        {
            return direction_;
        }

        /**
         * @brief
         * Zwraca kierunek patrzenia zwierzęcia w radianach.
         *
         * @see direction_
         */
        double getDirectionInRadians()
        {
            return direction_ * M_PI / 180.0;
        }

        /**
         * @brief
         * Przesuwa zwierzę o zadany dystans w kierunku w którym zwierzę patrzy.
         *
         * @see direction_
         * @todo write me!
         */
        void moveByDistance()
        {

        }

    protected:

        /// Zasięg widzenia
        const int radius_;

        /// Kąt widzenia
        const int angle_;

        /// Prędkość poruszania się
        const int speed_;

        /// Płodność
        const int fecundity_;

        /// Maksymalny poziom najedzenia (inaczej: odporność na głód)
        const int max_repletion_;

        /// Maksymalny poziom napojenia (inaczej: odporność na pragnienie)
        const int max_hydration_;

        /// Maksymalny poziom energii (inaczej: odporność na zmęczenie)
        const int max_energy_;

        /// Maksymalna długość życia
        const int max_age_;

        /**
         * @brief
         * Kierunek, w którym obrócone jest zwierzę, wyrażony w stopniach.
         *
         * Kąt liczony jest zgodnie z kierunkiem ruchu wskazówek zegara.
         * 0 oznacza, że zwierzę jest skierowane (patrzy) w kierunku północnym (w górę ekranu).
         * 90 - w kierunku wschodnim (w prawo)
         * 180 - w kierunku południowym (w dół)
         * 270 - w kierunku zachodnim (w lewo)
         *
         * Wartość tego pola powinna zawsze zawierać się w zakresie <0; 360)
         */
        double direction_;

        /// Obecny poziom najedzenia
        double repletion_;

        /// Obecny poziom napojenia
        double hydration_;

        /// Obecny poziom energii
        double energy_;

        /// Obecny wiek
        double age_;

        /// Czy zwierzę jest martwe?
        bool is_dead_;  
    };
}

BOOST_SERIALIZATION_ASSUME_ABSTRACT(Creature)

#endif
