# Neat bash trick to get the path where this file sits
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

if [ -z $1 ]; then
    echo "Usage:"
    echo ""
    echo "   sh $0 VVVBABYNTUP"
    echo ""
    exit
fi

$DIR/utils/makeclass.sh -f $1 t VVVTree tas vvv

python $DIR/utils/mergeClasses.py VVVTree.cc $DIR/src/VVVTree.cc > .VVVTree_new.cc
RET=$?
if [ ${RET} != 0 ]; then
    echo "Error merging!! Check VVVTree.cc or src/VVVTree.cc!"
    exit
fi
python $DIR/utils/mergeClasses.py VVVTree.h $DIR/src/VVVTree.h > .VVVTree_new.h
RET=$?
if [ ${RET} != 0 ]; then
    echo "Error merging!! Check VVVTree.h or src/VVVTree.h!"
    exit
fi

sed -i '$ d' .VVVTree_new.cc
sed -i '$ d' .VVVTree_new.h

cp src/VVVTree.cc .VVVTree_old.cc
cp src/VVVTree.h .VVVTree_old.h

cp .VVVTree_new.cc src/VVVTree.cc
cp .VVVTree_new.h src/VVVTree.h

mv VVVTree.cc .VVVTree_newOnly.cc
mv VVVTree.h .VVVTree_newOnly.h
