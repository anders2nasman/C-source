#include "model.h"

bool Model::write(const pair<string, string>& data)
{
    pair<map<string, string>::iterator,bool> result;
    // empty values? no
    // overwrite, no (inherent in insert)
    if ( !data.first.empty() && !data.second.empty() ) {
        result=database.insert(data);    // 161207 anders added
        // database.[database.last()]=data;    // 161207 anders allow overwrite?
        return result.second; //see doc map.insert returns true if inserted
    } else {
      return false;
    }
}

bool Model::get(const string& key, string& value)
{
    this->item = database.find(key); // 161207 anders added
    if (this->item != database.end()) {
        value = this->item->second;
        return true;
    }
    return false;
}

bool Model::search(const string& value)
{
    //161207 anders added - this->item is our state
    // we have to search database values
    for (this->item=database.begin(); this->item!=database.end(); this->item++) {
        if (this->item->second.find(value)>0) {
            return true;
        }
    }
    return false;

}

bool Model::next(pair<string, string>& data, const string& value)
{
    // 161207 anders added - this->item is our state
    if (this->item != database.end()) {
        data = *this->item;
        this->item++; // search do not return anything so increment after
        return true;
    }
    return false;

}

bool Model::dump()
{
    this->item=database.begin();
    return this->item!=database.end();
}

bool Model::next(pair<string, string>& data)
{
    // 161207 anders added - this->item is our state
    if (this->item != database.end()) {
        data = *this->item;
        this->item++; // search do not return anything so increment after
        return true;
    }
    return false;
}

bool Model::erase(const string& key)
{
  this->item = database.find(key);
    if (this->item != database.end()) {
        database.erase(this->item);
        return true;
    }
    return true;
}
