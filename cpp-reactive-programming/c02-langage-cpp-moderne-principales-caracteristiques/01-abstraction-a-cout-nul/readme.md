# Abstraction à coût nul

Depuis ses débuts, le langage C++ a permis
aux programmeurs de créer un code très performant,
optimisé pour le processeur sur lequel le programme est compilé,
tout en offrant la possibilité de travailler à un niveau d'abstraction élevé
lorsque cela est nécessaire.

Lors du développement des mécanismes d'abstraction,
les concepteurs du langage ont toujours veillé à minimiser,
voire à éliminer complètement, les pertes de performance associées.

Cette caractéristique du langage est appelée « abstraction à coût nul »
ou « abstraction sans perte de performance ».
Le seul coût notable réside dans les appels indirects
(par pointeur) aux fonctions virtuelles.
Malgré l'évolution et l'enrichissement constants du langage,
ses concepteurs ont scrupuleusement respecté cette garantie d'abstraction à coût nul,
caractéristique essentielle du C++ depuis ses origines.
