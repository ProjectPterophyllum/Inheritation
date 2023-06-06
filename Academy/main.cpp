#include "stdafx.h"

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHECK
	Human human("Master Chief", "John - 117", 42); //Halo :)
	delimiter;
	human.print();
	Student student("Lamperouge", "Lelouch", 17, "Zero/ImperatorSon", "BlackKnights", 100, 70); //(Code Geass) the same person which placed on my Teams_account avatar
	delimiter;
	student.print();
	Teacher teacher("SmartAI", "Cortana", 2023 - 2549, "Artifical Intelligence", 7);
	delimiter;
	teacher.print();
	delimiter;
	Graduate graduate("Lourens", "Barns", 35, "Nanomachines", "Predator", 100, 100, "How to replace the human body with nanomachines");
	delimiter;
	graduate.print();
	delimiter;
#endif // INHERITANCE_CHECK
#ifdef POLYMORPHISM
	//Generalisation:
	Human* group[] =
	{
	new Student("Angelo", "Tomas", 27, "Passenger Transportation", "SalieriTeam", 95, 100),
	new Teacher("Yoshida", "Shoyo", 999, "Bushido", 10),
	new Graduate("Sakata", "Gintoki", 29, "MartialArts/Kenjutsu", "Yorozuya", 100, 70, "How to be a Great Samurai"),
	new Student("Marley", "Robert", 30, "Biology", "JahRastafari", 100, 100),
	new Teacher("Cooper", "Sheldon", 25, "Theorethical Physics", 20),
	new Graduate("Friman", "Gordon", 27, "Theorethical Physics", "VALVE_HL", 100, 100, "How to teleport safety, without any issues"),
	new Graduate("Menethil", "Arthas", 22, "Theology", "Warriors of Light", 20, 100, "How to cure the plague with the sacred hammer"),
	new Teacher("Ner\'","Zul", 60, "Shamanism", 30)
	};
	//Specialisation
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->print();
		delimiter;
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++) delete group[i];
#endif // POLYMORPHISM
#ifdef TO_TEXT_FILE


#endif // TO_TEXT_FILE

}