#! /usr/bin/python
# -*- coding: utf-8 -*-

import os
import re
import string
import xml.dom.minidom

from obj.ModuleObj import ModuleObj
from utility.util import log
from utility.util import LogLevel
from utility.util import sorted_key


class AdcObj(ModuleObj):
    def __init__(self):
        ModuleObj.__init__(self, 'cust_adc.h', 'cust_adc.dtsi')
        self.__idx_map = {}

    def get_cfgInfo(self):
        pass

    def parse(self, node):
        self.get_cfgInfo()
        self.read(node)

    def read(self, node):
        nodes = node.childNodes
        try:
            for node in nodes:
                if node.nodeType == xml.dom.Node.ELEMENT_NODE:
                    if node.nodeName == 'count':
                        count = node.childNodes[0].nodeValue
                        continue
                    subNode = node.getElementsByTagName('varName')
                    if len(subNode):
                        ModuleObj.set_data(self, node.nodeName, subNode[0].childNodes[0].nodeValue)
        except:
            msg = 'read adc content fail!'
            log(LogLevel.error, msg)
            return False

        return True

    def gen_files(self):
        ModuleObj.gen_files(self)

    def fill_hFile(self):
        gen_str = ''
        sorted_list = sorted(ModuleObj.get_data(self).keys())

        for key in sorted_list:
            value = ModuleObj.get_data(self)[key]
            gen_str += '''#define AUXADC_%s_CHANNEL\t\t\t%s\n''' %(value.upper(), key[3:])

        return gen_str

    def fill_dtsiFile(self):
        gen_str = '''&auxadc {\n'''
        gen_str += '''\tadc_channel@ {\n'''
        gen_str += '''\t\tcompatible = "mediatek,adc_channel";\n'''

        val = -1

        # sort by the key, or the sequence is dissorted
        #sorted_list = sorted(ModuleObj.get_data(self).keys())
        for key in sorted_key(ModuleObj.get_data(self).keys()):
            value = ModuleObj.get_data(self)[key]

            if value == "TEMPERATURE":
                gen_str += '''\t\tmediatek,%s0 = <%d>;\n''' %(value.lower(), string.atoi(key[3:]))
            else:
                gen_str += '''\t\tmediatek,%s = <%d>;\n''' %(value.lower(), string.atoi(key[3:]))

            if value == "ADC_FDD_RF_PARAMS_DYNAMIC_CUSTOM_CH":
                val = string.atoi(key[3:])

        gen_str += '''\t\tstatus = \"okay\";\n'''
        gen_str += '''\t};\n'''
        gen_str += '''};\n'''

        gen_str += self.fill_extraNode(val)

        return gen_str

    def fill_extraNode(self, val):
        return ''

class AdcObj_MT6785(AdcObj):

    # for the new fearture from Chao Song
    def fill_extraNode(self, val):
        str = '''&md_auxadc {\n'''
        str += '''\tio-channels = <&auxadc %d>;\n''' %(val)
        str += '''};\n'''

        return str

