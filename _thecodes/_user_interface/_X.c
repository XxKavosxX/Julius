///*
// * _X.c
// *
// *  Created on: 10 de mar de 2017
// *      Author: maike_rodrigo
// */
//#include "_X.h"
//const char trinta_s[] PROGMEM = "30 seg" ;
//const char um_m[] PROGMEM = "01 min";
//const char tres_m[] PROGMEM = "03 min";
//const char cinco_m[] PROGMEM = "05 min";
//const char dez_m[] PROGMEM = "10 min";
//const char quinze_m[] PROGMEM = "15 min";
//const char vinte_m[] PROGMEM = "20 min";
//const char trinta_m[] PROGMEM = "30 min";
//const char uma_h[] PROGMEM = "01 hor";
//const char duas_h[] PROGMEM = "02 hrs";
//
//PGM_P const timers[10] PROGMEM = {
//    trinta_s,
//    um_m,
//    tres_m,
//    cinco_m,
//    dez_m,
//    quinze_m,
//    vinte_m,
//    trinta_m,
//    uma_h,
//    duas_h
//};
//
//
//const char emuso[8] PROGMEM = "ocupada";
//const char disponivel[6] PROGMEM = "livre";
//PGM_P const status_pin[2] PROGMEM = {
//    emuso,
//    disponivel
//};
//const char zero[] PROGMEM = "0";
//const char um[] PROGMEM = "1";
//const char dois[] PROGMEM = "2";
//const char tres[] PROGMEM = "3";
//const char quatro[] PROGMEM = "4";
//const char cinco[] PROGMEM = "5";
//const char seis[] PROGMEM = "6";
//const char sete[] PROGMEM = "7";
//const char oito[] PROGMEM = "8";
//
//PGM_P const numeros_inteiros[9] PROGMEM = {
//    zero,
//    um,
//    dois,
//    tres,
//    quatro,
//    cinco,
//    seis,
//    sete,
//    oito
//};
//
//
//const char verCons[9] PROGMEM = "Consumo\0";
//const char disp[11] PROGMEM = "Gerenciar\0";
//const char config[12] PROGMEM = "Configurar\0";
//const char hora[6] PROGMEM = "Hora";
//void (*p_menu_princ[4])() = {Construtor_VerConsumo, Construtor_Dispositivos, Construtor_Configurar, Construtor_Hora};
//
//PGM_P const mat_menuprinc[4] PROGMEM = {
//    verCons,
//    disp,
//    config,
//    hora
//};
//
//
//const char adicionar[11] PROGMEM = "Adicionar\0";
//const char remover[9] PROGMEM = "Remover\0";
//const char modificar[11] PROGMEM = "Modificar\0";
//const char informacao[11] PROGMEM = "Detalhes";
//void (*p_submenu_disp[4])() = {Construtor_AdicionarUI, Construtor_RemoverUI, Construtor_ModificarUI, Construtor_Detalhes};
//
//PGM_P const mat_tela_Dispositivos[4] PROGMEM = {
//    adicionar,
//    remover,
//    modificar,
//    informacao
//};
//
//
//
//const char adc_nome[9] PROGMEM = "Nome/ID\0";
//const char adc_sensor[15] PROGMEM = "Sensor/Comodo\0";
//const char adc_atuador[16] PROGMEM = "Atuador/Comodo\0";
//const char adc_timer[9] PROGMEM = "Timer\0";
//const char adc_salvar[7] PROGMEM = "Salvar";
//const char adc_mudar[10] PROGMEM = "Modificar";
//void (*p_adicionar[5])() = {Nome, Sensor, Atuador, Timer, Salvar};
//void (*p_modificar[5])() = {Nome, Sensor, Atuador, Timer, Modificar};
//PGM_P const mat_tela_adicionar[5] PROGMEM = {
//    adc_nome,
//    adc_sensor,
//    adc_atuador,
//    adc_timer,
//    adc_salvar
//};
//PGM_P const mat_tela_modificar[5] PROGMEM = {
//    adc_nome,
//    adc_sensor,
//    adc_atuador,
//    adc_timer,
//    adc_mudar
//};
//
//const char up_case_alfa[17] PROGMEM = "ABCDEFGHIJKLMNOP";
//const char up_case_alfa2[17] PROGMEM = "QRSTUVXYWZ./   X";
//const char numeros[17] PROGMEM = "123456789      S";
//void (*p_adicionando_nome[2])() = {_btnAddLetra, _btnDelLetra};
//
//PGM_P const teclado[3] PROGMEM = {
//    up_case_alfa,
//    up_case_alfa2,
//    numeros
//};
///////////////////////////////////////////////////
////////////SIMULACAO DE SENSORES ADICIONADOS
//const char quarto1[12] PROGMEM = "Meu Quarto\0";
//const char sala[15] PROGMEM = "Sala de estar\0";
//const char quarto2[14] PROGMEM = "Quarto Math.\0";
//const char corredor[9] PROGMEM = "Corredor";
//PGM_P const sensores[4] PROGMEM = {
//    quarto1,
//    sala,
//    quarto2,
//    corredor
//};
//static void (*p_select_sensor[1])() = {CDS_SelecSensor};
//static void (*p_select_atuador[1])() = {CDA_SelecAtuador};
//static void (*p_select_timer[1])() = {CDT_SelecTimer};
//
//void (*p_remove[1])() = {Remover};
//void (*p_muda[1])() = {Modifica};
//////////////////////////////////////////////////////
/////////////VARI�VEIS DE CONTAGEM/////////
//static uint8_t cont_lin_menus=0;
//static uint8_t cont_col_menus=0;
//static uint8_t MENU_ATUAL= MENU_PRINCIPAL;
//static uint8_t MAX_LIN_MENU=0;
//static uint8_t MAX_COL_MENU=0;
//uint8_t PASSO_ADICIONAR_APARELHO = 0;
///////////////////////////////////////////
//char mat_geral[14][16]; //MATRIZ QUE ARMAZENAR� OS TEXTOS DE CADA MENU
//
//////////////////////////////////////////
//////////////////////////////////////////
//void (**Comando)();   //PONTEIRO PARA PONTEIRO QUE ARMAZENARA O PONTEIRO PARA FUNCOES DE CADA TELA
//////////////////////////////////////////
//
//char nome_digitado_buffer[13];
//uint8_t defaultTimer_Aux;
//uint8_t indice_atuador_Aux;
//uint8_t indice_sensor_Aux;
//uint8_t disp_consumo_Aux;
//char nome_aparelho_Aux[13];
//
//void InicializarTela(){
//    ConstruirTela(sizeof(mat_menuprinc)/sizeof(mat_menuprinc[0]), mat_menuprinc);//ATUALIZA A TELA PARA A DO MENU PRINCIPAL
//    MENU_ATUAL = MENU_PRINCIPAL;
//    Comando = p_menu_princ;                 //ATUALIZA O VETOR DE COMANDOS PARA O DO MENU PRINCIPAL
//
//}
//void ConstruirTela(uint8_t numeroDeStrings, PGM_P const *mat, ...){
//    uint8_t ct = numeroDeStrings;
//    do{
//        --ct;
//        PGM_P progmem_P;
//        memcpy_P( &progmem_P, &(mat[ct]), sizeof(PGM_P));
//        strncpy_P(mat_geral[ct], progmem_P, 16);
//    }while (ct);
//    //Reinicia o contador das linhas e colunas
//    cont_col_menus=0;
//    cont_lin_menus=0;
//    //Copia o valor de m�ximo e m�nimo das linhas
//    MAX_LIN_MENU = numeroDeStrings-1;
//    MAX_COL_MENU = 0;
//    AtualizarTela(0);
//}
////void ConstruirTela(uint8_t numeroDeStrings, char** mat){
////    uint8_t ct = numeroDeStrings;
////    do{
////        --ct;
////        strncpy(mat_geral[ct],mat[ct], 16);
////    } while (ct);
////    cont_col_menus=0;
////    cont_lin_menus=0;
////    MAX_LIN_MENU = numeroDeStrings-1;
////    MAX_COL_MENU = 0;
////    AtualizarTela(0);
////}
//void AtualizarTela(uint8_t modo){
//    //FUN��O RESPONS�VEl POR ATUALIZAR A O VISUAL DA TELA
//    LimparLCD();
//    switch (modo){
//        case 0:
//        if (cont_lin_menus%2 == 0){
//            if (MAX_LIN_MENU != 0)
//            {
//                if ((cont_lin_menus == MAX_LIN_MENU)){
//
//                    RetornaCursor();
//                    EscreverLcd(mat_geral[cont_lin_menus-1]);
//                    SetCursor(1,0);
//                    EscreverLcd(mat_geral[cont_lin_menus]);
//                    EscreveLcdFlash(PSTR("<"));
//                    }else{
//
//                    RetornaCursor();
//                    EscreverLcd(mat_geral[cont_lin_menus]);
//                    EscreveLcdFlash(PSTR("<"));
//                    SetCursor(1,0);
//                    EscreverLcd(mat_geral[cont_lin_menus+1]);
//                }
//                }else{
//
//                RetornaCursor();
//                EscreverLcd(mat_geral[cont_lin_menus]);
//                EscreveLcdFlash(PSTR("<"));
//            }
//            }else{
//
//            RetornaCursor();
//            EscreverLcd(mat_geral[cont_lin_menus-1]);
//            SetCursor(1,0);
//            EscreverLcd(mat_geral[cont_lin_menus]);
//            EscreveLcdFlash(PSTR("<"));
//        }
//        break;
//        case 1:
//        RetornaCursor();
//        EscreverLcd(nome_digitado_buffer);
//        SetCursor(1,0);
//        EscreverLcd(mat_geral[cont_lin_menus]);
//        LigarCursor();
//        break;
//    }
//}
//void FuncoesTeclado(){
//
//    if (cont_lin_menus>=0 && cont_lin_menus<=MAX_LIN_MENU)
//    {
//        if((MENU_ATUAL == MENU_PRINCIPAL) | (MENU_ATUAL == CONSUMO)|(MENU_ATUAL == GERENCIAR)|(MENU_ATUAL == ADICIONAR)|(MENU_ATUAL == MODIFICAR)|(MENU_ATUAL == CONFIGURACOES)|(MENU_ATUAL == HORA)){
//            if (Comando != NULL){
//                Comando[cont_lin_menus]();
//                EscreveUsartFlash(PSTR("Op1\n"));
//            }
//        }else{
//
//            if(MENU_ATUAL ==  NOME_ESCREVENDO){
//            	EscreveUsartFlash(PSTR("Op2"));
//            //cont_lin_menus pode ser :
//            //Nome
//            //Sensor
//            //Atuador
//            //Timer
//            //Salvar
//            //Chama uma das fun��es acima, no click do bot�o "Ok"
//            switch (cont_lin_menus){
//                case 0:
//                Comando[0]();
//                break;
//                case 1:
//                if (cont_col_menus<11){
//                    //EscreveUsartFlash(PSTR("Salvar uma letra \n\0"));
//                    //Seleciona uma letra
//                    Comando[0]();
//                }
//                if (cont_col_menus==15){
//                    //EscreveUsartFlash(PSTR("Apagar uma letra \n\0"));
//                    //Apaga uma letra
//                    Comando[1]();
//                }
//                break;
//                case 2:
//                if (cont_col_menus<9){
//                    //EscreveUsartFlash(PSTR("Salvar um numero \n\0"));
//                    Comando[0]();
//                }
//                if (cont_col_menus==15){
//                    //EscreveUsartFlash(PSTR("Salvar o nome \n\0"));
//                    LimparLCD();
//                    EscreverLcd(nome_digitado_buffer);
//                    //EscreveLcdFlash(PSTR("           Salvo\0"));
//                    _delay_ms(500);
//                    Voltar();
//                }
//                break;
//            }
//
//            }
//            else{
//                 if(MENU_ATUAL |= SELECIONANDO_OPCAO|REMOVENDO|MODIFICANDO){
//                	 EscreveUsartFlash(PSTR("Op3"));
//                	 Comando[0]();
//                 }
//            }
//        }
//    }
//}
//void Voltar(){
//    EscreveUsartFlash(PSTR("Entrou Voltar\n"));
//    if((MENU_ATUAL == MENU_PRINCIPAL) | (MENU_ATUAL == CONSUMO)|(MENU_ATUAL == GERENCIAR)|(MENU_ATUAL == CONFIGURACOES)|(MENU_ATUAL == HORA)){
//
//		ConstruirTela(sizeof(mat_menuprinc)/sizeof(mat_menuprinc[0]), mat_menuprinc);
//	    Comando = p_menu_princ;
//	    EscreveUsartFlash(PSTR("Opcao1\n"));
//	    TransmiteUsart(MENU_ATUAL+48);
//	    MENU_ATUAL = MENU_PRINCIPAL;
//	    TransmiteUsart(MENU_ATUAL+48);
//    }else{
//    	if((MENU_ATUAL == ADICIONAR)|(MENU_ATUAL == REMOVER)|(MENU_ATUAL == REMOVENDO)|(MENU_ATUAL == MODIFICAR)|(MENU_ATUAL == MODIFICANDO)|(MENU_ATUAL == VER_INFO)|(MENU_ATUAL == MODIFICANDO)){
//    		ConstruirTela(sizeof(mat_tela_Dispositivos)/sizeof(mat_tela_Dispositivos[0]), mat_tela_Dispositivos);
//    		Comando = p_submenu_disp;
//    		TransmiteUsart(MENU_ATUAL+48);
//    		EscreveUsartFlash(PSTR("Opcao2\n"));
//    		MENU_ATUAL = GERENCIAR;
//    		TransmiteUsart(MENU_ATUAL);
//    	}else{
//             if((MENU_ATUAL == SELECIONANDO_OPCAO)|(MENU_ATUAL == NOME_ESCREVENDO)){
//                  ConstruirTela(sizeof(mat_tela_adicionar)/sizeof(mat_tela_adicionar[0]),mat_tela_adicionar);
//                  DesligarCursor();
//                  EscreveUsartFlash(PSTR("Opcao3\n"));
//                  Comando = p_adicionar;
//                  MENU_ATUAL = ADICIONAR;
//             }
//    	}
//    }
//}
//void Construtor_VerConsumo(){
//    EscreveUsartFlash(PSTR("Ver Consumo->"));
//    MENU_ATUAL = CONSUMO;
//    Comando = NULL;
//    CarregarConsumo();
//    AtualizarTela(0);
//}
//bool CarregarConsumo(){
//    //TROCAR ISSO POR UMA VERIFICACAO A CADA SCROLL NO TECLADO. A CADA SCROLL PUXA OUTRO CONSUMO DA MEMORIA
//    //N�o constr�i tudo por causa da falta de espa�o em mat geral
//     static uint8_t n_aparelhos=0;
//     n_aparelhos = getNAparelhos();
//     TransmiteUsart('\n');
//     EscreveUsartFlash(PSTR("Numero: "));
//     TransmiteUsart(n_aparelhos+48);
//     TransmiteUsart('\n');
//    char **mat_consumo;
//    mat_consumo = CriarMatriz(n_aparelhos, 13) ;
//    if (mat_consumo != NULL){
//         EscreveUsartFlash(PSTR("criando matriz de consumo:\t"));
//        uint8_t count = 0;
//        for (uint8_t i=0; i<16;i++){
//            Device aparelho_da_lista = getAparelhos(i);
//            char* aux;
//            aux = strstr_P(aparelho_da_lista.device_getName,VAZIO);
//            if ((strncmp_P(aux, VAZIO, 7) != 0)){
//                EscreveUsartFlash(PSTR("Adicionando um aparelho nao nulo, "));
//                TransmiteUsart('\n');
//                strncat(mat_consumo[count], aparelho_da_lista.device_getName, 12);
//                strncat(mat_consumo[count],  LongParaChar(aparelho_da_lista.device_getName),4);
//                count=count+1;
//            }else{
//                EscreveUsartFlash(PSTR("aparelho nulo, "));
//                TransmiteUsart('\n');
//            }
//        }
//        ConstruirTela(n_aparelhos , mat_consumo);
//        //free(mat_consumo);
//        return true;
//        }else{
//        SetCursor(0,0);
//        EscreveLcdFlash(PSTR(" Nenhum Aparelho"));
//        SetCursor(1,0);
//        EscreveLcdFlash(PSTR("foi adicionado  "));
//        _delay_ms(1500);
//        Voltar();
//        return false;
//    }
//}
//char** CriarMatriz(uint8_t numerolinhas, uint8_t numerocolunas){
//    //cria uma matriz dinamicamente
//    //Tenta alocar as linhas
//
//    if (numerolinhas>!0){
//
//        char **m = (char**)malloc(numerolinhas * sizeof(char*)); //Aloca um Vetor de Ponteiros
//
//        for (uint8_t i = 0; i < numerolinhas; i++){ //Percorre as linhas do Vetor de Ponteiros
//
//            m[i] = (char*) malloc(numerocolunas * sizeof(char)); //Aloca um Vetor de Inteiros para cada posi��o do Vetor de Ponteiros.
//            for (uint8_t j = 0; j < numerocolunas; j++){ //Percorre o Vetor de Inteiros atual.
//
//                m[i][j] = 0; //Inicializa com 0.
//            }
//        }
//
//        if (m == NULL){
//            EscreveUsartFlash(PSTR("Erro ao criar matriz\n"));
//            return NULL;
//            }else{
//            return m;
//        }
//    }
//    return NULL;
//}
//void Construtor_Dispositivos(){
//	EscreveUsartFlash(PSTR("Entrou Dispositivos->"));
//    MENU_ATUAL = GERENCIAR;
//    ConstruirTela(sizeof(mat_tela_Dispositivos)/sizeof(mat_tela_Dispositivos[0]), mat_tela_Dispositivos);
//    AtualizarTela(0);
//    Comando = p_submenu_disp;
//}
//void Construtor_AdicionarUI(){
//    EscreveUsartFlash(PSTR("Adicionar Dispositivo->"));
//    MENU_ATUAL = ADICIONAR;
//    ConstruirTela(sizeof(mat_tela_adicionar)/sizeof(mat_tela_adicionar[0]), mat_tela_adicionar);
//    AtualizarTela(0);
//    Comando = p_adicionar;
//}
//void Nome(){
//    EscreveUsartFlash(PSTR("Adicionar Nome->"));
//    MENU_ATUAL = NOME_ESCREVENDO;
//    ConstruirTela(sizeof(teclado)/sizeof(teclado[0]), teclado);
//    LigarCursor();
//    Comando = p_adicionando_nome;
//    AtualizarTela(1);
//    TransmiteUsart(MENU_ATUAL+48);
//}
//void _btnAddLetra(){
//    EscreveUsartFlash(PSTR("Atualizar Dado Digitado\n"));
//
//    if ((strlen(nome_digitado_buffer)<12)){
//        strncat(nome_digitado_buffer, &mat_geral[cont_lin_menus][cont_col_menus] , 1);
//        if (PASSO_ADICIONAR_APARELHO == 0)
//        {
//            PASSO_ADICIONAR_APARELHO++;
//        }
//        RetornaCursor();
//        EscreverLcd(nome_digitado_buffer);
//        SetCursor(1,cont_col_menus);
//        LigarCursor();
//    }
//}
//void _btnDelLetra(){
//    EscreveUsartFlash(PSTR("Apagar Dado Digitado\n"));
//    if ((strlen(nome_digitado_buffer)>0)) {
//        nome_digitado_buffer[(strlen(nome_digitado_buffer)-1)] = '\0';
//        RetornaCursor();
//        EscreveLcdFlash(PSTR("                \0"));
//        RetornaCursor();
//        EscreverLcd(nome_digitado_buffer);
//        SetCursor(1,cont_col_menus);
//        LigarCursor();
//    }
//}
//void Sensor(){
//    EscreveUsartFlash(PSTR("Adicionar Sensor->"));
//    MENU_ATUAL = SELECIONANDO_OPCAO;
//    ConstruirTela(sizeof(sensores)/sizeof(sensores[0]), sensores);
//    AtualizarTela(0);
//    Comando = p_select_sensor;
//}
//void CDS_SelecSensor(){
//    EscreveUsartFlash(PSTR("Sensor selecionado\n"));
//    LimparLCD();
//    EscreveLcdFlash((const char*)pgm_read_word(&sensores[cont_lin_menus]));
//    SetCursor(1,0);
//    EscreveLcdFlash(PSTR("           Salvo\0"));
//    indice_sensor_Aux = cont_lin_menus;
//     TransmiteUsart(indice_sensor_Aux+48);
//     TransmiteUsart('\n');
//
//    _delay_ms(500);
//    Voltar();
//}
//void Atuador(){
//    EscreveUsartFlash(PSTR("Adicionar Atuador->"));
//    MENU_ATUAL = SELECIONANDO_OPCAO;
//    Comando = NULL;
//    if (indice_sensor_Aux<2){
//        EscreveUsartFlash(PSTR("Entrou atuador if 1"));
//
//        char **mat_atuadores;
//        uint8_t i = 8; //getNumeroDeAparelhosConfigurados();
//        mat_atuadores = CriarMatriz(8, 14);
//        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//        if(mat_atuadores!=NULL){
//             EscreveUsartFlash(PSTR("Entrou atuador if 2"));
//            char (*disp_conec)[8] = getAparelhosConectados();
//            //             char pont[8];
//            //             strncpy(pont, disp_conec[adc_disp_aux.indice_sensor], 8);
//
//            do {
//                --i;
//
//                if ( disp_conec[indice_sensor_Aux][i] == '\0'){
//                    strncat_P(mat_atuadores[i], PSTR("Porta "), 7);
//                    strncat_P(mat_atuadores[i],  (PGM_P)pgm_read_word(&(numeros_inteiros[i])),3);
//                    strncat_P(mat_atuadores[i], PSTR(":"),2);
//                    strncat_P(mat_atuadores[i], (PGM_P)pgm_read_word(&(status_pin[1])),11);
//                    } else {
//                    strncat_P(mat_atuadores[i], PSTR("Porta "), 7);
//                    strncat_P(mat_atuadores[i],  (PGM_P)pgm_read_word(&(numeros_inteiros[i])),3);
//                    strncat_P(mat_atuadores[i], PSTR(":"),2);
//                    strncat_P(mat_atuadores[i], (PGM_P)pgm_read_word(&(status_pin[0])), 14);
//
//                }
//
//            } while (i);
//
//            ConstruirTela(8, (char**)mat_atuadores);
//            AtualizarTela(0);
//            Comando = p_select_atuador;
//        }
//    }else{
//      EscreveUsartFlash(PSTR("DEU RUIM"));
//      Voltar();
//    }
//}
//void CDA_SelecAtuador(){
//
//    char s[16];
//    strncpy(s, mat_geral[cont_lin_menus], 15);
//    char *aux;
//
//    aux = strstr(s, "livre\0");
//
//    if (strncmp_P(aux, "livre\0", 5) == 0){
//    EscreveUsartFlash(PSTR("Atuador Selecionado\n"));
//    char n[10];
//    LimparLCD();
//    EscreveLcdFlash(PSTR("Atuador: "));
//    EscreverLcd(itoa(cont_lin_menus, n ,10));
//    SetCursor(1,0);
//    EscreveLcdFlash(PSTR("     Selecionado\0"));
//    indice_atuador_Aux = cont_lin_menus;
//    _delay_ms(500);
//    Voltar();
//    }else{
//      char n[10];
//      LimparLCD();
//      EscreveLcdFlash(PSTR("Porta:"));
//      EscreverLcd(itoa(cont_lin_menus, n ,10));
//      SetCursor(1,0);
//      EscreveLcdFlash(PSTR("ocupada\0"));
//      _delay_ms(500);
//      AtualizarTela(0);
//    }
//
//}
//void Timer(){
//    EscreveUsartFlash(PSTR("Adicionar Timer->"));
//    MENU_ATUAL = SELECIONANDO_OPCAO;
//    ConstruirTela(sizeof(timers)/sizeof(timers[0]), timers);
//    AtualizarTela(0);
//    Comando = p_select_timer;
//}
//void CDT_SelecTimer(){
//    EscreveUsartFlash(PSTR("Timer Selecionado\n"));
//    LimparLCD();
//    EscreveLcdFlash(PSTR("Timer: "));
//    EscreveLcdFlash((char*)pgm_read_word(&(timers[cont_lin_menus])));
//    SetCursor(1,0);
//    EscreveLcdFlash(PSTR("     Selecionado\0"));
//    defaultTimer_Aux = cont_lin_menus;
//    _delay_ms(500);
//     Voltar();
//}
//void Construtor_RemoverUI(){
//    EscreveUsartFlash(PSTR("Remover->\n"));
//    MENU_ATUAL = REMOVER;
//    Comando = NULL;
//    ListarDispositivos(REMOVENDO, p_remove);
//    AtualizarTela(0);
//}
//void Remover(){
//    RemoverAparelhoRegistrado(mat_geral[cont_lin_menus]);
//    AtualizarTela(0);
//    Voltar();
//}
//bool ListarDispositivos(const int menu, void (**funcoes_da_tela)()){
//    //TROCAR ISSO POR UMA VERIFICACAO A CADA SCROLL NO TECLADO. A CADA SCROLL PUXA OUTRO CONSUMO DA MEMORIA
//    uint8_t n_aparelhos = 0;
//    n_aparelhos = getNAparelhos();
//    TransmiteUsart('\n');
//    EscreveUsartFlash(PSTR("Numero: "));
//    TransmiteUsart(n_aparelhos+48);
//    TransmiteUsart('\n');
//    char **mat_listardispositivos;
//    mat_listardispositivos = CriarMatriz(n_aparelhos, 13) ;
//    if (mat_listardispositivos != NULL){
//        uint8_t count = 0;
//        //Varre a lista
//        for (uint8_t i=0; i<16;i++){
//            Device aparelho_da_lista = getAparelhos(i);
//            char* aux;
//            aux = strstr_P(aparelho_da_lista.device_getName,VAZIO);
//            if ((strncmp_P(aux, VAZIO, 7) != 0)){
//                EscreveUsartFlash(PSTR("Adicionando um aparelho nao nulo, "));
//                TransmiteUsart('\n');
//                strncpy(mat_listardispositivos[count], aparelho_da_lista.device_getName, 12);
//                count++;
//            }else{
//            EscreveUsartFlash(PSTR("aparelho nulo, "));
//            TransmiteUsart('\n');
//          }
//        }
//        ConstruirTela(n_aparelhos , mat_listardispositivos);
//        MENU_ATUAL = menu;
//        Comando = funcoes_da_tela;
//        return true;
//    }else{
//       SetCursor(0,0);
//       EscreveLcdFlash(PSTR(" Nenhum Aparelho"));
//       SetCursor(1,0);
//       EscreveLcdFlash(PSTR("foi adicionado  "));
//       _delay_ms(1500);
//       Voltar();
//       return false;
//    }
//}
////Inicia a tela de modifica��o
//void Construtor_ModificarUI(){
//    MENU_ATUAL = MODIFICAR;
//    Comando = NULL;
//    ListarDispositivos(MODIFICANDO, p_muda);
//    AtualizarTela(0);
//}
////Comando para modificar
//void Modifica(){
//    strncpy(nome_aparelho_Aux, mat_geral[cont_lin_menus], 13);
//    ConstruirTela(sizeof(mat_tela_modificar)/sizeof(mat_tela_modificar[0]), mat_tela_modificar);
//    AtualizarTela(0);
//    Comando = p_modificar;
//}
//void Construtor_Detalhes(){
//    MENU_ATUAL = VER_INFO;
//    Comando = NULL;
//}
//void Construtor_Configurar(){
//    MENU_ATUAL = CONFIGURACOES;
//    Comando = NULL;
//}
//void Construtor_Hora(){
//    MENU_ATUAL = HORA;
//    Comando = NULL;
//    //printarHorario();
//}
//
//void Salvar(){
//    Device aux_novoAparelho(defaultTimer_Aux, indice_atuador_Aux, indice_sensor_Aux, nome_digitado_buffer, 0);
//    if ( RegistrarAparelho(aux_novoAparelho))
//    {
//        LimparLCD();
//        SetCursor(1,11);
//        EscreveLcdFlash(PSTR("Salvo"));
//        CarregarDispositivosRAM();
//        _delay_ms(500);
//        Voltar();
//    }
//    else{
//        LimparLCD();
//        SetCursor(1,7);
//        EscreveLcdFlash(PSTR("Nao Salvo"));
//        _delay_ms(500);
//        Voltar();
//    }
//    Voltar();
//}
//void Modificar(){
//
//    Device attApa(defaultTimer_Aux, indice_atuador_Aux, indice_sensor_Aux, nome_digitado_buffer, 0);
//
//    AtualizarRegistroAparelho(nome_aparelho_Aux, attApa) ;
//    EscreveUsartFlash(PSTR("Atualizou!\0"));
//    LimparLCD();
//    SetCursor(1,6);
//    EscreveLcdFlash(PSTR("Atualizado"));
//    _delay_ms(500);
//    Voltar();
//}
//void _TecladoLCD(unsigned char botaoclicado){
//    WatchDogResetar();
//    EscreveUsartFlash(PSTR("Entrou INT\n"));
//    switch (botaoclicado)
//    {
//        case 62: //DECREMENTA AS COLUNAS
//            if (cont_col_menus == 0){
//            cont_col_menus = 15;
//            }
//            else{
//            decr(cont_col_menus, 0);
//            }
//            if (MENU_ATUAL == NOME_ESCREVENDO){
//            SetCursor(1,cont_col_menus);
//            }
//            else{
//            AtualizarTela(0);
//        }
//        break;
//        case 61://INCREMENTA AS COLUNAS
//            if (cont_col_menus == 15){
//            cont_col_menus = 0;
//            }else{
//            incr(cont_col_menus, 15);
//            }
//            if (MENU_ATUAL == NOME_ESCREVENDO){
//            SetCursor(1,cont_col_menus);
//            }else{
//            AtualizarTela(0);
//        }
//        break;
//        case 59://DECREMENTA LINHAS
//            decr(cont_lin_menus, MAX_LIN_MENU);
//            if (MENU_ATUAL == NOME_ESCREVENDO)
//            {
//            AtualizarTela(1);
//            LigarCursor();
//            }
//            else{
//            AtualizarTela(0);
//        }
//        break;
//        case 55://INCREMENTA LINHAS
//            incr(cont_lin_menus, MAX_LIN_MENU);
//            if (MENU_ATUAL == NOME_ESCREVENDO)
//            {
//            AtualizarTela(1);
//            LigarCursor();
//            }
//            else{
//            AtualizarTela(0);
//        }
//        break;
//        case 47:
//            FuncoesTeclado();
//        break;
//        case 31:
//            Voltar();
//        break;
//    }
//    WatchDogResetar();
//    HabilitarNova_UI_Interrupcao(1);
//}
//ISR(INT1_vect){
//    HabilitarNova_UI_Interrupcao(0);
//    sei();
//    char dado = Ler(END_TCLD);
//    if(dado != NULL){
//    unsigned char clk_btn_mascara = 0b00111111 & dado;
//    _TecladoLCD(clk_btn_mascara);
//    }
//}
//void HabilitarInterrupcaoBTN(){
//    //UCSR0B = 0x00;
//
//	EIFR &= (1<<INTF0);
//    EICRA |= (1<<ISC11);                      //INTERRUP��O NA BORDA DE DESCIDA
//    EIMSK |= (1<<INT1);					   //HABILITA INTERRUP��O
//    sei();
//}
//void HabilitarNova_UI_Interrupcao(unsigned char valor){
//    if (valor){
//        EIMSK  |= (1<<INT1);
//    }
//    else{
//        EIMSK &= ~(1<<INT1);
//    }
//}
//
//
//
