using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Trabalho_3_CSharp
{
    public class ConjuntoElemento<T> : Conjunto<T> {

        private readonly T valor;
        private readonly Conjunto<T> conjunto;

        public ConjuntoElemento(T valor, Conjunto<T> conjunto) {
            this.valor = valor;
            this.conjunto = conjunto;
        }

        public override Boolean contemElemento(T elemento) {
            return Equals(elemento, valor) == true || conjunto.contemElemento(elemento);
        }

    }
}
