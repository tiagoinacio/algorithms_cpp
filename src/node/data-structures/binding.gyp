{
    "targets": [
        {
            "target_name": "ds",
            "sources": [
                "data-structures.cpp",
                "linked-list.cpp"
            ],
            "include_dirs": [
                "../../../external/GSL/include"
            ],
            "xcode_settings": {
                "OTHER_CFLAGS": [
                    "-std=c++14",
                    "-stdlib=libc++",
                    "-fexceptions"
                ]
            }
        }
    ]
}