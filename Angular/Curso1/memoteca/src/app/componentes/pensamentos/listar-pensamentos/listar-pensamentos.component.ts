import { Component, OnInit } from '@angular/core';
import { PensamentoService } from '../pensamento.service';
import { Pensamento } from '../pensamento';

@Component({
  selector: 'app-listar-pensamentos',
  templateUrl: './listar-pensamentos.component.html',
  styleUrls: ['./listar-pensamentos.component.css']
})
export class ListarPensamentosComponent implements OnInit {
  listaPensamentos: Pensamento[] = [


  ]
  constructor(private service : PensamentoService) { }

  ngOnInit() {
    this.service.listar().subscribe((listaPensamentos) => {
      this.listaPensamentos=listaPensamentos;
    });
  }

}
