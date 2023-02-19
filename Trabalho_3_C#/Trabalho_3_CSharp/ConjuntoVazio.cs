using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Trabalho_3_CSharp
{
    public class ConjuntoVazio<T> : Conjunto<T> {

        public ConjuntoVazio() {
        }

        public override Boolean contemElemento(T elemento) {
            return false;
        }

    }
}
