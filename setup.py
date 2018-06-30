from distutils.core import setup, Extension

phi2_hash_module = Extension('phi2_hash',
                               sources = ['phi2module.c',
                                          'phi2.c',
										  'sph/aes_helper.c',
										  'sph/skein.c',
										  'sph/jh.c',
                                          'sph/cubehash.c',
                                          'sph/streebog.c',
                                          'sph/echo.c',
										  'lyra2/Lyra2.c'],
                               include_dirs=['.', './sph', '.lyra2'])

setup (name = 'phi2_hash',
       version = '2.0',
       description = 'Bindings for phi2 hashing algorithm used by Luxcoin ',
       author='216k155',
       author_email='216k155@luxcore.io',
       url='https://github.com/216k155/phi2_hashing_module',
       ext_modules = [phi2_hash_module])