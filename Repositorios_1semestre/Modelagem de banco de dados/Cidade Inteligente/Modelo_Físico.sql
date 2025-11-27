
CREATE TABLE Motorista (
    Id_motorista INT PRIMARY KEY,
    Nome VARCHAR(100) NOT NULL,
    Telefone VARCHAR(15)
);

CREATE TABLE Estacionamento (
    Id_estacionamento INT PRIMARY KEY,
    Nome VARCHAR(100) NOT NULL,
    Endereco VARCHAR(255)
);

CREATE TABLE Vaga (
    Id_vaga INT PRIMARY KEY,
    Numero VARCHAR(10) NOT NULL,
    Estado VARCHAR(50), 
    Id_estacionamento INT NOT NULL,
    FOREIGN KEY (Id_estacionamento) REFERENCES Estacionamento(Id_estacionamento)
);

CREATE TABLE Gerencia (
    Id_motorista INT NOT NULL,
    Id_estacionamento INT NOT NULL,
    Id_vaga INT NOT NULL,
    
    PRIMARY KEY (Id_motorista, Id_estacionamento, Id_vaga),
    
    FOREIGN KEY (Id_motorista) REFERENCES Motorista(Id_motorista),
    FOREIGN KEY (Id_estacionamento) REFERENCES Estacionamento(Id_estacionamento),
    FOREIGN KEY (Id_vaga) REFERENCES Vaga(Id_vaga)
);
