# Estacionamento Inteligente

1. Entidade Motorista

Motorista(Id_motorista, Nome, Telefone)

PK: Id_motorista

Representa cada motorista registrado no sistema. Armazena seus dados básicos de identificação e contato.

2. Entidade Estacionamento

Estacionamento(Id_estacionamento, Nome, Endereco)

PK: Id_estacionamento

Armazena informações de cada estacionamento disponível no sistema, incluindo nome e localização.

3. Entidade Vaga

Vaga(Id_vaga, Numero, Estado, Id_estacionamento)

PK: Id_vaga

FK: Id_estacionamento → Estacionamento(Id_estacionamento)

Cada vaga pertence a um estacionamento.
Atributos como número e estado indicam identificação e disponibilidade.

Relacionamento:

Um estacionamento possui várias vagas (1:N).

4. Tabela Associativa Gerencia

Gerencia(Id_motorista, Id_estacionamento, Id_vaga)

PK composta: (Id_motorista, Id_estacionamento, Id_vaga)

FK1: Id_motorista → Motorista(Id_motorista)

FK2: Id_estacionamento → Estacionamento(Id_estacionamento)

FK3: Id_vaga → Vaga(Id_vaga)

Esta tabela representa a relação de gerenciamento entre motoristas e vagas dentro de um estacionamento.
Como o gerenciamento pode ocorrer de maneiras variadas, é necessário registrar o motorista responsável, a vaga e o estacionamento correspondente.

Relacionamentos:

Um motorista pode gerenciar várias vagas.

Uma vaga pode ser gerenciada por vários motoristas.

A associação depende também do estacionamento.

Isso caracteriza um relacionamento N:N entre Motorista e Vaga, com o contexto adicional do estacionamento.

5. Resumo Geral do Modelo

Motorista, Estacionamento e Vaga são entidades principais.

Vaga depende de Estacionamento, formando o relacionamento 1:N.

Gerencia resolve o relacionamento N:N entre Motorista e Vaga, incluindo o estacionamento envolvido, garantindo coerência no gerenciamento de vagas.

O modelo permite controle detalhado de quais motoristas estão associados a quais vagas e em qual estacionamento isso ocorre.

Desenvolvido por:
- Felipe Siller
- Lucas Oliveira
- Iago Colt

