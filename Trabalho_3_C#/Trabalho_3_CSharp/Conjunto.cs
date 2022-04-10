using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Trabalho_3_CSharp
{
    public abstract class Conjunto<T> {

        public abstract Boolean contemElemento(T elemento);
        public Conjunto<T> adicionarElemento(T elemento) {
            return new ConjuntoElemento<T>(elemento, this);
        }
        public Conjunto<T> uniao(Conjunto<T> conjunto) {
            return new Uniao<T>(this, conjunto);
        }
        public Conjunto<T> intersecao(Conjunto<T> conjunto) {
            return new Intersecao<T>(this, conjunto);
        }
        public Conjunto<T> diferenca(Conjunto<T> conjunto) {
            return new Diferenca<T>(this, conjunto);
        }
        public Conjunto<T> complemento() {
            return new Complemento<T>(this);
        }
    }
}
