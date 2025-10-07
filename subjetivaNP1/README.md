/*
    Este programa calcula o consumo de combustível, o tempo de viagem, o custo total e o número de paradas necessárias para abastecimento em um deslocamento veicular, considerando diferentes cenários e restrições.

    Funcionamento do Programa:
    - Entrada de Dados:
        O usuário informa:
        * Velocidade média do veículo (km/h)
        * Autonomia do veículo (km/l)
        * Distância do trajeto (km)
        * Preço do combustível (R$/l)
        * Capacidade total do tanque (L)
        * Se o tanque está cheio ou não
        * (Se não estiver cheio) Quantidade de combustível atual no tanque (L)
        * (Opcional) Tempo desejado para chegar ao destino (caso esteja atrasado)

    - Validação dos Inputs:
        O programa verifica se todos os valores digitados são válidos (maiores que zero, dentro dos limites do tanque, opções corretas).
        Caso o usuário digite letras ou caracteres inválidos, o programa limpa o buffer do teclado e solicita novamente o valor, evitando loops infinitos e garantindo que apenas dados corretos sejam processados.

    - Ajuste de Autonomia:
        Para cada intervalo de 20 km/h acima de 20 km/h na velocidade média, a autonomia do veículo é reduzida em 10%.
        Se o usuário estiver usando a reserva (menos de 10% do tanque), a autonomia é aumentada em 5%.

    - Cálculo dos Resultados:
        * Tempo de viagem: Calculado pela distância dividida pela velocidade média. Se houver paradas para abastecimento, são adicionados 15 minutos por parada.
        * Combustível necessário: Calculado pela distância dividida pela autonomia ajustada.
        * Custo total do combustível: Multiplicação do combustível necessário pelo preço do litro.
        * Valor extra de abastecimento: Calculado caso seja necessário abastecer durante a viagem.
        * Número de paradas: Calculado se o combustível disponível não for suficiente para a viagem.

    - Formatação do Tempo:
        O tempo de viagem é exibido em horas e minutos (por exemplo, 1h 30min).

    - Saída dos Resultados:
        O programa exibe todos os resultados em português, de forma clara e organizada.

    Resumo das Variáveis:
        avg_speed: Velocidade média do veículo (km/h)
        fuel_efficiency: Autonomia do veículo (km/l)
        distance: Distância do trajeto (km)
        fuel_price: Preço do combustível (R$/l)
        tank_capacity: Capacidade total do tanque (L)
        tank_current: Quantidade atual de combustível no tanque (L)
        tank_full: Indica se o tanque está cheio (1) ou não (2)
        travel_time: Tempo estimado de viagem (h)
        fuel_needed: Combustível necessário para a viagem (L)
        refuel_cost: Valor extra de abastecimento (R$)
        total_fuel_cost: Custo total do combustível para a viagem (R$)
        stops: Número de paradas para abastecimento (caso necessário)

    Casos de Uso:
        - Viagem Normal:
            O usuário informa todos os dados do veículo e do trajeto. O sistema calcula o tempo de viagem, autonomia ajustada, combustível necessário e custos.
        - Atraso:
            Se o usuário está atrasado, pode informar o tempo desejado para chegar ao destino. O programa ajusta automaticamente a velocidade média para cumprir o prazo, recalculando a autonomia (que diminui com o aumento da velocidade) e o consumo de combustível.
        - Reserva:
            Se o tanque não está cheio e a quantidade de combustível está abaixo de 10% da capacidade total, o sistema simula um aumento de 5% na autonomia, representando o uso da reserva do tanque.
        - Paradas para Abastecimento:
            Se o combustível disponível não é suficiente para completar a viagem, o programa calcula quantas paradas serão necessárias para abastecer. Para cada parada, são adicionados 15 minutos ao tempo total de viagem.

    Observações:
    - O código não utiliza funções, apenas estruturas básicas (if, while, for), conforme o conteúdo visto em aula.
    - Todas as entradas e saídas são feitas em português.
    - O tratamento de entradas inválidas garante robustez e evita erros de execução.
    - O sistema cobre os principais cenários de uso sugeridos pelo professor, tornando o cálculo realista e prático para planejamento de viagens veiculares.

    Evidências de Gestão do Projeto Ultilizando o Trello.
    - Segue o link : https://trello.com/invite/b/68d1d366e072d152ce1069d7/ATTI60b03a733feca6f4b3e22760f60679e2D07CD067/meu-quadro-do-trello
*/