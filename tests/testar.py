"""Testes de caixa-preta. Python 3 + GCC; nenhuma dependencia externa."""
from pathlib import Path
import subprocess, tempfile, json, platform, hashlib
from datetime import datetime, timezone
ROOT = Path(__file__).resolve().parents[1]

def cadastro(c=101, escola='Escola Horizonte', tema='Saude bucal', prevista=40, situacao=1, efetiva=0, data='10/10/2026'):
    valores=[1,c,escola,tema,data,'Turmas do 6 ano','Equipe IntegraPSE',prevista,situacao]
    if situacao==2: valores.append(efetiva)
    return '\n'.join(map(str,valores))+'\n'

def main():
    resultados=[]
    evidencia=ROOT/"docs/evidencias"
    evidencia.mkdir(parents=True, exist_ok=True)
    (evidencia/"testes.json").write_text(json.dumps({"status":"EM EXECUCAO"}),encoding="utf-8")
    (evidencia/"testes.txt").write_text("EM EXECUCAO - resultado anterior invalidado\n",encoding="utf-8")
    with tempfile.TemporaryDirectory() as pasta:
        exe=Path(pasta)/'pse'
        comando=['gcc','-std=c11','-Wall','-Wextra','-Wpedantic','-Werror',str(ROOT/'src/main.c'),'-o',str(exe)]
        subprocess.run(comando,check=True,capture_output=True,text=True)
        def teste(id, descricao, entrada, esperados, ausentes=()):
            try:
                r=subprocess.run([str(exe)],input=entrada,capture_output=True,text=True,timeout=5)
                saida,erro,retorno=r.stdout,r.stderr,r.returncode
            except subprocess.TimeoutExpired as e:
                saida=e.stdout or b''
                if isinstance(saida,bytes): saida=saida.decode('utf-8',errors='replace')
                erro='Tempo limite excedido';retorno=-1
            verificacoes=[{'texto':t,'presente':t in saida} for t in esperados]
            ok=retorno==0 and all(v['presente'] for v in verificacoes) and all(t not in saida for t in ausentes)
            contagens={}
            if id=='T01': contagens={'Nenhuma acao cadastrada.':3}
            if id=='T15': contagens={'Erro: informe um inteiro':6}
            if id=='T16': contagens={'campo obrigatorio vazio':2,'Erro: informe um inteiro':3}
            if id=='T17': contagens={'data invalida':2}
            if id=='T24': contagens={'Erro: informe um inteiro':3}
            if id=='T25': contagens={'campo obrigatorio vazio':2}
            if id=='T27': contagens={'data invalida':3}
            observadas={k:saida.count(k) for k in contagens}
            ok=ok and all(observadas[k]==v for k,v in contagens.items())
            resultados.append({'id':id,'cenario':descricao,'entrada':entrada,'esperado':list(esperados),
              'ausencias_esperadas':list(ausentes),'observado':saida,'stderr':erro,'retorno':retorno,
              'contagens_esperadas':contagens,'contagens_observadas':observadas,'verificacoes':verificacoes,
              'resultado':'PASSOU' if ok else 'FALHOU'})
            (evidencia/(id+'_entrada.txt')).write_text(entrada,encoding='utf-8')
            (evidencia/(id+'_saida.txt')).write_text(saida,encoding='utf-8')
        teste('T01','Base vazia: listar, pesquisar, atualizar e resumir','2\n3\n4\n5\n6\n',['Nenhuma acao cadastrada.','Acoes cadastradas: 0','N/A'])
        teste('T02','Cadastro planejado e listagem completa',cadastro()+'2\n6\n',['Codigo: 101 | Situacao: Planejada','Publico-alvo: Turmas do 6 ano','Previstos: 40 | Efetivos: 0'])
        teste('T03','Cadastro realizado solicita efetivos',cadastro(situacao=2,efetiva=32)+'5\n6\n',['Realizadas: 1','Total de participacoes efetivas: 32','80.00%'])
        teste('T04','Cadastro cancelado zera efetivos',cadastro(situacao=3)+'2\n6\n',['Situacao: Cancelada','Efetivos: 0'])
        segundo=cadastro(102).splitlines(); segundo.insert(1,'101')
        teste('T05','Codigo duplicado exige outro identificador',cadastro()+'\n'.join(segundo)+'\n5\n6\n',['codigo ja cadastrado','Acoes cadastradas: 2'])
        teste('T06','Pesquisa exata por codigo e registro ausente',cadastro()+'3\n1\n101\n3\n1\n999\n6\n',['Encontradas: 1','Nenhuma acao encontrada.'])
        teste('T07','Pesquisa parcial por escola retorna todos os resultados',cadastro()+cadastro(102,escola='Escola Horizonte II')+'3\n2\nhORIZONTE\n6\n',['Encontradas: 2'])
        teste('T08','Pesquisa parcial por tema',cadastro()+'3\n3\nBUCAL\n6\n',['Encontradas: 1'])
        teste('T09','Atualiza para realizada e corrige efetivos',cadastro()+'4\n101\n2\n32\n4\n101\n2\n36\n5\n6\n',['Total de participacoes efetivas: 36','90.00%'])
        teste('T10','Atualizacao de codigo inexistente',cadastro()+'4\n999\n5\n6\n',['Registro inexistente.','Planejadas: 1'])
        teste('T11','Realizada para cancelada e planejada elimina efetivos',cadastro(situacao=2,efetiva=32)+'4\n101\n3\n5\n4\n101\n1\n5\n6\n',['Canceladas: 1','Planejadas: 1','Total de participacoes efetivas: 0'])
        teste('T12','Resumo misto: percentual so das realizadas',cadastro(situacao=2,efetiva=32)+cadastro(102,prevista=20)+cadastro(103,prevista=10,situacao=3)+'5\n6\n',['Planejadas: 1 | Realizadas: 1 | Canceladas: 1','Previstos em todas as acoes: 70','Previstos nas realizadas: 40','80.00%'])
        teste('T13','Previsao zero evita divisao por zero',cadastro(prevista=0,situacao=2,efetiva=5)+'5\n6\n',['Total de participacoes efetivas: 5','N/A'])
        teste('T14','Participacao superior ao previsto permitida',cadastro(prevista=10,situacao=2,efetiva=12)+'5\n6\n',['120.00%'])
        teste('T15','Menu rejeita texto, decimal, lixo e inteiro excessivo','abc\n1.5\n2abc\n9999999999999999999999999\n0\n7\n6\n',['Erro: informe um inteiro','Encerrando o sistema.'])
        s=cadastro().replace('Escola Horizonte\n','\n   \nEscola Horizonte\n').replace('\n40\n1\n','\n-1\n40\n0\n4\n1\n')
        teste('T16','Campos vazios, quantidade negativa e situacao invalida',s+'2\n6\n',['campo obrigatorio vazio','Erro: informe um inteiro','Previstos: 40 | Efetivos: 0'])
        teste('T17','Datas impossiveis e ano nao bissexto',cadastro(data='31/04/2026\n29/02/2026\n29/02/2028')+'2\n6\n',['data invalida','Data prevista: 29/02/2028'])
        teste('T18','Campo longo recusado sem contaminar a proxima entrada',cadastro(escola='X'*101+'\nEscola Horizonte')+'2\n6\n',['texto muito longo','Escola: Escola Horizonte'])
        teste('T19','100 registros aceitos; tentativa 101 bloqueada',''.join(cadastro(c=i) for i in range(1,101))+'1\n5\n6\n',['Limite de armazenamento atingido','Acoes cadastradas: 100'])
        teste('T20','EOF no cadastro encerra sem confirmar','1\n101\n',['Operacao incompleta nao confirmada'],['Sucesso: acao cadastrada'])
        teste('T21','Somas de grandes quantidades sem overflow de int',cadastro(prevista=2147483647,situacao=2,efetiva=2147483647)+cadastro(102,prevista=2147483647,situacao=2,efetiva=2147483647)+'5\n6\n',['Total de participacoes efetivas: 4294967294','100.00%'])
        teste('T22','Limite exato de texto (100 bytes) aceito',cadastro(escola='A'*100)+'2\n6\n',['Escola: '+'A'*100],['texto muito longo'])
        teste('T23','Quantidade efetiva negativa exige correcao',cadastro(situacao=2,efetiva='-3\n32')+'5\n6\n',['Erro: informe um inteiro','Total de participacoes efetivas: 32'])
        teste('T24','Codigo zero ou negativo e submenu invalido',cadastro(c='0\n-1\n101')+'3\n9\n1\n101\n6\n',['Erro: informe um inteiro','Encontradas: 1'])
        teste('T25','Pesquisa vazia e sem correspondencia',cadastro()+'3\n2\n\n   \nInexistente\n6\n',['campo obrigatorio vazio','Nenhuma acao encontrada.'])
        teste('T26','Nova execucao inicia sem os dados da anterior','2\n6\n',['Nenhuma acao cadastrada.'])
        teste('T27','Datas de seculos e formato estrito',cadastro(data='29/02/1900\n1/01/2026\n01/01/0000\n29/02/2000')+'2\n6\n',['data invalida','Data prevista: 29/02/2000'])
        teste('T28','EOF em atualizacao incompleta encerra',cadastro()+'4\n101\n2\n',['Operacao incompleta nao confirmada'],['Sucesso: situacao atualizada'])
        teste('T29','Percentual agregado ponderado entre realizadas',cadastro(prevista=10,situacao=2,efetiva=10)+cadastro(102,prevista=90,situacao=2,efetiva=45)+'5\n6\n',['Total de participacoes efetivas: 55','55.00%'])
        teste('T30','Realizada retorna diretamente para planejada',cadastro(situacao=2,efetiva=32)+'4\n101\n1\n5\n6\n',['Planejadas: 1 | Realizadas: 0','Total de participacoes efetivas: 0','N/A'])
    relatorio={'status':'CONCLUIDO','executado_em_utc':datetime.now(timezone.utc).isoformat(),
      'codigo_sha256':hashlib.sha256((ROOT/'src/main.c').read_bytes()).hexdigest(),
      'ambiente':platform.platform(),'compilador':subprocess.check_output(['gcc','--version'],text=True).splitlines()[0],
      'flags':'-std=c11 -Wall -Wextra -Wpedantic -Werror','total':len(resultados),'testes':resultados}
    (evidencia/'testes.json').write_text(json.dumps(relatorio,ensure_ascii=False,indent=2),encoding='utf-8')
    texto='\n'.join(f"{x['id']} | {x['resultado']} | {x['cenario']}" for x in resultados)
    (evidencia/'testes.txt').write_text(texto+'\n',encoding='utf-8')
    md=['# Registro detalhado dos testes - revisão 2', 'Execução UTC: '+relatorio['executado_em_utc'],
        'SHA-256 de src/main.c: `'+relatorio['codigo_sha256']+'`',
        'Ambiente: '+relatorio['ambiente'], 'Compilador: '+relatorio['compilador'],
        'Testes automáticos opcionais; esta execução não comprova uso do Dev-C++.']
    for t in resultados:
        md += ['## '+t['id']+' - '+t['cenario'],
          'Entrada integral: ['+t['id']+'_entrada.txt]('+t['id']+'_entrada.txt)',
          'Saída integral observada: ['+t['id']+'_saida.txt]('+t['id']+'_saida.txt)',
          'Resultado esperado: retorno 0 e presença dos seguintes trechos:',
          '```text\n'+'\n'.join(t['esperado'])+'\n```',
          'Resultado observado: retorno '+str(t['retorno'])+'; '+str(sum(v['presente'] for v in t['verificacoes']))+'/'+str(len(t['verificacoes']))+' trechos esperados encontrados.',
          'Contagens esperadas: '+str(t['contagens_esperadas'])+'; observadas: '+str(t['contagens_observadas']),
          'Trechos que não devem aparecer: '+str(t['ausencias_esperadas']),
          '**Situação: '+t['resultado']+'**']
    (evidencia/'testes_detalhados.md').write_text('\n\n'.join(md)+'\n',encoding='utf-8')
    print(texto)
    aprovados=sum(t['resultado']=='PASSOU' for t in resultados)
    print(f'\n{aprovados}/{len(resultados)} testes passaram.')
    if aprovados != len(resultados): raise SystemExit(1)

if __name__=='__main__': main()
