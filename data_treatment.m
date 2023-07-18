% Definir as informações dos canais ThingSpeak
CHANNEL_IDS = [2216552, 2158006, 2217676, 2217677];
READ_API_KEYS = {'GNXRHFP7XHYJ3F1L', '12QQRKZ1KV1GDXNN', 'PJNS8XCCIQK54LP3', 'HXEYL13O3PVBKHX7'};
FIELD_NUMBER_LATITUDE = 2;
FIELD_NUMBER_LONGITUDE = 3;
FIELD_NUMBER_NIVEL = 1;

% Le a imagem do mapa de jardim da penha
imagem = imread('https://i.ibb.co/pv4ZZ7w/jardim-maiszonn.png','png');
[height, width, ~] = size(imagem);
imshow(imagem);
hold on;

% Escala de cor
mapaDeCores = jet;  % Escolha um mapa de cores adequado

% Loop através dos canais
numChannels = numel(CHANNEL_IDS);

for i = 1:numChannels
    channelID = CHANNEL_IDS(i);
    readAPIKey = READ_API_KEYS{i};

    % Ler os últimos 10 pontos do canal atual
    dados = thingSpeakRead(channelID, 'ReadKey', readAPIKey, 'numPoints', 10, 'fields', [FIELD_NUMBER_LATITUDE, FIELD_NUMBER_LONGITUDE, FIELD_NUMBER_NIVEL]);

    % Coletar os dados de latitude, longitude e nivel
    latitude = dados(:, 1);
    longitude = dados(:, 2);
    nivel = dados(:, 3);

    % Calcular a média dos valores de nível
    media = mean(nivel);

    % Plotar o ponto com base nos dados fornecidos
    scatter(longitude(1), latitude(1), 100, media, 'filled');
end

colormap(mapaDeCores);
colorbar;
caxis([0, 10]);

hold off;
