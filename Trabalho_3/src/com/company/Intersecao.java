/**
 * @file   Intersecao.java
 * @brief  Arquivo dedicado à função main do programa.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2022-01-15
 */

package com.company;

public class Intersecao<T> extends Conjunto<T> {

    private final Conjunto<T> conjunto1;
    private final Conjunto<T> conjunto2;

    public Intersecao(Conjunto<T> conjunto1, Conjunto<T> conjunto2) {
        this.conjunto1 = conjunto1;
        this.conjunto2 = conjunto2;
    }

    @Override
    public Boolean contemElemento(T elemento) {
        return conjunto1.contemElemento(elemento) && conjunto2.contemElemento(elemento);
    }

}
