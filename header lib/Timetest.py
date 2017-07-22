from numpy import min as min
from timeit import Timer

def test_mm(m, n): 
    k_list = [64, 80, 96, 104, 112, 120, 
              128, 144, 160, 176, 192, 200, 
              208, 224]

    print 'Matrix Multiplication (double precision)'
    print '{0:4} {1:4} {2:4} {3:10}'.format('m', 'n', 'k', 'time (ms)')

    for k in k_list:

        setup = 'import numpy; \
        A = numpy.array(numpy.random.rand(%d, %d), dtype = numpy.double); \
        B = numpy.array(numpy.random.rand(%d, %d), dtype = numpy.double)' \
        % (m, n, n, k)


        t = Timer('C = numpy.dot(A, B)', setup)
        try:
            num = 10
            print '{0:4d} {1:4d} {2:4d} {3:6.2f}'.\
                    format(m, n, k, min(t.repeat(5, num))/num*1000)
        except:
            t.print_exc()

if __name__ == '__main__':
    test_mm(m=10000, n=6000)

