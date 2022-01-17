/**
 * @file   Complemento.java
 * @brief  Arquivo dedicado à função main do programa.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2022-01-15
 */

package com.company;

public class Complemento<T> extends Conjunto<T> {

    private final Conjunto<T> conjunto;

    public Complemento(Conjunto<T> conjunto) {
        this.conjunto = conjunto;
    }

    @Override
    public Boolean contemElemento(T elemento) {
        return (!(conjunto.contemElemento(elemento)));
    }

}
