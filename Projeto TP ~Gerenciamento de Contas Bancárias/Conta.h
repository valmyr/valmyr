#ifndef _CONTA_H
#define _CONTA_H
struct Endereco{
    string rua;
    string CEP;
    string cidade;
    string estado;
};
class Conta{
  private:
      string nomeDoUsuario;
      long long CPF;
      int idade;
      Endereco enderecoDoUsuario;
      float saldo;
  public:
      Conta(const string & = "0",const long long & = 0,const int & = 0,const float & = 0,const Endereco & =  {"0","0","0","0"});
      void setNomeDoUsuario(const string &);
      void setCPF(const long long &);
      void setIdade(const int &);
      void setEnderecoDoUsuario(const Endereco &);
      void setSaldo(const float &);
      long long getCPF()const;
      int getIdade()const;
      string getEnderecoDoUsuario()const;
      float getSaldo()const;
      virtual bool cadastroUsuario() = 0;
      virtual bool salvarDados() = 0;
      bool sacar(float);
      bool depositar(float);
      void imprimir()const;
      ~Conta();
};
#endif //_Conta_H
