int main()
{
    //IDdict organizes Payroll records by ID
    UALdict<int, Pyroll*> IDdict;
    
    //namedict organizes Payroll records by name
    UALdict<string, Payroll*> namedict;

    Payroll *foo1, *foo2, *findfoo1, *findfoo2;

    foo1 = new Payroll(5, "Joe", "Anytown");
    foo2 = new Payroll(10, "John", "Mytown");

    IDdict.insert(foo1->getID(), foo1);
    IDdict.insert(foo2->getID(), foo2);
    namedict.insert(foo1->getname(), foo1);
    namedict.insert(foo2->getname(), foo2);

    findfoo1 = IDdict.find(5);
    if (findfoo1 != NULL) cout << findfoo1;
    else cout << "NULL ";
    findfoo2 = namedict.find("John");
    if (findfoo2 != NULL) cout << findfoo2;
    else cout << "NULL";
}
