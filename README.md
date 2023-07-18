# Monitoramento de Água - Projeto de IoT 2023/1

Este repositório contém os arquivos relacionados ao projeto de monitoramento de água desenvolvido como parte da disciplina de IoT no período 2023/1. Aqui você encontrará o arquivo `level_mensurament.ino`, que contém o código responsável pela leitura de dados do sensor VL53L0X e o arquivo `data_treatment.m` que contem o código matlab utilizado na plataforma thingspeak para tratamento e visualização dos dados.

## Descrição do Projeto

O objetivo deste projeto é criar um sistema de monitoramento de nível de água utilizando a tecnologia IoT. O sensor VL53L0X é utilizado para realizar as medições precisas do nível de água em um recipiente.

O arquivo `level_mensurament.ino` contém o código-fonte que permite a comunicação com o sensor VL53L0X e a leitura dos dados de nível de água. O código foi desenvolvido na plataforma Arduino IDE, garantindo sua compatibilidade com o módulo ESP8266.

## Funcionalidades

- Leitura precisa do nível de água utilizando o sensor VL53L0X.
- Comunicação e transmissão dos dados através do módulo ESP8266.
- Integração com a plataforma IoT para armazenamento e análise dos dados.

## Requisitos

- Placa Arduino compatível (ex.: Arduino Uno, Arduino Mega).
- Sensor de distância VL53L0X.
- Módulo ESP8266.
- Plataforma Arduino IDE instalada.
- Conta no ThingSpeak para a integração IoT.

Lembre-se que você deve adicionar ao seu arduino IDE as bibliotecas do esp8266, thingspeak e do sensor VL53L0X.

## Como Utilizar

1. Conecte o sensor VL53L0X e o módulo ESP8266 à placa Arduino conforme as especificações do hardware utilizado.
2. Acesse a plataforma ThingSpeak, faça um matlab visualization custom e cole o arquivo data_treatment.m (modifique-o para suas chaves).
3. Faça a configuração e o upload do arquivo `level_mensurament.ino` para a placa Arduino utilizando a Arduino IDE.
4. Certifique-se de ter uma conexão com a internet disponível para a transmissão dos dados.
5. Execute o código na placa Arduino e acompanhe os dados de nível de água através da plataforma ThingSpeak.

## Contribuição

Contribuições para o aprimoramento deste projeto são sempre bem-vindas. Caso queira contribuir, siga as diretrizes de contribuição e envie um pull request.

## Licença

Este projeto está licenciado sob a [Licença MIT](LICENSE). Sinta-se à vontade para utilizar, modificar e distribuir o código conforme necessário.

## Contato

Em caso de dúvidas ou sugestões, entre em contato através do e-mail [seu-email@example.com](mailto:seu-email@example.com).
