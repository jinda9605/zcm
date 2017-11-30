#include <iostream>
#include <string>
#include "Common.hpp"
#include "GetOpt.hpp"
#include "util/StringUtil.hpp"
#include "ZCMGen.hpp"
#include "Emitter.hpp"

using namespace std;

void setupOptionsNode(GetOpt& gopt)
{
    gopt.addString(0, "npath", ".", "Location for zcmtypes.js file");
}

static string getReaderFunc(const string& type)
{
    if (type == "double") {
        return "readDouble";
    } else if (type == "float") {
        return "readFloat";
    } else if (type == "int64_t") {
        return "read64";
    } else if (type == "int32_t") {
        return "read32";
    } else if (type == "int16_t") {
        return "read16";
    } else if (type == "int8_t" || type == "byte") {
        return "read8";
    } else if (type == "boolean") {
         return "readBoolean";
    } else if (type == "string") {
         return "readString";
    } else {
        return "";
    }
}

static string getWriterFunc(const string& type)
{
    if (type == "double") {
        return "writeDouble";
    } else if (type == "float") {
        return "writeFloat";
    } else if (type == "int64_t") {
        return "write64";
    } else if (type == "int32_t") {
        return "write32";
    } else if (type == "int16_t") {
        return "write16";
    } else if (type == "int8_t" || type == "byte") {
        return "write8";
    } else if (type == "boolean") {
         return "writeBoolean";
    } else if (type == "string") {
         return "writeString";
    } else {
        return "";
    }
}

static string getZeroInit(const ZCMMember& zm)
{
    auto& tn = zm.type.fullname;
    if (tn == "byte")    return "0";
    if (tn == "boolean") return "false";
    if (tn == "string")  return "\"\"";
    if (tn == "int8_t")  return "0";
    if (tn == "int16_t") return "0";
    if (tn == "int32_t") return "0";
    if (tn == "int64_t") return "0";
    if (tn == "float")   return "0.0";
    if (tn == "double")  return "0.0";
    return "new " + zm.type.nameUnderscore() + "()";
}

struct EmitModule : public Emitter
{
    ZCMGen& zcm;

    EmitModule(ZCMGen& zcm, const string& fname):
        Emitter(fname), zcm(zcm) {}

    void emitAutoGeneratedWarning()
    {
        emit(0, "/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY");
        emit(0, " * BY HAND!!");
        emit(0, " *");
        emit(0, " * Generated by zcm-gen");
        emit(0, " **/");
        emit(0, "");
    }

    void emitHeader()
    {
        emitAutoGeneratedWarning();

        emit(0, "var ref = require('ref');");
        emit(0, "var bigint = require('big-integer');");
        emit(0, "");
        emit(0, "var UINT64_MAX = bigint('ffffffffffffffff', 16);");
        emit(0, "function rotateLeftOne(val)");
        emit(0, "{");
        emit(0, "    return val.shiftLeft(1).and(UINT64_MAX).add("
                           "val.shiftRight(63).and(1))");
        emit(0, "}");
        emit(0, "");
        emit(0, "function createReader(data)");
        emit(0, "{");
        emit(0, "    var buf = data;");
        emit(0, "    var offset = 0;");
        emit(0, "    var methods = {");
        emit(0, "        readDouble: function() {");
        emit(0, "            var ret = buf.readDoubleBE(offset);");
        emit(0, "            offset += 8;");
        emit(0, "            return ret;");
        emit(0, "        },");
        emit(0, "        readFloat: function() {");
        emit(0, "            var ret = buf.readFloatBE(offset);");
        emit(0, "            offset += 4;");
        emit(0, "            return ret;");
        emit(0, "        },");
        emit(0, "        read64: function() {");
        emit(0, "            var ret = bigint(ref.readInt64BE(buf, offset));");
        emit(0, "            offset += 8;");
        emit(0, "            return ret;");
        emit(0, "        },");
        emit(0, "        readU64: function() {");
        emit(0, "            var ret = bigint(ref.readUInt64BE(buf, offset));");
        emit(0, "            offset += 8;");
        emit(0, "            return ret;");
        emit(0, "        },");
        emit(0, "        read32: function() {");
        emit(0, "            var ret = buf.readInt32BE(offset);");
        emit(0, "            offset += 4;");
        emit(0, "            return ret;");
        emit(0, "        },");
        emit(0, "        read16: function() {");
        emit(0, "            var ret = buf.readInt16BE(offset);");
        emit(0, "            offset += 2;");
        emit(0, "            return ret;");
        emit(0, "        },");
        emit(0, "        read8: function() {");
        emit(0, "            var ret = buf.readInt8(offset);");
        emit(0, "            offset += 1;");
        emit(0, "            return ret;");
        emit(0, "        },");
        emit(0, "        readBoolean: function() {");
        emit(0, "            var ret = buf.readInt8(offset);");
        emit(0, "            offset += 1;");
        emit(0, "            return ret != 0;");
        emit(0, "        },");
        emit(0, "        readString: function() {");
        emit(0, "            var len = methods.read32();");
        emit(0, "            var ret = ref.readCString(buf, offset);");
        emit(0, "            offset += len;");
        emit(0, "            return ret;");
        emit(0, "        },");
        emit(0, "        readArray: function(size, readValFunc) {");
        emit(0, "            var arr = [size];");
        emit(0, "            for (var i = 0; i < size; ++i)");
        emit(0, "                arr[i] = readValFunc();");
        emit(0, "            return arr;");
        emit(0, "        }");
        emit(0, "    };");
        emit(0, "    return methods;");
        emit(0, "}");
        emit(0, "");
        emit(0, "function createWriter(size)");
        emit(0, "{");
        emit(0, "    var buf = new Buffer(size);");
        emit(0, "    var offset = 0;");
        emit(0, "    var methods = {");
        emit(0, "        writeDouble: function(value) {");
        emit(0, "            buf.writeDoubleBE(value, offset);");
        emit(0, "            offset += 8;");
        emit(0, "        },");
        emit(0, "        writeFloat: function(value) {");
        emit(0, "            buf.writeFloatBE(value, offset);");
        emit(0, "            offset += 4;");
        emit(0, "        },");
        emit(0, "        write64: function(value) {");
        emit(0, "            ref.writeInt64BE(buf, offset, bigint.isInstance(value) ?");
        emit(0, "                                          value.toString() : value);");
        emit(0, "            offset += 8;");
        emit(0, "        },");
        emit(0, "        writeU64: function(value) {");
        emit(0, "            ref.writeUInt64BE(buf, offset, bigint.isInstance(value) ?");
        emit(0, "                                           value.toString() : value);");
        emit(0, "            offset += 8;");
        emit(0, "        },");
        emit(0, "        write32: function(value) {");
        emit(0, "            buf.writeInt32BE(value, offset);");
        emit(0, "            offset += 4;");
        emit(0, "        },");
        emit(0, "        write16: function(value) {");
        emit(0, "            buf.writeInt16BE(value, offset);");
        emit(0, "            offset += 2;");
        emit(0, "        },");
        emit(0, "        write8: function(value) {");
        emit(0, "            buf.writeInt8(value, offset);");
        emit(0, "            offset += 1;");
        emit(0, "        },");
        emit(0, "        writeBoolean: function(value) {");
        emit(0, "            buf.writeInt8(value, offset);");
        emit(0, "            offset += 1;");
        emit(0, "        },");
        emit(0, "        writeString: function(value) {");
        emit(0, "            methods.write32(value.length+1);");
        emit(0, "            ref.writeCString(buf, offset, value);");
        emit(0, "            offset += value.length+1;");
        emit(0, "        },");
        emit(0, "        writeArray: function(arr, size, writeValFunc) {");
        emit(0, "            for (var i = 0; i < size; ++i)");
        emit(0, "                writeValFunc(arr[i]);");
        emit(0, "        },");
        emit(0, "        getBuffer: function() {");
        emit(0, "            return buf;");
        emit(0, "        },");
        emit(0, "    };");
        emit(0, "    return methods;");
        emit(0, "}");
        emit(0, "");
        unordered_set<string> packages;
        for (auto& zs : zcm.structs)
            if (zs.structname.package != "")
                packages.insert(zs.structname.package);
        for (auto& pkg : packages)
            emit(0, "exports.%s = {};", pkg.c_str());
        emit(0, "");
    }

    void emitEncodeSingleMember(const ZCMMember& zm, const string& accessor_, int indent)
    {
        auto* accessor = accessor_.c_str();
        auto* tn = zm.type.nameUnderscoreCStr();

        auto writerFunc = getWriterFunc(tn);

        if (writerFunc != "") {
            emit(indent, "W.%s(%s);", writerFunc.c_str(), accessor);
        } else {
            emit(indent, "%s_encode_one(%s, W)", tn, accessor);
        }
    }

    void emitEncodeListMember(const ZCMMember& zm, const string& accessor_, int indent,
                              const string& len_, int fixedLen)
    {
        auto& tn = zm.type.fullname;
        auto* accessor = accessor_.c_str();
        auto* len = len_.c_str();

        auto writerFunc = getWriterFunc(tn);

        if (writerFunc != "") {
            if (fixedLen) {
                emit(indent, "W.writeArray(%s, %s, W.%s);", accessor, len, writerFunc.c_str());
            } else {
                emit(indent, "W.writeArray(%s, msg.%s, W.%s);",
                             accessor, len, writerFunc.c_str());
            }
        } else {
            fprintf(stderr, "Unable to encode list of type: %s\n", tn.c_str());
            assert(0);
        }
    }

    void emitEncodeOne(const ZCMStruct& zs)
    {
        auto* sn = zs.structname.nameUnderscoreCStr();

        emit(0, "%s_encode_one = function(msg, W)", sn);
        emit(0, "{");
        if (zs.members.size() == 0) {
            emit(0, "}");
            return;
        }

        for (auto& zm : zs.members) {
            if (zm.dimensions.size() == 0) {
                emitEncodeSingleMember(zm, "msg." + zm.membername, 1);
            } else {
                string accessor = "msg." + zm.membername;
                size_t n;
                for (n = 0; n < zm.dimensions.size() - 1; ++n) {
                    auto& dim = zm.dimensions[n];
                    accessor += "[i" + to_string(n) + "]";
                    if (dim.mode == ZCM_CONST) {
                        emit(1 + n, "for (var i%d = 0; i%d < %s; ++i%d) {",
                                    n, n, dim.size.c_str(), n);
                    } else {
                        emit(1 + n, "for (var i%d = 0; i%d < msg.%s; ++i%d) {",
                                    n, n, dim.size.c_str(), n);
                    }
                }

                // last dimension.
                auto& lastDim = zm.dimensions[zm.dimensions.size() - 1];
                bool lastDimFixedLen = (lastDim.mode == ZCM_CONST);

                if (ZCMGen::isPrimitiveType(zm.type.fullname)) {
                    emitEncodeListMember(zm, accessor, n + 1, lastDim.size, lastDimFixedLen);
                } else {
                    if (lastDimFixedLen) {
                        emit(n + 1, "for (var i%d = 0; i%d < %s; ++i%d) {",
                                    n, n, lastDim.size.c_str(), n);
                    } else {
                        emit(n + 1, "for (var i%d = 0; i%d < msg.%s; ++i%d) {",
                                    n, n, lastDim.size.c_str(), n);
                    }
                    accessor += "[i" + to_string(n) + "]";
                    emitEncodeSingleMember(zm, accessor, n + 2);
                    emit(n + 1, "}");
                }
                for (int i = (int) n - 1; i >= 0; --i) {
                    emit(i + 1, "}");
                }
            }
        }
        emit(0, "}");
    }

    void emitEncode(const ZCMStruct& zs)
    {
        auto* sn = zs.structname.nameUnderscoreCStr();

        emit(0, "%s.encode = function(msg)", sn);
        emit(0, "{");
        emit(0, "    var size = %s.encodedSize(msg);", sn);
        emit(0, "    var W = createWriter(size);");
        emit(0, "    W.writeU64(%s.__get_hash_recursive());", sn);
        emit(0, "    %s_encode_one(msg, W);", sn);
        emit(0, "    return W.getBuffer();");
        emit(0, "};");
        emit(0, "%s.prototype.encode = function()", sn);
        emit(0, "{");
        emit(0, "    return %s.encode(this);", sn);
        emit(0, "};");
    }

    void emitEncodedSize(const ZCMStruct& zs)
    {
        auto* sn = zs.structname.nameUnderscoreCStr();

        emit(0, "%s.encodedSize = function(msg)", sn);
        emit(0, "{");
        emit(1, "var size = 8;");
        emit(1, "var tmp = 1;");
        for (auto& zm : zs.members) {
            auto& mtn = zm.type.nameUnderscore();
            auto& mn = zm.membername;

            if (!ZCMGen::isPrimitiveType(mtn)) {
                emit(1, "size += %s.encodedSize(msg.%s);", mtn.c_str(), mn.c_str());
            } else if (mtn != "string") {
                int ndims = (int)zm.dimensions.size();
                if (ndims == 0) {
                    emit(1, "size += %d; \t//%s",
                                 ZCMGen::getPrimitiveTypeSize(mtn), mn.c_str());
                } else {
                    emit(1, "tmp = 1;");
                    for (int i = 0; i < ndims; ++i) {
                        emit(1, "tmp *= %s%s;",
                                (zm.dimensions[i].mode != ZCM_CONST) ? "msg." : "",
                                zm.dimensions[i].size.c_str());
                    }
                    emit(1, "size += tmp * %d; \t//%s",
                                 ZCMGen::getPrimitiveTypeSize(mtn), mn.c_str());
                }
            } else {
                int ndims = (int)zm.dimensions.size();
                if (ndims == 0) {
                    // The +1 and +4 below are to account for the null character
                    // and the writing of the length respectively
                    emit(1, "size += msg.%s.length + 1 + 4;", mn.c_str());
                } else {
                    emit(1, "for (var i = 0; i < msg.%s.length; ++i) {", mn.c_str());
                    emit(1 + 1, "size += msg.%s[i].length + 1 + 4;", mn.c_str());
                    emit(1, "}");
                }
            }
        }
        emit(1, "return size;");
        emit(0, "};");
    }

    void emitDecodeSingleMember(const ZCMMember& zm, const string& accessor_,
                                int indent, const string& sfx_)
    {
        auto* accessor = accessor_.c_str();
        auto* tn = zm.type.nameUnderscoreCStr();
        auto* sfx = sfx_.c_str();

        auto readerFunc = getReaderFunc(tn);

        if (readerFunc != "") {
            emit(indent, "%sR.%s()%s;", accessor, readerFunc.c_str(), sfx);
        } else {
            emit(indent, "%s%s_decode_one(R)%s", accessor, tn, sfx);
        }
    }

    void emitDecodeListMember(const ZCMMember& zm, const string& accessor_, int indent,
                              bool isFirst, const string& len_, bool fixedLen)
    {
        auto& tn = zm.type.fullname;
        auto* accessor = accessor_.c_str();
        auto* len = len_.c_str();
        const char* suffix = isFirst ? "" : ")";

        auto readerFunc = getReaderFunc(tn);

        if (readerFunc == "") {
            fprintf(stderr, "Unable to encode list of type: %s\n", tn.c_str());
            assert(0);
        }

        emit(indent, "%sR.readArray(%s%s, R.%s)%s",
                     accessor, (fixedLen ? "" : "msg."),
                     len, readerFunc.c_str(), suffix);
    }

    void emitDecodeOne(const ZCMStruct& zs)
    {
        auto* sn = zs.structname.nameUnderscoreCStr();

        emit(0, "%s_decode_one = function(R)", sn);
        emit(0, "{");
        emit(1,     "var msg = new %s();", sn);
        for (auto& zm : zs.members) {
            if (zm.dimensions.size() == 0) {
                string accessor = "msg." + zm.membername + " = ";
                emitDecodeSingleMember(zm, accessor.c_str(), 1, "");
            } else {
                string accessor = "msg." + zm.membername;

                // iterate through the dimensions of the member, building up
                // an accessor string, and emitting for loops
                size_t n = 0;
                for (; n < zm.dimensions.size() - 1; ++n) {
                    auto& dim = zm.dimensions[n];

                    if (n == 0) {
                        emit(1, "%s = []", accessor.c_str());
                    } else {
                        emit(n + 1, "%s.push([])", accessor.c_str());
                    }

                    if (dim.mode == ZCM_CONST) {
                        emit(n + 1, "for (var i%d = 0; i%d < %s; ++i%d) {",
                                    n, n, dim.size.c_str(), n);
                    } else {
                        emit(n + 1, "for (var i%d = 0; i%d < msg.%s; ++i%d) {",
                                    n, n, dim.size.c_str(), n);
                    }

                    if (n > 0 && n < zm.dimensions.size()-1) {
                        accessor += "[i" + to_string(n - 1) + "]";
                    }
                }

                // last dimension.
                auto& lastDim = zm.dimensions[zm.dimensions.size()-1];
                bool lastDimFixedLen = (lastDim.mode == ZCM_CONST);

                if (ZCMGen::isPrimitiveType(zm.type.fullname)) {
                    if (n == 0) {
                        accessor += " = ";
                    } else {
                        accessor += ".push(";
                    }

                    emitDecodeListMember(zm, accessor, n + 1, n == 0,
                                         lastDim.size, lastDimFixedLen);
                } else {
                    if (n == 0) {
                        emit(1, "%s = [];", accessor.c_str());
                    } else {
                        emit(n + 1, "%s.push([]);", accessor.c_str());
                        accessor += "[i" + to_string(n - 1) + "]";
                    }
                    emit(n + 1, "for (var i%d = 0; i%d < %s%s; ++i%d) {",
                                n, n, (lastDimFixedLen ? "" : "msg."),
                                lastDim.size.c_str(), n);
                    accessor += ".push(";
                    emitDecodeSingleMember(zm, accessor, n + 2, ")");
                    emit(n + 1, "}");
                }
                for (int i = (int) n - 1; i >= 0; --i)
                    emit(i + 1, "}");
            }
        }
        emit(1, "return msg;");
        emit(0, "}");
    }

    void emitDecode(const ZCMStruct& zs)
    {
        auto* sn = zs.structname.nameUnderscoreCStr();

        emit(0, "%s.decode = function(data)", sn);
        emit(0, "{");
        emit(1,     "var R = createReader(data);");
        emit(1,     "var hash = R.readU64();");
        emit(1,     "if (!hash.eq(%s.__get_hash_recursive())) {", sn);
        emit(1,     "    console.error('Err: hash mismatch on %s.')", sn);
        emit(1,     "    console.error('Received:\\n', hash)");
        emit(1,     "    console.error('Expected:\\n', %s.__get_hash_recursive());", sn);
        emit(1,     "    return null;");
        emit(1,     "}");
        emit(1,     "return %s_decode_one(R);", sn);
        emit(0, "};");
    }

    void emitGetHash(const ZCMStruct& zs)
    {
        auto* sn = zs.structname.nameUnderscoreCStr();

        emit(0, "%s.__hash = null;", sn);
        emit(0, "%s.__get_hash_recursive = function(parents)", sn);
        emit(0, "{");
        emit(1,     "if (%s.__hash != null) return %s.__hash", sn, sn);
        emit(1,     "if (!parents) parents = [];");
        emit(1,     "if (parents.indexOf('%s') != -1) return 0;", zs.structname.fullname.c_str());
        // If any nonPrimitive members, push yourself into the list so you aren't double counted
        for (auto& zm : zs.members) {
            if (!ZCMGen::isPrimitiveType(zm.type.fullname)) {
                emit(1, "newparents = parents.slice(0, parents.length);");
                emit(1, "newparents.push('%s')", zs.structname.fullname.c_str());
                break;
            }
        }
        emitStart(1, "var tmphash = bigint('%lu')", zs.hash);
        for (auto &zm : zs.members) {
            if (!ZCMGen::isPrimitiveType(zm.type.fullname)) {
                emitContinue(".add(%s.__get_hash_recursive(newparents))",
                             zm.type.nameUnderscoreCStr());
            }
        }
        emitEnd (".and(UINT64_MAX);");

        emit(0, "");
        emit(1, "%s.__hash = rotateLeftOne(tmphash);", sn);
        emit(1, "return %s.__hash;", sn);
        emit(0, "};");
    }

    void emitConstructor(const ZCMStruct& zs)
    {
        auto* sn = zs.structname.nameUnderscoreCStr();

        emit(0, "function %s()", sn);
        emit(0, "{");
        for (auto& zm : zs.members)
            emit(1, "this.%s = %s;", zm.membername.c_str(), getZeroInit(zm).c_str());
        emit(0, "");
        for (size_t i = 0; i < zs.constants.size(); ++i) {
            static string hexPrefix = "0x";
            if (zs.constants[i].type == "int64_t") {
                if (zs.constants[i].valstr.size() > 2 &&
                    zs.constants[i].valstr.compare(0, hexPrefix.length(), hexPrefix) == 0)
                    emit(1, "this.%s = bigint(\"%s\", 16).toString();",
                            zs.constants[i].membername.c_str(),
                            zs.constants[i].valstr.c_str() + 2);
                else
                    emit(1, "this.%s = bigint(\"%s\").toString();",
                            zs.constants[i].membername.c_str(), zs.constants[i].valstr.c_str());
            } else {
                emit(1, "this.%s = %s;",
                        zs.constants[i].membername.c_str(), zs.constants[i].valstr.c_str());
            }
        }
        emit(1, "this.__hash = %s.__get_hash_recursive().toString();", sn);
        emit(0, "}");
    }

    void emitStruct(ZCMStruct& zs)
    {
        auto* sn = zs.structname.nameUnderscoreCStr();
        auto* fn = zs.structname.fullname.c_str();

        emit(0, "/********************************************/", sn);
        emit(0, "// %s", sn);
        emit(0, "/********************************************/", sn);
        emitConstructor(zs);
        emitGetHash(zs);
        emitEncodedSize(zs);
        emitEncodeOne(zs);
        emitEncode(zs);
        emitDecodeOne(zs);
        emitDecode(zs);

        emit(0, "exports.%s = %s;", fn, sn);
        emit(0, "");
        emit(0, "");
    }

    void emitGetClientZcmTypes()
    {
        emit(0, "exports.getZcmtypes = function()");
        emit(0, "{");
        emit(1, "return {");
        for (auto& zs : zcm.structs) {
            auto* sn = zs.structname.fullname.c_str();
            emit(2, "'%s' : new exports.%s(),", sn, sn);
        }
        emit(1, "};");
        emit(0, "};");
    }

    void emitModule()
    {
        emitHeader();
        for (auto& zs : zcm.structs) {
            emitStruct(zs);
        }
        emitGetClientZcmTypes();
    }
};

int emitNode(ZCMGen& zcm)
{
    if (zcm.gopt->getBool("little-endian-encoding")) {
        printf("Nodejs does not currently support little endian encoding\n");
        return -1;
    }

    string npath = zcm.gopt->getString("npath");
    string fileName = npath + "/zcmtypes.js";
    EmitModule E{zcm, fileName};
    if (!E.good())
        return -1;

    E.emitModule();

    return 0;
}
