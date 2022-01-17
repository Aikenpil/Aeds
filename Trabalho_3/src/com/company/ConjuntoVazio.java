/**
 * @file   ConjuntoVazio.java
 * @brief  Arquivo dedicado à função main do programa.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2022-01-15
 */

package com.company;

public class ConjuntoVazio<T> extends Conjunto<T> {

    public ConjuntoVazio(){
    }

    @Override
    public Boolean contemElemento(T elemento) {
        return false;
    }

}

