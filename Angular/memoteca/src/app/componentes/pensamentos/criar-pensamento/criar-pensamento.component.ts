import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-criar-pensamento',
  templateUrl: './criar-pensamento.component.html',
  styleUrls: ['./criar-pensamento.component.css']
})
export class CriarPensamentoComponent implements OnInit {

  pensamento = {
    id:'1',
    conteudo:"conteudo 1",
    autoria: "dev",
    modelo:"modelo1"
  }

  constructor(private readonly router : Router) { }

  ngOnInit(): void {
  }
  criarPensamento(){
    alert("calaboca")
  }
  cancelarPensamento(){
    // this.router.navigate(["listarPensamento"])
  }
}
