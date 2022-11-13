# Tòpics
- Base Teòrica
- Avantatges / Desavantatges
- Encriptació
	- Exemples Reals
- Previsió de Futur
	- Comercialització


# Base Teòrica
Actualment la tecnologia funciona amb bits. Aquests són 1 i 0 que es formen depenent si els transistors deixen o no, passar electricitat. El conjunt de tots aquests transistors formen els actuals ordinadors, mòbils…
Un sistema quàntic, per superposició, pot estar en dos estats a la vegada.

```exemple1
Sistema actual  --> 1 o 0
Sistema quàntic --> 1 i 0
```

Un transistor normal pot fer 1 operació a la vegada, mentre que un transistor quàntic, si no es determina el seu estat, pot fer 4 operacions a la vegada. Aquest és un dels problemes que es troba en el món quàntic, mantenir aquesta sobreposició és un cost molt alt.  

```Moneda
Moneda en la mà es Cara o Creu
Moneda en el aire es Cara i Creu.
```


![Photo](https://www.researchgate.net/publication/271532617/figure/fig4/AS:349605003841542@1460363736871/Bits-three-state-systems-cobits-and-qubits-Our-secure-delegated-computing-protocol.png)



| #QuBits | #bits | RAM |
| --- | --- | --- |
| 1 | 2 | 2 bits |
| 3 | 8 | 1 Byte |
| 33 | 8589934592 | 1 GByte |
| 43 | 8.8x10^12 | 1 TByte |

# Avantatges i Desavantatges
## Avantatges
- Computació ràpida: Són 1000 cops més ràpids que els superordinadors actuals.
- Millora de la simulació: En ser més ràpids, es poden simular més casuístiques.
- Millora de la privacitat: En tindre una criptogràfica quàntica, és impossible vulnerar. Xina ha dit que és impossible hackejar.
- Millora de la IA i Machine Learning.

## Desavantatges
- Nous algoritmes: Els algoritmes actuals no funcionen i són molt dèbils en un món quàntic.
- La baixa temperatura que necessiten per funcionar (-200 °C).
- No està obert al públic i encara estan en una fase molt inicial 10 QuBits.
- Seguretat en internet.


# Encriptació Quàntica
QKD (Quantic Key Distribution).
Fotons: Unitat d'energia més petita en una onda de llum i que no es pot dividir.
Polarització: propietat de les ondes que permet que oscil·lin en més d'una orientació. Quan s'observa un fotó s'altera i es determina en una sola direcció.
![[Pasted image 20221113115440.png]]
1. Alice envia fotons polaritzats en 4 direccions diferents de manera aleatòria.
![[Pasted image 20221113115612.png]]
2. Bob té 2 detectors per saber interpretar les direccions que li arriben. Ho fa de forma aleatòria. (Això fa que tingui un 50% de probabilitats)
![[Pasted image 20221113115814.png]]
3. Quan Bob acaba de llegir el missatge que li ha enviat Alice, li diu quina cadena aleatòria de detectors ha fet servir per detectar els fotons.

4. Alice compara la seqüència de Bob amb la seva seqüència inicial i li diu quan ha utilitzat el detector de manera incorrecta. D'aquesta manera Bob sap quins són els fotons registrats correctament (Els que ha fet malament no els fa servir).
![[Pasted image 20221113120105.png]]
6. El resultat correcte serà la clau quàntica que faran servir totes dues parts per encriptar i desencriptar la informació.
## Per què és tan segur?
Si un atacant intenta escoltar la cadena de fotons que li envia Alice a Bob, a l'observar aquests fotons, pertorba l'estat quàntic definint un estat. Això provoca que, el missatge que li arriba a Alice no és el que ella va enviar.

![[Pasted image 20221113120441.png]]
![[Pasted image 20221113120459.png]]
Quan Bob acaba de llegir tota la cadena, li envia una part a Alice perquè comprovi. Si aquesta detecta que hi ha molts errors o inconcordances, farà saltar l'alarma dient que hi ha algo alterant 
# Enllaços
- ¿Que són els ORDINADORS QUÀNTICS?
https://youtu.be/035rUtCPKWU

- Com es Fabrica un Bit Quàntic
https://youtu.be/mVu_kOtuybM
