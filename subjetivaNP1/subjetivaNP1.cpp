#include <stdio.h>
#include <cmath>

int main() {
    // Declaração das variáveis em inglês
    float avg_speed = 0, fuel_efficiency = 0, distance = 0, fuel_price = 0, travel_time;
    float fuel_needed, refuel_cost, tank_capacity = 0, tank_current = 0, fuel_to_fill, remaining_fuel;
    int tank_full = 0;
    int result;
    int stops = 0;

    // Validação dos dados de entrada (em português) com tratamento de caracteres inválidos
    printf("Digite a velocidade média do veículo (km/h): ");
    result = scanf("%f", &avg_speed);
    while (result != 1 || avg_speed <= 0) {
        printf("Valor inválido! Digite um número maior que zero: ");
        while(getchar() != '\n');
        result = scanf("%f", &avg_speed);
    }

    printf("Digite a autonomia do veículo (km/l): ");
    result = scanf("%f", &fuel_efficiency);
    while (result != 1 || fuel_efficiency <= 0) {
        printf("Valor inválido! Digite um número maior que zero: ");
        while(getchar() != '\n');
        result = scanf("%f", &fuel_efficiency);
    }

    printf("Digite a distância do trajeto (km): ");
    result = scanf("%f", &distance);
    while (result != 1 || distance <= 0) {
        printf("Valor inválido! Digite um número maior que zero: ");
        while(getchar() != '\n');
        result = scanf("%f", &distance);
    }

    printf("Digite o preço do combustível (R$/l): ");
    result = scanf("%f", &fuel_price);
    while (result != 1 || fuel_price <= 0) {
        printf("Valor inválido! Digite um número maior que zero: ");
        while(getchar() != '\n');
        result = scanf("%f", &fuel_price);
    }

    printf("Digite a capacidade total do tanque (L): ");
    result = scanf("%f", &tank_capacity);
    while (result != 1 || tank_capacity <= 0) {
        printf("Valor inválido! Digite um número maior que zero: ");
        while(getchar() != '\n');
        result = scanf("%f", &tank_capacity);
    }

    printf("O tanque está cheio?\n Sim - 1\t Não - 2: ");
    result = scanf("%i", &tank_full);
    while (result != 1 || (tank_full != 1 && tank_full != 2)) {
        printf("Opção inválida! Digite 1 para Sim ou 2 para Não: ");
        while(getchar() != '\n');
        result = scanf("%i", &tank_full);
    }

    // Pergunta se está atrasado e deseja ajustar o tempo de viagem
    float desired_time = 0;
    printf("Você está atrasado e precisa chegar em um tempo específico?\nDigite o tempo desejado em horas (ou 0 para ignorar): ");
    result = scanf("%f", &desired_time);
    while (result != 1 || desired_time < 0) {
        printf("Valor inválido! Digite um número maior ou igual a zero: ");
        while(getchar() != '\n');
        result = scanf("%f", &desired_time);
    }
    if (desired_time > 0) {
        avg_speed = distance / desired_time;
        printf("Velocidade média ajustada para chegar em %.2f horas: %.2f km/h\n", desired_time, avg_speed);
    }

    // Calcula o tempo de viagem
    travel_time = distance / avg_speed;

    // Ajusta a eficiência do combustível conforme a velocidade média
    if (avg_speed > 20) {
        int intervals = (int)((avg_speed - 20) / 20);
        for (int i = 0; i < intervals; i++) {
            fuel_efficiency = fuel_efficiency * 0.9;
        }
    }

    // Reserva: se combustível atual < 10% do tanque, aumenta autonomia em 5%
    if (tank_full == 2) {
        printf("Quanto de combustível há atualmente no tanque? (L): ");
        result = scanf("%f", &tank_current);
        while (result != 1 || tank_current < 0 || tank_current >= tank_capacity) {
            if (result != 1 || tank_current < 0) {
                printf("Valor inválido! Digite um número maior ou igual a zero: ");
            } else {
                printf("Quantidade inválida! O valor deve ser menor que a capacidade total do tanque (%.2f L): ", tank_capacity);
            }
            while(getchar() != '\n');
            result = scanf("%f", &tank_current);
        }
        if (tank_current < 0.1 * tank_capacity) {
            fuel_efficiency *= 1.05;
            printf("Autonomia aumentada em 5%% por uso da reserva.\n");
        }
    } else {
        tank_current = tank_capacity;
    }

    // Calcula o total de combustível necessário para a viagem
    fuel_needed = distance / fuel_efficiency;

    // Caso o tanque não esteja cheio
    if (tank_full == 2) {
        // Calcula quanto falta para encher o tanque
        fuel_to_fill = tank_capacity - tank_current;
        printf("Você precisa de %.2fL para encher o tanque.\n", fuel_to_fill);

        // Custo para encher o tanque
        refuel_cost = fuel_to_fill * fuel_price;

        // Calcula quanto combustível vai faltar para a viagem
        remaining_fuel = fuel_needed - tank_current;

        // Se o combustível atual for insuficiente para a viagem
        if (tank_current < fuel_needed) {
            stops = (int)(remaining_fuel / tank_capacity);
            if ((int)remaining_fuel % (int)tank_capacity != 0) stops++;
            printf("Você precisará parar %d vez(es) para abastecer.\n", stops);

            // Adiciona 15 minutos (0.25h) por parada ao tempo de viagem
            travel_time += stops * 0.25;
        } else {
            printf("Não será necessário parar para abastecer.\n");
        }
    } else {
        // Caso o tanque esteja cheio
        printf("Tanque cheio.\n");
        // Se o tanque for suficiente, não há custo extra
        refuel_cost = (fuel_needed > tank_capacity) ? (fuel_needed - tank_capacity) * fuel_price : 0;
        if (fuel_needed > tank_capacity) {
            stops = (int)((fuel_needed - tank_capacity) / tank_capacity);
            if ((int)(fuel_needed - tank_capacity) % (int)tank_capacity != 0) stops++;
            travel_time += stops * 0.25;
            printf("Você precisará parar %d vez(es) para abastecer.\n", stops);
        } else {
            printf("Não será necessário parar para abastecer.\n");
        }
    }

    // Custo total do combustível para a viagem
    float total_fuel_cost = fuel_needed * fuel_price;

    // Formatação do tempo: horas e minutos
    int horas = (int)travel_time;
    int minutos = (int)((travel_time - horas) * 60);

    // Exibe os resultados (em português)
    printf("\nAutonomia ajustada do veículo: %.2f km/l\n", fuel_efficiency);
    printf("Tempo estimado de viagem: %dh %dmin\n", horas, minutos);
    printf("Combustível necessário para a viagem: %.2f L\n", fuel_needed);
    printf("Custo total do combustível: R$ %.2f\n", total_fuel_cost);
    printf("Valor extra de abastecimento: R$ %.2f\n", refuel_cost);

    return 0;
}