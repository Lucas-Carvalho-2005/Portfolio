-- Gerado por Oracle SQL Developer Data Modeler 24.3.0.240.1210
--   em:        2024-12-08 16:30:01 AMT
--   site:      Oracle Database 11g
--   tipo:      Oracle Database 11g



-- predefined type, no DDL - MDSYS.SDO_GEOMETRY

-- predefined type, no DDL - XMLTYPE

CREATE TABLE cliente (
    idcliente       INTEGER NOT NULL,
    nome            VARCHAR2(100) NOT NULL,
    cpfcnpj         VARCHAR2(14) NOT NULL,
    email           VARCHAR2(100) NOT NULL,
    telefone        VARCHAR2(11) NOT NULL,
    qtdsaidatotal   INTEGER NOT NULL,
    valorsaidatotal NUMBER(10, 2) NOT NULL
);

ALTER TABLE cliente ADD CONSTRAINT cliente_pk PRIMARY KEY ( idcliente );

CREATE TABLE doc_entr (
    iddocentr             INTEGER NOT NULL,
    data                  DATE NOT NULL,
    fornecedr_idfornecedr INTEGER NOT NULL
);

ALTER TABLE doc_entr ADD CONSTRAINT doc_entr_pk PRIMARY KEY ( iddocentr,
                                                              fornecedr_idfornecedr );

CREATE TABLE entr_estoque (
    identradaest                   INTEGER NOT NULL,
    produto_idproduto              INTEGER NOT NULL,
    doc_entr_iddocentr             INTEGER NOT NULL,
    doc_entr_fornecedr_idfornecedr INTEGER NOT NULL
);

ALTER TABLE entr_estoque ADD CONSTRAINT entr_estoque_pk PRIMARY KEY ( identradaest );

CREATE TABLE fornecedr (
    idfornecedr INTEGER NOT NULL,
    nome        VARCHAR2(100) NOT NULL,
    cpfcnpj     VARCHAR2(14) NOT NULL,
    email       VARCHAR2(100) NOT NULL,
    telefone    VARCHAR2(11) NOT NULL
);

ALTER TABLE fornecedr ADD CONSTRAINT fornecedr_pk PRIMARY KEY ( idfornecedr );

CREATE TABLE item_doc_entr (
    iditemdocent              INTEGER NOT NULL,
    doc_entr_iddocentr        INTEGER NOT NULL,
    produto_idproduto         INTEGER NOT NULL,
    doc_entr_idfornecedr      INTEGER NOT NULL,
    entr_estoque_identradaest INTEGER NOT NULL
);

CREATE UNIQUE INDEX item_doc_entr__idx ON
    item_doc_entr (
        entr_estoque_identradaest
    ASC );

ALTER TABLE item_doc_entr ADD CONSTRAINT item_doc_entr_pk PRIMARY KEY ( iditemdocent );

CREATE TABLE item_ped_compra (
    iditempedcomp        INTEGER NOT NULL,
    quantidade           INTEGER NOT NULL,
    precounitario        INTEGER NOT NULL,
    ped_compra_idpedcomp INTEGER NOT NULL,
    produto_idproduto    INTEGER NOT NULL
);

ALTER TABLE item_ped_compra ADD CONSTRAINT item_ped_compra_pk PRIMARY KEY ( iditempedcomp );

CREATE TABLE item_pedido (
    iditempedido      INTEGER NOT NULL,
    quantidade        INTEGER NOT NULL,
    precounitario     NUMBER(10, 2) NOT NULL,
    produto_idproduto INTEGER NOT NULL,
    pedido_idpedido   INTEGER NOT NULL
);

ALTER TABLE item_pedido ADD CONSTRAINT item_pedido_pk PRIMARY KEY ( iditempedido );

CREATE TABLE ped_compra (
    idpedcomp             INTEGER NOT NULL,
    data                  DATE NOT NULL,
    fornecedr_idfornecedr INTEGER NOT NULL
);

ALTER TABLE ped_compra ADD CONSTRAINT ped_compra_pk PRIMARY KEY ( idpedcomp );

CREATE TABLE pedido (
    idpedido          INTEGER NOT NULL,
    data              DATE NOT NULL,
    cliente_idcliente INTEGER NOT NULL
);

ALTER TABLE pedido ADD CONSTRAINT pedido_pk PRIMARY KEY ( idpedido );

CREATE TABLE produto (
    idproduto                  INTEGER NOT NULL,
    nome                       VARCHAR2(50) NOT NULL,
    descricao                  VARCHAR2(200) NOT NULL,
    qtdminest                  INTEGER NOT NULL,
    qtdatualest                INTEGER NOT NULL,
    tempopermest               DATE NOT NULL,
    tipo_produto_idtipoproduto INTEGER NOT NULL
);

ALTER TABLE produto ADD CONSTRAINT produto_pk PRIMARY KEY ( idproduto );

CREATE TABLE tipo_produto (
    idtipoproduto INTEGER NOT NULL,
    nome          VARCHAR2(20) NOT NULL
);

ALTER TABLE tipo_produto ADD CONSTRAINT tipo_produto_pk PRIMARY KEY ( idtipoproduto );

CREATE TABLE tipo_saida (
    idtiposaída     INTEGER NOT NULL,
    nome            INTEGER NOT NULL,
    pedido_idpedido INTEGER NOT NULL
);

ALTER TABLE tipo_saida ADD CONSTRAINT tipo_saida_pk PRIMARY KEY ( idtiposaída );

CREATE TABLE usuario (
    idusuario INTEGER NOT NULL,
    nome      VARCHAR2(50) NOT NULL,
    cpf       VARCHAR2(11) NOT NULL,
    email     VARCHAR2(100) NOT NULL,
    telefone  VARCHAR2(11) NOT NULL,
    apelido   VARCHAR2(20) NOT NULL,
    senha     VARCHAR2(20) NOT NULL
);

ALTER TABLE usuario ADD CONSTRAINT usuario_pk PRIMARY KEY ( idusuario );

ALTER TABLE doc_entr
    ADD CONSTRAINT doc_entr_fornecedr_fk FOREIGN KEY ( fornecedr_idfornecedr )
        REFERENCES fornecedr ( idfornecedr );

ALTER TABLE entr_estoque
    ADD CONSTRAINT entr_estoque_doc_entr_fk
        FOREIGN KEY ( doc_entr_iddocentr,
                      doc_entr_fornecedr_idfornecedr )
            REFERENCES doc_entr ( iddocentr,
                                  fornecedr_idfornecedr );

ALTER TABLE entr_estoque
    ADD CONSTRAINT entr_estoque_produto_fk FOREIGN KEY ( produto_idproduto )
        REFERENCES produto ( idproduto );

ALTER TABLE item_doc_entr
    ADD CONSTRAINT item_doc_entr_doc_entr_fk
        FOREIGN KEY ( doc_entr_iddocentr,
                      doc_entr_idfornecedr )
            REFERENCES doc_entr ( iddocentr,
                                  fornecedr_idfornecedr );

ALTER TABLE item_doc_entr
    ADD CONSTRAINT item_doc_entr_entr_estoque_fk FOREIGN KEY ( entr_estoque_identradaest )
        REFERENCES entr_estoque ( identradaest );

ALTER TABLE item_doc_entr
    ADD CONSTRAINT item_doc_entr_produto_fk FOREIGN KEY ( produto_idproduto )
        REFERENCES produto ( idproduto );

ALTER TABLE item_ped_compra
    ADD CONSTRAINT item_ped_compra_ped_compra_fk FOREIGN KEY ( ped_compra_idpedcomp )
        REFERENCES ped_compra ( idpedcomp );

ALTER TABLE item_ped_compra
    ADD CONSTRAINT item_ped_compra_produto_fk FOREIGN KEY ( produto_idproduto )
        REFERENCES produto ( idproduto );

ALTER TABLE item_pedido
    ADD CONSTRAINT item_pedido_pedido_fk FOREIGN KEY ( pedido_idpedido )
        REFERENCES pedido ( idpedido );

ALTER TABLE item_pedido
    ADD CONSTRAINT item_pedido_produto_fk FOREIGN KEY ( produto_idproduto )
        REFERENCES produto ( idproduto );

ALTER TABLE ped_compra
    ADD CONSTRAINT ped_compra_fornecedr_fk FOREIGN KEY ( fornecedr_idfornecedr )
        REFERENCES fornecedr ( idfornecedr );

ALTER TABLE pedido
    ADD CONSTRAINT pedido_cliente_fk FOREIGN KEY ( cliente_idcliente )
        REFERENCES cliente ( idcliente );

ALTER TABLE produto
    ADD CONSTRAINT produto_tipo_produto_fk FOREIGN KEY ( tipo_produto_idtipoproduto )
        REFERENCES tipo_produto ( idtipoproduto );

ALTER TABLE tipo_saida
    ADD CONSTRAINT tipo_saida_pedido_fk FOREIGN KEY ( pedido_idpedido )
        REFERENCES pedido ( idpedido );



-- Relatório do Resumo do Oracle SQL Developer Data Modeler: 
-- 
-- CREATE TABLE                            13
-- CREATE INDEX                             1
-- ALTER TABLE                             27
-- CREATE VIEW                              0
-- ALTER VIEW                               0
-- CREATE PACKAGE                           0
-- CREATE PACKAGE BODY                      0
-- CREATE PROCEDURE                         0
-- CREATE FUNCTION                          0
-- CREATE TRIGGER                           0
-- ALTER TRIGGER                            0
-- CREATE COLLECTION TYPE                   0
-- CREATE STRUCTURED TYPE                   0
-- CREATE STRUCTURED TYPE BODY              0
-- CREATE CLUSTER                           0
-- CREATE CONTEXT                           0
-- CREATE DATABASE                          0
-- CREATE DIMENSION                         0
-- CREATE DIRECTORY                         0
-- CREATE DISK GROUP                        0
-- CREATE ROLE                              0
-- CREATE ROLLBACK SEGMENT                  0
-- CREATE SEQUENCE                          0
-- CREATE MATERIALIZED VIEW                 0
-- CREATE MATERIALIZED VIEW LOG             0
-- CREATE SYNONYM                           0
-- CREATE TABLESPACE                        0
-- CREATE USER                              0
-- 
-- DROP TABLESPACE                          0
-- DROP DATABASE                            0
-- 
-- REDACTION POLICY                         0
-- 
-- ORDS DROP SCHEMA                         0
-- ORDS ENABLE SCHEMA                       0
-- ORDS ENABLE OBJECT                       0
-- 
-- ERRORS                                   0
-- WARNINGS                                 0
