//
// Generated file, do not edit! Created by nedtool 5.2 from neighbor.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "neighbor_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(neighbor)

neighbor::neighbor(const char *name, short kind) : ::omnetpp::cMessage(name,kind)
{
    this->flag = 0;
    this->key = 0;
    this->neighbour = 0;
    this->id = 0;
    this->clusterCount = 0;
    cdsClusters_arraysize = 0;
    this->cdsClusters = 0;
}

neighbor::neighbor(const neighbor& other) : ::omnetpp::cMessage(other)
{
    cdsClusters_arraysize = 0;
    this->cdsClusters = 0;
    copy(other);
}

neighbor::~neighbor()
{
    delete [] this->cdsClusters;
}

neighbor& neighbor::operator=(const neighbor& other)
{
    if (this==&other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void neighbor::copy(const neighbor& other)
{
    this->flag = other.flag;
    this->key = other.key;
    this->neighbour = other.neighbour;
    this->id = other.id;
    this->clusterCount = other.clusterCount;
    delete [] this->cdsClusters;
    this->cdsClusters = (other.cdsClusters_arraysize==0) ? nullptr : new int[other.cdsClusters_arraysize];
    cdsClusters_arraysize = other.cdsClusters_arraysize;
    for (unsigned int i=0; i<cdsClusters_arraysize; i++)
        this->cdsClusters[i] = other.cdsClusters[i];
}

void neighbor::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->flag);
    doParsimPacking(b,this->key);
    doParsimPacking(b,this->neighbour);
    doParsimPacking(b,this->id);
    doParsimPacking(b,this->clusterCount);
    b->pack(cdsClusters_arraysize);
    doParsimArrayPacking(b,this->cdsClusters,cdsClusters_arraysize);
}

void neighbor::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->flag);
    doParsimUnpacking(b,this->key);
    doParsimUnpacking(b,this->neighbour);
    doParsimUnpacking(b,this->id);
    doParsimUnpacking(b,this->clusterCount);
    delete [] this->cdsClusters;
    b->unpack(cdsClusters_arraysize);
    if (cdsClusters_arraysize==0) {
        this->cdsClusters = 0;
    } else {
        this->cdsClusters = new int[cdsClusters_arraysize];
        doParsimArrayUnpacking(b,this->cdsClusters,cdsClusters_arraysize);
    }
}

int neighbor::getFlag() const
{
    return this->flag;
}

void neighbor::setFlag(int flag)
{
    this->flag = flag;
}

int neighbor::getKey() const
{
    return this->key;
}

void neighbor::setKey(int key)
{
    this->key = key;
}

int neighbor::getNeighbour() const
{
    return this->neighbour;
}

void neighbor::setNeighbour(int neighbour)
{
    this->neighbour = neighbour;
}

int neighbor::getId() const
{
    return this->id;
}

void neighbor::setId(int id)
{
    this->id = id;
}

int neighbor::getClusterCount() const
{
    return this->clusterCount;
}

void neighbor::setClusterCount(int clusterCount)
{
    this->clusterCount = clusterCount;
}

void neighbor::setCdsClustersArraySize(unsigned int size)
{
    int *cdsClusters2 = (size==0) ? nullptr : new int[size];
    unsigned int sz = cdsClusters_arraysize < size ? cdsClusters_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        cdsClusters2[i] = this->cdsClusters[i];
    for (unsigned int i=sz; i<size; i++)
        cdsClusters2[i] = 0;
    cdsClusters_arraysize = size;
    delete [] this->cdsClusters;
    this->cdsClusters = cdsClusters2;
}

unsigned int neighbor::getCdsClustersArraySize() const
{
    return cdsClusters_arraysize;
}

int neighbor::getCdsClusters(unsigned int k) const
{
    if (k>=cdsClusters_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", cdsClusters_arraysize, k);
    return this->cdsClusters[k];
}

void neighbor::setCdsClusters(unsigned int k, int cdsClusters)
{
    if (k>=cdsClusters_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", cdsClusters_arraysize, k);
    this->cdsClusters[k] = cdsClusters;
}

class neighborDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    neighborDescriptor();
    virtual ~neighborDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(neighborDescriptor)

neighborDescriptor::neighborDescriptor() : omnetpp::cClassDescriptor("neighbor", "omnetpp::cMessage")
{
    propertynames = nullptr;
}

neighborDescriptor::~neighborDescriptor()
{
    delete[] propertynames;
}

bool neighborDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<neighbor *>(obj)!=nullptr;
}

const char **neighborDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *neighborDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int neighborDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int neighborDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *neighborDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "flag",
        "key",
        "neighbour",
        "id",
        "clusterCount",
        "cdsClusters",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int neighborDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flag")==0) return base+0;
    if (fieldName[0]=='k' && strcmp(fieldName, "key")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "neighbour")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "clusterCount")==0) return base+4;
    if (fieldName[0]=='c' && strcmp(fieldName, "cdsClusters")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *neighborDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **neighborDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *neighborDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int neighborDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    neighbor *pp = (neighbor *)object; (void)pp;
    switch (field) {
        case 5: return pp->getCdsClustersArraySize();
        default: return 0;
    }
}

const char *neighborDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    neighbor *pp = (neighbor *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string neighborDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    neighbor *pp = (neighbor *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getFlag());
        case 1: return long2string(pp->getKey());
        case 2: return long2string(pp->getNeighbour());
        case 3: return long2string(pp->getId());
        case 4: return long2string(pp->getClusterCount());
        case 5: return long2string(pp->getCdsClusters(i));
        default: return "";
    }
}

bool neighborDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    neighbor *pp = (neighbor *)object; (void)pp;
    switch (field) {
        case 0: pp->setFlag(string2long(value)); return true;
        case 1: pp->setKey(string2long(value)); return true;
        case 2: pp->setNeighbour(string2long(value)); return true;
        case 3: pp->setId(string2long(value)); return true;
        case 4: pp->setClusterCount(string2long(value)); return true;
        case 5: pp->setCdsClusters(i,string2long(value)); return true;
        default: return false;
    }
}

const char *neighborDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *neighborDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    neighbor *pp = (neighbor *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


