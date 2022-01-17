/**
 * @file   ConjuntoElemento.java
 * @brief  Arquivo dedicado à função main do programa.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2022-01-15
 */

package com.company;

public class ConjuntoElemento<T> extends Conjunto<T> {

    private final T valor;
    private final Conjunto<T> conjunto;

    public ConjuntoElemento(T valor, Conjunto<T> conjunto) {
        this.valor = valor;
        this.conjunto = conjunto;
    }

    @Override
    public Boolean contemElemento(T elemento) {
        return elemento == valor || conjunto.contemElemento(elemento);
    }

}
