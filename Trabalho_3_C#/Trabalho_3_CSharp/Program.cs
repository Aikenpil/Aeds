using System;

namespace Trabalho_3_CSharp {
    public class Program {
        static void Main(string[] args) {

            // c1 = {1, 2, 3, 4, 5}
            Conjunto<int> c1 = new ConjuntoVazio<int>();
            c1 = c1.adicionarElemento(1);
            c1 = c1.adicionarElemento(2);
            c1 = c1.adicionarElemento(3);
            c1 = c1.adicionarElemento(4);
            c1 = c1.adicionarElemento(5);

            // c2 = {1, 3, 5, 7, 9}
            Conjunto<int> c2 = new ConjuntoVazio<int>();
            c2 = c2.adicionarElemento(1);
            c2 = c2.adicionarElemento(3);
            c2 = c2.adicionarElemento(5);
            c2 = c2.adicionarElemento(7);
            c2 = c2.adicionarElemento(9);

            Console.WriteLine(c1.contemElemento(2) ? "2 Pertence a c1" : "2 Nao Pertence a c1");
            Console.WriteLine(c1.contemElemento(7) ? "7 Pertence a c1" : "7 Nao Pertence a c1");
            Console.WriteLine();

            Console.WriteLine(c2.contemElemento(7) ? "7 Pertence a c2" : "7 Nao Pertence a c2");
            Console.WriteLine(c2.contemElemento(8) ? "8 Pertence a c2" : "8 Nao Pertence a c2");
            Console.WriteLine();

            // c3 = c1 U c2 = {1, 2, 3, 4, 5, 7, 9}
            Conjunto<int> c3 = c1.uniao(c2);

            Console.WriteLine(c3.contemElemento(5) ? "5 Pertence a c3" : "5 Nao Pertence a c3");
            Console.WriteLine(c3.contemElemento(6) ? "6 Pertence a c3" : "6 Nao Pertence a c3");
            Console.WriteLine();

            // c4 = c1 ∩ c2 = {1, 3, 5}
            Conjunto<int> c4 = c1.intersecao(c2);

            Console.WriteLine(c4.contemElemento(3) ? "3 Pertence a c4" : "3 Nao Pertence a c4");
            Console.WriteLine(c4.contemElemento(4) ? "4 Pertence a c4" : "4 Nao Pertence a c4");
            Console.WriteLine();

            // c5 = c1 - c2 = {2, 4}
            Conjunto<int> c5 = c1.diferenca(c2);

            Console.WriteLine(c5.contemElemento(3) ? "3 Pertence a c5" : "3 Nao Pertence a c5");
            Console.WriteLine(c5.contemElemento(4) ? "4 Pertence a c5" : "4 Nao Pertence a c5");
            Console.WriteLine();

            // c6 = complemento(c1)
            Conjunto<int> c6 = c1.complemento();

            Console.WriteLine(c6.contemElemento(2) ? "2 Pertence a c6" : "2 Nao Pertence a c6");
            Console.WriteLine(c6.contemElemento(7) ? "7 Pertence a c6" : "7 Nao Pertence a c6");
            Console.WriteLine();

        }
    }
}
