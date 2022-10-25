using System;
using System.Runtime.InteropServices;

class Program
{
    static void Main()
    {
        
        var start = DateTime.Now;
        var rng = new Random();
        IntPtr queue = Connector.initList();

        for(int i = 0; i < 1000000; i++){
            Connector.push_el(queue, rng.Next(1000), rng.Next(1000));
        }

        int a ;
        for(int i = 0; i < 1000000; i++){
            a = (Connector.pop_el(queue));
        }
        var end = DateTime.Now;
        Console.WriteLine(end - start);
    }

}

class Connector
{
    [DllImport("./qp.dll")]
    public static extern IntPtr initList();

    [DllImport("./qp.dll")]
    public static extern void deleteList(IntPtr pq);
    
    [DllImport("./qp.dll")]
    public static extern void push_el(IntPtr pq, int v, int p);

    [DllImport("./qp.dll")]
    public static extern int pop_el(IntPtr pq);

}