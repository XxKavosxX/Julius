///*
// * rotina_principal.cpp
// *
// * Created: 19/10/2016 10:29:19
// *  Author: rodri
// */
// #include "rotina_principal.h"
// volatile unsigned int estado_sensores = 0x0000;
// volatile unsigned int desligar_agora_atuadores;
// volatile unsigned int ultimo_estado_sensores;// = 0b11111111;
//
// TarefaDesligar fila_desligamento[16]; //trabalhando com at� 16 dispositivos ou 2 PCF8574 atuadores
// TarefaDesligar *porta_endereco[16];
// Device dispositivos_conectados[16];
// char ListaDeDispConectados[2][8] = {{'\0'}, {'\0'}};
// unsigned int contador;
// /////////////////=================================///////////////////////
//
// void FormatarLista(){
//
//     for (contador = 0; contador < 16; contador++) {  //Inicia os ponteiros das estruturas
//         porta_endereco[contador] = &fila_desligamento[contador];
//         fila_desligamento[contador].setControlPin(contador);
//     }
// }
// _Bool CarregarDispositivosRAM(){
//
//     int aux_cont = 0;
//
//     Device dispositivo_encontrado;
//
//     for (contador = 0; contador<16; contador++){
//
//         dispositivo_encontrado = BuscarAparelhoEndereco((1+(32*contador)));
//
//         if ((strncmp_P(dispositivo_encontrado.getName(), VAZIO, 7) != 0)){
//
//             switch (dispositivo_encontrado.getSensorPin()){
//
//                 case 0: //SENSOR NA PORTA 0 DO PCF8574 de SENSORES
//                 SetAtuadoresOcupados(0,dispositivo_encontrado.getControlPin(), 1);
//                 EscreveUsartFlash(PSTR("Um aparelho foi encontrado\n"));
//                 ListaDeDispConectados[0][aux_cont] = CONECTADO;
//                 aux_cont++;
//                 dispositivos_conectados[dispositivo_encontrado.getControlPin()] = dispositivo_encontrado;
//                 return true;
//                 //break;
//                 case 1:
//                 SetAtuadoresOcupados(1,dispositivo_encontrado.getControlPin()-8, 1);
//                 EscreveUsartFlash(PSTR("Um aparelho foi encontrado\n"));
//                 ListaDeDispConectados[1][aux_cont] = CONECTADO;
//                 //ListaDeDispConectados[1][aux_cont] = dispositivo_encontrado.indice_atuador;
//                 aux_cont++;
//                 dispositivos_conectados[dispositivo_encontrado.getControlPin()] = dispositivo_encontrado;
//                 return true;
//                 //break;
//             }
//         }
//         EscreveUsartFlash(PSTR("Saindo\n"));
//     }
//     return false;
// }
// void IniciarAtuadores(){
//
//	 //Ligar aparelhos conforme os sensores
//     estado_sensores = 0xFF00 | Ler(END_SEN);
//     ultimo_estado_sensores = 0xFFFF;
//     desligar_agora_atuadores = 0xFFFF;
//     //////////////// ?????????????
//     AtualizarFila(estado_sensores);
//     Escrever(END_ATUADOR1, ultimo_estado_sensores);
//     Escrever(END_ATUADOR2, ultimo_estado_sensores);
//
// }
// /////////////////////////////////////////////////////////////////////////
// //////////////////////========INICIALIZA��O==////////////////////////////
// uint16_t InterrupcaoSensorDisparada() {
//
//     PararContador();
//     HabilitarNovaInterrupcaoSEN(false);
//     EscreveUsartFlash(PSTR("Um sensor deixou de detectar presenca\n"));
//     //////// ??????????????
//     estado_sensores = 0xFF00 | Ler(END_SEN);
//     EscreveUsartFlash(PSTR("Criando fila de desligamento...\n"));
//     return estado_sensores;
// }
//
//_Bool ExecutarDesligamentoAparelho() {
//
//     HabilitarNovaInterrupcaoSEN(false);
//
//     desligar_agora_atuadores &= ~(1<<porta_endereco[fila_desligamento[0].getControlPin()]->getControlPin()) ;
//     switch (porta_endereco[fila_desligamento[0].getControlPin()]->getControlPin()){
//         case 0:
//         EscreveUsartFlash(PSTR("Desligando->"));
//         	 if(Escrever(35, desligar_agora_atuadores)){
//         		EscreveUsartFlash(PSTR("Desligado\n"));
//         		RemoverTarefaDaFila(fila_desligamento[0].getControlPin());
//         		IniciarContadorTarefa();
//         		return true;
//         	 }else{
//         		EscreveUsartFlash(PSTR("Não foi possível Desligar\n"));
//         		RemoverTarefaDaFila(fila_desligamento[0].getControlPin());
//         		IniciarContadorTarefa();
//         		return false;
//         	 }
//         case 1:
//         EscreveUsartFlash(PSTR("Desligando->"));
//         	 if(Escrever(36, desligar_agora_atuadores)){
//         		 EscreveUsartFlash(PSTR("Desligado\n"));
//                 return true;
//         	 }else{
//         		 EscreveUsartFlash(PSTR("Não foi possível Desligar\n"));
//                 return false;
//         	 }
//         	OrganizarFila();
//         	HabilitarNovaInterrupcaoSEN(true);
//     }
//     return false;
// }
// /////////////////////////////////////////////////////////////////////////
// //////////////////////========CENTRAL========////////////////////////////
// void AtualizarFila(unsigned int novo_estado_sensores) {
//	 // Recebe 16 bits, cada um correspondente ao estado atual de um dispositivo
//     EscreveUsartFlash(PSTR("Gerenciando Tarefas...\n"));
//     unsigned int removeFromList;
//     unsigned int addToList;
//     unsigned int add = 0;
//     unsigned int rem = 0;
//
//     addToList = (ultimo_estado_sensores) & (~(novo_estado_sensores));
//     removeFromList = (~(ultimo_estado_sensores)) & (novo_estado_sensores);
//     unsigned int pcounter;
//
//     for (unsigned int contador = 0; contador < 16 ; contador++) {
//         add = addToList & (1 << contador) ;
//         rem = removeFromList & (1 << contador);
//         if (add != 0) { //nos indices em que forem encontrados '1s'
//             pcounter=0;
//             while ( pcounter < 16)
//             {
//                 if (strncmp_P( dispositivos_conectados[pcounter].getName(),VAZIO,  7) !=0)
//                 {
//                    IncluirNovaTarefaNaFila(dispositivos_conectados[pcounter], pcounter);
//                 }
//                 pcounter ++;
//             }
//         }
//         if (rem != 0) {
//             pcounter=0;
//             while ( pcounter < 16)
//             {
//                 if (strncmp_P( dispositivos_conectados[pcounter].getName(),VAZIO,  7) !=0)
//                 {
//                     RemoverTarefaDaFila(pcounter);
//                 }
//                 pcounter ++;
//             }
//         }
//     }
//     ultimo_estado_sensores = novo_estado_sensores;
//     OrganizarFila();
//     IniciarContadorTarefa();
//
// }
// /////////////////////////////////////////////////////////////////////////
// //////////////////////========FERRAMENTAS====////////////////////////////
// void IncluirNovaTarefaNaFila(Device aparelho, unsigned int indice) {
//     //escreve_usart("Entrou no create\n");
//     TarefaDesligar aux_task(aparelho, HorarioParaSegundos());
//     *porta_endereco[indice] = aux_task;
// }
// void RemoverTarefaDaFila(unsigned int indice) {
//     porta_endereco[indice]->resetTarefaDesligar();
// }
// void IniciarContadorTarefa() {
//   //HabilitarNovaInterrupcaoSEN(false);
//   if (fila_desligamento[0].getStatus() != OUTQEUE ) {
//
//     fila_desligamento[0].setCountdownTimer(HorarioParaSegundos()); //Atualiza o timer_to_shutdown setando o timer atual e subtraindo do timer decorrido
//
//     SetTempoDesligamento(fila_desligamento[0].getCountdownTimer()); /*Levando em considera��o que a tempo entre a inclus�o na lista e o start do contador � '0' getCountdownTimer(0)*/
//     IniciarContador();
//   }
//   //HabilitarNovaInterrupcaoSEN(true);
// }
// void OrganizarFila() {
//      EscreveUsartFlash(PSTR("Organizando"));
//      TransmiteUsart('\n');
//     //HabilitarNovaInterrupcaoSEN(false);
//     TarefaDesligar aux_tarefa;
//     TarefaDesligar *aux_tarefa2;
//     for (uint8_t i = 0; i < 14; i++) {
//         for (uint8_t j = i + 1; j < 15; j++) {
//             if (((fila_desligamento[i].getCountdownTimer() >= fila_desligamento[j].getCountdownTimer())&&fila_desligamento[j].getStatus()) ||fila_desligamento[i].getStatus()==0)
//             {
//
//                 aux_tarefa = *porta_endereco[fila_desligamento[i].getControlPin()];
//                 *porta_endereco[fila_desligamento[i].getControlPin()] = *porta_endereco[fila_desligamento[j].getControlPin()];
//                 *porta_endereco[fila_desligamento[j].getControlPin()] = aux_tarefa;
//
//                 aux_tarefa2 = porta_endereco[fila_desligamento[i].getControlPin()];
//                 porta_endereco[fila_desligamento[i].getControlPin()] = porta_endereco[fila_desligamento[j].getControlPin()];
//                 porta_endereco[fila_desligamento[j].getControlPin()] = aux_tarefa2;
//             }
//         }
//     }
//     //ImprimirFilaDesligamentos();
//     //HabilitarNovaInterrupcaoSEN(true);
// }
// void ImprimirFilaDesligamentos(){
//     EscreveUsartFlash(PSTR("========== Fila de Desligamento =======================\n"));
//     EscreveUsartFlash(PSTR("status\t"));
//     EscreveUsartFlash(PSTR("timer\t"));
//     EscreveUsartFlash(PSTR("pinoSensor\t"));
//     EscreveUsartFlash(PSTR("pinoAtuador\t"));
//     EscreveUsartFlash(PSTR("nome\t"));
//     EscreveUsartFlash(PSTR("\n"));
//
//     for (unsigned int i = 0; i<16; i++)
//     {
//         char a = (char) fila_desligamento[i].getStatus()+48;
//         TransmiteUsart(a);
//         TransmiteUsart('\t');
//         EscreveUsart(LongParaChar(fila_desligamento[i].getCountdownTimer()));
//         TransmiteUsart('\t');
//         char b2 = (char) fila_desligamento[i].getSensorPin()+48;
//         TransmiteUsart(b2);
//         EscreveUsartFlash(PSTR("\t\t"));
//         EscreveUsart(InteiroParaChar(fila_desligamento[i].getControlPin()));
//         EscreveUsartFlash(PSTR("\t\t"));
//         char vet[13];
//         strncpy(vet, fila_desligamento[i].getName(), 13);
//         EscreveUsart(vet);
//         EscreveUsartFlash(PSTR("\n"));
//     }
// }
// char (*getAparelhosConectados())[8]{
//     return ListaDeDispConectados;
// }
// Device getAparelhos(unsigned int indice){
//     return dispositivos_conectados[indice];
// }
// void imprimirAparelhosConectados(){
//     EscreveUsartFlash(PSTR("============ Aparelhos Conectados ====================\n"));
//     EscreveUsartFlash(PSTR("Atuador \0"));
//     EscreveUsartFlash(PSTR("Sensor \0"));
//     EscreveUsartFlash(PSTR("Consumo \0"));
//     EscreveUsartFlash(PSTR("Timer    \0"));
//     EscreveUsartFlash(PSTR("Nome\0"));
//     TransmiteUsart('\n');
//     uint8_t i = 16;
//     do {
//         --i;
//         TransmiteUsart((char) dispositivos_conectados[i].getControlPin()+48);
//         EscreveUsartFlash(PSTR("\t \0"));
//         TransmiteUsart((char) dispositivos_conectados[i].getSensorPin() +48);
//         EscreveUsartFlash(PSTR("\t \0"));
//         TransmiteUsart((char) dispositivos_conectados[i].getConsumo() +48);
//         EscreveUsartFlash(PSTR("\t   \0"));
//         char buff[10];
//         EscreveUsart(FloatParaChar(buff, dispositivos_conectados[i].getDefaultTimer_inMin(), 1));
//         EscreveUsartFlash(PSTR("\t    \0"));
//         char vet[15];
//         strncpy(vet, dispositivos_conectados[i].getName(), 13);
//         EscreveUsart(vet);
//         EscreveUsartFlash(PSTR("\n\0"));
//
//     } while (i);
// }
// void HabilitarInterrupcaoSEN(){
//     //UCSR0B = 0x00;
//     EICRA |= (1<<ISC01);                      //INTERRUP��O NA BORDA DE DESCIDA
//     EIMSK |= (1<<INT0);					   //HABILITA INTERRUP��O
//     sei();
// }
// void HabilitarNovaInterrupcaoSEN(unsigned char valor){
//     if (valor){
//         EIMSK  |= (1<<INT0);
//     }
//     else{
//         EIMSK &= ~(1<<INT0);
//     }
// }
// ISR(INT0_vect){
//     sei();
//     AtualizarFila(InterrupcaoSensorDisparada());
// }
