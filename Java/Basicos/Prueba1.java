import java.util.Scanner;


public class Prueba1 
{
    protected int edad;
    protected String nombre;
    
    public Prueba1(int edad, String nombre)
    {
        this.edad = edad;
        this.nombre = nombre;
    }
    
    public int getEdad()
    {
        return edad;
    }
    
    protected void printName()
    {
        System.out.println("Tu nombre es: " + nombre);
    }
    
    public static void main(String [] args)
    {
        //Scanner c; sin instancia
        //Scanner* cc = new Scanner; así es en C++
        Scanner s = new Scanner(System.in);
        System.out.println("Escribe tu nombre karnal: ");
        String nombre = s.nextLine();
        System.out.println("Rifate tu edad también karnal: ");
        int edad = s.nextInt();
        Prueba1 ejemplo = new Prueba1(edad, nombre);
        System.out.println();
        ejemplo.printName();
        System.out.println("Tu edad es: " + ejemplo.getEdad());
    }
    
}
