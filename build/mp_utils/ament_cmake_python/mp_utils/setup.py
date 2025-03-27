from setuptools import find_packages
from setuptools import setup

setup(
    name='mp_utils',
    version='0.0.0',
    packages=find_packages(
        include=('mp_utils', 'mp_utils.*')),
)
