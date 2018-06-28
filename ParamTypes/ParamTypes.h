#pragma once

/**
 * @brief La clase ParamTypes ilustra el uso de las plantillas para
 * procesamiento de datos de un tipo de dato (T) que es especificado
 * en otro lugar del código.
 *
 * Las plantillas son la base de c++ moderno, por ejemplo, los
 * punteros inteligentes.
 */

template <typename T>
class ParamTypes
{
public:
    /**
     * @brief GetMinimumValue
     * @param lhs un valor tipo T constante debido a que será comparado, no modificado
     * @param rhs un valor tipo T constante debido a que será comparado, no modificado
     * @return
     */
    T GetMinimumValue(const T& lhs, const T& rhs) const;
};
