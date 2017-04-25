#ifndef COMISSIONADO_H
#define COMISSIONADO_H

#include "Funcionario.h"

class Comissionado:Funcionario{
    private:
        double vendasSemanais, percentualComissao;
    public:

        double calcularSalario();
    
        void setVendasSemanais(double _vendasSemanais);
        void setPercentualComissao(double _percentualComissao);
        double getVendasSemanais();
        double getPercentualComissao();
        Comissionado();
        Comissionado(double ct_vendasSemanais, double ct_percentualComissao);

};


#endif //COMISSIONADO_H