#!@PYTHON_EXECUTABLE@
#ckwg +4
# Copyright 2011-2013 by Kitware, Inc. All Rights Reserved. Please refer to
# KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
# Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.


def test_import(path_unused):
    try:
        import sprokit.pipeline_util.export_
    except:
        test_error("Failed to import the export_ module")


def test_simple_pipeline(path):
    import os

    from sprokit.pipeline import pipeline
    from sprokit.pipeline import modules
    from sprokit.pipeline_util import bake
    from sprokit.pipeline_util import export_

    modules.load_known_modules()

    p = bake.bake_pipe_file(path)
    r, w = os.pipe()

    name = 'graph'

    export_.export_dot(w, p, name)

    p.setup_pipeline()

    export_.export_dot(w, p, name)

    os.close(r)
    os.close(w)


if __name__ == '__main__':
    import os
    import sys

    if not len(sys.argv) == 5:
        test_error("Expected four arguments")
        sys.exit(1)

    testname = sys.argv[1]

    os.chdir(sys.argv[2])

    sys.path.append(sys.argv[3])

    pipeline_dir = sys.argv[4]

    tests = \
        { 'import': test_import
        , 'simple_pipeline': test_simple_pipeline
        }

    path = os.path.join(pipeline_dir, '%s.pipe' % testname)

    from sprokit.test.test import *

    run_test(testname, tests, path)