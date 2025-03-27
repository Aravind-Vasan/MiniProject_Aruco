from setuptools import find_packages
from setuptools import setup

setup(
    name='mp_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('mp_msgs', 'mp_msgs.*')),
)
