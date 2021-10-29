//
// Created by Terrence Turner on 10/28/21.
//

#include <stdio.h>
#include "asciiArt.h"

//Items
void printSword(){
    //long sword
    printf("Long Sword\n");
    printf(" __-----__________{]__________________________________________________\n");
    printf("{&&&&&&&#%%%%&#%%&%%&%%&%%&%%#%%&|]__________________________________________________\\\n");
    printf("                  {]\n");
    printf("\n");
}

void printShield(){
    //Shield
    printf("Shield\n");
    printf(" _________________________\n");
    printf("|<><><>     |  |    <><><>|\n");
    printf("|<>         |  |        <>|\n");
    printf("|           |  |          |\n");
    printf("|  (______ <\\-/> ______)  |\n");
    printf("|  /_.-=-.\\| \" |/.-=-._\\  |\n");
    printf("|   /_    \\(o_o)/    _\\   |\n");
    printf("|    /_  /\\/ ^ \\/\\  _\\    |\n");
    printf("|      \\/ | / \\ | \\/      |\n");
    printf("|_______ /((( )))\\ _______|\n");
    printf("|      __\\ \\___/ /__      |\n");
    printf("|--- (((---'   '---))) ---|\n");
    printf("|           |  |          |\n");
    printf("|           |  |          |\n");
    printf(":           |  |          :\n");
    printf(" \\<>        |  |       <>/ \n");
    printf("  \\<>       |  |      <>/  \n");
    printf("   \\<>      |  |     <>/   \n");
    printf("    `\\<>    |  |   <>/'    \n");
    printf("      `\\<>  |  |  <>/'     \n");
    printf("        `\\<>|  |<>/'       \n");
    printf("          `-.  .-`          \n");
    printf("            '--'            \n");
    printf("\n");

}

void printBow(){
    //Bow
    printf("Bow and Arrows\n");
    printf("          4$$-.                \n");
    printf("           4   \".              \n");
    printf("           4    ^.             \n");
    printf("           4     $             \n");
    printf("           4     'b            \n");
    printf("           4      \"b.         \n");
    printf("           4        $         \n");
    printf("           4        $r        \n");
    printf("           4        $F        \n");
    printf("-$b========4========$b====*P=-\n");
    printf("           4       *$$F       \n");
    printf("           4        $$\"       \n");
    printf("           4       .$F        \n");
    printf("           4       dP         \n");
    printf("           4      F           \n");
    printf("           4     @            \n");
    printf("           4    .              \n");
    printf("           J.                 \n");
    printf("          '$$                 \n");
    printf("\n");

}

void printMusket(){
    //Musket
    printf("Musket\n");
    printf("                           ::. .\n");
    printf("                        .-=*##################################*+#*****#####*+++++++****= \n");
    printf(" .----------:        .=####%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%###***********+++++++========----:.........:: \n");
    printf(".#%%%%########%%##=   .+#%%%%%%*=::+--:...\n");
    printf(".#%%%%%%%%%%%%%%%%%%%%%%%%%%#*+*#%%%%%%*....:\n");
    printf(" #%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#\n");
    printf(" +@%%%%#*+==-\n");
    printf("\n");

}

void printArmor(){
    //Armor
    printf("Armor\n");
    printf("          {}\n");
    printf("         .--.\n");
    printf("        /.--.\\\n");
    printf("        |====|\n");
    printf("        |`::`|\n");
    printf("    .-;`\\..../`;-.\n");
    printf("   /  |...::...|  \\\n");
    printf("  |   /'''::'''\\   |\n");
    printf("  ;--'\\   ::   /\\--;\n");
    printf("  <__>,>._::_.<,<__>\n");
    printf("  |  |/   ^^   \\|  |\n");
    printf("  \\::/|        |\\::/\n");
    printf("  |||\\|        |/|||\n");
    printf("  ''' |___/\\___| '''\n");
    printf("       \\_ || _/\n");
    printf("       <_ >< _>\n");
    printf("       |  ||  |\n");
    printf("       |  ||  |\n");
    printf("      _\\.:||:./_\n");
    printf("     /____/\\____\\\n");
    printf("\n");

}

void printPotion(){
    //Potion
    printf("Potion\n");
    printf("    _\n");
    printf("   [_ ]\n");
    printf(" .-'. '-.\n");
    printf("/:;/ _.-'\\\n");
    printf("|:._   .-|\n");
    printf("|:._     |\n");
    printf("|:._     |\n");
    printf("|:._     |\n");
    printf("|:._     |\n");
    printf("`-.____.-'\n");
    printf("\n");
}

//Dungeon
void printDungeon(){
    //Dungeon
    printf("Dungeon\n");
    printf("______________________________________________________\n");
    printf("[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]\n");
    printf(".-.`| `-/-.__/.-'\\_.-._,'/`-._'\\_.-._`-'_/-._.'|/.-'\\-\n");
    printf("\\_.-`./`-._'\\__.-`-.__.-`--._/--.`-._\\`-._\\__.-)`-'._/\n");
    printf("`._-'.\\_.---._-.\\_`-..`\\_.---._`-.__.-`'._.--./`-'._,'\n");
    printf("__/`.-/       `.'_`./`.'       '.\\__.-`.'    (_.-\\_,-.\n");
    printf("`._-/'          |._.-|           |.'`.|       `(_.`-._\n");
    printf(".-',`)          | /`.|           |`-/`|         ;.-'_/\n");
    printf("`\\,-/           |\\.-'|           |\\-'`|          ;\\_,-\n");
    printf(" -./`._        [[[[[[[[         [[[[[[[[         .',-'\n");
    printf("\n");
}



//Enemies
void printGargoyle(){
    //gargoyle
    printf("Gargoyle\n");
    printf(",                                                               ,\n");
    printf("\\'.                                                           .'/\n");
    printf(" ),\\                                                         /,( \n");
    printf("/__\\'.                                                     .'/__\\\n");
    printf("\\  `'.'-.__                                           __.-'.'`  /\n");
    printf("`)   `'-. \\                                         / .-'`   ('\n");
    printf("/   _.--'\\ '.          ,               ,          .' /'--._   \\\n");
    printf("|-'`      '. '-.__    / \\             / \\    __.-' .'      `'-|\n");
    printf("\\         _.`'-.,_'-.|/\\ \\    _,_    / /\\|.-'_,.-'`._         /\n");
    printf(" `\\    .-'       /'-.|| \\ |.-\"   \"-.| / ||.-'\\       '-.    /`\n");
    printf("   )-'`        .'   :||  / -.\\\\ //.- \\  ||:   '.        `'-(\n");
    printf("  /          .'    / \\\\_ |  /o`^'o\\  | _// \\    '.          \\\n");
    printf("  \\       .-'    .'   `--|  `\"/ \\\"`  |--`   '.    '-.       /\n");
    printf("   `)  _.'     .'    .--.; |\\__\"__/| ;.--.    '.     '._  ('\n");
    printf("  /_.'     .-'  _.-'     \\\\ \\/^\\/ //     `-._  '-.     '._\\\n");
    printf("   \\     .'`_.--'          \\\\     //          `--._`'.     /\n");
    printf("    '-._' /`            _   \\\\-.-//   _            `\\ '_.-'\n");
    printf("        `<     _,..--''`|    \\`\"`/    |`''--..,_     >`\n");
    printf("         _\\  ``--..__   \\     `'`     /   __..--``  /_\n");
    printf("        /  '-.__     ``'-;    / \\    ;-'``     __.-'  \\\n");
    printf("       |    _   ``''--..  \\'-' | '-'/  ..--''``   _    |\n");
    printf("       \\     '-.       /   |/--|--\\|   \\       .-'     /\n");
    printf("        '-._    '-._  /    |---|---|    \\  _.-'    _.-'\n");
    printf("          `'-._   '/ / / /---|---\\ \\ \\ \\'   _.-'`\n");
    printf("               '-./ / / / \\`---`/ \\ \\ \\ \\.-'\n");
    printf("                   `)` `  /'---'\\  ` `(`\n");
    printf("                  /`     |       |     `\\\n");
    printf("                 /  /  | |       | |  \\  \\\n");
    printf("             .--'  /   | '.     .' |   \\  '--.\n");
    printf("            /_____/|  / \\._\\   /_./ \\  |\\_____\\\n");
    printf("           (/      (/'     \\) (/     `\\)      \\)\n");
    printf("\n");

}

void printWisp(){
    //wisp
    printf("Wisp\n");
    printf("               ..::..                             \n");
    printf("              .=-::-=+******+++-.                  \n");
    printf("          :=-:++=:-=++++++*+++=--:-==.             \n");
    printf("         -=+++=====+========++=-----=+.              \n");
    printf("       :.====-::..:::::::-=====+=+===***-                 \n");
    printf("      .+=---:---=++===--...::-===+++***#+.               \n");
    printf("    .-=---:=**+**#:#*#%%#=.:::---==+****=:            \n");
    printf("   =++==::-#-%%###= :##@%%#-..:--===++=---:            \n");
    printf("   -+++=:.--=#**%%%%-##*%%%%+=..::-======:---=.        \n");
    printf("   .+++=--***+=-*****%%%%#-...:---====+++=::-         \n");
    printf("  ::+*+=-+##****##%%%%%%%%%%%%#*-.::---=====+==--:     \n");
    printf(" -==**+=-::=++=-=+*=+%%#%%#*=..:::----===-:-:-:   \n");
    printf("  -**++=-:.=#+:     .==++-....:-::::--=+=---=: \n");
    printf(" :*+-===-:.-#*=.   .:***. ....:--:.:::-+++++=:+-  \n");
    printf(" +*=--:==-:+#+-::-=*###%%=..:::::---::-=++++++***-   \n");
    printf(" .=+---==-:=#########*=-:::::-----=-.:====+++***=: \n");
    printf("  .*+-:=--:::****##+:.:::..:---------:====-==+**== \n");
    printf("  .**+==::::-:+**+-:::..:.::---::::--===--::--=+*-  \n");
    printf("   :**++===-:---::-----:::::---::::-------::-:=+*:  \n");
    printf("    .+*****++==-::::-==---=-:-====-::====---::-=+:  \n");
    printf("      :.-+--=*+-:-::-========-:-=+++========--.-=*+: \n");
    printf("         -=-.-+*+=-:-====++=-:---++::+-=::========+*:\n");
    printf("\n");

}

void printElemental(){
    //Elemental (Fire)
    printf("Elemental Fire\n");
    printf("              (  .      )\n");
    printf("          )           (              )\n");
    printf("                .  '   .   '  .  '  .\n");
    printf("       (    , )       (.   )  (   ',    )\n");
    printf("        .' ) ( . )    ,  ( ,     )   ( .\n");
    printf("     ). , ( .   (  ) ( , ')  .' (  ,    )\n");
    printf("    (_,) . ), ) _) _,')  (, ) '. )  ,. (' )\n");
    printf("   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("\n");

}

void printBoss(){
    //Demilich Boss
    printf("Demilich Boss\n");
    printf("         _,.-------.,_\n");
    printf("     ,;~'             '~;,\n");
    printf("   ,;                     ;,\n");
    printf("  ;                         ;\n");
    printf(" ,'                         ',\n");
    printf(",;                           ;,\n");
    printf("; ;      .           .      ; ;\n");
    printf("| ;   ______       ______   ; |\n");
    printf("|  `/~\"     ~\" . \"~     \"~\\'  |\n");
    printf("|  ~  ,-~~~^~, | ,~^~~~-,  ~  |\n");
    printf(" |   |        }:{        |   |\n");
    printf(" |   l       / | \\       !   |\n");
    printf(" .~  (__,.--\" .^. \"--.,__)  ~.\n");
    printf(" |     ---;' / | \\ `;---     |\n");
    printf("  \\__.       \\/^\\/       .__/\n");
    printf("   V| \\                 / |V\n");
    printf("    | |T~\\___!___!___/~T| |    \n");
    printf("    | |`IIII_I_I_I_IIII'| |  \n");
    printf("    |  \\,III I I I III,/  |  \n");
    printf("     \\   `~~~~~~~~~~'    /  \n");
    printf("       \\   .       .   /     \n");
    printf("         \\.    ^    ./     \n");
    printf("           ^~~~^~~~^      \n");
    printf("\n");

}


//Enemies in Dungeon
void printGargoyleDungeon(){
    //Dungeon and gargoyle
    printf("Dungeon and Gargoyle\n");
    printf("______________________________________________________\n");
    printf("[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]\n");
    printf(".-.`| `-/-.__/.-'\\_.-._,'/`-._'\\_.-._`-'_/-._.'|/.-'\\-\n");
    printf("\\_.-`./`-._'\\__.-`-.__.-`--._/--.`-._\\`-._\\__.-)`-'._/\n");
    printf("`._-'.\\_.---._-.\\_`-..`\\_.---._`-.__.-`'._.--./`-'._,'\n");
    printf("__/`.-/       `.'_`./`.'       '.\\__.-`.'    (_.-\\_,-.\n");
    printf("`._-/'          |._.-|           |.'`.|       `(_.`-._\n");
    printf(".-',`)          | /`.|           |`-/`|         ;.-'_/\n");
    printf("`\\,-/           |\\.-'|           |\\-'`|          ;\\_,-\n");
    printf(",               |._.-|           |.'`.|          `(_.`-._       ,\n");
    printf("\\'.             | /`.|           |`-/`|           ;.-'_/      .'/\n");
    printf(" ),\\            |._.-|           |.'`.|           `(_.`-._   /,( \n");
    printf("/__\\'.          | /`.|           |`-/`|           `(_.`-._.'  /__\\\n");
    printf("\\  `'.'-.__     |._.-|           |.'`.|               __.-'.'`  /\n");
    printf("`)   `'-. \\     | /`.|           |`-/`|               / .-'`   ('\n");
    printf("/   _.--'\\ '.          ,               ,          .' /'--._   \\\n");
    printf("|-'`      '. '-.__    / \\             / \\    __.-' .'      `'-|\n");
    printf("\\         _.`'-.,_'-.|/\\ \\    _,_    / /\\|.-'_,.-'`._         /\n");
    printf(" `\\    .-'       /'-.|| \\ |.-\"   \"-.| / ||.-'\\       '-.    /`\n");
    printf("   )-'`        .'   :||  / -.\\\\ //.- \\  ||:   '.        `'-(\n");
    printf("  /          .'    / \\\\_ |  /o`^'o\\  | _// \\    '.          \\\n");
    printf("  \\       .-'    .'   `--|  `\"/ \\\"`  |--`   '.    '-.       /\n");
    printf("   `)  _.'     .'    .--.; |\\__\"__/| ;.--.    '.     '._  ('\n");
    printf("  /_.'     .-'  _.-'     \\\\ \\/^\\/ //     `-._  '-.     '._\\\n");
    printf("   \\     .'`_.--'          \\\\     //          `--._`'.     /\n");
    printf("    '-._' /`            _   \\\\-.-//   _            `\\ '_.-'\n");
    printf("`._-/'  `<     _,..--''`|    \\`\"`/    |`''--..,_     >`\n");
    printf(".-',`)   _\\  ``--..__   \\     `'`     /   __..--``  /_\n");
    printf("`\\,-/  /  '-.__     ``'-;    / \\    ;-'``     __.-'  \\\n");
    printf("`._-/' |    _   ``''--..  \\'-' | '-'/  ..--''``   _    |\n");
    printf(".-',`) \\     '-.       /   |/--|--\\|   \\       .-'     /\n");
    printf("`\\,-/  '-._    '-._  /    |---|---|    \\  _.-'    _.-'\n");
    printf("`._-/'    `'-._   '/ / / /---|---\\ \\ \\ \\'   _.-'`\n");
    printf(".-',`)         '-./ / / / \\`---`/ \\ \\ \\ \\.-'\n");
    printf("`\\,-/             `)` `  /'---'\\  ` `(`\n");
    printf("`._-/'            /`     |       |     `\\\n");
    printf(".-',`)           /  /  | |       | |  \\  \\\n");
    printf("`\\,-/       .--'  /   | '.     .' |   \\  '--.\n");
    printf("`._-/'      /_____/|  / \\._\\   /_./ \\  |\\_____\\\n");
    printf(".-',`)      (/      (/'     \\) (/     `\\)      \\)\n");
    printf("`\\,-/           |\\.-'|           |\\-'`|          ;\\_,-\n");
    printf(" -./`._        [[[[[[[[         [[[[[[[[         .',-'\n");
    printf("\n");

}

void printWispDungeon(){
    //Wisp in dungeon
    printf("Wisp in dungeon\n");
    printf("______________________________________________________\n");
    printf("[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]\n");
    printf(".-.`| `-/-.__/.-'\\_.-._,'/`-._'\\_.-._`-'_/-._.'|/.-'\\-\n");
    printf("\\_.-`./`-._'\\__.-`-.__.-`--._/--.`-._\\`-._\\__.-)`-'._/\n");
    printf("`._-'.\\_.---._-.\\_`-..`\\_.---._`-.__.-`'._.--./`-'._,'\n");
    printf("__/`.-/       `.'_`./`.'       '.\\__.-`.'    (_.-\\_,-.\n");
    printf("`._-/'          |._.-|           |.'`.|       `(_.`-._\n");
    printf("               ..::..            |.'`.|       (_.-\\_,-.    \n");
    printf("              .=-::-=+******+++-.             `(_.`-._     \n");
    printf("          :=-:++=:-=++++++*+++=--:-==.        `(_.`-._     \n");
    printf("         -=+++=====+========++=-----=+.       (_.-\\_,-.      \n");
    printf("       :.====-::..:::::::-=====+=+===***-     `(_.`-._            \n");
    printf("      .+=---:---=++===--...::-===+++***#+.    (_.-\\_,-.          \n");
    printf("    .-=---:=**+**#:#*#%%#=.:::---==+****=:       (_.-\\_,-.      \n");
    printf("   =++==::-#-%%###= :##@%%#-..:--===++=---:       `(_.`-._       \n");
    printf("   -+++=:.--=#**%%%%-##*%%%%+=..::-======:---=.     (_.-\\_,-.    \n");
    printf("   .+++=--***+=-*****%%%%#-...:---====+++=::-   `(_.`-._      \n");
    printf("  ::+*+=-+##****##%%%%%%%%%%%%#*-.::---=====+==--:     (_.-\\_,-.  \n");
    printf(" -==**+=-::=++=-=+*=+%%#%%#*=..:::----===-:-:-:   \n");
    printf("  -**++=-:.=#+:     .==++-....:-::::--=+=---=: \n");
    printf(" :*+-===-:.-#*=.   .:***. ....:--:.:::-+++++=:+-  \n");
    printf(" +*=--:==-:+#+-::-=*###%%=..:::::---::-=++++++***-   \n");
    printf(" .=+---==-:=#########*=-:::::-----=-.:====+++***=: \n");
    printf("  .*+-:=--:::****##+:.:::..:---------:====-==+**== \n");
    printf("  .**+==::::-:+**+-:::..:.::---::::--===--::--=+*-  \n");
    printf("   :**++===-:---::-----:::::---::::-------::-:=+*:  \n");
    printf("    .+*****++==-::::-==---=-:-====-::====---::-=+:  \n");
    printf("      :.-+--=*+-:-::-========-:-=+++========--.-=*+: \n");
    printf("         -=-.-+*+=-:-====++=-:---++::+-=::========+*:\n");
    printf("`\\,-/           |\\.-'|           |\\-'`|          ;\\_,-\n");
    printf(" -./`._        [[[[[[[[         [[[[[[[[         .',-'\n");
    printf("\n");

}

void printElementalDungeon(){
    // Dungeon and Fire
    printf("Fire Elemental in Dungeon\n");
    printf("______________________________________________________\n");
    printf("[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]\n");
    printf(".-.`| `-/-.__/.-'\\_.-._,'/`-._'\\_.-._`-'_/-._.'|/.-'\\-\n");
    printf("\\_.-`./`-._'\\__.-`-.__.-`--._/--.`-._\\`-._\\__.-)`-'._/\n");
    printf("`._-'.\\_.---._-.\\_`-..`\\_.---._`-.__.-`'._.--./`-'._,'\n");
    printf("__/`.-/       `.'_`./`.'       '.\\__.-`.'    (_.-\\_,-.\n");
    printf("`._-/'          |._.-|           |.'`.|       `(_.`-._\n");
    printf("              (  .      )                      ;.-'_/\n");
    printf("          )           (              )          ;\\_,-\n");
    printf("                .  '   .   '  .  '  .           ;.-'_/\n");
    printf("       (    , )       (.   )  (   ',    )        ;\\_,-\n");
    printf("        .' ) ( . )    ,  ( ,     )   ( .        ;.-'_/\n");
    printf("     ). , ( .   (  ) ( , ')  .' (  ,    )        ;\\_,-\n");
    printf("    (_,) . ), ) _) _,')  (, ) '. )  ,. (' )      ;.-'_/\n");
    printf("   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^    ;\\_,-\n");
    printf("`\\,-/           |\\.-'|           |\\-'`|          ;\\_,-\n");
    printf(" -./`._        [[[[[[[[         [[[[[[[[         .',-'\n");
    printf("\n");

}

void printBossDungeon(){
    //Demilich Boss in Dungeon
    printf("Demilich Boss in Dungeon\n");
    printf("______________________________________________________\n");
    printf("[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]\n");
    printf(".-.`| `-/-.__/.-'\\_.-._,'/`-._'\\_.-._`-'_/-._.'|/.-'\\-\n");
    printf("\\_.-`./`-._'\\__.-`-.__.-`--._/--.`-._\\`-._\\__.-)`-'._/\n");
    printf("`._-'.\\_.---._-.\\_`-..`\\_.---._`-.__.-`'._.--./`-'._,'\n");
    printf("__/`.-/       `.'_`./`.'       '.\\__.-`.'    (_.-\\_,-.\n");
    printf("`._-/'          |._.-|           |.'`.|       `(_.`-._\n");
    printf("         _,.-------.,_           |`-/`|       (_.-\\_,-.\n");
    printf("     ,;~'             '~;,       |.'`.|       `(_.`-._\n");
    printf("   ,;                     ;,     |`-/`|       (_.-\\_,-.\n");
    printf("  ;                         ;    |.'`.|       `(_.`-._\n");
    printf(" ,'                         ',   |`-/`|       (_.-\\_,-.\n");
    printf(",;                           ;,  |.'`.|       `(_.`-._\n");
    printf("; ;      .           .      ; ;  |`-/`|       (_.-\\_,-.\n");
    printf("| ;   ______       ______   ; |  |.'`.|       `(_.`-._\n");
    printf("|  `/~\"     ~\" . \"~     \"~\\'  |  |`-/`|       (_.-\\_,-.\n");
    printf("|  ~  ,-~~~^~, | ,~^~~~-,  ~  |  |.'`.|       `(_.`-._\n");
    printf(" |   |        }:{        |   |   |`-/`|       (_.-\\_,-.\n");
    printf(" |   l       / | \\       !   |   |.'`.|       `(_.`-._\n");
    printf(" .~  (__,.--\" .^. \"--.,__)  ~.   |`-/`|       (_.-\\_,-.\n");
    printf(" |     ---;' / | \\ `;---     |   |.'`.|       `(_.`-._\n");
    printf("  \\__.       \\/^\\/       .__/    |`-/`|       (_.-\\_,-.\n");
    printf("   V| \\                 / |V     |.'`.|       `(_.`-._\n");
    printf("    | |T~\\___!___!___/~T| |      |`-/`|       (_.-\\_,-.\n");
    printf("    | |`IIII_I_I_I_IIII'| |      |.'`.|       `(_.`-._\n");
    printf("    |  \\,III I I I III,/  |      |`-/`|       (_.-\\_,-.\n");
    printf("     \\   `~~~~~~~~~~'    /       |.'`.|      `(_.`-._\n");
    printf("       \\   .       .   /         |`-/`|       (_.-\\_,-.\n");
    printf("         \\.    ^    ./           |.'`.|       `(_.`-._\n");
    printf("           ^~~~^~~~^             |`-/`|       (_.-\\_,-.\n");
    printf("`\\,-/           |\\.-'|           |\\-'`|          ;\\_,-\n");
    printf(" -./`._        [[[[[[[[         [[[[[[[[         .',-'\n");
    printf("\n");

}