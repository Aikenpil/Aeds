/**
 * @file   Conjunto.java
 * @brief  Arquivo dedicado à classe abstrata que.
 * @author Gustavo Rangel Bandeira Cauduro
 * @date   2022-01-15
 */

package com.company;

public abstract class Conjunto<T> {
    public abstract Boolean contemElemento(T elemento);
    Conjunto<T> adicionarElemento(T elemento) {
        return new ConjuntoElemento<>(elemento, this);
    }
    Conjunto<T> uniao(Conjunto<T> conjunto ) {
        return new Uniao<>(this, conjunto);
    }
    Conjunto<T> intersecao(Conjunto<T> conjunto) {
        return new Intersecao<>(this, conjunto);
    }
    Conjunto<T> diferenca(Conjunto<T> conjunto) {
        return new Diferenca<>(this, conjunto);
    }
    Conjunto<T> complemento() {
        return new Complemento<>(this);
    }
}
