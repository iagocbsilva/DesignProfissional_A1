const cidadeDosRelojoeiros = {
  nome: "Cidade dos Relojoeiros",
  lat: -15.7801,   
  lng: -47.9292,
  zoom: 13
};

window.addEventListener('load', () => {
  const map = L.map('map').setView([cidadeDosRelojoeiros.lat, cidadeDosRelojoeiros.lng], cidadeDosRelojoeiros.zoom);

  L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
    attribution: '&copy; OpenStreetMap contributors'
  }).addTo(map);

  L.marker([cidadeDosRelojoeiros.lat, cidadeDosRelojoeros.lng || cidadeDosRelojoeiros.lat])
    .addTo(map)
    .bindPopup(`<b>${cidadeDosRelojoeiros.nome}</b><br>Rua Sem Número`)
    .openPopup();
});