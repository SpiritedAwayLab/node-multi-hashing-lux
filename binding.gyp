{
    "targets": [
        {
            "target_name": "multihashing",
            "sources": [
                "multihashing.cc",
                
                "phi2.c",
										  'sph/aes_helper.c',
										  'sph/skein.c',
										  'sph/jh.c',
                                          'sph/cubehash.c',
                                          'sph/streebog.c',
                                          'sph/echo.c',
										  'lyra2/Lyra2.c'
               
            ],
            "include_dirs": [
                "sph",
                "lyra2",
                "<!(node -e \"require('nan')\")"
            ],
            "cflags_cc": [
                "-std=c++0x"
            ],
        }
    ]
}
