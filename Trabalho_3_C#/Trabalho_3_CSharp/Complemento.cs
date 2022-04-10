using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Trabalho_3_CSharp {
    public class Complemento<T> : Conjunto<T> {

    private readonly Conjunto<T> conjunto;

        public Complemento(Conjunto<T> conjunto) {
            this.conjunto = conjunto;
        }
        public override Boolean contemElemento(T elemento) {
            return !(conjunto.contemElemento(elemento));
        }

    }
}
