using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Trabalho_3_CSharp
{
    public class Intersecao<T> : Conjunto<T> {

    private readonly Conjunto<T> conjunto1;
    private readonly Conjunto<T> conjunto2;

    public Intersecao(Conjunto<T> conjunto1, Conjunto<T> conjunto2)
    {
        this.conjunto1 = conjunto1;
        this.conjunto2 = conjunto2;
    }

    public override Boolean contemElemento(T elemento)
    {
        return conjunto1.contemElemento(elemento) && conjunto2.contemElemento(elemento);
    }

}
}
