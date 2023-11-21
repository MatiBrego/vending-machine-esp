![Austral Ingenieria](https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQooGo7vQn4t9-6Bt46qZF-UY4_QFpYOeh7kVWzwpr_lbLr5wka)

#       Proyecto Smart vending machine simulation

El objetivo de este proyecto es simular una máquina expendedora inteligente que publica sus eventos en un broker MQTT. Esta tiene la capacidad de avisar cuando se realiza una compra de cierto producto, cuando se inserta crédito, cuando se hace una recarga e stock y cuando se rompe (Simulado a través de uno de los botones). Además, al iniciarse, la máquina se suscribe a cierto tópico y avisa que está lista para recibir la información del stock que tenía antes de apagarse a través de ese tópico.

##      Hardware

 Placa de desarrollo de ESP32
 7 Pulsadores Tact
 2 LEDs externos: 1 rojo, 1 verde
 2 Resistores de 220 ohm
 Cables Dupont

##     Tópicos MQTT

Todos los tópicos comienzan con `VendingMachine/`.

###   Publicación

- `/init`
- `/status`
- `/stock`
- `/stock/product/buy`
- `/credit`

###  Subscripción

- `/machine_init_[id]`



