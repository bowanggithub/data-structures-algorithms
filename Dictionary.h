//The dictionary abstract class
template <typename Key, typename E>
class Dictionary
{
private:
    void operator =(const Dictionary&) {}
    Dictionary(const Dictionary&) {}

public:
    Dictionary() {}
    virtual ~Dictionary() {}

    //reinitialize distionary
    virtual void clear() =0;

    //insert a record
    //k: the key for the record being inserted
    //e: the record being inserted
    virtual void insert(const Key& k, const E& e) =0;

    //remove and return a record
    //k: the key of the record to be removed
    //return: a matching record. If multiple records match
    //"k", remove any arbitrary one. Return NULL if no record
    //with key "k" exists
    virtual E remove(coonst Key& k) =0;

    //remove and return an arbitrary record from distionary
    //return: the record removed, or NULL if none exists
    virtual E removeAny() =0;

    //return : a record matching "k" (NULL is none exists)
    //If multiple records match, return an arbitrary one
    //k: the key of the record to find
    virtual E find(const Key& k) const =0;

    //return the number of records in the distionary
    virtual int size() =0;
};
