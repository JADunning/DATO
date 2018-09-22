#<eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
using namespace eosio;

//need pointer 
//need table containing utility data and number of views and index



// Smart Contract Name: dato
// Table struct:
//   notestruct: multi index table to store the notes
//     prim_key(uint64): primary key
//     user(acco#includeunt_name/uint64): account name for the user
//     note(string): the note message
//     timestamp(uint64): the store the last update block time
// Public method:
//   isnewuser => to check if the given account name has note in table or not
// Public actions:
//   update => put the note into the multi-index table and sign by the given account

// Replace the contract class name when you start your own project
class datosmart : public eosio::contract {
  private:
    bool isnewuser( account_name user ) {
      notetable noteobj(_self, _self);
      // get object by secordary key
      auto notes = noteobj.get_index<N(getbyuser)>();
      auto note = notes.find(user);

      return note == notes.end();
    }

    /// @abi table
    struct utildata {
      uint64_t      prim_key;  // primary key
      std::string   utilitydata;      // the utility data
      std::int  numremaining;      // the utility data
      std::string  tokenname;      // the utility data
      uint64_t      timestamp; // the store the last update block time

      // primary key
      auto primary_key() const { return prim_key; }
      // secondary key: user
    };

    // create a multi-index table and support secondary key
    ///typedef eosio::multi_index< N(notestruct), notestruct,
    //  indexed_by< N(getbyuser), const_mem_fun<notestruct, account_name, &notestruct::get_by_user> >
    //  > notetable;

  public:
    using contract::contract;

    /// @abi action
    void usedato( username _user, token token, amount type?, utilitydata string ) {
      // to sign the action with the given account
      require_auth( _user );

      //reduce tokens in user account by amount     
 
        // insert object
        obj.emplace( _self, [&]( auto& address ) {
          utildata.prim_key    = obj.available_primary_key();
          utildata.user        = _user;
          utildata.numremaining    = <TD>;
          utildata.tokenname    = token.name;
          utildata.utilitydata   = utilitydata;
          
          utildata.timestamp   = now();
       // insert object
       // obj.emplace( _self, [&]( auto& address ) {
       //   address.prim_key    = obj.available_primary_key();
       //   address.user        = _user;
       //   address.note        = _note;
       //   address.timestamp   = now();
        });
      }
    }
  
    void pullutilitydata( pullername _user, token token) {
      // to sign the action with the given account
      require_auth( _user );

      //get pointer to next utilty data
      
      //get from data table
      
      //reduce view data
      
      //move on pointer
      
    
  

};

// specify the contract name, and export a public action: update
EOSIO_ABI( datosmart, (usedato, issuedato, usedato) )
